#include "mdb_service.h"

#include "connection_service.h"
#include "device_config.h"
#include "logging_utils.h"
#include "mdb_config.h"
#include "mdb_codec.h"
#include "machine_protocol.h"


#ifndef SAMPLE_OFFSET_US
#define SAMPLE_OFFSET_US 52
#endif

namespace {
constexpr unsigned long kApprovedCreditTtlMs = 5UL * 60UL * 1000UL;
constexpr size_t kSniffRecentFramesLimit = 2;
constexpr size_t kSniffSummaryFamiliesLimit = 4;
constexpr uint8_t kKnownExperimentFamilyCount = 5;
constexpr uint8_t kKnownExperimentFamilies[kKnownExperimentFamilyCount][2] = {
    {12, 6}, {12, 7}, {14, 2}, {14, 3}, {15, 2}};
constexpr uint8_t kCoinChangerResetCommand = 0x00;
constexpr uint8_t kCoinChangerSetupCommand = 0x01;
constexpr uint8_t kCoinChangerTubeStatusCommand = 0x02;
constexpr uint8_t kCoinChangerPollCommand = 0x03;
constexpr uint8_t kCoinChangerCoinTypeCommand = 0x04;
constexpr uint8_t kCoinChangerDispenseCommand = 0x05;
constexpr uint8_t kCoinChangerExpansionCommand = 0x07;
constexpr uint8_t kCoinChangerExpansionIdSubcommand = 0x00;
constexpr uint8_t kCoinChangerExpansionFeatureEnableSubcommand = 0x01;
constexpr uint8_t kCoinChangerExpansionDiagStatusSubcommand = 0x05;
constexpr uint8_t kCoinChangerJustResetStatus = 0x0B;
constexpr uint8_t kCoinChangerDiagnosticOkMain = 0x03;
constexpr uint8_t kCoinChangerDiagnosticOkSub = 0x00;
static_assert(sizeof(kMdbCoinChangerManufacturer) == 4,
              "Coin changer manufacturer code must stay 3 chars");
static_assert(sizeof(kMdbCoinChangerSerial) == 13,
              "Coin changer serial must stay 12 chars");
static_assert(sizeof(kMdbCoinChangerModel) == 13,
              "Coin changer model must stay 12 chars");
// Cashless Device #1 occupies command bytes 0x10..0x17.
constexpr uint8_t kCashlessSetupCommand = 0x01;
constexpr uint8_t kCashlessPollCommand = 0x02;
constexpr uint8_t kCashlessResetCommand = 0x00;
constexpr uint8_t kCashlessReaderControlCommand = 0x04;
constexpr uint8_t kCashlessExpansionCommand = 0x07;
constexpr uint8_t kCashlessBeginSession = 0x03;
constexpr uint8_t kCashlessSetupSubcommand = 0x00;
constexpr uint8_t kCashlessSetupMaxMinSubcommand = 0x01;
constexpr uint8_t kCashlessExpansionIdSubcommand = 0x00;
constexpr uint8_t kCashlessReaderControlSubcommand = 0x01;
constexpr uint8_t kCashlessLevel = 0x01;
// MDB Currency/Country Code for Kyrgyzstani som (KGS), ISO 4217 = 417 decimal = 0x14 0x17.
constexpr uint8_t kCashlessCurrencyCountryCodeHi = 0x14;
constexpr uint8_t kCashlessCurrencyCountryCodeLo = 0x17;
constexpr uint8_t kGatewayTelephoneCurrencyCountryCodeHi = 0x09;
constexpr uint8_t kGatewayTelephoneCurrencyCountryCodeLo = 0x96;
constexpr uint8_t kCashlessAppMaxResponseTime = 0x01;
constexpr unsigned long kCreditFlowObservationWindowMs = 5000;
constexpr unsigned long kCashlessSplitContinuationWindowUs = 8000;
constexpr size_t kObservedRawStatusWindowBytes = 8;
// Backend sends amounts in minor units: 100 = 1.00 KGS.
// MDB setup advertises the scale factor as a single byte: 0x64 = 100.
// With scale factor 100 and 2 decimal places, MDB value 5000 means 50.00 KGS.
constexpr uint8_t kCashlessScalingFactor = 0x64;
constexpr uint8_t kCashlessDecimalPlaces = 2;

String byteToHex(uint8_t value);

bool shouldSuppressSetupResponseLowLevelTxTrace(const char* eventName,
                                                const char* txKind) {
  if (eventName == nullptr || txKind == nullptr) {
    return false;
  }

  if (strcmp(txKind, "setup_response") != 0) {
    return false;
  }

  return strcmp(eventName, "phy_tx_raw") == 0 ||
         strcmp(eventName, "mdb_bus_tx_raw") == 0 ||
         strcmp(eventName, "tx_word_raw9") == 0 ||
         strcmp(eventName, "tx_bit_timing") == 0 ||
         strcmp(eventName, "response_queue_enqueue") == 0 ||
         strcmp(eventName, "response_queue_dequeue") == 0 ||
         strcmp(eventName, "tx_start") == 0 ||
         strcmp(eventName, "tx_bitstream_start") == 0 ||
         strcmp(eventName, "tx_gpio_assert_low") == 0 ||
         strcmp(eventName, "tx_done") == 0 ||
         strcmp(eventName, "tx_line_release") == 0 ||
         strcmp(eventName, "tx_gpio_release_high") == 0 ||
         strcmp(eventName, "tx_duration_observed") == 0;
}


constexpr GatewayCompatProfileConfig kGatewayCompatProfileDefaultV0 = {
    0,
    "gateway_default_v0",
    "kgs_iso4217_bcd_1417",
    kCashlessAppMaxResponseTime,
    0x00,
    kCashlessCurrencyCountryCodeHi,
    kCashlessCurrencyCountryCodeLo,
    "iso4217_numeric_packed_bcd",
    "options_and_response_time",
    false,
};

constexpr GatewayCompatProfileConfig kGatewayCompatProfileAlt1 = {
    1,
    "gateway_repo_like_alt1",
    "kgs_iso4217_bcd_1417",
    0x03,
    0x09,
    kCashlessCurrencyCountryCodeHi,
    kCashlessCurrencyCountryCodeLo,
    "iso4217_numeric_packed_bcd",
    "currency_code_encoding",
    false,
};

constexpr GatewayCompatProfileConfig kGatewayCompatProfileAlt2Currency = {
    2,
    "gateway_repo_like_alt2_currency",
    "kgs_telephone_bcd_0996",
    0x03,
    0x09,
    kGatewayTelephoneCurrencyCountryCodeHi,
    kGatewayTelephoneCurrencyCountryCodeLo,
    "telephone_country_code_packed_bcd",
    "currency_country_code_encoding_mode",
    true,
};

const GatewayCompatProfileConfig& selectGatewayCompatProfileConfig(uint8_t profileId) {
  switch (profileId) {
    case 2:
      return kGatewayCompatProfileAlt2Currency;
    case 1:
      return kGatewayCompatProfileAlt1;
    case 0:
    default:
      return kGatewayCompatProfileDefaultV0;
  }
}

uint8_t sanitizeGatewayCompatProfileId(uint8_t profileId) {
  if (kGatewayCompatForceStandardProfile) {
    return kGatewayCompatForcedProfileId;
  }
  return 0;
}

String byteToHex(uint8_t value);

String buildSetupResponseExperimentLabel(uint8_t hi, uint8_t lo,
                                         uint8_t responseTime,
                                         uint8_t options) {
  return String("sweep_") + byteToHex(hi) + byteToHex(lo) +
         "_rt" + responseTime + "_o" + byteToHex(options);
}


constexpr uint8_t kCashlessDevice1BaseByte = 0x10;
constexpr uint8_t kCashlessDevice1LastByte = 0x17;
// This VMC still emits a gateway-style setup wrapper after Cashless #1 reset:
//   19 03 01 [00] 1D
// We translate only this observed pattern into our internal 0x11 setup frame.
constexpr uint8_t kObservedGatewaySetupByte = 0x19;
constexpr uint8_t kObservedGatewaySetupPayload1 = 0x03;
constexpr uint8_t kObservedGatewaySetupPayload2 = 0x01;
constexpr uint8_t kObservedGatewaySetupPayload3 = 0x00;
constexpr uint8_t kObservedGatewaySetupChecksum = 0x1D;
constexpr uint8_t kObservedGatewayPollByte = 0x1A;
constexpr uint8_t kObservedCoinChangerPollByte = 0xFE;
constexpr uint8_t kObservedGatewayExpansionByte = 0x19;
constexpr uint8_t kObservedGatewayExpansionPayload1 = 0x01;
constexpr uint8_t kObservedGatewayExpansionChecksum = 0x1A;
constexpr uint8_t kCoinCompatTailByteA = 0xFC;
constexpr uint8_t kCoinCompatTailByteB = 0x7C;
constexpr uint8_t kCoinCompatTailByteC = 0x1C;
constexpr uint8_t kIgnoredForeignTailByteA = 0x60;
constexpr uint8_t kIgnoredForeignTailByteB = 0x0B;
constexpr uint8_t kCompatBurstNoiseTailByte = 0x30;
constexpr unsigned long kCoinCompatTailIgnoreWindowUs = 2000UL; constexpr bool kIgnoreCoinCompatTailBytes = false; // Diagnostic mode: keep FC/7C/1C visible as normal RX frames instead of hiding them as tails.
constexpr unsigned long kGatewayWrapperLongRetryCycleUs = 50000000UL;
constexpr unsigned long kObservedGatewaySetupCompatWindowUs = 1500000UL;
constexpr unsigned long kSetupResponseAckTimeoutMs = 250UL;
constexpr unsigned long kBeginSessionAckTimeoutMs = 1000UL;
constexpr bool kForceTestResponseOnAnyValidRx = false;
constexpr uint8_t kForcedTestResponseByte = 0x00;
constexpr bool kLogEveryPoll = false;
constexpr bool kLogEveryStateTransition = false;
constexpr bool kLogEveryResponseDecision = false;
constexpr bool kLogGatewaySetupCompatTrace = false;
constexpr bool kEmitVerbosePhyRuntimeEvents = false;
constexpr bool kEmitVerbosePhyDecoderEvents = false;
constexpr bool kForceCompactProbeDebug = true;

bool isProbeDebugEventType(const char* eventType) {
  if (eventType == nullptr) {
    return false;
  }
  return strcmp(eventType, "probe") == 0 || strncmp(eventType, "probe_", 6) == 0;
}

bool isCashlessDevice1CommandByte(uint8_t value) {
  return value >= kCashlessDevice1BaseByte && value <= kCashlessDevice1LastByte;
}

bool isIgnoredForeignTailByte(uint8_t value) {
  return value == kIgnoredForeignTailByteA || value == kIgnoredForeignTailByteB;
}

bool isCompatBurstNoiseTailByte(uint8_t value) {
  return isIgnoredForeignTailByte(value) || value == kCompatBurstNoiseTailByte;
}

bool isCoinCompatTailByte(uint8_t value) {
  return value == kCoinCompatTailByteA || value == kCoinCompatTailByteB ||
         value == kCoinCompatTailByteC;
}

// Определяет, изменился ли снимок cashless-состояния.
bool snapshotChanged(const CashlessSession::Snapshot& lhs,
                     const CashlessSession::Snapshot& rhs) {
  return lhs.state != rhs.state ||
         lhs.pendingAmountMinor != rhs.pendingAmountMinor ||
         lhs.approvedAmountMinor != rhs.approvedAmountMinor ||
         lhs.reservedAmountMinor != rhs.reservedAmountMinor ||
         lhs.pendingTransactionId != rhs.pendingTransactionId ||
         lhs.approvedTransactionId != rhs.approvedTransactionId;
}

// Экранирует строку для безопасной ручной сборки JSON.
String escapeForJson(const String& text) {
  String escaped;
  escaped.reserve(text.length() + 8);
  for (size_t i = 0; i < text.length(); ++i) {
    const char ch = text[i];
    if (ch == '\\' || ch == '"') {
      escaped += '\\';
    }
    escaped += ch;
  }
  return escaped;
}

bool isWrapperContinuationPending(MdbService::WrapperFsmState state,
                                  bool wrapperStandardFlowEntered) {
  return state != MdbService::WrapperFsmState::Idle &&
         !wrapperStandardFlowEntered;
}

String buildWrapperContinuationBlockerLabel(
    MdbService::WrapperFsmState state, bool wrapperStandardFlowEntered,
    const String& wrapperContinuationInterpretation,
    const String& wrapperTransitionReason) {
  if (!isWrapperContinuationPending(state, wrapperStandardFlowEntered)) {
    return "";
  }
  if (!wrapperContinuationInterpretation.isEmpty()) {
    return String("waiting_for_wrapper_continuation/") +
           wrapperContinuationInterpretation;
  }
  if (!wrapperTransitionReason.isEmpty()) {
    return String("waiting_for_wrapper_continuation/") +
           wrapperTransitionReason;
  }
  return "waiting_for_wrapper_continuation";
}

String buildWrapperPhaseAndStateJson(const String& wrapperPhase,
                                     const String& wrapperState) {
  return String(",\"wrapper_phase\":\"") + escapeForJson(wrapperPhase) +
         "\",\"wrapper_fsm_state\":\"" + escapeForJson(wrapperState) + "\"";
}

String buildGatewayWrapperWaitingForContinuationJson(
    unsigned long timestampUs, const char* readerState,
    const String& wrapperExpectedNextRxKind,
    const String& wrapperExpectedNextAction) {
  return String("{\"timestamp_us\":") + timestampUs +
         ",\"reader_state\":\"" +
         (readerState == nullptr ? "" : String(readerState)) +
         "\",\"wrapper_expected_next_rx_kind\":\"" +
         escapeForJson(wrapperExpectedNextRxKind) +
         "\",\"wrapper_expected_next_action\":\"" +
         escapeForJson(wrapperExpectedNextAction) + "\"}";
}

const char* endReasonToString(uint8_t code) {
  switch (code) {
    case 1:
      return "gap_timeout";
    case 2:
      return "buffer_full";
    case 3:
      return "continuation_success";
    case 4:
      return "continuation_failure";
    case 5:
      return "immediate_valid_short";
    default:
      return "unknown";
  }
}

const char* continuationResultToString(uint8_t code) {
  switch (code) {
    case 1:
      return "appended";
    case 2:
      return "failed";
    default:
      return "not_attempted";
  }
}

const char* continuationFailReasonToString(uint8_t code) {
  switch (code) {
    case 1:
      return "no_followup_bytes";
    case 2:
      return "still_partial_after_append";
    default:
      return "none";
  }
}

String boolToJson(bool value) { return value ? "true" : "false"; }

uint16_t raw9Word(uint8_t value, bool ninthBit) {
  return static_cast<uint16_t>(value) | (ninthBit ? 0x100U : 0U);
}

const char* observationCloseReasonToClassification(bool pollingDisappeared,
                                                   bool machineChanged) {
  if (pollingDisappeared) {
    return "unsafe_effect";
  }
  if (machineChanged) {
    return "safe_possible_effect";
  }
  return "safe_no_visible_effect";
}

void appendByteHex(String& out, uint8_t value) {
  if (!out.isEmpty()) {
    out += ' ';
  }
  if (value < 0x10) {
    out += '0';
  }
  out += String(value, HEX);
}

String bytesToHex(const uint8_t* data, size_t length) {
  String out;
  for (size_t i = 0; i < length; ++i) {
    appendByteHex(out, data[i]);
  }
  out.toUpperCase();
  return out;
}

String byteToHex(uint8_t value) {
  String out;
  if (value < 0x10) {
    out += '0';
  }
  out += String(value, HEX);
  out.toUpperCase();
  return out;
}

String byteBitsLsbFirst(uint8_t value, uint8_t bitCount) {
  String out;
  for (uint8_t i = 0; i < bitCount; ++i) {
    out += ((value >> i) & 0x1U) ? '1' : '0';
  }
  return out;
}

String byteBitsMsbView(uint8_t value, uint8_t bitCount) {
  String out;
  for (int i = static_cast<int>(bitCount) - 1; i >= 0; --i) {
    out += ((value >> i) & 0x1U) ? '1' : '0';
  }
  return out;
}

const char* decoderPathLabel(uint32_t pathIndex) {
  switch (pathIndex) {
    case 0:
      return "edge_ring_strict";
    case 1:
      return "unused";
    default:
      return "unknown";
  }
}

const char* decoderBadReasonLabel(uint8_t reason) {
  switch (static_cast<MachinePhy::DecoderBadReason>(reason)) {
    case MachinePhy::DecoderBadReason::None:
      return "none";
    case MachinePhy::DecoderBadReason::RingOverflow:
      return "ring_overflow";
    case MachinePhy::DecoderBadReason::PolarityMismatch:
      return "polarity_mismatch";
    case MachinePhy::DecoderBadReason::StartBitInvalid:
      return "start_bit_invalid";
    case MachinePhy::DecoderBadReason::StopBitInvalid:
      return "stop_bit_invalid";
    case MachinePhy::DecoderBadReason::TimingDrift:
      return "timing_drift";
    case MachinePhy::DecoderBadReason::NoIdleBeforeStart:
      return "no_idle_before_start";
    case MachinePhy::DecoderBadReason::InsufficientEdgeContext:
      return "insufficient_edge_context";
    default:
      return "unknown";
  }
}

const char* decoderTraceEdgeDecisionLabel(uint8_t decision) {
  switch (static_cast<MachinePhy::DecoderTraceEdgeDecision>(decision)) {
    case MachinePhy::DecoderTraceEdgeDecision::Unknown:
      return "unknown";
    case MachinePhy::DecoderTraceEdgeDecision::Accepted:
      return "accepted";
    case MachinePhy::DecoderTraceEdgeDecision::BeforeWindow:
      return "before_window";
    case MachinePhy::DecoderTraceEdgeDecision::AfterWindow:
      return "after_window";
    case MachinePhy::DecoderTraceEdgeDecision::Duplicate:
      return "duplicate";
    case MachinePhy::DecoderTraceEdgeDecision::TooClose:
      return "too_close";
    case MachinePhy::DecoderTraceEdgeDecision::Overwritten:
      return "overwritten";
    default:
      return "unknown";
  }
}

const char* decoderTraceScanStopReasonLabel(uint8_t reason) {
  switch (static_cast<MachinePhy::DecoderTraceScanStopReason>(reason)) {
    case MachinePhy::DecoderTraceScanStopReason::Unknown:
      return "unknown";
    case MachinePhy::DecoderTraceScanStopReason::LiveRingTail:
      return "live_ring_tail";
    case MachinePhy::DecoderTraceScanStopReason::RingOverwritten:
      return "ring_overwritten";
    default:
      return "unknown";
  }
}

uint8_t byteDistance(uint8_t lhs, uint8_t rhs) {
  return static_cast<uint8_t>(
      __builtin_popcount(static_cast<unsigned int>(lhs ^ rhs)));
}

String gapsToJson(const machine::Frame& frame) {
  String json = "[";
  bool first = true;
  for (size_t i = 1; i < frame.length; ++i) {
    if (!first) {
      json += ',';
    }
    json += frame.bytes[i].gapBeforeMs;
    first = false;
  }
  json += "]";
  return json;
}

bool isKnownExperimentFamily(uint8_t address, uint8_t command) {
  for (size_t i = 0; i < kKnownExperimentFamilyCount; ++i) {
    if (kKnownExperimentFamilies[i][0] == address &&
        kKnownExperimentFamilies[i][1] == command) {
      return true;
    }
  }
  return false;
}
}  // namespace

MdbService::MdbService(ConnectionService& connectionService)
    : connectionService_(connectionService) {}

const char* MdbService::responsePathStateLabel(ResponsePathState state) {
  switch (state) {
    case ResponsePathState::Idle:
      return "IDLE";
    case ResponsePathState::RxFrameReady:
      return "RX_FRAME_READY";
    case ResponsePathState::ResponseDecision:
      return "RESPONSE_DECISION";
    case ResponsePathState::TxPending:
      return "TX_PENDING";
    case ResponsePathState::TxSending:
      return "TX_SENDING";
    case ResponsePathState::TxDone:
      return "TX_DONE";
    case ResponsePathState::TxReleased:
      return "TX_RELEASED";
    case ResponsePathState::TxTimeout:
      return "TX_TIMEOUT";
    case ResponsePathState::TxAbort:
      return "TX_ABORT";
    default:
      return "UNKNOWN";
  }
}

const char* MdbService::txScopeLabel(TxScope scope) {
  switch (scope) {
    case TxScope::MdbResponse:
      return "mdb_response";
    case TxScope::DebugCommand:
      return "debug_command";
    case TxScope::Experiment:
      return "experiment";
    case TxScope::None:
    default:
      return "none";
  }
}

const char* MdbService::dialogueDirectionLabel(DialogueDirection direction) {
  switch (direction) {
    case DialogueDirection::RxFromMachine:
      return "RX_FROM_MACHINE";
    case DialogueDirection::TxToMachine:
      return "TX_TO_MACHINE";
    default:
      return "UNKNOWN";
  }
}

const char* MdbService::dialogueKindLabel(DialogueKind kind) {
  switch (kind) {
    case DialogueKind::Reset:
      return "RESET";
    case DialogueKind::Setup:
      return "SETUP";
    case DialogueKind::ExpansionId:
      return "EXPANSION_ID";
    case DialogueKind::Enable:
      return "ENABLE";
    case DialogueKind::Disable:
      return "DISABLE";
    case DialogueKind::Poll:
      return "POLL";
    case DialogueKind::Ack:
      return "ACK";
    case DialogueKind::Nak:
      return "NAK";
    case DialogueKind::JustReset:
      return "JUST_RESET";
    case DialogueKind::ReaderConfig:
      return "READER_CONFIG";
    case DialogueKind::ReaderStateChange:
      return "READER_STATE_CHANGE";
    case DialogueKind::Unknown:
    default:
      return "UNKNOWN";
  }
}

const char* MdbService::readerStateLabel(ReaderState state) {
  switch (state) {
    case ReaderState::Uninitialized:
      return "UNINITIALIZED";
    case ReaderState::ResetSeen:
      return "RESET_SEEN";
    case ReaderState::SetupSeen:
      return "SETUP_SEEN";
    case ReaderState::SetupResponded:
      return "SETUP_RESPONDED";
    case ReaderState::ExpansionPending:
      return "EXPANSION_PENDING";
    case ReaderState::Disabled:
      return "DISABLED";
    case ReaderState::Enabled:
      return "ENABLED";
    case ReaderState::PollActive:
      return "POLL_ACTIVE";
    case ReaderState::SessionIdle:
      return "SESSION_IDLE";
    case ReaderState::SessionActive:
      return "SESSION_ACTIVE";
    case ReaderState::Error:
      return "ERROR";
    default:
      return "UNKNOWN";
  }
}

const char* MdbService::wrapperFsmStateLabel(WrapperFsmState state) {
  switch (state) {
    case WrapperFsmState::Idle:
      return "WRAPPER_IDLE";
    case WrapperFsmState::SetupConfigSeen:
      return "WRAPPER_SETUP_CONFIG_SEEN";
    case WrapperFsmState::ReaderConfigSent:
      return "WRAPPER_READER_CONFIG_SENT";
    case WrapperFsmState::WaitingForContinuation:
      return "WRAPPER_WAITING_FOR_CONTINUATION";
    case WrapperFsmState::ContinuationTimeout:
      return "WRAPPER_CONTINUATION_TIMEOUT";
    case WrapperFsmState::ResetObserved:
      return "WRAPPER_RESET_OBSERVED";
    case WrapperFsmState::RetryObserved:
      return "WRAPPER_RETRY_OBSERVED";
    case WrapperFsmState::ContinuedToStandardFlow:
      return "WRAPPER_CONTINUED_TO_STANDARD_FLOW";
    default:
      return "WRAPPER_UNKNOWN";
  }
}

const char* MdbService::wrapperAckSemanticsModeLabel(
    WrapperAckSemanticsMode mode) {
  switch (mode) {
    case WrapperAckSemanticsMode::WrapperContinuationOnly:
      return "wrapper_continuation_only";
    case WrapperAckSemanticsMode::StandardSetupAck:
    default:
      return "standard_setup_ack";
  }
}

const char* MdbService::currentDialoguePhaseLabel() const {
  if (responsePathState_ == ResponsePathState::RxFrameReady ||
      responsePathState_ == ResponsePathState::ResponseDecision ||
      responsePathState_ == ResponsePathState::TxPending ||
      responsePathState_ == ResponsePathState::TxSending) {
    return responsePathStateLabel(responsePathState_);
  }
  return readerStateLabel(readerState_);
}

const char* MdbService::postResetPhaseLabel() const {
  if (lastResetTsUs_ == 0) {
    return "IDLE";
  }
  if (lastResetAckSentUs_ == 0 || lastResetAckSentUs_ < lastResetTsUs_) {
    return "RESET_SEEN";
  }
  if (cashlessJustResetPending_ &&
      (lastPollAfterResetTsUs_ == 0 ||
       lastPollAfterResetTsUs_ < lastResetAckSentUs_)) {
    return "WAITING_FOR_POLL_AFTER_RESET";
  }
  if (cashlessJustResetPending_ &&
      lastPollAfterResetTsUs_ >= lastResetAckSentUs_) {
    return "JUST_RESET_READY";
  }
  if (!cashlessJustResetPending_ && lastJustResetSentUs_ >= lastResetAckSentUs_) {
    return "WAITING_FOR_ENABLE_OR_SETUP";
  }
  return "RESET_ACK_SENT";
}

void MdbService::setWrapperFsmState(WrapperFsmState newState,
                                    const char* reason, unsigned long tsUs) {
  if (wrapperFsmState_ == newState) {
    if (reason != nullptr && *reason != '\0') {
      wrapperTransitionReason_ = reason;
    }
    return;
  }

  const WrapperFsmState oldState = wrapperFsmState_;
  wrapperFsmState_ = newState;
  wrapperTransitionReason_ = reason == nullptr ? "" : String(reason);
  emitEvent("wrapper_phase_transition",
            String("{\"timestamp_us\":") + tsUs +
                ",\"old_state\":\"" +
                escapeForJson(wrapperFsmStateLabel(oldState)) +
                "\",\"new_state\":\"" +
                escapeForJson(wrapperFsmStateLabel(newState)) +
                "\",\"reason\":\"" +
                escapeForJson(wrapperTransitionReason_) + "\"}");
}

const char* MdbService::txAuditKindBucketLabel(size_t index) {
  switch (index) {
    case 0:
      return "ack";
    case 1:
      return "just_reset_status";
    case 2:
      return "setup_response";
    case 3:
      return "expansion_response";
    case 4:
      return "begin_session";
    case 5:
      return "vend_approved";
    case 6:
      return "vend_denied";
    case 7:
      return "revalue_limit_zero";
    case 8:
      return "end_session";
    case 9:
    default:
      return "other";
  }
}

size_t MdbService::txAuditKindBucketFor(const char* txKind,
                                        DialogueKind kind) {
  if (txKind != nullptr && txKind[0] != '\0') {
    if (strcmp(txKind, "just_reset_status") == 0) {
      return 1;
    }
    if (strcmp(txKind, "setup_response") == 0) {
      return 2;
    }
    if (strcmp(txKind, "expansion_response") == 0 ||
        strcmp(txKind, "setup_expansion_response") == 0) {
      return 3;
    }
    if (strcmp(txKind, "begin_session") == 0) {
      return 4;
    }
    if (strcmp(txKind, "vend_approved") == 0) {
      return 5;
    }
    if (strstr(txKind, "vend_denied") != nullptr) {
      return 6;
    }
    if (strcmp(txKind, "revalue_limit_zero") == 0) {
      return 7;
    }
    if (strcmp(txKind, "end_session") == 0) {
      return 8;
    }
    if (strcmp(txKind, "session_complete") == 0) {
      return 9;
    }
    if (strstr(txKind, "ack") != nullptr) {
      return 0;
    }
  }

  switch (kind) {
    case DialogueKind::Ack:
      return 0;
    case DialogueKind::JustReset:
      return 1;
    case DialogueKind::ReaderConfig:
      return 2;
    case DialogueKind::ExpansionId:
      return 3;
    default:
      return 9;
  }
}

// Инициализирует PHY и стартовое состояние cashless-сервиса.
void MdbService::begin() {
  rxInvertEnabled_ = MDB_RX_INVERT;
  session_.begin(connectionService_.isWebSocketConnected(), millis());
  phy_.setTxObserver(MdbService::handlePhyTxObservedThunk, this);
  phy_.setStatusObserver(MdbService::handlePhyStatusObservedThunk, this);
  phy_.setFrameObserver(MdbService::handleFastFrameObservedThunk, this);
  phy_.begin(MDB_BAUD_RATE, MDB_RX_PIN, MDB_TX_PIN, rxInvertEnabled_, MDB_TX_INVERT,
             MDB_FRAME_GAP_MS);
  active_ = true;
  stateDirty_ = true;
  expectedAddress_ = kMdbCashlessEnabled
                         ? static_cast<int>(kMdbCashlessAddress)
                         : (kMdbCoinChangerEnabled
                                ? static_cast<int>(kMdbCoinChangerAddress)
                                : -1);
  cashlessAddress_ = kMdbCashlessAddress;
  experimentMode_ = ExperimentMode::PassiveOnly;
  experimentConfig_ = {};
  experimentArmed_ = false;
  experimentReplyPending_ = false;
  experimentObservationActive_ = false;
  experimentFireOnceRequested_ = false;
  experimentRepliesThisSession_ = 0;
  experimentObservedPostFamilies_ = "";
  resetCoinChangerProtocolState(true);
  clearCoinChangerPendingPayment();
  isReaderEnabled_ = false;
  cashlessJustResetPending_ = true;
  cashlessSetupSeen_ = false;
  cashlessSetupMaxMinSeen_ = false;
  cashlessSetupResponsePending_ = false;
  cashlessSetupResponseAwaitingAck_ = false;
  cashlessExpansionSeen_ = false;
  cashlessSetupResponseSentAtMs_ = 0;
  cashlessSetupResponseSentUs_ = 0;
  lastSetupResponseReplyDelayUs_ = 0;
  lastSetupResponseTxUs_ = 0;
  lastSetupRxTsUs_ = 0;
  lastSetupRxEndUs_ = 0;
  lastSetupDecisionTsUs_ = 0;
  lastSetupFrameBuiltTsUs_ = 0;
  lastSetupQueueEnqueueTsUs_ = 0;
  lastSetupTxDoneUs_ = 0;
  lastSetupReleaseUs_ = 0;
  lastSetupDecisionToTxUs_ = 0;
  lastSetupBuildToTxUs_ = 0;
  lastSetupTotalResponseUs_ = 0;
  lastSetupToRepeatUs_ = 0;
  lastSetupResponseChecksum_ = 0;
  lastSetupResponseOptions_ = 0;
  lastSetupResponseResponseTime_ = 0;
  lastSetupResponseCountryCodeHi_ = kCashlessCurrencyCountryCodeHi;
  lastSetupResponseCountryCodeLo_ = kCashlessCurrencyCountryCodeLo;
  lastSetupFastPathUsed_ = false;
  currentSetupResponseGatewayCompat_ = false;
  gatewayCompatLastSetupResponseUs_ = 0;
  gatewayCompatFollowupActive_ = false;
  gatewayCompatFirstFollowupCaptured_ = false;
  gatewayCompatTotalFramesSeenAtArm_ = 0;
  gatewayCompatBusAliveAfterSetup_ = false;
  lastUnknownRxAfterSetupExpectationUs_ = 0;
  suppressedUnknownRxAfterSetupCount_ = 0;
  gatewayCompatExpectedFollowup_ = "WRAPPER_CONTINUATION_OR_RESET_OR_RETRY";
  gatewayCompatRetryInterpretation_ = "idle";
  gatewayCompatLastOutcome_ = "idle";
  gatewayCompatResponseProfileId_ = sanitizeGatewayCompatProfileId(gatewayCompatResponseProfileId_);
  gatewayCompatSemanticSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  wrapperFsmState_ = WrapperFsmState::Idle;
  wrapperAckSemanticsMode_ = WrapperAckSemanticsMode::StandardSetupAck;
  wrapperStandardFlowEntered_ = false;
  wrapperAckSemanticsSuspect_ = false;
  wrapperContinuationTimeoutCount_ = 0;
  wrapperExpectedNextRxKind_ = "";
  wrapperExpectedNextAction_ = "";
  wrapperTransitionReason_ = "";
  wrapperContinuationKind_ = "";
  wrapperContinuationRaw9_ = 0;
  wrapperContinuationDeltaUs_ = 0;
  wrapperContinuationInterpretation_ = "";
  setupResponseRejectedByVmc_ = "unknown";
  setupRejectionBasis_ = "";
  lastNakAfterSetupTsUs_ = 0;
  lastNakAfterSetupRaw9_ = 0;
  lastNakAfterSetupDeltaUs_ = 0;
  repeatedSetupCount_ = 0;
  repeatedSetupSamePayloadCount_ = 0;
  repeatedSetupVariantCount_ = 0;
  lastSetupSeenUs_ = 0;
  lastSetupRaw9_ = 0;
  lastSetupSubcommand_ = -1;
  lastSetupVariant_ = "";
  lastSetupHex_ = "";
  lastRepeatedSetupReasonGuess_ = "";
  previousSetupVariant_ = "";
  previousSetupRaw9_ = 0;
  previousSetupTimestampUs_ = 0;
  repeatedSetupInterpretation_ = "";
  setupResponseProfileId_ = gatewayCompatResponseProfileIdLabel();
  setupResponseSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  gatewayCurrencyCountryCodeProfileId_ = gatewayCurrencyCountryCodeProfileIdLabel();
  currencyCountryCodeEncodingMode_ = gatewayCurrencyCountryCodeEncodingModeLabel();
  firstFollowupKindAfterSetup_ = "";
  firstFollowupRaw9AfterSetup_ = 0;
  firstFollowupDeltaUs_ = 0;
  firstFollowupInterpretation_ = "";
  setupNakCausal_ = "unknown";
  setupNakInterpretation_ = "";
  resetSeenCount_ = 0;
  resetAckSentCount_ = 0;
  justResetSentCount_ = 0;
  justResetAcknowledgedCount_ = 0;
  resetAfterSetupRetryCount_ = 0;
  pollMissingAfterResetCount_ = 0;
  lastResetTsUs_ = 0;
  lastResetAckSentUs_ = 0;
  lastResetAckPreparedUs_ = 0;
  lastResetAckDoneUs_ = 0;
  lastResetAckReleaseUs_ = 0;
  lastPollAfterResetTsUs_ = 0;
  lastJustResetSentUs_ = 0;
  lastSetupResponseToResetUs_ = 0;
  lastResetToAckUs_ = 0;
  lastNextRxAfterResetTsUs_ = 0;
  repeatedSetupThenResetObserved_ = false;
  pollMissingAfterResetLogged_ = false;
  lastResetCauseGuess_ = "";
  nextActionHypothesis_ = "await_setup_or_reset";
  beginSessionPending_ = false;
  beginSessionAmountMinor_ = 0;
  beginSessionAwaitingAck_ = false;
  beginSessionTxCount_ = 0;
  beginSessionAckCount_ = 0;
  lastBeginSessionTxUs_ = 0;
  lastBeginSessionAckUs_ = 0;
  lastBeginSessionSentAtMs_ = 0;
  lastBeginSessionStatus_ = "idle";
  creditFlowActive_ = false;
  creditFlowCompleted_ = false;
  creditFlowNeedsJustReset_ = false;
  creditFlowJustResetSent_ = false;
  creditFlowVendDeniedSent_ = false;
  creditFlowSessionEndSent_ = false;
  creditFlowObservationActive_ = false;
  creditFlowExactReplyDelayUs_ = 0;
  clearPendingCashlessSplitPrefix();
  clearObservedRawStatusWindow();
  responsePathState_ = ResponsePathState::Idle;
  responseStateChangedAtUs_ = 0;
  lastAcceptedRxFrame_ = {};
  lastResponseDecisionReason_ = "";
  lastResponseDecisionWillRespond_ = false;
  lastTxFrame_ = {};
  lastTxKind_ = "";
  lastTxErrorReason_ = "";
  txAttemptCount_ = 0;
  txSuccessCount_ = 0;
  txAbortCount_ = 0;
  txTimeoutCount_ = 0;
  lastTxStartUs_ = 0;
  lastTxDoneUs_ = 0;
  lastTxReleaseUs_ = 0;
  currentTxScope_ = TxScope::None;
  currentTxKind_ = "";
  gatewaySetupCompatStage_ = 0;
  gatewaySetupCompatStartedUs_ = 0;
  gatewaySetupCompatSawExplicitZero_ = false;
  readerState_ = ReaderState::Uninitialized;
  lastRxKind_ = DialogueKind::Unknown;
  lastTxKindEnum_ = DialogueKind::Unknown;
  txFrameCount_ = 0;
  pollRxCount_ = 0;
  pollTxCount_ = 0;
  enableRxCount_ = 0;
  enableAppliedCount_ = 0;
  setupRxCount_ = 0;
  setupTxCount_ = 0;
  expansionRxCount_ = 0;
  expansionTxCount_ = 0;
  ackTxCount_ = 0;
  noResponseCount_ = 0;
  stateTransitionCount_ = 0;
  lastRxToTxLatencyUs_ = 0;
  lastNoResponseReason_ = "";
  lastStateTransitionReason_ = "";
  debugTransportReadyEmitted_ = false;
  for (size_t i = 0; i < kDialogueHistorySize; ++i) {
    dialogueHistory_[i] = {};
  }
  dialogueHistoryNext_ = 0;
  dialogueHistoryCount_ = 0;
  rebuildPrecomputedFrames();
}

void MdbService::startRealtimeRx() {
  activate();
  phy_.startEventTask();
}

// Включает сервис и PHY по требованию.
void MdbService::activate() {
  active_ = true;
  phy_.setTxObserver(MdbService::handlePhyTxObservedThunk, this);
  phy_.setStatusObserver(MdbService::handlePhyStatusObservedThunk, this);
  phy_.setFrameObserver(MdbService::handleFastFrameObservedThunk, this);
  phy_.activate();
}

void MdbService::handlePhyTxObservedThunk(void* context, uint32_t frameId,
                                          size_t byteIndex, uint8_t value,
                                          uint8_t ninthBit,
                                          unsigned long tsUs) {
  if (context == nullptr) {
    return;
  }
  static_cast<MdbService*>(context)->handlePhyTxObserved(frameId, byteIndex, value,
                                                         ninthBit, tsUs);
}

void MdbService::handlePhyStatusObservedThunk(void* context, const char* eventName,
                                              unsigned long tsUs,
                                              UBaseType_t priority,
                                              BaseType_t coreId,
                                              uint32_t auxValue) {
  if (context == nullptr) {
    return;
  }
  static_cast<MdbService*>(context)->handlePhyStatusObserved(eventName, tsUs,
                                                             priority, coreId,
                                                             auxValue);
}

void MdbService::handleFastFrameObservedThunk(void* context,
                                              const machine::Frame& frame,
                                              unsigned long finalizedAtMs) {
  if (context == nullptr) {
    return;
  }
  static_cast<MdbService*>(context)->handleFastFrameObserved(frame, finalizedAtMs);
}

void MdbService::copyReasonText(char* target, size_t capacity,
                                const char* source) {
  if (target == nullptr || capacity == 0) {
    return;
  }
  if (source == nullptr) {
    target[0] = '\0';
    return;
  }
  strncpy(target, source, capacity - 1);
  target[capacity - 1] = '\0';
}

MdbService::DialogueKind MdbService::classifyRxFrameKind(
    const machine::Frame& frame) const {
  if (frame.normalizedLength == 0) {
    return DialogueKind::Unknown;
  }
  if (frame.normalizedLength == 1) {
    if (frame.normalized[0] == mdb::kAck) {
      return DialogueKind::Ack;
    }
    if (frame.normalized[0] == mdb::kNak) {
      return DialogueKind::Nak;
    }
    if (kMdbCashlessEnabled && frame.normalized[0] == kObservedGatewayPollByte) {
      return DialogueKind::Poll;
    }
  }
  if (frame.hasCandidateAddress &&
      matchesCashlessDialogueAddress(frame.candidateAddress,
                                     frame.candidateCommand)) {
    if (frame.checksumValid &&
        frame.candidateCommand == kCashlessResetCommand) {
      return DialogueKind::Reset;
    }
    if (frame.checksumValid &&
        frame.candidateCommand == kCashlessPollCommand) {
      return DialogueKind::Poll;
    }
    if (frame.checksumValid &&
        frame.candidateCommand == kCashlessSetupCommand) {
      return DialogueKind::Setup;
    }
    if ((frame.checksumValid &&
         frame.candidateCommand == kCashlessExpansionCommand &&
         frame.normalizedLength >= 2 &&
         frame.normalized[1] == kCashlessExpansionIdSubcommand)) {
      return DialogueKind::ExpansionId;
    }
    if (frame.checksumValid &&
        frame.candidateCommand == kCashlessReaderControlCommand &&
        frame.normalizedLength >= 2 &&
        frame.normalized[1] == kCashlessReaderControlSubcommand) {
      if (frame.normalizedLength >= 3 && frame.normalized[2] == 0x00) {
        return DialogueKind::Disable;
      }
      return DialogueKind::Enable;
    }
    if (frame.checksumValid &&
        frame.candidateCommand == kCashlessReaderControlCommand &&
        frame.normalizedLength == 1 &&
        (readerState_ == ReaderState::ExpansionPending ||
         readerState_ == ReaderState::Disabled)) {
      return DialogueKind::Enable;
    }
  }
  return DialogueKind::Unknown;
}

bool MdbService::matchesCashlessDialogueAddress(uint8_t address,
                                                uint8_t command) const {
  if (!kMdbCashlessEnabled) {
    return false;
  }
  if (address == cashlessAddress_) {
    return true;
  }

  const uint8_t followupAddress =
      static_cast<uint8_t>((cashlessAddress_ + 1U) & 0x1FU);
  if (address != followupAddress) {
    return false;
  }

  const bool followupPhase =
      readerState_ == ReaderState::ExpansionPending ||
      readerState_ == ReaderState::Disabled ||
      readerState_ == ReaderState::Enabled ||
      readerState_ == ReaderState::PollActive ||
      readerState_ == ReaderState::SessionIdle ||
      readerState_ == ReaderState::SessionActive;
  if (!followupPhase) {
    return false;
  }

  return command == kCashlessReaderControlCommand ||
         command == kCashlessPollCommand ||
         command == kCashlessExpansionCommand ||
         command == kCashlessSetupCommand;
}

bool MdbService::matchesCoinChangerDialogueAddress(uint8_t address,
                                                   uint8_t command) const {
  if (!kMdbCoinChangerEnabled || address != kMdbCoinChangerAddress) {
    return false;
  }

  return command == kCoinChangerResetCommand ||
         command == kCoinChangerSetupCommand ||
         command == kCoinChangerTubeStatusCommand ||
         command == kCoinChangerPollCommand ||
         command == kCoinChangerCoinTypeCommand ||
         command == kCoinChangerDispenseCommand ||
         command == kCoinChangerExpansionCommand;
}

MdbService::DialogueKind MdbService::classifyTxFrameKind(const uint8_t* frame,
                                                         size_t length,
                                                         const char* txKind) const {
  if (frame == nullptr || length == 0) {
    return DialogueKind::Unknown;
  }
  if (length == 1) {
    if (frame[0] == mdb::kAck) {
      return DialogueKind::Ack;
    }
    if (frame[0] == mdb::kNak) {
      return DialogueKind::Nak;
    }
  }
  if (txKind != nullptr) {
    if (strcmp(txKind, "just_reset_status") == 0) {
      return DialogueKind::JustReset;
    }
    if (strcmp(txKind, "setup_response") == 0) {
      return DialogueKind::ReaderConfig;
    }
    if (strcmp(txKind, "expansion_response") == 0 ||
        strcmp(txKind, "setup_expansion_response") == 0) {
      return DialogueKind::ExpansionId;
    }
    if (strcmp(txKind, "begin_session") == 0 ||
        strcmp(txKind, "vend_approved") == 0 ||
        strcmp(txKind, "vend_denied") == 0 ||
        strcmp(txKind, "vend_denied_minimal") == 0 ||
        strcmp(txKind, "end_session") == 0 ||
        strcmp(txKind, "session_complete") == 0 ||
        strcmp(txKind, "revalue_limit_zero") == 0) {
      return DialogueKind::ReaderStateChange;
    }
    if (strcmp(txKind, "ack") == 0 || strstr(txKind, "ack") != nullptr) {
      return DialogueKind::Ack;
    }
  }
  if (length > 1) {
    if (frame[0] == 0x00) {
      return DialogueKind::JustReset;
    }
    if (frame[0] == 0x01) {
      return DialogueKind::ReaderConfig;
    }
    if (frame[0] == 0x09) {
      return DialogueKind::ExpansionId;
    }
  }
  return DialogueKind::Unknown;
}

void MdbService::appendDialogueEvent(DialogueDirection direction, DialogueKind kind,
                                     uint16_t raw9, uint8_t dataByte,
                                     bool ninthBit, ReaderState stateBefore,
                                     ReaderState stateAfter,
                                     const char* decision,
                                     unsigned long tsUs) {
  DialogueEvent& slot = dialogueHistory_[dialogueHistoryNext_];
  slot = {};
  slot.used = true;
  slot.tsUs = tsUs;
  slot.direction = static_cast<uint8_t>(direction);
  slot.kind = static_cast<uint8_t>(kind);
  slot.raw9 = raw9;
  slot.dataByte = dataByte;
  slot.ninthBit = ninthBit;
  slot.stateBefore = static_cast<uint8_t>(stateBefore);
  slot.stateAfter = static_cast<uint8_t>(stateAfter);
  copyReasonText(slot.decision, sizeof(slot.decision), decision);
  dialogueHistoryNext_ = (dialogueHistoryNext_ + 1U) % kDialogueHistorySize;
  if (dialogueHistoryCount_ < kDialogueHistorySize) {
    dialogueHistoryCount_++;
  }
  emitEvent("dialogue_trace",
            String("{\"timestamp_us\":") + tsUs + ",\"direction\":\"" +
                dialogueDirectionLabel(direction) + "\",\"kind\":\"" +
                dialogueKindLabel(kind) + "\",\"raw9\":" + raw9 +
                ",\"data_byte\":" + dataByte + ",\"ninth_bit\":" +
                boolToJson(ninthBit) + ",\"reader_state_before\":\"" +
                readerStateLabel(stateBefore) + "\",\"reader_state_after\":\"" +
                readerStateLabel(stateAfter) +
                "\",\"response_decision_reason\":\"" +
                escapeForJson(decision == nullptr ? "" : String(decision)) + "\"}");
}

void MdbService::transitionReaderState(ReaderState newState, const char* reason,
                                       unsigned long tsUs) {
  const ReaderState oldState = readerState_;
  if (oldState == newState) {
    return;
  }
  readerState_ = newState;
  stateTransitionCount_++;
  lastStateTransitionReason_ = reason == nullptr ? "" : reason;
  appendDialogueEvent(DialogueDirection::RxFromMachine,
                      DialogueKind::ReaderStateChange, 0, 0, false, oldState,
                      newState, reason, tsUs);
  if (kLogEveryStateTransition) {
    emitEvent("reader_state_transition",
              String("{\"old_state\":\"") + readerStateLabel(oldState) +
                  "\",\"new_state\":\"" + readerStateLabel(newState) +
                  "\",\"reason\":\"" +
                  escapeForJson(lastStateTransitionReason_) +
                  "\",\"timestamp_us\":" + tsUs + "}");
  }
  emitProtocolProgressExpectation(reason, tsUs);
}

void MdbService::noteNoResponse(const char* reason, unsigned long tsUs,
                                DialogueKind kind) {
  noResponseCount_++;
  lastNoResponseReason_ = reason == nullptr ? "" : reason;
  appendDialogueEvent(DialogueDirection::TxToMachine, kind, 0, 0, false,
                      readerState_, readerState_, reason, tsUs);
  emitEvent("poll_no_response",
            String("{\"reason\":\"") + escapeForJson(lastNoResponseReason_) +
                "\",\"timestamp_us\":" + tsUs + ",\"kind\":\"" +
                dialogueKindLabel(kind) + "\"}");
}

String MdbService::buildDialogueHistoryJson() const {
  String json = "[";
  for (size_t i = 0; i < dialogueHistoryCount_; ++i) {
    const size_t index =
        (dialogueHistoryNext_ + kDialogueHistorySize - dialogueHistoryCount_ + i) %
        kDialogueHistorySize;
    const DialogueEvent& event = dialogueHistory_[index];
    if (!event.used) {
      continue;
    }
    if (json.length() > 1) {
      json += ',';
    }
    json += String("{\"ts_us\":") + event.tsUs + ",\"direction\":\"" +
            dialogueDirectionLabel(
                static_cast<DialogueDirection>(event.direction)) +
            "\",\"kind\":\"" +
            dialogueKindLabel(static_cast<DialogueKind>(event.kind)) +
            "\",\"raw9\":" + event.raw9 + ",\"data_byte\":" + event.dataByte +
            ",\"ninth_bit\":" + boolToJson(event.ninthBit) +
            ",\"state_before\":\"" +
            readerStateLabel(static_cast<ReaderState>(event.stateBefore)) +
            "\",\"state_after\":\"" +
            readerStateLabel(static_cast<ReaderState>(event.stateAfter)) +
            "\",\"decision\":\"" + escapeForJson(String(event.decision)) + "\"}";
  }
  json += "]";
  return json;
}

String MdbService::expectedNextRxKindLabel() const {
  const auto standardExpectedNextRx = [&]() -> String {
    if (cashlessJustResetPending_) {
      return "POLL";
    }

    switch (readerState_) {
      case ReaderState::ResetSeen:
        return "SETUP_CONFIG_DATA";
      case ReaderState::SetupSeen:
      case ReaderState::SetupResponded:
      case ReaderState::ExpansionPending:
        if (!cashlessSetupMaxMinSeen_) {
          return "SETUP_MAX_MIN_OR_ENABLE_OR_OPTIONAL_EXPANSION_ID";
        }
        if (!cashlessExpansionSeen_) {
          return "ENABLE_OR_OPTIONAL_EXPANSION_ID";
        }
        if (!isReaderEnabled_) {
          return "ENABLE";
        }
        return "POLL";
      case ReaderState::Disabled:
        return "ENABLE_OR_POLL";
      case ReaderState::Enabled:
      case ReaderState::PollActive:
      case ReaderState::SessionIdle:
      case ReaderState::SessionActive:
        return "POLL";
      case ReaderState::Uninitialized:
        return "RESET_OR_SETUP";
      case ReaderState::Error:
      default:
        return "UNKNOWN";
    }
  };

  if (isWrapperContinuationPending(wrapperFsmState_,
                                   wrapperStandardFlowEntered_)) {
    const String wrapperExpected = wrapperExpectedNextRxKindLabel();
    if (!wrapperExpected.isEmpty()) {
      return wrapperExpected;
    }
  }

  return standardExpectedNextRx();
}

String MdbService::wrapperExpectedNextRxKindLabel() const {
  if (!wrapperExpectedNextRxKind_.isEmpty()) {
    return wrapperExpectedNextRxKind_;
  }
  if (cashlessJustResetPending_) {
    return "POLL";
  }

  switch (wrapperFsmState_) {
    case WrapperFsmState::SetupConfigSeen:
      return "NONE_BEFORE_READER_CONFIG";
    case WrapperFsmState::ReaderConfigSent:
    case WrapperFsmState::WaitingForContinuation:
      return "WRAPPER_CONTINUATION_OR_RESET_OR_RETRY";
    case WrapperFsmState::ContinuationTimeout:
      return gatewayCompatBusAliveAfterSetup_ ? "WRAPPER_RETRY_OR_RESET"
                                              : "WRAPPER_CONTINUATION_OR_RETRY_OR_RESET";
    case WrapperFsmState::ResetObserved:
      return "POLL_OR_SETUP_RESTART";
    case WrapperFsmState::RetryObserved:
      return "SETUP_RETRY_OR_RESET_OR_WRAPPER_CONTINUATION";
    case WrapperFsmState::ContinuedToStandardFlow:
      return "STANDARD_FLOW_CONTINUED";
    case WrapperFsmState::Idle:
    default:
      return "";
  }
}

String MdbService::expectedNextTxKindLabel() const {
  const auto standardExpectedNextTx = [&]() -> String {
    if (cashlessJustResetPending_) {
      return "just_reset_status";
    }

    switch (readerState_) {
      case ReaderState::ResetSeen:
        return "ack";
      case ReaderState::SetupSeen:
        return "setup_response";
      case ReaderState::SetupResponded:
      case ReaderState::ExpansionPending:
        if (!cashlessSetupMaxMinSeen_) {
          return "no_data_or_ack_or_expansion_response";
        }
        if (!cashlessExpansionSeen_) {
          return "ack_or_optional_expansion_response";
        }
        if (!isReaderEnabled_) {
          return "ack";
        }
        return "poll_reply";
      case ReaderState::Disabled:
        return "ack";
      case ReaderState::Enabled:
      case ReaderState::PollActive:
      case ReaderState::SessionIdle:
      case ReaderState::SessionActive:
        return "poll_reply";
      case ReaderState::Uninitialized:
        return "ack_or_setup_response";
      case ReaderState::Error:
      default:
        return "unknown";
    }
  };

  if (isWrapperContinuationPending(wrapperFsmState_,
                                   wrapperStandardFlowEntered_)) {
    if (wrapperFsmState_ == WrapperFsmState::SetupConfigSeen) {
      return "setup_response";
    }
    return "none_until_wrapper_continuation";
  }

  return standardExpectedNextTx();
}

String MdbService::wrapperExpectedNextActionLabel() const {
  if (!wrapperExpectedNextAction_.isEmpty()) {
    return wrapperExpectedNextAction_;
  }
  if (cashlessJustResetPending_) {
    return "WAIT_FOR_POLL_AFTER_RESET";
  }

  switch (wrapperFsmState_) {
    case WrapperFsmState::SetupConfigSeen:
      return "SEND_READER_CONFIG";
    case WrapperFsmState::ReaderConfigSent:
    case WrapperFsmState::WaitingForContinuation:
      return "WAIT_FOR_WRAPPER_CONTINUATION";
    case WrapperFsmState::ContinuationTimeout:
      return gatewayCompatBusAliveAfterSetup_ ? "WAIT_FOR_WRAPPER_RETRY_OR_RESET"
                                              : "WAIT_FOR_INITIAL_WRAPPER_CONTINUATION";
    case WrapperFsmState::ResetObserved:
      return "WAIT_FOR_RESET_RECOVERY";
    case WrapperFsmState::RetryObserved:
      return "WAIT_FOR_WRAPPER_RETRY_DECISION";
    case WrapperFsmState::ContinuedToStandardFlow:
      return "ENTER_STANDARD_CASHLESS_FLOW";
    case WrapperFsmState::Idle:
    default:
      return "";
  }
}

String MdbService::protocolProgressBlockerLabel() const {
  const String wrapperContinuationBlocker = buildWrapperContinuationBlockerLabel(
      wrapperFsmState_, wrapperStandardFlowEntered_,
      wrapperContinuationInterpretation_, wrapperTransitionReason_);
  if (!wrapperContinuationBlocker.isEmpty()) {
    return wrapperContinuationBlocker;
  }

  if ((readerState_ == ReaderState::SetupResponded ||
       readerState_ == ReaderState::ExpansionPending) &&
      !cashlessSetupMaxMinSeen_) {
    if (!lastRepeatedSetupReasonGuess_.isEmpty()) {
      return String("waiting_for_setup_max_min_or_enable_or_optional_expansion/") +
             lastRepeatedSetupReasonGuess_;
    }
    return "waiting_for_setup_max_min_or_enable_or_optional_expansion";
  }
  if (readerState_ == ReaderState::ExpansionPending && cashlessSetupMaxMinSeen_ &&
      !cashlessExpansionSeen_ && !isReaderEnabled_) {
    if (lastRxKind_ == DialogueKind::Unknown && !lastUnknownReason_.isEmpty()) {
      return String("waiting_for_enable_or_optional_expansion/") +
             lastUnknownReason_;
    }
    return "waiting_for_enable_or_optional_expansion";
  }
  if (readerState_ == ReaderState::Disabled && !isReaderEnabled_) {
    return "waiting_for_reader_enable";
  }
  if (cashlessJustResetPending_ && pollRxCount_ == 0) {
    if (!lastResetCauseGuess_.isEmpty()) {
      return String("waiting_for_poll_after_reset/") + lastResetCauseGuess_;
    }
    return "waiting_for_poll_after_reset";
  }
  if ((readerState_ == ReaderState::Enabled ||
       readerState_ == ReaderState::SessionIdle) &&
      pollRxCount_ == 0) {
    return "waiting_for_poll";
  }
  return "";
}

String MdbService::setupProgressionBlockerLabel() const {
  const String wrapperContinuationBlocker = buildWrapperContinuationBlockerLabel(
      wrapperFsmState_, wrapperStandardFlowEntered_,
      wrapperContinuationInterpretation_, wrapperTransitionReason_);
  if (!wrapperContinuationBlocker.isEmpty()) {
    return wrapperContinuationBlocker;
  }

  if (!cashlessSetupSeen_) {
    return "";
  }
  if (!cashlessSetupMaxMinSeen_) {
    if (!lastRepeatedSetupReasonGuess_.isEmpty()) {
      return String("waiting_for_setup_max_min_or_retry/") +
             lastRepeatedSetupReasonGuess_;
    }
    return "waiting_for_setup_max_min_or_retry";
  }
  if (!isReaderEnabled_ && !cashlessExpansionSeen_) {
    return "waiting_for_enable_or_optional_expansion";
  }
  if (!isReaderEnabled_) {
    return "waiting_for_enable";
  }
  return "waiting_for_poll";
}

String MdbService::foreignTrafficCausalLabel() const {
  if (lastUnknownReason_.startsWith("foreign_address_")) {
    return "false";
  }
  return "unknown";
}

int16_t MdbService::setupSubcommandValue(const machine::Frame& frame) const {
  if (!frame.checksumValid || frame.candidateCommand != kCashlessSetupCommand ||
      frame.normalizedLength < 2) {
    return -1;
  }
  return static_cast<int16_t>(frame.normalized[1]);
}

const GatewayCompatProfileConfig& MdbService::gatewayCompatProfileConfig() const {
  return selectGatewayCompatProfileConfig(
      sanitizeGatewayCompatProfileId(gatewayCompatResponseProfileId_));
}

const char* MdbService::gatewayCompatResponseProfileIdLabel() const {
  return gatewayCompatProfileConfig().profileLabel;
}

const char* MdbService::gatewayCurrencyCountryCodeProfileIdLabel() const {
  return gatewayCompatProfileConfig().currencyProfileLabel;
}

uint8_t MdbService::gatewayCompatResponseTime() const {
  return gatewayCompatProfileConfig().responseTime;
}

uint8_t MdbService::gatewayCompatResponseOptions() const {
  return gatewayCompatProfileConfig().options;
}

uint8_t MdbService::gatewayCompatCurrencyCountryCodeHi() const {
  return gatewayCompatProfileConfig().currencyCountryCodeHi;
}

uint8_t MdbService::gatewayCompatCurrencyCountryCodeLo() const {
  return gatewayCompatProfileConfig().currencyCountryCodeLo;
}

const char* MdbService::gatewayCurrencyCountryCodeEncodingModeLabel() const {
  return gatewayCompatProfileConfig().currencyEncodingModeLabel;
}

String MdbService::gatewayCurrencyCountryCodeBytesHex() const {
  return byteToHex(gatewayCompatCurrencyCountryCodeHi()) + " " +
         byteToHex(gatewayCompatCurrencyCountryCodeLo());
}

bool MdbService::gatewayCurrencyCountryCodeChangedFromProfile1() const {
  return gatewayCompatProfileConfig().currencyEncodingChangedFromProfile1;
}

const char* MdbService::gatewayCompatSemanticSuspectFieldLabel() const {
  return gatewayCompatProfileConfig().semanticSuspectFieldLabel;
}

bool MdbService::gatewayWrapperRetryAfterLongSilence() const {
  return lastSetupToRepeatUs_ >= kGatewayWrapperLongRetryCycleUs;
}

String MdbService::gatewayWrapperExpectedNextActionLabel() const {
  const bool gatewayContext =
      lastSetupVariant_ == "SETUP_CONFIG_GATEWAY_COMPAT" ||
      previousSetupVariant_ == "SETUP_CONFIG_GATEWAY_COMPAT" ||
      !gatewayCompatLastOutcome_.isEmpty();
  if (!gatewayContext) {
    return expectedNextRxKindLabel();
  }
  if (wrapperFsmState_ != WrapperFsmState::Idle) {
    const String wrapperExpectedAction = wrapperExpectedNextActionLabel();
    if (!wrapperExpectedAction.isEmpty()) {
      return wrapperExpectedAction;
    }
  }
  if (gatewayCompatLastOutcome_ == "reset" || repeatedSetupThenResetObserved_) {
    return "POLL_AFTER_RESET_ACK_OR_WRAPPER_RESTART";
  }
  if (gatewayWrapperLongRetryObserved()) {
    return "WRAPPER_RETRY_OR_RESET_RECOVERY";
  }
  if (gatewayWrapperFollowupMissing() || gatewayCompatLastOutcome_ == "awaiting_followup") {
    return "SETUP_MAX_MIN_OR_ENABLE_OR_OPTIONAL_EXPANSION_OR_WRAPPER_CONTINUATION";
  }
  if (!gatewayCompatExpectedFollowup_.isEmpty()) {
    return gatewayCompatExpectedFollowup_;
  }
  return expectedNextRxKindLabel();
}

bool MdbService::gatewayWrapperFollowupMissing() const {
  return wrapperFsmState_ == WrapperFsmState::ContinuationTimeout ||
         gatewayCompatLastOutcome_ == "no_followup_timeout";
}

bool MdbService::gatewayWrapperLongRetryObserved() const {
  return gatewayCompatLastOutcome_ == "long_retry_cycle_observed" ||
         gatewayWrapperRetryAfterLongSilence();
}

bool MdbService::gatewayWrapperResetAfterSilence() const {
  return repeatedSetupThenResetObserved_ && gatewayWrapperRetryAfterLongSilence();
}

String MdbService::gatewayWrapperMissingStepHypothesisLabel() const {
  const bool gatewayContext =
      lastSetupVariant_ == "SETUP_CONFIG_GATEWAY_COMPAT" ||
      previousSetupVariant_ == "SETUP_CONFIG_GATEWAY_COMPAT" ||
      gatewayCompatLastOutcome_ == "no_followup_timeout" ||
      gatewayCompatLastOutcome_ == "repeated_same_setup" ||
      gatewayCompatLastOutcome_ == "long_retry_cycle_observed";
  if (!gatewayContext) {
    return "";
  }

  if (gatewayWrapperResetAfterSilence()) {
    return "gateway_wrapper_handshake_not_accepted_vmc_restarts_setup_after_watchdog_cycle";
  }
  if (wrapperFsmState_ == WrapperFsmState::ContinuationTimeout &&
      gatewayCompatBusAliveAfterSetup_) {
    return "gateway_wrapper_followup_missing_but_bus_alive";
  }
  if (gatewayCompatLastOutcome_ == "long_retry_cycle_observed") {
    return "gateway_wrapper_watchdog_retry_without_standard_followup";
  }
  if (gatewayCompatLastOutcome_ == "repeated_same_setup" ||
      gatewayCompatLastOutcome_ == "repeated_setup_variant") {
    return "gateway_wrapper_reissues_setup_without_acceptance";
  }
  if (gatewayCompatLastOutcome_ == "no_followup_timeout") {
    return "gateway_wrapper_followup_missing_after_reader_config";
  }
  if (gatewayCompatLastOutcome_ == "reset") {
    return "vmc_reset_recovery_path_after_gateway_setup";
  }
  if (gatewayCompatLastOutcome_ == "foreign_traffic") {
    return "followup_obscured_by_foreign_address_traffic";
  }
  if (gatewayCompatLastOutcome_ == "awaiting_followup") {
    return "awaiting_gateway_wrapper_followup";
  }
  return "";
}

String MdbService::gatewayWrapperAcceptanceStateLabel() const {
  if (setupResponseRejectedByVmc_ == "true") {
    return "explicit_rejection";
  }
  if (gatewayCompatLastOutcome_ == "setup_max_min" ||
      gatewayCompatLastOutcome_ == "enable" ||
      gatewayCompatLastOutcome_ == "optional_expansion" ||
      gatewayCompatLastOutcome_ == "poll" ||
      gatewayCompatLastOutcome_ == "setup_other_variant") {
    return "progressed";
  }
  if (gatewayCompatLastOutcome_ == "long_retry_cycle_observed") {
    return "wrapper_retry_after_silence";
  }
  if (gatewayCompatLastOutcome_ == "repeated_same_setup" ||
      gatewayCompatLastOutcome_ == "repeated_setup_variant") {
    return "wrapper_retry_without_progress";
  }
  if (gatewayCompatLastOutcome_ == "no_followup_timeout") {
    return "immediate_followup_missing";
  }
  if (wrapperFsmState_ == WrapperFsmState::ContinuationTimeout &&
      gatewayCompatBusAliveAfterSetup_) {
    return "wrapper_followup_missing_but_bus_alive";
  }
  if (gatewayCompatLastOutcome_ == "reset") {
    return "reset_recovery_path";
  }
  if (gatewayCompatLastOutcome_ == "awaiting_followup" ||
      gatewayCompatLastOutcome_ == "first_gateway_setup_observed" ||
      gatewayCompatLastOutcome_ == "idle" ||
      gatewayCompatLastOutcome_.isEmpty()) {
    return "awaiting_followup";
  }
  return "unknown";
}

String MdbService::gatewayWrapperPhaseLabel() const {
  const bool gatewayContext =
      lastSetupVariant_ == "SETUP_CONFIG_GATEWAY_COMPAT" ||
      previousSetupVariant_ == "SETUP_CONFIG_GATEWAY_COMPAT" ||
      gatewayCompatLastOutcome_ == "awaiting_followup" ||
      gatewayCompatLastOutcome_ == "no_followup_timeout" ||
      gatewayCompatLastOutcome_ == "repeated_same_setup" ||
      gatewayCompatLastOutcome_ == "long_retry_cycle_observed" ||
      gatewayCompatLastOutcome_ == "reset";
  if (!gatewayContext) {
    return "IDLE";
  }
  if (wrapperFsmState_ != WrapperFsmState::Idle) {
    return wrapperFsmStateLabel(wrapperFsmState_);
  }
  if (lastSetupSeenUs_ > 0) {
    return "WRAPPER_SETUP_CONFIG_SEEN";
  }
  return "IDLE";
}

String MdbService::buildSetupVariantLabel(const machine::Frame& frame) const {
  if (!frame.checksumValid || frame.candidateCommand != kCashlessSetupCommand) {
    return "";
  }
  if (frame.normalizedLength >= 4 &&
      frame.normalized[1] == kObservedGatewaySetupPayload1 &&
      frame.normalized[2] == kObservedGatewaySetupPayload2 &&
      frame.normalized[3] == kObservedGatewaySetupPayload3) {
    return "SETUP_CONFIG_GATEWAY_COMPAT";
  }
  if (frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessSetupMaxMinSubcommand) {
    return "SETUP_MAX_MIN_PRICE";
  }
  if (frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessSetupSubcommand) {
    return "SETUP_CONFIG_STANDARD";
  }
  if (frame.normalizedLength < 2) {
    return "SETUP_CONFIG_NO_SUBCOMMAND";
  }
  return String("SETUP_CONFIG_VARIANT_") + byteToHex(frame.normalized[1]);
}

String MdbService::buildSetupClassificationReason(
    const machine::Frame& frame) const {
  if (!frame.checksumValid || frame.candidateCommand != kCashlessSetupCommand) {
    return "not_setup";
  }
  if (frame.normalizedLength >= 4 &&
      frame.normalized[1] == kObservedGatewaySetupPayload1 &&
      frame.normalized[2] == kObservedGatewaySetupPayload2 &&
      frame.normalized[3] == kObservedGatewaySetupPayload3) {
    return "gateway_setup_wrapper_observed";
  }
  if (frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessSetupMaxMinSubcommand) {
    return "setup_subcommand_01_max_min";
  }
  if (frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessSetupSubcommand) {
    return "setup_subcommand_00_config";
  }
  if (frame.normalizedLength < 2) {
    return "setup_without_explicit_subcommand";
  }
  return String("setup_unrecognized_subcommand_") + byteToHex(frame.normalized[1]);
}

void MdbService::noteSetupObserved(const machine::Frame& frame, unsigned long tsUs,
                                   const char* handlerReason) {
  if (!frame.checksumValid || frame.candidateCommand != kCashlessSetupCommand) {
    return;
  }

  const String variant = buildSetupVariantLabel(frame);
  const String frameHex = machine::normalizedHex(frame);
  const int16_t subcommand = setupSubcommandValue(frame);
  const unsigned long raw9 = frame.normalizedLength > 0
                                 ? raw9Word(frame.normalized[0], true)
                                 : 0;
  const unsigned long elapsedSinceLastSetupResponseUs =
      (lastSetupResponseTxUs_ > 0 && tsUs >= lastSetupResponseTxUs_)
          ? (tsUs - lastSetupResponseTxUs_)
          : 0;
  const bool longRetryCycle =
      elapsedSinceLastSetupResponseUs >= kGatewayWrapperLongRetryCycleUs;

  String repeatedReasonGuess = "first_setup_observed";
  String repeatedInterpretation = "first_setup_observed";
  if (lastSetupSeenUs_ > 0) {
    repeatedSetupCount_++;
    if (lastSetupHex_ == frameHex) {
      repeatedSetupSamePayloadCount_++;
      lastSetupToRepeatUs_ = elapsedSinceLastSetupResponseUs;
      repeatedReasonGuess = longRetryCycle
                                ? "vmc_retry_same_setup_after_long_silence"
                                : "vmc_retry_same_setup_after_setup_response";
      repeatedInterpretation =
          longRetryCycle ? "wrapper_retry_after_silence"
                         : "wrapper_retry_without_progress";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "unknown";
        setupRejectionBasis_ = longRetryCycle
                                   ? "repeated_same_setup_after_long_silence"
                                   : "repeated_same_setup_retry";
      }
    } else if (lastSetupVariant_ == variant) {
      repeatedSetupVariantCount_++;
      lastSetupToRepeatUs_ = elapsedSinceLastSetupResponseUs;
      repeatedReasonGuess =
          longRetryCycle
              ? "vmc_retry_same_setup_variant_after_long_silence"
              : "vmc_retry_same_setup_variant_after_setup_response";
      repeatedInterpretation =
          longRetryCycle ? "long_retry_cycle_observed"
                         : "wrapper_retry_without_progress";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "unknown";
        setupRejectionBasis_ = longRetryCycle
                                   ? "repeated_setup_variant_after_long_silence"
                                   : "repeated_setup_variant_retry";
      }
    } else {
      repeatedSetupVariantCount_++;
      lastSetupToRepeatUs_ = elapsedSinceLastSetupResponseUs;
      repeatedReasonGuess = "multi_step_setup_variant_progression";
      repeatedInterpretation = "expected_multi_step_gateway_progression";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "false";
        setupRejectionBasis_ = "multi_step_setup_progression";
      }
    }
  } else if (variant == "SETUP_MAX_MIN_PRICE") {
    repeatedReasonGuess = "expected_multi_step_setup_max_min";
    repeatedInterpretation = "expected_multi_step_setup_max_min";
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "false";
      setupRejectionBasis_ = "setup_max_min_progression";
    }
  }

  if (lastSetupSeenUs_ > 0) {
    previousSetupVariant_ = lastSetupVariant_;
    previousSetupRaw9_ = lastSetupRaw9_;
    previousSetupTimestampUs_ = lastSetupSeenUs_;
  }
  lastSetupSeenUs_ = tsUs;
  lastSetupRaw9_ = static_cast<uint16_t>(raw9);
  lastSetupSubcommand_ = subcommand;
  lastSetupVariant_ = variant;
  lastSetupHex_ = frameHex;
  lastRepeatedSetupReasonGuess_ = repeatedReasonGuess;
  repeatedSetupInterpretation_ = repeatedInterpretation;
  if (variant == "SETUP_CONFIG_GATEWAY_COMPAT") {
    wrapperStandardFlowEntered_ = false;
    wrapperExpectedNextRxKind_ = "SETUP_RETRY_OR_ENABLE_OR_POLL";
    wrapperExpectedNextAction_ = "SEND_READER_CONFIG";
    if (lastSetupSeenUs_ == tsUs && gatewayCompatLastSetupResponseUs_ == 0) {
      setWrapperFsmState(WrapperFsmState::SetupConfigSeen,
                         "gateway_setup_config_seen", tsUs);
    }
    gatewayCompatRetryInterpretation_ = repeatedInterpretation;
    if (longRetryCycle &&
        (repeatedReasonGuess == "vmc_retry_same_setup_after_long_silence" ||
         repeatedReasonGuess ==
             "vmc_retry_same_setup_variant_after_long_silence")) {
      gatewayCompatLastOutcome_ = "long_retry_cycle_observed";
      wrapperContinuationKind_ = "repeated_same_setup";
      wrapperContinuationRaw9_ = static_cast<uint16_t>(raw9);
      wrapperContinuationDeltaUs_ = elapsedSinceLastSetupResponseUs;
      wrapperContinuationInterpretation_ = "wrapper_retry_after_silence";
      if (gatewayCompatResponseProfileId_ < 1) {
        const uint8_t oldProfileId = gatewayCompatResponseProfileId_;
        setGatewayCompatResponseProfile(static_cast<uint8_t>(oldProfileId + 1));
        emitEvent("gateway_compat_profile_escalated",
                  String("{\"old_profile_id\":") + oldProfileId +
                      ",\"new_profile_id\":" + gatewayCompatResponseProfileId_ +
                      ",\"reason\":\"long_retry_cycle_same_setup\""
                      ",\"elapsed_since_last_setup_response_us\":" +
                      elapsedSinceLastSetupResponseUs + "}");
      } else {
        emitEvent("gateway_compat_profile_escalation_blocked",
                  String("{\"current_profile_id\":") + gatewayCompatResponseProfileId_ +
                      ",\"reason\":\"alt2_currency_disabled_after_reset_rejection\""
                      ",\"elapsed_since_last_setup_response_us\":" +
                      elapsedSinceLastSetupResponseUs + "}");
      }
      setWrapperFsmState(WrapperFsmState::RetryObserved,
                         "gateway_wrapper_long_retry_observed", tsUs);
    } else if (repeatedReasonGuess ==
               "vmc_retry_same_setup_after_setup_response") {
      gatewayCompatLastOutcome_ = "repeated_same_setup";
      wrapperContinuationKind_ = "repeated_same_setup";
      wrapperContinuationRaw9_ = static_cast<uint16_t>(raw9);
      wrapperContinuationDeltaUs_ = elapsedSinceLastSetupResponseUs;
      wrapperContinuationInterpretation_ = "wrapper_retry_without_progress";
      setWrapperFsmState(WrapperFsmState::RetryObserved,
                         "gateway_wrapper_same_setup_retry", tsUs);
    } else if (repeatedReasonGuess ==
               "vmc_retry_same_setup_variant_after_setup_response") {
      gatewayCompatLastOutcome_ = "repeated_setup_variant";
      wrapperContinuationKind_ = "repeated_setup_variant";
      wrapperContinuationRaw9_ = static_cast<uint16_t>(raw9);
      wrapperContinuationDeltaUs_ = elapsedSinceLastSetupResponseUs;
      wrapperContinuationInterpretation_ = "wrapper_retry_without_progress";
      setWrapperFsmState(WrapperFsmState::RetryObserved,
                         "gateway_wrapper_variant_retry", tsUs);
    } else if (repeatedReasonGuess == "first_setup_observed") {
      gatewayCompatLastOutcome_ = "first_gateway_setup_observed";
      wrapperContinuationKind_ = "";
      wrapperContinuationRaw9_ = 0;
      wrapperContinuationDeltaUs_ = 0;
      wrapperContinuationInterpretation_ = "wrapper_setup_config_seen";
      setWrapperFsmState(WrapperFsmState::SetupConfigSeen,
                         "gateway_setup_config_seen", tsUs);
    }
  } else if (variant == "SETUP_MAX_MIN_PRICE") {
    gatewayCompatLastOutcome_ = "setup_max_min";
  }

  emitEvent("setup_variant_observed",
            String("{\"timestamp_us\":") + tsUs +
                ",\"frame_hex\":\"" + escapeForJson(frameHex) +
                "\",\"setup_variant\":\"" + escapeForJson(variant) +
                "\",\"setup_subcommand\":" + subcommand +
                ",\"classification_reason\":\"" +
                escapeForJson(buildSetupClassificationReason(frame)) +
                "\",\"repeated_setup_count\":" + repeatedSetupCount_ +
                ",\"repeated_setup_same_payload_count\":" +
                repeatedSetupSamePayloadCount_ +
                ",\"repeated_setup_variant_count\":" +
                repeatedSetupVariantCount_ +
                ",\"elapsed_since_last_setup_response_us\":" +
                elapsedSinceLastSetupResponseUs +
                ",\"repeated_setup_reason_guess\":\"" +
                escapeForJson(repeatedReasonGuess) +
                "\",\"repeated_setup_interpretation\":\"" +
                escapeForJson(repeatedInterpretation) +
                "\",\"gateway_wrapper_cycle_delta_us\":" +
                elapsedSinceLastSetupResponseUs +
                ",\"gateway_wrapper_retry_after_60s\":" +
                boolToJson(longRetryCycle) +
                ",\"wrapper_fsm_state\":\"" +
                escapeForJson(gatewayWrapperPhaseLabel()) +
                "\",\"wrapper_expected_next_rx_kind\":\"" +
                escapeForJson(wrapperExpectedNextRxKindLabel()) +
                "\",\"wrapper_expected_next_action\":\"" +
                escapeForJson(wrapperExpectedNextActionLabel()) +
                "\",\"wrapper_standard_flow_entered\":" +
                boolToJson(wrapperStandardFlowEntered_) +
                ",\"wrapper_phase\":\"" +
                escapeForJson(gatewayWrapperPhaseLabel()) +
                "\",\"wrapper_handshake_acceptance\":\"" +
                escapeForJson(gatewayWrapperAcceptanceStateLabel()) +
                "\",\"next_expected_stage\":\"" +
                escapeForJson(expectedNextRxKindLabel()) +
                "\",\"handler_reason\":\"" +
                escapeForJson(handlerReason == nullptr ? "" : String(handlerReason)) +
                "\"}");
}

void MdbService::armGatewayCompatFollowupTracking(unsigned long txStartUs) {
  gatewayCompatLastSetupResponseUs_ = txStartUs;
  gatewayCompatFollowupActive_ = true;
  gatewayCompatFirstFollowupCaptured_ = false;
  gatewayCompatTotalFramesSeenAtArm_ = totalFramesSeen_;
  gatewayCompatBusAliveAfterSetup_ = false;
  gatewayCompatExpectedFollowup_ =
      "WRAPPER_CONTINUATION_OR_RESET_OR_RETRY";
  gatewayCompatSemanticSuspectField_ =
      gatewayCompatSemanticSuspectFieldLabel();
  gatewayCompatLastOutcome_ = "awaiting_followup";
  gatewayCompatRetryInterpretation_ = "awaiting_followup";
  wrapperStandardFlowEntered_ = false;
  wrapperExpectedNextRxKind_ = "WRAPPER_CONTINUATION_OR_RESET_OR_RETRY";
  wrapperExpectedNextAction_ = "WAIT_FOR_WRAPPER_CONTINUATION";
  wrapperContinuationKind_ = "";
  wrapperContinuationRaw9_ = 0;
  wrapperContinuationDeltaUs_ = 0;
  wrapperContinuationInterpretation_ = "awaiting_wrapper_continuation";
  wrapperAckSemanticsMode_ = WrapperAckSemanticsMode::WrapperContinuationOnly;
  wrapperAckSemanticsSuspect_ = true;
  setWrapperFsmState(WrapperFsmState::ReaderConfigSent,
                     "gateway_reader_config_sent", txStartUs);
  setWrapperFsmState(WrapperFsmState::WaitingForContinuation,
                     "gateway_waiting_for_continuation", txStartUs);
  firstFollowupKindAfterSetup_ = "";
  firstFollowupRaw9AfterSetup_ = 0;
  firstFollowupDeltaUs_ = 0;
  firstFollowupInterpretation_ = "";
  setupNakCausal_ = "unknown";
  setupNakInterpretation_ = "";
  const String wrapperPhase = gatewayWrapperPhaseLabel();
  emitEvent("gateway_compat_followup_armed",
            String("{\"tx_start_us\":") + txStartUs +
                ",\"profile_id\":\"" +
                escapeForJson(gatewayCompatResponseProfileIdLabel()) +
                "\",\"expected_followup\":\"" +
                escapeForJson(gatewayCompatExpectedFollowup_) +
                "\"" + buildWrapperPhaseAndStateJson(wrapperPhase, wrapperPhase) +
                "\",\"wrapper_ack_semantics_mode\":\"" +
                escapeForJson(
                    wrapperAckSemanticsModeLabel(wrapperAckSemanticsMode_)) +
                "\",\"wrapper_expected_peer_action\":\"" +
                escapeForJson(gatewayWrapperExpectedNextActionLabel()) +
                "\",\"followup_timeout_us\":" +
                gatewayCompatFollowupTimeoutUs_ +
                ",\"semantic_suspect_field\":\"" +
                escapeForJson(gatewayCompatSemanticSuspectField_) + "\"}");
}

void MdbService::noteGatewayCompatFollowup(const machine::Frame& frame,
                                           DialogueKind kind) {
  if (!gatewayCompatFollowupActive_ || gatewayCompatFirstFollowupCaptured_ ||
      gatewayCompatLastSetupResponseUs_ == 0 ||
      frame.endedAtUs < gatewayCompatLastSetupResponseUs_) {
    return;
  }

  const String frameHex = machine::normalizedHex(frame);
  String followupKind;
  String interpretation;
  bool captureAsContinuation = true;

  if (kind == DialogueKind::Setup) {
    const String variant = buildSetupVariantLabel(frame);
    if (variant == "SETUP_MAX_MIN_PRICE") {
      followupKind = "setup_max_min";
      interpretation = "wrapper_continued_with_setup_max_min";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "false";
        setupRejectionBasis_ = "setup_max_min_progression";
      }
    } else if (!lastSetupHex_.isEmpty() && frameHex == lastSetupHex_) {
      followupKind = "repeated_same_setup";
      interpretation = gatewayWrapperRetryAfterLongSilence()
                           ? "wrapper_retry_after_silence"
                           : "wrapper_retry_without_progress";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "unknown";
        setupRejectionBasis_ = "repeated_same_setup_retry";
      }
    } else if (!lastSetupVariant_.isEmpty() && variant == lastSetupVariant_) {
      followupKind = "repeated_setup_variant";
      interpretation = gatewayWrapperRetryAfterLongSilence()
                           ? "wrapper_retry_after_silence"
                           : "wrapper_retry_without_progress";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "unknown";
        setupRejectionBasis_ = "repeated_setup_variant_retry";
      }
    } else {
      followupKind = "setup_other_variant";
      interpretation = "wrapper_unknown_continuation";
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "false";
        setupRejectionBasis_ = "multi_step_setup_progression";
      }
    }
  } else if (kind == DialogueKind::Enable) {
    followupKind = "enable";
    interpretation = "wrapper_continued_with_enable";
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "false";
      setupRejectionBasis_ = "enable_progression";
    }
  } else if (kind == DialogueKind::ExpansionId) {
    followupKind = "optional_expansion";
    interpretation = "wrapper_continued_with_expansion";
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "false";
      setupRejectionBasis_ = "expansion_progression";
    }
  } else if (kind == DialogueKind::Nak) {
    followupKind = "nak";
    interpretation = "wrapper_retry_without_progress";
    setupNakCausal_ = "true";
    setupNakInterpretation_ = interpretation;
    setupResponseRejectedByVmc_ = "true";
    setupRejectionBasis_ = "explicit_nak";
  } else if (kind == DialogueKind::Reset) {
    followupKind = "reset";
    interpretation = "wrapper_reset_after_reader_config";
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "unknown";
      setupRejectionBasis_ = "reset_after_setup_response";
    }
  } else if (kind == DialogueKind::Unknown &&
             buildUnknownRxReason(frame).startsWith("foreign_address_")) {
    followupKind = "foreign_traffic";
    interpretation = "wrapper_unknown_continuation";
    if (setupNakCausal_ != "true") {
      setupNakCausal_ = "false";
      setupNakInterpretation_ = "nak_not_observed_in_followup_window";
    }
    captureAsContinuation = false;
  } else if (kind == DialogueKind::Ack) {
    followupKind = "ack";
    interpretation = "wrapper_unknown_continuation";
    captureAsContinuation = false;
  } else if (kind == DialogueKind::Poll) {
    followupKind = "poll";
    interpretation = "wrapper_unknown_continuation";
  } else {
    followupKind = dialogueKindLabel(kind);
    interpretation = "wrapper_unknown_continuation";
    captureAsContinuation = false;
  }

  if (!captureAsContinuation) {
    gatewayCompatBusAliveAfterSetup_ = true;
    emitEvent("gateway_compat_non_continuation_observed",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"kind\":\"" + escapeForJson(followupKind) +
                  "\",\"interpretation\":\"" + escapeForJson(interpretation) +
                  "\",\"wrapper_phase\":\"" +
                  escapeForJson(gatewayWrapperPhaseLabel()) +
                  "\",\"wrapper_expected_next_rx_kind\":\"" +
                  escapeForJson(wrapperExpectedNextRxKindLabel()) + "\"}");
    return;
  }

  gatewayCompatFirstFollowupCaptured_ = true;
  gatewayCompatFollowupActive_ = false;
  firstFollowupKindAfterSetup_ = followupKind;
  firstFollowupRaw9AfterSetup_ = lastAcceptedRxFrame_.raw9;
  firstFollowupDeltaUs_ = frame.endedAtUs - gatewayCompatLastSetupResponseUs_;
  firstFollowupInterpretation_ = interpretation;
  gatewayCompatLastOutcome_ = followupKind;
  gatewayCompatRetryInterpretation_ = interpretation;
  wrapperContinuationKind_ = followupKind;
  wrapperContinuationRaw9_ = firstFollowupRaw9AfterSetup_;
  wrapperContinuationDeltaUs_ = firstFollowupDeltaUs_;
  wrapperContinuationInterpretation_ = interpretation;

  if (followupKind == "setup_max_min") {
    wrapperStandardFlowEntered_ = true;
    wrapperExpectedNextRxKind_ = "ENABLE_OR_OPTIONAL_EXPANSION_ID";
    wrapperExpectedNextAction_ = "ENTER_STANDARD_CASHLESS_FLOW";
    setWrapperFsmState(WrapperFsmState::ContinuedToStandardFlow,
                       "wrapper_continued_to_setup_max_min", frame.endedAtUs);
  } else if (followupKind == "enable" || followupKind == "optional_expansion" ||
             followupKind == "setup_other_variant" || followupKind == "poll") {
    wrapperStandardFlowEntered_ = true;
    wrapperExpectedNextRxKind_ = "STANDARD_FLOW_ACTIVE";
    wrapperExpectedNextAction_ = "ENTER_STANDARD_CASHLESS_FLOW";
    setWrapperFsmState(WrapperFsmState::ContinuedToStandardFlow,
                       "wrapper_continued_to_standard_flow", frame.endedAtUs);
  } else if (followupKind == "reset") {
    wrapperExpectedNextRxKind_ = "POLL_OR_SETUP_RESTART";
    wrapperExpectedNextAction_ = "WAIT_FOR_RESET_RECOVERY";
    setWrapperFsmState(WrapperFsmState::ResetObserved,
                       "wrapper_reset_after_reader_config", frame.endedAtUs);
  } else if (followupKind == "repeated_same_setup" ||
             followupKind == "repeated_setup_variant" ||
             followupKind == "nak") {
    wrapperExpectedNextRxKind_ = "SETUP_RETRY_OR_RESET_OR_WRAPPER_CONTINUATION";
    wrapperExpectedNextAction_ = "WAIT_FOR_WRAPPER_RETRY_DECISION";
    setWrapperFsmState(WrapperFsmState::RetryObserved,
                       "wrapper_retry_observed", frame.endedAtUs);
  }

  const String wrapperPhase = gatewayWrapperPhaseLabel();
  emitEvent("gateway_compat_followup_observed",
            String("{\"timestamp_us\":") + frame.endedAtUs +
                ",\"first_followup_kind_after_setup\":\"" +
                escapeForJson(firstFollowupKindAfterSetup_) +
                "\",\"first_followup_raw9_after_setup\":" +
                firstFollowupRaw9AfterSetup_ +
                ",\"first_followup_delta_us\":" + firstFollowupDeltaUs_ +
                ",\"first_followup_interpretation\":\"" +
                escapeForJson(firstFollowupInterpretation_) +
                "\",\"wrapper_continuation_kind\":\"" +
                escapeForJson(wrapperContinuationKind_) +
                "\",\"wrapper_continuation_raw9\":" +
                wrapperContinuationRaw9_ +
                ",\"wrapper_continuation_delta_us\":" +
                wrapperContinuationDeltaUs_ +
                ",\"wrapper_continuation_interpretation\":\"" +
                escapeForJson(wrapperContinuationInterpretation_) +
                "\"" + buildWrapperPhaseAndStateJson(wrapperPhase, wrapperPhase) +
                "\",\"wrapper_standard_flow_entered\":" +
                boolToJson(wrapperStandardFlowEntered_) +
                ",\"wrapper_expected_next_rx_kind\":\"" +
                escapeForJson(wrapperExpectedNextRxKindLabel()) +
                "\",\"wrapper_expected_next_action\":\"" +
                escapeForJson(wrapperExpectedNextActionLabel()) +
                "\",\"wrapper_handshake_acceptance\":\"" +
                escapeForJson(gatewayWrapperAcceptanceStateLabel()) +
                "\",\"setup_response_profile_id\":\"" +
                escapeForJson(gatewayCompatResponseProfileIdLabel()) +
                "\",\"semantic_suspect_field\":\"" +
                escapeForJson(gatewayCompatSemanticSuspectField_) + "\"}");
}

void MdbService::noteGatewayCompatFollowupTimeout(unsigned long nowUs) {
  if (!gatewayCompatFollowupActive_ || gatewayCompatFirstFollowupCaptured_ ||
      gatewayCompatLastSetupResponseUs_ == 0 ||
      nowUs < gatewayCompatLastSetupResponseUs_) {
    return;
  }

  gatewayCompatBusAliveAfterSetup_ =
      totalFramesSeen_ > gatewayCompatTotalFramesSeenAtArm_ ||
      gatewayCompatBusAliveAfterSetup_;
  firstFollowupKindAfterSetup_ = "no_followup_timeout";
  firstFollowupRaw9AfterSetup_ = 0;
  firstFollowupDeltaUs_ = nowUs - gatewayCompatLastSetupResponseUs_;
  firstFollowupInterpretation_ = gatewayCompatBusAliveAfterSetup_
                                     ? "wrapper_followup_missing_but_bus_alive"
                                     : "wrapper_initial_followup_missing";
  gatewayCompatLastOutcome_ = "no_followup_timeout";
  gatewayCompatRetryInterpretation_ = firstFollowupInterpretation_;
  gatewayCompatFollowupActive_ = false;
  wrapperContinuationKind_ = "no_followup_timeout";
  wrapperContinuationRaw9_ = 0;
  wrapperContinuationDeltaUs_ = firstFollowupDeltaUs_;
  wrapperContinuationInterpretation_ = firstFollowupInterpretation_;
  wrapperExpectedNextRxKind_ = gatewayCompatBusAliveAfterSetup_
                                   ? "WRAPPER_RETRY_OR_RESET"
                                   : "WRAPPER_CONTINUATION_OR_RETRY_OR_RESET";
  wrapperExpectedNextAction_ = gatewayCompatBusAliveAfterSetup_
                                   ? "WAIT_FOR_WRAPPER_RETRY_OR_RESET"
                                   : "WAIT_FOR_INITIAL_WRAPPER_CONTINUATION";
  wrapperContinuationTimeoutCount_++;
  setWrapperFsmState(WrapperFsmState::ContinuationTimeout,
                     gatewayCompatBusAliveAfterSetup_
                         ? "wrapper_followup_missing_but_bus_alive"
                         : "wrapper_initial_followup_missing",
                     nowUs);
  if (setupNakCausal_ != "true") {
    setupNakCausal_ = "false";
    setupNakInterpretation_ = "no_nak_seen_within_followup_timeout";
  }
  emitSetupResponseRejectionAudit(
      gatewayCompatBusAliveAfterSetup_ ? "followup_timeout_bus_alive"
                                       : "followup_timeout_no_bus_activity",
      nowUs, nullptr, "timeout",
      String("\"followup_timeout_us\":") + gatewayCompatFollowupTimeoutUs_ +
          ",\"followup_delta_us\":" + firstFollowupDeltaUs_ +
          ",\"gateway_bus_alive_after_setup\":" +
          boolToJson(gatewayCompatBusAliveAfterSetup_));
  const String wrapperPhase = gatewayWrapperPhaseLabel();
  emitEvent("gateway_compat_followup_timeout",
            String("{\"timestamp_us\":") + nowUs +
                ",\"followup_timeout_us\":" + gatewayCompatFollowupTimeoutUs_ +
                ",\"delta_us\":" + firstFollowupDeltaUs_ +
                ",\"setup_response_profile_id\":\"" +
                escapeForJson(gatewayCompatResponseProfileIdLabel()) +
                "\"" + buildWrapperPhaseAndStateJson(wrapperPhase, wrapperPhase) +
                "\",\"wrapper_followup_missing\":" +
                boolToJson(gatewayWrapperFollowupMissing()) +
                ",\"wrapper_standard_flow_entered\":" +
                boolToJson(wrapperStandardFlowEntered_) +
                ",\"wrapper_continuation_timeout_count\":" +
                wrapperContinuationTimeoutCount_ +
                ",\"wrapper_continuation_kind\":\"" +
                escapeForJson(wrapperContinuationKind_) +
                "\",\"wrapper_continuation_interpretation\":\"" +
                escapeForJson(wrapperContinuationInterpretation_) +
                "\",\"wrapper_expected_peer_action\":\"" +
                escapeForJson(gatewayWrapperExpectedNextActionLabel()) +
                "\",\"gateway_wrapper_acceptance_state\":\"" +
                escapeForJson(gatewayWrapperAcceptanceStateLabel()) +
                "\",\"semantic_suspect_field\":\"" +
                escapeForJson(gatewayCompatSemanticSuspectField_) + "\"}");
}

String MdbService::buildUnknownTentativeKind(const machine::Frame& frame) const {
  if (!frame.hasCandidateAddress) {
    return "NO_CANDIDATE_ADDRESS";
  }
  if (!matchesCashlessDialogueAddress(frame.candidateAddress,
                                      frame.candidateCommand)) {
    if (frame.candidateCommand == kCashlessReaderControlCommand) {
      return "FOREIGN_READER_CONTROL";
    }
    if (frame.candidateCommand == kCashlessExpansionCommand) {
      return "FOREIGN_EXPANSION";
    }
    if (frame.candidateCommand == kCashlessPollCommand) {
      return "FOREIGN_POLL";
    }
    if (frame.candidateCommand == kCashlessSetupCommand) {
      return "FOREIGN_SETUP";
    }
    return "FOREIGN_UNKNOWN_COMMAND";
  }
  if (frame.candidateCommand == kCashlessReaderControlCommand) {
    return "UNCLASSIFIED_READER_CONTROL";
  }
  if (frame.candidateCommand == kCashlessExpansionCommand) {
    return "UNCLASSIFIED_EXPANSION";
  }
  if (frame.candidateCommand == kCashlessSetupCommand) {
    return "UNCLASSIFIED_SETUP";
  }
  return "UNCLASSIFIED_CASHLESS";
}

String MdbService::buildUnknownRxReason(const machine::Frame& frame) const {
  if (!frame.hasCandidateAddress) {
    return "no_candidate_address";
  }

  if (!matchesCashlessDialogueAddress(frame.candidateAddress,
                                      frame.candidateCommand)) {
    return String("foreign_address_") + frame.candidateAddress + "_command_" +
           frame.candidateCommand;
  }

  if (!frame.checksumValid) {
    return "checksum_invalid";
  }

  if (frame.candidateCommand == kCashlessReaderControlCommand &&
      frame.normalizedLength < 2) {
    return "reader_control_missing_subcommand";
  }

  if (frame.candidateCommand == kCashlessExpansionCommand &&
      frame.normalizedLength < 2) {
    return "expansion_missing_subcommand";
  }

  if (frame.candidateCommand == kCashlessSetupCommand &&
      frame.normalizedLength < 2) {
    return "setup_missing_subcommand";
  }

  return String("cashless_command_") + frame.candidateCommand +
         "_not_classified";
}

void MdbService::emitProtocolProgressExpectation(const char* reason,
                                                 unsigned long tsUs) {
  const bool isUnknownAfterSetup =
      reason != nullptr && strcmp(reason, "unknown_rx_after_setup") == 0;
  uint16_t suppressedDuplicates = 0;
  constexpr unsigned long kUnknownRxAfterSetupRateLimitUs = 10000000UL;
  if (isUnknownAfterSetup) {
    if (lastUnknownRxAfterSetupExpectationUs_ > 0 &&
        tsUs >= lastUnknownRxAfterSetupExpectationUs_ &&
        (tsUs - lastUnknownRxAfterSetupExpectationUs_) <
            kUnknownRxAfterSetupRateLimitUs) {
      if (suppressedUnknownRxAfterSetupCount_ < 0xFFFFU) {
        suppressedUnknownRxAfterSetupCount_++;
      }
      return;
    }
    suppressedDuplicates = suppressedUnknownRxAfterSetupCount_;
    suppressedUnknownRxAfterSetupCount_ = 0;
    lastUnknownRxAfterSetupExpectationUs_ = tsUs;
  }
  const bool expansionExpected =
      cashlessSetupMaxMinSeen_ && !cashlessExpansionSeen_ && !isReaderEnabled_;
  const bool enableExpected = cashlessSetupMaxMinSeen_ && !isReaderEnabled_;
  String json;
  if (!json.reserve(768)) {
    return;
  }
  json = "{\"timestamp_us\":";
  json += tsUs;
  json += ",\"reader_state\":\"";
  json += readerStateLabel(readerState_);
  json += "\",\"post_reset_phase\":\"";
  json += postResetPhaseLabel();
  json += "\",\"expected_next_rx_kind\":\"";
  json += escapeForJson(expectedNextRxKindLabel());
  json += "\",\"expected_next_tx_kind\":\"";
  json += escapeForJson(expectedNextTxKindLabel());
  json += "\",\"expansion_expected\":";
  json += boolToJson(expansionExpected);
  json += ",\"enable_expected\":";
  json += boolToJson(enableExpected);
  json += ",\"poll_expected\":";
  json += boolToJson(isReaderEnabled_ || cashlessJustResetPending_);
  json += ",\"protocol_progress_blocker\":\"";
  json += escapeForJson(protocolProgressBlockerLabel());
  json += "\",\"setup_progression_blocker\":\"";
  json += escapeForJson(setupProgressionBlockerLabel());
  json += "\",\"last_setup_variant\":\"";
  json += escapeForJson(lastSetupVariant_);
  json += "\",\"repeated_setup_count\":";
  json += repeatedSetupCount_;
  json += ",\"wrapper_fsm_state\":\"";
  json += escapeForJson(gatewayWrapperPhaseLabel());
  json += ",\"wrapper_expected_next_rx_kind\":\"";
  json += escapeForJson(wrapperExpectedNextRxKindLabel());
  json += "\",\"wrapper_expected_next_action\":\"";
  json += escapeForJson(wrapperExpectedNextActionLabel());
  json += "\",\"wrapper_standard_flow_entered\":";
  json += boolToJson(wrapperStandardFlowEntered_);
  json += ",\"wrapper_transition_reason\":\"";
  json += escapeForJson(wrapperTransitionReason_);
  json += "\"";
  json += ",\"reason\":\"";
  json += escapeForJson(reason == nullptr ? "" : String(reason));
  json += "\"";
  if (isUnknownAfterSetup || suppressedDuplicates > 0) {
    json += ",\"suppressed_duplicates\":";
    json += suppressedDuplicates;
  }
  json += "}";
  emitEvent("protocol_progress_expectation", json);
}

void MdbService::emitPostResetProgressionExpectation(const char* reason,
                                                     unsigned long tsUs) {
  const unsigned long elapsedSinceResetAckUs =
      (lastResetAckSentUs_ > 0 && tsUs >= lastResetAckSentUs_)
          ? (tsUs - lastResetAckSentUs_)
          : 0;
  emitEvent("post_reset_progression_expectation",
            String("{\"timestamp_us\":") + tsUs +
                ",\"post_reset_phase\":\"" + postResetPhaseLabel() +
                "\",\"just_reset_pending\":" +
                boolToJson(cashlessJustResetPending_) +
                ",\"expected_next_rx_kind\":\"" +
                escapeForJson(expectedNextRxKindLabel()) +
                "\",\"expected_next_tx_kind\":\"" +
                escapeForJson(expectedNextTxKindLabel()) +
                "\",\"protocol_progress_blocker\":\"" +
                escapeForJson(protocolProgressBlockerLabel()) +
                "\",\"repeated_setup_then_reset_observed\":" +
                boolToJson(repeatedSetupThenResetObserved_) +
                ",\"reset_after_setup_retry_count\":" +
                resetAfterSetupRetryCount_ +
                ",\"last_reset_cause_guess\":\"" +
                escapeForJson(lastResetCauseGuess_) +
                "\",\"next_action_hypothesis\":\"" +
                escapeForJson(nextActionHypothesis_) +
                "\",\"elapsed_since_reset_ack_us\":" +
                elapsedSinceResetAckUs +
                ",\"reason\":\"" +
                escapeForJson(reason == nullptr ? "" : String(reason)) + "\"}");
}

String MdbService::buildDialogueTelemetryJson() const {
  const bool expansionExpected =
      cashlessSetupMaxMinSeen_ && !cashlessExpansionSeen_ && !isReaderEnabled_;
  const bool enableExpected = cashlessSetupMaxMinSeen_ && !isReaderEnabled_;
  return String("{\"current_dialogue_phase\":\"") +
         currentDialoguePhaseLabel() +
         "\",\"last_reader_state\":\"" + readerStateLabel(readerState_) +
         "\",\"last_rx_kind\":\"" + dialogueKindLabel(lastRxKind_) +
         "\",\"last_tx_kind\":\"" + dialogueKindLabel(lastTxKindEnum_) +
         "\",\"tx_frame_count\":" + txFrameCount_ +
         ",\"poll_rx_count\":" + pollRxCount_ +
         ",\"poll_tx_count\":" + pollTxCount_ +
         ",\"enable_rx_count\":" + enableRxCount_ +
         ",\"enable_applied_count\":" + enableAppliedCount_ +
         ",\"setup_rx_count\":" + setupRxCount_ +
         ",\"setup_tx_count\":" + setupTxCount_ +
         ",\"expansion_rx_count\":" + expansionRxCount_ +
         ",\"expansion_tx_count\":" + expansionTxCount_ +
         ",\"ack_tx_count\":" + ackTxCount_ +
         ",\"no_response_count\":" + noResponseCount_ +
         ",\"state_transition_count\":" + stateTransitionCount_ +
         ",\"last_no_response_reason\":\"" +
         escapeForJson(lastNoResponseReason_) +
         "\",\"last_state_transition_reason\":\"" +
         escapeForJson(lastStateTransitionReason_) +
         "\",\"post_reset_phase\":\"" + postResetPhaseLabel() +
         "\",\"expected_next_rx_kind\":\"" +
         escapeForJson(expectedNextRxKindLabel()) +
         "\",\"expected_next_tx_kind\":\"" +
         escapeForJson(expectedNextTxKindLabel()) +
         "\",\"last_unknown_raw9\":" + lastUnknownRxFrame_.raw9 +
         ",\"last_unknown_reason\":\"" +
         escapeForJson(lastUnknownReason_) +
         "\",\"last_unknown_candidate_address\":" +
         lastUnknownCandidateAddress_ +
         ",\"last_unknown_candidate_command\":" +
         lastUnknownCandidateCommand_ +
         ",\"expansion_expected\":" + boolToJson(expansionExpected) +
         ",\"enable_expected\":" + boolToJson(enableExpected) +
         ",\"poll_expected\":" +
         boolToJson(isReaderEnabled_ || cashlessJustResetPending_) +
         ",\"protocol_progress_blocker\":\"" +
         escapeForJson(protocolProgressBlockerLabel()) +
         "\",\"setup_progression_blocker\":\"" +
         escapeForJson(setupProgressionBlockerLabel()) +
         "\",\"last_setup_raw9\":" + lastSetupRaw9_ +
         ",\"last_setup_subcommand\":" + lastSetupSubcommand_ +
         ",\"last_setup_variant\":\"" + escapeForJson(lastSetupVariant_) +
         "\",\"previous_setup_variant\":\"" +
         escapeForJson(previousSetupVariant_) +
         "\",\"previous_setup_raw9\":" + previousSetupRaw9_ +
         ",\"previous_setup_timestamp_us\":" + previousSetupTimestampUs_ +
         ",\"repeated_setup_count\":" + repeatedSetupCount_ +
         ",\"repeated_setup_same_payload_count\":" +
         repeatedSetupSamePayloadCount_ +
         ",\"repeated_setup_variant_count\":" +
         repeatedSetupVariantCount_ +
         ",\"repeated_setup_interpretation\":\"" +
         escapeForJson(repeatedSetupInterpretation_) + "\"" +
         ",\"last_setup_response_checksum\":" +
         static_cast<unsigned int>(lastSetupResponseChecksum_) +
         ",\"last_setup_response_options\":" +
         static_cast<unsigned int>(lastSetupResponseOptions_) +
         ",\"last_setup_response_response_time\":" +
         static_cast<unsigned int>(lastSetupResponseResponseTime_) +
         ",\"last_setup_response_scale_factor\":" +
         static_cast<unsigned int>(kCashlessScalingFactor) +
         ",\"last_setup_response_decimal_places\":" +
         static_cast<unsigned int>(kCashlessDecimalPlaces) +
         ",\"last_setup_response_feature_level\":" +
         static_cast<unsigned int>(kCashlessLevel) +
         ",\"gateway_currency_profile_id\":\"" +
         escapeForJson(gatewayCurrencyCountryCodeProfileId_) +
         "\",\"currency_code_encoding_mode\":\"" +
         escapeForJson(currencyCountryCodeEncodingMode_) +
         "\",\"currency_code_bytes_hex\":\"" +
         escapeForJson(gatewayCurrencyCountryCodeBytesHex()) +
         "\",\"currency_encoding_changed_from_profile1\":" +
         boolToJson(gatewayCurrencyCountryCodeChangedFromProfile1()) +
         ",\"last_setup_response_currency_code_bytes_hex\":\"" +
         escapeForJson(byteToHex(lastSetupResponseCountryCodeHi_) + " " +
                       byteToHex(lastSetupResponseCountryCodeLo_)) +
         "\"" +
         ",\"setup_response_profile_id\":\"" +
         escapeForJson(setupResponseProfileId_) +
         "\",\"setup_response_suspect_field\":\"" +
         escapeForJson(setupResponseSuspectField_) + "\"" +
         ",\"last_setup_reply_delay_us\":" + lastSetupResponseReplyDelayUs_ +
         ",\"last_setup_decision_to_tx_us\":" + lastSetupDecisionToTxUs_ +
         ",\"last_setup_build_to_tx_us\":" + lastSetupBuildToTxUs_ +
         ",\"last_setup_total_response_us\":" + lastSetupTotalResponseUs_ +
         ",\"setup_fast_path_enabled\":" + boolToJson(setupFastPathEnabled_) +
         ",\"last_setup_fast_path_used\":" + boolToJson(lastSetupFastPathUsed_) +
         ",\"setup_response_rejected_by_vmc\":\"" +
         escapeForJson(setupResponseRejectedByVmc_) +
         "\",\"setup_rejection_basis\":\"" +
         escapeForJson(setupRejectionBasis_) +
         "\",\"last_nak_after_setup_ts_us\":" + lastNakAfterSetupTsUs_ +
         ",\"last_nak_after_setup_raw9\":" + lastNakAfterSetupRaw9_ +
         ",\"last_nak_after_setup_delta_us\":" + lastNakAfterSetupDeltaUs_ +
         ",\"setup_nak_causal\":\"" + escapeForJson(setupNakCausal_) +
         "\",\"setup_nak_interpretation\":\"" +
         escapeForJson(setupNakInterpretation_) + "\"" +
         ",\"delta_setup_to_repeat_us\":" + lastSetupToRepeatUs_ +
         ",\"setup_retry_after_response_us\":" + lastSetupToRepeatUs_ +
         ",\"gateway_compat_response_profile_id\":\"" +
         escapeForJson(gatewayCompatResponseProfileIdLabel()) +
         "\",\"gateway_compat_expected_followup\":\"" +
         escapeForJson(gatewayCompatExpectedFollowup_) +
         "\",\"gateway_compat_followup_timeout_us\":" +
         gatewayCompatFollowupTimeoutUs_ +
         ",\"gateway_compat_semantic_suspect_field\":\"" +
         escapeForJson(gatewayCompatSemanticSuspectField_) +
         "\",\"gateway_compat_retry_interpretation\":\"" +
         escapeForJson(gatewayCompatRetryInterpretation_) +
         "\",\"gateway_compat_last_outcome\":\"" +
         escapeForJson(gatewayCompatLastOutcome_) +
         "\",\"gateway_wrapper_cycle_delta_us\":" + lastSetupToRepeatUs_ +
         ",\"gateway_wrapper_retry_after_60s\":" +
         boolToJson(gatewayWrapperRetryAfterLongSilence()) +
         ",\"wrapper_fsm_state\":\"" +
         escapeForJson(gatewayWrapperPhaseLabel()) +
         "\",\"wrapper_expected_next_rx_kind\":\"" +
         escapeForJson(wrapperExpectedNextRxKindLabel()) +
         "\",\"wrapper_expected_next_action\":\"" +
         escapeForJson(wrapperExpectedNextActionLabel()) +
         "\",\"wrapper_standard_flow_entered\":" +
         boolToJson(wrapperStandardFlowEntered_) +
         ",\"wrapper_transition_reason\":\"" +
         escapeForJson(wrapperTransitionReason_) +
         "\",\"wrapper_continuation_kind\":\"" +
         escapeForJson(wrapperContinuationKind_) +
         "\",\"wrapper_continuation_raw9\":" +
         wrapperContinuationRaw9_ +
         ",\"wrapper_continuation_delta_us\":" +
         wrapperContinuationDeltaUs_ +
         ",\"wrapper_continuation_interpretation\":\"" +
         escapeForJson(wrapperContinuationInterpretation_) +
         "\",\"wrapper_ack_semantics_mode\":\"" +
         escapeForJson(
             wrapperAckSemanticsModeLabel(wrapperAckSemanticsMode_)) +
         "\",\"wrapper_ack_semantics_suspect\":" +
         boolToJson(wrapperAckSemanticsSuspect_) +
         ",\"wrapper_continuation_timeout_count\":" +
         wrapperContinuationTimeoutCount_ +
         ",\"wrapper_phase\":\"" +
         escapeForJson(gatewayWrapperPhaseLabel()) +
         "\",\"wrapper_followup_missing\":" +
         boolToJson(gatewayWrapperFollowupMissing()) +
         ",\"wrapper_long_retry_observed\":" +
         boolToJson(gatewayWrapperLongRetryObserved()) +
         ",\"wrapper_reset_after_silence\":" +
         boolToJson(gatewayWrapperResetAfterSilence()) +
         ",\"wrapper_handshake_acceptance\":\"" +
         escapeForJson(gatewayWrapperAcceptanceStateLabel()) +
         "\",\"wrapper_expected_peer_action\":\"" +
         escapeForJson(gatewayWrapperExpectedNextActionLabel()) +
         "\"" +
         ",\"gateway_wrapper_expected_next_action\":\"" +
         escapeForJson(gatewayWrapperExpectedNextActionLabel()) +
         "\",\"gateway_wrapper_missing_step_hypothesis\":\"" +
         escapeForJson(gatewayWrapperMissingStepHypothesisLabel()) +
         "\",\"gateway_wrapper_acceptance_state\":\"" +
         escapeForJson(gatewayWrapperAcceptanceStateLabel()) +
         "\",\"first_followup_kind_after_setup\":\"" +
         escapeForJson(firstFollowupKindAfterSetup_) +
         "\",\"first_followup_raw9_after_setup\":" +
         firstFollowupRaw9AfterSetup_ +
         ",\"first_followup_delta_us\":" + firstFollowupDeltaUs_ +
         ",\"first_followup_interpretation\":\"" +
         escapeForJson(firstFollowupInterpretation_) + "\"" +
         ",\"repeated_setup_then_reset_observed\":" +
         boolToJson(repeatedSetupThenResetObserved_) +
         ",\"reset_after_setup_retry_count\":" +
         resetAfterSetupRetryCount_ +
         ",\"poll_missing_after_reset_count\":" +
         pollMissingAfterResetCount_ +
         ",\"last_reset_cause_guess\":\"" +
         escapeForJson(lastResetCauseGuess_) +
         "\",\"next_action_hypothesis\":\"" +
         escapeForJson(nextActionHypothesis_) +
         "\",\"last_reset_ack_prepare_us\":" + lastResetAckPreparedUs_ +
         ",\"last_reset_ack_done_us\":" + lastResetAckDoneUs_ +
         ",\"last_reset_ack_release_us\":" + lastResetAckReleaseUs_ +
         ",\"last_setup_response_to_reset_us\":" +
         lastSetupResponseToResetUs_ +
         ",\"last_reset_to_ack_us\":" + lastResetToAckUs_ +
         ",\"last_next_rx_after_reset_ts_us\":" +
         lastNextRxAfterResetTsUs_ +
         ",\"elapsed_waiting_for_poll_after_reset_us\":" +
         ((lastResetAckSentUs_ > 0 && micros() >= lastResetAckSentUs_ &&
           (lastPollAfterResetTsUs_ == 0 ||
            lastPollAfterResetTsUs_ < lastResetAckSentUs_))
              ? (micros() - lastResetAckSentUs_)
              : 0) +
         ",\"foreign_traffic_causal\":\"" +
         escapeForJson(foreignTrafficCausalLabel()) + "\"" +
         ",\"begin_session_pending\":" + boolToJson(beginSessionPending_) +
         ",\"begin_session_awaiting_ack\":" +
         boolToJson(beginSessionAwaitingAck_) +
         ",\"begin_session_tx_count\":" + beginSessionTxCount_ +
         ",\"begin_session_ack_count\":" + beginSessionAckCount_ +
         ",\"last_begin_session_tx_us\":" + lastBeginSessionTxUs_ +
         ",\"last_begin_session_ack_us\":" + lastBeginSessionAckUs_ +
         ",\"last_begin_session_status\":\"" +
         escapeForJson(lastBeginSessionStatus_) +
         "\",\"rx_to_tx_latency_us\":" + lastRxToTxLatencyUs_ +
         ",\"dialogue_history_count\":" + dialogueHistoryCount_ +
         ",\"dialogue_history\":" + buildDialogueHistoryJson() + "}";
}

MdbService::DialogueKind MdbService::prepareAcceptedRxFrame(
    const machine::Frame& frame) {
  if (frame.length == 0) {
    return DialogueKind::Unknown;
  }
  const DialogueKind kind = classifyRxFrameKind(frame);
  lastAcceptedRxFrame_.valid = true;
  lastAcceptedRxFrame_.dataByte = frame.bytes[0].raw;
  lastAcceptedRxFrame_.ninthBit = frame.bytes[0].highBit;
  lastAcceptedRxFrame_.raw9 =
      raw9Word(lastAcceptedRxFrame_.dataByte, lastAcceptedRxFrame_.ninthBit);
  lastAcceptedRxFrame_.timestampUs = frame.bytes[0].tsUs;
  lastAcceptedRxFrame_.hex = machine::normalizedHex(frame);
  lastRxKind_ = kind;
  if (kind == DialogueKind::Nak && lastSetupResponseTxUs_ > 0 &&
      frame.endedAtUs >= lastSetupResponseTxUs_) {
    lastNakAfterSetupTsUs_ = frame.endedAtUs;
    lastNakAfterSetupRaw9_ = lastAcceptedRxFrame_.raw9;
    lastNakAfterSetupDeltaUs_ = frame.endedAtUs - lastSetupResponseTxUs_;
    setupNakCausal_ = "true";
    setupNakInterpretation_ = "explicit_negative_ack_after_setup_response";
    setupResponseRejectedByVmc_ = "true";
    setupRejectionBasis_ = "explicit_nak";
    emitSetupResponseRejectionAudit(
        "explicit_nak", frame.endedAtUs, &frame, "nak",
        String("\"nak_raw9\":") + lastNakAfterSetupRaw9_ +
            ",\"nak_raw9_hex\":\"" + String(lastNakAfterSetupRaw9_, HEX) +
            "\"");
  }
  noteGatewayCompatFollowup(frame, kind);
  switch (kind) {
    case DialogueKind::Poll:
      pollRxCount_++;
      break;
    case DialogueKind::Enable:
    case DialogueKind::Disable:
      enableRxCount_++;
      break;
    case DialogueKind::Setup:
      setupRxCount_++;
      break;
    case DialogueKind::ExpansionId:
      expansionRxCount_++;
      break;
    default:
      break;
  }
  responsePathState_ = ResponsePathState::RxFrameReady;
  responseStateChangedAtUs_ = frame.endedAtUs;
  return kind;
}

void MdbService::emitAcceptedRxFrameTrace(const machine::Frame& frame,
                                          DialogueKind kind) {
  if (frame.length == 0) {
    return;
  }
  const bool addressAliasMatched =
      frame.hasCandidateAddress && frame.candidateAddress != cashlessAddress_ &&
      matchesCashlessDialogueAddress(frame.candidateAddress,
                                     frame.candidateCommand);
  appendDialogueEvent(DialogueDirection::RxFromMachine, kind,
                      lastAcceptedRxFrame_.raw9, lastAcceptedRxFrame_.dataByte,
                      lastAcceptedRxFrame_.ninthBit, readerState_, readerState_,
                      "rx_frame_accepted", frame.endedAtUs);
  emitEvent("rx_frame_accepted",
            String("{\"raw9\":") + lastAcceptedRxFrame_.raw9 +
                ",\"raw9_hex\":\"" +
                String(lastAcceptedRxFrame_.raw9, HEX) +
                "\",\"data_byte\":" + lastAcceptedRxFrame_.dataByte +
                ",\"data_hex\":\"" + byteToHex(lastAcceptedRxFrame_.dataByte) +
                "\",\"ninth_bit\":" +
                boolToJson(lastAcceptedRxFrame_.ninthBit) +
                ",\"timestamp_us\":" + lastAcceptedRxFrame_.timestampUs +
                ",\"frame_hex\":\"" + lastAcceptedRxFrame_.hex +
                "\",\"decoded_kind\":\"" + dialogueKindLabel(kind) +
                "\",\"checksum_valid\":" + boolToJson(frame.checksumValid) +
                ",\"standard_mdb_valid\":" +
                boolToJson(frame.standardMdbValid) +
                ",\"compat_candidate\":" +
                boolToJson(frame.compatCandidate) +
                ",\"address_alias_matched\":" +
                boolToJson(addressAliasMatched) +
                ",\"candidate_address\":" +
                (frame.hasCandidateAddress ? String(frame.candidateAddress)
                                           : String(-1)) +
                ",\"candidate_command\":" +
                (frame.hasCandidateAddress ? String(frame.candidateCommand)
                                           : String(-1)) + "}");
  if (addressAliasMatched) {
    emitEvent("cashless_address_alias_match",
              String("{\"candidate_address\":") + frame.candidateAddress +
                  ",\"candidate_command\":" + frame.candidateCommand +
                  ",\"cashless_address\":" +
                  static_cast<unsigned int>(cashlessAddress_) +
                  ",\"reader_state\":\"" + readerStateLabel(readerState_) +
                  "\"}");
  }
  if (kind == DialogueKind::Unknown) {
    const String tentative = buildUnknownTentativeKind(frame);
    const String reason = buildUnknownRxReason(frame);
    lastUnknownRxFrame_ = lastAcceptedRxFrame_;
    lastUnknownCandidateAddress_ =
        frame.hasCandidateAddress ? static_cast<int16_t>(frame.candidateAddress)
                                  : static_cast<int16_t>(-1);
    lastUnknownCandidateCommand_ =
        frame.hasCandidateAddress ? static_cast<int16_t>(frame.candidateCommand)
                                  : static_cast<int16_t>(-1);
    lastUnknownReason_ = reason;
    emitEvent("rx_frame_tentative",
              String("{\"raw9\":") + lastAcceptedRxFrame_.raw9 +
                  ",\"raw9_hex\":\"" + String(lastAcceptedRxFrame_.raw9, HEX) +
                  "\",\"frame_hex\":\"" + lastAcceptedRxFrame_.hex +
                  "\",\"data_byte\":" + lastAcceptedRxFrame_.dataByte +
                  ",\"data_hex\":\"" + byteToHex(lastAcceptedRxFrame_.dataByte) +
                  "\",\"ninth_bit\":" +
                  boolToJson(lastAcceptedRxFrame_.ninthBit) +
                  ",\"candidate_address\":" +
                  (frame.hasCandidateAddress ? String(frame.candidateAddress)
                                             : String(-1)) +
                  ",\"candidate_command\":" +
                  (frame.hasCandidateAddress ? String(frame.candidateCommand)
                                             : String(-1)) +
                  ",\"address_bits\":" +
                  (frame.hasCandidateAddress
                       ? String(frame.normalized[0] >> 3U)
                       : String(-1)) +
                  ",\"command_bits\":" +
                  (frame.hasCandidateAddress
                       ? String(frame.normalized[0] & 0x07U)
                       : String(-1)) +
                  ",\"checksum_valid\":" + boolToJson(frame.checksumValid) +
                  ",\"tentative_kind\":\"" + escapeForJson(tentative) +
                  "\",\"reason_for_unknown\":\"" +
                  escapeForJson(reason) + "\"}");
    emitProtocolProgressExpectation("unknown_rx_after_setup", frame.endedAtUs);
  }
}

void MdbService::recordAcceptedRxFrame(const machine::Frame& frame) {
  const DialogueKind kind = prepareAcceptedRxFrame(frame);
  emitAcceptedRxFrameTrace(frame, kind);
}

void MdbService::dispatchAcceptedFrame(const machine::Frame& frame,
                                       unsigned long now,
                                       bool clearSplitPrefix) {
  const bool shouldTraceAcceptedFrame =
      (frame.checksumValid && frame.hasCandidateAddress) ||
      (kMdbCashlessEnabled && frame.normalizedLength == 1 &&
       frame.normalized[0] == kObservedGatewayPollByte);
  DialogueKind acceptedKind = DialogueKind::Unknown;
  if ((frame.checksumValid && frame.hasCandidateAddress) ||
      (kMdbCashlessEnabled && frame.normalizedLength == 1 &&
       frame.normalized[0] == kObservedGatewayPollByte)) {
    acceptedKind = prepareAcceptedRxFrame(frame);
  }

  bool fastReplyHandled = false;
  if (fastHandledFramePending_ && frame.endedAtUs == fastHandledFrameEndedUs_ &&
      frame.hasCandidateAddress &&
      frame.candidateAddress == fastHandledFrameAddress_ &&
      frame.candidateCommand == fastHandledFrameCommand_) {
    fastReplyHandled = true;
    fastHandledFramePending_ = false;
  } else {
    fastReplyHandled = tryFastCreditFlowReply(frame, now);
  }

  if (clearSplitPrefix) {
    clearPendingCashlessSplitPrefix();
  }
  processFrame(frame, now, fastReplyHandled);
  if (shouldTraceAcceptedFrame) {
    emitAcceptedRxFrameTrace(frame, acceptedKind);
  }
  rxFrameCount_++;
  lastRxFrameAt_ = now;
}

void MdbService::recordResponseDecision(const char* reason, bool willRespond,
                                        unsigned long tsUs) {
  lastResponseDecisionReason_ = reason == nullptr ? "" : reason;
  lastResponseDecisionWillRespond_ = willRespond;
  setResponsePathState(ResponsePathState::ResponseDecision, tsUs, reason);
  if (kLogEveryResponseDecision || !willRespond) {
    emitEvent("response_decision",
              String("{\"reason\":\"") +
                  escapeForJson(lastResponseDecisionReason_) +
                  "\",\"will_respond\":" + boolToJson(willRespond) +
                  ",\"timestamp_us\":" + tsUs +
                  ",\"last_rx_raw9\":" + lastAcceptedRxFrame_.raw9 +
                  ",\"last_rx_data_byte\":" + lastAcceptedRxFrame_.dataByte +
                  ",\"last_rx_ninth_bit\":" +
                  boolToJson(lastAcceptedRxFrame_.ninthBit) +
                  ",\"last_rx_kind\":\"" +
                  dialogueKindLabel(lastRxKind_) + "\"}");
  }
  if (!willRespond) {
    if (txExpectationPending_ && txExpectationRequired_) {
      txMissingCount_++;
      lastTxAuditReason_ = "no_response_after_expected_tx";
      emitEvent(
          "tx_missing_for_rx_kind",
          String("{\"rx_kind\":\"") +
              dialogueKindLabel(txExpectationRxKind_) +
              "\",\"reader_state\":\"" +
              readerStateLabel(txExpectationReaderState_) +
              "\",\"expected_tx_kind\":\"" +
              escapeForJson(lastExpectedTxKind_) +
              "\",\"reason\":\"no_response_after_expected_tx\",\"timestamp_us\":" +
              tsUs + "}");
      clearExpectedTxAudit();
    }
    if (lastRxKind_ == DialogueKind::Poll) {
      noteNoResponse(reason, tsUs, lastRxKind_);
    }
    setResponsePathState(ResponsePathState::Idle, tsUs, reason);
    flushPendingProbeIfIdle();
  }
}

void MdbService::noteExpectedTxKind(DialogueKind rxKind, ReaderState stateBefore,
                                    const char* expectedTxKind,
                                    unsigned long tsUs, bool required,
                                    const char* reason,
                                    bool emitAuditEvent) {
  if (txExpectationPending_ && txExpectationRequired_) {
    txMissingCount_++;
    lastTxAuditReason_ = "expected_tx_overwritten";
    emitEvent(
        "tx_missing_for_rx_kind",
        String("{\"rx_kind\":\"") +
            dialogueKindLabel(txExpectationRxKind_) +
            "\",\"reader_state\":\"" +
            readerStateLabel(txExpectationReaderState_) +
            "\",\"expected_tx_kind\":\"" +
            escapeForJson(lastExpectedTxKind_) +
            "\",\"reason\":\"expected_tx_overwritten\",\"timestamp_us\":" +
            tsUs + "}");
  }

  lastExpectedTxKind_ = expectedTxKind == nullptr ? "" : expectedTxKind;
  txExpectationPending_ = !lastExpectedTxKind_.isEmpty();
  txExpectationRequired_ = required && txExpectationPending_;
  txExpectationSetAtUs_ = tsUs;
  txExpectationRxKind_ = rxKind;
  txExpectationReaderState_ = stateBefore;
  lastRxToExpectedTxMapping_ =
      String(dialogueKindLabel(rxKind)) + "@" + readerStateLabel(stateBefore) +
      "->" + lastExpectedTxKind_;
  lastTxAuditReason_ = reason == nullptr ? "" : reason;

  if (emitAuditEvent) {
    emitEvent("tx_expected_for_rx_kind",
              String("{\"rx_kind\":\"") + dialogueKindLabel(rxKind) +
                  "\",\"reader_state\":\"" +
                  readerStateLabel(stateBefore) +
                  "\",\"expected_tx_kind\":\"" +
                  escapeForJson(lastExpectedTxKind_) +
                  "\",\"required\":" + boolToJson(txExpectationRequired_) +
                  ",\"reason\":\"" +
                  escapeForJson(lastTxAuditReason_) +
                  "\",\"timestamp_us\":" + tsUs + "}");
  }
}

void MdbService::noteActualTxKind(const char* actualTxKind, DialogueKind kind,
                                  ReaderState stateBefore,
                                  unsigned long tsUs) {
  lastActualTxKind_ = actualTxKind == nullptr ? "" : actualTxKind;
  const size_t actualBucket = txAuditKindBucketFor(actualTxKind, kind);
  if (actualBucket < kTxAuditKindBucketCount &&
      txEmittedCountByKind_[actualBucket] < 0xFFU) {
    txEmittedCountByKind_[actualBucket]++;
  }

  const DialogueKind mappedRxKind =
      txExpectationPending_ ? txExpectationRxKind_ : lastRxKind_;
  const ReaderState mappedState =
      txExpectationPending_ ? txExpectationReaderState_ : stateBefore;
  lastRxToActualTxMapping_ =
      String(dialogueKindLabel(mappedRxKind)) + "@" +
      readerStateLabel(mappedState) + "->" + lastActualTxKind_;

  if (txExpectationPending_) {
    const size_t expectedBucket =
        txAuditKindBucketFor(lastExpectedTxKind_.c_str(), DialogueKind::Unknown);
    const bool matched = expectedBucket == actualBucket;
    emitEvent("tx_expected_vs_actual",
              String("{\"rx_kind\":\"") +
                  dialogueKindLabel(txExpectationRxKind_) +
                  "\",\"reader_state\":\"" +
                  readerStateLabel(txExpectationReaderState_) +
                  "\",\"expected_tx_kind\":\"" +
                  escapeForJson(lastExpectedTxKind_) +
                  "\",\"actual_tx_kind\":\"" +
                  escapeForJson(lastActualTxKind_) +
                  "\",\"status\":\"" +
                  (matched ? "ok" : "mismatch") +
                  "\",\"timestamp_us\":" + tsUs + "}");
    if (expectedBucket != actualBucket) {
      txDecisionMismatchCount_++;
      lastTxAuditReason_ = "expected_vs_actual_tx_kind_mismatch";
      emitEvent("tx_decision_mismatch",
                String("{\"rx_kind\":\"") +
                    dialogueKindLabel(txExpectationRxKind_) +
                    "\",\"reader_state\":\"" +
                    readerStateLabel(txExpectationReaderState_) +
                    "\",\"expected_tx_kind\":\"" +
                    escapeForJson(lastExpectedTxKind_) +
                    "\",\"actual_tx_kind\":\"" +
                    escapeForJson(lastActualTxKind_) +
                    "\",\"timestamp_us\":" + tsUs + "}");
    }
  } else {
    emitEvent("tx_unexpected_without_mapping",
              String("{\"actual_tx_kind\":\"") +
                  escapeForJson(lastActualTxKind_) +
                  "\",\"rx_kind\":\"" +
                  dialogueKindLabel(lastRxKind_) +
                  "\",\"timestamp_us\":" + tsUs + "}");
  }

  clearExpectedTxAudit();
}

void MdbService::noteTxCompleted(const char* txKind, DialogueKind kind) {
  const size_t bucket = txAuditKindBucketFor(txKind, kind);
  if (bucket < kTxAuditKindBucketCount &&
      txCompletedCountByKind_[bucket] < 0xFFU) {
    txCompletedCountByKind_[bucket]++;
  }
}

void MdbService::noteTxAbortForKind(const char* txKind, DialogueKind kind,
                                    const char* reason,
                                    unsigned long tsUs) {
  const size_t bucket = txAuditKindBucketFor(txKind, kind);
  if (bucket < kTxAuditKindBucketCount &&
      txAbortCountByKind_[bucket] < 0xFFU) {
    txAbortCountByKind_[bucket]++;
  }
  lastTxAuditReason_ = reason == nullptr ? "" : reason;
  emitEvent("tx_abort_by_kind",
            String("{\"tx_kind\":\"") +
                escapeForJson(txKind == nullptr ? "" : String(txKind)) +
                "\",\"decoded_kind\":\"" + dialogueKindLabel(kind) +
                "\",\"reason\":\"" +
                escapeForJson(lastTxAuditReason_) +
                "\",\"timestamp_us\":" + tsUs + "}");
  clearExpectedTxAudit();
}

void MdbService::noteTxTimeoutForKind(const char* txKind, DialogueKind kind,
                                      const char* reason,
                                      unsigned long tsUs) {
  const size_t bucket = txAuditKindBucketFor(txKind, kind);
  if (bucket < kTxAuditKindBucketCount &&
      txTimeoutCountByKind_[bucket] < 0xFFU) {
    txTimeoutCountByKind_[bucket]++;
  }
  lastTxAuditReason_ = reason == nullptr ? "" : reason;
  emitEvent("tx_timeout_by_kind",
            String("{\"tx_kind\":\"") +
                escapeForJson(txKind == nullptr ? "" : String(txKind)) +
                "\",\"decoded_kind\":\"" + dialogueKindLabel(kind) +
                "\",\"reason\":\"" +
                escapeForJson(lastTxAuditReason_) +
                "\",\"timestamp_us\":" + tsUs + "}");
  clearExpectedTxAudit();
}

void MdbService::clearExpectedTxAudit() {
  txExpectationPending_ = false;
  txExpectationRequired_ = false;
  txExpectationSetAtUs_ = 0;
  txExpectationRxKind_ = DialogueKind::Unknown;
  txExpectationReaderState_ = ReaderState::Uninitialized;
}

void MdbService::setResponsePathState(ResponsePathState state, unsigned long tsUs,
                                      const char* reason) {
  responsePathState_ = state;
  responseStateChangedAtUs_ = tsUs;
  emitEvent("response_path_state",
            String("{\"state\":\"") + responsePathStateLabel(state) +
                "\",\"timestamp_us\":" + tsUs +
                ",\"reason\":\"" +
                escapeForJson(reason == nullptr ? "" : String(reason)) + "\"}");
}

void MdbService::flushPendingProbeIfIdle() {
  if (!probeRequestPending_ || responsePathState_ != ResponsePathState::Idle) {
    return;
  }
  probeRequestPending_ = false;
  emitProbeEvent("deferred_idle_flush", "pending_probe_flush");
}

String MdbService::buildResponseTelemetryJson() const {
  return String("{\"response_path_state\":\"") +
         responsePathStateLabel(responsePathState_) +
         "\",\"response_state_changed_at_us\":" + responseStateChangedAtUs_ +
         ",\"last_rx_frame\":{\"valid\":" + boolToJson(lastAcceptedRxFrame_.valid) +
         ",\"raw9\":" + lastAcceptedRxFrame_.raw9 +
         ",\"data_byte\":" + lastAcceptedRxFrame_.dataByte +
         ",\"ninth_bit\":" + boolToJson(lastAcceptedRxFrame_.ninthBit) +
         ",\"timestamp_us\":" + lastAcceptedRxFrame_.timestampUs +
         ",\"hex\":\"" + escapeForJson(lastAcceptedRxFrame_.hex) +
         "\"},\"last_response_decision\":{\"reason\":\"" +
         escapeForJson(lastResponseDecisionReason_) +
         "\",\"will_respond\":" + boolToJson(lastResponseDecisionWillRespond_) +
         "},\"last_tx_frame\":{\"valid\":" + boolToJson(lastTxFrame_.valid) +
         ",\"raw9\":" + lastTxFrame_.raw9 +
         ",\"data_byte\":" + lastTxFrame_.dataByte +
         ",\"ninth_bit\":" + boolToJson(lastTxFrame_.ninthBit) +
         ",\"timestamp_us\":" + lastTxFrame_.timestampUs +
         ",\"hex\":\"" + escapeForJson(lastTxFrame_.hex) +
         "\",\"kind\":\"" + escapeForJson(lastTxKind_) +
         "\"},\"expected_tx_kind\":\"" +
         escapeForJson(lastExpectedTxKind_) +
         "\",\"last_actual_tx_kind\":\"" +
         escapeForJson(lastActualTxKind_) +
         "\",\"last_tx_audit_reason\":\"" +
         escapeForJson(lastTxAuditReason_) +
         "\",\"last_rx_to_expected_tx_mapping\":\"" +
         escapeForJson(lastRxToExpectedTxMapping_) +
         "\",\"last_rx_to_actual_tx_mapping\":\"" +
         escapeForJson(lastRxToActualTxMapping_) +
         "\",\"tx_decision_mismatch_count\":" + txDecisionMismatchCount_ +
         ",\"tx_missing_count\":" + txMissingCount_ +
         ",\"tx_emitted_count_by_kind\":" +
         buildTxAuditCountJson(txEmittedCountByKind_) +
         ",\"tx_completed_count_by_kind\":" +
         buildTxAuditCountJson(txCompletedCountByKind_) +
         ",\"tx_timeout_count_by_kind\":" +
         buildTxAuditCountJson(txTimeoutCountByKind_) +
         ",\"tx_abort_count_by_kind\":" +
         buildTxAuditCountJson(txAbortCountByKind_) +
         ",\"tx_expectation_pending\":" + boolToJson(txExpectationPending_) +
         ",\"tx_expectation_required\":" + boolToJson(txExpectationRequired_) +
         "},\"tx_attempt_count\":" + txAttemptCount_ +
         ",\"tx_success_count\":" + txSuccessCount_ +
         ",\"tx_abort_count\":" + txAbortCount_ +
         ",\"tx_timeout_count\":" + txTimeoutCount_ +
         ",\"last_tx_start_us\":" + lastTxStartUs_ +
         ",\"last_tx_done_us\":" + lastTxDoneUs_ +
         ",\"last_tx_release_us\":" + lastTxReleaseUs_ +
         ",\"last_tx_error_reason\":\"" + escapeForJson(lastTxErrorReason_) + "\"}";
}

String MdbService::buildTxAuditCountJson(const uint8_t* counters) const {
  String json = "{";
  if (counters == nullptr) {
    json += "}";
    return json;
  }
  for (size_t i = 0; i < kTxAuditKindBucketCount; ++i) {
    if (i > 0) {
      json += ",";
    }
    json += String("\"") + txAuditKindBucketLabel(i) + "\":" + counters[i];
  }
  json += "}";
  return json;
}

void MdbService::emitObservedTxByte(TxScope scope, uint32_t frameId, size_t byteIndex,
                                    uint8_t value, uint8_t ninthBit,
                                    unsigned long tsUs) {
  const unsigned long bitUs = phy_.txBitPeriodUs();
  const unsigned long charUs = phy_.txCharacterUs();
  const uint16_t raw9 = raw9Word(value, ninthBit != 0);
  const DialogueKind kind = classifyTxFrameKind(&value, 1, currentTxKind_.c_str());
  const String baseJson =
      String("{\"tx_scope\":\"") + txScopeLabel(scope) +
      "\",\"tx_kind\":\"" + escapeForJson(currentTxKind_) +
      "\",\"frame_id\":" + frameId + ",\"byte_index\":" + byteIndex +
      ",\"hex\":\"" + byteToHex(value) + "\",\"value\":" + value +
      ",\"ninth_bit\":" + ninthBit + ",\"raw9\":" + raw9 +
      ",\"decoded_kind\":\"" + dialogueKindLabel(kind) +
      "\",\"raw9_hex\":\"" + String(raw9, HEX) +
      "\",\"bit_lsb_first\":\"" + byteBitsLsbFirst(value, 8) +
      "\",\"tx_ts_us\":" + tsUs + ",\"bit_period_us\":" + bitUs +
      ",\"character_tx_us\":" + charUs + "}";
  const char* eventName = "phy_tx_raw";
  switch (scope) {
    case TxScope::MdbResponse:
      if (kMdbUartEvtVerboseTxByteTrace) { eventName = "mdb_bus_tx_raw"; }
      break;
    case TxScope::DebugCommand:
      eventName = "mdb_debug_tx_raw";
      break;
    case TxScope::Experiment:
      eventName = "mdb_experiment_tx_raw";
      break;
    case TxScope::None:
    default:
      eventName = "phy_tx_raw";
      break;
  }
  if (!shouldSuppressSetupResponseLowLevelTxTrace(eventName, currentTxKind_.c_str())) {
    emitEvent(eventName, baseJson);
  }
  if (kMdbUartEvtVerboseTxByteTrace &&
      !shouldSuppressSetupResponseLowLevelTxTrace("tx_word_raw9", currentTxKind_.c_str())) {
    emitEvent("tx_word_raw9", baseJson);
  }
  if (!shouldSuppressSetupResponseLowLevelTxTrace("tx_bit_timing", currentTxKind_.c_str())) {
    emitEvent("tx_bit_timing",
              String("{\"tx_scope\":\"") + txScopeLabel(scope) +
                  "\",\"tx_kind\":\"" + escapeForJson(currentTxKind_) +
                  "\",\"byte_index\":" + byteIndex +
                  ",\"start_ts_us\":" + tsUs +
                  ",\"end_ts_us\":" + (tsUs + charUs) +
                  ",\"bit_period_us\":" + bitUs +
                  ",\"character_tx_us\":" + charUs + "}");
  }
}

unsigned long MdbService::transmitResponseFrame(const char* decisionReason,
                                                const char* txKind,
                                                const uint8_t* frame,
                                                size_t length,
                                                unsigned long rxEndedUs) {
  if (frame == nullptr || length == 0) {
    lastTxErrorReason_ = "empty_tx_frame";
    txAbortCount_++;
    noteTxAbortForKind(txKind, DialogueKind::Unknown, "empty_tx_frame", micros());
    setResponsePathState(ResponsePathState::TxAbort, micros(),
                         "empty_tx_frame");
    emitEvent("tx_abort", "{\"reason\":\"empty_tx_frame\"}");
    return 0;
  }

  const unsigned long preparedAtUs = micros();
  const uint16_t firstRaw9 = raw9Word(frame[0], false);
  const uint16_t lastRaw9 = raw9Word(frame[length - 1], false);
  const DialogueKind txKindEnum = classifyTxFrameKind(frame, length, txKind);
  const ReaderState stateBeforeTx = readerState_;
  lastTxFrame_.valid = true;
  lastTxFrame_.dataByte = frame[length - 1];
  lastTxFrame_.ninthBit = false;
  lastTxFrame_.raw9 = lastRaw9;
  lastTxFrame_.timestampUs = preparedAtUs;
  lastTxFrame_.hex = bytesToHex(frame, length);
  lastTxKind_ = txKind == nullptr ? "" : txKind;
  lastTxKindEnum_ = txKindEnum;
  lastTxErrorReason_ = "";
  if (lastTxKind_ == "setup_response") {
    lastSetupQueueEnqueueTsUs_ = preparedAtUs;
  }
  currentTxScope_ = TxScope::MdbResponse;
  currentTxKind_ = lastTxKind_;
  txAttemptCount_++;
  txFrameCount_++;
  if (lastAcceptedRxFrame_.valid && preparedAtUs >= lastAcceptedRxFrame_.timestampUs) {
    lastRxToTxLatencyUs_ = preparedAtUs - lastAcceptedRxFrame_.timestampUs;
  }
  switch (txKindEnum) {
    case DialogueKind::Poll:
      pollTxCount_++;
      break;
    case DialogueKind::ReaderConfig:
      setupTxCount_++;
      break;
    case DialogueKind::ExpansionId:
      expansionTxCount_++;
      break;
    case DialogueKind::Ack:
      ackTxCount_++;
      if (lastRxKind_ == DialogueKind::Poll) {
        pollTxCount_++;
      }
      break;
    default:
      break;
  }
  lastResponseDecisionReason_ = decisionReason == nullptr ? "" : decisionReason;
  lastResponseDecisionWillRespond_ = true;
  responsePathState_ = ResponsePathState::TxPending;
  responseStateChangedAtUs_ = preparedAtUs;

  beginDeferredTxTrace();
  const unsigned long firstTxUs = phy_.write(frame, length);
  const unsigned long afterWriteUs = micros();
  flushDeferredTxTrace();

  setResponsePathState(ResponsePathState::ResponseDecision, preparedAtUs,
                       decisionReason);
  emitEvent("response_decision",
            String("{\"reason\":\"") +
                escapeForJson(lastResponseDecisionReason_) +
                "\",\"will_respond\":true,\"timestamp_us\":" + preparedAtUs +
                ",\"last_rx_raw9\":" + lastAcceptedRxFrame_.raw9 +
                ",\"last_rx_data_byte\":" + lastAcceptedRxFrame_.dataByte +
                ",\"last_rx_ninth_bit\":" +
                boolToJson(lastAcceptedRxFrame_.ninthBit) + "}");
  auto emitTxTraceEvent = [&](const char* eventName, const String& payload) {
    if (shouldSuppressSetupResponseLowLevelTxTrace(eventName, lastTxKind_.c_str())) {
      return;
    }
    emitEvent(eventName, payload);
  };

  setResponsePathState(ResponsePathState::TxPending, preparedAtUs, txKind);
  emitTxTraceEvent("response_queue_enqueue",
                   String("{\"tx_kind\":\"") + escapeForJson(lastTxKind_) +
                       "\",\"queue_depth\":1,\"timestamp_us\":" + preparedAtUs + "}");
  emitEvent("tx_frame_prepared",
            String("{\"tx_kind\":\"") + escapeForJson(lastTxKind_) +
                "\",\"frame_hex\":\"" + lastTxFrame_.hex +
                "\",\"byte_count\":" + length +
                ",\"first_raw9\":" + firstRaw9 +
                ",\"last_raw9\":" + lastRaw9 +
                ",\"decoded_kind\":\"" + dialogueKindLabel(txKindEnum) +
                "\",\"rx_ended_us\":" + rxEndedUs +
                ",\"timestamp_us\":" + preparedAtUs + "}");

  if (firstTxUs == 0) {
    lastTxErrorReason_ = "phy_write_failed";
    txAbortCount_++;
    noteTxAbortForKind(txKind, txKindEnum, "phy_write_failed", afterWriteUs);
    setResponsePathState(ResponsePathState::TxAbort, afterWriteUs,
                         "phy_write_failed");
    emitEvent("tx_abort",
              String("{\"reason\":\"phy_write_failed\",\"tx_kind\":\"") +
                  escapeForJson(lastTxKind_) + "\"}");
    currentTxScope_ = TxScope::None;
    currentTxKind_ = "";
    return 0;
  }

  const unsigned long charUs = phy_.txCharacterUs();
  const unsigned long expectedDurationUs = charUs * length;
  const unsigned long expectedDoneUs = firstTxUs + expectedDurationUs;
  const unsigned long doneUs =
      afterWriteUs > expectedDoneUs ? afterWriteUs : expectedDoneUs;
  const unsigned long durationDriftUs =
      afterWriteUs > expectedDoneUs ? (afterWriteUs - expectedDoneUs) : 0;
  lastTxStartUs_ = firstTxUs;
  lastTxDoneUs_ = doneUs;
  lastTxReleaseUs_ = doneUs;
  lastTxFrame_.timestampUs = firstTxUs;
  noteActualTxKind(txKind, txKindEnum, stateBeforeTx, firstTxUs);

  setResponsePathState(ResponsePathState::TxSending, firstTxUs, txKind);
  emitTxTraceEvent("response_queue_dequeue",
                   String("{\"tx_kind\":\"") + escapeForJson(lastTxKind_) +
                       "\",\"queue_depth\":0,\"timestamp_us\":" + firstTxUs + "}");
  emitTxTraceEvent("tx_start",
                   String("{\"timestamp_us\":") + firstTxUs + ",\"tx_kind\":\"" +
                       escapeForJson(lastTxKind_) + "\",\"frame_hex\":\"" +
                       lastTxFrame_.hex + "\"}");
  emitTxTraceEvent("tx_bitstream_start",
                   String("{\"timestamp_us\":") + firstTxUs + ",\"tx_kind\":\"" +
                       escapeForJson(lastTxKind_) + "\",\"bit_period_us\":" +
                       phy_.txBitPeriodUs() + ",\"character_tx_us\":" + charUs + "}");
  emitTxTraceEvent("tx_gpio_assert_low",
                   String("{\"timestamp_us\":") + firstTxUs + ",\"tx_kind\":\"" +
                       escapeForJson(lastTxKind_) +
                       "\",\"mdb_line_level\":\"low\"}");
  emitTxTraceEvent("tx_done",
                   String("{\"timestamp_us\":") + doneUs + ",\"tx_kind\":\"" +
                       escapeForJson(lastTxKind_) + "\",\"frame_hex\":\"" +
                       lastTxFrame_.hex + "\",\"expected_done_us\":" +
                       expectedDoneUs + ",\"duration_drift_us\":" +
                       durationDriftUs + "}");
  emitTxTraceEvent("tx_line_release",
                   String("{\"timestamp_us\":") + doneUs + ",\"tx_kind\":\"" +
                       escapeForJson(lastTxKind_) +
                       "\",\"mdb_line_level\":\"idle_high\"}");
  emitTxTraceEvent("tx_gpio_release_high",
                   String("{\"timestamp_us\":") + doneUs + ",\"tx_kind\":\"" +
                       escapeForJson(lastTxKind_) +
                       "\",\"mdb_line_level\":\"high\"}");
  appendDialogueEvent(DialogueDirection::TxToMachine, txKindEnum, firstRaw9,
                      frame[0], length == 1, stateBeforeTx, readerState_,
                      decisionReason, doneUs);
  setResponsePathState(ResponsePathState::TxDone, doneUs, txKind);
  setResponsePathState(ResponsePathState::TxReleased, doneUs, txKind);
  setResponsePathState(ResponsePathState::Idle, doneUs, "tx_complete");
  flushPendingProbeIfIdle();

  if (durationDriftUs > 0) {
    emitTxTraceEvent("tx_duration_observed",
                     String("{\"tx_kind\":\"") + escapeForJson(lastTxKind_) +
                         "\",\"expected_done_us\":" + expectedDoneUs +
                         ",\"actual_done_us\":" + afterWriteUs +
                         ",\"duration_drift_us\":" + durationDriftUs + "}");
  }
  txSuccessCount_++;
  noteTxCompleted(txKind, txKindEnum);

  currentTxScope_ = TxScope::None;
  currentTxKind_ = "";
  return firstTxUs;
}

unsigned long MdbService::transmitDebugFrame(TxScope scope, const char* txKind,
                                             const uint8_t* frame,
                                             size_t length) {
  if (frame == nullptr || length == 0) {
    return 0;
  }
  currentTxScope_ = scope;
  currentTxKind_ = txKind == nullptr ? "" : txKind;
  beginDeferredTxTrace();
  const unsigned long firstTxUs = phy_.write(frame, length);
  flushDeferredTxTrace();
  currentTxScope_ = TxScope::None;
  currentTxKind_ = "";
  return firstTxUs;
}

void MdbService::beginDeferredTxTrace() {
  deferTxObserverEvents_ = true;
  deferredTxFrameId_ = 0;
  deferredTxCount_ = 0;
}

void MdbService::flushDeferredTxTrace() {
  for (size_t i = 0; i < deferredTxCount_; ++i) {
    emitObservedTxByte(currentTxScope_, deferredTxFrameId_, i, deferredTxBytes_[i],
                       deferredTxNinthBits_[i], deferredTxTimestampsUs_[i]);
  }
  deferredTxFrameId_ = 0;
  deferredTxCount_ = 0;
  deferTxObserverEvents_ = false;
}

void MdbService::handlePhyTxObserved(uint32_t frameId, size_t byteIndex, uint8_t value,
                                     uint8_t ninthBit, unsigned long tsUs) {
  if (deferTxObserverEvents_) {
    if (deferredTxCount_ < kStoredFrameBytes) {
      deferredTxFrameId_ = frameId;
      deferredTxBytes_[deferredTxCount_] = value;
      deferredTxNinthBits_[deferredTxCount_] = ninthBit;
      deferredTxTimestampsUs_[deferredTxCount_] = tsUs;
      deferredTxCount_++;
    }
    return;
  }
  emitObservedTxByte(currentTxScope_, frameId, byteIndex, value, ninthBit, tsUs);
}

void MdbService::handlePhyStatusObserved(const char* eventName, unsigned long tsUs,
                                         UBaseType_t priority, BaseType_t coreId,
                                         uint32_t auxValue) {
  if (strcmp(eventName, "phy_task_alive") == 0 ||
      strcmp(eventName, "phy_task_tick") == 0) {
    const uint32_t loopCounter = strcmp(eventName, "phy_task_tick") == 0 ? (auxValue >> 1U) : auxValue;
    const uint32_t pinLevel = strcmp(eventName, "phy_task_tick") == 0 ? (auxValue & 0x1U) : 0U;
    creditFlowPhyLoopCounter_ = loopCounter;
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent(eventName,
                String("{\"loop_counter\":") + loopCounter +
                    ",\"pin_level\":" + pinLevel + "}");
    }
    return;
  }
  if (strcmp(eventName, "phy_config_ok") == 0) {
    emitEvent("phy_config_ok",
              String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                  ",\"core_id\":" + coreId + ",\"phy_is_ready\":" + auxValue +
                  ",\"uart_mode\":\"8bit_parity_hack_rx\","
                  "\"rx_inverted_status\":" + boolToJson(rxInvertEnabled_) +
                  ",\"rx_timeout_chars\":2,\"rx_full_threshold\":1,"
                  "\"soft_rx_mode\":\"timer_grid\","
                  "\"soft_start_level\":" + (rxInvertEnabled_ ? "1" : "0") +
                  ",\"soft_data_invert\":" + boolToJson(rxInvertEnabled_) +
                  ",\"bit_period_us\":104,"
                  "\"sample_offset_us\":" + SAMPLE_OFFSET_US +
                  ",\"start_guard_us\":28}");
    return;
  }
  if (strcmp(eventName, "phy_gpio_init_level") == 0) {
    emitEvent("phy_gpio_init_level",
              String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                  ",\"core_id\":" + coreId + ",\"rx_pin\":" + MDB_RX_PIN +
                  ",\"gpio_level\":" + auxValue + "}");
    return;
  }
  if (strcmp(eventName, "phy_tx_idle_check") == 0) {
    emitEvent("phy_tx_idle_check",
              String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                  ",\"core_id\":" + coreId + ",\"tx_pin\":" + MDB_TX_PIN +
                  ",\"gpio_level\":" + auxValue + "}");
    return;
  }
  if (strcmp(eventName, "phy_raw_edge_count") == 0) {
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("phy_raw_edge_count",
                String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                    ",\"core_id\":" + coreId + ",\"raw_edge_count\":" + auxValue + "}");
    }
    return;
  }
  if (strcmp(eventName, "phy_decoder_state") == 0) {
    const uint32_t bitPos = auxValue & 0xFFU;
    const uint32_t lastByte = (auxValue >> 8U) & 0xFFU;
    const bool ninthBit = (auxValue & (1UL << 16U)) != 0;
    const uint32_t resetReason = (auxValue >> 17U) & 0x7FU;
    const uint32_t pathIndex = (auxValue >> 24U) & 0x3U;
    const uint32_t mode = (auxValue >> 26U) & 0x3U;
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("phy_decoder_state",
                String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                    ",\"core_id\":" + coreId + ",\"bit_pos\":" + bitPos +
                    ",\"last_byte\":" + lastByte +
                    ",\"last_byte_hex\":\"" + byteToHex(static_cast<uint8_t>(lastByte)) +
                    "\",\"ninth_bit\":" + boolToJson(ninthBit) +
                    ",\"reset_reason\":" + resetReason +
                    ",\"mode\":" + mode +
                    ",\"path\":\"" + String(decoderPathLabel(pathIndex)) + "\"}");
    }
    return;
  }
  if (strcmp(eventName, "phy_decoder_mode") == 0) {
    emitEvent("phy_decoder_mode",
              String("{\"ts_us\":") + tsUs + ",\"mode\":" + auxValue + "}");
    for (uint8_t mode = 0; mode < MachinePhy::kSoftwareDecoderModes; ++mode) {
      emitDecoderModeScore(mode, "mode_switched");
    }
    return;
  }
  if (strcmp(eventName, "phy_soft_bit_trace") == 0) {
    const uint8_t partialByte = static_cast<uint8_t>(auxValue & 0xFFU);
    const bool ninthBit = (auxValue & (1UL << 8U)) != 0;
    const uint32_t pathIndex = (auxValue >> 9U) & 0x3U;
    const uint32_t mode = (auxValue >> 11U) & 0x3U;
    if (mode < MachinePhy::kSoftwareDecoderModes) {
      decoderModeTraceCount_[mode]++;
      decoderModeLastPartial_[mode] = partialByte;
      decoderModeLastPath_[mode] = static_cast<uint8_t>(pathIndex);
    }
    const String bitsLsb = byteBitsLsbFirst(partialByte, 5);
    const String bitsMsb = byteBitsMsbView(partialByte, 5);
    if (kEmitVerbosePhyDecoderEvents) {
      emitEvent("phy_soft_bit_trace",
                String("{\"ts_us\":") + tsUs + ",\"partial_byte\":" + partialByte +
                    ",\"partial_byte_hex\":\"" + byteToHex(partialByte) +
                    "\",\"mode\":" + mode +
                    ",\"bit_buffer_lsb_first\":\"" + bitsLsb +
                    "\",\"bit_buffer_msb_view\":\"" + bitsMsb +
                    "\",\"ninth_bit\":" + boolToJson(ninthBit) +
                    ",\"path\":\"" + String(decoderPathLabel(pathIndex)) + "\"}");
      if (mode < MachinePhy::kSoftwareDecoderModes &&
          (partialByte != 0 || decoderModeTraceCount_[mode] == 1 ||
           (decoderModeTraceCount_[mode] % 64U) == 0U)) {
        emitDecoderModeScore(static_cast<uint8_t>(mode), "bit_trace");
      }
    }
    return;
  }
  if (strcmp(eventName, "phy_gpio14_drive_capability") == 0) {
    emitEvent("phy_gpio14_drive_capability",
              String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                  ",\"core_id\":" + coreId + ",\"rx_pin\":" + MDB_RX_PIN +
                  ",\"drive_capability\":" + auxValue + "}");
    return;
  }
  if (strcmp(eventName, "MDB_BUS_STUCK") == 0) {
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("MDB_BUS_STUCK",
                String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                    ",\"core_id\":" + coreId + ",\"level\":" + auxValue + "}");
    }
    return;
  }
  if (strcmp(eventName, "phy_init_error") == 0) {
    emitEvent("phy_init_error", String("{\"error_code\":") + auxValue + "}");
    return;
  }
  if (strcmp(eventName, "phy_fast_ack_request") == 0) {
    const uint8_t firstByte = static_cast<uint8_t>(auxValue & 0xFFU);
    if (isIgnoredForeignTailByte(firstByte)) {
      return;
    }
    const bool isCoinChangerCommand =
        kMdbCoinChangerEnabled &&
        ((firstByte >> 3U) == kMdbCoinChangerAddress);
    const bool isCoinChangerPoll =
        isCoinChangerCommand &&
        ((firstByte & 0x07U) == kCoinChangerPollCommand);
    const bool isGatewayPoll = firstByte == kObservedGatewayPollByte;
    const bool isCashlessCommand =
        kMdbCashlessEnabled && isCashlessDevice1CommandByte(firstByte);
    if (!isCashlessCommand && !isGatewayPoll && !isCoinChangerCommand) {
      return;
    }

    const bool isCashlessReset =
        firstByte == cashlessCommandByte(kCashlessResetCommand);
    const bool isCashlessPoll = firstByte == cashlessCommandByte(kCashlessPollCommand);
    if (isCoinChangerPoll) {
      fastHandledFramePending_ = true;
      fastHandledFrameEndedUs_ = tsUs;
      fastHandledFrameAddress_ = kMdbCoinChangerAddress;
      fastHandledFrameCommand_ = kCoinChangerPollCommand;
      deferredFastPathCashlessTxUs_ =
          sendCoinChangerPollResponse("coin_poll_fast_ack_request", false);
      return;
    }
    if (isCashlessReset) {
      // RESET is acknowledged only after the checksum-valid frame is assembled.
      return;
    }
    if (!isCashlessPoll && !isGatewayPoll) {
      return;
    }

    fastHandledFramePending_ = true;
    fastHandledFrameEndedUs_ = tsUs;
    fastHandledFrameAddress_ = cashlessAddress_;
    fastHandledFrameCommand_ = kCashlessPollCommand;

    deferredFastPathCashlessTxUs_ =
        sendCashlessPollReply(millis(), tsUs, deferredFastPathCashlessKind_,
                              deferredFastPathCashlessEnabled_);
    return;
  }
  if (strcmp(eventName, "phy_rx_raw_debug") == 0) {
    const uint8_t firstByte = static_cast<uint8_t>(auxValue & 0xFFU);
    const bool ninthBit = (auxValue & (1UL << 8U)) != 0;
    if (creditFlowActive_) {
      creditFlowLastRxByteUs_ = tsUs;
    }
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("phy_rx_raw_debug",
                String("{\"ts_us\":") + tsUs + ",\"first_byte\":" + auxValue +
                    ",\"first_byte_hex\":\"" + byteToHex(firstByte) +
                    "\",\"ninth_bit\":" + boolToJson(ninthBit) +
                    "\",\"credit_flow_active\":" + boolToJson(creditFlowActive_) + "}");
    }
    if (kEmitVerbosePhyRuntimeEvents &&
        firstByte == cashlessCommandByte(kCashlessSetupCommand) &&
        (millis() - lastCapturedSymbolDumpAtMs_) > 250UL) {
      MachinePhy::CapturedSymbol symbols[8] = {};
      const size_t count = phy_.copyCapturedSymbols(symbols, 8);
      String json = String("{\"count\":") + count + ",\"symbols\":[";
      for (size_t i = 0; i < count; ++i) {
        if (i > 0) {
          json += ',';
        }
        json += String("{\"raw_bits\":\"") + String(symbols[i].data, HEX) +
                "\",\"timestamp_us\":" + symbols[i].timestampUs + "}";
      }
      json += "]}";
      emitEvent("phy_captured_symbols_snapshot", json);
      lastCapturedSymbolDumpAtMs_ = millis();
    }

    auto resetGatewaySetupCompat = [&]() {
      if (kLogGatewaySetupCompatTrace && gatewaySetupCompatStage_ != 0) {
        emitEvent("cashless_gateway_setup_trace",
                  String("{\"action\":\"reset\",\"stage\":") +
                      gatewaySetupCompatStage_ + "}");
      }
      gatewaySetupCompatStage_ = 0;
      gatewaySetupCompatStartedUs_ = 0;
      gatewaySetupCompatSawExplicitZero_ = false;
    };
    auto beginGatewaySetupCompat = [&]() {
      gatewaySetupCompatStage_ = 1;
      gatewaySetupCompatStartedUs_ = tsUs;
      gatewaySetupCompatSawExplicitZero_ = false;
      if (kLogGatewaySetupCompatTrace) {
        emitEvent("cashless_gateway_setup_trace",
                  "{\"action\":\"begin\",\"stage\":1}");
      }
    };
    auto handleGatewaySetupCompat = [&]() {
      const uint8_t setupCommand = cashlessCommandByte(kCashlessSetupCommand);
      const uint8_t syntheticValues[5] = {
          setupCommand, kObservedGatewaySetupPayload1, kObservedGatewaySetupPayload2,
          kObservedGatewaySetupPayload3,
          static_cast<uint8_t>(setupCommand + kObservedGatewaySetupPayload1 +
                               kObservedGatewaySetupPayload2 +
                               kObservedGatewaySetupPayload3)};
      machine::RawByte synthetic[5] = {};
      for (size_t i = 0; i < 5; ++i) {
        synthetic[i].raw = syntheticValues[i];
        synthetic[i].value7 = syntheticValues[i];
        synthetic[i].highBit = (i == 0);
        synthetic[i].tsUs = tsUs;
        synthetic[i].tsMs = tsUs / 1000UL;
        synthetic[i].gapBeforeMs = 0;
      }
      machine::Frame assumedFrame;
      machine::buildFrame(synthetic, 5, assumedFrame);
      assumedFrame.finalizedAtUs = tsUs;
      assumedFrame.frameGapAfterMs = 0;
      const unsigned long now = millis();
      handleFastFrameObserved(assumedFrame, now);
      clearPendingCashlessSplitPrefix();
      dispatchAcceptedFrame(assumedFrame, now, true);
      storeSniffFrame(assumedFrame);
      emitEvent("cashless_gateway_setup_compat",
                String("{\"observed_hex\":\"19 03 01") +
                    (gatewaySetupCompatSawExplicitZero_ ? " 00" : "") +
                    " 1D\",\"synthetic_frame_hex\":\"" +
                    bytesToHex(syntheticValues, 5) +
                    "\",\"inserted_missing_zero\":" +
                    boolToJson(!gatewaySetupCompatSawExplicitZero_) + "}");
      clearObservedRawStatusWindow();
      resetGatewaySetupCompat();
    };

    if (gatewaySetupCompatStage_ != 0 &&
        (tsUs < gatewaySetupCompatStartedUs_ ||
         (tsUs - gatewaySetupCompatStartedUs_) >
             kObservedGatewaySetupCompatWindowUs)) {
      resetGatewaySetupCompat();
    }

    if (ninthBit && firstByte == kObservedGatewaySetupByte) {
      beginGatewaySetupCompat();
    } else {
      switch (gatewaySetupCompatStage_) {
        case 1:
          if (!ninthBit && firstByte == kObservedGatewaySetupPayload1) {
            gatewaySetupCompatStage_ = 2;
            if (kLogGatewaySetupCompatTrace) {
              emitEvent("cashless_gateway_setup_trace",
                        "{\"action\":\"advance\",\"stage\":2}");
            }
          } else {
            resetGatewaySetupCompat();
          }
          break;
        case 2:
          if (!ninthBit && firstByte == kObservedGatewaySetupPayload2) {
            gatewaySetupCompatStage_ = 3;
            if (kLogGatewaySetupCompatTrace) {
              emitEvent("cashless_gateway_setup_trace",
                        "{\"action\":\"advance\",\"stage\":3}");
            }
          } else {
            resetGatewaySetupCompat();
          }
          break;
        case 3:
          if (!ninthBit && firstByte == kObservedGatewaySetupPayload3) {
            gatewaySetupCompatSawExplicitZero_ = true;
            gatewaySetupCompatStage_ = 4;
            if (kLogGatewaySetupCompatTrace) {
              emitEvent("cashless_gateway_setup_trace",
                        "{\"action\":\"advance\",\"stage\":4}");
            }
          } else if (ninthBit && firstByte == kObservedGatewaySetupChecksum) {
            if (kLogGatewaySetupCompatTrace) {
              emitEvent("cashless_gateway_setup_trace",
                        "{\"action\":\"complete\",\"stage\":3}");
            }
            handleGatewaySetupCompat();
            return;
          } else {
            resetGatewaySetupCompat();
          }
          break;
        case 4:
          if (ninthBit && firstByte == kObservedGatewaySetupChecksum) {
            if (kLogGatewaySetupCompatTrace) {
              emitEvent("cashless_gateway_setup_trace",
                        "{\"action\":\"complete\",\"stage\":4}");
            }
            handleGatewaySetupCompat();
            return;
          }
          resetGatewaySetupCompat();
          break;
        default:
          break;
      }
    }

    appendObservedRawStatusByte(firstByte, ninthBit, tsUs);
    return;
  }
  if (strcmp(eventName, "phy_soft_byte") == 0) {
    const uint8_t firstByte = static_cast<uint8_t>(auxValue & 0xFFU);
    const bool ninthBit = (auxValue & (1UL << 8U)) != 0;
    const uint32_t pathIndex = (auxValue >> 9U) & 0x3U;
    const uint32_t mode = (auxValue >> 11U) & 0x3U;
    if (mode < MachinePhy::kSoftwareDecoderModes) {
      decoderModeByteCount_[mode]++;
      decoderModeLastByte_[mode] = firstByte;
      decoderModeLastPath_[mode] = static_cast<uint8_t>(pathIndex);
      const uint8_t distanceTo10 = byteDistance(firstByte, 0x10U);
      const uint8_t distanceTo08 = byteDistance(firstByte, 0x08U);
      if (distanceTo10 <= decoderModeBestDistanceTo10_[mode]) {
        decoderModeBestDistanceTo10_[mode] = distanceTo10;
        decoderModeBestByte_[mode] = firstByte;
      }
      if (distanceTo08 <= decoderModeBestDistanceTo08_[mode]) {
        decoderModeBestDistanceTo08_[mode] = distanceTo08;
        decoderModeBestByte_[mode] = firstByte;
      }
    }
    if (creditFlowActive_) {
      creditFlowLastRxByteUs_ = tsUs;
    }
    const String bitsLsb = byteBitsLsbFirst(firstByte, 8);
    const String bitsMsb = byteBitsMsbView(firstByte, 8);
    if (kEmitVerbosePhyDecoderEvents) {
      emitEvent("phy_soft_byte",
                String("{\"ts_us\":") + tsUs + ",\"byte\":" + firstByte +
                    ",\"byte_hex\":\"" + byteToHex(firstByte) +
                    "\",\"mode\":" + mode +
                    ",\"bit_buffer_lsb_first\":\"" + bitsLsb +
                    "\",\"bit_buffer_msb_view\":\"" + bitsMsb +
                    "\",\"ninth_bit\":" + boolToJson(ninthBit) +
                    ",\"path\":\"" + String(decoderPathLabel(pathIndex)) + "\"" +
                    ",\"credit_flow_active\":" + boolToJson(creditFlowActive_) + "}");
      if (mode < MachinePhy::kSoftwareDecoderModes) {
        emitDecoderModeScore(static_cast<uint8_t>(mode), "soft_byte");
      }
    }
    return;
  }
  if (strcmp(eventName, "phy_read_status") == 0) {
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("phy_read_status",
                String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                    ",\"core_id\":" + coreId + ",\"aux_value\":" + auxValue +
                    ",\"credit_flow_active\":" + boolToJson(creditFlowActive_) + "}");
    }
    return;
  }
  if (strcmp(eventName, "phy_rx_error_byte") == 0) {
    const uint8_t rawByte = static_cast<uint8_t>(auxValue & 0xFFU);
    const bool ninthBit = (auxValue & (1UL << 8U)) != 0;
    if (creditFlowActive_) {
      creditFlowLastRxByteUs_ = tsUs;
    }
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("phy_rx_error_byte",
                String("{\"ts_us\":") + tsUs + ",\"raw_hex_byte\":\"" +
                    byteToHex(rawByte) + "\",\"raw_byte\":" + rawByte +
                    ",\"ninth_bit\":" + boolToJson(ninthBit) +
                    ",\"credit_flow_active\":" + boolToJson(creditFlowActive_) + "}");
    }
    appendObservedRawStatusByte(rawByte, ninthBit, tsUs);
    return;
  }
  if (strcmp(eventName, "phy_uart_error") == 0) {
    const uint32_t errorCode = auxValue & 0xFFU;
    const bool addressBitHint = (auxValue & (1UL << 8U)) != 0;
    if (kEmitVerbosePhyRuntimeEvents) {
      emitEvent("phy_uart_error",
                String("{\"ts_us\":") + tsUs + ",\"error_code\":" + errorCode +
                    ",\"address_bit_hint\":" + boolToJson(addressBitHint) +
                    ",\"credit_flow_active\":" + boolToJson(creditFlowActive_) + "}");
    }
    return;
  }
  emitEvent(eventName,
            String("{\"ts_us\":") + tsUs + ",\"task_priority\":" + priority +
                ",\"core_id\":" + coreId + ",\"aux_value\":" + auxValue +
                ",\"credit_flow_active\":" + boolToJson(creditFlowActive_) + "}");
}

void MdbService::handleFastFrameObserved(const machine::Frame& frame,
                                         unsigned long finalizedAtMs) {
  if (frame.length == 0) {
    return;
  }

  if (lastResetAckSentUs_ > 0 && frame.endedAtUs > lastResetAckSentUs_ &&
      (lastNextRxAfterResetTsUs_ == 0 ||
       lastNextRxAfterResetTsUs_ < lastResetAckSentUs_)) {
    lastNextRxAfterResetTsUs_ = frame.endedAtUs;
    const DialogueKind nextKindAfterReset = classifyRxFrameKind(frame);
    const unsigned long deltaSinceResetAckUs = frame.endedAtUs - lastResetAckSentUs_;
    if (nextKindAfterReset == DialogueKind::Poll) {
      nextActionHypothesis_ = "vmc_polled_after_reset_ack";
    } else if (nextKindAfterReset == DialogueKind::Setup) {
      nextActionHypothesis_ = "vmc_restarted_setup_after_reset_ack";
    } else if (nextKindAfterReset == DialogueKind::Unknown) {
      nextActionHypothesis_ = "vmc_sent_non_dialogue_or_foreign_frame_after_reset_ack";
    } else {
      nextActionHypothesis_ =
          String("vmc_sent_") + dialogueKindLabel(nextKindAfterReset) +
          "_after_reset_ack";
    }
    emitEvent("next_rx_after_reset_ack_seen",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"delta_from_ack_us\":" + deltaSinceResetAckUs +
                  ",\"kind\":\"" + dialogueKindLabel(nextKindAfterReset) +
                  "\",\"frame_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"candidate_address\":" +
                  (frame.hasCandidateAddress
                       ? String(static_cast<unsigned int>(frame.candidateAddress))
                       : String("-1")) +
                  ",\"candidate_command\":" +
                  (frame.hasCandidateAddress
                       ? String(static_cast<unsigned int>(frame.candidateCommand))
                       : String("-1")) +
                  ",\"next_action_hypothesis\":\"" +
                  escapeForJson(nextActionHypothesis_) + "\"}");
  }

  if (kForceTestResponseOnAnyValidRx &&
      ((frame.checksumValid && frame.hasCandidateAddress) ||
       (kMdbCashlessEnabled && frame.normalizedLength == 1 &&
        frame.normalized[0] == kObservedGatewayPollByte))) {
    const uint8_t forcedFrame[] = {kForcedTestResponseByte};
    transmitResponseFrame("forced_test_response", "forced_test_response",
                          forcedFrame, sizeof(forcedFrame), frame.endedAtUs);
    fastHandledFramePending_ = true;
    fastHandledFrameEndedUs_ = frame.endedAtUs;
    fastHandledFrameAddress_ =
        frame.hasCandidateAddress ? frame.candidateAddress : cashlessAddress_;
    fastHandledFrameCommand_ =
        frame.hasCandidateAddress ? frame.candidateCommand : 0;
    return;
  }

  auto markFastHandled = [&]() {
    fastHandledFramePending_ = true;
    fastHandledFrameEndedUs_ = frame.endedAtUs;
    fastHandledFrameAddress_ =
        frame.hasCandidateAddress ? frame.candidateAddress : cashlessAddress_;
    fastHandledFrameCommand_ = frame.hasCandidateAddress ? frame.candidateCommand : 0;
  };

  auto handleFastPollReply = [&](const char* transitionReason,
                                 bool gatewayCompat) {
    if (kLogEveryPoll) {
      String payload = String("{\"timestamp_us\":") + frame.endedAtUs +
                       ",\"reader_state\":\"" + readerStateLabel(readerState_) +
                       "\"";
      payload += gatewayCompat ? ",\"gateway_compat\":true}"
                               : ",\"fast_path\":true}";
      emitEvent("poll_rx_seen", payload);
    }
    transitionReaderState(ReaderState::PollActive, transitionReason,
                          frame.endedAtUs);
    deferredFastPathCashlessTxUs_ =
        sendCashlessPollReply(finalizedAtMs, frame.endedAtUs,
                              deferredFastPathCashlessKind_,
                              deferredFastPathCashlessEnabled_);
    if (deferredFastPathCashlessKind_ == 2) {
      transitionReaderState(ReaderState::ResetSeen, "poll_just_reset_fast",
                            deferredFastPathCashlessTxUs_);
    } else if (deferredFastPathCashlessKind_ == 3) {
      transitionReaderState(ReaderState::SessionActive,
                            "poll_begin_session_fast",
                            deferredFastPathCashlessTxUs_);
    } else if (deferredFastPathCashlessEnabled_) {
      transitionReaderState(ReaderState::SessionIdle, "poll_ack_fast",
                            deferredFastPathCashlessTxUs_);
    } else {
      transitionReaderState(ReaderState::Disabled,
                            "poll_ack_while_disabled_fast",
                            deferredFastPathCashlessTxUs_);
    }
    markFastHandled();
  };

  if (frame.checksumValid && frame.hasCandidateAddress &&
      matchesCashlessDialogueAddress(frame.candidateAddress,
                                     frame.candidateCommand) &&
      frame.candidateCommand == kCashlessResetCommand) {
    const unsigned long ackPrepareUs = micros();
    const unsigned long deltaSinceSetupResponseUs =
        (lastSetupResponseTxUs_ > 0 && frame.endedAtUs >= lastSetupResponseTxUs_)
            ? (frame.endedAtUs - lastSetupResponseTxUs_)
            : 0;
    lastSetupResponseToResetUs_ = deltaSinceSetupResponseUs;
    lastResetCauseGuess_ =
        repeatedSetupSamePayloadCount_ > 0
            ? "reset_after_repeated_same_setup_retry"
            : (repeatedSetupCount_ > 0
                   ? "reset_after_setup_retry"
                   : (lastTxKind_ == "setup_response"
                          ? "reset_after_setup_response"
                          : "reset_without_prior_setup_retry"));
    repeatedSetupThenResetObserved_ = repeatedSetupCount_ > 0;
    if (repeatedSetupThenResetObserved_ && resetAfterSetupRetryCount_ < 0xFFFFU) {
      resetAfterSetupRetryCount_++;
    }
    resetSeenCount_++;
    lastResetTsUs_ = frame.endedAtUs;
    lastResetAckPreparedUs_ = ackPrepareUs;
    lastPollAfterResetTsUs_ = 0;
    lastJustResetSentUs_ = 0;
    lastNextRxAfterResetTsUs_ = 0;
    pollMissingAfterResetLogged_ = false;
    nextActionHypothesis_ = "vmc_should_poll_for_just_reset_status";
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "unknown";
      setupRejectionBasis_ = "reset_after_setup_response";
    }
    emitEvent("reset_seen",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"frame_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"fast_path\":true,\"repeated_setup_count_before_reset\":" +
                  repeatedSetupCount_ +
                  ",\"repeated_setup_same_payload_count_before_reset\":" +
                  repeatedSetupSamePayloadCount_ +
                  ",\"delta_from_last_setup_response_to_reset_us\":" +
                  deltaSinceSetupResponseUs +
                  ",\"last_reset_cause_guess\":\"" +
                  escapeForJson(lastResetCauseGuess_) + "\"}");
    if (repeatedSetupThenResetObserved_) {
      emitEvent("repeated_setup_then_reset_observed",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"repeated_setup_count\":" + repeatedSetupCount_ +
                    ",\"repeated_setup_same_payload_count\":" +
                    repeatedSetupSamePayloadCount_ +
                    ",\"last_reset_cause_guess\":\"" +
                    escapeForJson(lastResetCauseGuess_) + "\"}");
    }
    emitSetupResponseRejectionAudit("reset_after_setup_response", frame.endedAtUs,
                                    &frame, "reset",
                                    String("\"fast_path\":true"));
    if (lastTxKind_ == "setup_response" && lastTxDoneUs_ > 0 &&
        frame.endedAtUs >= lastTxDoneUs_) {
      emitEvent("setup_followed_by_reset",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"delay_us_since_setup_response\":" +
                    (frame.endedAtUs - lastTxDoneUs_) +
                    ",\"setup_reply_delay_us\":" +
                    lastSetupResponseReplyDelayUs_ +
                    ",\"fast_path\":true}");
    }
    noteExpectedTxKind(DialogueKind::Reset, readerState_, "ack", frame.endedAtUs,
                       true, "reset_requires_ack_fast");
    emitEvent("reset_ack_prepared",
              String("{\"timestamp_us\":") + ackPrepareUs +
                  ",\"expected_tx_kind\":\"ack\",\"fast_path\":true,"
                  "\"reset_rx_ts_us\":" + frame.endedAtUs +
                  ",\"delta_from_last_setup_response_to_reset_us\":" +
                  deltaSinceSetupResponseUs + "}");
    const unsigned long firstTxUs = sendAckRaw("cashless_reset_ack");
    resetAckSentCount_++;
    lastResetAckSentUs_ = firstTxUs;
    lastResetAckDoneUs_ = lastTxDoneUs_;
    lastResetAckReleaseUs_ = lastTxReleaseUs_;
    lastResetToAckUs_ =
        (firstTxUs > 0 && frame.endedAtUs > 0 && firstTxUs >= frame.endedAtUs)
            ? (firstTxUs - frame.endedAtUs)
            : 0;
    emitEvent("reset_ack_sent",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"tx_kind\":\"ack\",\"fast_path\":true"
                  ",\"ack_prepare_ts_us\":" + ackPrepareUs +
                  ",\"ack_tx_done_us\":" + lastResetAckDoneUs_ +
                  ",\"ack_release_us\":" + lastResetAckReleaseUs_ +
                  ",\"delta_from_reset_to_ack_us\":" + lastResetToAckUs_ +
                  "}");
    markSetupResponseAckMissing("reset_before_ack",
                                String("\"frame_hex\":\"") +
                                    machine::normalizedHex(frame) + "\"");
    isReaderEnabled_ = false;
    beginSessionPending_ = false;
    beginSessionAmountMinor_ = 0;
    cashlessJustResetPending_ = true;
    cashlessSetupSeen_ = false;
    cashlessSetupMaxMinSeen_ = false;
    cashlessSetupResponsePending_ = false;
    cashlessSetupResponseAwaitingAck_ = false;
    cashlessExpansionSeen_ = false;
    emitEvent("just_reset_pending_set",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"reason\":\"reset_ack_sent_fast\"}");
    transitionReaderState(ReaderState::ResetSeen, "reset_seen_fast",
                          frame.endedAtUs);
    emitEvent("waiting_for_poll_after_reset",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"just_reset_pending\":true,\"fast_path\":true"
                  ",\"next_action_hypothesis\":\"" +
                  escapeForJson(nextActionHypothesis_) + "\"}");
    emitPostResetProgressionExpectation("reset_ack_sent_fast", firstTxUs);
    session_.onReaderDisabled(finalizedAtMs);
    deferredFastPathCashlessTxUs_ = firstTxUs;
    deferredFastPathCashlessKind_ = 1;
    deferredFastPathCashlessEnabled_ = false;
    stateDirty_ = true;
    markFastHandled();
    return;
  }

  if (kMdbCashlessEnabled && frame.normalizedLength == 1 &&
      frame.normalized[0] == kObservedGatewayPollByte) {
    handleFastPollReply("gateway_poll_seen_fast", true);
    return;
  }

  if (kMdbCoinChangerEnabled && frame.normalizedLength == 1 &&
      frame.normalized[0] == kObservedCoinChangerPollByte) {
    const unsigned long pendingScaledBefore = coinChangerPendingScaled_;
    const bool justResetPendingBefore = coinChangerJustResetPending_;
    if (coinChangerAwaitingVmcScaled_ > 0 &&
        coinChangerLastCreditReplyTxUs_ > 0 &&
        frame.endedAtUs >= coinChangerLastCreditReplyTxUs_) {
      emitEvent("coin_reply_followup_poll_seen",
                String("{\"compat_mode\":true,\"rx_ts_us\":") +
                    frame.endedAtUs +
                    ",\"delta_us_from_last_credit_reply\":" +
                    (frame.endedAtUs - coinChangerLastCreditReplyTxUs_) +
                    ",\"awaiting_vmc_scaled\":" +
                    coinChangerAwaitingVmcScaled_ +
                    ",\"transaction_id\":\"" +
                    escapeForJson(coinChangerPendingTransactionId_) + "\"}");
    }
    emitEvent("compat_single_byte_trigger_observed",
    String("{\"experimental\":true,\"not_standard_mdb_poll\":true,\"raw_hex\":\"") +
    machine::rawHex(frame) +
    "\",\"normalized_hex\":\"" + machine::normalizedHex(frame) +
    "\",\"decoded_direction\":\"" + machine::directionToString(frame.decodedDirection) +
    "\",\"decoded_frame_kind\":\"" + machine::frameKindToString(frame.decodedKind) +
    "\",\"standard_mdb_valid\":" + boolToJson(frame.standardMdbValid) +
    ",\"compat_candidate\":" + boolToJson(frame.compatCandidate) +
    ",\"candidate_address\":" + String(static_cast<unsigned int>(frame.candidateAddress)) +
    ",\"candidate_command\":" + String(static_cast<unsigned int>(frame.candidateCommand)) +
    ",\"rx_ts_us\":" + String(frame.endedAtUs) +
    "}");
        const unsigned long firstTxUs =
        sendCoinChangerPollResponse("coin_poll_observed_compat", true);
    lastCoinCompatPollObservedUs_ = frame.endedAtUs;
    lastCoinCompatPollReplyTxUs_ = firstTxUs;
    coinCompatTailIgnoreUntilUs_ =
        frame.endedAtUs + kCoinCompatTailIgnoreWindowUs;
    emitEvent("coin_poll_observed_compat",
              String("{\"fast_path\":true,\"rx_ts_us\":") + frame.endedAtUs +
                  ",\"tx_ts_us\":" + firstTxUs +
                  ",\"pending_scaled_before_reply\":" + pendingScaledBefore +
                  ",\"remaining_scaled_after_reply\":" +
                  coinChangerPendingScaled_ +
                  ",\"just_reset_pending_before_reply\":" +
                  boolToJson(justResetPendingBefore) +
                  ",\"tail_ignore_until_us\":" +
                  coinCompatTailIgnoreUntilUs_ + "}");
    markFastHandled();
    return;
  }

  if (frame.checksumValid && frame.hasCandidateAddress &&
      matchesCoinChangerDialogueAddress(frame.candidateAddress,
                                        frame.candidateCommand) &&
      handleCoinChangerCommand(frame, finalizedAtMs, true)) {
    markFastHandled();
    return;
  }

  if (frame.checksumValid && frame.hasCandidateAddress &&
      matchesCashlessDialogueAddress(frame.candidateAddress,
                                     frame.candidateCommand)) {
    if (frame.candidateCommand == kCashlessPollCommand) {
      handleFastPollReply("poll_seen_fast", false);
      return;
    }

    if (frame.normalizedLength > 1 &&
        frame.candidateCommand == kCashlessSetupCommand &&
        !(frame.normalizedLength >= 2 &&
          frame.normalized[1] == kCashlessSetupMaxMinSubcommand)) {
      currentSetupResponseGatewayCompat_ =
          buildSetupVariantLabel(frame) == "SETUP_CONFIG_GATEWAY_COMPAT";
      lastSetupFastPathUsed_ = true;
      lastSetupRxTsUs_ = frame.bytes[0].tsUs;
      lastSetupRxEndUs_ = frame.endedAtUs;
      const bool hadJustResetPending = cashlessJustResetPending_;
      cashlessJustResetPending_ = false;
      nextActionHypothesis_ = "vmc_restarted_setup_sequence";
      cashlessSetupSeen_ = true;
      cashlessSetupMaxMinSeen_ = false;
      cashlessSetupResponsePending_ = false;
      cashlessExpansionSeen_ = false;
      const ReaderState stateBeforeSetup = readerState_;
      if (stateBeforeSetup != ReaderState::SetupSeen) {
        readerState_ = ReaderState::SetupSeen;
        stateTransitionCount_++;
        lastStateTransitionReason_ = "setup_seen_fast";
      }
      if (currentSetupResponseGatewayCompat_) {
        wrapperStandardFlowEntered_ = false;
        wrapperExpectedNextRxKind_ = "SETUP_RETRY_OR_ENABLE_OR_POLL";
        wrapperExpectedNextAction_ = "SEND_READER_CONFIG";
        setWrapperFsmState(WrapperFsmState::SetupConfigSeen,
                           "gateway_setup_config_seen", frame.endedAtUs);
      }
      lastSetupDecisionTsUs_ = micros();
      noteExpectedTxKind(DialogueKind::Setup, ReaderState::SetupSeen,
                         "setup_response", frame.endedAtUs, true,
                         "setup_requires_reader_config_fast", false);
      const unsigned long previousSetupResponseTxUs = lastSetupResponseTxUs_;
      deferredFastPathCashlessTxUs_ =
          sendReaderSetupResponse(frame.endedAtUs, "setup_response");
      if (currentSetupResponseGatewayCompat_) {
        armGatewayCompatFollowupTracking(deferredFastPathCashlessTxUs_);
      }
      if (hadJustResetPending) {
        emitEvent("just_reset_pending_cleared",
                  String("{\"timestamp_us\":") + deferredFastPathCashlessTxUs_ +
                      ",\"reason\":\"setup_seen_before_poll_fast\"}");
      }
      const unsigned long currentSetupResponseTxUs = lastSetupResponseTxUs_;
      lastSetupResponseTxUs_ = previousSetupResponseTxUs;
      noteSetupObserved(frame, frame.endedAtUs, "fast_setup_config");
      lastSetupResponseTxUs_ = currentSetupResponseTxUs;
      emitEvent("tx_expected_for_rx_kind",
                String("{\"rx_kind\":\"SETUP\",\"reader_state\":\"SETUP_SEEN\","
                       "\"expected_tx_kind\":\"setup_response\",\"required\":true,"
                       "\"reason\":\"setup_requires_reader_config_fast\","
                       "\"timestamp_us\":") +
                    frame.endedAtUs + "}");
      if (stateBeforeSetup != ReaderState::SetupSeen) {
        appendDialogueEvent(DialogueDirection::RxFromMachine,
                            DialogueKind::ReaderStateChange, 0, 0, false,
                            stateBeforeSetup, ReaderState::SetupSeen,
                            "setup_seen_fast", frame.endedAtUs);
        if (kLogEveryStateTransition) {
          emitEvent("reader_state_transition",
                    String("{\"old_state\":\"") +
                        readerStateLabel(stateBeforeSetup) +
                        "\",\"new_state\":\"SETUP_SEEN\",\"reason\":\"setup_seen_fast\","
                        "\"timestamp_us\":" + frame.endedAtUs + "}");
        }
      }
      transitionReaderState(ReaderState::SetupResponded,
                            "setup_response_sent_fast",
                            deferredFastPathCashlessTxUs_);
      if (currentSetupResponseGatewayCompat_) {
        emitEvent("gateway_wrapper_waiting_for_continuation",
                  buildGatewayWrapperWaitingForContinuationJson(
                      deferredFastPathCashlessTxUs_,
                      readerStateLabel(readerState_),
                      wrapperExpectedNextRxKindLabel(),
                      wrapperExpectedNextActionLabel()));
      } else {
        transitionReaderState(ReaderState::ExpansionPending,
                              "awaiting_expansion_or_enable_fast",
                              deferredFastPathCashlessTxUs_);
      }
      deferredFastPathCashlessKind_ = 5;
      deferredFastPathCashlessEnabled_ = isReaderEnabled_;
      markFastHandled();
      return;
    }

    if (frame.candidateCommand == kCashlessSetupCommand &&
        frame.normalizedLength >= 2 &&
        frame.normalized[1] == kCashlessSetupMaxMinSubcommand) {
      if (cashlessJustResetPending_) {
        emitEvent("just_reset_pending_cleared",
                  String("{\"timestamp_us\":") + frame.endedAtUs +
                      ",\"reason\":\"setup_max_min_seen_before_poll_fast\"}");
      }
      cashlessJustResetPending_ = false;
      nextActionHypothesis_ = "vmc_progressed_to_setup_max_min";
      cashlessSetupSeen_ = true;
      cashlessSetupMaxMinSeen_ = true;
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "false";
        setupRejectionBasis_ = "setup_max_min_progression";
      }
      noteSetupObserved(frame, frame.endedAtUs, "fast_setup_max_min");
      noteExpectedTxKind(DialogueKind::Setup, readerState_, "no_data",
                         frame.endedAtUs, false, "setup_max_min_no_data_fast");
      recordResponseDecision("setup_max_min_no_data", false, frame.endedAtUs);
      emitEvent("cashless_setup_max_min_seen",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"frame_hex\":\"" + machine::normalizedHex(frame) +
                    "\",\"fast_path\":true,\"response\":\"no_data\"}");
      deferredFastPathCashlessKind_ = 6;
      deferredFastPathCashlessEnabled_ = isReaderEnabled_;
      stateDirty_ = true;
      markFastHandled();
      return;
    }

    const bool isExpansionId =
        frame.candidateCommand == kCashlessExpansionCommand &&
        frame.normalizedLength >= 2 &&
        frame.normalized[1] == kCashlessExpansionIdSubcommand;
    if (isExpansionId) {
      if (cashlessJustResetPending_) {
        emitEvent("just_reset_pending_cleared",
                  String("{\"timestamp_us\":") + frame.endedAtUs +
                      ",\"reason\":\"expansion_seen_before_poll_fast\"}");
      }
      cashlessJustResetPending_ = false;
      nextActionHypothesis_ = "vmc_requested_expansion_id";
      cashlessExpansionSeen_ = true;
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "false";
        setupRejectionBasis_ = "expansion_progression";
      }
      noteExpectedTxKind(DialogueKind::ExpansionId, readerState_,
                         "expansion_response", frame.endedAtUs, true,
                         "expansion_request_id_fast");
      deferredFastPathCashlessTxUs_ =
          sendReaderExpansionIdResponse("expansion_response");
      transitionReaderState(ReaderState::Disabled,
                            "expansion_response_sent_fast",
                            deferredFastPathCashlessTxUs_);
      deferredFastPathCashlessKind_ = 6;
      deferredFastPathCashlessEnabled_ = isReaderEnabled_;
      markFastHandled();
      return;
    }

    if (frame.candidateCommand == kCashlessReaderControlCommand &&
        frame.normalizedLength >= 2 &&
        frame.normalized[1] == kCashlessReaderControlSubcommand) {
      const bool enable =
          frame.normalizedLength >= 3 ? frame.normalized[2] == 0x01 : true;
      emitEvent(enable ? "enable_seen" : "disable_seen",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"fast_path\":true}");
      isReaderEnabled_ = enable;
      if (enable) {
        if (setupResponseRejectedByVmc_ != "true") {
          setupResponseRejectedByVmc_ = "false";
          setupRejectionBasis_ = "enable_progression";
        }
        session_.onReaderEnabled(finalizedAtMs);
        emitEvent("enable_accepted",
                  String("{\"timestamp_us\":") + frame.endedAtUs +
                      ",\"fast_path\":true}");
        enableAppliedCount_++;
        transitionReaderState(ReaderState::Enabled, "enable_state_applied_fast",
                              frame.endedAtUs);
        transitionReaderState(ReaderState::SessionIdle,
                              "reader_enabled_waiting_poll_fast",
                              frame.endedAtUs);
        if (creditFlowActive_) {
          creditFlowEnableSeen_ = true;
          beginSessionPending_ = true;
          beginSessionAmountMinor_ = creditFlowAmountMinor_;
        }
      } else {
        session_.onReaderDisabled(finalizedAtMs);
        beginSessionPending_ = false;
        beginSessionAmountMinor_ = 0;
        transitionReaderState(ReaderState::Disabled, "disable_state_applied_fast",
                              frame.endedAtUs);
      }
      noteExpectedTxKind(enable ? DialogueKind::Enable : DialogueKind::Disable,
                         readerState_, "ack", frame.endedAtUs, true,
                         "reader_control_ack_fast");
      deferredFastPathCashlessTxUs_ = sendAckRaw("reader_control_ack");
      deferredFastPathCashlessKind_ = 7;
      deferredFastPathCashlessEnabled_ = enable;
      stateDirty_ = true;
      markFastHandled();
      return;
    }
  }

  if (!creditFlowActive_) {
    return;
  }

  if (frame.hasCandidateAddress && frame.candidateAddress == 12 &&
      frame.candidateCommand == 6 && !creditFlowVendApprovedSent_) {
    noteExpectedTxKind(DialogueKind::Unknown, readerState_, "vend_approved",
                       frame.endedAtUs, true, "vend_approved_fast");
    const unsigned long firstTxUs = sendVendApproved(100, "vend_approved");
    transitionReaderState(ReaderState::SessionActive, "vend_approved_sent_fast",
                          firstTxUs);
    creditFlowLastRxByteUs_ = frame.endedAtUs;
    creditFlowFrameFinalizedUs_ = frame.finalizedAtUs;
    creditFlowFirstTxByteUs_ = firstTxUs;
    creditFlowSessionHijackAttempted_ = true;
    creditFlowVendApprovedSent_ = true;
    creditFlowResponseDelayUs_ =
        (firstTxUs > 0 && frame.endedAtUs > 0 && firstTxUs >= frame.endedAtUs)
            ? (firstTxUs - frame.endedAtUs)
            : 0;
    creditFlowExactReplyDelayUs_ = creditFlowResponseDelayUs_;
    creditFlowObservationActive_ = true;
    creditFlowObservationEndsAt_ = finalizedAtMs + kCreditFlowObservationWindowMs;
    creditFlowPostReplyFrameCount_ = 0;
    creditFlowObservedFamilies_ = "";
    creditFlowCandidateBytes_ = "02 00 64";
    fastHandledFramePending_ = true;
    fastHandledFrameEndedUs_ = frame.endedAtUs;
    fastHandledFrameAddress_ = frame.candidateAddress;
    fastHandledFrameCommand_ = frame.candidateCommand;
    deferredFastPathVendApproved_ = true;
    deferredFastPathFinalizeCreditFlow_ = true;
    deferredFastPathFinalizeStatus_ = "completed";
    deferredFastPathFinalizeReason_ = "vend_approved_sent";
    return;
  }

  if (frame.hasCandidateAddress && frame.candidateAddress == 12 &&
      frame.candidateCommand == 7 &&
      !creditFlowBeginSessionSent_ && !creditFlowVendApprovedSent_) {
    noteExpectedTxKind(DialogueKind::Unknown, readerState_, "begin_session",
                       frame.endedAtUs, true, "begin_session_fast");
    const unsigned long firstTxUs = sendBeginSession(100, "begin_session");
    transitionReaderState(ReaderState::SessionActive,
                          "begin_session_sent_fast", firstTxUs);
    creditFlowLastRxByteUs_ = frame.endedAtUs;
    creditFlowFrameFinalizedUs_ = frame.finalizedAtUs;
    creditFlowFirstTxByteUs_ = firstTxUs;
    creditFlowSessionHijackAttempted_ = true;
    creditFlowBeginSessionSent_ = true;
    creditFlowAwaitingAck_ = true;
    creditFlowResponseDelayUs_ =
        (firstTxUs > 0 && frame.endedAtUs > 0 && firstTxUs >= frame.endedAtUs)
            ? (firstTxUs - frame.endedAtUs)
            : 0;
    creditFlowExactReplyDelayUs_ = creditFlowResponseDelayUs_;
    creditFlowObservationActive_ = true;
    creditFlowObservationEndsAt_ = finalizedAtMs + kCreditFlowObservationWindowMs;
    creditFlowPostReplyFrameCount_ = 0;
    creditFlowObservedFamilies_ = "";
    creditFlowCandidateBytes_ = "03 00 64";
    fastHandledFramePending_ = true;
    fastHandledFrameEndedUs_ = frame.endedAtUs;
    fastHandledFrameAddress_ =
        frame.hasCandidateAddress ? frame.candidateAddress : cashlessAddress_;
    fastHandledFrameCommand_ = frame.hasCandidateAddress ? frame.candidateCommand : 0;
    deferredFastPathBeginSession_ = true;
  }
}

// Логически отключает сервис и физический интерфейс.
void MdbService::deactivate() {
  active_ = false;
  phy_.deactivate();
}

// Главный цикл сервиса: PHY, parser, FSM, TTL кредита и события.
void MdbService::update() {
  if (!active_) {
    return;
  }

  const unsigned long now = millis();
  emitDebugTransportReadyIfNeeded(now);
  const CashlessSession::Snapshot beforeUpdate = session_.snapshot();
  session_.update(connectionService_.isWebSocketConnected(), now);
  applyDesiredState(now);
  if (snapshotChanged(beforeUpdate, session_.snapshot())) {
    stateDirty_ = true;
  }

  if (session_.snapshot().approvedAmountMinor > 0 &&
      now - lastApprovedAt_ > kApprovedCreditTtlMs) {
    const CashlessSession::Snapshot beforeClear = session_.snapshot();
    session_.clear(now);
    emitEvent("credit_expired", "{}");
    stateDirty_ = stateDirty_ || snapshotChanged(beforeClear, session_.snapshot());
  }

  if (hasCoinChangerUnresolvedPayment() && coinChangerQueuedAtMs_ > 0 &&
      now - coinChangerQueuedAtMs_ > kMdbCoinChangerPaymentTimeoutMs) {
    emitEvent("coin_payment_expired",
              String("{\"amount_minor\":") + coinChangerPendingAmountMinor_ +
                  ",\"remaining_scaled\":" + coinChangerPendingScaled_ +
                  ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                  ",\"vmc_credit_accepted\":false" +
                  ",\"transaction_id\":\"" +
                  escapeForJson(coinChangerPendingTransactionId_) + "\"}");
    clearCoinChangerPendingPayment();
    stateDirty_ = true;
  }

  const uint32_t rawGpioInterruptCount = phy_.rawGpioInterruptCount();
  if (rawGpioInterruptCount != lastReportedRawGpioInterruptCount_ &&
      (lastReportedRawGpioSnapshotAtMs_ == 0 ||
       (now - lastReportedRawGpioSnapshotAtMs_) >= 1000UL)) {
    if (kEmitVerbosePhyRuntimeEvents) {
      unsigned long tsUs[MachinePhy::kRecentRxInterrupts] = {};
      uint8_t levels[MachinePhy::kRecentRxInterrupts] = {};
      const size_t count =
          phy_.copyRecentRxInterrupts(tsUs, levels, MachinePhy::kRecentRxInterrupts);
      const unsigned long lastInterruptTsUs = count > 0 ? tsUs[count - 1] : 0;
      const unsigned long deltaUs =
          count >= 2 && tsUs[count - 1] >= tsUs[count - 2]
              ? (tsUs[count - 1] - tsUs[count - 2])
              : 0;
      String json = String("{\"raw_gpio_interrupt_count\":") + rawGpioInterruptCount +
                    ",\"last_interrupt_ts_us\":" + lastInterruptTsUs +
                    ",\"delta_us\":" + deltaUs +
                    ",\"recent_interrupts\":[";
      for (size_t i = 0; i < count; ++i) {
        if (i > 0) {
          json += ",";
        }
        json += String("{\"ts_us\":") + tsUs[i] + ",\"level\":" + levels[i] + "}";
      }
      json += "]}";
      emitEvent("phy_gpio_irq_snapshot", json);
    }
    lastReportedRawGpioInterruptCount_ = rawGpioInterruptCount;
    lastReportedRawGpioSnapshotAtMs_ = now;
  }

  phy_.update();
  processExperiment(now);
  machine::Frame frame;
  while (phy_.takeFrame(frame)) {
    if (pendingCashlessSplitPrefixActive_) {
      machine::Frame combinedFrame;
      if (tryBuildCashlessSplitFrame(frame, combinedFrame)) {
        emitEvent("cashless_split_frame_combined",
                  String("{\"prefix_hex\":\"") +
                      machine::normalizedHex(pendingCashlessSplitPrefixFrame_) +
                      "\",\"payload_hex\":\"" + machine::normalizedHex(frame) +
                      "\",\"combined_hex\":\"" +
                      machine::normalizedHex(combinedFrame) + "\"}");
        clearPendingCashlessSplitPrefix();
        frame = combinedFrame;
      } else if (frame.startedAtUs <= pendingCashlessSplitPrefixFrame_.endedAtUs ||
                 (frame.startedAtUs - pendingCashlessSplitPrefixFrame_.endedAtUs) >
                     kCashlessSplitContinuationWindowUs ||
                 frame.bytes[0].highBit) {
        clearPendingCashlessSplitPrefix();
      }
    }

    storeSniffFrame(frame);
    totalFramesSeen_++;
    if (monitorEnabled_) {
      emitEvent("rx_frame",
                String("{\"hex\":\"") + machine::rawHex(frame) +
                    "\",\"normalized_hex\":\"" + machine::normalizedHex(frame) +
                    "\",\"length\":" + frame.length +
                    ",\"frame_gap_before_ms\":" + frame.frameGapBeforeMs +
                    ",\"frame_gap_after_ms\":" + frame.frameGapAfterMs +
                    ",\"end_reason\":\"" + endReasonToString(frame.endReasonCode) +
                    "\",\"end_reason_code\":" + frame.endReasonCode +
                    ",\"inter_byte_gaps_ms\":" + gapsToJson(frame) +
                    ",\"maybe_partial\":" + boolToJson(frame.maybePartial) +
                    ",\"maybe_merged\":" + boolToJson(frame.maybeMerged) +
                    ",\"truncated\":" + boolToJson(frame.truncated) +
                    ",\"frame_capture_quality\":" + frame.captureQuality +
                    ",\"has_high_bit\":" + boolToJson(frame.hasHighBit) +
                    ",\"parse_ok\":" + boolToJson(frame.parseOk) +
                    ",\"checksum_valid\":" + boolToJson(frame.checksumValid) +
                    ",\"decoded_direction\":\"" +
                    machine::directionToString(frame.decodedDirection) +
                    "\",\"decoded_frame_kind\":\"" +
                    machine::frameKindToString(frame.decodedKind) +
                    "\",\"checksum_expected\":" + frame.checksumExpected +
                    ",\"checksum_received\":" + frame.checksumReceived +
                    ",\"strict_mode_bits_ok\":" +
                    boolToJson(frame.strictModeBitsOk) +
                    ",\"relaxed_decode_used\":" +
                    boolToJson(frame.relaxedDecodeUsed) +
                    ",\"single_byte_command\":" +
                    boolToJson(frame.singleByteCommand) +
                    ",\"standard_mdb_valid\":" +
                    boolToJson(frame.standardMdbValid) +
                    ",\"compat_candidate\":" +
                    boolToJson(frame.compatCandidate) +
                    ",\"continuation_attempted\":" +
                    boolToJson(frame.continuationAttempted) +
                    ",\"continuation_wait_started_ms\":" +
                    frame.continuationWaitStartedMs +
                    ",\"continuation_wait_ms\":" + frame.continuationWaitMs +
                    ",\"continuation_appended_bytes\":" +
                    frame.continuationAppendedBytes +
                    ",\"continuation_result\":\"" +
                    continuationResultToString(frame.continuationResultCode) +
                    "\",\"continuation_fail_reason\":\"" +
                    continuationFailReasonToString(
                        frame.continuationFailReasonCode) +
                    "\",\"reboot_gap_detected\":" +
                    boolToJson(frame.rebootGapDetected) +
                    ",\"session_break_gap_detected\":" +
                    boolToJson(frame.sessionBreakGapDetected) +
                    ",\"candidate_address\":" +
                    (frame.hasCandidateAddress ? String(frame.candidateAddress)
                                               : String(-1)) +
                    ",\"candidate_command\":" +
                    (frame.hasCandidateAddress ? String(frame.candidateCommand)
                                               : String(-1)) +
                    "}");
    }
    emitObservedRxBytes(frame);
    dispatchAcceptedFrame(frame, now, false);
    if (shouldTrackCashlessSplitPrefix(frame)) {
      pendingCashlessSplitPrefixFrame_ = frame;
      pendingCashlessSplitPrefixCapturedAtMs_ = now;
      pendingCashlessSplitPrefixActive_ = true;
      emitEvent("cashless_split_prefix_observed",
                String("{\"frame_hex\":\"") + machine::normalizedHex(frame) +
                    "\",\"candidate_address\":" + frame.candidateAddress +
                    ",\"candidate_command\":" + frame.candidateCommand + "}");
    } else if (pendingCashlessSplitPrefixActive_ &&
               now > pendingCashlessSplitPrefixCapturedAtMs_ &&
               (now - pendingCashlessSplitPrefixCapturedAtMs_) > 20UL) {
      clearPendingCashlessSplitPrefix();
    }
    rxFrameCount_++;
    lastRxFrameAt_ = now;
    if (lastProbeTxAt_ != 0 && now >= lastProbeTxAt_) {
      rxFramesAfterProbeTx_++;
    }
  }

  if (cashlessSetupResponseAwaitingAck_ && cashlessSetupResponseSentAtMs_ > 0 &&
      now >= cashlessSetupResponseSentAtMs_ &&
      (now - cashlessSetupResponseSentAtMs_) >= kSetupResponseAckTimeoutMs) {
    markSetupResponseAckMissing("timeout");
  }

  if (beginSessionAwaitingAck_ && lastBeginSessionSentAtMs_ > 0 &&
      now >= lastBeginSessionSentAtMs_ &&
      (now - lastBeginSessionSentAtMs_) >= kBeginSessionAckTimeoutMs) {
    markBeginSessionAckMissing("timeout", now);
  }

  if (experimentObservationActive_ && now >= experimentObservationEndsAt_) {
    emitEvent("observation_timeout_fired",
              String("{\"run_id\":") + experimentActiveRunId_ +
                  ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                  "\",\"observation_ends_at_ms\":" + experimentObservationEndsAt_ +
                  ",\"now_ms\":" + now + "}");
    finalizeExperimentObservation(now, "observation_timeout");
  }

  if (creditFlowObservationActive_ && now >= creditFlowObservationEndsAt_) {
    finalizeCreditFlowStrategy(now, "timed_out", "awaiting_begin_session_ack_timeout");
  }

  flushDeferredFastPathEvents();

  if (clearSessionPending_) {
    const CashlessSession::Snapshot beforeClear = session_.snapshot();
    const bool hadProtocolState =
        readerState_ != ReaderState::Uninitialized ||
        lastRxKind_ != DialogueKind::Unknown ||
        !lastTxKind_.isEmpty() ||
        setupRxCount_ > 0 || setupTxCount_ > 0 ||
        pollRxCount_ > 0 || enableRxCount_ > 0 ||
        dialogueHistoryCount_ > 0 ||
        wrapperFsmState_ != WrapperFsmState::Idle ||
        !wrapperTransitionReason_.isEmpty() ||
        responsePathState_ != ResponsePathState::Idle ||
        probeRequestPending_;
    session_.clear(now);
    resetCashlessRuntimeState(true);
    resetCoinChangerProtocolState(true);
    clearCoinChangerPendingPayment();
    clearSessionPending_ = false;
    emitEvent("session_cleared", "{}");
    emitEvent("cashless_runtime_state_cleared",
              String("{\"just_reset_pending\":") +
                  boolToJson(cashlessJustResetPending_) +
                  ",\"reader_state\":\"" +
                  escapeForJson(readerStateLabel(readerState_)) +
                  "\",\"expected_next_rx_kind\":\"" +
                  escapeForJson(expectedNextRxKindLabel()) +
                  "\",\"expected_next_tx_kind\":\"" +
                  escapeForJson(expectedNextTxKindLabel()) +
                  "\",\"protocol_state_was_dirty\":" +
                  boolToJson(hadProtocolState) + "}");
    stateDirty_ = true;
    stateDirty_ = stateDirty_ || snapshotChanged(beforeClear, session_.snapshot());
  }

  if (stateDirty_) {
    emitStateChanged();
    stateDirty_ = false;
  }
}

// Переводит pending-платёж в активный кредит автомата.
void MdbService::requestApproveCredit(unsigned long amountMinor,
                                      const String& transactionId) {
  activate();
  const unsigned long now = millis();
  const CashlessSession::Snapshot before = session_.snapshot();
  String reason;
  bool changed = false;
  if (!session_.approvePayment(amountMinor, transactionId, now, reason, changed)) {
    emitEvent("approve_rejected",
              String("{\"reason\":\"") + escapeForJson(reason) + "\"}");
    return;
  }
  lastApprovedAt_ = now;
  if (changed) {
    if (session_.snapshot().approvedAmountMinor > 0) {
      const unsigned long amount = session_.snapshot().approvedAmountMinor;
      initiateBeginSession(
          static_cast<uint16_t>(amount > 0xFFFFUL ? 0xFFFFU : amount));
    }
    emitEvent("credit_approved",
              String("{\"amount_minor\":") + amountMinor +
                  ",\"pending_amount_minor\":" + session_.snapshot().pendingAmountMinor +
                  ",\"approved_amount_minor\":" +
                  session_.snapshot().approvedAmountMinor +
                  ",\"transaction_id\":\"" +
                  escapeForJson(session_.snapshot().approvedTransactionId) + "\"}");
    stateDirty_ = stateDirty_ || snapshotChanged(before, session_.snapshot());
  }
}

void MdbService::requestCoinPayment(unsigned long amountMinor,
                                    const String& transactionId) {
  activate();
  const unsigned long now = millis();
  if (amountMinor == 0) {
    emitEvent("payment_rejected",
              "{\"reason\":\"invalid_amount_minor\"}");
    return;
  }
  if ((amountMinor % kMdbCoinChangerScalingFactor) != 0) {
    emitEvent("payment_rejected",
              String("{\"reason\":\"unsupported_coin_scaling\","
                     "\"amount_minor\":") +
                  amountMinor + ",\"scale_factor\":" +
                  static_cast<unsigned int>(kMdbCoinChangerScalingFactor) + "}");
    return;
  }
  if (hasCoinChangerUnresolvedPayment()) {
    const String rejectionReason =
        coinChangerAwaitingVmcScaled_ > 0
            ? String("coin_credit_awaiting_vmc_acceptance")
            : String("coin_payment_pending");
    emitEvent("payment_rejected",
              String("{\"reason\":\"") + rejectionReason +
                  String("\",\"amount_minor\":") +
                  coinChangerPendingAmountMinor_ +
                  ",\"pending_scaled\":" + coinChangerPendingScaled_ +
                  ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                  ",\"transaction_id\":\"" +
                  escapeForJson(coinChangerPendingTransactionId_) + "\"}");
    return;
  }
  coinChangerPendingAmountMinor_ = amountMinor;
  coinChangerPendingScaled_ = amountMinor / kMdbCoinChangerScalingFactor;
  coinChangerAwaitingVmcAmountMinor_ = 0;
  coinChangerAwaitingVmcScaled_ = 0;
  coinChangerLastCreditReplyTxUs_ = 0;
  coinChangerQueuedAtMs_ = now;
  coinChangerPendingTransactionId_ = transactionId;
  coinChangerAwaitingVmcTransactionId_ = "";
  emitEvent("payment_received",
            String("{\"amount_minor\":") + amountMinor +
                ",\"pending_amount_minor\":0,\"approved_amount_minor\":0,"
                "\"transaction_id\":\"" +
                escapeForJson(transactionId) + "\"}");
  emitEvent("coin_payment_queued",
            String("{\"amount_minor\":") + amountMinor +
                ",\"scaled_amount\":" + coinChangerPendingScaled_ +
                ",\"transaction_id\":\"" +
                escapeForJson(transactionId) + "\"}");
  stateDirty_ = true;
}

// Сохраняет новый платёж как pending.
void MdbService::requestRecordPayment(unsigned long amountMinor,
                                      const String& transactionId) {
  activate();
  const unsigned long now = millis();
  const CashlessSession::Snapshot before = session_.snapshot();
  String reason;
  bool changed = false;
  if (!session_.recordPayment(amountMinor, transactionId, now, reason, changed)) {
    emitEvent("payment_rejected",
              String("{\"reason\":\"") + escapeForJson(reason) + "\"}");
    return;
  }
  if (changed) {
    emitEvent("payment_received",
              String("{\"amount_minor\":") + amountMinor +
                  ",\"pending_amount_minor\":" + session_.snapshot().pendingAmountMinor +
                  ",\"approved_amount_minor\":" +
                  session_.snapshot().approvedAmountMinor +
                  ",\"transaction_id\":\"" +
                  escapeForJson(session_.snapshot().pendingTransactionId) + "\"}");
    stateDirty_ = stateDirty_ || snapshotChanged(before, session_.snapshot());
  } else {
    emitEvent("payment_ignored",
              String("{\"reason\":\"") + escapeForJson(reason) + "\"}");
  }
}

void MdbService::resetCoinChangerProtocolState(bool justResetPending) {
  coinChangerJustResetPending_ = justResetPending;
  coinChangerEnabledMask_ = 0x001F;
  coinChangerManualDispenseMask_ = 0xFFFFU;
  coinChangerFeatureEnableMask_ = 0;
  lastCoinCompatPollObservedUs_ = 0;
  lastCoinCompatPollReplyTxUs_ = 0;
  coinCompatTailIgnoreUntilUs_ = 0;
  coinChangerLastCreditReplyTxUs_ = 0;
}

void MdbService::clearCoinChangerPendingPayment() {
  coinChangerPendingAmountMinor_ = 0;
  coinChangerPendingScaled_ = 0;
  coinChangerAwaitingVmcAmountMinor_ = 0;
  coinChangerAwaitingVmcScaled_ = 0;
  coinChangerLastCreditReplyTxUs_ = 0;
  coinChangerQueuedAtMs_ = 0;
  coinChangerPendingTransactionId_ = "";
  coinChangerAwaitingVmcTransactionId_ = "";
}

bool MdbService::hasCoinChangerUnresolvedPayment() const {
  return coinChangerPendingScaled_ > 0 || coinChangerAwaitingVmcScaled_ > 0;
}

void MdbService::requeueCoinChangerAwaitingAcceptance(const char* reason) {
  if (coinChangerAwaitingVmcScaled_ == 0) {
    return;
  }

  const unsigned long requeuedScaled = coinChangerAwaitingVmcScaled_;
  const unsigned long requeuedAmountMinor = coinChangerAwaitingVmcAmountMinor_;
  const String requeuedTransactionId =
      coinChangerAwaitingVmcTransactionId_.isEmpty()
          ? coinChangerPendingTransactionId_
          : coinChangerAwaitingVmcTransactionId_;
  coinChangerPendingScaled_ += requeuedScaled;
  coinChangerAwaitingVmcAmountMinor_ = 0;
  coinChangerAwaitingVmcScaled_ = 0;
  coinChangerLastCreditReplyTxUs_ = 0;
  coinChangerAwaitingVmcTransactionId_ = "";
  emitEvent("coin_credit_requeued",
            String("{\"reason\":\"") +
                escapeForJson(String(reason == nullptr ? "" : reason)) +
                "\",\"requeued_scaled\":" + requeuedScaled +
                ",\"requeued_amount_minor\":" + requeuedAmountMinor +
                ",\"pending_scaled\":" + coinChangerPendingScaled_ +
                ",\"transaction_id\":\"" +
                escapeForJson(requeuedTransactionId) + "\"}");
  stateDirty_ = true;
}

bool MdbService::shouldIgnoreCoinCompatTail(const machine::Frame& frame,
                                            unsigned long* deltaUs) const {
  if (coinCompatTailIgnoreUntilUs_ == 0 || frame.normalizedLength != 1 ||
      frame.endedAtUs == 0 || lastCoinCompatPollObservedUs_ == 0) {
    return false;
  }

  const uint8_t tailByte = frame.normalized[0];
  if (!isCoinCompatTailByte(tailByte) ||
      frame.endedAtUs < lastCoinCompatPollObservedUs_ ||
      frame.endedAtUs > coinCompatTailIgnoreUntilUs_) {
    return false;
  }

  if (deltaUs != nullptr) {
    *deltaUs = frame.endedAtUs - lastCoinCompatPollObservedUs_;
  }
  return true;
}

void MdbService::resetCashlessRuntimeState(bool justResetPending) {
  isReaderEnabled_ = false;
  beginSessionPending_ = false;
  beginSessionAmountMinor_ = 0;
  beginSessionAwaitingAck_ = false;
  beginSessionTxCount_ = 0;
  beginSessionAckCount_ = 0;
  lastBeginSessionTxUs_ = 0;
  lastBeginSessionAckUs_ = 0;
  lastBeginSessionSentAtMs_ = 0;
  lastBeginSessionStatus_ = "idle";

  cashlessJustResetPending_ = justResetPending;
  cashlessSetupSeen_ = false;
  cashlessSetupMaxMinSeen_ = false;
  cashlessSetupResponsePending_ = false;
  cashlessSetupResponseAwaitingAck_ = false;
  cashlessExpansionSeen_ = false;
  cashlessSetupResponseSentAtMs_ = 0;
  cashlessSetupResponseSentUs_ = 0;
  lastSetupResponseReplyDelayUs_ = 0;
  lastSetupResponseTxUs_ = 0;
  lastSetupRxTsUs_ = 0;
  lastSetupRxEndUs_ = 0;
  lastSetupDecisionTsUs_ = 0;
  lastSetupFrameBuiltTsUs_ = 0;
  lastSetupQueueEnqueueTsUs_ = 0;
  lastSetupTxDoneUs_ = 0;
  lastSetupReleaseUs_ = 0;
  lastSetupDecisionToTxUs_ = 0;
  lastSetupBuildToTxUs_ = 0;
  lastSetupTotalResponseUs_ = 0;
  lastSetupToRepeatUs_ = 0;
  lastSetupResponseChecksum_ = 0;
  lastSetupResponseOptions_ = 0;
  lastSetupResponseResponseTime_ = 0;
  lastSetupFastPathUsed_ = false;
  currentSetupResponseGatewayCompat_ = false;

  gatewayCompatLastSetupResponseUs_ = 0;
  gatewayCompatFollowupActive_ = false;
  gatewayCompatFirstFollowupCaptured_ = false;
  gatewayCompatTotalFramesSeenAtArm_ = 0;
  gatewayCompatBusAliveAfterSetup_ = false;
  gatewayCompatExpectedFollowup_ = "WRAPPER_CONTINUATION_OR_RESET_OR_RETRY";
  gatewayCompatRetryInterpretation_ = "idle";
  gatewayCompatLastOutcome_ = "idle";
  gatewayCompatSemanticSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();

  wrapperFsmState_ = WrapperFsmState::Idle;
  wrapperAckSemanticsMode_ = WrapperAckSemanticsMode::StandardSetupAck;
  wrapperStandardFlowEntered_ = false;
  wrapperAckSemanticsSuspect_ = false;
  wrapperContinuationTimeoutCount_ = 0;
  wrapperExpectedNextRxKind_ = "";
  wrapperExpectedNextAction_ = "";
  wrapperTransitionReason_ = "";
  wrapperContinuationKind_ = "";
  wrapperContinuationRaw9_ = 0;
  wrapperContinuationDeltaUs_ = 0;
  wrapperContinuationInterpretation_ = "";

  setupResponseRejectedByVmc_ = "unknown";
  setupRejectionBasis_ = "";
  lastNakAfterSetupTsUs_ = 0;
  lastNakAfterSetupRaw9_ = 0;
  lastNakAfterSetupDeltaUs_ = 0;
  repeatedSetupCount_ = 0;
  repeatedSetupSamePayloadCount_ = 0;
  repeatedSetupVariantCount_ = 0;
  lastSetupSeenUs_ = 0;
  lastSetupRaw9_ = 0;
  lastSetupSubcommand_ = -1;
  lastSetupVariant_ = "";
  lastSetupHex_ = "";
  lastRepeatedSetupReasonGuess_ = "";
  previousSetupVariant_ = "";
  previousSetupRaw9_ = 0;
  previousSetupTimestampUs_ = 0;
  repeatedSetupInterpretation_ = "";
  setupResponseProfileId_ = gatewayCompatResponseProfileIdLabel();
  setupResponseSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  firstFollowupKindAfterSetup_ = "";
  firstFollowupRaw9AfterSetup_ = 0;
  firstFollowupDeltaUs_ = 0;
  firstFollowupInterpretation_ = "";
  setupNakCausal_ = "unknown";
  setupNakInterpretation_ = "";

  resetSeenCount_ = 0;
  resetAckSentCount_ = 0;
  justResetSentCount_ = 0;
  justResetAcknowledgedCount_ = 0;
  resetAfterSetupRetryCount_ = 0;
  pollMissingAfterResetCount_ = 0;
  lastResetTsUs_ = 0;
  lastResetAckSentUs_ = 0;
  lastResetAckPreparedUs_ = 0;
  lastResetAckDoneUs_ = 0;
  lastResetAckReleaseUs_ = 0;
  lastPollAfterResetTsUs_ = 0;
  lastJustResetSentUs_ = 0;
  lastSetupResponseToResetUs_ = 0;
  lastResetToAckUs_ = 0;
  lastNextRxAfterResetTsUs_ = 0;
  repeatedSetupThenResetObserved_ = false;
  pollMissingAfterResetLogged_ = false;
  lastResetCauseGuess_ = "";
  nextActionHypothesis_ = "await_setup_or_reset";

  clearPendingCashlessSplitPrefix();
  clearObservedRawStatusWindow();
  gatewaySetupCompatStage_ = 0;
  gatewaySetupCompatStartedUs_ = 0;
  gatewaySetupCompatSawExplicitZero_ = false;

  responsePathState_ = ResponsePathState::Idle;
  responseStateChangedAtUs_ = 0;
  lastAcceptedRxFrame_ = {};
  lastResponseDecisionReason_ = "";
  lastResponseDecisionWillRespond_ = false;
  lastTxFrame_ = {};
  lastTxKind_ = "";
  lastTxKindEnum_ = DialogueKind::Unknown;
  lastTxErrorReason_ = "";
  txAttemptCount_ = 0;
  txSuccessCount_ = 0;
  txAbortCount_ = 0;
  txTimeoutCount_ = 0;
  lastTxStartUs_ = 0;
  lastTxDoneUs_ = 0;
  lastTxReleaseUs_ = 0;
  currentTxScope_ = TxScope::None;
  currentTxKind_ = "";
  txFrameCount_ = 0;

  readerState_ = ReaderState::Uninitialized;
  lastRxKind_ = DialogueKind::Unknown;
  pollRxCount_ = 0;
  pollTxCount_ = 0;
  enableRxCount_ = 0;
  enableAppliedCount_ = 0;
  setupRxCount_ = 0;
  setupTxCount_ = 0;
  expansionRxCount_ = 0;
  expansionTxCount_ = 0;
  ackTxCount_ = 0;
  noResponseCount_ = 0;
  stateTransitionCount_ = 0;
  lastRxToTxLatencyUs_ = 0;
  lastNoResponseReason_ = "";
  lastStateTransitionReason_ = "";

  probeRequestPending_ = false;

  for (size_t i = 0; i < kDialogueHistorySize; ++i) {
    dialogueHistory_[i] = {};
  }
  dialogueHistoryNext_ = 0;
  dialogueHistoryCount_ = 0;
}

// Планирует очистку текущей сессии.
void MdbService::requestClearSession() {
  activate();
  clearSessionPending_ = true;
  beginSessionPending_ = false;
  beginSessionAmountMinor_ = 0;
}

// Публикует диагностическую конфигурацию MDB-сервиса.
String MdbService::buildCompactProbeJson(const char* snapshotMode,
                                         const char* trigger,
                                         size_t fullProbeLength,
                                         const String& fullProbeHash,
                                         const char* compactReason) const {
  const bool txPathReady = active_ && phy_.isActive();
  const bool txStateMachineReady =
      responsePathState_ != ResponsePathState::TxAbort &&
      responsePathState_ != ResponsePathState::TxTimeout;
  String json;
  if (!json.reserve(3072)) {
    return String();
  }

  json = "{\"baud_rate\":";
  json += MDB_BAUD_RATE;
  json += ",\"uptime_ms\":";
  json += millis();
  json += ",\"snapshot_mode\":\"";
  json += escapeForJson(snapshotMode == nullptr ? "direct" : String(snapshotMode));
  json += "\",\"trigger\":\"";
  json += escapeForJson(trigger == nullptr ? "mdb_probe" : String(trigger));
  json += "\",\"debug_channel\":\"serial_text_json\"";
  json += ",\"rx_invert\":";
  json += boolToJson(rxInvertEnabled_);
  json += ",\"passive_sniff\":";
  json += boolToJson(passiveSniffEnabled_);
  json += ",\"tx_path_ready\":";
  json += boolToJson(txPathReady);
  json += ",\"tx_gpio_ready\":";
  json += boolToJson(txPathReady);
  json += ",\"tx_state_machine_ready\":";
  json += boolToJson(txStateMachineReady);
  json += ",\"reader_enabled\":";
  json += boolToJson(isReaderEnabled_);
  json += ",\"current_dialogue_phase\":\"";
  json += currentDialoguePhaseLabel();
  json += "\",\"last_reader_state\":\"";
  json += readerStateLabel(readerState_);
  json += "\",\"session_state\":\"";
  json += stateToString(session_.snapshot().state);
  json += "\",\"response_path_state\":\"";
  json += responsePathStateLabel(responsePathState_);
  json += "\",\"last_rx_kind\":\"";
  json += dialogueKindLabel(lastRxKind_);
  json += "\",\"last_tx_kind\":\"";
  json += dialogueKindLabel(lastTxKindEnum_);
  json += "\",\"setup_response_experiment_enabled\":";
  json += boolToJson(setupResponseExperimentEnabled_);
  json += ",\"setup_response_experiment_label\":\"";
  json += escapeForJson(setupResponseExperimentEnabled_ ? setupResponseExperimentLabel_ : String(""));
  json += "\",\"setup_response_experiment_currency_code_bytes_hex\":\"";
  json += escapeForJson(byteToHex(setupResponseExperimentCurrencyCountryCodeHi_) + " " +
                        byteToHex(setupResponseExperimentCurrencyCountryCodeLo_));
  json += "\",\"setup_response_experiment_max_response_time\":";
  json += static_cast<unsigned int>(setupResponseExperimentResponseTime_);
  json += ",\"setup_response_experiment_options\":";
  json += static_cast<unsigned int>(setupResponseExperimentOptions_);
  json += ",\"tx_attempt_count\":";
  json += txAttemptCount_;
  json += ",\"tx_success_count\":";
  json += txSuccessCount_;
  json += ",\"tx_timeout_count\":";
  json += txTimeoutCount_;
  json += ",\"reset_seen_count\":";
  json += resetSeenCount_;
  json += ",\"setup_rx_count\":";
  json += setupRxCount_;
  json += ",\"setup_tx_count\":";
  json += setupTxCount_;
  json += ",\"poll_rx_count\":";
  json += pollRxCount_;
  json += ",\"enable_rx_count\":";
  json += enableRxCount_;
  json += ",\"expected_next_rx_kind\":\"";
  json += escapeForJson(expectedNextRxKindLabel());
  json += "\",\"expected_next_tx_kind\":\"";
  json += escapeForJson(expectedNextTxKindLabel());
  json += "\",\"protocol_progress_blocker\":\"";
  json += escapeForJson(protocolProgressBlockerLabel());
  json += "\",\"gateway_compat_last_outcome\":\"";
  json += escapeForJson(gatewayCompatLastOutcome_);
  json += "\"";
  const String wrapperPhase = gatewayWrapperPhaseLabel();
  json += buildWrapperPhaseAndStateJson(wrapperPhase, wrapperPhase);
  json += ",\"wrapper_expected_next_rx_kind\":\"";
  json += escapeForJson(wrapperExpectedNextRxKindLabel());
  json += "\",\"wrapper_expected_next_action\":\"";
  json += escapeForJson(wrapperExpectedNextActionLabel());
  json += "\",\"wrapper_standard_flow_entered\":";
  json += boolToJson(wrapperStandardFlowEntered_);
  json += ",\"wrapper_transition_reason\":\"";
  json += escapeForJson(wrapperTransitionReason_);
  json += "\"";
  json += ",\"wrapper_continuation_kind\":\"";
  json += escapeForJson(wrapperContinuationKind_);
  json += "\",\"wrapper_continuation_delta_us\":";
  json += wrapperContinuationDeltaUs_;
  json += ",\"wrapper_continuation_interpretation\":\"";
  json += escapeForJson(wrapperContinuationInterpretation_);
  json += "\",\"wrapper_ack_semantics_mode\":\"";
  json += escapeForJson(
      wrapperAckSemanticsModeLabel(wrapperAckSemanticsMode_));
  json += "\",\"wrapper_ack_semantics_suspect\":";
  json += boolToJson(wrapperAckSemanticsSuspect_);
  json += ",\"wrapper_continuation_timeout_count\":";
  json += wrapperContinuationTimeoutCount_;
  json += ",\"probe_compacted\":true";
  json += ",\"probe_compact_reason\":\"";
  json += escapeForJson(compactReason == nullptr ? "oversized_full_probe"
                                                : String(compactReason));
  json += "\",\"probe_chunked\":false";
  json += ",\"probe_chunk_count\":1";
  json += ",\"probe_full_json_length\":";
  json += fullProbeLength;
  json += ",\"probe_full_json_hash\":\"";
  json += escapeForJson(fullProbeHash);
  json += "\"}";
  return json;
}

void MdbService::emitProbeEvent(const char* snapshotMode, const char* trigger) {
  const bool txPathReady = active_ && phy_.isActive();
  const bool txStateMachineReady =
      responsePathState_ != ResponsePathState::TxAbort &&
      responsePathState_ != ResponsePathState::TxTimeout;
  const auto isJsonObject = [](const String& json) -> bool {
    return json.length() >= 2 && json[0] == '{' &&
           json[json.length() - 1] == '}';
  };
  const auto fnv1aHashHex = [](const String& value) -> String {
    uint32_t hash = 2166136261UL;
    for (size_t i = 0; i < value.length(); ++i) {
      hash ^= static_cast<uint8_t>(value[i]);
      hash *= 16777619UL;
    }
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "0x%08lX",
             static_cast<unsigned long>(hash));
    return String(buffer);
  };
  const auto spliceObjectFields = [](const String& json) -> String {
    if (json.length() >= 2 && json[0] == '{' &&
        json[json.length() - 1] == '}') {
      return json.substring(1, json.length() - 1);
    }
    return json;
  };
  const String responseTelemetry =
      spliceObjectFields(buildResponseTelemetryJson());
  const String dialogueTelemetry =
      spliceObjectFields(buildDialogueTelemetryJson());
  constexpr size_t kProbeSafeJsonLengthLimit = 9000U;
  const bool busyImmediatePath =
      snapshotMode != nullptr && strcmp(snapshotMode, "busy_immediate") == 0;
  const bool deferredIdleFlushPath =
      snapshotMode != nullptr &&
      strcmp(snapshotMode, "deferred_idle_flush") == 0;
  const bool waitingForPollAfterReset =
      strcmp(postResetPhaseLabel(), "WAITING_FOR_POLL_AFTER_RESET") == 0;
  if (waitingForPollAfterReset && !pollMissingAfterResetLogged_) {
    pollMissingAfterResetLogged_ = true;
    if (pollMissingAfterResetCount_ < 0xFFFFU) {
      pollMissingAfterResetCount_++;
    }
  }
  const String probeSourcePath =
      snapshotMode == nullptr ? "direct" : String(snapshotMode);
  const bool pendingProbeFlushActive =
      probeRequestPending_ ||
      (trigger != nullptr && strcmp(trigger, "pending_probe_flush") == 0);
  const bool preferCompactProbe =
      kForceCompactProbeDebug || busyImmediatePath || deferredIdleFlushPath || pendingProbeFlushActive;
  const auto buildFullProbeJson = [&]() -> String {
    String json;
    if (!json.reserve(12288)) {
      return String();
    }
    const auto sessionSnapshot = session_.snapshot();
    const unsigned long nowUs = micros();
    json = "{\"baud_rate\":";
    json += MDB_BAUD_RATE;
    json += ",\"uptime_ms\":";
    json += millis();
    json += ",\"snapshot_mode\":\"";
    json += escapeForJson(snapshotMode == nullptr ? "direct" : String(snapshotMode));
    json += "\",\"trigger\":\"";
    json += escapeForJson(trigger == nullptr ? "mdb_probe" : String(trigger));
    json += "\",\"debug_channel\":\"serial_text_json\"";
    json += ",\"transport_websocket_connected\":";
    json += boolToJson(connectionService_.isWebSocketConnected());
    json += ",\"transport_wifi_connected\":";
    json += boolToJson(connectionService_.isWifiConnected());
    json += ",\"rx_pin\":";
    json += MDB_RX_PIN;
    json += ",\"tx_pin\":";
    json += MDB_TX_PIN;
    json += ",\"rx_invert\":";
    json += boolToJson(rxInvertEnabled_);
    json += ",\"passive_sniff\":";
    json += boolToJson(passiveSniffEnabled_);
    json += ",\"expected_address\":";
    json += expectedAddress_;
    json += ",\"cashless_address\":";
    json += static_cast<unsigned int>(cashlessAddress_);
    json += ",\"cashless_base_byte\":";
    json += static_cast<unsigned int>(
        cashlessCommandByte(kCashlessResetCommand));
    json += ",\"cashless_just_reset_pending\":";
    json += boolToJson(cashlessJustResetPending_);
    json += ",\"just_reset_pending\":";
    json += boolToJson(cashlessJustResetPending_);
    json += ",\"post_reset_phase\":\"";
    json += postResetPhaseLabel();
    json += "\"";
    json += ",\"cashless_setup_seen\":";
    json += boolToJson(cashlessSetupSeen_);
    json += ",\"cashless_setup_response_awaiting_ack\":";
    json += boolToJson(cashlessSetupResponseAwaitingAck_);
    json += ",\"cashless_expansion_seen\":";
    json += boolToJson(cashlessExpansionSeen_);
    json += ",\"reader_enabled\":";
    json += boolToJson(isReaderEnabled_);
    json += ",\"session_state\":\"";
    json += stateToString(sessionSnapshot.state);
    json += "\"";
    json += ",\"tx_path_ready\":";
    json += boolToJson(txPathReady);
    json += ",\"tx_gpio_ready\":";
    json += boolToJson(txPathReady);
    json += ",\"tx_state_machine_ready\":";
    json += boolToJson(txStateMachineReady);
    json += ",\"pending_amount_minor\":";
    json += sessionSnapshot.pendingAmountMinor;
    json += ",\"approved_amount_minor\":";
    json += sessionSnapshot.approvedAmountMinor;
    json += ",\"reserved_amount_minor\":";
    json += sessionSnapshot.reservedAmountMinor;
    json += ",\"state\":\"";
    json += stateToString(sessionSnapshot.state);
    json += "\"";
    json += ",\"reset_seen_count\":";
    json += resetSeenCount_;
    json += ",\"reset_ack_sent_count\":";
    json += resetAckSentCount_;
    json += ",\"just_reset_sent_count\":";
    json += justResetSentCount_;
    json += ",\"just_reset_acknowledged_count\":";
    json += justResetAcknowledgedCount_;
    json += ",\"last_reset_ts_us\":";
    json += lastResetTsUs_;
    json += ",\"last_reset_ack_sent_us\":";
    json += lastResetAckSentUs_;
    json += ",\"last_reset_ack_prepare_us\":";
    json += lastResetAckPreparedUs_;
    json += ",\"last_reset_ack_done_us\":";
    json += lastResetAckDoneUs_;
    json += ",\"last_reset_ack_release_us\":";
    json += lastResetAckReleaseUs_;
    json += ",\"last_poll_after_reset_ts_us\":";
    json += lastPollAfterResetTsUs_;
    json += ",\"last_just_reset_sent_us\":";
    json += lastJustResetSentUs_;
    json += ",\"repeated_setup_then_reset_observed\":";
    json += boolToJson(repeatedSetupThenResetObserved_);
    json += ",\"reset_after_setup_retry_count\":";
    json += resetAfterSetupRetryCount_;
    json += ",\"poll_missing_after_reset_count\":";
    json += pollMissingAfterResetCount_;
    json += ",\"last_reset_cause_guess\":\"";
    json += escapeForJson(lastResetCauseGuess_);
    json += "\",\"next_action_hypothesis\":\"";
    json += escapeForJson(nextActionHypothesis_);
    json += "\",\"last_setup_response_to_reset_us\":";
    json += lastSetupResponseToResetUs_;
    json += ",\"last_reset_to_ack_us\":";
    json += lastResetToAckUs_;
    json += ",\"last_next_rx_after_reset_ts_us\":";
    json += lastNextRxAfterResetTsUs_;
    json += ",\"foreign_traffic_causal\":\"";
    json += escapeForJson(foreignTrafficCausalLabel());
    json += "\",\"elapsed_since_reset_ack_us\":";
    json += ((lastResetAckSentUs_ > 0 && nowUs >= lastResetAckSentUs_)
                 ? (nowUs - lastResetAckSentUs_)
                 : 0);
    json += ",";
    json += responseTelemetry;
    json += ",";
    json += dialogueTelemetry;
    json += "}";
    return json;
  };

  String details;
  if (!preferCompactProbe) {
    details = buildFullProbeJson();
  }
  const size_t probeJsonLength = details.length();
  const bool probeJsonLooksValid = isJsonObject(details);
  const String probeJsonHash =
      probeJsonLooksValid ? fnv1aHashHex(details) : String("0x00000000");
  const size_t probeQueueDepth = connectionService_.outboxDepth();
  const size_t probeQueueCapacity = connectionService_.outboxCapacity();
  const String probeSendTransport = kForceCompactProbeDebug
                                        ? String("serial_text_json_probe_only")
                                        : (connectionService_.isWebSocketConnected()
                                               ? String("serial_text_json_with_ws_optional")
                                               : String("serial_text_json_only"));
  bool probeCompacted = preferCompactProbe ||
                        probeJsonLength > kProbeSafeJsonLengthLimit;
  uint8_t probeSendRetryCount = 0;
  String probeCompactReason;
  if (kForceCompactProbeDebug) {
    probeCompactReason = "forced_compact_probe";
  } else if (busyImmediatePath) {
    probeCompactReason = "busy_probe_prefers_compact";
  } else if (deferredIdleFlushPath || pendingProbeFlushActive) {
    probeCompactReason = "pending_probe_flush_prefers_compact";
  } else if (probeCompacted) {
    probeCompactReason = "full_probe_exceeds_safe_size_limit";
  }
  String probeBuildMode = "full";
  if (kForceCompactProbeDebug) {
    probeBuildMode = "compact_forced";
  } else if (busyImmediatePath) {
    probeBuildMode = "compact_preferred_busy_path";
  } else if (deferredIdleFlushPath || pendingProbeFlushActive) {
    probeBuildMode = "compact_preferred_deferred_path";
  } else if (probeCompacted) {
    probeBuildMode = "compact_fallback";
  }
  String probeBuildStage = probeCompacted ? "compact_probe_build"
                                          : "full_probe_build";
  bool probeBuildSuccess = preferCompactProbe ? true : probeJsonLooksValid;
  String probeBuildFailureReason;
  String probePayload = details;
  String probePayloadHash = probeJsonHash;
  size_t probePayloadLength = probeJsonLength;

  if (!preferCompactProbe && !probeJsonLooksValid) {
    probeBuildFailureReason =
        details.isEmpty() ? "full_probe_build_empty" : "full_probe_build_invalid";
    probeBuildMode = "compact_fallback";
    probeBuildStage = "compact_probe_build";
    probeCompacted = true;
    if (probeCompactReason.isEmpty()) {
      probeCompactReason = probeBuildFailureReason;
    }
  }

  if (probeCompacted) {
    probePayload = buildCompactProbeJson(snapshotMode, trigger, probeJsonLength,
                                         probeJsonHash, probeCompactReason.c_str());
    probePayloadHash = fnv1aHashHex(probePayload);
    probePayloadLength = probePayload.length();
    if (!isJsonObject(probePayload)) {
      probeBuildSuccess = false;
      if (probeBuildFailureReason.isEmpty()) {
        probeBuildFailureReason = probePayload.isEmpty()
                                      ? "compact_probe_build_empty"
                                      : "compact_probe_build_invalid";
      }
    } else {
      probeBuildSuccess = true;
    }
  }

  emitEvent("probe_built",
            String("{\"snapshot_mode\":\"") +
                escapeForJson(probeSourcePath) +
                "\",\"trigger\":\"" +
                escapeForJson(trigger == nullptr ? "mdb_probe"
                                                : String(trigger)) +
                "\",\"response_path_state\":\"" +
                responsePathStateLabel(responsePathState_) +
                "\",\"reader_state\":\"" + readerStateLabel(readerState_) +
                "\",\"probe_source_path\":\"" +
                escapeForJson(probeSourcePath) +
                "\",\"pending_probe_flush_active\":" +
                boolToJson(pendingProbeFlushActive) +
                ",\"probe_build_mode\":\"" +
                escapeForJson(probeBuildMode) +
                "\",\"probe_build_stage\":\"" +
                escapeForJson(probeBuildStage) +
                "\",\"probe_build_success\":" +
                boolToJson(probeBuildSuccess) +
                ",\"probe_build_failure_reason\":\"" +
                escapeForJson(probeBuildFailureReason) +
                "\",\"probe_json_length\":" + probePayloadLength +
                ",\"probe_full_json_length\":" + probeJsonLength +
                ",\"probe_compacted\":" + boolToJson(probeCompacted) + "}");

  if (!probeBuildSuccess) {
    emitEvent("probe_build_failed",
              String("{\"reason\":\"probe_build_failed\",\"probe_source_path\":\"") +
                  escapeForJson(probeSourcePath) +
                  "\",\"pending_probe_flush_active\":" +
                  boolToJson(pendingProbeFlushActive) +
                  ",\"probe_build_mode\":\"" +
                  escapeForJson(probeBuildMode) +
                  "\",\"probe_build_stage\":\"" +
                  escapeForJson(probeBuildStage) +
                  "\",\"probe_build_failure_reason\":\"" +
                  escapeForJson(probeBuildFailureReason) +
                  "\",\"serialized_length\":" + probePayloadLength +
                  ",\"probe_full_json_length\":" + probeJsonLength +
                  ",\"probe_send_transport\":\"" +
                  escapeForJson(probeSendTransport) + "\"}");
    emitEvent("probe_error",
              String("{\"reason\":\"probe_build_failed\",\"probe_source_path\":\"") +
                  escapeForJson(probeSourcePath) +
                  "\",\"pending_probe_flush_active\":" +
                  boolToJson(pendingProbeFlushActive) +
                  ",\"serialized_length\":" + probePayloadLength +
                  ",\"probe_full_json_length\":" + probeJsonLength +
                  ",\"queue_result\":\"not_attempted\",\"probe_send_drop_reason\":\"" +
                  escapeForJson(probeBuildFailureReason) +
                  "\",\"probe_build_mode\":\"" +
                  escapeForJson(probeBuildMode) +
                  "\",\"probe_build_stage\":\"" +
                  escapeForJson(probeBuildStage) + "\"}");
    emitEvent("probe_emit_skipped",
              String("{\"reason\":\"probe_build_failed\",\"probe_source_path\":\"") +
                  escapeForJson(probeSourcePath) +
                  "\",\"probe_emit_skipped_reason\":\"" +
                  escapeForJson(probeBuildFailureReason) + "\"}");
    return;
  }

  emitEvent("probe_send_started",
            String("{\"snapshot_mode\":\"") +
                escapeForJson(probeSourcePath) +
                "\",\"trigger\":\"" +
                escapeForJson(trigger == nullptr ? "mdb_probe"
                                                : String(trigger)) +
                "\",\"probe_source_path\":\"" +
                escapeForJson(probeSourcePath) +
                "\",\"pending_probe_flush_active\":" +
                boolToJson(pendingProbeFlushActive) +
                ",\"probe_build_mode\":\"" +
                escapeForJson(probeBuildMode) +
                "\",\"probe_build_stage\":\"" +
                escapeForJson(probeBuildStage) +
                "\",\"probe_build_success\":true" +
                ",\"probe_build_failure_reason\":\"" +
                escapeForJson(probeBuildFailureReason) +
                "\",\"probe_json_length\":" + probePayloadLength +
                ",\"probe_json_hash\":\"" +
                escapeForJson(probePayloadHash) +
                "\",\"probe_full_json_length\":" + probeJsonLength +
                ",\"probe_full_json_hash\":\"" +
                escapeForJson(probeJsonHash) +
                "\",\"probe_json_valid\":true" +
                ",\"probe_send_transport\":\"" +
                escapeForJson(probeSendTransport) +
                "\",\"probe_send_queue_depth\":" + probeQueueDepth +
                ",\"probe_send_queue_capacity\":" + probeQueueCapacity +
                ",\"probe_send_size_limit\":" + kProbeSafeJsonLengthLimit +
                ",\"probe_compacted\":" + boolToJson(probeCompacted) +
                ",\"probe_compact_reason\":\"" +
                escapeForJson(probeCompactReason) +
                "\",\"probe_chunked\":false,\"probe_chunk_count\":1,"
                "\"probe_send_retry_count\":0}");

  String probeQueueResult;
  String probeFailureReason;
  bool probeQueued =
      emitEvent("probe", probePayload, &probeQueueResult, &probeFailureReason);
  if (!probeQueued && !probeCompacted) {
    probeSendRetryCount = 1;
    probeCompacted = true;
    probeBuildMode = "compact_retry_fallback";
    probeBuildStage = "compact_probe_build_after_send_failure";
    probeCompactReason = String("full_probe_emit_failed_") + probeFailureReason;
    probePayload = buildCompactProbeJson(snapshotMode, trigger, probeJsonLength,
                                         probeJsonHash, probeCompactReason.c_str());
    probePayloadHash = fnv1aHashHex(probePayload);
    probePayloadLength = probePayload.length();
    if (!isJsonObject(probePayload)) {
      probeBuildFailureReason = probePayload.isEmpty()
                                    ? "compact_probe_build_empty_after_send_failure"
                                    : "compact_probe_build_invalid_after_send_failure";
      emitEvent("probe_build_failed",
                String("{\"reason\":\"probe_build_failed\",\"probe_source_path\":\"") +
                    escapeForJson(probeSourcePath) +
                    "\",\"pending_probe_flush_active\":" +
                    boolToJson(pendingProbeFlushActive) +
                    ",\"probe_build_mode\":\"" +
                    escapeForJson(probeBuildMode) +
                    "\",\"probe_build_stage\":\"" +
                    escapeForJson(probeBuildStage) +
                    "\",\"probe_build_failure_reason\":\"" +
                    escapeForJson(probeBuildFailureReason) +
                    "\",\"serialized_length\":" + probePayloadLength +
                    ",\"probe_full_json_length\":" + probeJsonLength +
                    ",\"probe_send_transport\":\"" +
                    escapeForJson(probeSendTransport) + "\"}");
      emitEvent("probe_error",
                String("{\"reason\":\"probe_build_failed\",\"probe_source_path\":\"") +
                    escapeForJson(probeSourcePath) +
                    "\",\"pending_probe_flush_active\":" +
                    boolToJson(pendingProbeFlushActive) +
                    ",\"serialized_length\":" + probePayloadLength +
                    ",\"probe_full_json_length\":" + probeJsonLength +
                    ",\"queue_result\":\"not_attempted\",\"probe_send_drop_reason\":\"" +
                    escapeForJson(probeBuildFailureReason) +
                    "\",\"probe_build_mode\":\"" +
                    escapeForJson(probeBuildMode) +
                    "\",\"probe_build_stage\":\"" +
                    escapeForJson(probeBuildStage) + "\"}");
      emitEvent("probe_emit_skipped",
                String("{\"reason\":\"probe_build_failed\",\"probe_source_path\":\"") +
                    escapeForJson(probeSourcePath) +
                    "\",\"probe_emit_skipped_reason\":\"" +
                    escapeForJson(probeBuildFailureReason) + "\"}");
      return;
    }
    probeQueueResult = "not_sent";
    probeFailureReason = "";
    probeQueued =
        emitEvent("probe", probePayload, &probeQueueResult, &probeFailureReason);
  }
  if (!probeQueued) {
    const String dropReason =
        probeFailureReason.isEmpty() ? "probe_emit_failed" : probeFailureReason;
    emitEvent("probe_send_failed",
              String("{\"reason\":\"probe_emit_failed\",\"probe_source_path\":\"") +
                  escapeForJson(probeSourcePath) +
                  "\",\"pending_probe_flush_active\":" +
                  boolToJson(pendingProbeFlushActive) +
                  ",\"probe_build_mode\":\"" +
                  escapeForJson(probeBuildMode) +
                  "\",\"probe_build_stage\":\"" +
                  escapeForJson(probeBuildStage) +
                  "\",\"probe_build_success\":true" +
                  ",\"probe_json_length\":" +
                  probeJsonLength + ",\"probe_json_hash\":\"" +
                  escapeForJson(probeJsonHash) + "\",\"queue_result\":\"" +
                  escapeForJson(probeQueueResult) +
                  "\",\"probe_send_transport\":\"" +
                  escapeForJson(probeSendTransport) +
                  "\",\"probe_send_queue_depth\":" + probeQueueDepth +
                  ",\"probe_send_queue_capacity\":" + probeQueueCapacity +
                  ",\"probe_send_size_limit\":" + kProbeSafeJsonLengthLimit +
                  ",\"probe_send_drop_reason\":\"" +
                  escapeForJson(dropReason) +
                  "\",\"probe_send_retry_count\":" + probeSendRetryCount +
                  ",\"probe_compacted\":" + boolToJson(probeCompacted) +
                  ",\"probe_compact_reason\":\"" +
                  escapeForJson(probeCompactReason) + "\"}");
    emitEvent("probe_error",
              String("{\"reason\":\"probe_emit_failed\",\"probe_source_path\":\"") +
                  escapeForJson(probeSourcePath) +
                  "\",\"pending_probe_flush_active\":" +
                  boolToJson(pendingProbeFlushActive) +
                  ",\"serialized_length\":" +
                  probePayloadLength + ",\"probe_json_hash\":\"" +
                  escapeForJson(probePayloadHash) + "\",\"queue_result\":\"" +
                  escapeForJson(probeQueueResult) +
                  "\",\"probe_send_drop_reason\":\"" +
                  escapeForJson(dropReason) +
                  "\",\"probe_compacted\":" + boolToJson(probeCompacted) +
                  ",\"probe_compact_reason\":\"" +
                  escapeForJson(probeCompactReason) + "\"}");
    emitEvent("probe_emit_skipped",
              String("{\"reason\":\"probe_emit_failed\",\"probe_source_path\":\"") +
                  escapeForJson(probeSourcePath) +
                  "\",\"queue_result\":\"" +
                  escapeForJson(probeQueueResult) +
                  "\",\"probe_emit_skipped_reason\":\"" +
                  escapeForJson(dropReason) + "\"}");
    return;
  }

  emitEvent("probe_send_completed",
            String("{\"snapshot_mode\":\"") +
                escapeForJson(probeSourcePath) +
                "\",\"trigger\":\"" +
                escapeForJson(trigger == nullptr ? "mdb_probe"
                                                : String(trigger)) +
                "\",\"probe_source_path\":\"" +
                escapeForJson(probeSourcePath) +
                "\",\"pending_probe_flush_active\":" +
                boolToJson(pendingProbeFlushActive) +
                ",\"probe_build_mode\":\"" +
                escapeForJson(probeBuildMode) +
                "\",\"probe_build_stage\":\"" +
                escapeForJson(probeBuildStage) +
                "\",\"probe_build_success\":true" +
                ",\"probe_build_failure_reason\":\"" +
                escapeForJson(probeBuildFailureReason) +
                "\",\"probe_json_length\":" + probePayloadLength +
                ",\"probe_json_hash\":\"" +
                escapeForJson(probePayloadHash) +
                "\",\"probe_full_json_length\":" + probeJsonLength +
                ",\"probe_full_json_hash\":\"" +
                escapeForJson(probeJsonHash) +
                "\",\"queue_result\":\"" +
                escapeForJson(probeQueueResult) +
                "\",\"probe_send_transport\":\"" +
                escapeForJson(probeSendTransport) +
                "\",\"probe_send_queue_depth\":" + probeQueueDepth +
                ",\"probe_send_queue_capacity\":" + probeQueueCapacity +
                ",\"probe_send_size_limit\":" + kProbeSafeJsonLengthLimit +
                ",\"probe_send_retry_count\":" + probeSendRetryCount +
                ",\"probe_compacted\":" + boolToJson(probeCompacted) +
                ",\"probe_compact_reason\":\"" +
                escapeForJson(probeCompactReason) +
                "\",\"probe_chunked\":false,\"probe_chunk_count\":1,"
                "\"probe_send_drop_reason\":\"\"}");
  if (waitingForPollAfterReset) {
    const unsigned long pollMissingTsUs = micros();
    const unsigned long elapsedSinceResetAckUs =
        (lastResetAckSentUs_ > 0 && pollMissingTsUs >= lastResetAckSentUs_)
            ? (pollMissingTsUs - lastResetAckSentUs_)
            : 0;
    emitEvent("poll_missing_after_reset",
              String("{\"timestamp_us\":") + pollMissingTsUs +
                  ",\"elapsed_us_since_reset_ack\":" +
                  elapsedSinceResetAckUs +
                  ",\"repeated_setup_then_reset_observed\":" +
                  boolToJson(repeatedSetupThenResetObserved_) +
                  ",\"reset_after_setup_retry_count\":" +
                  resetAfterSetupRetryCount_ +
                  ",\"last_reset_cause_guess\":\"" +
                  escapeForJson(lastResetCauseGuess_) +
                  "\",\"next_action_hypothesis\":\"" +
                  escapeForJson(nextActionHypothesis_) + "\"" +
                  ",\"reader_state\":\"" + readerStateLabel(readerState_) +
                  "\"}");
    emitSetupResponseRejectionAudit(
        "poll_missing_after_reset", pollMissingTsUs, nullptr,
        "poll_missing_after_reset",
        String("\"elapsed_us_since_reset_ack\":") + elapsedSinceResetAckUs +
            ",\"next_action_hypothesis\":\"" +
            escapeForJson(nextActionHypothesis_) + "\"");
  }
  emitEvent("probe_emitted",
            String("{\"snapshot_mode\":\"") +
                escapeForJson(probeSourcePath) +
                "\",\"trigger\":\"" +
                escapeForJson(trigger == nullptr ? "mdb_probe"
                                                : String(trigger)) +
                "\",\"probe_source_path\":\"" +
                escapeForJson(probeSourcePath) +
                "\",\"pending_probe_flush_active\":" +
                boolToJson(pendingProbeFlushActive) +
                ",\"probe_build_mode\":\"" +
                escapeForJson(probeBuildMode) +
                "\",\"probe_build_stage\":\"" +
                escapeForJson(probeBuildStage) +
                "\",\"probe_build_success\":true" +
                ",\"probe_build_failure_reason\":\"" +
                escapeForJson(probeBuildFailureReason) +
                "\",\"probe_json_length\":" + probePayloadLength +
                ",\"probe_json_hash\":\"" +
                escapeForJson(probePayloadHash) +
                "\",\"probe_full_json_length\":" + probeJsonLength +
                ",\"probe_full_json_hash\":\"" +
                escapeForJson(probeJsonHash) +
                "\",\"queue_result\":\"" +
                escapeForJson(probeQueueResult) +
                "\",\"probe_send_transport\":\"" +
                escapeForJson(probeSendTransport) +
                "\",\"probe_send_queue_depth\":" + probeQueueDepth +
                ",\"probe_send_queue_capacity\":" + probeQueueCapacity +
                ",\"probe_send_size_limit\":" + kProbeSafeJsonLengthLimit +
                ",\"probe_send_retry_count\":" + probeSendRetryCount +
                ",\"probe_compacted\":" + boolToJson(probeCompacted) +
                ",\"probe_compact_reason\":\"" +
                escapeForJson(probeCompactReason) +
                "\",\"probe_chunked\":false,\"probe_chunk_count\":1,"
                "\"probe_send_drop_reason\":\"\","
                "\"response_path_state\":\"" +
                responsePathStateLabel(responsePathState_) + "\"}");
}

// Публикует диагностическую конфигурацию MDB-сервиса.
void MdbService::requestProbe() {
  activate();
  const unsigned long nowUs = micros();
  emitEvent("command_ack",
            String("{\"command\":\"mdb_probe\",\"accepted\":true,"
                   "\"timestamp_us\":") +
                nowUs + ",\"response_path_state\":\"" +
                responsePathStateLabel(responsePathState_) + "\"}");
  emitEvent("probe_requested",
            String("{\"timestamp_us\":") + nowUs +
                ",\"response_path_state\":\"" +
                responsePathStateLabel(responsePathState_) +
                "\",\"reader_state\":\"" + readerStateLabel(readerState_) +
                "\"}");
  if (responsePathState_ != ResponsePathState::Idle) {
    probeRequestPending_ = true;
    emitEvent("probe_deferred",
              String("{\"timestamp_us\":") + nowUs +
                  ",\"reason\":\"response_path_busy\",\"response_path_state\":\"" +
                  responsePathStateLabel(responsePathState_) +
                  "\",\"will_emit_after_idle\":true}");
    emitProbeEvent("busy_immediate", "mdb_probe");
    return;
  }
  emitProbeEvent("idle_immediate", "mdb_probe");
}

void MdbService::emitDebugTransportReadyIfNeeded(unsigned long nowMs) {
  if (debugTransportReadyEmitted_) {
    return;
  }
  if (connectionService_.deviceId().isEmpty()) {
    return;
  }
  debugTransportReadyEmitted_ = true;
  emitEvent("debug_transport_ready",
            String("{\"device_id\":\"") + connectionService_.deviceId() +
                "\",\"uptime_ms\":" + nowMs +
                ",\"transport_mode\":\"usb_serial_json_text\",\"uart_id\":0"
                ",\"serial_baud\":115200,\"debug_channel\":\"serial_text_json\","
                "\"binary_debug_output\":false,\"websocket_connected\":" +
                boolToJson(connectionService_.isWebSocketConnected()) +
                ",\"wifi_connected\":" +
                boolToJson(connectionService_.isWifiConnected()) +
                ",\"response_path_state\":\"" +
                responsePathStateLabel(responsePathState_) +
                "\",\"reader_state\":\"" +
                readerStateLabel(readerState_) + "\"}");
}

// Отправляет тестовый кадр в линию автомата.
void MdbService::requestProbeTx() {
  activate();
  const uint8_t frame[] = {cashlessCommandByte(kCashlessResetCommand), mdb::kAck};
  transmitDebugFrame(TxScope::DebugCommand, "probe_tx", frame, sizeof(frame));
  lastProbeTxAt_ = millis();
  rxFramesAfterProbeTx_ = 0;
  emitEvent("probe_tx",
            String("{\"hex\":\"") + bytesToHex(frame, sizeof(frame)) + "\"}");
}

// Выполняет грубый pulse-тест TX-линии.
void MdbService::requestPulseTest() {
  activate();
  phy_.pulseTest(MDB_TX_PIN);
  emitEvent("pulse_test", String("{\"tx_pin\":") + MDB_TX_PIN + "}");
}

void MdbService::requestHoldTxLowTest() {
  activate();
  constexpr unsigned long kHoldMs = 2000;
  phy_.holdActiveTest(MDB_TX_PIN, kHoldMs);
  emitEvent("tx_hold_low_test",
            String("{\"tx_pin\":") + MDB_TX_PIN + ",\"hold_ms\":" +
                kHoldMs + "}");
}

void MdbService::requestIrqSnapshot() {
  const uint32_t rawGpioInterruptCount = phy_.rawGpioInterruptCount();
  unsigned long tsUs[MachinePhy::kRecentRxInterrupts] = {};
  uint8_t levels[MachinePhy::kRecentRxInterrupts] = {};
  const size_t count =
      phy_.copyRecentRxInterrupts(tsUs, levels, MachinePhy::kRecentRxInterrupts);
  const unsigned long lastInterruptTsUs = count > 0 ? tsUs[count - 1] : 0;
  const unsigned long deltaUs =
      count >= 2 && tsUs[count - 1] >= tsUs[count - 2] ? (tsUs[count - 1] - tsUs[count - 2]) : 0;
  String json = String("{\"rx_pin\":") + MDB_RX_PIN +
                ",\"rx_invert\":" + boolToJson(rxInvertEnabled_) +
                ",\"current_rx_level\":" + phy_.currentRxLevel() +
                ",\"raw_gpio_interrupt_count\":" + rawGpioInterruptCount +
                ",\"last_interrupt_ts_us\":" + lastInterruptTsUs +
                ",\"delta_us\":" + deltaUs + ",\"recent_interrupts\":[";
  for (size_t i = 0; i < count; ++i) {
    if (i > 0) {
      json += ",";
    }
    json += String("{\"ts_us\":") + tsUs[i] + ",\"level\":" + levels[i] + "}";
  }
  json += "]}";
  emitEvent("irq_snapshot", json);
}

void MdbService::requestPhyDecoderStatus() {
  MachinePhy::SoftwareDecoderPathState pathStates[MachinePhy::kSoftwareDecoderPaths] = {};
  const size_t pathCount = phy_.copySoftwareDecoderPathStates(
      pathStates, MachinePhy::kSoftwareDecoderPaths);
  MachinePhy::CapturedSymbol symbols[8] = {};
  const size_t symbolCount = phy_.copyCapturedSymbols(symbols, 8);
  const MachinePhy::DecoderStats decoderStats = phy_.mdb_decoder_get_stats();
  String lastGoodRaw9Hex = String(decoderStats.lastGoodFrame.raw9, HEX);
  lastGoodRaw9Hex.toUpperCase();
  String currentTraceRaw9Hex = String(decoderStats.currentCandidateTrace.raw9, HEX);
  currentTraceRaw9Hex.toUpperCase();
  String lastBadTraceRaw9Hex = String(decoderStats.lastBadTrace.raw9, HEX);
  lastBadTraceRaw9Hex.toUpperCase();

  String json = String("{\"rx_pin\":") + MDB_RX_PIN +
                ",\"rx_invert\":" + boolToJson(rxInvertEnabled_) +
                ",\"current_rx_level\":" + phy_.currentRxLevel() +
                ",\"raw_gpio_interrupt_count\":" +
                phy_.rawGpioInterruptCount() +
                ",\"active_decoder_mode\":" +
                phy_.activeSoftwareDecoderMode() +
                ",\"soft_last_edge_delta_us\":" +
                phy_.softwareDecoderLastDeltaUs() +
                ",\"phy_loop_counter\":" + creditFlowPhyLoopCounter_ +
                ",\"framing_error_count\":" +
                decoderStats.framingErrorCount +
                ",\"polarity_mismatch_count\":" +
                decoderStats.polarityMismatchCount +
                ",\"resync_count\":" + decoderStats.resyncCount +
                ",\"ring_overflow_count\":" +
                decoderStats.ringOverflowCount +
                ",\"last_bad_reason\":\"" +
                String(decoderBadReasonLabel(decoderStats.lastBadReason)) +
                "\",\"last_good_frame\":{\"valid\":" +
                boolToJson(decoderStats.lastGoodFrame.valid) +
                ",\"data_byte\":" + decoderStats.lastGoodFrame.dataByte +
                ",\"data_byte_hex\":\"" +
                byteToHex(decoderStats.lastGoodFrame.dataByte) +
                "\",\"ninth_bit\":" +
                boolToJson(decoderStats.lastGoodFrame.ninthBit) +
                ",\"raw9\":" + decoderStats.lastGoodFrame.raw9 +
                ",\"raw9_hex\":\"" +
                lastGoodRaw9Hex +
                "\",\"stop_ok\":" +
                boolToJson(decoderStats.lastGoodFrame.stopOk) +
                ",\"timestamp_us\":" +
                decoderStats.lastGoodFrame.timestampUs + "}";
  const auto appendTraceJson =
      [&](const char* fieldName, const MachinePhy::DecoderFrameTrace& trace,
          const String& raw9Hex) {
        json += ",\"";
        json += fieldName;
        json += "\":{\"valid\":";
        json += boolToJson(trace.valid);
        json += ",\"trace_generation_id\":";
        json += trace.traceGenerationId;
        json += ",\"candidate_start_ts\":";
        json += trace.candidateStartTsUs;
        json += ",\"frame_window_start_us\":";
        json += trace.frameWindowStartUs;
        json += ",\"frame_window_end_us\":";
        json += trace.frameWindowEndUs;
        json += ",\"trace_updated_ts\":";
        json += trace.traceUpdatedTsUs;
        json += ",\"candidate_finalize_ts\":";
        json += trace.candidateFinalizeTsUs;
        json += ",\"latest_edge_ts_seen_when_finalized\":";
        json += trace.latestEdgeTsSeenWhenFinalized;
        json += ",\"first_ring_index\":";
        json += trace.firstRingIndex;
        json += ",\"last_ring_index\":";
        json += trace.lastRingIndex;
        json += ",\"ring_write_index_at_candidate_create\":";
        json += trace.ringWriteIndexAtCandidateCreate;
        json += ",\"ring_write_index_at_frame_finalize\":";
        json += trace.ringWriteIndexAtFrameFinalize;
        json += ",\"initial_level_before_start\":";
        json += trace.initialLevelBeforeStart;
        json += ",\"sampled_start\":";
        json += trace.sampledStart;
        json += ",\"sampled_data_byte\":";
        json += trace.sampledDataByte;
        json += ",\"sampled_data_byte_hex\":\"";
        json += byteToHex(trace.sampledDataByte);
        json += "\",\"sampled_mode_bit\":";
        json += boolToJson(trace.sampledModeBit);
        json += ",\"sampled_stop_bit\":";
        json += trace.sampledStopBit;
        json += ",\"raw9\":";
        json += trace.raw9;
        json += ",\"raw9_hex\":\"";
        json += raw9Hex;
        json += "\",\"bad_reason\":\"";
        json += decoderBadReasonLabel(trace.badReason);
        json += "\",\"phase_error_us\":";
        json += trace.phaseErrorUs;
        json += ",\"idle_duration_before_start_us\":";
        json += trace.idleDurationBeforeStartUs;
        json += ",\"edge_count_used_for_frame\":";
        json += trace.edgeCountUsedForFrame;
        json += ",\"edge_count_stored\":";
        json += trace.edgeCountStored;
        json += ",\"scanned_edge_count\":";
        json += trace.scannedEdgeCount;
        json += ",\"accepted_edge_count\":";
        json += trace.acceptedEdgeCount;
        json += ",\"rejected_edge_count\":";
        json += trace.rejectedEdgeCount;
        json += ",\"collected_edge_count_total\":";
        json += trace.collectedEdgeCountTotal;
        json += ",\"collected_edge_count_in_window\":";
        json += trace.collectedEdgeCountInWindow;
        json += ",\"reject_before_window_count\":";
        json += trace.rejectBeforeWindowCount;
        json += ",\"reject_after_window_count\":";
        json += trace.rejectAfterWindowCount;
        json += ",\"reject_duplicate_count\":";
        json += trace.rejectDuplicateCount;
        json += ",\"reject_too_close_count\":";
        json += trace.rejectTooCloseCount;
        json += ",\"reject_overwritten_count\":";
        json += trace.rejectOverwrittenCount;
        json += ",\"finalized_with_live_ring_tail\":";
        json += boolToJson(trace.finalizedWithLiveRingTail);
        json += ",\"scan_stop_reason\":\"";
        json += decoderTraceScanStopReasonLabel(trace.scanStopReason);
        json += "\"";
        json += ",\"sampled_bits\":[";
        for (size_t i = 0; i < MachinePhy::kDecoderSampleCount; ++i) {
          if (i > 0) {
            json += ",";
          }
          json += trace.sampledBits[i];
        }
        json += "],\"sample_timestamps_us\":[";
        for (size_t i = 0; i < MachinePhy::kDecoderSampleCount; ++i) {
          if (i > 0) {
            json += ",";
          }
          json += trace.sampleTimestampsUs[i];
        }
        json += "],\"edge_list\":[";
        for (size_t i = 0; i < trace.edgeCountStored; ++i) {
          if (i > 0) {
            json += ",";
          }
          json += String("{\"ts_us\":") + trace.edges[i].tsUs +
                  ",\"ring_index\":" + trace.edges[i].ringIndex +
                  ",\"level\":" + trace.edges[i].level +
                  ",\"decision\":\"" +
                  String(decoderTraceEdgeDecisionLabel(trace.edges[i].decision)) +
                  "\"}";
        }
        json += "]}";
      };
  appendTraceJson("current_candidate_trace", decoderStats.currentCandidateTrace,
                  currentTraceRaw9Hex);
  appendTraceJson("last_bad_trace", decoderStats.lastBadTrace,
                  lastBadTraceRaw9Hex);
  appendTraceJson("debug_frame_trace", decoderStats.lastBadTrace,
                  lastBadTraceRaw9Hex);
  json += ",\"decoder_paths\":[";
  for (size_t i = 0; i < pathCount; ++i) {
    if (i > 0) {
      json += ",";
    }
    json += String("{\"path_index\":") + i +
            ",\"path\":\"" + String(decoderPathLabel(i)) +
            "\",\"framing\":" + boolToJson(pathStates[i].framing) +
            ",\"bit_pos\":" + pathStates[i].bitPos +
            ",\"last_value\":" + pathStates[i].lastValue +
            ",\"last_value_hex\":\"" + byteToHex(pathStates[i].lastValue) +
            "\",\"bit_buffer_lsb_first\":\"" +
            byteBitsLsbFirst(pathStates[i].lastValue, 8) +
            "\",\"bit_buffer_msb_view\":\"" +
            byteBitsMsbView(pathStates[i].lastValue, 8) +
            "\",\"ninth_bit\":" + boolToJson(pathStates[i].ninthBit) +
            ",\"reset_reason\":" + pathStates[i].resetReason +
            ",\"last_activity_us\":" + pathStates[i].lastActivityUs + "}";
  }
  json += "],\"decoder_modes\":[";
  for (uint8_t mode = 0; mode < MachinePhy::kSoftwareDecoderModes; ++mode) {
    if (mode > 0) {
      json += ",";
    }
    const uint8_t best10 = decoderModeBestDistanceTo10_[mode];
    const uint8_t best08 = decoderModeBestDistanceTo08_[mode];
    json += String("{\"mode\":") + mode +
            ",\"trace_count\":" + decoderModeTraceCount_[mode] +
            ",\"byte_count\":" + decoderModeByteCount_[mode] +
            ",\"last_partial\":" + decoderModeLastPartial_[mode] +
            ",\"last_partial_hex\":\"" +
            byteToHex(decoderModeLastPartial_[mode]) +
            "\",\"last_byte\":" + decoderModeLastByte_[mode] +
            ",\"last_byte_hex\":\"" +
            byteToHex(decoderModeLastByte_[mode]) +
            "\",\"best_byte\":" + decoderModeBestByte_[mode] +
            ",\"best_byte_hex\":\"" +
            byteToHex(decoderModeBestByte_[mode]) +
            "\",\"best_distance_to_0x10\":" +
            (best10 == 0xFF ? -1 : static_cast<int>(best10)) +
            ",\"best_distance_to_0x08\":" +
            (best08 == 0xFF ? -1 : static_cast<int>(best08)) +
            ",\"last_path\":\"" +
            String(decoderPathLabel(decoderModeLastPath_[mode])) + "\"}";
  }
  json += "],\"captured_symbols\":[";
  for (size_t i = 0; i < symbolCount; ++i) {
    if (i > 0) {
      json += ",";
    }
    String rawBitsHex = String(symbols[i].data, HEX);
    rawBitsHex.toUpperCase();
    json += String("{\"raw_bits\":") + symbols[i].data +
            ",\"raw_bits_hex\":\"" + rawBitsHex +
            "\",\"timestamp_us\":" + symbols[i].timestampUs + "}";
  }
  json += "]}";
  emitEvent("phy_decoder_status", json);
}

void MdbService::initiateBeginSession(uint16_t amountMinor) {
  activate();
  beginSessionPending_ = amountMinor > 0;
  beginSessionAmountMinor_ = amountMinor;
  beginSessionAwaitingAck_ = false;
  lastBeginSessionStatus_ = beginSessionPending_ ? "armed" : "idle";
  emitEvent("cashless_begin_session_armed",
            String("{\"amount_minor\":") + amountMinor +
                ",\"reader_enabled\":" + boolToJson(isReaderEnabled_) + "}");
}

void MdbService::markBeginSessionSent(unsigned long firstTxUs, uint16_t amountMinor) {
  beginSessionAwaitingAck_ = firstTxUs != 0;
  lastBeginSessionTxUs_ = firstTxUs;
  lastBeginSessionSentAtMs_ = millis();
  lastBeginSessionStatus_ = firstTxUs != 0 ? "sent" : "send_failed";
  if (firstTxUs != 0) {
    beginSessionTxCount_++;
  }
  emitEvent("cashless_begin_session_tx_state",
            String("{\"status\":\"") + escapeForJson(lastBeginSessionStatus_) +
                "\",\"amount_minor\":" + amountMinor +
                ",\"tx_ts_us\":" + firstTxUs + "}");
}

void MdbService::markBeginSessionAckReceived(unsigned long ackTsUs) {
  if (!beginSessionAwaitingAck_) {
    return;
  }
  beginSessionAwaitingAck_ = false;
  beginSessionAckCount_++;
  lastBeginSessionAckUs_ = ackTsUs;
  lastBeginSessionStatus_ = "ack_received";
  emitEvent("cashless_begin_session_ack_received",
            String("{\"ack\":true,\"ack_ts_us\":") + ackTsUs +
                ",\"begin_session_tx_ts_us\":" + lastBeginSessionTxUs_ + "}");
}

void MdbService::markBeginSessionAckMissing(const char* reason, unsigned long nowMs) {
  if (!beginSessionAwaitingAck_) {
    return;
  }
  beginSessionAwaitingAck_ = false;
  lastBeginSessionStatus_ = reason == nullptr ? "ack_missing" : reason;
  emitEvent("cashless_begin_session_ack_missing",
            String("{\"ack\":false,\"reason\":\"") +
                escapeForJson(lastBeginSessionStatus_) +
                "\",\"begin_session_tx_ts_us\":" + lastBeginSessionTxUs_ +
                ",\"wait_ms\":" +
                (lastBeginSessionSentAtMs_ > 0 && nowMs >= lastBeginSessionSentAtMs_
                     ? (nowMs - lastBeginSessionSentAtMs_)
                     : 0) +
                "}");
}

void MdbService::startCreditFlowStrategy(uint16_t amountMinor) {
  activate();
  uint32_t candidateRunId = static_cast<uint32_t>(millis());
  if (candidateRunId < 2) {
    candidateRunId = 2;
  }
  if (candidateRunId <= creditFlowRunCounter_) {
    candidateRunId = creditFlowRunCounter_ + 1;
  }
  creditFlowRunCounter_ = candidateRunId;
  creditFlowActiveRunId_ = candidateRunId;
  creditFlowActive_ = true;
  creditFlowCompleted_ = false;
  creditFlowNeedsJustReset_ = false;
  creditFlowJustResetSent_ = false;
  creditFlowSessionHijackAttempted_ = false;
  creditFlowVendDeniedSent_ = false;
  creditFlowVendApprovedSent_ = false;
  creditFlowSessionEndSent_ = false;
  creditFlowSetupSeen_ = false;
  creditFlowExpansionSeen_ = false;
  creditFlowEnableSeen_ = false;
  creditFlowBeginSessionSent_ = false;
  creditFlowAwaitingAck_ = false;
  creditFlowAckReceived_ = false;
  creditFlowObservationActive_ = false;
  creditFlowStartedAt_ = millis();
  creditFlowObservationEndsAt_ = 0;
  creditFlowResponseDelayUs_ = 0;
  creditFlowExactReplyDelayUs_ = 0;
  creditFlowLastRxByteUs_ = 0;
  creditFlowFrameFinalizedUs_ = 0;
  creditFlowFirstTxByteUs_ = 0;
  creditFlowPhyLoopCounter_ = 0;
  for (size_t i = 0; i < MachinePhy::kSoftwareDecoderModes; ++i) {
    decoderModeTraceCount_[i] = 0;
    decoderModeByteCount_[i] = 0;
    decoderModeLastPartial_[i] = 0;
    decoderModeLastByte_[i] = 0;
    decoderModeBestByte_[i] = 0;
    decoderModeBestDistanceTo10_[i] = 0xFF;
    decoderModeBestDistanceTo08_[i] = 0xFF;
    decoderModeLastPath_[i] = 0;
  }
  creditFlowAmountMinor_ = amountMinor;
  creditFlowPostReplyFrameCount_ = 0;
  creditFlowCandidateLabel_ = "CREDIT_FLOW_03";
  creditFlowCandidateBytes_ = "";
  creditFlowObservedFamilies_ = "";
  deferredTxFrameId_ = 0;
  deferredTxCount_ = 0;
  fastHandledFramePending_ = false;
  fastHandledFrameEndedUs_ = 0;
  fastHandledFrameAddress_ = 0;
  fastHandledFrameCommand_ = 0;
  isReaderEnabled_ = false;
  beginSessionPending_ = false;
  beginSessionAmountMinor_ = 0;
  deferredFastPathVendApproved_ = false;
  deferredFastPathBeginSession_ = false;
  deferredFastPathCashlessKind_ = 0;
  deferredFastPathCashlessTxUs_ = 0;
  deferredFastPathCashlessEnabled_ = false;
  deferredFastPathFinalizeCreditFlow_ = false;
  deferredFastPathFinalizeStatus_ = nullptr;
  deferredFastPathFinalizeReason_ = nullptr;
  rebuildPrecomputedFrames();
  emitEvent("credit_flow_strategy_started",
            String("{\"run_id\":") + creditFlowActiveRunId_ +
                ",\"amount_minor\":" + amountMinor +
                ",\"trigger_family\":\"12/7_or_0x10\","
                "\"session_hijack_mode\":true}");
}

void MdbService::stopCreditFlowStrategy() {
  if (!creditFlowActive_) {
    return;
  }
  finalizeCreditFlowStrategy(millis(), "failed", "manually_stopped");
}

void MdbService::emitDecoderModeScore(uint8_t mode, const char* reason) {
  if (mode >= MachinePhy::kSoftwareDecoderModes) {
    return;
  }
  const uint8_t best10 = decoderModeBestDistanceTo10_[mode];
  const uint8_t best08 = decoderModeBestDistanceTo08_[mode];
  emitEvent("phy_decoder_mode_score",
            String("{\"reason\":\"") + reason +
                "\",\"mode\":" + mode +
                ",\"trace_count\":" + decoderModeTraceCount_[mode] +
                ",\"byte_count\":" + decoderModeByteCount_[mode] +
                ",\"last_partial\":" + decoderModeLastPartial_[mode] +
                ",\"last_partial_hex\":\"" +
                byteToHex(decoderModeLastPartial_[mode]) +
                "\",\"last_byte\":" + decoderModeLastByte_[mode] +
                ",\"last_byte_hex\":\"" +
                byteToHex(decoderModeLastByte_[mode]) +
                "\",\"best_byte\":" + decoderModeBestByte_[mode] +
                ",\"best_byte_hex\":\"" +
                byteToHex(decoderModeBestByte_[mode]) +
                "\",\"best_distance_to_0x10\":" +
                (best10 == 0xFF ? -1 : static_cast<int>(best10)) +
                ",\"best_distance_to_0x08\":" +
                (best08 == 0xFF ? -1 : static_cast<int>(best08)) +
                ",\"last_path\":\"" +
                String(decoderPathLabel(decoderModeLastPath_[mode])) + "\"}");
}

void MdbService::flushDeferredFastPathEvents() {
  if (deferredFastPathCashlessKind_ != 0) {
    switch (deferredFastPathCashlessKind_) {
      case 1:
        if (deferredFastPathCashlessTxUs_ != 0) {
          emitEvent("ACK_SENT",
                    String("{\"trigger\":\"fast_cashless_reset\","
                           "\"tx_ts_us\":") +
                        deferredFastPathCashlessTxUs_ + "}");
        }
        emitEvent("cashless_reset_received",
                  String("{\"cashless_address\":") +
                      static_cast<unsigned int>(cashlessAddress_) +
                      ",\"just_reset_pending\":true,\"fast_path\":true}");
        break;
      case 2:
        emitEvent("JUST_RESET_SENT",
                  String("{\"status_byte\":0,\"fast_path\":true,\"tx_ts_us\":") +
                      deferredFastPathCashlessTxUs_ + "}");
        emitEvent("cashless_poll_just_reset",
                  String("{\"setup_seen\":") + boolToJson(cashlessSetupSeen_) +
                      ",\"expansion_seen\":" +
                      boolToJson(cashlessExpansionSeen_) +
                      ",\"fast_path\":true}");
        break;
      case 3:
        emitEvent("cashless_begin_session_sent",
                  String("{\"amount_minor\":") + creditFlowAmountMinor_ +
                      ",\"fast_path\":true}");
        break;
      case 4:
        emitEvent("ACK_SENT",
                  String("{\"trigger\":\"fast_cashless_poll_ack\","
                         "\"tx_ts_us\":") +
                      deferredFastPathCashlessTxUs_ +
                      ",\"reader_enabled\":" +
                      boolToJson(deferredFastPathCashlessEnabled_) + "}");
        break;
      case 5:
        emitEvent("SETUP_RECEIVED",
                  String("{\"run_id\":") + creditFlowActiveRunId_ +
                      ",\"fast_path\":true}");
        emitEvent("cashless_setup_response",
                  String("{\"mdb_level\":") + kCashlessLevel +
                      ",\"scaling_factor\":" + kCashlessScalingFactor +
                      ",\"decimal_places\":" + kCashlessDecimalPlaces +
                      ",\"response_time\":" +
                      lastSetupResponseResponseTime_ +
                      ",\"options\":" + lastSetupResponseOptions_ +
                      ",\"profile_id\":\"" +
                      escapeForJson(setupResponseProfileId_) +
                      "\"" +
                      ",\"tx_ts_us\":" + deferredFastPathCashlessTxUs_ +
                      ",\"reply_delay_us\":" + lastSetupResponseReplyDelayUs_ +
                      ",\"fast_path\":true}");
        break;
      case 6:
        emitEvent("cashless_expansion_response",
                  "{\"expansion_header\":9,\"device_id\":\"DENIS0000001\","
                  "\"version_major\":1,\"version_minor\":1,"
                  "\"version_patch\":1,\"fast_path\":true}");
        break;
      case 7:
        emitEvent("ACK_SENT",
                  String("{\"trigger\":\"fast_reader_control\","
                         "\"tx_ts_us\":") +
                      deferredFastPathCashlessTxUs_ + "}");
        emitEvent("cashless_reader_control",
                  String("{\"enabled\":") +
                      boolToJson(deferredFastPathCashlessEnabled_) +
                      ",\"fast_path\":true}");
        break;
      default:
        break;
    }
    deferredFastPathCashlessKind_ = 0;
    deferredFastPathCashlessTxUs_ = 0;
    deferredFastPathCashlessEnabled_ = false;
  }

  if (deferredFastPathVendApproved_) {
    emitEvent("cashless_vend_compat",
              String("{\"family\":\"12/6\",\"action\":\"vend_approved\","
                     "\"amount_minor\":100,\"reason\":\"force_active_session_phy_fast\","
                     "\"response_delay_us\":") +
                  creditFlowResponseDelayUs_ + ",\"exact_reply_delay_us\":" +
                  creditFlowExactReplyDelayUs_ + "}");
    emitEvent("credit_flow_timing_debug",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"last_rx_byte_us\":" + creditFlowLastRxByteUs_ +
                  ",\"frame_finalized_us\":" + creditFlowFrameFinalizedUs_ +
                  ",\"first_tx_byte_us\":" + creditFlowFirstTxByteUs_ +
                  ",\"rx_to_finalize_gap\":" +
                  (creditFlowFrameFinalizedUs_ >= creditFlowLastRxByteUs_
                       ? (creditFlowFrameFinalizedUs_ - creditFlowLastRxByteUs_)
                       : 0) +
                  ",\"finalize_to_tx_gap\":" +
                  (creditFlowFirstTxByteUs_ >= creditFlowFrameFinalizedUs_
                       ? (creditFlowFirstTxByteUs_ - creditFlowFrameFinalizedUs_)
                       : 0) +
                  ",\"rx_timeout_chars\":2}");
    deferredFastPathVendApproved_ = false;
  }

  if (deferredFastPathBeginSession_) {
    emitEvent("credit_flow_begin_session_sent",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"amount_minor\":100,\"response_delay_us\":" +
                  creditFlowResponseDelayUs_ +
                  ",\"exact_reply_delay_us\":" + creditFlowExactReplyDelayUs_ +
                  ",\"early_timeout\":" +
                  boolToJson(creditFlowResponseDelayUs_ > 5000) +
                  ",\"trigger\":\"phy_fast_path\"}");
    emitEvent("credit_flow_timing_debug",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"last_rx_byte_us\":" + creditFlowLastRxByteUs_ +
                  ",\"frame_finalized_us\":" + creditFlowFrameFinalizedUs_ +
                  ",\"first_tx_byte_us\":" + creditFlowFirstTxByteUs_ +
                  ",\"rx_to_finalize_gap\":" +
                  (creditFlowFrameFinalizedUs_ >= creditFlowLastRxByteUs_
                       ? (creditFlowFrameFinalizedUs_ - creditFlowLastRxByteUs_)
                       : 0) +
                  ",\"finalize_to_tx_gap\":" +
                  (creditFlowFirstTxByteUs_ >= creditFlowFrameFinalizedUs_
                       ? (creditFlowFirstTxByteUs_ - creditFlowFrameFinalizedUs_)
                       : 0) +
                  ",\"rx_timeout_chars\":2}");
    deferredFastPathBeginSession_ = false;
  }

  if (deferredFastPathFinalizeCreditFlow_) {
    finalizeCreditFlowStrategy(millis(), deferredFastPathFinalizeStatus_,
                               deferredFastPathFinalizeReason_);
    deferredFastPathFinalizeCreditFlow_ = false;
    deferredFastPathFinalizeStatus_ = nullptr;
    deferredFastPathFinalizeReason_ = nullptr;
  }
}

void MdbService::requestSniffRecent() {
  activate();
  const size_t framesToEmit =
      sniffHistoryCount_ > kSniffRecentFramesLimit ? kSniffRecentFramesLimit
                                                   : sniffHistoryCount_;
  emitEvent("sniff_recent_meta", buildSniffRecentMetaJson(framesToEmit));
  for (size_t offset = 0; offset < framesToEmit; ++offset) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - framesToEmit + offset) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used) {
      continue;
    }
    emitEvent("sniff_recent_frame", buildSniffRecentFrameJson(record, offset));
  }
}

void MdbService::requestSniffSummary() {
  activate();
  emitEvent("sniff_summary_meta", buildSniffSummaryMetaJson());
  uint16_t familySeen[32][8] = {};
  uint16_t familyPass[kStrategyCount][32][8] = {};
  uint16_t familyPlausible[kStrategyCount][32][8] = {};

  for (size_t i = 0; i < sniffHistoryCount_; ++i) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - sniffHistoryCount_ + i) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used || record.length == 0) continue;
    bool recordFamilySeen[32][8] = {};
    for (size_t s = 0; s < kStrategyCount; ++s) {
      const StrategyView& view = record.strategies[s];
      if (view.hasCandidateAddress && view.candidateAddress < 32 &&
          view.candidateCommand < 8) {
        recordFamilySeen[view.candidateAddress][view.candidateCommand] = true;
        if (view.checksumValid) {
          familyPass[s][view.candidateAddress][view.candidateCommand]++;
        }
        if (view.plausible) {
          familyPlausible[s][view.candidateAddress][view.candidateCommand]++;
        }
      }
    }
    for (size_t address = 0; address < 32; ++address) {
      for (size_t command = 0; command < 8; ++command) {
        if (recordFamilySeen[address][command]) {
          familySeen[address][command]++;
        }
      }
    }
  }

  struct FamilySummary {
    uint8_t address = 0;
    uint8_t command = 0;
    uint16_t seen = 0;
    uint8_t bestStrategyIndex = 0;
  };
  FamilySummary topFamilies[kSniffSummaryFamiliesLimit] = {};
  size_t topFamilyCount = 0;

  auto maybeStoreFamily = [&](uint8_t address, uint8_t command, uint16_t seen,
                              uint8_t bestStrategyIndex) {
    if (topFamilyCount < kSniffSummaryFamiliesLimit) {
      topFamilies[topFamilyCount].address = address;
      topFamilies[topFamilyCount].command = command;
      topFamilies[topFamilyCount].seen = seen;
      topFamilies[topFamilyCount].bestStrategyIndex = bestStrategyIndex;
      topFamilyCount++;
      return;
    }
    size_t weakestIndex = 0;
    for (size_t i = 1; i < topFamilyCount; ++i) {
      if (topFamilies[i].seen < topFamilies[weakestIndex].seen) {
        weakestIndex = i;
      }
    }
    if (seen > topFamilies[weakestIndex].seen) {
      topFamilies[weakestIndex].address = address;
      topFamilies[weakestIndex].command = command;
      topFamilies[weakestIndex].seen = seen;
      topFamilies[weakestIndex].bestStrategyIndex = bestStrategyIndex;
    }
  };

  for (size_t address = 0; address < 32; ++address) {
    for (size_t command = 0; command < 8; ++command) {
      if (familySeen[address][command] == 0) {
        continue;
      }
      size_t bestStrategyIndex = 0;
      uint16_t bestPass = 0;
      uint16_t bestPlausible = 0;
      for (size_t s = 0; s < kStrategyCount; ++s) {
        const uint16_t pass = familyPass[s][address][command];
        const uint16_t plausible = familyPlausible[s][address][command];
        if (pass > bestPass || (pass == bestPass && plausible >= bestPlausible)) {
          bestPass = pass;
          bestPlausible = plausible;
          bestStrategyIndex = s;
        }
      }
      maybeStoreFamily(static_cast<uint8_t>(address), static_cast<uint8_t>(command),
                       familySeen[address][command],
                       static_cast<uint8_t>(bestStrategyIndex));
    }
  }

  for (size_t i = 0; i + 1 < topFamilyCount; ++i) {
    for (size_t j = i + 1; j < topFamilyCount; ++j) {
      if (topFamilies[j].seen > topFamilies[i].seen) {
        const FamilySummary tmp = topFamilies[i];
        topFamilies[i] = topFamilies[j];
        topFamilies[j] = tmp;
      }
    }
  }

  for (size_t i = 0; i < topFamilyCount; ++i) {
    const uint8_t address = topFamilies[i].address;
    const uint8_t command = topFamilies[i].command;
    const uint8_t bestStrategyIndex = topFamilies[i].bestStrategyIndex;
    emitEvent("sniff_summary_family",
              buildSniffSummaryFamilyJson(
                  address, command, familySeen[address][command], bestStrategyIndex,
                  familyPass[bestStrategyIndex][address][command],
                  familyPlausible[bestStrategyIndex][address][command]));
  }
}

void MdbService::requestSniffStats() {
  activate();
  emitEvent("sniff_stats", buildSniffStatsJson());
}

void MdbService::requestSniffClear() {
  for (size_t i = 0; i < kSniffHistorySize; ++i) {
    sniffHistory_[i] = {};
  }
  sniffHistoryNext_ = 0;
  sniffHistoryCount_ = 0;
  totalFramesSeen_ = 0;
  checksumPassCount_ = 0;
  checksumFailCount_ = 0;
  expectedMatchCount_ = 0;
  foreignFrameCount_ = 0;
  ambiguousFrameCount_ = 0;
  invalidFrameCount_ = 0;
  emitEvent("sniff_cleared", "{}");
}

void MdbService::setExpectedAddress(int address) {
  expectedAddress_ = address;
  emitEvent("expected_address_changed",
            String("{\"expected_address\":") + expectedAddress_ + "}");
}

void MdbService::setCashlessAddress(int address) {
  if (address < 0) {
    address = 0;
  } else if (address > 31) {
    address = 31;
  }
  cashlessAddress_ = static_cast<uint8_t>(address);
  isReaderEnabled_ = false;
  beginSessionPending_ = false;
  beginSessionAmountMinor_ = 0;
  cashlessJustResetPending_ = true;
  cashlessSetupSeen_ = false;
  cashlessSetupMaxMinSeen_ = false;
  cashlessSetupResponsePending_ = false;
  cashlessSetupResponseAwaitingAck_ = false;
  cashlessExpansionSeen_ = false;
  cashlessSetupResponseSentAtMs_ = 0;
  cashlessSetupResponseSentUs_ = 0;
  lastSetupResponseReplyDelayUs_ = 0;
  lastSetupResponseTxUs_ = 0;
  lastSetupRxTsUs_ = 0;
  lastSetupRxEndUs_ = 0;
  lastSetupDecisionTsUs_ = 0;
  lastSetupFrameBuiltTsUs_ = 0;
  lastSetupQueueEnqueueTsUs_ = 0;
  lastSetupTxDoneUs_ = 0;
  lastSetupReleaseUs_ = 0;
  lastSetupDecisionToTxUs_ = 0;
  lastSetupBuildToTxUs_ = 0;
  lastSetupTotalResponseUs_ = 0;
  lastSetupToRepeatUs_ = 0;
  lastSetupResponseChecksum_ = 0;
  lastSetupResponseOptions_ = 0;
  lastSetupResponseResponseTime_ = 0;
  lastSetupFastPathUsed_ = false;
  currentSetupResponseGatewayCompat_ = false;
  gatewayCompatLastSetupResponseUs_ = 0;
  gatewayCompatFollowupActive_ = false;
  gatewayCompatFirstFollowupCaptured_ = false;
  gatewayCompatTotalFramesSeenAtArm_ = 0;
  gatewayCompatBusAliveAfterSetup_ = false;
  gatewayCompatExpectedFollowup_ = "WRAPPER_CONTINUATION_OR_RESET_OR_RETRY";
  gatewayCompatRetryInterpretation_ = "idle";
  gatewayCompatLastOutcome_ = "idle";
  gatewayCompatSemanticSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  wrapperFsmState_ = WrapperFsmState::Idle;
  wrapperAckSemanticsMode_ = WrapperAckSemanticsMode::StandardSetupAck;
  wrapperStandardFlowEntered_ = false;
  wrapperAckSemanticsSuspect_ = false;
  wrapperContinuationTimeoutCount_ = 0;
  wrapperExpectedNextRxKind_ = "";
  wrapperExpectedNextAction_ = "";
  wrapperTransitionReason_ = "";
  wrapperContinuationKind_ = "";
  wrapperContinuationRaw9_ = 0;
  wrapperContinuationDeltaUs_ = 0;
  wrapperContinuationInterpretation_ = "";
  setupResponseRejectedByVmc_ = "unknown";
  setupRejectionBasis_ = "";
  lastNakAfterSetupTsUs_ = 0;
  lastNakAfterSetupRaw9_ = 0;
  lastNakAfterSetupDeltaUs_ = 0;
  repeatedSetupCount_ = 0;
  repeatedSetupSamePayloadCount_ = 0;
  repeatedSetupVariantCount_ = 0;
  lastSetupSeenUs_ = 0;
  lastSetupRaw9_ = 0;
  lastSetupSubcommand_ = -1;
  lastSetupVariant_ = "";
  lastSetupHex_ = "";
  lastRepeatedSetupReasonGuess_ = "";
  previousSetupVariant_ = "";
  previousSetupRaw9_ = 0;
  previousSetupTimestampUs_ = 0;
  repeatedSetupInterpretation_ = "";
  setupResponseProfileId_ = gatewayCompatResponseProfileIdLabel();
  setupResponseSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  firstFollowupKindAfterSetup_ = "";
  firstFollowupRaw9AfterSetup_ = 0;
  firstFollowupDeltaUs_ = 0;
  firstFollowupInterpretation_ = "";
  setupNakCausal_ = "unknown";
  setupNakInterpretation_ = "";
  resetSeenCount_ = 0;
  resetAckSentCount_ = 0;
  justResetSentCount_ = 0;
  justResetAcknowledgedCount_ = 0;
  resetAfterSetupRetryCount_ = 0;
  pollMissingAfterResetCount_ = 0;
  lastResetTsUs_ = 0;
  lastResetAckSentUs_ = 0;
  lastResetAckPreparedUs_ = 0;
  lastResetAckDoneUs_ = 0;
  lastResetAckReleaseUs_ = 0;
  lastPollAfterResetTsUs_ = 0;
  lastJustResetSentUs_ = 0;
  lastSetupResponseToResetUs_ = 0;
  lastResetToAckUs_ = 0;
  lastNextRxAfterResetTsUs_ = 0;
  repeatedSetupThenResetObserved_ = false;
  pollMissingAfterResetLogged_ = false;
  lastResetCauseGuess_ = "";
  nextActionHypothesis_ = "await_setup_or_reset";
  clearPendingCashlessSplitPrefix();
  clearObservedRawStatusWindow();
  gatewaySetupCompatStage_ = 0;
  gatewaySetupCompatStartedUs_ = 0;
  gatewaySetupCompatSawExplicitZero_ = false;
  emitEvent("cashless_address_changed",
            String("{\"cashless_address\":") +
                static_cast<unsigned int>(cashlessAddress_) +
                ",\"cashless_base_byte\":" +
                static_cast<unsigned int>(
                    cashlessCommandByte(kCashlessResetCommand)) +
                ",\"just_reset_pending\":true}");
}


void MdbService::setGatewayCompatResponseProfile(uint8_t profileId) {
  activate();
  const uint8_t requestedProfileId = profileId;
  const uint8_t sanitizedProfileId = sanitizeGatewayCompatProfileId(profileId);
  gatewayCompatResponseProfileId_ = sanitizedProfileId;
  gatewayCompatSemanticSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  setupResponseProfileId_ = gatewayCompatResponseProfileIdLabel();
  setupResponseSuspectField_ = gatewayCompatSemanticSuspectFieldLabel();
  gatewayCurrencyCountryCodeProfileId_ = gatewayCurrencyCountryCodeProfileIdLabel();
  currencyCountryCodeEncodingMode_ = gatewayCurrencyCountryCodeEncodingModeLabel();

  if (requestedProfileId != sanitizedProfileId) {
    emitEvent("gateway_compat_profile_request_sanitized",
              String("{\"requested_profile_index\":") + requestedProfileId +
                  ",\"applied_profile_index\":" + sanitizedProfileId +
                  ",\"forced_standard_profile\":" +
                  boolToJson(kGatewayCompatForceStandardProfile) +
                  ",\"forced_profile_id\":" +
                  kGatewayCompatForcedProfileId +
                  ",\"applied_profile_id\":\"" +
                  escapeForJson(gatewayCompatResponseProfileIdLabel()) +
                  "\",\"reason\":\"standard_profile_forced_global\"}");
  }

  emitEvent("gateway_compat_response_profile_changed",
            String("{\"profile_id\":\"") +
                escapeForJson(gatewayCompatResponseProfileIdLabel()) +
                "\",\"profile_index\":" + gatewayCompatResponseProfileId_ +
                ",\"requested_profile_index\":" + requestedProfileId +
                ",\"response_time\":" + gatewayCompatResponseTime() +
                ",\"options\":" + gatewayCompatResponseOptions() +
                ",\"gateway_currency_profile_id\":\"" +
                escapeForJson(gatewayCurrencyCountryCodeProfileId_) +
                "\",\"currency_code_encoding_mode\":\"" +
                escapeForJson(currencyCountryCodeEncodingMode_) +
                "\",\"currency_code_bytes_hex\":\"" +
                escapeForJson(gatewayCurrencyCountryCodeBytesHex()) +
                "\",\"currency_encoding_changed_from_profile1\":" +
                boolToJson(gatewayCurrencyCountryCodeChangedFromProfile1()) +
                ",\"semantic_suspect_field\":\"" +
                escapeForJson(gatewayCompatSemanticSuspectField_) +
                "\",\"forced_standard_profile\":" +
                boolToJson(kGatewayCompatForceStandardProfile) + "}");
}

void MdbService::configureSetupResponseExperiment(bool enabled,
                                                  uint8_t currencyCountryCodeHi,
                                                  uint8_t currencyCountryCodeLo,
                                                  uint8_t responseTime,
                                                  uint8_t options,
                                                  const String& label) {
  activate();
  setupResponseExperimentEnabled_ = enabled;
  setupResponseExperimentCurrencyCountryCodeHi_ = currencyCountryCodeHi;
  setupResponseExperimentCurrencyCountryCodeLo_ = currencyCountryCodeLo;
  setupResponseExperimentResponseTime_ = responseTime;
  setupResponseExperimentOptions_ = options;
  setupResponseExperimentLabel_ =
      label.isEmpty()
          ? buildSetupResponseExperimentLabel(currencyCountryCodeHi,
                                             currencyCountryCodeLo,
                                             responseTime, options)
          : label;

  emitEvent("setup_response_experiment_changed",
            String("{\"enabled\":") + boolToJson(setupResponseExperimentEnabled_) +
                ",\"label\":\"" +
                escapeForJson(setupResponseExperimentLabel_) +
                "\",\"currency_code_bytes_hex\":\"" +
                escapeForJson(byteToHex(setupResponseExperimentCurrencyCountryCodeHi_) +
                              " " +
                              byteToHex(setupResponseExperimentCurrencyCountryCodeLo_)) +
                "\",\"max_response_time\":" +
                static_cast<unsigned int>(setupResponseExperimentResponseTime_) +
                ",\"options\":" +
                static_cast<unsigned int>(setupResponseExperimentOptions_) + "}");
}

// Переключает инверсию RX-линии.
void MdbService::setRxInvertEnabled(bool enabled) {
  activate();
  rxInvertEnabled_ = enabled;
  phy_.setRxInvert(enabled);
  emitEvent("rx_invert_changed",
            String("{\"rx_invert\":") + (rxInvertEnabled_ ? "true" : "false") + "}");
}

// Включает или выключает подробный монитор входящих кадров.
void MdbService::setMonitorEnabled(bool enabled) {
  activate();
  monitorEnabled_ = enabled;
  emitEvent(enabled ? "monitor_started" : "monitor_stopped", "{}");
}

// Переключает passive-sniff режим без автоматических ответов.
void MdbService::setPassiveSniffEnabled(bool enabled) {
  activate();
  passiveSniffEnabled_ = enabled;
  emitEvent("passive_sniff_changed",
            String("{\"enabled\":") + (passiveSniffEnabled_ ? "true" : "false") +
                "}");
}

// Отправляет произвольную HEX-последовательность в линию автомата.
void MdbService::sendRawHex(const String& hexPayload) {
  activate();
  uint8_t buffer[64] = {};
  size_t length = 0;
  if (!parseHexPayload(hexPayload, buffer, length)) {
    emitEvent("raw_send_failed", String("{\"reason\":\"invalid_hex\"}"));
    return;
  }

  transmitDebugFrame(TxScope::DebugCommand, "raw_send", buffer, length);
  String rawHex;
  for (size_t i = 0; i < length; ++i) {
    if (i > 0) rawHex += ' ';
    if (buffer[i] < 0x10) rawHex += '0';
    rawHex += String(buffer[i], HEX);
  }
  rawHex.toUpperCase();
  emitEvent("raw_tx", String("{\"hex\":\"") + rawHex + "\"}");
}

void MdbService::setExperimentEnabled(bool enabled) {
  activate();
  if (!enabled && experimentObservationActive_) {
    emitEvent("observation_close_skipped",
              String("{\"reason\":\"disable_requested_while_observation_open\","
                     "\"run_id\":") +
                  experimentActiveRunId_ + "}");
    finalizeExperimentObservation(millis(), "observation_aborted");
  }

  const bool preserveObservation = experimentObservationActive_;
  const bool preserveReplyPending = experimentReplyPending_;
  experimentConfig_.enabled = enabled;
  experimentMode_ =
      enabled
          ? (experimentConfig_.replyLength > 1
                 ? ExperimentMode::ProtocolShapedProbe
                 : ExperimentMode::SelectiveReplyProbe)
          : ExperimentMode::PassiveOnly;
  experimentArmed_ = enabled;
  if (!preserveReplyPending) {
    experimentReplyPending_ = false;
  }
  if (!preserveObservation) {
    experimentObservationActive_ = false;
    experimentObservedPostFamilies_ = "";
  } else if (enabled) {
    emitEvent("observation_context_preserved",
              String("{\"run_id\":") + experimentActiveRunId_ +
                  ",\"reason\":\"enable_rearm_during_observation\","
                  "\"candidate_label\":\"" +
                  escapeForJson(experimentObservationCandidateLabel_) + "\"}");
  }
  experimentFireOnceRequested_ = false;
  experimentRepliesThisSession_ = 0;
  if (!enabled) {
    baselineSeriesActive_ = false;
    baselineSeriesCompleted_ = false;
    baselineSeriesIndex_ = 0;
  }
  emitEvent(enabled ? "experiment_arm" : "experiment_disabled",
            String("{\"mode\":\"") + experimentModeToString(experimentMode_) +
                "\",\"enabled\":" + boolToJson(enabled) + "}");
}

void MdbService::configureExperiment(uint8_t expectedAddress, uint8_t triggerAddress,
                                     uint8_t triggerCommand, uint8_t replyByte,
                                     unsigned long replyDelayMs,
                                     unsigned long cooldownMs,
                                     uint8_t maxRepliesPerSession,
                                     uint8_t baselineSeriesCount,
                                     unsigned long observationWindowMs,
                                     bool disableOnAnyError) {
  activate();
  experimentConfig_.expectedAddress = expectedAddress;
  experimentConfig_.triggerAddress = triggerAddress;
  experimentConfig_.triggerCommand = triggerCommand;
  experimentConfig_.replyByte = replyByte;
  experimentConfig_.replyBytes[0] = replyByte;
  experimentConfig_.replyBytes[1] = 0x00;
  experimentConfig_.replyLength = 1;
  experimentConfig_.protocolProbeCandidateId = 0;
  experimentConfig_.replyDelayMs = replyDelayMs;
  experimentConfig_.cooldownMs = cooldownMs;
  experimentConfig_.maxRepliesPerSession = maxRepliesPerSession;
  experimentConfig_.baselineSeriesCount = baselineSeriesCount;
  experimentConfig_.observationWindowMs = observationWindowMs;
  experimentConfig_.disableOnAnyError = disableOnAnyError;
  baselineSeriesActive_ = baselineSeriesCount > 0;
  baselineSeriesCompleted_ = false;
  baselineSeriesIndex_ = 0;
  uint8_t protocolBytes[2] = {0x00, 0x00};
  uint8_t protocolLength = 0;
  if (baselineSeriesCount >= 0x80) {
    const uint8_t candidateId = static_cast<uint8_t>(baselineSeriesCount & 0x7F);
    if (resolveProtocolProbeCandidate(candidateId, protocolBytes, protocolLength)) {
      experimentConfig_.protocolProbeCandidateId = candidateId;
      experimentConfig_.replyBytes[0] = protocolBytes[0];
      experimentConfig_.replyBytes[1] = protocolBytes[1];
      experimentConfig_.replyLength = protocolLength;
      experimentMode_ = ExperimentMode::ProtocolShapedProbe;
    } else {
      experimentMode_ = ExperimentMode::SelectiveReplyProbe;
    }
  } else {
    experimentMode_ = ExperimentMode::SelectiveReplyProbe;
  }
  if (experimentObservationActive_) {
    emitEvent("validation_candidate_switched",
              String("{\"run_id\":") + experimentActiveRunId_ +
                  ",\"current_observation_candidate\":\"" +
                  escapeForJson(experimentObservationCandidateLabel_) +
                  "\",\"next_candidate_bytes\":\"" +
                  bytesToHex(experimentConfig_.replyBytes,
                             experimentConfig_.replyLength) +
                  "\"}");
    emitEvent("observation_context_preserved",
              String("{\"run_id\":") + experimentActiveRunId_ +
                  ",\"reason\":\"configure_during_observation\","
                  "\"candidate_label\":\"" +
                  escapeForJson(experimentObservationCandidateLabel_) + "\"}");
  }
  emitEvent(
      "experiment_configured",
      String("{\"expected_address\":") + expectedAddress +
          ",\"trigger_family\":\"" + String(triggerAddress) + "/" +
          String(triggerCommand) + "\",\"reply_byte_hex\":\"" +
          bytesToHex(experimentConfig_.replyBytes, experimentConfig_.replyLength) +
          "\",\"experiment_mode\":\"" + experimentModeToString(experimentMode_) +
          "\",\"protocol_probe_candidate_id\":" +
          experimentConfig_.protocolProbeCandidateId +
          ",\"reply_len\":" + experimentConfig_.replyLength +
          ",\"reply_delay_ms\":" + replyDelayMs +
          ",\"cooldown_ms\":" + cooldownMs +
          ",\"max_replies_per_session\":" + maxRepliesPerSession +
          ",\"baseline_series_count\":" + baselineSeriesCount +
          ",\"observation_window_ms\":" + observationWindowMs +
          ",\"disable_on_any_error\":" + boolToJson(disableOnAnyError) + "}");
}

void MdbService::requestExperimentFireOnce() {
  activate();
  experimentFireOnceRequested_ = true;
  experimentArmed_ = true;
  emitEvent("rearm_applied",
            String("{\"mode\":\"") + experimentModeToString(experimentMode_) +
                "\",\"fire_once\":true,\"observation_open\":" +
                boolToJson(experimentObservationActive_) + "}");
  emitEvent("experiment_arm",
            String("{\"mode\":\"") + experimentModeToString(experimentMode_) +
                "\",\"fire_once\":true}");
}

String MdbService::buildExperimentCandidateLabel() const {
  if (experimentMode_ == ExperimentMode::ProtocolShapedProbe &&
      experimentConfig_.protocolProbeCandidateId != 0) {
    switch (experimentConfig_.protocolProbeCandidateId) {
      case 1:
        return "AA_00";
      case 2:
        return "00_AA";
      case 3:
        return "AA_AA";
      case 4:
        return "AA_FF";
      case 5:
        return "AA_55";
      case 6:
        return "55_AA";
      default:
        break;
    }
  }
  return bytesToHex(experimentConfig_.replyBytes, experimentConfig_.replyLength);
}

// Возвращает признак активности сервиса.
bool MdbService::isActive() const { return active_; }

// Возвращает признак, можно ли сейчас безопасно запускать OTA.
bool MdbService::isSafeForOta() const {
  return !hasCoinChangerUnresolvedPayment() && session_.isSafeForOta();
}

// Возвращает JSON-сводку состояния сервиса.
String MdbService::buildDebugStateJson() const {
  return String("{\"active\":") + (active_ ? "true" : "false") +
         ",\"monitor_enabled\":" + (monitorEnabled_ ? "true" : "false") +
         ",\"passive_sniff\":" + (passiveSniffEnabled_ ? "true" : "false") +
         ",\"rx_invert\":" + (rxInvertEnabled_ ? "true" : "false") +
         ",\"experiment_mode\":\"" +
         experimentModeToString(experimentMode_) +
         "\",\"experiment_enabled\":" +
         boolToJson(experimentConfig_.enabled) +
         ",\"experiment_armed\":" + boolToJson(experimentArmed_) +
         ",\"experiment_reply_pending\":" +
         boolToJson(experimentReplyPending_) +
         ",\"experiment_observation_active\":" +
         boolToJson(experimentObservationActive_) +
         ",\"experiment_reply_byte\":\"" +
         bytesToHex(experimentConfig_.replyBytes, experimentConfig_.replyLength) +
         "\",\"experiment_reply_len\":" + experimentConfig_.replyLength +
         ",\"protocol_probe_candidate_id\":" +
         experimentConfig_.protocolProbeCandidateId +
         "\",\"baseline_series_count\":" +
         experimentConfig_.baselineSeriesCount +
         ",\"baseline_series_index\":" + baselineSeriesIndex_ +
         ",\"baseline_series_active\":" + boolToJson(baselineSeriesActive_) +
         ",\"baseline_series_completed\":" +
         boolToJson(baselineSeriesCompleted_) +
         ",\"experiment_replies_this_session\":" +
         experimentRepliesThisSession_ +
         ",\"state\":\"" + stateToString(session_.snapshot().state) +
         "\",\"pending_amount_minor\":" + session_.snapshot().pendingAmountMinor +
         ",\"approved_amount_minor\":" + session_.snapshot().approvedAmountMinor +
         ",\"reserved_amount_minor\":" + session_.snapshot().reservedAmountMinor +
         ",\"expected_address\":" + expectedAddress_ +
         ",\"cashless_address\":" +
         String(static_cast<unsigned int>(cashlessAddress_)) +
         ",\"cashless_enabled\":" + boolToJson(kMdbCashlessEnabled) +
         ",\"coin_changer_enabled\":" + boolToJson(kMdbCoinChangerEnabled) +
         ",\"coin_changer_address\":" +
         String(static_cast<unsigned int>(kMdbCoinChangerAddress)) +
         ",\"coin_just_reset_pending\":" +
         boolToJson(coinChangerJustResetPending_) +
         ",\"coin_enable_mask_hex\":\"" +
         escapeForJson(
             byteToHex(static_cast<uint8_t>(coinChangerEnabledMask_ >> 8)) +
             " " +
             byteToHex(static_cast<uint8_t>(coinChangerEnabledMask_ & 0xFFU))) +
         "\",\"coin_feature_mask\":" + coinChangerFeatureEnableMask_ +
         ",\"coin_pending_amount_minor\":" + coinChangerPendingAmountMinor_ +
         ",\"coin_pending_scaled\":" + coinChangerPendingScaled_ +
         ",\"coin_awaiting_vmc_amount_minor\":" +
         coinChangerAwaitingVmcAmountMinor_ +
         ",\"coin_awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
         ",\"coin_last_credit_reply_tx_us\":" +
         coinChangerLastCreditReplyTxUs_ +
         ",\"coin_transaction_id\":\"" +
         escapeForJson(coinChangerPendingTransactionId_) + "\"" +
         ",\"cashless_base_byte\":" +
         String(static_cast<unsigned int>(
             cashlessCommandByte(kCashlessResetCommand))) +
         ",\"cashless_just_reset_pending\":" +
         boolToJson(cashlessJustResetPending_) +
         ",\"cashless_setup_seen\":" + boolToJson(cashlessSetupSeen_) +
         ",\"cashless_expansion_seen\":" +
         boolToJson(cashlessExpansionSeen_) +
         ",\"reader_enabled\":" + boolToJson(isReaderEnabled_) +
         ",\"rx_frame_count\":" + rxFrameCount_ + ",\"last_rx_frame_at\":" +
         lastRxFrameAt_ + ",\"last_probe_tx_at\":" + lastProbeTxAt_ +
         ",\"rx_frames_after_probe_tx\":" + rxFramesAfterProbeTx_ +
         ",\"sniff_history_count\":" + sniffHistoryCount_ +
         ",\"checksum_pass_count\":" + checksumPassCount_ +
         ",\"checksum_fail_count\":" + checksumFailCount_ +
         ",\"clear_session_pending\":" + (clearSessionPending_ ? "true" : "false") +
         "," + buildResponseTelemetryJson().substring(1) + "," +
         buildDialogueTelemetryJson().substring(1);
}

// Отправляет одно MDB-событие в backend.
bool MdbService::emitEvent(const char* eventType, const String& details,
                           String* deliveryMode, String* failureReason) {
  if (deliveryMode != nullptr) {
    *deliveryMode = "not_sent";
  }
  if (failureReason != nullptr) {
    *failureReason = "";
  }
  if (eventType == nullptr || details.isEmpty() || details[0] != '{' ||
      details[details.length() - 1] != '}') {
    if (failureReason != nullptr) {
      *failureReason = "invalid_event_details";
    }
    return false;
  }

  const String deviceId = connectionService_.deviceId();
  String message;
  const size_t reservedLength = strlen(eventType) + deviceId.length() +
                                details.length() + 64;
  if (!message.reserve(reservedLength)) {
    if (failureReason != nullptr) {
      *failureReason = "message_reserve_failed";
    }
    return false;
  }
  message = "{\"type\":\"mdb_event\",\"event\":\"";
  message += eventType;
  message += "\",\"device_id\":\"";
  message += deviceId;
  message += "\",\"details\":";
  message += details;
  message += "}";
  if (message.isEmpty() || message[0] != '{' ||
      message[message.length() - 1] != '}') {
    if (failureReason != nullptr) {
      *failureReason = "invalid_event_message";
    }
    return false;
  }
  logSerialLine(message);

  String mode = "serial_only";
  if (connectionService_.isWebSocketConnected()) {
    const bool noisyProtocolExpectation =
        strcmp(eventType, "protocol_progress_expectation") == 0;
    const bool probeDebugEvent = isProbeDebugEventType(eventType);
    const size_t outboxDepth = connectionService_.outboxDepth();
    const size_t outboxCapacity = connectionService_.outboxCapacity();
    if (probeDebugEvent) {
      mode = "serial_only_probe_debug";
    } else if (noisyProtocolExpectation && outboxCapacity > 0 &&
               outboxDepth + 1 >= outboxCapacity) {
      mode = "serial_only_ws_throttled";
    } else {
      mode = connectionService_.sendText(message) ? "serial_and_ws"
                                                  : "serial_ws_enqueue_failed";
    }
  }
  if (deliveryMode != nullptr) {
    *deliveryMode = mode;
  }
  return true;
}

bool MdbService::emitControlEvent(const char* eventType, const String& details,
                                  String* deliveryMode) {
  return emitEvent(eventType, details, deliveryMode);
}

void MdbService::emitObservedRxBytes(const machine::Frame& frame) {
  for (size_t index = 0; index < frame.length; ++index) {
    const machine::RawByte& byte = frame.bytes[index];
    const bool observed08 = byte.raw == 0x08U || byte.value7 == 0x08U;

    String json = String("{\"message\":\"RX byte observed\"") +
                  ",\"byte_index\":" + index +
                  ",\"raw_hex\":\"" + byteToHex(byte.raw) + "\"" +
                  ",\"normalized_hex\":\"" + byteToHex(byte.value7) + "\"" +
                  ",\"raw_value\":" + byte.raw +
                  ",\"normalized_value\":" + byte.value7 +
                  ",\"observed_0x08\":" + boolToJson(observed08) +
                  ",\"high_bit\":" + boolToJson(byte.highBit) +
                  ",\"ts_us\":" + byte.tsUs +
                  ",\"frame_hex\":\"" + machine::rawHex(frame) + "\"" +
                  ",\"normalized_frame_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"frame_length\":" + frame.length;
    if (index == 0) {
      json += ",\"candidate_address\":" + String(byte.value7 >> 3U) +
              ",\"candidate_command\":" + String(byte.value7 & 0x07U);
    }
    json += "}";
    emitEvent("rx_byte_observed", json);
    if (observed08) {
      emitEvent("rx_byte_0x08_observed", json);
    }
  }
}

// Публикует обновлённое состояние cashless-FSM.
void MdbService::emitStateChanged() {
  emitEvent("state_changed",
            String("{\"state\":\"") + stateToString(session_.snapshot().state) +
                "\",\"pending_amount_minor\":" +
                session_.snapshot().pendingAmountMinor +
                ",\"approved_amount_minor\":" +
                session_.snapshot().approvedAmountMinor +
                ",\"reserved_amount_minor\":" +
                session_.snapshot().reservedAmountMinor +
                ",\"coin_pending_amount_minor\":" +
                coinChangerPendingAmountMinor_ +
                ",\"coin_pending_scaled\":" + coinChangerPendingScaled_ +
                ",\"coin_awaiting_vmc_amount_minor\":" +
                coinChangerAwaitingVmcAmountMinor_ +
                ",\"coin_awaiting_vmc_scaled\":" +
                coinChangerAwaitingVmcScaled_ +
                ",\"coin_transaction_id\":\"" +
                escapeForJson(coinChangerPendingTransactionId_) + "\"}");
}

void MdbService::storeSniffFrame(const machine::Frame& frame) {
  SniffFrameRecord record;
  record.used = true;
  record.startedAtMs = frame.startedAtMs;
  record.endedAtMs = frame.endedAtMs;
  record.frameGapBeforeMs = frame.frameGapBeforeMs;
  record.frameGapAfterMs = frame.frameGapAfterMs;
  record.length = frame.length > kStoredFrameBytes ? kStoredFrameBytes : frame.length;
  record.truncated = frame.truncated || frame.length > kStoredFrameBytes;
  record.maybePartial = frame.maybePartial;
  record.maybeMerged = frame.maybeMerged;
  record.endReasonCode = frame.endReasonCode;
  record.captureQuality = frame.captureQuality;
  record.continuationAttempted = frame.continuationAttempted;
  record.continuationWaitStartedMs = frame.continuationWaitStartedMs;
  record.continuationWaitMs = frame.continuationWaitMs;
  record.continuationAppendedBytes = frame.continuationAppendedBytes;
  record.continuationResultCode = frame.continuationResultCode;
  record.continuationFailReasonCode = frame.continuationFailReasonCode;
  record.rebootGapDetected = frame.rebootGapDetected;
  record.sessionBreakGapDetected = frame.sessionBreakGapDetected;
  record.expectedAddressConfigured = expectedAddress_ >= 0;
  record.expectedAddress =
      expectedAddress_ >= 0 ? static_cast<uint8_t>(expectedAddress_) : 0xFF;

  for (size_t i = 0; i < record.length; ++i) {
    record.raw[i] = frame.bytes[i].raw;
    record.normalized[i] = frame.normalized[i];
    record.highBit[i] = frame.bytes[i].highBit;
    record.tsMs[i] = frame.bytes[i].tsMs;
    record.gapBeforeMs[i] = frame.bytes[i].gapBeforeMs;
  }

  populateStrategyViews(frame, record);
  sniffHistory_[sniffHistoryNext_] = record;
  sniffHistoryNext_ = (sniffHistoryNext_ + 1) % kSniffHistorySize;
  if (sniffHistoryCount_ < kSniffHistorySize) {
    sniffHistoryCount_++;
  }
}

void MdbService::populateStrategyViews(const machine::Frame& frame,
                                       SniffFrameRecord& record) const {
  for (size_t strategyIndex = 0; strategyIndex < kStrategyCount; ++strategyIndex) {
    StrategyView& view = record.strategies[strategyIndex];
    view.name = static_cast<char>('A' + strategyIndex);
    const size_t length = frame.length > kStoredFrameBytes ? kStoredFrameBytes : frame.length;
    view.length = length;
    for (size_t i = 0; i < length; ++i) {
      const uint8_t raw = frame.bytes[i].raw;
      uint8_t transformed = raw;
      switch (strategyIndex) {
        case 0:
          transformed = raw;
          break;
        case 1:
          transformed = raw & 0x7F;
          break;
        case 2:
          transformed = frame.bytes[i].highBit ? (raw & 0x7F) : raw;
          break;
        case 3:
          transformed = (i == 0) ? raw : (raw & 0x7F);
          break;
        case 4:
          transformed = raw & 0x7F;
          break;
      }
      view.bytes[i] = transformed;
    }

    mdb::MasterBlock block;
    view.parseOk = mdb::parseMasterBlock(view.bytes, view.length, block);
    view.checksumValid = view.parseOk && block.checksumValid;
    if (view.length > 0) {
      view.hasCandidateAddress = true;
      view.candidateAddress = view.bytes[0] >> 3;
      view.candidateCommand = view.bytes[0] & 0x07;
    }
    view.plausible =
        view.parseOk && (view.checksumValid || view.length <= 2 || view.candidateCommand <= 7);
    view.confidence = 0;
    if (view.parseOk) view.confidence += 25;
    if (view.checksumValid) view.confidence += 40;
    if (view.hasCandidateAddress) view.confidence += 10;
    if (record.expectedAddressConfigured &&
        view.candidateAddress == record.expectedAddress) {
      view.confidence += 25;
    }
  }
}

String MdbService::buildSniffRecentJson() const {
  const size_t framesToEmit =
      sniffHistoryCount_ > kSniffRecentFramesLimit ? kSniffRecentFramesLimit
                                                   : sniffHistoryCount_;
  String json = "{\"frames\":[";
  json.reserve(768);
  for (size_t offset = 0; offset < framesToEmit; ++offset) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - framesToEmit + offset) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used) {
      continue;
    }
    if (json[json.length() - 1] != '[') {
      json += ',';
    }
    json += "{\"started_at_ms\":";
    json += record.startedAtMs;
    json += ",\"frame_gap_before_ms\":";
    json += record.frameGapBeforeMs;
    json += ",\"frame_gap_after_ms\":";
    json += record.frameGapAfterMs;
    json += ",\"timestamp_ms\":";
    json += record.startedAtMs;
    json += ",\"length\":";
    json += record.length;
    json += ",\"raw_hex\":\"";
    json += bytesToHex(record.raw, record.length);
    json += "\",\"normalized_hex\":\"";
    json += bytesToHex(record.normalized, record.length);
    json += "\",\"end_reason\":\"";
    json += endReasonToString(record.endReasonCode);
    json += "\",\"truncated\":";
    json += boolToJson(record.truncated);
    json += ",\"maybe_partial\":";
    json += boolToJson(record.maybePartial);
    json += ",\"maybe_merged\":";
    json += boolToJson(record.maybeMerged);
    json += ",\"continuation_attempted\":";
    json += boolToJson(record.continuationAttempted);
    json += ",\"continuation_appended_bytes\":";
    json += record.continuationAppendedBytes;
    json += ",\"frame_end_reason\":\"";
    json += endReasonToString(record.endReasonCode);
    json += "\"";
    json += ",\"frame_capture_quality\":";
    json += record.captureQuality;
    json += ",\"expected_address\":";
    json += record.expectedAddressConfigured ? String(record.expectedAddress) : String(-1);
    int bestStrategy = -1;
    uint8_t bestConfidence = 0;
    for (size_t s = 0; s < kStrategyCount; ++s) {
      const StrategyView& view = record.strategies[s];
      if (view.plausible && view.confidence >= bestConfidence) {
        bestConfidence = view.confidence;
        bestStrategy = static_cast<int>(s);
      }
    }
    json += ",\"best_strategy\":";
    if (bestStrategy >= 0) {
      const StrategyView& view = record.strategies[bestStrategy];
      json += "{\"name\":\"";
      json += view.name;
      json += "\",\"checksum_valid\":";
      json += boolToJson(view.checksumValid);
      json += ",\"candidate_address\":";
      json += view.hasCandidateAddress ? String(view.candidateAddress) : String(-1);
      json += ",\"candidate_command\":";
      json += view.hasCandidateAddress ? String(view.candidateCommand) : String(-1);
      json += ",\"confidence\":";
      json += view.confidence;
      json += "}";
    } else {
      json += "null";
    }
    json += "}";
  }
  json += "],\"returned_frames\":";
  json += framesToEmit;
  json += ",\"stored_frames\":";
  json += sniffHistoryCount_;
  json += "}";
  return json;
}

String MdbService::buildSniffRecentFrameJson(const SniffFrameRecord& record,
                                             size_t index) const {
  String json = "{\"index\":";
  json += index;
  json += ",\"started_at_ms\":";
  json += record.startedAtMs;
  json += ",\"frame_gap_before_ms\":";
  json += record.frameGapBeforeMs;
  json += ",\"frame_gap_after_ms\":";
  json += record.frameGapAfterMs;
  json += ",\"timestamp_ms\":";
  json += record.startedAtMs;
  json += ",\"length\":";
  json += record.length;
  json += ",\"raw_hex\":\"";
  json += bytesToHex(record.raw, record.length);
  json += "\",\"normalized_hex\":\"";
  json += bytesToHex(record.normalized, record.length);
  json += "\",\"expected_address\":";
  json += record.expectedAddressConfigured ? String(record.expectedAddress) : String(-1);
  json += ",\"maybe_partial\":";
  json += boolToJson(record.maybePartial);
  json += ",\"maybe_merged\":";
  json += boolToJson(record.maybeMerged);
  json += ",\"continuation_attempted\":";
  json += boolToJson(record.continuationAttempted);
  json += ",\"continuation_appended_bytes\":";
  json += record.continuationAppendedBytes;
  json += ",\"frame_end_reason\":\"";
  json += endReasonToString(record.endReasonCode);
  json += "\"";
  int bestStrategy = -1;
  uint8_t bestConfidence = 0;
  for (size_t s = 0; s < kStrategyCount; ++s) {
    const StrategyView& view = record.strategies[s];
    if (view.plausible && view.confidence >= bestConfidence) {
      bestConfidence = view.confidence;
      bestStrategy = static_cast<int>(s);
    }
  }
  json += ",\"best_strategy\":";
  if (bestStrategy >= 0) {
    const StrategyView& view = record.strategies[bestStrategy];
    json += "{\"name\":\"";
    json += view.name;
    json += "\",\"checksum_valid\":";
    json += boolToJson(view.checksumValid);
    json += ",\"candidate_address\":";
    json += view.hasCandidateAddress ? String(view.candidateAddress) : String(-1);
    json += ",\"candidate_command\":";
    json += view.hasCandidateAddress ? String(view.candidateCommand) : String(-1);
    json += ",\"confidence\":";
    json += view.confidence;
    json += "}";
  } else {
    json += "null";
  }
  json += "}";
  return json;
}

String MdbService::buildSniffRecentMetaJson(size_t returnedFrames) const {
  return String("{\"returned_frames\":") + returnedFrames +
         ",\"stored_frames\":" + sniffHistoryCount_ + "}";
}

String MdbService::buildSniffSummaryJson() const {
  uint16_t rawFirstCounts[256] = {};
  uint16_t addressCounts[32] = {};
  uint16_t commandCounts[8] = {};
  uint16_t lengthCounts[kStoredFrameBytes + 1] = {};
  uint16_t intervalCounts[256] = {};
  uint16_t strategyPass[kStrategyCount] = {};
  uint16_t strategyPlausible[kStrategyCount] = {};
  uint16_t familySeen[32][8] = {};
  uint16_t familyPass[kStrategyCount][32][8] = {};
  uint16_t familyPlausible[kStrategyCount][32][8] = {};

  unsigned long previousStart = 0;
  for (size_t i = 0; i < sniffHistoryCount_; ++i) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - sniffHistoryCount_ + i) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used || record.length == 0) continue;
    rawFirstCounts[record.raw[0]]++;
    lengthCounts[record.length <= kStoredFrameBytes ? record.length : kStoredFrameBytes]++;
    if (previousStart != 0) {
      const unsigned long interval = record.startedAtMs - previousStart;
      intervalCounts[interval < 256 ? interval : 255]++;
    }
    previousStart = record.startedAtMs;
    bool recordFamilySeen[32][8] = {};
    for (size_t s = 0; s < kStrategyCount; ++s) {
      const StrategyView& view = record.strategies[s];
      if (view.hasCandidateAddress) {
        if (view.candidateAddress < 32) {
          addressCounts[view.candidateAddress]++;
        }
        if (view.candidateCommand < 8) {
          commandCounts[view.candidateCommand]++;
        }
        if (view.candidateAddress < 32 && view.candidateCommand < 8) {
          recordFamilySeen[view.candidateAddress][view.candidateCommand] = true;
          if (view.checksumValid) {
            familyPass[s][view.candidateAddress][view.candidateCommand]++;
          }
          if (view.plausible) {
            familyPlausible[s][view.candidateAddress][view.candidateCommand]++;
          }
        }
      }
      if (view.checksumValid) strategyPass[s]++;
      if (view.plausible) strategyPlausible[s]++;
    }
    for (size_t address = 0; address < 32; ++address) {
      for (size_t command = 0; command < 8; ++command) {
        if (recordFamilySeen[address][command]) {
          familySeen[address][command]++;
        }
      }
    }
  }

  auto topIndex = [](const uint16_t* counts, size_t size) -> int {
    uint16_t best = 0;
    int bestIndex = -1;
    for (size_t i = 0; i < size; ++i) {
      if (counts[i] > best) {
        best = counts[i];
        bestIndex = static_cast<int>(i);
      }
    }
    return bestIndex;
  };

  const int topRaw = topIndex(rawFirstCounts, 256);
  const int topAddress = topIndex(addressCounts, 32);
  const int topCommand = topIndex(commandCounts, 8);
  const int topLength = topIndex(lengthCounts, kStoredFrameBytes + 1);
  const int topInterval = topIndex(intervalCounts, 256);

  struct FamilySummary {
    uint8_t address = 0;
    uint8_t command = 0;
    uint16_t seen = 0;
    uint8_t bestStrategyIndex = 0;
  };
  FamilySummary topFamilies[kSniffSummaryFamiliesLimit] = {};
  size_t topFamilyCount = 0;

  auto maybeStoreFamily = [&](uint8_t address, uint8_t command, uint16_t seen,
                              uint8_t bestStrategyIndex) {
    if (topFamilyCount < kSniffSummaryFamiliesLimit) {
      topFamilies[topFamilyCount].address = address;
      topFamilies[topFamilyCount].command = command;
      topFamilies[topFamilyCount].seen = seen;
      topFamilies[topFamilyCount].bestStrategyIndex = bestStrategyIndex;
      topFamilyCount++;
      return;
    }

    size_t weakestIndex = 0;
    for (size_t i = 1; i < topFamilyCount; ++i) {
      if (topFamilies[i].seen < topFamilies[weakestIndex].seen) {
        weakestIndex = i;
      }
    }

    if (seen > topFamilies[weakestIndex].seen) {
      topFamilies[weakestIndex].address = address;
      topFamilies[weakestIndex].command = command;
      topFamilies[weakestIndex].seen = seen;
      topFamilies[weakestIndex].bestStrategyIndex = bestStrategyIndex;
    }
  };

  for (size_t address = 0; address < 32; ++address) {
    for (size_t command = 0; command < 8; ++command) {
      if (familySeen[address][command] == 0) {
        continue;
      }
      size_t bestStrategyIndex = 0;
      uint16_t bestPass = 0;
      uint16_t bestPlausible = 0;
      for (size_t s = 0; s < kStrategyCount; ++s) {
        const uint16_t pass = familyPass[s][address][command];
        const uint16_t plausible = familyPlausible[s][address][command];
        if (pass > bestPass || (pass == bestPass && plausible >= bestPlausible)) {
          bestPass = pass;
          bestPlausible = plausible;
          bestStrategyIndex = s;
        }
      }
      maybeStoreFamily(static_cast<uint8_t>(address), static_cast<uint8_t>(command),
                       familySeen[address][command],
                       static_cast<uint8_t>(bestStrategyIndex));
    }
  }

  for (size_t i = 0; i + 1 < topFamilyCount; ++i) {
    for (size_t j = i + 1; j < topFamilyCount; ++j) {
      if (topFamilies[j].seen > topFamilies[i].seen) {
        const FamilySummary tmp = topFamilies[i];
        topFamilies[i] = topFamilies[j];
        topFamilies[j] = tmp;
      }
    }
  }

  String json = String("{\"frame_count\":") + sniffHistoryCount_ +
                ",\"total_frames_seen\":" + totalFramesSeen_ +
                ",\"most_common_raw_first_byte\":" + topRaw +
                ",\"most_common_candidate_address\":" + topAddress +
                ",\"most_common_candidate_command\":" + topCommand +
                ",\"most_common_length\":" + topLength +
                ",\"most_common_interval_ms\":" + topInterval +
                ",\"strategy_valid_ratio\":[";
  json.reserve(1024);
  for (size_t s = 0; s < kStrategyCount; ++s) {
    if (s > 0) json += ',';
    json += "{\"name\":\"";
    json += static_cast<char>('A' + s);
    json += "\",\"checksum_pass\":";
    json += strategyPass[s];
    json += ",\"plausible\":";
    json += strategyPlausible[s];
    json += "}";
  }
  json += "]";

  json += ",\"address_command_families\":[";
  bool firstFamily = true;
  for (size_t i = 0; i < topFamilyCount; ++i) {
      const size_t address = topFamilies[i].address;
      const size_t command = topFamilies[i].command;
      const size_t bestStrategyIndex = topFamilies[i].bestStrategyIndex;
      if (!firstFamily) {
        json += ',';
      }
      firstFamily = false;
      json += "{\"candidate_address\":";
      json += address;
      json += ",\"candidate_command\":";
      json += command;
      json += ",\"seen\":";
      json += familySeen[address][command];
      json += ",\"best_strategy\":\"";
      json += static_cast<char>('A' + bestStrategyIndex);
      json += "\",\"best_checksum_pass\":";
      json += familyPass[bestStrategyIndex][address][command];
      json += ",\"best_pass_ratio\":";
      if (familySeen[address][command] == 0) {
        json += "0.00";
      } else {
        json += String(static_cast<float>(familyPass[bestStrategyIndex][address][command]) /
                       static_cast<float>(familySeen[address][command]),
                       2);
      }
      json += "}";
  }
  json += "],\"returned_families\":";
  json += topFamilyCount;
  json += "}";
  return json;
}

String MdbService::buildSniffSummaryMetaJson() const {
  uint16_t rawFirstCounts[256] = {};
  uint16_t addressCounts[32] = {};
  uint16_t commandCounts[8] = {};
  uint16_t lengthCounts[kStoredFrameBytes + 1] = {};
  uint16_t intervalCounts[256] = {};
  uint16_t strategyPass[kStrategyCount] = {};
  uint16_t strategyPlausible[kStrategyCount] = {};

  unsigned long previousStart = 0;
  for (size_t i = 0; i < sniffHistoryCount_; ++i) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - sniffHistoryCount_ + i) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used || record.length == 0) continue;
    rawFirstCounts[record.raw[0]]++;
    lengthCounts[record.length <= kStoredFrameBytes ? record.length : kStoredFrameBytes]++;
    if (previousStart != 0) {
      const unsigned long interval = record.startedAtMs - previousStart;
      intervalCounts[interval < 256 ? interval : 255]++;
    }
    previousStart = record.startedAtMs;
    for (size_t s = 0; s < kStrategyCount; ++s) {
      const StrategyView& view = record.strategies[s];
      if (view.hasCandidateAddress) {
        if (view.candidateAddress < 32) addressCounts[view.candidateAddress]++;
        if (view.candidateCommand < 8) commandCounts[view.candidateCommand]++;
      }
      if (view.checksumValid) strategyPass[s]++;
      if (view.plausible) strategyPlausible[s]++;
    }
  }

  auto topIndex = [](const uint16_t* counts, size_t size) -> int {
    uint16_t best = 0;
    int bestIndex = -1;
    for (size_t i = 0; i < size; ++i) {
      if (counts[i] > best) {
        best = counts[i];
        bestIndex = static_cast<int>(i);
      }
    }
    return bestIndex;
  };

  const int topRaw = topIndex(rawFirstCounts, 256);
  const int topAddress = topIndex(addressCounts, 32);
  const int topCommand = topIndex(commandCounts, 8);
  const int topLength = topIndex(lengthCounts, kStoredFrameBytes + 1);
  const int topInterval = topIndex(intervalCounts, 256);

  String json = String("{\"frame_count\":") + sniffHistoryCount_ +
                ",\"total_frames_seen\":" + totalFramesSeen_ +
                ",\"most_common_raw_first_byte\":" + topRaw +
                ",\"most_common_candidate_address\":" + topAddress +
                ",\"most_common_candidate_command\":" + topCommand +
                ",\"most_common_length\":" + topLength +
                ",\"most_common_interval_ms\":" + topInterval +
                ",\"strategy_valid_ratio\":[";
  for (size_t s = 0; s < kStrategyCount; ++s) {
    if (s > 0) json += ',';
    json += "{\"name\":\"";
    json += static_cast<char>('A' + s);
    json += "\",\"checksum_pass\":";
    json += strategyPass[s];
    json += ",\"plausible\":";
    json += strategyPlausible[s];
    json += "}";
  }
  json += "]}";
  return json;
}

String MdbService::buildSniffSummaryFamilyJson(uint8_t address, uint8_t command,
                                               uint16_t seen,
                                               uint8_t bestStrategyIndex,
                                               uint16_t bestChecksumPass,
                                               uint16_t bestPlausible) const {
  String json = String("{\"candidate_address\":") + address +
                ",\"candidate_command\":" + command + ",\"seen\":" + seen +
                ",\"best_strategy\":\"" + static_cast<char>('A' + bestStrategyIndex) +
                "\",\"best_checksum_pass\":" + bestChecksumPass +
                ",\"best_plausible\":" + bestPlausible +
                ",\"best_pass_ratio\":";
  if (seen == 0) {
    json += "0.00";
  } else {
    json += String(static_cast<float>(bestChecksumPass) / static_cast<float>(seen), 2);
  }
  json += "}";
  return json;
}

String MdbService::buildSniffStatsJson() const {
  unsigned long strategyPass[kStrategyCount] = {};
  unsigned long strategyPlausible[kStrategyCount] = {};
  unsigned long strategyCandidates[kStrategyCount] = {};

  for (size_t i = 0; i < sniffHistoryCount_; ++i) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - sniffHistoryCount_ + i) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used) {
      continue;
    }
    for (size_t s = 0; s < kStrategyCount; ++s) {
      const StrategyView& view = record.strategies[s];
      if (view.hasCandidateAddress) {
        strategyCandidates[s]++;
      }
      if (view.plausible) {
        strategyPlausible[s]++;
      }
      if (view.checksumValid) {
        strategyPass[s]++;
      }
    }
  }

  String json = String("{\"total_frames_seen\":") + totalFramesSeen_ +
         ",\"sniff_history_count\":" + sniffHistoryCount_ +
         ",\"checksum_pass_count\":" + checksumPassCount_ +
         ",\"checksum_fail_count\":" + checksumFailCount_ +
         ",\"expected_match_count\":" + expectedMatchCount_ +
         ",\"foreign_frame_count\":" + foreignFrameCount_ +
         ",\"ambiguous_frame_count\":" + ambiguousFrameCount_ +
         ",\"invalid_frame_count\":" + invalidFrameCount_ +
         ",\"expected_address\":" + expectedAddress_ +
         ",\"strategy_totals\":[";

  for (size_t s = 0; s < kStrategyCount; ++s) {
    if (s > 0) {
      json += ',';
    }
    json += "{\"name\":\"";
    json += static_cast<char>('A' + s);
    json += "\",\"candidate_frames\":";
    json += strategyCandidates[s];
    json += ",\"plausible_frames\":";
    json += strategyPlausible[s];
    json += ",\"checksum_pass\":";
    json += strategyPass[s];
    json += "}";
  }
  json += "]}";
  return json;
}

// Обрабатывает один уже собранный кадр линии автомата.
void MdbService::processFrame(const machine::Frame& frame, unsigned long now,
                              bool cashlessFastReplyHandled) {
  (void)now;
  if (frame.length == 0) {
    return;
  }

  if (cashlessSetupResponseAwaitingAck_ && frame.normalizedLength == 1 &&
      frame.normalized[0] == mdb::kAck) {
    markSetupResponseAckReceived(frame.endedAtUs);
  }

  if (beginSessionAwaitingAck_ && frame.normalizedLength == 1 &&
      frame.normalized[0] == mdb::kAck) {
    markBeginSessionAckReceived(frame.endedAtUs);
  }

  if (coinChangerAwaitingVmcScaled_ > 0 && frame.normalizedLength == 1 &&
      frame.normalized[0] == mdb::kNak &&
      coinChangerLastCreditReplyTxUs_ > 0 &&
      frame.endedAtUs >= coinChangerLastCreditReplyTxUs_) {
    emitEvent("coin_credit_rejected_by_vmc",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"last_credit_reply_tx_us\":" +
                  coinChangerLastCreditReplyTxUs_ +
                  ",\"awaiting_vmc_scaled\":" +
                  coinChangerAwaitingVmcScaled_ +
                  ",\"transaction_id\":\"" +
                  escapeForJson(coinChangerPendingTransactionId_) + "\"}");
    requeueCoinChangerAwaitingAcceptance("vmc_nak_after_local_credit");
  }

  if (coinCompatTailIgnoreUntilUs_ > 0 && frame.endedAtUs > coinCompatTailIgnoreUntilUs_) {
    coinCompatTailIgnoreUntilUs_ = 0;
  }

  bool coinCompatTailIgnored = false;
  unsigned long coinCompatTailDeltaUs = 0;
  if (kIgnoreCoinCompatTailBytes && shouldIgnoreCoinCompatTail(frame, &coinCompatTailDeltaUs)) {
    coinCompatTailIgnored = true;
    emitEvent("coin_compat_tail_ignored",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"raw_hex\":\"" + machine::rawHex(frame) +
                  "\",\"normalized_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"delta_us_from_compat_poll\":" +
                  coinCompatTailDeltaUs +
                  ",\"compat_poll_rx_ts_us\":" +
                  lastCoinCompatPollObservedUs_ +
                  ",\"compat_poll_reply_tx_ts_us\":" +
                  lastCoinCompatPollReplyTxUs_ +
                  ",\"pending_scaled\":" + coinChangerPendingScaled_ +
                  ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                  "}");
    setResponsePathState(ResponsePathState::Idle, frame.endedAtUs,
                         "coin_compat_tail_ignored");
  }

  if (frame.normalizedLength == 1 &&
      isIgnoredForeignTailByte(frame.normalized[0])) {
    return;
  }

  if (!coinCompatTailIgnored && kMdbCashlessEnabled && !cashlessFastReplyHandled &&
      frame.normalizedLength == 1 &&
      frame.normalized[0] == kObservedGatewayPollByte) {
    uint8_t replyKind = 0;
    bool readerEnabled = isReaderEnabled_;
    const unsigned long firstTxUs =
        sendCashlessPollReply(now, frame.endedAtUs, replyKind, readerEnabled);
    switch (replyKind) {
      case 2:
        emitEvent("JUST_RESET_SENT",
                  String("{\"status_byte\":0,\"gateway_compat\":true,"
                         "\"tx_ts_us\":") +
                      firstTxUs + "}");
        emitEvent("cashless_poll_just_reset",
                  String("{\"setup_seen\":") + boolToJson(cashlessSetupSeen_) +
                      ",\"expansion_seen\":" +
                      boolToJson(cashlessExpansionSeen_) +
                      ",\"gateway_compat\":true}");
        break;
      case 3:
        emitEvent("cashless_begin_session_sent",
                  String("{\"amount_minor\":") + creditFlowAmountMinor_ +
                      ",\"gateway_compat\":true}");
        break;
      case 4:
      default:
        emitEvent("ACK_SENT",
                  String("{\"trigger\":\"gateway_poll_ack\",\"tx_ts_us\":") +
                      firstTxUs + ",\"reader_enabled\":" +
                      boolToJson(readerEnabled) + "}");
        emitEvent("cashless_poll_ack",
                  String("{\"reader_enabled\":") + boolToJson(readerEnabled) +
                      ",\"begin_session_pending\":" +
                      boolToJson(beginSessionPending_) +
                      ",\"gateway_compat\":true}");
        break;
    }
    cashlessFastReplyHandled = true;
  }

  if (!coinCompatTailIgnored && !cashlessFastReplyHandled &&
      kMdbCoinChangerEnabled &&
      frame.normalizedLength == 1 &&
      frame.normalized[0] == kObservedCoinChangerPollByte) {
    const unsigned long pendingScaledBefore = coinChangerPendingScaled_;
    const bool justResetPendingBefore = coinChangerJustResetPending_;
    if (coinChangerAwaitingVmcScaled_ > 0 &&
        coinChangerLastCreditReplyTxUs_ > 0 &&
        frame.endedAtUs >= coinChangerLastCreditReplyTxUs_) {
      emitEvent("coin_reply_followup_poll_seen",
                String("{\"compat_mode\":true,\"rx_ts_us\":") +
                    frame.endedAtUs +
                    ",\"delta_us_from_last_credit_reply\":" +
                    (frame.endedAtUs - coinChangerLastCreditReplyTxUs_) +
                    ",\"awaiting_vmc_scaled\":" +
                    coinChangerAwaitingVmcScaled_ +
                    ",\"transaction_id\":\"" +
                    escapeForJson(coinChangerPendingTransactionId_) + "\"}");
    }
    const unsigned long firstTxUs =
        sendCoinChangerPollResponse("coin_poll_observed_compat", true);
    lastCoinCompatPollObservedUs_ = frame.endedAtUs;
    lastCoinCompatPollReplyTxUs_ = firstTxUs;
    coinCompatTailIgnoreUntilUs_ =
        frame.endedAtUs + kCoinCompatTailIgnoreWindowUs;
    emitEvent("coin_poll_observed_compat",
              String("{\"fast_path\":false,\"rx_ts_us\":") + frame.endedAtUs +
                  ",\"tx_ts_us\":" + firstTxUs +
                  ",\"pending_scaled_before_reply\":" + pendingScaledBefore +
                  ",\"remaining_scaled_after_reply\":" +
                  coinChangerPendingScaled_ +
                  ",\"just_reset_pending_before_reply\":" +
                  boolToJson(justResetPendingBefore) +
                  ",\"tail_ignore_until_us\":" +
                  coinCompatTailIgnoreUntilUs_ + "}");
    return;
  }

  bool directCoinHandled = false;
  if (!coinCompatTailIgnored && !cashlessFastReplyHandled && frame.checksumValid &&
      frame.hasCandidateAddress &&
      matchesCoinChangerDialogueAddress(frame.candidateAddress,
                                        frame.candidateCommand)) {
    directCoinHandled = handleCoinChangerCommand(frame, now, false);
  }

  bool directCashlessHandled = false;
  if (!coinCompatTailIgnored && !cashlessFastReplyHandled && !directCoinHandled &&
      frame.checksumValid &&
      frame.hasCandidateAddress &&
      matchesCashlessDialogueAddress(frame.candidateAddress,
                                     frame.candidateCommand)) {
    handleCashlessCommand(frame.candidateAddress, frame.candidateCommand, frame, now);
    directCashlessHandled = true;
  }

  bool mergedCashlessHandled = false;
  if (!coinCompatTailIgnored && !cashlessFastReplyHandled && !directCoinHandled &&
      !directCashlessHandled) {
    mergedCashlessHandled = tryHandleMergedCashlessFrame(frame, now);
  }

  if (!coinCompatTailIgnored && !cashlessFastReplyHandled && !directCoinHandled &&
      !directCashlessHandled && !mergedCashlessHandled) {
    handleCashlessCommand(frame.candidateAddress, frame.candidateCommand, frame, now);
  }

  if (!passiveSniffEnabled_) {
    return;
  }

  for (size_t i = 0; i < frame.length; ++i) {
    emitEvent("sniff_byte",
              String("{\"index\":") + i + ",\"raw\":" + frame.bytes[i].raw +
                  ",\"value7\":" + frame.bytes[i].value7 + ",\"high_bit\":" +
                  boolToJson(frame.bytes[i].highBit) + ",\"ts_ms\":" +
                  frame.bytes[i].tsMs + ",\"gap_before_ms\":" +
                  frame.bytes[i].gapBeforeMs + "}");
  }

  emitEvent("sniff_frame_raw",
            String("{\"raw_hex\":\"") + machine::rawHex(frame) +
                "\",\"frame_start_ms\":" + frame.startedAtMs +
                ",\"frame_end_ms\":" + frame.endedAtMs +
                ",\"frame_gap_before_ms\":" + frame.frameGapBeforeMs +
                ",\"frame_gap_after_ms\":" + frame.frameGapAfterMs +
                ",\"end_reason\":\"" + endReasonToString(frame.endReasonCode) +
                "\",\"end_reason_code\":" + frame.endReasonCode +
                ",\"frame_capture_quality\":" + frame.captureQuality +
                ",\"maybe_partial\":" + boolToJson(frame.maybePartial) +
                ",\"maybe_merged\":" + boolToJson(frame.maybeMerged) +
                ",\"truncated\":" + boolToJson(frame.truncated) +
                ",\"continuation_attempted\":" +
                boolToJson(frame.continuationAttempted) +
                ",\"continuation_wait_started_ms\":" +
                frame.continuationWaitStartedMs +
                ",\"continuation_wait_ms\":" + frame.continuationWaitMs +
                ",\"continuation_appended_bytes\":" +
                frame.continuationAppendedBytes +
                ",\"continuation_result\":\"" +
                continuationResultToString(frame.continuationResultCode) +
                "\",\"continuation_fail_reason\":\"" +
                continuationFailReasonToString(
                    frame.continuationFailReasonCode) +
                "\",\"reboot_gap_detected\":" +
                boolToJson(frame.rebootGapDetected) +
                ",\"session_break_gap_detected\":" +
                boolToJson(frame.sessionBreakGapDetected) + "}");

  emitEvent("sniff_frame_normalized",
            String("{\"normalized_hex\":\"") + machine::normalizedHex(frame) +
                "\",\"length\":" + frame.length + ",\"has_high_bit\":" +
                boolToJson(frame.hasHighBit) + "}");

  const SniffFrameRecord& record =
      sniffHistory_[(sniffHistoryNext_ + kSniffHistorySize - 1) % kSniffHistorySize];
  for (size_t s = 0; s < kStrategyCount; ++s) {
    const StrategyView& view = record.strategies[s];
    emitEvent("sniff_command_candidate",
              String("{\"strategy\":\"") + view.name + "\",\"strategy_hex\":\"" +
                  bytesToHex(view.bytes, view.length) + "\",\"candidate_address\":" +
                  (view.hasCandidateAddress ? String(view.candidateAddress) : String(-1)) +
                  ",\"candidate_command\":" +
                  (view.hasCandidateAddress ? String(view.candidateCommand) : String(-1)) +
                  ",\"checksum_valid\":" + boolToJson(view.checksumValid) +
                  ",\"parse_ok\":" + boolToJson(view.parseOk) +
                  ",\"plausible\":" + boolToJson(view.plausible) +
                  ",\"confidence\":"
                  + view.confidence + "}");
    if (view.checksumValid) {
      checksumPassCount_++;
      emitEvent("checksum_pass",
                String("{\"strategy\":\"") + view.name + "\",\"hex\":\"" +
                    bytesToHex(view.bytes, view.length) + "\",\"candidate_address\":" +
                    view.candidateAddress + ",\"candidate_command\":" +
                    view.candidateCommand + "}");
    } else {
      checksumFailCount_++;
      emitEvent("checksum_fail",
                String("{\"strategy\":\"") + view.name + "\",\"hex\":\"" +
                    bytesToHex(view.bytes, view.length) + "\",\"candidate_address\":" +
                    (view.hasCandidateAddress ? String(view.candidateAddress) : String(-1)) +
                    ",\"candidate_command\":" +
                    (view.hasCandidateAddress ? String(view.candidateCommand) : String(-1)) + "}");
    }
  }
}

bool MdbService::handleCoinChangerCommand(const machine::Frame& frame,
                                          unsigned long now,
                                          bool fastPath) {
  if (!frame.checksumValid || !frame.hasCandidateAddress ||
      !matchesCoinChangerDialogueAddress(frame.candidateAddress,
                                        frame.candidateCommand)) {
    return false;
  }

  switch (frame.candidateCommand) {
    case kCoinChangerResetCommand: {
      requeueCoinChangerAwaitingAcceptance("vmc_coin_reset");
      resetCoinChangerProtocolState(true);
      sendAckRaw("coin_reset_ack");
      emitEvent("coin_reset_seen",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"fast_path\":" + boolToJson(fastPath) +
                    ",\"queued_payment\":" +
                    boolToJson(coinChangerPendingScaled_ > 0) + "}");
      stateDirty_ = true;
      return true;
    }

    case kCoinChangerSetupCommand: {
      const unsigned long firstTxUs =
          sendCoinChangerSetupResponse("coin_setup_response");
      emitEvent("coin_setup_response",
                String("{\"timestamp_us\":") + firstTxUs +
                    ",\"fast_path\":" + boolToJson(fastPath) +
                    ",\"feature_level\":" +
                    static_cast<unsigned int>(kMdbCoinChangerFeatureLevel) +
                    ",\"currency_code\":\"" +
                    escapeForJson(byteToHex(kMdbCoinChangerCurrencyCountryCodeHi) +
                                  " " +
                                  byteToHex(kMdbCoinChangerCurrencyCountryCodeLo)) +
                    "\",\"scale_factor\":" +
                    static_cast<unsigned int>(kMdbCoinChangerScalingFactor) +
                    ",\"decimal_places\":" +
                    static_cast<unsigned int>(kMdbCoinChangerDecimalPlaces) +
                    ",\"routing_mask_hex\":\"" +
                    escapeForJson(byteToHex(
                                      static_cast<uint8_t>(
                                          (kMdbCoinChangerRoutingMask >> 8) & 0xFFU)) +
                                  " " +
                                  byteToHex(static_cast<uint8_t>(
                                      kMdbCoinChangerRoutingMask & 0xFFU))) +
                    "\"}");
      return true;
    }

    case kCoinChangerTubeStatusCommand: {
      const unsigned long firstTxUs =
          sendCoinChangerTubeStatusResponse("coin_tube_status");
      emitEvent("coin_tube_status_response",
                String("{\"timestamp_us\":") + firstTxUs +
                    ",\"fast_path\":" + boolToJson(fastPath) + "}");
      return true;
    }

    case kCoinChangerPollCommand:
      if (coinChangerAwaitingVmcScaled_ > 0 &&
          coinChangerLastCreditReplyTxUs_ > 0 &&
          frame.endedAtUs >= coinChangerLastCreditReplyTxUs_) {
        emitEvent("coin_reply_followup_poll_seen",
                  String("{\"compat_mode\":false,\"rx_ts_us\":") +
                      frame.endedAtUs +
                      ",\"delta_us_from_last_credit_reply\":" +
                      (frame.endedAtUs - coinChangerLastCreditReplyTxUs_) +
                      ",\"awaiting_vmc_scaled\":" +
                      coinChangerAwaitingVmcScaled_ +
                      ",\"transaction_id\":\"" +
                      escapeForJson(coinChangerPendingTransactionId_) + "\"}");
      }
      sendCoinChangerPollResponse("coin_poll_response", false);
      return true;

    case kCoinChangerCoinTypeCommand: {
      if (frame.normalizedLength >= 6) {
        coinChangerEnabledMask_ =
            static_cast<uint16_t>((frame.normalized[1] << 8) |
                                  frame.normalized[2]);
        coinChangerManualDispenseMask_ =
            static_cast<uint16_t>((frame.normalized[3] << 8) |
                                  frame.normalized[4]);
        stateDirty_ = true;
      }
      sendAckRaw("coin_type_ack");
      emitEvent("coin_authorized_in_vmc",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"basis\":\"coin_type_ack_sent\",\"fast_path\":" +
                    boolToJson(fastPath) + "}");
      emitEvent("coin_type_configured",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"fast_path\":" + boolToJson(fastPath) +
                    ",\"enable_mask_hex\":\"" +
                    escapeForJson(
                        byteToHex(static_cast<uint8_t>(coinChangerEnabledMask_ >> 8)) +
                        " " +
                        byteToHex(static_cast<uint8_t>(coinChangerEnabledMask_ & 0xFFU))) +
                    "\",\"manual_dispense_mask_hex\":\"" +
                    escapeForJson(
                        byteToHex(static_cast<uint8_t>(coinChangerManualDispenseMask_ >> 8)) +
                        " " +
                        byteToHex(static_cast<uint8_t>(
                            coinChangerManualDispenseMask_ & 0xFFU))) +
                    "\"}");
      return true;
    }

    case kCoinChangerDispenseCommand: {
      const uint8_t dispense = frame.normalizedLength >= 2 ? frame.normalized[1] : 0;
      sendAckRaw("coin_dispense_ack");
      emitEvent("coin_dispense_ignored",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"fast_path\":" + boolToJson(fastPath) +
                    ",\"count\":" + static_cast<unsigned int>(dispense >> 4) +
                    ",\"coin_type\":" +
                    static_cast<unsigned int>(dispense & 0x0FU) + "}");
      return true;
    }

    case kCoinChangerExpansionCommand: {
      const uint8_t subcommand =
          frame.normalizedLength >= 2 ? frame.normalized[1]
                                      : kCoinChangerExpansionIdSubcommand;
      if (subcommand == kCoinChangerExpansionIdSubcommand) {
        const unsigned long firstTxUs =
            sendCoinChangerExpansionIdResponse("coin_expansion_response");
        emitEvent("coin_expansion_response",
                  String("{\"timestamp_us\":") + firstTxUs +
                      ",\"fast_path\":" + boolToJson(fastPath) +
                      ",\"manufacturer\":\"" +
                      escapeForJson(String(kMdbCoinChangerManufacturer)) +
                      "\",\"model\":\"" +
                      escapeForJson(String(kMdbCoinChangerModel)) + "\"}");
        return true;
      }
      if (subcommand == kCoinChangerExpansionFeatureEnableSubcommand) {
        if (frame.normalizedLength >= 7) {
          coinChangerFeatureEnableMask_ =
              (static_cast<uint32_t>(frame.normalized[2]) << 24) |
              (static_cast<uint32_t>(frame.normalized[3]) << 16) |
              (static_cast<uint32_t>(frame.normalized[4]) << 8) |
              static_cast<uint32_t>(frame.normalized[5]);
          stateDirty_ = true;
        }
        sendAckRaw("coin_expansion_feature_ack");
        emitEvent("coin_expansion_feature_enable",
                  String("{\"timestamp_us\":") + frame.endedAtUs +
                      ",\"fast_path\":" + boolToJson(fastPath) +
                      ",\"feature_mask\":" + coinChangerFeatureEnableMask_ + "}");
        return true;
      }
      if (subcommand == kCoinChangerExpansionDiagStatusSubcommand) {
        const unsigned long firstTxUs =
            sendCoinChangerDiagnosticStatusResponse("coin_diag_status");
        emitEvent("coin_diag_status_response",
                  String("{\"timestamp_us\":") + firstTxUs +
                      ",\"fast_path\":" + boolToJson(fastPath) + "}");
        return true;
      }
      sendAckRaw("coin_expansion_ack");
      emitEvent("coin_expansion_ignored",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"fast_path\":" + boolToJson(fastPath) +
                    ",\"subcommand\":" +
                    static_cast<unsigned int>(subcommand) + "}");
      return true;
    }

    default:
      break;
  }

  (void)now;
  return false;
}

// Обрабатывает cashless-команду, адресованную текущему устройству.
void MdbService::handleCashlessCommand(uint8_t address, uint8_t command,
                                       const machine::Frame& frame,
                                       unsigned long now) {
  if (!matchesCashlessDialogueAddress(address, command)) {
    return;
  }

  observeCreditFlowFrame(frame, now);

  const bool handledLevel1 = handleLevel1CashlessFrame(frame, now);
  emitEvent("cashless_raw_selected",
            String("{\"raw_bytes\":\"") + machine::rawHex(frame) +
                "\",\"normalized_bytes\":\"" + machine::normalizedHex(frame) +
                "\",\"candidate_address\":" + address +
                ",\"candidate_command\":" + command +
                ",\"cashless_address\":" +
                static_cast<unsigned int>(cashlessAddress_) +
                ",\"length\":" + frame.normalizedLength +
                ",\"handled_level1\":" + boolToJson(handledLevel1) + "}");

  if (handledLevel1) {
    return;
  }

  if (!passiveSniffEnabled_ || sniffHistoryCount_ == 0) {
    return;
  }

  const SniffFrameRecord& record =
      sniffHistory_[(sniffHistoryNext_ + kSniffHistorySize - 1) % kSniffHistorySize];
  int bestStrategy = -1;
  uint8_t bestConfidence = 0;
  for (size_t s = 0; s < kStrategyCount; ++s) {
    const StrategyView& view = record.strategies[s];
    if (!view.plausible) {
      continue;
    }
    if (view.confidence >= bestConfidence) {
      bestConfidence = view.confidence;
      bestStrategy = static_cast<int>(s);
    }
  }

  if (bestStrategy < 0) {
    invalidFrameCount_++;
    emitEvent("ambiguous_frame",
              String("{\"raw_hex\":\"") + machine::rawHex(frame) +
                  "\",\"normalized_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"reason\":\"no_plausible_strategy\"}");
    return;
  }

  const StrategyView& view = record.strategies[bestStrategy];
  String json = String("{\"strategy_used\":\"") + view.name +
                "\",\"raw_bytes\":\"" + machine::rawHex(frame) +
                "\",\"normalized_bytes\":\"" + bytesToHex(view.bytes, view.length) +
                "\",\"candidate_address\":" + view.candidateAddress +
                ",\"candidate_command\":" + view.candidateCommand +
                ",\"expected_address\":" + expectedAddress_ +
                ",\"checksum_valid\":" + boolToJson(view.checksumValid) +
                ",\"looks_like_poll\":" + boolToJson(frame.looksLikePoll) +
                ",\"looks_like_command\":" + boolToJson(frame.looksLikeCommand) +
                ",\"strategy_confidence\":" + view.confidence;

  if (expectedAddress_ >= 0 &&
      view.candidateAddress == static_cast<uint8_t>(expectedAddress_)) {
    expectedMatchCount_++;
    emitEvent("expected_address_match", json + "}");
    emitEvent("potential_our_command", json + "}");
    handleExperimentTrigger(view, frame, now);
    observeExperimentFrame(view, now);
    return;
  }

  if (expectedAddress_ >= 0) {
    foreignFrameCount_++;
    emitEvent("foreign_command", json + "}");
    observeExperimentFrame(view, now);
    return;
  }

  ambiguousFrameCount_++;
  emitEvent("sniff_command", json + "}");
  observeExperimentFrame(view, now);
}

bool MdbService::frameStartsWith(const machine::Frame& frame, uint8_t firstByte,
                                 int secondByte, int thirdByte) const {
  if (frame.normalizedLength == 0 || frame.normalized[0] != firstByte) {
    return false;
  }
  if (secondByte >= 0 &&
      (frame.normalizedLength < 2 ||
       frame.normalized[1] != static_cast<uint8_t>(secondByte))) {
    return false;
  }
  if (thirdByte >= 0 &&
      (frame.normalizedLength < 3 ||
       frame.normalized[2] != static_cast<uint8_t>(thirdByte))) {
    return false;
  }
  return true;
}

uint8_t MdbService::cashlessCommandByte(uint8_t command) const {
  return static_cast<uint8_t>(((cashlessAddress_ & 0x1FU) << 3) |
                              (command & 0x07U));
}

bool MdbService::shouldTrackCashlessSplitPrefix(const machine::Frame& frame) const {
  if (!kMdbCashlessEnabled) {
    return false;
  }
  if (frame.length != 1 || !frame.hasCandidateAddress || !frame.hasHighBit ||
      !frame.bytes[0].highBit ||
      !matchesCashlessDialogueAddress(frame.candidateAddress,
                                      frame.candidateCommand)) {
    return false;
  }

  return frame.candidateCommand == kCashlessSetupCommand ||
         frame.candidateCommand == kCashlessExpansionCommand ||
         frame.candidateCommand == kCashlessReaderControlCommand;
}

bool MdbService::tryBuildCashlessSplitFrame(const machine::Frame& payloadFrame,
                                           machine::Frame& combined) const {
  if (!kMdbCashlessEnabled) {
    return false;
  }
  if (!pendingCashlessSplitPrefixActive_ ||
      pendingCashlessSplitPrefixFrame_.length != 1 ||
      !pendingCashlessSplitPrefixFrame_.bytes[0].highBit ||
      payloadFrame.length == 0 || payloadFrame.bytes[0].highBit ||
      payloadFrame.startedAtUs <= pendingCashlessSplitPrefixFrame_.endedAtUs ||
      (payloadFrame.startedAtUs - pendingCashlessSplitPrefixFrame_.endedAtUs) >
          kCashlessSplitContinuationWindowUs) {
    return false;
  }

  const size_t combinedLength =
      pendingCashlessSplitPrefixFrame_.length + payloadFrame.length;
  if (combinedLength > machine::kMaxFrameBytes) {
    return false;
  }

  machine::RawByte raw[machine::kMaxFrameBytes] = {};
  size_t outIndex = 0;
  for (size_t i = 0; i < pendingCashlessSplitPrefixFrame_.length; ++i) {
    raw[outIndex++] = pendingCashlessSplitPrefixFrame_.bytes[i];
  }
  for (size_t i = 0; i < payloadFrame.length; ++i) {
    raw[outIndex++] = payloadFrame.bytes[i];
  }

  machine::buildFrame(raw, combinedLength, combined);
  combined.finalizedAtUs = payloadFrame.finalizedAtUs;
  combined.frameGapBeforeMs = pendingCashlessSplitPrefixFrame_.frameGapBeforeMs;
  combined.frameGapAfterMs = payloadFrame.frameGapAfterMs;
  combined.truncated =
      pendingCashlessSplitPrefixFrame_.truncated || payloadFrame.truncated;
  combined.endReasonCode = payloadFrame.endReasonCode;
  combined.continuationAttempted = payloadFrame.continuationAttempted;
  combined.continuationWaitStartedMs = payloadFrame.continuationWaitStartedMs;
  combined.continuationWaitMs = payloadFrame.continuationWaitMs;
  combined.continuationAppendedBytes = payloadFrame.continuationAppendedBytes;
  combined.continuationResultCode = payloadFrame.continuationResultCode;
  combined.continuationFailReasonCode = payloadFrame.continuationFailReasonCode;
  combined.rebootGapDetected = pendingCashlessSplitPrefixFrame_.rebootGapDetected ||
                               payloadFrame.rebootGapDetected;
  combined.sessionBreakGapDetected =
      pendingCashlessSplitPrefixFrame_.sessionBreakGapDetected ||
      payloadFrame.sessionBreakGapDetected;

  return combined.checksumValid && combined.hasCandidateAddress &&
         matchesCashlessDialogueAddress(combined.candidateAddress,
                                        combined.candidateCommand);
}

void MdbService::clearPendingCashlessSplitPrefix() {
  pendingCashlessSplitPrefixActive_ = false;
  pendingCashlessSplitPrefixFrame_ = {};
  pendingCashlessSplitPrefixCapturedAtMs_ = 0;
}

void MdbService::appendObservedRawStatusByte(uint8_t value, bool ninthBit,
                                             unsigned long tsUs) {
  if (!kMdbCashlessEnabled) {
    return;
  }
  if (observedRawStatusLength_ >= kObservedRawStatusWindowBytes) {
    const size_t keep = kObservedRawStatusWindowBytes - 1;
    for (size_t i = 0; i < keep; ++i) {
      observedRawStatusBytes_[i] = observedRawStatusBytes_[i + 1];
    }
    observedRawStatusLength_ = keep;
  }

  machine::RawByte& raw = observedRawStatusBytes_[observedRawStatusLength_++];
  raw = {};
  raw.raw = value;
  raw.value7 = value;
  raw.highBit = ninthBit;
  raw.tsUs = tsUs;
  raw.tsMs = tsUs / 1000UL;
  raw.gapBeforeMs =
      observedRawStatusLength_ == 1
          ? 0
          : (raw.tsMs - observedRawStatusBytes_[observedRawStatusLength_ - 2].tsMs);

  auto tryDispatchGatewaySetupCompatFromTail = [&](size_t patternLength,
                                                   bool insertedMissingZero) -> bool {
    if (observedRawStatusLength_ < patternLength) {
      return false;
    }

    const size_t start = observedRawStatusLength_ - patternLength;
    if (!observedRawStatusBytes_[start].highBit ||
        !observedRawStatusBytes_[observedRawStatusLength_ - 1].highBit) {
      return false;
    }
    if (observedRawStatusBytes_[observedRawStatusLength_ - 1].tsUs <
            observedRawStatusBytes_[start].tsUs ||
        (observedRawStatusBytes_[observedRawStatusLength_ - 1].tsUs -
         observedRawStatusBytes_[start].tsUs) >
            kObservedGatewaySetupCompatWindowUs) {
      return false;
    }

    const uint8_t setupCommand = cashlessCommandByte(kCashlessSetupCommand);
    const uint8_t syntheticValues[5] = {
        setupCommand, kObservedGatewaySetupPayload1, kObservedGatewaySetupPayload2,
        kObservedGatewaySetupPayload3,
        static_cast<uint8_t>(setupCommand + kObservedGatewaySetupPayload1 +
                             kObservedGatewaySetupPayload2 +
                             kObservedGatewaySetupPayload3)};
    machine::RawByte synthetic[5] = {};
    for (size_t i = 0; i < 5; ++i) {
      synthetic[i].raw = syntheticValues[i];
      synthetic[i].value7 = syntheticValues[i];
      synthetic[i].highBit = (i == 0);
      synthetic[i].tsUs = tsUs;
      synthetic[i].tsMs = tsUs / 1000UL;
      synthetic[i].gapBeforeMs = 0;
    }

    machine::Frame assumedFrame;
    machine::buildFrame(synthetic, 5, assumedFrame);
    if (!assumedFrame.checksumValid || !assumedFrame.hasCandidateAddress ||
        assumedFrame.candidateAddress != cashlessAddress_ ||
        assumedFrame.candidateCommand != kCashlessSetupCommand) {
      emitEvent("cashless_synthetic_frame_rejected",
                String("{\"frame_hex\":\"") + bytesToHex(syntheticValues, 5) +
                    "\",\"parse_ok\":" + boolToJson(assumedFrame.parseOk) +
                    ",\"checksum_valid\":" + boolToJson(assumedFrame.checksumValid) +
                    ",\"has_candidate_address\":" +
                    boolToJson(assumedFrame.hasCandidateAddress) +
                    ",\"candidate_address\":" + assumedFrame.candidateAddress +
                    ",\"candidate_command\":" + assumedFrame.candidateCommand +
                    ",\"cashless_address\":" +
                    static_cast<unsigned int>(cashlessAddress_) + "}");
      return false;
    }

    String observedHex = byteToHex(observedRawStatusBytes_[start].raw);
    for (size_t i = start + 1; i < observedRawStatusLength_; ++i) {
      observedHex += " ";
      observedHex += byteToHex(observedRawStatusBytes_[i].raw);
    }

    assumedFrame.finalizedAtUs = tsUs;
    assumedFrame.frameGapAfterMs = 0;
    const unsigned long now = millis();
    handleFastFrameObserved(assumedFrame, now);
    dispatchAcceptedFrame(assumedFrame, now, true);
    storeSniffFrame(assumedFrame);
    emitEvent("cashless_gateway_setup_compat",
              String("{\"observed_hex\":\"") + observedHex +
                  "\",\"synthetic_frame_hex\":\"" + bytesToHex(syntheticValues, 5) +
                  "\",\"inserted_missing_zero\":" +
                  boolToJson(insertedMissingZero) + "}");
    clearObservedRawStatusWindow();
    return true;
  };

  auto tryDispatchGatewayExpansionCompatFromTail = [&]() -> bool {
    if (observedRawStatusLength_ < 3) {
      return false;
    }

    const size_t start = observedRawStatusLength_ - 3;
    if (!observedRawStatusBytes_[start].highBit ||
        !observedRawStatusBytes_[observedRawStatusLength_ - 1].highBit) {
      return false;
    }
    if (observedRawStatusBytes_[start].raw != kObservedGatewayExpansionByte ||
        observedRawStatusBytes_[start + 1].raw !=
            kObservedGatewayExpansionPayload1 ||
        observedRawStatusBytes_[start + 2].raw !=
            kObservedGatewayExpansionChecksum) {
      return false;
    }
    if (observedRawStatusBytes_[observedRawStatusLength_ - 1].tsUs <
            observedRawStatusBytes_[start].tsUs ||
        (observedRawStatusBytes_[observedRawStatusLength_ - 1].tsUs -
         observedRawStatusBytes_[start].tsUs) >
            kObservedGatewaySetupCompatWindowUs) {
      return false;
    }

    const uint8_t setupCommand = cashlessCommandByte(kCashlessSetupCommand);
    const uint8_t syntheticValues[3] = {
        setupCommand, kCashlessSetupMaxMinSubcommand,
        static_cast<uint8_t>(setupCommand + kCashlessSetupMaxMinSubcommand)};
    machine::RawByte synthetic[3] = {};
    for (size_t i = 0; i < 3; ++i) {
      synthetic[i].raw = syntheticValues[i];
      synthetic[i].value7 = syntheticValues[i];
      synthetic[i].highBit = (i == 0);
      synthetic[i].tsUs = tsUs;
      synthetic[i].tsMs = tsUs / 1000UL;
      synthetic[i].gapBeforeMs = 0;
    }

    machine::Frame assumedFrame;
    machine::buildFrame(synthetic, 3, assumedFrame);
    if (!assumedFrame.checksumValid || !assumedFrame.hasCandidateAddress ||
        assumedFrame.candidateAddress != cashlessAddress_ ||
        assumedFrame.candidateCommand != kCashlessSetupCommand) {
      emitEvent("cashless_synthetic_frame_rejected",
                String("{\"frame_hex\":\"") + bytesToHex(syntheticValues, 3) +
                    "\",\"parse_ok\":" + boolToJson(assumedFrame.parseOk) +
                    ",\"checksum_valid\":" +
                    boolToJson(assumedFrame.checksumValid) +
                    ",\"has_candidate_address\":" +
                    boolToJson(assumedFrame.hasCandidateAddress) +
                    ",\"candidate_address\":" + assumedFrame.candidateAddress +
                    ",\"candidate_command\":" + assumedFrame.candidateCommand +
                    ",\"cashless_address\":" +
                    static_cast<unsigned int>(cashlessAddress_) + "}");
      return false;
    }

    assumedFrame.finalizedAtUs = tsUs;
    assumedFrame.frameGapAfterMs = 0;
    const unsigned long now = millis();
    handleFastFrameObserved(assumedFrame, now);
    dispatchAcceptedFrame(assumedFrame, now, true);
    storeSniffFrame(assumedFrame);
    emitEvent("cashless_gateway_expansion_compat",
              String("{\"observed_hex\":\"19 01 1A\",\"synthetic_frame_hex\":\"") +
                  bytesToHex(syntheticValues, 3) + "\"}");
    clearObservedRawStatusWindow();
    return true;
  };

  auto tryDispatchCompatResetSetupBurst = [&]() -> bool {
    const uint8_t resetByte = cashlessCommandByte(kCashlessResetCommand);
    const uint8_t setupCommand = cashlessCommandByte(kCashlessSetupCommand);
    if (observedRawStatusLength_ < 5) {
      return false;
    }

    for (size_t start = 0; (start + 4) < observedRawStatusLength_; ++start) {
      if (!observedRawStatusBytes_[start].highBit ||
          observedRawStatusBytes_[start].raw != resetByte ||
          observedRawStatusBytes_[start + 1].raw != kObservedGatewaySetupByte ||
          observedRawStatusBytes_[start + 2].raw != kObservedGatewaySetupPayload1 ||
          observedRawStatusBytes_[start + 3].raw != kObservedGatewaySetupPayload2) {
        continue;
      }

      size_t checksumIndex = start + 4;
      bool insertedMissingZero = true;
      if (observedRawStatusBytes_[start + 3].raw == kObservedGatewaySetupPayload3) {
        continue;
      }
      if (observedRawStatusBytes_[checksumIndex].raw == kObservedGatewaySetupPayload3) {
        insertedMissingZero = false;
        checksumIndex = start + 5;
        if (checksumIndex >= observedRawStatusLength_) {
          continue;
        }
      }
      if (observedRawStatusBytes_[checksumIndex].raw != kObservedGatewaySetupChecksum) {
        continue;
      }

      if (observedRawStatusBytes_[checksumIndex].tsUs <
              observedRawStatusBytes_[start].tsUs ||
          (observedRawStatusBytes_[checksumIndex].tsUs -
           observedRawStatusBytes_[start].tsUs) >
              kObservedGatewaySetupCompatWindowUs) {
        continue;
      }

      bool discardedTail = false;
      for (size_t i = checksumIndex + 1; i < observedRawStatusLength_; ++i) {
        if (isCompatBurstNoiseTailByte(observedRawStatusBytes_[i].raw)) {
          discardedTail = true;
        }
      }

      String observedHex = byteToHex(observedRawStatusBytes_[start].raw);
      for (size_t i = start + 1; i < observedRawStatusLength_; ++i) {
        observedHex += " ";
        observedHex += byteToHex(observedRawStatusBytes_[i].raw);
      }

      String gatewayObservedHex = byteToHex(observedRawStatusBytes_[start + 1].raw);
      for (size_t i = start + 2; i <= checksumIndex; ++i) {
        gatewayObservedHex += " ";
        gatewayObservedHex += byteToHex(observedRawStatusBytes_[i].raw);
      }

      const unsigned long now = millis();
      const unsigned long firstTxUs = sendAckRaw("compat_reset_ack");
      markSetupResponseAckMissing("reset_before_ack",
                                  String("\"frame_hex\":\"") +
                                      escapeForJson(observedHex) + "\"");
      isReaderEnabled_ = false;
      beginSessionPending_ = false;
      beginSessionAmountMinor_ = 0;
      cashlessJustResetPending_ = true;
      cashlessSetupSeen_ = false;
      cashlessSetupResponsePending_ = false;
      cashlessExpansionSeen_ = false;
      session_.onReaderDisabled(now);
      stateDirty_ = true;

      const uint8_t syntheticValues[5] = {
          setupCommand, kObservedGatewaySetupPayload1,
          kObservedGatewaySetupPayload2, kObservedGatewaySetupPayload3,
          static_cast<uint8_t>(setupCommand + kObservedGatewaySetupPayload1 +
                               kObservedGatewaySetupPayload2 +
                               kObservedGatewaySetupPayload3)};
      machine::RawByte synthetic[5] = {};
      for (size_t i = 0; i < 5; ++i) {
        synthetic[i].raw = syntheticValues[i];
        synthetic[i].value7 = syntheticValues[i];
        synthetic[i].highBit = (i == 0);
        synthetic[i].tsUs = tsUs;
        synthetic[i].tsMs = tsUs / 1000UL;
        synthetic[i].gapBeforeMs = 0;
      }

      machine::Frame assumedFrame;
      machine::buildFrame(synthetic, 5, assumedFrame);
      if (!assumedFrame.checksumValid || !assumedFrame.hasCandidateAddress ||
          assumedFrame.candidateAddress != cashlessAddress_ ||
          assumedFrame.candidateCommand != kCashlessSetupCommand) {
        emitEvent("cashless_synthetic_frame_rejected",
                  String("{\"frame_hex\":\"") + bytesToHex(syntheticValues, 5) +
                      "\",\"parse_ok\":" +
                      boolToJson(assumedFrame.parseOk) +
                      ",\"checksum_valid\":" +
                      boolToJson(assumedFrame.checksumValid) +
                      ",\"has_candidate_address\":" +
                      boolToJson(assumedFrame.hasCandidateAddress) +
                      ",\"candidate_address\":" + assumedFrame.candidateAddress +
                      ",\"candidate_command\":" + assumedFrame.candidateCommand +
                      ",\"cashless_address\":" +
                      static_cast<unsigned int>(cashlessAddress_) + "}");
        emitEvent("ACK_SENT",
                  String("{\"trigger\":\"compat_burst_reset\","
                         "\"tx_ts_us\":") +
                      firstTxUs + "}");
        emitEvent("cashless_reset_received",
                  String("{\"cashless_address\":") +
                      static_cast<unsigned int>(cashlessAddress_) +
                      ",\"just_reset_pending\":true,\"compat_burst\":true}");
        emitEvent("mdb_compat_burst_detected",
                  String("{\"observed_hex\":\"") + observedHex +
                      "\",\"gateway_observed_hex\":\"" + gatewayObservedHex +
                      "\",\"synthetic_frame_hex\":\"" +
                      bytesToHex(syntheticValues, 5) +
                      "\",\"virtual_reset_ack_tx_ts_us\":" + firstTxUs +
                      ",\"inserted_missing_zero\":" +
                      boolToJson(insertedMissingZero) +
                      ",\"discarded_tail\":" + boolToJson(discardedTail) +
                      ",\"setup_dispatched\":false}");
        clearPendingCashlessSplitPrefix();
        clearObservedRawStatusWindow();
        gatewaySetupCompatStage_ = 0;
        gatewaySetupCompatStartedUs_ = 0;
        gatewaySetupCompatSawExplicitZero_ = false;
        return true;
      }

      assumedFrame.finalizedAtUs = tsUs;
      assumedFrame.frameGapAfterMs = 0;
      storeSniffFrame(assumedFrame);
      dispatchAcceptedFrame(assumedFrame, now, true);
      cashlessJustResetPending_ = true;
      emitEvent("ACK_SENT",
                String("{\"trigger\":\"compat_burst_reset\","
                       "\"tx_ts_us\":") +
                    firstTxUs + "}");
      emitEvent("cashless_reset_received",
                String("{\"cashless_address\":") +
                    static_cast<unsigned int>(cashlessAddress_) +
                    ",\"just_reset_pending\":true,\"compat_burst\":true}");
      emitEvent("mdb_compat_burst_detected",
                String("{\"observed_hex\":\"") + observedHex +
                    "\",\"gateway_observed_hex\":\"" + gatewayObservedHex +
                    "\",\"synthetic_frame_hex\":\"" +
                    bytesToHex(syntheticValues, 5) +
                    "\",\"virtual_reset_ack_tx_ts_us\":" + firstTxUs +
                    ",\"inserted_missing_zero\":" +
                    boolToJson(insertedMissingZero) +
                    ",\"discarded_tail\":" + boolToJson(discardedTail) +
                    ",\"setup_dispatched\":true}");
      emitEvent("cashless_gateway_setup_compat",
                String("{\"observed_hex\":\"") + gatewayObservedHex +
                    "\",\"synthetic_frame_hex\":\"" +
                    bytesToHex(syntheticValues, 5) +
                    "\",\"inserted_missing_zero\":" +
                    boolToJson(insertedMissingZero) +
                    ",\"compat_burst\":true}");
      clearObservedRawStatusWindow();
      gatewaySetupCompatStage_ = 0;
      gatewaySetupCompatStartedUs_ = 0;
      gatewaySetupCompatSawExplicitZero_ = false;
      return true;
    }

    return false;
  };

  if (tryDispatchCompatResetSetupBurst()) {
    return;
  }

  if (observedRawStatusLength_ >= 4) {
    const size_t start4 = observedRawStatusLength_ - 4;
    if (observedRawStatusBytes_[start4].raw == kObservedGatewaySetupByte &&
        observedRawStatusBytes_[start4 + 1].raw == kObservedGatewaySetupPayload1 &&
        observedRawStatusBytes_[start4 + 2].raw == kObservedGatewaySetupPayload2 &&
        observedRawStatusBytes_[start4 + 3].raw == kObservedGatewaySetupChecksum &&
        tryDispatchGatewaySetupCompatFromTail(4, true)) {
      return;
    }
  }

  if (observedRawStatusLength_ >= 5) {
    const size_t start5 = observedRawStatusLength_ - 5;
    if (observedRawStatusBytes_[start5].raw == kObservedGatewaySetupByte &&
        observedRawStatusBytes_[start5 + 1].raw == kObservedGatewaySetupPayload1 &&
        observedRawStatusBytes_[start5 + 2].raw == kObservedGatewaySetupPayload2 &&
        observedRawStatusBytes_[start5 + 3].raw == kObservedGatewaySetupPayload3 &&
        observedRawStatusBytes_[start5 + 4].raw == kObservedGatewaySetupChecksum &&
        tryDispatchGatewaySetupCompatFromTail(5, false)) {
      return;
    }
  }

  if (tryDispatchGatewayExpansionCompatFromTail()) {
    return;
  }

  if (tryHandleObservedRawStatusWindow(tsUs)) {
    return;
  }
}

bool MdbService::tryHandleObservedRawStatusWindow(unsigned long tsUs) {
  if (!kMdbCashlessEnabled) {
    return false;
  }
  if (observedRawStatusLength_ < 2) {
    return false;
  }

  const unsigned long now = millis();
  auto dispatchSyntheticObservedFrame =
      [&](const uint8_t* values, size_t valueCount, const char* eventName,
          const String& details) -> bool {
    machine::RawByte synthetic[machine::kMaxFrameBytes] = {};
    for (size_t i = 0; i < valueCount; ++i) {
      synthetic[i].raw = values[i];
      synthetic[i].value7 = values[i];
      synthetic[i].highBit = (i == 0);
      synthetic[i].tsUs = tsUs;
      synthetic[i].tsMs = tsUs / 1000UL;
      synthetic[i].gapBeforeMs = 0;
    }

    machine::Frame assumedFrame;
    machine::buildFrame(synthetic, valueCount, assumedFrame);
    if (!assumedFrame.checksumValid || !assumedFrame.hasCandidateAddress ||
        assumedFrame.candidateAddress != cashlessAddress_ ||
        assumedFrame.candidateCommand != kCashlessSetupCommand) {
      emitEvent("cashless_synthetic_frame_rejected",
                String("{\"frame_hex\":\"") + bytesToHex(values, valueCount) +
                    "\",\"parse_ok\":" + boolToJson(assumedFrame.parseOk) +
                    ",\"checksum_valid\":" + boolToJson(assumedFrame.checksumValid) +
                    ",\"has_candidate_address\":" +
                    boolToJson(assumedFrame.hasCandidateAddress) +
                    ",\"candidate_address\":" + assumedFrame.candidateAddress +
                    ",\"candidate_command\":" + assumedFrame.candidateCommand +
                    ",\"cashless_address\":" +
                    static_cast<unsigned int>(cashlessAddress_) + "}");
      return false;
    }

    assumedFrame.finalizedAtUs = tsUs;
    assumedFrame.frameGapAfterMs = 0;
    handleFastFrameObserved(assumedFrame, now);
    dispatchAcceptedFrame(assumedFrame, now, true);
    storeSniffFrame(assumedFrame);
    emitEvent(eventName, details);
    clearObservedRawStatusWindow();
    return true;
  };
  for (size_t start = 0; start < observedRawStatusLength_; ++start) {
    if (!observedRawStatusBytes_[start].highBit) {
      continue;
    }

    for (size_t length = 2; (start + length) <= observedRawStatusLength_; ++length) {
      machine::Frame frame;
    machine::buildFrame(&observedRawStatusBytes_[start], length, frame);
    if (!frame.checksumValid || !frame.hasCandidateAddress ||
        !matchesCashlessDialogueAddress(frame.candidateAddress,
                                        frame.candidateCommand)) {
      continue;
    }

      const bool isCashlessDialogueFamily =
          frame.candidateCommand == kCashlessResetCommand ||
          frame.candidateCommand == kCashlessPollCommand ||
          frame.candidateCommand == kCashlessSetupCommand ||
          frame.candidateCommand == kCashlessExpansionCommand ||
          frame.candidateCommand == kCashlessReaderControlCommand;
      if (!isCashlessDialogueFamily) {
        continue;
      }

      frame.finalizedAtUs = tsUs;
      frame.frameGapAfterMs = 0;
      handleFastFrameObserved(frame, now);
      clearPendingCashlessSplitPrefix();
      dispatchAcceptedFrame(frame, now, false);
      storeSniffFrame(frame);
      emitEvent("cashless_raw_status_frame",
                String("{\"frame_hex\":\"") + machine::normalizedHex(frame) +
                    "\",\"candidate_address\":" + frame.candidateAddress +
                    ",\"candidate_command\":" + frame.candidateCommand +
                    ",\"length\":" + frame.normalizedLength +
                    ",\"handled\":true}");
      clearObservedRawStatusWindow();
      return true;
    }
  }

  const uint8_t setupCommand = cashlessCommandByte(kCashlessSetupCommand);
  const uint8_t assumedSetupByte1 = 0x03U;
  const uint8_t assumedSetupByte2 = 0x01U;
  const uint8_t assumedSetupByte3 = 0x00U;
  const uint8_t assumedSetupChecksum = static_cast<uint8_t>(
      setupCommand + assumedSetupByte1 + assumedSetupByte2 + assumedSetupByte3);
  for (size_t start = 0; (start + 1) < observedRawStatusLength_; ++start) {
    if (observedRawStatusBytes_[start].raw != setupCommand ||
        observedRawStatusBytes_[start + 1].raw != assumedSetupByte1) {
      continue;
    }

    for (size_t end = start + 2; end < observedRawStatusLength_; ++end) {
      if (observedRawStatusBytes_[end].raw != assumedSetupChecksum) {
        continue;
      }
      if (observedRawStatusBytes_[end].tsUs < observedRawStatusBytes_[start].tsUs ||
          (observedRawStatusBytes_[end].tsUs - observedRawStatusBytes_[start].tsUs) >
              kObservedGatewaySetupCompatWindowUs) {
        continue;
      }

      const uint8_t values[5] = {setupCommand, assumedSetupByte1, assumedSetupByte2,
                                 assumedSetupByte3, assumedSetupChecksum};
      if (dispatchSyntheticObservedFrame(
              values, 5, "cashless_partial_setup_assumed",
              String("{\"frame_hex\":\"") + bytesToHex(values, 5) +
                  "\",\"start_raw\":\"" + byteToHex(observedRawStatusBytes_[start].raw) +
                  "\",\"next_raw\":\"" + byteToHex(observedRawStatusBytes_[start + 1].raw) +
                  "\",\"end_raw\":\"" + byteToHex(observedRawStatusBytes_[end].raw) + "\"}")) {
        return true;
      }
    }
  }

  const uint8_t compatSetupValues[5] = {
      setupCommand, kObservedGatewaySetupPayload1, kObservedGatewaySetupPayload2,
      kObservedGatewaySetupPayload3,
      static_cast<uint8_t>(setupCommand + kObservedGatewaySetupPayload1 +
                           kObservedGatewaySetupPayload2 + kObservedGatewaySetupPayload3)};
  for (size_t start = 0; (start + 2) < observedRawStatusLength_; ++start) {
    if (observedRawStatusBytes_[start].raw != kObservedGatewaySetupByte ||
        observedRawStatusBytes_[start + 1].raw != kObservedGatewaySetupPayload1 ||
        observedRawStatusBytes_[start + 2].raw != kObservedGatewaySetupPayload2) {
      continue;
    }

    for (size_t end = start + 3; end < observedRawStatusLength_; ++end) {
      if (observedRawStatusBytes_[end].raw != kObservedGatewaySetupChecksum) {
        continue;
      }
      if (observedRawStatusBytes_[end].tsUs < observedRawStatusBytes_[start].tsUs ||
          (observedRawStatusBytes_[end].tsUs - observedRawStatusBytes_[start].tsUs) >
              (kCashlessSplitContinuationWindowUs * 2UL)) {
        continue;
      }

      bool sawExplicitZero = false;
      for (size_t middle = start + 3; middle < end; ++middle) {
        if (observedRawStatusBytes_[middle].raw == kObservedGatewaySetupPayload3) {
          sawExplicitZero = true;
          break;
        }
      }

      String observedHex = byteToHex(observedRawStatusBytes_[start].raw);
      for (size_t i = start + 1; i <= end; ++i) {
        observedHex += " ";
        observedHex += byteToHex(observedRawStatusBytes_[i].raw);
      }

      if (dispatchSyntheticObservedFrame(
              compatSetupValues, 5, "cashless_gateway_setup_compat",
              String("{\"observed_hex\":\"") + observedHex +
                  "\",\"synthetic_frame_hex\":\"" + bytesToHex(compatSetupValues, 5) +
                  "\",\"inserted_missing_zero\":" + boolToJson(!sawExplicitZero) + "}")) {
        return true;
      }
    }
  }

  return false;
}

bool MdbService::tryHandleMergedCashlessFrame(const machine::Frame& frame,
                                             unsigned long now) {
  if (!kMdbCashlessEnabled) {
    return false;
  }
  if (frame.length < 2 || !frame.hasHighBit) {
    return false;
  }

  size_t highBitStarts[machine::kMaxFrameBytes] = {};
  size_t highBitCount = 0;
  for (size_t i = 0; i < frame.length && highBitCount < machine::kMaxFrameBytes; ++i) {
    if (frame.bytes[i].highBit) {
      highBitStarts[highBitCount++] = i;
    }
  }

  if (highBitCount < 2 || highBitStarts[0] != 0) {
    return false;
  }

  bool handledAny = false;
  for (size_t i = 0; i < highBitCount; ++i) {
    const size_t start = highBitStarts[i];
    const size_t end = (i + 1 < highBitCount) ? highBitStarts[i + 1] : frame.length;
    if (end <= start) {
      continue;
    }

    machine::Frame subFrame;
    machine::buildFrame(&frame.bytes[start], end - start, subFrame);
    subFrame.finalizedAtUs = frame.finalizedAtUs;
    subFrame.frameGapBeforeMs = (start == 0) ? frame.frameGapBeforeMs : 0;
    subFrame.frameGapAfterMs = (end == frame.length) ? frame.frameGapAfterMs : 0;

    if (!subFrame.hasCandidateAddress ||
        !matchesCashlessDialogueAddress(subFrame.candidateAddress,
                                        subFrame.candidateCommand)) {
      continue;
    }

    handleCashlessCommand(subFrame.candidateAddress, subFrame.candidateCommand,
                          subFrame, now);
    emitEvent("cashless_merged_subframe",
              String("{\"frame_hex\":\"") + machine::normalizedHex(subFrame) +
                  "\",\"candidate_address\":" + subFrame.candidateAddress +
                  ",\"candidate_command\":" + subFrame.candidateCommand +
                  ",\"length\":" + subFrame.normalizedLength +
                  ",\"handled\":true}");
    handledAny = true;
  }

  return handledAny;
}

void MdbService::clearObservedRawStatusWindow() { observedRawStatusLength_ = 0; }

bool MdbService::handleLevel1CashlessFrame(const machine::Frame& frame,
                                           unsigned long now) {
  if (frame.normalizedLength == 0) {
    return false;
  }

  const bool isCashlessDialogue =
      frame.checksumValid && frame.hasCandidateAddress &&
      matchesCashlessDialogueAddress(frame.candidateAddress,
                                     frame.candidateCommand);
  const bool isCompactReaderControlEnableCompat =
      isCashlessDialogue &&
      frame.candidateCommand == kCashlessReaderControlCommand &&
      frame.normalizedLength == 1 &&
      (readerState_ == ReaderState::ExpansionPending ||
       readerState_ == ReaderState::Disabled);
  const bool isCashlessReset =
      isCashlessDialogue && frame.candidateCommand == kCashlessResetCommand;
  if (isCashlessReset) {
    const unsigned long ackPrepareUs = micros();
    const unsigned long deltaSinceSetupResponseUs =
        (lastSetupResponseTxUs_ > 0 && frame.endedAtUs >= lastSetupResponseTxUs_)
            ? (frame.endedAtUs - lastSetupResponseTxUs_)
            : 0;
    lastSetupResponseToResetUs_ = deltaSinceSetupResponseUs;
    lastResetCauseGuess_ =
        repeatedSetupSamePayloadCount_ > 0
            ? "reset_after_repeated_same_setup_retry"
            : (repeatedSetupCount_ > 0
                   ? "reset_after_setup_retry"
                   : (lastTxKind_ == "setup_response"
                          ? "reset_after_setup_response"
                          : "reset_without_prior_setup_retry"));
    repeatedSetupThenResetObserved_ = repeatedSetupCount_ > 0;
    if (repeatedSetupThenResetObserved_ && resetAfterSetupRetryCount_ < 0xFFFFU) {
      resetAfterSetupRetryCount_++;
    }
    resetSeenCount_++;
    lastResetTsUs_ = frame.endedAtUs;
    lastResetAckPreparedUs_ = ackPrepareUs;
    lastPollAfterResetTsUs_ = 0;
    lastJustResetSentUs_ = 0;
    lastNextRxAfterResetTsUs_ = 0;
    pollMissingAfterResetLogged_ = false;
    nextActionHypothesis_ = "vmc_should_poll_for_just_reset_status";
    emitEvent("reset_seen",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"frame_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"fast_path\":false,\"repeated_setup_count_before_reset\":" +
                  repeatedSetupCount_ +
                  ",\"repeated_setup_same_payload_count_before_reset\":" +
                  repeatedSetupSamePayloadCount_ +
                  ",\"delta_from_last_setup_response_to_reset_us\":" +
                  deltaSinceSetupResponseUs +
                  ",\"last_reset_cause_guess\":\"" +
                  escapeForJson(lastResetCauseGuess_) + "\"}");
    if (repeatedSetupThenResetObserved_) {
      emitEvent("repeated_setup_then_reset_observed",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"repeated_setup_count\":" + repeatedSetupCount_ +
                    ",\"repeated_setup_same_payload_count\":" +
                    repeatedSetupSamePayloadCount_ +
                    ",\"last_reset_cause_guess\":\"" +
                    escapeForJson(lastResetCauseGuess_) + "\"}");
    }
    emitSetupResponseRejectionAudit("reset_after_setup_response", frame.endedAtUs,
                                    &frame, "reset",
                                    String("\"fast_path\":false"));
    if (lastTxKind_ == "setup_response" && lastTxDoneUs_ > 0 &&
        frame.endedAtUs >= lastTxDoneUs_) {
      emitEvent("setup_followed_by_reset",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"delay_us_since_setup_response\":" +
                    (frame.endedAtUs - lastTxDoneUs_) +
                    ",\"setup_reply_delay_us\":" +
                    lastSetupResponseReplyDelayUs_ +
                    ",\"fast_path\":false}");
    }
    noteExpectedTxKind(DialogueKind::Reset, readerState_, "ack", frame.endedAtUs,
                       true, "reset_requires_ack");
    emitEvent("reset_ack_prepared",
              String("{\"timestamp_us\":") + ackPrepareUs +
                  ",\"expected_tx_kind\":\"ack\",\"fast_path\":false"
                  ",\"reset_rx_ts_us\":" + frame.endedAtUs +
                  ",\"delta_from_last_setup_response_to_reset_us\":" +
                  deltaSinceSetupResponseUs + "}");
    const unsigned long firstTxUs = sendAckRaw("cashless_reset_ack");
    resetAckSentCount_++;
    lastResetAckSentUs_ = firstTxUs;
    lastResetAckDoneUs_ = lastTxDoneUs_;
    lastResetAckReleaseUs_ = lastTxReleaseUs_;
    lastResetToAckUs_ =
        (firstTxUs > 0 && frame.endedAtUs > 0 && firstTxUs >= frame.endedAtUs)
            ? (firstTxUs - frame.endedAtUs)
            : 0;
    emitEvent("reset_ack_sent",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"tx_kind\":\"ack\",\"fast_path\":false"
                  ",\"ack_prepare_ts_us\":" + ackPrepareUs +
                  ",\"ack_tx_done_us\":" + lastResetAckDoneUs_ +
                  ",\"ack_release_us\":" + lastResetAckReleaseUs_ +
                  ",\"delta_from_reset_to_ack_us\":" + lastResetToAckUs_ +
                  "}");
    isReaderEnabled_ = false;
    beginSessionPending_ = false;
    beginSessionAmountMinor_ = 0;
    cashlessJustResetPending_ = true;
    cashlessSetupSeen_ = false;
    cashlessSetupMaxMinSeen_ = false;
    cashlessSetupResponsePending_ = false;
    cashlessSetupResponseAwaitingAck_ = false;
    cashlessExpansionSeen_ = false;
    session_.onReaderDisabled(now);
    emitEvent("just_reset_pending_set",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"reason\":\"reset_ack_sent\"}");
    transitionReaderState(ReaderState::ResetSeen, "reset_seen", frame.endedAtUs);
    emitEvent("waiting_for_poll_after_reset",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"just_reset_pending\":true,\"fast_path\":false"
                  ",\"next_action_hypothesis\":\"" +
                  escapeForJson(nextActionHypothesis_) + "\"}");
    emitPostResetProgressionExpectation("reset_ack_sent", firstTxUs);
    markSetupResponseAckMissing("reset_before_ack",
                                String("\"frame_hex\":\"") +
                                    machine::normalizedHex(frame) + "\"");
    stateDirty_ = true;
    emitEvent("ACK_SENT",
              String("{\"trigger\":\"reset\",\"tx_ts_us\":") + firstTxUs + "}");
    emitEvent("cashless_reset_received",
              String("{\"cashless_address\":") +
                  static_cast<unsigned int>(cashlessAddress_) +
                  ",\"just_reset_pending\":true}");
    return true;
  }

  if (isCompactReaderControlEnableCompat) {
    emitEvent("enable_seen",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"compact_compat\":true,"
                  "\"frame_hex\":\"" + machine::normalizedHex(frame) + "\"}");
    isReaderEnabled_ = true;
    session_.onReaderEnabled(now);
    emitEvent("enable_accepted",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"compact_compat\":true}");
    enableAppliedCount_++;
    transitionReaderState(ReaderState::Enabled, "enable_state_applied_compact",
                          frame.endedAtUs);
    transitionReaderState(ReaderState::SessionIdle,
                          "reader_enabled_waiting_poll_compact", frame.endedAtUs);
    noteExpectedTxKind(DialogueKind::Enable, readerState_, "ack", frame.endedAtUs,
                       true, "reader_control_enable_compact_ack");
    const unsigned long firstTxUs = sendAckRaw("reader_control_enable_compact_ack");
    emitEvent("enable_state_applied",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"enabled\":true,\"compact_compat\":true}");
    emitEvent("cashless_reader_control",
              "{\"enabled\":true,\"compact_compat\":true}");
    return true;
  }

  if (frame.normalizedLength > 1 &&
      isCashlessDialogue &&
      frame.candidateCommand == kCashlessSetupCommand &&
      !(frame.normalizedLength >= 2 &&
        frame.normalized[1] == kCashlessSetupMaxMinSubcommand)) {
    currentSetupResponseGatewayCompat_ =
        buildSetupVariantLabel(frame) == "SETUP_CONFIG_GATEWAY_COMPAT";
    lastSetupFastPathUsed_ = false;
    lastSetupRxTsUs_ = frame.bytes[0].tsUs;
    lastSetupRxEndUs_ = frame.endedAtUs;
    if (cashlessJustResetPending_) {
      emitEvent("just_reset_pending_cleared",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"reason\":\"setup_seen_before_poll\"}");
    }
    transitionReaderState(ReaderState::SetupSeen, "setup_seen", frame.endedAtUs);
    if (currentSetupResponseGatewayCompat_) {
      wrapperStandardFlowEntered_ = false;
      wrapperExpectedNextRxKind_ = "SETUP_RETRY_OR_ENABLE_OR_POLL";
      wrapperExpectedNextAction_ = "SEND_READER_CONFIG";
      setWrapperFsmState(WrapperFsmState::SetupConfigSeen,
                         "gateway_setup_config_seen", frame.endedAtUs);
    }
    lastSetupDecisionTsUs_ = micros();
    noteExpectedTxKind(DialogueKind::Setup, ReaderState::SetupSeen,
                       "setup_response", frame.endedAtUs, true,
                       "setup_requires_reader_config");
    const unsigned long firstTxUs =
        sendReaderSetupResponse(frame.endedAtUs, "setup_response");
    if (currentSetupResponseGatewayCompat_) {
      armGatewayCompatFollowupTracking(firstTxUs);
    }
    cashlessJustResetPending_ = false;
    nextActionHypothesis_ = "vmc_restarted_setup_sequence";
    cashlessSetupSeen_ = true;
    cashlessSetupMaxMinSeen_ = false;
    cashlessSetupResponsePending_ = false;
    cashlessExpansionSeen_ = false;
    noteSetupObserved(frame, frame.endedAtUs, "setup_config");
    transitionReaderState(ReaderState::SetupResponded, "setup_response_sent",
                          firstTxUs);
    if (currentSetupResponseGatewayCompat_) {
      emitEvent("gateway_wrapper_waiting_for_continuation",
                buildGatewayWrapperWaitingForContinuationJson(
                    firstTxUs, readerStateLabel(readerState_),
                    wrapperExpectedNextRxKindLabel(),
                    wrapperExpectedNextActionLabel()));
    } else {
      transitionReaderState(ReaderState::ExpansionPending,
                            "awaiting_expansion_or_enable", firstTxUs);
    }
    emitEvent("SETUP_RECEIVED",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"frame_hex\":\"" + machine::normalizedHex(frame) + "\"}");
    if (creditFlowActive_ && !creditFlowSetupSeen_) {
      creditFlowSetupSeen_ = true;
      emitEvent("credit_flow_setup_seen",
                String("{\"run_id\":") + creditFlowActiveRunId_ + "}");
    }
    emitEvent("cashless_setup_response",
              String("{\"mdb_level\":") + kCashlessLevel +
                  ",\"scaling_factor\":" + kCashlessScalingFactor +
                  ",\"decimal_places\":" + kCashlessDecimalPlaces +
                  ",\"response_time\":" + lastSetupResponseResponseTime_ +
                  ",\"options\":" + lastSetupResponseOptions_ +
                  ",\"profile_id\":\"" +
                  escapeForJson(setupResponseProfileId_) + "\"" +
                  ",\"tx_ts_us\":" + lastSetupResponseTxUs_ +
                  ",\"reply_delay_us\":" + lastSetupResponseReplyDelayUs_ + "}");
    return true;
  }

  if (isCashlessDialogue &&
      frame.candidateCommand == kCashlessSetupCommand &&
      frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessSetupMaxMinSubcommand) {
    if (cashlessJustResetPending_) {
      emitEvent("just_reset_pending_cleared",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"reason\":\"setup_max_min_seen_before_poll\"}");
    }
    noteExpectedTxKind(DialogueKind::Setup, readerState_, "no_data",
                       frame.endedAtUs, false, "setup_max_min_no_data");
    recordResponseDecision("setup_max_min_no_data", false, frame.endedAtUs);
    cashlessJustResetPending_ = false;
    nextActionHypothesis_ = "vmc_progressed_to_setup_max_min";
    cashlessSetupSeen_ = true;
    cashlessSetupMaxMinSeen_ = true;
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "false";
      setupRejectionBasis_ = "setup_max_min_progression";
    }
    noteSetupObserved(frame, frame.endedAtUs, "setup_max_min");
    emitEvent("cashless_setup_max_min_seen",
              String("{\"timestamp_us\":") + frame.endedAtUs +
                  ",\"frame_hex\":\"" + machine::normalizedHex(frame) +
                  "\",\"response\":\"no_data\"}");
    return true;
  }

  const bool isExpansionId =
      isCashlessDialogue &&
      frame.candidateCommand == kCashlessExpansionCommand &&
      frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessExpansionIdSubcommand;
  if (isExpansionId) {
    if (cashlessJustResetPending_) {
      emitEvent("just_reset_pending_cleared",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"reason\":\"expansion_seen_before_poll\"}");
    }
    noteExpectedTxKind(DialogueKind::ExpansionId, readerState_,
                       "expansion_response", frame.endedAtUs, true,
                       "expansion_request_id");
    const unsigned long firstTxUs =
        sendReaderExpansionIdResponse("expansion_response");
    cashlessJustResetPending_ = false;
    nextActionHypothesis_ = "vmc_requested_expansion_id";
    cashlessExpansionSeen_ = true;
    if (setupResponseRejectedByVmc_ != "true") {
      setupResponseRejectedByVmc_ = "false";
      setupRejectionBasis_ = "expansion_progression";
    }
    if (creditFlowActive_ && !creditFlowExpansionSeen_) {
      creditFlowExpansionSeen_ = true;
      emitEvent("credit_flow_expansion_seen",
                String("{\"run_id\":") + creditFlowActiveRunId_ + "}");
    }
    transitionReaderState(ReaderState::Disabled, "expansion_response_sent",
                          firstTxUs);
    emitEvent("cashless_expansion_response",
              String("{\"expansion_header\":9,\"device_id\":\"") +
                  escapeForJson(String("DENIS00000001")) +
                  "\",\"version_major\":1,\"version_minor\":1,"
                  "\"version_patch\":1,\"trigger\":\"expansion_id_standard\"}");
    return true;
  }

  if (isCashlessDialogue &&
      frame.candidateCommand == kCashlessReaderControlCommand &&
      frame.normalizedLength >= 2 &&
      frame.normalized[1] == kCashlessReaderControlSubcommand) {
    const bool enable =
        frame.normalizedLength >= 3 ? frame.normalized[2] == 0x01 : true;
    emitEvent(enable ? "enable_seen" : "disable_seen",
              String("{\"timestamp_us\":") + frame.endedAtUs + "}");
    isReaderEnabled_ = enable;
    if (enable) {
      if (setupResponseRejectedByVmc_ != "true") {
        setupResponseRejectedByVmc_ = "false";
        setupRejectionBasis_ = "enable_progression";
      }
      session_.onReaderEnabled(now);
      emitEvent("enable_accepted",
                String("{\"timestamp_us\":") + frame.endedAtUs + "}");
      enableAppliedCount_++;
      transitionReaderState(ReaderState::Enabled, "enable_state_applied",
                            frame.endedAtUs);
      transitionReaderState(ReaderState::SessionIdle,
                            "reader_enabled_waiting_poll", frame.endedAtUs);
      if (creditFlowActive_) {
        creditFlowEnableSeen_ = true;
        beginSessionPending_ = true;
        beginSessionAmountMinor_ = creditFlowAmountMinor_;
        emitEvent("credit_flow_enable_seen",
                  String("{\"run_id\":") + creditFlowActiveRunId_ +
                      ",\"enabled\":true}");
      }
    } else {
      session_.onReaderDisabled(now);
      beginSessionPending_ = false;
      beginSessionAmountMinor_ = 0;
      transitionReaderState(ReaderState::Disabled, "disable_state_applied",
                            frame.endedAtUs);
    }
    noteExpectedTxKind(enable ? DialogueKind::Enable : DialogueKind::Disable,
                       readerState_, "ack", frame.endedAtUs, true,
                       "reader_control_ack");
    const unsigned long firstTxUs = sendAckRaw("reader_control_ack");
    emitEvent(enable ? "enable_state_applied" : "disable_state_applied",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"enabled\":" + boolToJson(enable) + "}");
    emitEvent("cashless_reader_control",
              String("{\"enabled\":") + boolToJson(enable) + "}");
    return true;
  }

  if (isCashlessDialogue && frame.candidateCommand == kCashlessPollCommand) {
    transitionReaderState(ReaderState::PollActive, "poll_seen", frame.endedAtUs);
    uint8_t replyKind = 0;
    bool readerEnabled = isReaderEnabled_;
    const uint16_t beginSessionAmount = beginSessionAmountMinor_;
    const unsigned long firstTxUs =
        sendCashlessPollReply(now, frame.endedAtUs, replyKind, readerEnabled);
    if (kLogEveryPoll) {
      emitEvent("poll_rx_seen",
                String("{\"timestamp_us\":") + frame.endedAtUs +
                    ",\"reader_state\":\"" + readerStateLabel(readerState_) +
                    "\"}");
    }
    if (replyKind == 2) {
      emitEvent("JUST_RESET_SENT",
                String("{\"status_byte\":0,\"tx_ts_us\":") + firstTxUs + "}");
      emitEvent("cashless_poll_just_reset",
                String("{\"setup_seen\":") + boolToJson(cashlessSetupSeen_) +
                    ",\"expansion_seen\":" +
                    boolToJson(cashlessExpansionSeen_) + "}");
    } else if (replyKind == 3) {
      transitionReaderState(ReaderState::SessionActive, "poll_begin_session",
                            firstTxUs);
      emitEvent("cashless_begin_session_sent",
                String("{\"amount_minor\":") + beginSessionAmount + "}");
      if (creditFlowActive_) {
        emitEvent("credit_flow_begin_session_sent",
                  String("{\"run_id\":") + creditFlowActiveRunId_ +
                      ",\"amount_minor\":" + beginSessionAmount +
                      ",\"response_delay_us\":" + creditFlowResponseDelayUs_ +
                      ",\"exact_reply_delay_us\":" +
                      creditFlowExactReplyDelayUs_ +
                      ",\"early_timeout\":" +
                      boolToJson(creditFlowResponseDelayUs_ > 5000) + "}");
      }
    } else {
      if (isReaderEnabled_) {
        transitionReaderState(ReaderState::SessionIdle, "poll_ack",
                              firstTxUs);
      } else {
        transitionReaderState(ReaderState::Disabled, "poll_ack_while_disabled",
                              firstTxUs);
      }
      emitEvent("ACK_SENT",
                String("{\"trigger\":\"sendAck\",\"tx_ts_us\":") + firstTxUs +
                    "}");
      emitEvent("cashless_poll_ack",
                String("{\"reader_enabled\":") + boolToJson(readerEnabled) +
                    ",\"begin_session_pending\":" +
                    boolToJson(beginSessionPending_) + "}");
    }
    return true;
  }

  if (frame.checksumValid) {
    recordResponseDecision("unsupported_command", false, frame.endedAtUs);
  }

  return false;
}

void MdbService::observeCreditFlowFrame(const machine::Frame& frame, unsigned long now) {
  if (!creditFlowActive_) {
    return;
  }

  if (creditFlowVendDeniedSent_ && !creditFlowSessionEndSent_ &&
      !creditFlowSetupSeen_ && !creditFlowExpansionSeen_ &&
      !creditFlowEnableSeen_ && frame.hasCandidateAddress &&
      !(frameStartsWith(frame, cashlessCommandByte(kCashlessSetupCommand),
                        kCashlessSetupSubcommand) ||
        frameStartsWith(frame, cashlessCommandByte(kCashlessSetupCommand),
                        kCashlessSetupMaxMinSubcommand) ||
        frameStartsWith(frame, cashlessCommandByte(kCashlessExpansionCommand),
                        kCashlessExpansionIdSubcommand) ||
        frameStartsWith(frame, cashlessCommandByte(kCashlessReaderControlCommand),
                        kCashlessReaderControlSubcommand))) {
    sendEndSession();
    creditFlowSessionEndSent_ = true;
    emitEvent("cashless_session_end_compat",
              String("{\"family\":\"") + frame.candidateAddress + "/" +
                  frame.candidateCommand +
                  "\",\"action\":\"end_session\",\"reason\":\"generic_post_vend_denied_noise\"}");
  }

  if (creditFlowAwaitingAck_ && frame.normalizedLength == 1 &&
      frame.normalized[0] == mdb::kAck) {
    creditFlowAckReceived_ = true;
    creditFlowAwaitingAck_ = false;
    emitEvent("credit_flow_begin_session_ack_received",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"ack\":true}");
    finalizeCreditFlowStrategy(now, "completed", "begin_session_ack_received");
    return;
  }

  if (!creditFlowObservationActive_) {
    return;
  }

  creditFlowPostReplyFrameCount_++;
  String family = "unknown";
  if (frame.hasCandidateAddress) {
    family = String(frame.candidateAddress) + "/" + String(frame.candidateCommand);
  }
  if (!creditFlowObservedFamilies_.isEmpty()) {
    creditFlowObservedFamilies_ += " -> ";
  }
  creditFlowObservedFamilies_ += family;
  emitEvent("observation_frame_captured",
            String("{\"run_id\":") + creditFlowActiveRunId_ +
                ",\"observation_window_id\":\"credit-flow-obs-" +
                creditFlowActiveRunId_ + "\",\"candidate_label\":\"" +
                creditFlowCandidateLabel_ + "\",\"candidate_bytes\":\"" +
                escapeForJson(creditFlowCandidateBytes_) + "\"" +
                ",\"post_reply_frame_count\":" + creditFlowPostReplyFrameCount_ +
                ",\"family\":\"" + escapeForJson(family) + "\"}");
}

bool MdbService::tryFastCreditFlowReply(const machine::Frame& frame, unsigned long now) {
  if (!creditFlowActive_ || frame.normalizedLength == 0) {
    return false;
  }

  if (frame.hasCandidateAddress && frame.candidateAddress == 12 &&
      frame.candidateCommand == 6 && !creditFlowVendApprovedSent_) {
    const unsigned long firstTxUs = sendVendApproved(100);
    creditFlowSessionHijackAttempted_ = true;
    creditFlowVendApprovedSent_ = true;
    creditFlowResponseDelayUs_ =
        (firstTxUs > 0 && frame.endedAtUs > 0 && firstTxUs >= frame.endedAtUs)
            ? (firstTxUs - frame.endedAtUs)
            : 0;
    creditFlowExactReplyDelayUs_ = creditFlowResponseDelayUs_;
    creditFlowObservationActive_ = true;
    creditFlowObservationEndsAt_ = now + kCreditFlowObservationWindowMs;
    creditFlowPostReplyFrameCount_ = 0;
    creditFlowObservedFamilies_ = "";
    creditFlowCandidateBytes_ = "02 00 64";
    emitEvent("cashless_vend_compat",
              String("{\"family\":\"12/6\",\"action\":\"vend_approved\","
                     "\"amount_minor\":100,\"reason\":\"force_active_session_fast\","
                     "\"response_delay_us\":") +
                  creditFlowResponseDelayUs_ + ",\"exact_reply_delay_us\":" +
                  creditFlowExactReplyDelayUs_ + "}");
    finalizeCreditFlowStrategy(now, "completed", "vend_approved_sent");
    return true;
  }

  if (frame.hasCandidateAddress && frame.candidateAddress == 12 &&
      frame.candidateCommand == 7 &&
      !creditFlowBeginSessionSent_ && !creditFlowVendApprovedSent_) {
    const unsigned long firstTxUs = sendBeginSession(100);
    creditFlowSessionHijackAttempted_ = true;
    creditFlowBeginSessionSent_ = true;
    creditFlowAwaitingAck_ = true;
    creditFlowResponseDelayUs_ =
        (firstTxUs > 0 && frame.endedAtUs > 0 && firstTxUs >= frame.endedAtUs)
            ? (firstTxUs - frame.endedAtUs)
            : 0;
    creditFlowExactReplyDelayUs_ = creditFlowResponseDelayUs_;
    creditFlowObservationActive_ = true;
    creditFlowObservationEndsAt_ = now + kCreditFlowObservationWindowMs;
    creditFlowPostReplyFrameCount_ = 0;
    creditFlowObservedFamilies_ = "";
    creditFlowCandidateBytes_ = "03 00 64";
    emitEvent("credit_flow_begin_session_sent",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"amount_minor\":100,\"response_delay_us\":" +
                  creditFlowResponseDelayUs_ +
                  ",\"exact_reply_delay_us\":" + creditFlowExactReplyDelayUs_ +
                  ",\"early_timeout\":" +
                  boolToJson(creditFlowResponseDelayUs_ > 5000) +
                  ",\"trigger\":\"fast_path\"}");
    return true;
  }

  return false;
}

void MdbService::finalizeCreditFlowStrategy(unsigned long now, const char* status,
                                            const char* reason) {
  if (!creditFlowActive_) {
    return;
  }

  const uint8_t handshakeSteps =
      (creditFlowSetupSeen_ ? 1 : 0) + (creditFlowExpansionSeen_ ? 1 : 0) +
      (creditFlowEnableSeen_ ? 1 : 0);
  const float handshakeScore = handshakeSteps / 3.0f;
  const bool sequenceObserved = creditFlowPostReplyFrameCount_ > 0;
  const bool earlyTimeout = creditFlowResponseDelayUs_ > 5000;
  if (creditFlowObservationActive_) {
    emitEvent("post_reply_sequence_observed",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"observation_window_id\":\"credit-flow-obs-" +
                  creditFlowActiveRunId_ +
                  "\",\"candidate_label\":\"" + creditFlowCandidateLabel_ +
                  "\",\"candidate_bytes\":\"" +
                  escapeForJson(creditFlowCandidateBytes_) + "\"" +
                  ",\"post_reply_sequence_observed\":" +
                  boolToJson(sequenceObserved) +
                  ",\"post_reply_frames\":" + creditFlowPostReplyFrameCount_ +
                  ",\"post_reply_families\":\"" +
                  escapeForJson(creditFlowObservedFamilies_) + "\"}");
    emitEvent("post_reply_machine_change_detected",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"observation_window_id\":\"credit-flow-obs-" +
                  creditFlowActiveRunId_ +
                  "\",\"candidate_label\":\"" + creditFlowCandidateLabel_ +
                  "\",\"candidate_bytes\":\"" +
                  escapeForJson(creditFlowCandidateBytes_) + "\"" +
                  ",\"machine_change_detected\":false,\"new_family_appeared\":false,"
                  "\"polling_disappeared\":false,\"loop_stayed_stable\":true}");
    emitEvent("post_reply_observation_closed",
              String("{\"run_id\":") + creditFlowActiveRunId_ +
                  ",\"observation_window_id\":\"credit-flow-obs-" +
                  creditFlowActiveRunId_ +
                  "\",\"candidate_label\":\"" + creditFlowCandidateLabel_ +
                  "\",\"candidate_bytes\":\"" +
                  escapeForJson(creditFlowCandidateBytes_) + "\"" +
                  ",\"observation_opened\":true,\"observation_closed\":true"
                  ",\"observation_close_reason\":\"" + reason +
                  "\",\"post_reply_sequence_observed\":" +
                  boolToJson(sequenceObserved) +
                  ",\"post_reply_machine_change_detected\":false"
                  ",\"post_reply_frame_count\":" + creditFlowPostReplyFrameCount_ +
                  ",\"post_reply_families\":\"" +
                  escapeForJson(creditFlowObservedFamilies_) +
                  "\",\"anchor_seen_after_reply\":0,\"unexpected_family_count\":0"
                  ",\"polling_disappeared\":false,\"loop_stayed_stable\":true"
                  ",\"final_classification_candidate\":\"safe_no_visible_effect\"}");
  }
  emitEvent("credit_flow_strategy_result",
            String("{\"run_id\":") + creditFlowActiveRunId_ +
                ",\"status\":\"" + status + "\",\"completion_reason\":\"" + reason +
                "\",\"just_reset_sent\":" +
                boolToJson(creditFlowJustResetSent_) +
                ",\"session_hijack_attempted\":" +
                boolToJson(creditFlowSessionHijackAttempted_) +
                ",\"vend_denied_sent\":" +
                boolToJson(creditFlowVendDeniedSent_) +
                ",\"vend_approved_sent\":" +
                boolToJson(creditFlowVendApprovedSent_) +
                ",\"session_end_sent\":" +
                boolToJson(creditFlowSessionEndSent_) +
                ",\"setup_seen\":" + boolToJson(creditFlowSetupSeen_) +
                ",\"expansion_seen\":" + boolToJson(creditFlowExpansionSeen_) +
                ",\"enable_seen\":" + boolToJson(creditFlowEnableSeen_) +
                ",\"begin_session_sent\":" + boolToJson(creditFlowBeginSessionSent_) +
                ",\"ack_received\":" + boolToJson(creditFlowAckReceived_) +
                ",\"handshake_completeness_score\":" + String(handshakeScore, 3) +
                ",\"response_delay_us\":" + creditFlowResponseDelayUs_ +
                ",\"exact_reply_delay_us\":" + creditFlowExactReplyDelayUs_ +
                ",\"last_rx_byte_us\":" + creditFlowLastRxByteUs_ +
                ",\"frame_finalized_us\":" + creditFlowFrameFinalizedUs_ +
                ",\"first_tx_byte_us\":" + creditFlowFirstTxByteUs_ +
                ",\"phy_loop_counter\":" + creditFlowPhyLoopCounter_ +
                ",\"rx_to_finalize_gap\":" +
                (creditFlowFrameFinalizedUs_ >= creditFlowLastRxByteUs_
                     ? (creditFlowFrameFinalizedUs_ - creditFlowLastRxByteUs_)
                     : 0) +
                ",\"finalize_to_tx_gap\":" +
                (creditFlowFirstTxByteUs_ >= creditFlowFrameFinalizedUs_
                     ? (creditFlowFirstTxByteUs_ - creditFlowFrameFinalizedUs_)
                     : 0) +
                ",\"early_timeout\":" + boolToJson(earlyTimeout) +
                ",\"post_reply_sequence_observed\":" + boolToJson(sequenceObserved) +
                ",\"post_reply_families\":\"" +
                escapeForJson(creditFlowObservedFamilies_) + "\"}");
  creditFlowCompleted_ = strcmp(status, "completed") == 0;
  creditFlowActive_ = false;
  creditFlowObservationActive_ = false;
  creditFlowAwaitingAck_ = false;
  creditFlowNeedsJustReset_ = false;
}

void MdbService::handleExperimentTrigger(const StrategyView& view,
                                         const machine::Frame& frame,
                                         unsigned long now) {
  (void)frame;
  if ((experimentMode_ != ExperimentMode::SelectiveReplyProbe &&
       experimentMode_ != ExperimentMode::ProtocolShapedProbe) ||
      !experimentConfig_.enabled) {
    return;
  }
  if (view.candidateAddress != experimentConfig_.triggerAddress ||
      view.candidateCommand != experimentConfig_.triggerCommand) {
    return;
  }
  if (!experimentArmed_ && !experimentFireOnceRequested_) {
    emitEvent("experiment_reply_skipped", "{\"reason\":\"not_armed\"}");
    return;
  }
  if (experimentObservationActive_ || experimentReplyPending_) {
    emitEvent("experiment_reply_skipped", "{\"reason\":\"busy\"}");
    return;
  }
  if (experimentRepliesThisSession_ >= experimentConfig_.maxRepliesPerSession) {
    emitEvent("experiment_reply_skipped",
              "{\"reason\":\"max_replies_per_session\"}");
    return;
  }
  if (experimentLastReplyAt_ != 0 &&
      now - experimentLastReplyAt_ < experimentConfig_.cooldownMs) {
    emitEvent(
        "experiment_cooldown_active",
        String("{\"cooldown_ms\":") + experimentConfig_.cooldownMs +
            ",\"remaining_ms\":" +
            (experimentConfig_.cooldownMs - (now - experimentLastReplyAt_)) + "}");
    return;
  }

  experimentTriggerAt_ = now;
  experimentScheduledReplyAt_ = now + experimentConfig_.replyDelayMs;
  experimentReplyPending_ = true;
  experimentLastTriggerFamily_ =
      String(view.candidateAddress) + "/" + String(view.candidateCommand);
  experimentLastPreContext_ = buildRecentFamilyPath(5);
  emitEvent(
      "experiment_triggered_on_anchor",
      String("{\"anchor_timestamp_ms\":") + now + ",\"trigger_family\":\"" +
          experimentLastTriggerFamily_ + "\",\"reply_delay_ms\":" +
          experimentConfig_.replyDelayMs + ",\"pre_context\":\"" +
          escapeForJson(experimentLastPreContext_) + "\"}");
}

void MdbService::processExperiment(unsigned long now) {
  if (!experimentReplyPending_ || now < experimentScheduledReplyAt_) {
    return;
  }
  if ((experimentMode_ != ExperimentMode::SelectiveReplyProbe &&
       experimentMode_ != ExperimentMode::ProtocolShapedProbe) ||
      !experimentConfig_.enabled) {
    experimentReplyPending_ = false;
    return;
  }

  const uint8_t replyLength =
      experimentConfig_.replyLength == 0 ? 1 : experimentConfig_.replyLength;
  transmitDebugFrame(TxScope::Experiment, "experiment_reply",
                     experimentConfig_.replyBytes, replyLength);
  experimentReplyPending_ = false;
  experimentObservationActive_ = true;
  experimentObservationEndsAt_ = now + experimentConfig_.observationWindowMs;
  experimentLastReplyAt_ = now;
  experimentRunCounter_++;
  experimentActiveRunId_ = experimentRunCounter_;
  experimentRepliesThisSession_++;
  experimentPostReplyFrameCount_ = 0;
  experimentUnexpectedFamilyCount_ = 0;
  experimentAnchorSeenAfterReply_ = 0;
  experimentSequenceObservedEmitted_ = false;
  experimentMachineChangeEmitted_ = false;
  experimentObservationClosedEmitted_ = false;
  experimentObservationTriggerAddress_ = experimentConfig_.triggerAddress;
  experimentObservationTriggerCommand_ = experimentConfig_.triggerCommand;
  experimentObservedPostFamilies_ = "";
  experimentObservationReason_ = "";
  experimentLastReplyHex_ = bytesToHex(experimentConfig_.replyBytes, replyLength);
  experimentObservationCandidateLabel_ = buildExperimentCandidateLabel();
  emitEvent("observation_context_created",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) + "\"}");
  emitEvent("observation_timeout_scheduled",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"observation_ends_at_ms\":" + experimentObservationEndsAt_ +
                ",\"observation_window_ms\":" +
                experimentConfig_.observationWindowMs + "}");
  emitEvent("observation_opened",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"trigger_timestamp_ms\":" + experimentTriggerAt_ +
                ",\"reply_timestamp_ms\":" + now +
                ",\"observation_opened\":true,\"observation_window_ms\":" +
                experimentConfig_.observationWindowMs + "}");
  emitEvent("experiment_reply_sent",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"anchor_timestamp_ms\":" + experimentTriggerAt_ +
                ",\"reply_timestamp_ms\":" + now +
                ",\"raw_reply_hex\":\"" + experimentLastReplyHex_ +
                "\",\"normalized_reply_hex\":\"" + experimentLastReplyHex_ + "\"" +
                ",\"mode\":\"" + experimentModeToString(experimentMode_) +
                "\",\"protocol_probe_candidate_id\":" +
                experimentConfig_.protocolProbeCandidateId +
                ",\"reply_len\":" + replyLength +
                ",\"cycle_context_before\":\"" +
                escapeForJson(experimentLastPreContext_) + "\"}");
  if (experimentFireOnceRequested_) {
    experimentFireOnceRequested_ = false;
    experimentArmed_ = false;
  }
}

void MdbService::observeExperimentFrame(const StrategyView& view, unsigned long now) {
  if (!experimentObservationActive_) {
    emitEvent("observation_close_skipped",
              String("{\"reason\":\"frame_received_without_active_observation\","
                     "\"run_id\":") +
                  experimentActiveRunId_ + "}");
    return;
  }
  experimentPostReplyFrameCount_++;
  const String family =
      String(view.candidateAddress) + "/" + String(view.candidateCommand);
  if (!experimentObservedPostFamilies_.isEmpty()) {
    experimentObservedPostFamilies_ += " -> ";
  }
  experimentObservedPostFamilies_ += family;
  if (view.candidateAddress == experimentObservationTriggerAddress_ &&
      view.candidateCommand == experimentObservationTriggerCommand_) {
    experimentAnchorSeenAfterReply_++;
  }
  emitEvent("observation_sequence_evaluated",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"post_reply_frame_count\":" +
                experimentPostReplyFrameCount_ + ",\"family\":\"" +
                escapeForJson(family) + "\"}");
  if (!isKnownExperimentFamily(view.candidateAddress, view.candidateCommand)) {
    experimentUnexpectedFamilyCount_++;
  }
  emitEvent("observation_frame_captured",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"post_reply_frame_count\":" +
                experimentPostReplyFrameCount_ + ",\"family\":\"" +
                escapeForJson(family) + "\",\"unexpected_family_count\":" +
                experimentUnexpectedFamilyCount_ + ",\"anchor_seen_after_reply\":" +
                experimentAnchorSeenAfterReply_ + "}");

  if (experimentConfig_.disableOnAnyError &&
      experimentUnexpectedFamilyCount_ >= 2) {
    disableExperimentDueToError("unexpected_family_after_reply", now);
    return;
  }

  if (now >= experimentObservationEndsAt_) {
    finalizeExperimentObservation(now, "observation_complete");
  }
}

void MdbService::finalizeExperimentObservation(unsigned long now,
                                               const char* reason) {
  if (!experimentObservationActive_) {
    emitEvent("observation_close_skipped",
              String("{\"reason\":\"no_active_observation\",\"requested_reason\":\"") +
                  reason + "\",\"run_id\":" + experimentActiveRunId_ + "}");
    return;
  }
  experimentObservationActive_ = false;
  experimentObservationReason_ = reason;
  const bool pollingDisappeared = experimentPostReplyFrameCount_ == 0;
  const bool machineChanged =
      pollingDisappeared || experimentUnexpectedFamilyCount_ > 0;
  const bool sequenceObserved = experimentPostReplyFrameCount_ > 0;
  const char* finalClassification =
      observationCloseReasonToClassification(pollingDisappeared, machineChanged);
  emitEvent("observation_sequence_built",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"post_reply_frame_count\":" +
                experimentPostReplyFrameCount_ + ",\"post_reply_families\":\"" +
                escapeForJson(experimentObservedPostFamilies_) +
                "\",\"sequence_observed\":" + boolToJson(sequenceObserved) + "}");
  emitEvent(
      "post_reply_sequence_observed",
      String("{\"run_id\":") + experimentActiveRunId_ +
          ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
          "\",\"candidate_label\":\"" +
          escapeForJson(experimentObservationCandidateLabel_) +
          "\",\"candidate_bytes\":\"" +
          escapeForJson(experimentLastReplyHex_) +
          "\",\"anchor_timestamp_ms\":" + experimentTriggerAt_ +
          ",\"reply_timestamp_ms\":" + experimentLastReplyAt_ +
          ",\"observation_end_ms\":" + now + ",\"reason\":\"" + reason +
          "\",\"observation_opened\":true,\"observation_closed\":true" +
          ",\"post_reply_sequence_observed\":" + boolToJson(sequenceObserved) +
          ",\"post_reply_machine_change_detected\":" + boolToJson(machineChanged) +
          ",\"post_reply_frames\":" + experimentPostReplyFrameCount_ +
          ",\"post_reply_families\":\"" +
          escapeForJson(experimentObservedPostFamilies_) +
          "\",\"anchor_seen_after_reply\":" + experimentAnchorSeenAfterReply_ +
          ",\"unexpected_family_count\":" + experimentUnexpectedFamilyCount_ +
          ",\"polling_disappeared\":" + boolToJson(pollingDisappeared) + "}");
  experimentSequenceObservedEmitted_ = true;
  emitEvent("machine_change_evaluated",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"machine_change_detected\":" + boolToJson(machineChanged) +
                ",\"polling_disappeared\":" + boolToJson(pollingDisappeared) +
                ",\"loop_stayed_stable\":" + boolToJson(!machineChanged) + "}");
  emitEvent(
      "post_reply_machine_change_detected",
      String("{\"run_id\":") + experimentActiveRunId_ +
          ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
          "\",\"candidate_label\":\"" +
          escapeForJson(experimentObservationCandidateLabel_) +
          "\",\"candidate_bytes\":\"" +
          escapeForJson(experimentLastReplyHex_) +
          "\",\"machine_change_detected\":" + boolToJson(machineChanged) +
          ",\"new_family_appeared\":" +
          boolToJson(experimentUnexpectedFamilyCount_ > 0) +
          ",\"polling_disappeared\":" + boolToJson(pollingDisappeared) +
          ",\"loop_stayed_stable\":" + boolToJson(!machineChanged) +
          ",\"post_reply_pattern\":\"" +
          escapeForJson(experimentObservedPostFamilies_) + "\"}");
  experimentMachineChangeEmitted_ = true;
  emitEvent("observation_closed",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"observation_opened\":true,\"observation_closed\":true" +
                ",\"observation_close_reason\":\"" + reason +
                "\",\"post_reply_sequence_observed\":" +
                boolToJson(sequenceObserved) +
                ",\"post_reply_machine_change_detected\":" +
                boolToJson(machineChanged) + "}");
  emitEvent(
      "post_reply_observation_closed",
      String("{\"run_id\":") + experimentActiveRunId_ +
          ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
          "\",\"candidate_label\":\"" +
          escapeForJson(experimentObservationCandidateLabel_) +
          "\",\"candidate_bytes\":\"" +
          escapeForJson(experimentLastReplyHex_) +
          "\",\"trigger_timestamp_ms\":" + experimentTriggerAt_ +
          ",\"reply_timestamp_ms\":" + experimentLastReplyAt_ +
          ",\"observation_end_ms\":" + now +
          ",\"observation_opened\":true,\"observation_closed\":true" +
          ",\"observation_close_reason\":\"" + reason +
          "\",\"post_reply_sequence_observed\":" + boolToJson(sequenceObserved) +
          ",\"post_reply_machine_change_detected\":" +
          boolToJson(machineChanged) +
          ",\"post_reply_frame_count\":" + experimentPostReplyFrameCount_ +
          ",\"post_reply_families\":\"" +
          escapeForJson(experimentObservedPostFamilies_) +
          "\",\"anchor_seen_after_reply\":" + experimentAnchorSeenAfterReply_ +
          ",\"unexpected_family_count\":" + experimentUnexpectedFamilyCount_ +
          ",\"polling_disappeared\":" + boolToJson(pollingDisappeared) +
          ",\"loop_stayed_stable\":" + boolToJson(!machineChanged) +
          ",\"final_classification_candidate\":\"" + finalClassification +
          "\",\"notes\":\"sequence_and_machine_change_reported\"" +
          ",\"sequence_event_emitted\":" +
          boolToJson(experimentSequenceObservedEmitted_) +
          ",\"machine_change_event_emitted\":" +
          boolToJson(experimentMachineChangeEmitted_) + "}");
  experimentObservationClosedEmitted_ = true;
  emitEvent("observation_result_emitted",
            String("{\"run_id\":") + experimentActiveRunId_ +
                ",\"observation_window_id\":\"obs-" + experimentActiveRunId_ +
                "\",\"candidate_label\":\"" +
                escapeForJson(experimentObservationCandidateLabel_) +
                "\",\"candidate_bytes\":\"" +
                escapeForJson(experimentLastReplyHex_) +
                "\",\"final_classification_candidate\":\"" +
                finalClassification + "\",\"close_reason\":\"" + reason +
                "\",\"observation_result_emitted\":true}");

  if (baselineSeriesActive_ && experimentConfig_.baselineSeriesCount > 0) {
    if (baselineSeriesIndex_ < 0xFF) {
      baselineSeriesIndex_++;
    }
    baselineSeriesCompleted_ =
        baselineSeriesIndex_ >= experimentConfig_.baselineSeriesCount;
    emitEvent(
        "experiment_baseline_series_progress",
        String("{\"reply_byte_hex\":\"") + experimentLastReplyHex_ +
            "\",\"baseline_series_index\":" + baselineSeriesIndex_ +
            ",\"baseline_series_count\":" +
            experimentConfig_.baselineSeriesCount +
            ",\"baseline_series_active\":" + boolToJson(baselineSeriesActive_) +
            ",\"baseline_series_completed\":" +
            boolToJson(baselineSeriesCompleted_) + "}");
  }

  if (experimentConfig_.disableOnAnyError && pollingDisappeared) {
    disableExperimentDueToError("no_post_reply_frames", now);
  }
}

void MdbService::disableExperimentDueToError(const char* reason,
                                             unsigned long now) {
  experimentMode_ = ExperimentMode::PassiveOnly;
  experimentConfig_.enabled = false;
  experimentArmed_ = false;
  experimentReplyPending_ = false;
  experimentObservationActive_ = false;
  experimentFireOnceRequested_ = false;
  experimentLastDisableAt_ = now;
  emitEvent("experiment_disabled_due_to_error",
            String("{\"reason\":\"") + reason + "\",\"disabled_at_ms\":" +
                now + "}");
}

String MdbService::buildRecentFamilyPath(size_t limit) const {
  String out;
  if (sniffHistoryCount_ == 0) {
    return out;
  }
  const size_t framesToWalk = sniffHistoryCount_ > limit ? limit : sniffHistoryCount_;
  for (size_t offset = 0; offset < framesToWalk; ++offset) {
    const size_t index =
        (sniffHistoryNext_ + kSniffHistorySize - framesToWalk + offset) %
        kSniffHistorySize;
    const SniffFrameRecord& record = sniffHistory_[index];
    if (!record.used) {
      continue;
    }
    int bestStrategy = -1;
    uint8_t bestConfidence = 0;
    for (size_t s = 0; s < kStrategyCount; ++s) {
      const StrategyView& view = record.strategies[s];
      if (!view.plausible) {
        continue;
      }
      if (view.confidence >= bestConfidence) {
        bestConfidence = view.confidence;
        bestStrategy = static_cast<int>(s);
      }
    }
    if (bestStrategy < 0) {
      continue;
    }
    const StrategyView& view = record.strategies[bestStrategy];
    if (!out.isEmpty()) {
      out += " -> ";
    }
    out += String(view.candidateAddress) + "/" + String(view.candidateCommand);
  }
  return out;
}

const char* MdbService::experimentModeToString(ExperimentMode mode) const {
  switch (mode) {
    case ExperimentMode::ProtocolShapedProbe:
      return "protocol_shaped_probe";
    case ExperimentMode::SelectiveReplyProbe:
      return "selective_reply_probe";
    case ExperimentMode::PassiveOnly:
    default:
      return "passive_only";
  }
}

bool MdbService::resolveProtocolProbeCandidate(uint8_t candidateId,
                                               uint8_t* outBytes,
                                               uint8_t& outLength) const {
  if (outBytes == nullptr) {
    outLength = 0;
    return false;
  }
  switch (candidateId) {
    case 1:
      outBytes[0] = 0xAA;
      outBytes[1] = 0x00;
      outLength = 2;
      return true;
    case 2:
      outBytes[0] = 0x00;
      outBytes[1] = 0xAA;
      outLength = 2;
      return true;
    case 3:
      outBytes[0] = 0xAA;
      outBytes[1] = 0xAA;
      outLength = 2;
      return true;
    case 4:
      outBytes[0] = 0xAA;
      outBytes[1] = 0xFF;
      outLength = 2;
      return true;
    case 5:
      outBytes[0] = 0xAA;
      outBytes[1] = 0x55;
      outLength = 2;
      return true;
    case 6:
      outBytes[0] = 0x55;
      outBytes[1] = 0xAA;
      outLength = 2;
      return true;
    default:
      outLength = 0;
      return false;
  }
}

unsigned long MdbService::sendReaderSetupResponse(unsigned long rxEndedUs,
                                                  const char* responseReason) {
  const unsigned long buildStartedUs = micros();
  if (!currentSetupResponseGatewayCompat_) {
    gatewayCompatFollowupActive_ = false;
    gatewayCompatFirstFollowupCaptured_ = false;
    gatewayCompatBusAliveAfterSetup_ = false;
    gatewayCompatLastOutcome_ = "non_gateway_setup_response";
    wrapperStandardFlowEntered_ = true;
    wrapperExpectedNextRxKind_ = "";
    wrapperExpectedNextAction_ = "";
    wrapperContinuationKind_ = "";
    wrapperContinuationRaw9_ = 0;
    wrapperContinuationDeltaUs_ = 0;
    wrapperContinuationInterpretation_ = "";
    wrapperAckSemanticsMode_ = WrapperAckSemanticsMode::StandardSetupAck;
    wrapperAckSemanticsSuspect_ = false;
    setWrapperFsmState(WrapperFsmState::Idle, "non_gateway_setup_response",
                       buildStartedUs);
  }
  const bool useSetupResponseExperiment = setupResponseExperimentEnabled_;
  const uint8_t responseTime =
      useSetupResponseExperiment
          ? setupResponseExperimentResponseTime_
          : (currentSetupResponseGatewayCompat_ ? gatewayCompatResponseTime()
                                                : kCashlessAppMaxResponseTime);
  const uint8_t options =
      useSetupResponseExperiment
          ? setupResponseExperimentOptions_
          : (currentSetupResponseGatewayCompat_ ? gatewayCompatResponseOptions()
                                                : 0x00);
  const uint8_t currencyCountryCodeHi =
      useSetupResponseExperiment
          ? setupResponseExperimentCurrencyCountryCodeHi_
          : (currentSetupResponseGatewayCompat_
                 ? gatewayCompatCurrencyCountryCodeHi()
                 : kCashlessCurrencyCountryCodeHi);
  const uint8_t currencyCountryCodeLo =
      useSetupResponseExperiment
          ? setupResponseExperimentCurrencyCountryCodeLo_
          : (currentSetupResponseGatewayCompat_
                 ? gatewayCompatCurrencyCountryCodeLo()
                 : kCashlessCurrencyCountryCodeLo);
  const uint8_t payload[] = {
      // 0x01 = READER CONFIGURATION DATA header.
      0x01,
      // MDB level supported by this reader.
      kCashlessLevel,
      // Country / currency code in packed BCD. Gateway profile 2 tests phone-code form.
      currencyCountryCodeHi,
      currencyCountryCodeLo,
      // Scale factor occupies exactly one byte: 0x64 = 100 minor units per 1.00 KGS.
      kCashlessScalingFactor,
      // Decimal places shown by the VMC: 2 => 5000 is displayed as 50.00.
      kCashlessDecimalPlaces,
      // Maximum response time in seconds.
      responseTime,
      // Misc/options byte. Gateway compat can be tested with one alternate repo-like profile.
      options,
  };
  static_assert(sizeof(payload) == 8,
                "MDB SETUP RESPONSE payload must stay 8 bytes before checksum");
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  lastSetupFrameBuiltTsUs_ = micros();
  lastSetupResponseChecksum_ =
      length > 0 ? frame[length - 1] : static_cast<uint8_t>(0);
  lastSetupResponseOptions_ = options;
  lastSetupResponseResponseTime_ = responseTime;
  lastSetupResponseCountryCodeHi_ = currencyCountryCodeHi;
  lastSetupResponseCountryCodeLo_ = currencyCountryCodeLo;
  setupResponseProfileId_ = useSetupResponseExperiment
                                ? String("setup_experiment_") + setupResponseExperimentLabel_
                                : (currentSetupResponseGatewayCompat_
                                       ? String(gatewayCompatResponseProfileIdLabel())
                                       : String("standard_setup_default"));
  setupResponseSuspectField_ =
      useSetupResponseExperiment
          ? String("currency_max_response_time_options_sweep")
          : (currentSetupResponseGatewayCompat_
                 ? String(gatewayCompatSemanticSuspectFieldLabel())
                 : String("none"));
  gatewayCurrencyCountryCodeProfileId_ = useSetupResponseExperiment
                                  ? String("custom_experimental")
                                  : (currentSetupResponseGatewayCompat_
                                         ? String(gatewayCurrencyCountryCodeProfileIdLabel())
                                         : String("standard_iso4217_bcd"));
  currencyCountryCodeEncodingMode_ = useSetupResponseExperiment
                                  ? String("custom_experimental")
                                  : (currentSetupResponseGatewayCompat_
                                         ? String(gatewayCurrencyCountryCodeEncodingModeLabel())
                                         : String("iso4217_numeric_packed_bcd"));
  wrapperAckSemanticsMode_ = currentSetupResponseGatewayCompat_
                                 ? WrapperAckSemanticsMode::WrapperContinuationOnly
                                 : WrapperAckSemanticsMode::StandardSetupAck;
  wrapperAckSemanticsSuspect_ = currentSetupResponseGatewayCompat_;
  const unsigned long firstTxUs =
      transmitResponseFrame(responseReason, "setup_response", frame, length, rxEndedUs);
  markSetupResponseSent(firstTxUs, !currentSetupResponseGatewayCompat_);
  lastSetupResponseTxUs_ = firstTxUs;
  lastSetupResponseReplyDelayUs_ =
      (firstTxUs > 0 && rxEndedUs > 0 && firstTxUs >= rxEndedUs)
          ? (firstTxUs - rxEndedUs)
          : 0;
  lastSetupDecisionToTxUs_ =
      (firstTxUs > 0 && lastSetupDecisionTsUs_ > 0 && firstTxUs >= lastSetupDecisionTsUs_)
          ? (firstTxUs - lastSetupDecisionTsUs_)
          : 0;
  lastSetupBuildToTxUs_ =
      (firstTxUs > 0 && lastSetupFrameBuiltTsUs_ > 0 && firstTxUs >= lastSetupFrameBuiltTsUs_)
          ? (firstTxUs - lastSetupFrameBuiltTsUs_)
          : 0;
  lastSetupTxDoneUs_ = lastTxDoneUs_;
  lastSetupReleaseUs_ = lastTxReleaseUs_;
  lastSetupTotalResponseUs_ =
      (lastSetupTxDoneUs_ > 0 && rxEndedUs > 0 && lastSetupTxDoneUs_ >= rxEndedUs)
          ? (lastSetupTxDoneUs_ - rxEndedUs)
          : 0;
  emitEvent("cashless_setup_response_timing",
            String("{\"rx_ended_us\":") + rxEndedUs +
                ",\"tx_ts_us\":" + firstTxUs +
                ",\"reply_delay_us\":" + lastSetupResponseReplyDelayUs_ + "}");
  String slowStage = "none";
  if (lastSetupDecisionToTxUs_ > 20000UL) {
    if (lastSetupBuildToTxUs_ > 20000UL) {
      slowStage = "pre_tx_transport_or_event_overhead";
    } else if (lastSetupFrameBuiltTsUs_ > buildStartedUs &&
               (lastSetupFrameBuiltTsUs_ - buildStartedUs) > 5000UL) {
      slowStage = "frame_build_overhead";
    } else {
      slowStage = "decision_to_tx_gap";
    }
  }
  emitEvent("setup_fast_path_timing",
            String("{\"setup_rx_ts_us\":") + lastSetupRxTsUs_ +
                ",\"setup_rx_end_us\":" + rxEndedUs +
                ",\"setup_decision_ts_us\":" + lastSetupDecisionTsUs_ +
                ",\"setup_frame_built_ts_us\":" + lastSetupFrameBuiltTsUs_ +
                ",\"setup_queue_enqueue_ts_us\":" + lastSetupQueueEnqueueTsUs_ +
                ",\"setup_tx_start_us\":" + firstTxUs +
                ",\"setup_tx_done_us\":" + lastSetupTxDoneUs_ +
                ",\"setup_release_us\":" + lastSetupReleaseUs_ +
                ",\"setup_reply_delay_us\":" + lastSetupResponseReplyDelayUs_ +
                ",\"setup_total_response_us\":" + lastSetupTotalResponseUs_ +
                ",\"decision_to_tx_us\":" + lastSetupDecisionToTxUs_ +
                ",\"build_to_tx_us\":" + lastSetupBuildToTxUs_ +
                ",\"fast_path\":" + boolToJson(lastSetupFastPathUsed_) +
                ",\"profile_id\":\"" + escapeForJson(setupResponseProfileId_) +
                "\"" +
                ",\"slow_stage\":\"" + slowStage + "\"}");
  emitEvent("setup_response_audit",
            String("{\"timestamp_us\":") + firstTxUs +
                ",\"frame_hex\":\"" + bytesToHex(frame, length) +
                "\",\"profile_id\":\"" +
                escapeForJson(setupResponseProfileId_) +
                "\",\"gateway_compat\":" +
                boolToJson(currentSetupResponseGatewayCompat_) +
                ",\"feature_level\":" +
                static_cast<unsigned int>(kCashlessLevel) +
                ",\"currency_code\":\"" +
                escapeForJson(byteToHex(currencyCountryCodeHi) + " " +
                              byteToHex(currencyCountryCodeLo)) +
                "\",\"scale_factor\":" +
                static_cast<unsigned int>(kCashlessScalingFactor) +
                ",\"decimal_places\":" +
                static_cast<unsigned int>(kCashlessDecimalPlaces) +
                ",\"max_response_time\":" +
                static_cast<unsigned int>(responseTime) +
                ",\"options\":" + static_cast<unsigned int>(options) +
                ",\"gateway_currency_profile_id\":\"" +
                escapeForJson(gatewayCurrencyCountryCodeProfileId_) +
                "\",\"currency_code_encoding_mode\":\"" +
                escapeForJson(currencyCountryCodeEncodingMode_) +
                "\",\"currency_code_bytes_hex\":\"" +
                escapeForJson(byteToHex(currencyCountryCodeHi) + " " +
                              byteToHex(currencyCountryCodeLo)) +
                "\",\"currency_encoding_changed_from_profile1\":" +
                boolToJson(currentSetupResponseGatewayCompat_ &&
                           gatewayCurrencyCountryCodeChangedFromProfile1()) +
                ",\"semantic_suspect_field\":\"" +
                escapeForJson(setupResponseSuspectField_) +
                "\",\"checksum\":" +
                static_cast<unsigned int>(lastSetupResponseChecksum_) +
                ",\"payload_length\":" + length + "}");
  return firstTxUs;
}

unsigned long MdbService::sendReaderExpansionIdResponse(
    const char* responseReason) {
  const uint8_t payload[] = {
      // 0x09 = Expansion Identification Data header.
      0x09,
      // 12-byte reader identification string.
      'D', 'E', 'N', 'I', 'S', '0', '0', '0', '0', '0', '0', '1',
      // 3-byte version tuple.
      0x01, 0x01, 0x01,
  };
  static_assert(sizeof(payload) == 16,
                "MDB EXPANSION ID payload must stay 16 bytes before checksum");
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  return transmitResponseFrame(responseReason, "expansion_response", frame, length);
}

unsigned long MdbService::sendCoinChangerSetupResponse(
    const char* responseReason) {
  const uint8_t payload[23] = {
      kMdbCoinChangerFeatureLevel,
      kMdbCoinChangerCurrencyCountryCodeHi,
      kMdbCoinChangerCurrencyCountryCodeLo,
      kMdbCoinChangerScalingFactor,
      kMdbCoinChangerDecimalPlaces,
      static_cast<uint8_t>((kMdbCoinChangerRoutingMask >> 8) & 0xFFU),
      static_cast<uint8_t>(kMdbCoinChangerRoutingMask & 0xFFU),
      kMdbCoinChangerCoinCredits[0],
      kMdbCoinChangerCoinCredits[1],
      kMdbCoinChangerCoinCredits[2],
      kMdbCoinChangerCoinCredits[3],
      kMdbCoinChangerCoinCredits[4],
      kMdbCoinChangerCoinCredits[5],
      kMdbCoinChangerCoinCredits[6],
      kMdbCoinChangerCoinCredits[7],
      kMdbCoinChangerCoinCredits[8],
      kMdbCoinChangerCoinCredits[9],
      kMdbCoinChangerCoinCredits[10],
      kMdbCoinChangerCoinCredits[11],
      kMdbCoinChangerCoinCredits[12],
      kMdbCoinChangerCoinCredits[13],
      kMdbCoinChangerCoinCredits[14],
      kMdbCoinChangerCoinCredits[15],
  };
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  return transmitResponseFrame(responseReason, "coin_setup_response", frame,
                               length);
}

unsigned long MdbService::sendCoinChangerTubeStatusResponse(
    const char* responseReason) {
  const uint8_t payload[] = {0x00, 0x00};
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  return transmitResponseFrame(responseReason, "coin_tube_status", frame,
                               length);
}

bool MdbService::selectCoinChangerCoinType(unsigned long remainingScaled,
                                           uint8_t& coinType,
                                           uint8_t& coinValue) const {
  static const uint8_t kPreferredTypes[] = {4, 3, 2, 1, 0};
  for (size_t i = 0; i < sizeof(kPreferredTypes); ++i) {
    const uint8_t type = kPreferredTypes[i];
    const uint8_t value = kMdbCoinChangerCoinCredits[type];
    if (value == 0 || remainingScaled < value ||
        (coinChangerEnabledMask_ & (1U << type)) == 0) {
      continue;
    }
    coinType = type;
    coinValue = value;
    return true;
  }
  return false;
}

unsigned long MdbService::sendCoinChangerPollResponse(
    const char* responseReason, bool compatMode) {
  const String responseReasonJson =
      responseReason == nullptr ? String("") : String(responseReason);
  const auto emitReplySent = [&](const char* kind, unsigned long txTsUs,
                                 unsigned long emittedScaled,
                                 unsigned long remainingScaled,
                                 const String& replyHex) {
    emitEvent("coin_poll_reply_sent",
              String("{\"kind\":\"") + escapeForJson(String(kind)) +
                  "\",\"compat_mode\":" + boolToJson(compatMode) +
                  ",\"emitted_scaled\":" + emittedScaled +
                  ",\"remaining_scaled\":" + remainingScaled +
                  ",\"pending_amount_minor\":" + coinChangerPendingAmountMinor_ +
                  ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                  ",\"tx_ts_us\":" + txTsUs +
                  ",\"response_reason\":\"" +
                  escapeForJson(responseReasonJson) +
                  "\",\"reply_hex\":\"" + escapeForJson(replyHex) + "\"}");
  };
  const auto emitReplySuppressed = [&](const char* reason,
                                       const char* suppressedKind,
                                       unsigned long emittedScaled,
                                       unsigned long remainingScaled) {
    emitEvent("coin_poll_reply_suppressed",
              String("{\"reason\":\"") + escapeForJson(String(reason)) +
                  "\",\"suppressed_kind\":\"" +
                  escapeForJson(String(suppressedKind)) +
                  "\",\"compat_mode\":" + boolToJson(compatMode) +
                  ",\"pending_amount_minor\":" + coinChangerPendingAmountMinor_ +
                  ",\"pending_scaled\":" + coinChangerPendingScaled_ +
                  ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                  ",\"emitted_scaled\":" + emittedScaled +
                  ",\"remaining_scaled\":" + remainingScaled +
                  ",\"enable_mask_hex\":\"" +
                  escapeForJson(
                      byteToHex(static_cast<uint8_t>(coinChangerEnabledMask_ >> 8)) +
                      " " +
                      byteToHex(static_cast<uint8_t>(coinChangerEnabledMask_ & 0xFFU))) +
                  "\",\"response_reason\":\"" +
                  escapeForJson(responseReasonJson) + "\"}");
  };

  if (compatMode && coinChangerPendingScaled_ > 0 && coinChangerJustResetPending_) {
    emitReplySuppressed("compat_credit_priority", "just_reset", 0,
                        coinChangerPendingScaled_);
    coinChangerJustResetPending_ = false;
    stateDirty_ = true;
  }

  if (coinChangerJustResetPending_) {
    coinChangerJustResetPending_ = false;
    stateDirty_ = true;
    const uint8_t payload[] = {kCoinChangerJustResetStatus};
    uint8_t frame[sizeof(payload) + 1] = {};
    const size_t length =
        mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
    const unsigned long firstTxUs =
        transmitResponseFrame(responseReason, "coin_poll_just_reset", frame,
                              length);
    if (firstTxUs == 0) {
      emitReplySuppressed("just_reset_tx_failed", "just_reset", 0,
                          coinChangerPendingScaled_);
      return 0;
    }
    emitReplySent("just_reset", firstTxUs, 0, coinChangerPendingScaled_,
                  bytesToHex(frame, length));
    return firstTxUs;
  }

  if (coinChangerPendingScaled_ == 0) {
    const unsigned long firstTxUs = sendAckRaw("coin_poll_ack");
    if (firstTxUs == 0) {
      emitReplySuppressed("ack_tx_failed", "ack", 0, 0);
      return 0;
    }
    emitReplySent("ack", firstTxUs, 0, 0,
                  bytesToHex(ackFrame_, ackFrameLength_));
    return firstTxUs;
  }

  uint8_t payload[16] = {};
  size_t payloadLength = 0;
  unsigned long remainingScaled = coinChangerPendingScaled_;
  unsigned long emittedScaled = 0;
  while ((payloadLength + 2) <= sizeof(payload)) {
    uint8_t coinType = 0;
    uint8_t coinValue = 0;
    if (!selectCoinChangerCoinType(remainingScaled, coinType, coinValue)) {
      break;
    }
    payload[payloadLength++] = static_cast<uint8_t>(0x40U | (coinType & 0x0FU));
    payload[payloadLength++] = 0x00;
    remainingScaled -= coinValue;
    emittedScaled += coinValue;
  }

  if (payloadLength == 0) {
    emitReplySuppressed("no_enabled_coin_type_for_pending_amount", "credit", 0,
                        coinChangerPendingScaled_);
    const unsigned long firstTxUs = sendAckRaw("coin_poll_ack");
    if (firstTxUs == 0) {
      emitReplySuppressed("ack_tx_failed_after_credit_suppressed", "ack", 0,
                          coinChangerPendingScaled_);
      return 0;
    }
    emitReplySent("ack", firstTxUs, 0, coinChangerPendingScaled_,
                  bytesToHex(ackFrame_, ackFrameLength_));
    return firstTxUs;
  }

  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, payloadLength, frame, sizeof(frame));
  const unsigned long firstTxUs =
      transmitResponseFrame(responseReason, "coin_poll_credit", frame, length);
  if (firstTxUs == 0) {
    emitReplySuppressed("credit_tx_failed", "credit", emittedScaled,
                        remainingScaled);
    return 0;
  }

  coinChangerPendingScaled_ = remainingScaled;
  coinChangerAwaitingVmcScaled_ += emittedScaled;
  coinChangerAwaitingVmcAmountMinor_ +=
      emittedScaled * static_cast<unsigned long>(kMdbCoinChangerScalingFactor);
  coinChangerLastCreditReplyTxUs_ = firstTxUs;
  if (coinChangerAwaitingVmcTransactionId_.isEmpty()) {
    coinChangerAwaitingVmcTransactionId_ = coinChangerPendingTransactionId_;
  }
  emitReplySent("credit", firstTxUs, emittedScaled, coinChangerPendingScaled_,
                bytesToHex(frame, length));
  emitEvent("coin_reply_sent_local",
            String("{\"amount_minor\":") + coinChangerPendingAmountMinor_ +
                ",\"emitted_scaled\":" + emittedScaled +
                ",\"remaining_scaled\":" + coinChangerPendingScaled_ +
                ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                ",\"tx_ts_us\":" + firstTxUs +
                ",\"reply_hex\":\"" + escapeForJson(bytesToHex(frame, length)) +
                "\",\"transaction_id\":\"" +
                escapeForJson(coinChangerPendingTransactionId_) + "\"}");
  emitEvent("coin_credit_assumed_local_only",
            String("{\"amount_minor\":") + coinChangerPendingAmountMinor_ +
                ",\"emitted_scaled\":" + emittedScaled +
                ",\"remaining_scaled\":" + coinChangerPendingScaled_ +
                ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                ",\"transaction_id\":\"" +
                escapeForJson(coinChangerPendingTransactionId_) + "\"}");
  emitEvent("coin_payment_progress",
            String("{\"amount_minor\":") + coinChangerPendingAmountMinor_ +
                ",\"emitted_scaled\":" + emittedScaled +
                ",\"remaining_scaled\":" + coinChangerPendingScaled_ +
                ",\"awaiting_vmc_scaled\":" + coinChangerAwaitingVmcScaled_ +
                ",\"vmc_credit_accepted\":false,\"local_only\":true"
                ",\"transaction_id\":\"" +
                escapeForJson(coinChangerPendingTransactionId_) + "\"}");
  if (coinChangerPendingScaled_ == 0) {
    emitEvent("coin_payment_completed",
              String("{\"amount_minor\":") + coinChangerPendingAmountMinor_ +
                  ",\"transaction_id\":\"" +
                  escapeForJson(coinChangerPendingTransactionId_) +
                  "\",\"vmc_credit_accepted\":false,"
                  "\"completion_scope\":\"local_reply_only\"}");
  }
  stateDirty_ = true;
  return firstTxUs;
}

unsigned long MdbService::sendCoinChangerExpansionIdResponse(
    const char* responseReason) {
  const uint8_t payload[] = {
      static_cast<uint8_t>(kMdbCoinChangerManufacturer[0]),
      static_cast<uint8_t>(kMdbCoinChangerManufacturer[1]),
      static_cast<uint8_t>(kMdbCoinChangerManufacturer[2]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[0]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[1]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[2]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[3]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[4]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[5]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[6]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[7]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[8]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[9]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[10]),
      static_cast<uint8_t>(kMdbCoinChangerSerial[11]),
      static_cast<uint8_t>(kMdbCoinChangerModel[0]),
      static_cast<uint8_t>(kMdbCoinChangerModel[1]),
      static_cast<uint8_t>(kMdbCoinChangerModel[2]),
      static_cast<uint8_t>(kMdbCoinChangerModel[3]),
      static_cast<uint8_t>(kMdbCoinChangerModel[4]),
      static_cast<uint8_t>(kMdbCoinChangerModel[5]),
      static_cast<uint8_t>(kMdbCoinChangerModel[6]),
      static_cast<uint8_t>(kMdbCoinChangerModel[7]),
      static_cast<uint8_t>(kMdbCoinChangerModel[8]),
      static_cast<uint8_t>(kMdbCoinChangerModel[9]),
      static_cast<uint8_t>(kMdbCoinChangerModel[10]),
      static_cast<uint8_t>(kMdbCoinChangerModel[11]),
      0x01,
      0x00,
      static_cast<uint8_t>((kMdbCoinChangerOptionalFeatureBits >> 24) & 0xFFU),
      static_cast<uint8_t>((kMdbCoinChangerOptionalFeatureBits >> 16) & 0xFFU),
      static_cast<uint8_t>((kMdbCoinChangerOptionalFeatureBits >> 8) & 0xFFU),
      static_cast<uint8_t>(kMdbCoinChangerOptionalFeatureBits & 0xFFU),
  };
  static_assert(sizeof(payload) == 33,
                "Coin changer expansion ID payload must stay 33 bytes");
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  return transmitResponseFrame(responseReason, "coin_expansion_response", frame,
                               length);
}

unsigned long MdbService::sendCoinChangerDiagnosticStatusResponse(
    const char* responseReason) {
  const uint8_t payload[] = {kCoinChangerDiagnosticOkMain,
                             kCoinChangerDiagnosticOkSub};
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  return transmitResponseFrame(responseReason, "coin_diag_status", frame, length);
}

unsigned long MdbService::sendCashlessPollReply(unsigned long now,
                                                unsigned long rxEndedUs,
                                                uint8_t& replyKind,
                                                bool& readerEnabled) {
  replyKind = 0;
  readerEnabled = isReaderEnabled_;

  if (lastResetAckSentUs_ > 0 &&
      (lastPollAfterResetTsUs_ == 0 ||
       lastPollAfterResetTsUs_ < lastResetAckSentUs_)) {
    lastPollAfterResetTsUs_ = rxEndedUs;
    pollMissingAfterResetLogged_ = false;
    nextActionHypothesis_ = "poll_received_after_reset_ack";
    emitEvent("poll_after_reset_seen",
              String("{\"timestamp_us\":") + rxEndedUs +
                  ",\"reader_state\":\"" + readerStateLabel(readerState_) +
                  "\",\"delta_from_reset_ack_us\":" +
                  ((lastResetAckSentUs_ > 0 && rxEndedUs >= lastResetAckSentUs_)
                       ? (rxEndedUs - lastResetAckSentUs_)
                       : 0) +
                  "}");
    emitPostResetProgressionExpectation("poll_after_reset_seen", rxEndedUs);
  }

  if (cashlessJustResetPending_) {
    emitEvent("just_reset_prepared",
              String("{\"timestamp_us\":") + rxEndedUs +
                  ",\"reader_state\":\"" + readerStateLabel(readerState_) +
                  "\"}");
    cashlessJustResetPending_ = false;
    emitEvent("just_reset_pending_cleared",
              String("{\"timestamp_us\":") + rxEndedUs +
                  ",\"reason\":\"poll_just_reset_status_sent\"}");
    replyKind = 2;
    noteExpectedTxKind(DialogueKind::Poll, readerState_, "just_reset_status",
                       rxEndedUs, true, "poll_just_reset");
    const unsigned long firstTxUs = sendJustResetRaw("poll_just_reset");
    justResetSentCount_++;
    justResetAcknowledgedCount_++;
    lastJustResetSentUs_ = firstTxUs;
    nextActionHypothesis_ = "await_enable_or_setup_after_just_reset";
    emitEvent("just_reset_sent",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"tx_kind\":\"just_reset_status\"}");
    emitEvent("just_reset_audit",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"reply_kind\":2,\"expected_tx_kind\":\"just_reset_status\","
                  "\"actual_tx_kind\":\"just_reset_status\"}");
    emitPostResetProgressionExpectation("just_reset_sent", firstTxUs);
    return firstTxUs;
  }

  if (beginSessionPending_ && isReaderEnabled_) {
    const unsigned long nowUs = micros();
    creditFlowResponseDelayUs_ =
        rxEndedUs > 0 && nowUs >= rxEndedUs ? (nowUs - rxEndedUs) : 0;
    const uint16_t amountMinor = beginSessionAmountMinor_;
    noteExpectedTxKind(DialogueKind::Poll, readerState_, "begin_session",
                       rxEndedUs, true, "poll_begin_session");
    const unsigned long firstTxUs =
        sendBeginSession(amountMinor, "poll_begin_session");
    markBeginSessionSent(firstTxUs, amountMinor);
    creditFlowExactReplyDelayUs_ =
        (firstTxUs > 0 && rxEndedUs > 0 && firstTxUs >= rxEndedUs)
            ? (firstTxUs - rxEndedUs)
            : 0;
    if (creditFlowActive_) {
      creditFlowBeginSessionSent_ = true;
      creditFlowAwaitingAck_ = true;
      creditFlowObservationActive_ = true;
      creditFlowObservationEndsAt_ = now + kCreditFlowObservationWindowMs;
      creditFlowPostReplyFrameCount_ = 0;
      creditFlowObservedFamilies_ = "";
      creditFlowCandidateBytes_ = "03";
    }
    beginSessionPending_ = false;
    beginSessionAmountMinor_ = 0;
    replyKind = 3;
    readerEnabled = isReaderEnabled_;
    return firstTxUs;
  }

  replyKind = 4;
  readerEnabled = isReaderEnabled_;
  noteExpectedTxKind(DialogueKind::Poll, readerState_, "ack", rxEndedUs, true,
                     isReaderEnabled_ ? "poll_no_pending_data"
                                      : "poll_state_not_enabled");
  return sendAckRaw(isReaderEnabled_ ? "no_pending_data" : "state_not_enabled");
}

void MdbService::markSetupResponseSent(unsigned long firstTxUs, bool awaitAck) {
  if (cashlessSetupResponseAwaitingAck_) {
    markSetupResponseAckMissing("replaced_by_new_setup_response");
  }
  cashlessSetupResponsePending_ = awaitAck;
  cashlessSetupResponseAwaitingAck_ = awaitAck;
  cashlessSetupResponseSentAtMs_ = millis();
  cashlessSetupResponseSentUs_ = firstTxUs;
  if (!awaitAck) {
    emitEvent("setup_response_ack_semantics_overridden",
              String("{\"timestamp_us\":") + firstTxUs +
                  ",\"mode\":\"" +
                  escapeForJson(
                      wrapperAckSemanticsModeLabel(wrapperAckSemanticsMode_)) +
                  "\",\"gateway_compat\":" +
                  boolToJson(currentSetupResponseGatewayCompat_) +
                  ",\"reason\":\"gateway_wrapper_continuation_wait\"}");
  }
}

void MdbService::markSetupResponseAckReceived(unsigned long ackTsUs) {
  if (!cashlessSetupResponseAwaitingAck_) {
    return;
  }

  const unsigned long waitMs =
      cashlessSetupResponseSentAtMs_ > 0 ? (millis() - cashlessSetupResponseSentAtMs_) : 0;
  const unsigned long waitUs =
      (cashlessSetupResponseSentUs_ > 0 && ackTsUs >= cashlessSetupResponseSentUs_)
          ? (ackTsUs - cashlessSetupResponseSentUs_)
          : 0;
  cashlessSetupResponseAwaitingAck_ = false;
  cashlessSetupResponsePending_ = false;
  emitEvent("cashless_setup_response_ack_received",
            String("{\"ack\":true,\"ack_ts_us\":") + ackTsUs +
                ",\"setup_response_tx_ts_us\":" + cashlessSetupResponseSentUs_ +
                ",\"wait_us\":" + waitUs + ",\"wait_ms\":" + waitMs + "}");
}

void MdbService::markSetupResponseAckMissing(const char* reason,
                                             const String& extraJson) {
  if (!cashlessSetupResponseAwaitingAck_) {
    return;
  }

  const unsigned long waitMs =
      cashlessSetupResponseSentAtMs_ > 0 ? (millis() - cashlessSetupResponseSentAtMs_) : 0;
  const unsigned long nowUs = micros();
  cashlessSetupResponseAwaitingAck_ = false;
  cashlessSetupResponsePending_ = false;
  noteGatewayCompatFollowupTimeout(nowUs);
  String json = String("{\"ack\":false,\"reason\":\"") + reason +
                "\",\"setup_response_tx_ts_us\":" + cashlessSetupResponseSentUs_ +
                ",\"wait_ms\":" + waitMs;
  if (setupResponseRejectedByVmc_ != "true") {
    setupResponseRejectedByVmc_ = "unknown";
    setupRejectionBasis_ = "timeout_waiting_for_followup";
  }
  if (!extraJson.isEmpty()) {
    json += ",";
    json += extraJson;
  }
  json += "}";
  emitEvent("cashless_setup_response_ack_missing", json);
}

void MdbService::emitSetupResponseRejectionAudit(const char* basis,
                                                 unsigned long tsUs,
                                                 const machine::Frame* followupFrame,
                                                 const char* followupKind,
                                                 const String& extraJson) {
  String json = String("{\"timestamp_us\":") + tsUs +
                ",\"basis\":\"" +
                escapeForJson(basis == nullptr ? "unknown" : String(basis)) +
                "\",\"setup_response_profile_id\":\"" +
                escapeForJson(setupResponseProfileId_) +
                "\",\"gateway_compat_response_profile_id\":\"" +
                escapeForJson(gatewayCompatResponseProfileIdLabel()) +
                "\",\"gateway_currency_profile_id\":\"" +
                escapeForJson(gatewayCurrencyCountryCodeProfileId_) +
                "\",\"currency_code_encoding_mode\":\"" +
                escapeForJson(currencyCountryCodeEncodingMode_) +
                "\",\"setup_response_suspect_field\":\"" +
                escapeForJson(setupResponseSuspectField_) +
                "\",\"setup_response_rejected_by_vmc\":\"" +
                escapeForJson(setupResponseRejectedByVmc_) +
                "\",\"setup_rejection_basis\":\"" +
                escapeForJson(setupRejectionBasis_) +
                "\",\"setup_response_tx_ts_us\":" + lastSetupResponseTxUs_ +
                ",\"setup_reply_delay_us\":" + lastSetupResponseReplyDelayUs_ +
                ",\"setup_total_response_us\":" + lastSetupTotalResponseUs_ +
                ",\"setup_response_checksum\":" +
                static_cast<unsigned int>(lastSetupResponseChecksum_) +
                ",\"setup_response_options\":" +
                static_cast<unsigned int>(lastSetupResponseOptions_) +
                ",\"setup_response_response_time\":" +
                static_cast<unsigned int>(lastSetupResponseResponseTime_) +
                ",\"setup_response_currency_code_bytes_hex\":\"" +
                escapeForJson(byteToHex(lastSetupResponseCountryCodeHi_) + " " +
                              byteToHex(lastSetupResponseCountryCodeLo_)) +
                "\",\"last_setup_variant\":\"" +
                escapeForJson(lastSetupVariant_) +
                "\",\"repeated_setup_count\":" + repeatedSetupCount_ +
                ",\"repeated_setup_same_payload_count\":" +
                repeatedSetupSamePayloadCount_ +
                ",\"repeated_setup_then_reset_observed\":" +
                boolToJson(repeatedSetupThenResetObserved_) +
                ",\"reset_after_setup_retry_count\":" +
                resetAfterSetupRetryCount_ +
                ",\"last_reset_cause_guess\":\"" +
                escapeForJson(lastResetCauseGuess_) +
                "\",\"wrapper_phase\":\"" +
                escapeForJson(gatewayWrapperPhaseLabel()) +
                "\",\"wrapper_fsm_state\":\"" +
                escapeForJson(wrapperFsmStateLabel(wrapperFsmState_)) +
                "\",\"wrapper_expected_next_rx_kind\":\"" +
                escapeForJson(wrapperExpectedNextRxKindLabel()) +
                "\",\"wrapper_expected_next_action\":\"" +
                escapeForJson(wrapperExpectedNextActionLabel()) +
                "\",\"wrapper_continuation_kind\":\"" +
                escapeForJson(wrapperContinuationKind_) +
                "\",\"wrapper_continuation_interpretation\":\"" +
                escapeForJson(wrapperContinuationInterpretation_) +
                "\",\"last_rx_kind\":\"" +
                escapeForJson(dialogueKindLabel(lastRxKind_)) +
                "\",\"last_tx_kind\":\"" +
                escapeForJson(lastTxKind_) + "\"";
  if (followupFrame != nullptr) {
    const unsigned long deltaUs =
        (lastSetupResponseTxUs_ > 0 && tsUs >= lastSetupResponseTxUs_)
            ? (tsUs - lastSetupResponseTxUs_)
            : 0;
    json += ",\"followup_frame_hex\":\"" +
            escapeForJson(machine::normalizedHex(*followupFrame)) +
            "\",\"followup_kind\":\"" +
            escapeForJson(followupKind == nullptr
                              ? dialogueKindLabel(classifyRxFrameKind(*followupFrame))
                              : String(followupKind)) +
            "\",\"delta_from_setup_response_us\":" + deltaUs;
  }
  if (!extraJson.isEmpty()) {
    json += ",";
    json += extraJson;
  }
  json += "}";
  emitEvent("setup_response_rejection_audit", json);
}

unsigned long MdbService::sendJustResetRaw(const char* responseReason) {
  uint8_t frame[2] = {};
  const uint8_t payload[] = {0x00};
  const size_t length = mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  return transmitResponseFrame(responseReason, "just_reset_status", frame, length);
}

void MdbService::sendJustResetStatus() {
  const unsigned long firstTxUs = sendJustResetRaw();
  emitEvent("JUST_RESET_SENT",
            String("{\"status_byte\":0,\"tx_ts_us\":") + firstTxUs + "}");
}

unsigned long MdbService::sendAckRaw(const char* responseReason) {
  return transmitResponseFrame(responseReason, "ack", ackFrame_, ackFrameLength_);
}

// Отправляет ACK в линию автомата.
void MdbService::sendAck() {
  const unsigned long firstTxUs = sendAckRaw("send_ack");
  emitEvent("ACK_SENT",
            String("{\"trigger\":\"sendAck\",\"tx_ts_us\":") + firstTxUs +
                "}");
}

// Отправляет NAK в линию автомата.
void MdbService::sendNak() {
  uint8_t frame[2] = {};
  const size_t length = mdb::buildSingleByteResponse(mdb::kNak, frame, sizeof(frame));
  transmitResponseFrame("nak_response", "nak", frame, length);
}

// Отправляет RET в линию автомата.
void MdbService::sendRet() {
  uint8_t frame[2] = {};
  const size_t length = mdb::buildSingleByteResponse(mdb::kRet, frame, sizeof(frame));
  transmitResponseFrame("ret_response", "ret", frame, length);
}

// Отправляет подтверждение vend с суммой.
unsigned long MdbService::sendVendApproved(unsigned long amountMinor,
                                           const char* responseReason) {
  if (amountMinor != creditFlowAmountMinor_) {
    creditFlowAmountMinor_ = static_cast<uint16_t>(amountMinor > 0xFFFFUL ? 0xFFFFU : amountMinor);
    rebuildPrecomputedFrames();
  }
  const unsigned long firstTxUs = transmitResponseFrame(
      responseReason, "vend_approved", vendApprovedFrame_,
      vendApprovedFrameLength_);
  emitEvent("cashless_tx_packet_debug",
            String("{\"kind\":\"vend_approved\",\"payload_hex\":\"") +
                bytesToHex(vendApprovedPayload_, sizeof(vendApprovedPayload_)) +
                "\",\"frame_hex\":\"" +
                bytesToHex(vendApprovedFrame_, vendApprovedFrameLength_) +
                "\",\"checksum_hex\":\"" +
                byteToHex(vendApprovedFrame_[vendApprovedFrameLength_ - 1]) +
                "\",\"checksum_value\":" +
                vendApprovedFrame_[vendApprovedFrameLength_ - 1] +
                ",\"ninth_bit_forced_zero\":true}");
  return firstTxUs;
}

// Отправляет отказ vend с суммой.
void MdbService::sendVendDenied(unsigned long amountMinor) {
  uint8_t payload[3] = {0x06, static_cast<uint8_t>((amountMinor >> 8) & 0xFF),
                        static_cast<uint8_t>(amountMinor & 0xFF)};
  uint8_t frame[4] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  transmitResponseFrame("vend_denied", "vend_denied", frame, length);
}

void MdbService::sendVendDeniedMinimal() {
  transmitResponseFrame("vend_denied_minimal", "vend_denied_minimal",
                        vendDeniedFrame_, vendDeniedFrameLength_);
}

void MdbService::sendRevalueLimitZero() {
  const uint8_t payload[] = {0x05, 0xFF};
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  transmitResponseFrame("revalue_limit_zero", "revalue_limit_zero", frame, length);
}

void MdbService::sendEndSession() {
  const uint8_t payload[] = {0x04};
  uint8_t frame[sizeof(payload) + 1] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  transmitResponseFrame("end_session", "end_session", frame, length);
}

// Отправляет завершение текущей сессии.
void MdbService::sendSessionComplete() {
  const uint8_t payload[] = {0x07};
  uint8_t frame[3] = {};
  const size_t length =
      mdb::buildSlaveBlock(payload, sizeof(payload), frame, sizeof(frame));
  transmitResponseFrame("session_complete", "session_complete", frame, length);
}

unsigned long MdbService::sendBeginSession(uint16_t amountMinor,
                                           const char* responseReason) {
  if (amountMinor != creditFlowAmountMinor_) {
    creditFlowAmountMinor_ = amountMinor;
    rebuildPrecomputedFrames();
  }
  const unsigned long firstTxUs = transmitResponseFrame(
      responseReason, "begin_session", beginSessionFrame_,
      beginSessionFrameLength_);
  emitEvent("cashless_tx_packet_debug",
            String("{\"kind\":\"begin_session\",\"payload_hex\":\"") +
                bytesToHex(beginSessionPayload_, sizeof(beginSessionPayload_)) +
                "\",\"frame_hex\":\"" +
                bytesToHex(beginSessionFrame_, beginSessionFrameLength_) +
                "\",\"checksum_hex\":\"" +
                byteToHex(beginSessionFrame_[beginSessionFrameLength_ - 1]) +
                "\",\"checksum_value\":" +
                beginSessionFrame_[beginSessionFrameLength_ - 1] +
                ",\"ninth_bit_forced_zero\":true}");
  return firstTxUs;
}

void MdbService::rebuildPrecomputedFrames() {
  ackFrameLength_ =
      mdb::buildSingleByteResponse(mdb::kAck, ackFrame_, sizeof(ackFrame_));
  vendDeniedFrameLength_ = mdb::buildSlaveBlock(vendDeniedPayload_,
                                                sizeof(vendDeniedPayload_),
                                                vendDeniedFrame_,
                                                sizeof(vendDeniedFrame_));

  // VEND APPROVED amount is sent exactly as backend minor units in two bytes.
  // Example: 5000 (minor units) => 0x13 0x88 => 50.00 KGS with scale factor 100.
  vendApprovedPayload_[0] = 0x02;
  vendApprovedPayload_[1] = static_cast<uint8_t>((creditFlowAmountMinor_ >> 8) & 0xFF);
  vendApprovedPayload_[2] = static_cast<uint8_t>(creditFlowAmountMinor_ & 0xFF);
  vendApprovedFrameLength_ = mdb::buildSlaveBlock(vendApprovedPayload_,
                                                  sizeof(vendApprovedPayload_),
                                                  vendApprovedFrame_,
                                                  sizeof(vendApprovedFrame_));

  beginSessionPayload_[0] = kCashlessBeginSession;
  beginSessionPayload_[1] = static_cast<uint8_t>((creditFlowAmountMinor_ >> 8) & 0xFF);
  beginSessionPayload_[2] = static_cast<uint8_t>(creditFlowAmountMinor_ & 0xFF);
  beginSessionFrameLength_ = mdb::buildSlaveBlock(beginSessionPayload_,
                                                  sizeof(beginSessionPayload_),
                                                  beginSessionFrame_,
                                                  sizeof(beginSessionFrame_));
}

// Разбирает HEX-строку в массив байтов для raw-send.
bool MdbService::parseHexPayload(const String& hexPayload, uint8_t* buffer,
                                 size_t& length) {
  String normalized;
  normalized.reserve(hexPayload.length());

  for (size_t i = 0; i < hexPayload.length(); ++i) {
    const char ch = hexPayload[i];
    if (ch == ' ' || ch == ':' || ch == '-' || ch == '\n' || ch == '\r' ||
        ch == '\t') {
      continue;
    }
    normalized += ch;
  }

  if (normalized.length() == 0 || (normalized.length() % 2) != 0) {
    return false;
  }

  length = normalized.length() / 2;
  if (length > 64) {
    return false;
  }

  auto parseNibble = [](char ch) -> int {
    if (ch >= '0' && ch <= '9') {
      return ch - '0';
    }
    if (ch >= 'a' && ch <= 'f') {
      return ch - 'a' + 10;
    }
    if (ch >= 'A' && ch <= 'F') {
      return ch - 'A' + 10;
    }
    return -1;
  };

  for (size_t i = 0; i < length; ++i) {
    const int hi = parseNibble(normalized[i * 2]);
    const int lo = parseNibble(normalized[i * 2 + 1]);
    if (hi < 0 || lo < 0) {
      return false;
    }
    buffer[i] = static_cast<uint8_t>((hi << 4) | lo);
  }

  return true;
}

// Поддерживает state machine в актуальном состоянии по внешним условиям.
void MdbService::applyDesiredState(unsigned long now) {
  session_.update(connectionService_.isWebSocketConnected(), now);
}

// Преобразует состояние FSM в строку.
const char* MdbService::stateToString(CashlessSession::State state) const {
  return CashlessSession::stateToString(state);
}
