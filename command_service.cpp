#include "command_service.h"

#include <ArduinoJson.h>
#include <cstring>

#include "logging_utils.h"
#include "mdb_service.h"
#include "ota_manager.h"
#include "pulse_config_service.h"
#include "pulse_service.h"
#include "uart_service.h"

namespace {
constexpr bool kLogIncomingWsText = false;

bool containsRawToken(const uint8_t* payload, size_t length, const char* token) {
  if (payload == nullptr || token == nullptr) {
    return false;
  }

  const size_t tokenLen = strlen(token);
  if (tokenLen == 0 || length < tokenLen) {
    return false;
  }

  for (size_t i = 0; i + tokenLen <= length; ++i) {
    if (memcmp(payload + i, token, tokenLen) == 0) {
      return true;
    }
  }
  return false;
}

bool isIgnorableTransportNoiseRaw(const uint8_t* payload, size_t length) {
  return containsRawToken(payload, length, "\"type\":\"connected\"") ||
         containsRawToken(payload, length, "\"type\":\"disconnected\"") ||
         containsRawToken(payload, length, "\"type\":\"ping\"") ||
         containsRawToken(payload, length, "\"type\":\"pong\"") ||
         containsRawToken(payload, length, "\"type\":\"hello\"") ||
         containsRawToken(payload, length, "\"type\":\"welcome\"") ||
         containsRawToken(payload, length, "\"type\":\"status\"") ||
         containsRawToken(payload, length, "\"type\":\"keepalive\"");
}

bool isIgnorableTransportType(const String& messageType) {
  return messageType == "connected" || messageType == "disconnected" ||
         messageType == "ping" || messageType == "pong" ||
         messageType == "hello" || messageType == "welcome" ||
         messageType == "status" || messageType == "keepalive";
}
}  // namespace

CommandService::CommandService(PulseService& pulseService, MdbService& mdbService,
                               PulseConfigService& pulseConfigService,
                               UartService& uartService, OtaManager& otaService)
    : pulseService_(pulseService),
      mdbService_(mdbService),
      pulseConfigService_(pulseConfigService),
      uartService_(uartService),
      otaService_(otaService) {}

// Разбирает JSON-команду от backend и маршрутизирует её в нужный сервис.
void CommandService::handleTextMessage(const uint8_t* payload, size_t length) {
  if (kLogIncomingWsText) {
    logSerialText("WS text: ");
    logSerialBytes(payload, length);
    logSerialLine("");
  }

  // Ранний отсев служебного websocket-мусора даже если он приходит
  // фрагментами/повторами и не является полноценным JSON-командным пакетом.
  if (isIgnorableTransportNoiseRaw(payload, length)) {
    return;
  }

  JsonDocument doc;
  const auto error = deserializeJson(doc, payload, length);
  if (error) {
    logSerialLine(String("WS JSON parse failed: ") + error.c_str());
    mdbService_.emitControlEvent(
        "transport_error",
        String("{\"reason\":\"json_parse_failed\",\"error\":\"") +
            error.c_str() + "\",\"length\":" + length + "}");
    return;
  }

  const String messageType = String(doc["type"] | "");
  if (messageType != "command") {
    if (isIgnorableTransportType(messageType)) {
      return;
    }
    mdbService_.emitControlEvent(
        "command_rejected",
        String("{\"command\":\"\",\"reason\":\"unsupported_message_type\","
               "\"type\":\"") +
            messageType + "\"}");
    return;
  }

  JsonVariant payloadNode = doc["payload"];
  if (!payloadNode.is<JsonObject>()) {
    mdbService_.emitControlEvent(
        "command_rejected",
        "{\"command\":\"\",\"reason\":\"missing_payload_object\"}");
    return;
  }

  const char* commandName = payloadNode["command"] | "";
  const String command = String(commandName);
  mdbService_.emitControlEvent(
      "command_received",
      String("{\"command\":\"") + command + "\",\"length\":" + length + "}");

  if (command == "pay") {
    const unsigned long amountMinor =
        payloadNode["payload"]["amount"].is<unsigned long>()
            ? payloadNode["payload"]["amount"].as<unsigned long>()
            : 0;
    const String transport =
        String(payloadNode["payload"]["transport"] | "pulse");

    if (transport == "pulse") {
      pulseService_.requestPulse(amountMinor);
      return;
    }

    if (transport == "mdb") {
      uartService_.deactivate();
      const String transactionId =
          String(payloadNode["payload"]["transaction_id"] | "");
      mdbService_.requestCoinPayment(amountMinor, transactionId);
      return;
    }

    if (transport == "uart") {
      mdbService_.deactivate();
      uartService_.requestPay(amountMinor);
      return;
    }

    logSerialLine(String("Unsupported pay transport: ") + transport);
    return;
  }

  if (command == "reboot") {
    pulseService_.requestReboot();
    return;
  }

  if (command == "refresh_pulse_config") {
    logSerialLine("Pulse config refresh requested");
    pulseConfigService_.requestRefresh();
    return;
  }

  if (command == "ota_update") {
    const char* url = payloadNode["payload"]["url"] | "";
    const char* version = payloadNode["payload"]["version"] | "";
    const char* sha256 = payloadNode["payload"]["sha256"] | "";
    otaService_.requestUpdate(String(url), String(version), String(sha256));
    return;
  }

  if (command == "mdb_probe") {
    uartService_.deactivate();
    mdbService_.requestProbe();
    return;
  }

  if (command == "mdb_irq_snapshot") {
    uartService_.deactivate();
    mdbService_.requestIrqSnapshot();
    return;
  }

  if (command == "phy_decoder_status") {
    uartService_.deactivate();
    mdbService_.requestPhyDecoderStatus();
    return;
  }

  if (command == "mdb_clear_session") {
    uartService_.deactivate();
    mdbService_.requestClearSession();
    return;
  }

  if (command == "mdb_approve") {
    uartService_.deactivate();
    const unsigned long amountMinor =
        payloadNode["payload"]["amount"].is<unsigned long>()
            ? payloadNode["payload"]["amount"].as<unsigned long>()
            : 0;
    const String transactionId =
        String(payloadNode["payload"]["transaction_id"] | "");
    mdbService_.requestApproveCredit(amountMinor, transactionId);
    return;
  }

  if (command == "mdb_monitor_start") {
    uartService_.deactivate();
    mdbService_.setMonitorEnabled(true);
    return;
  }

  if (command == "mdb_passive_sniff_on") {
    uartService_.deactivate();
    mdbService_.setPassiveSniffEnabled(true);
    return;
  }

  if (command == "mdb_passive_sniff_off") {
    uartService_.deactivate();
    mdbService_.setPassiveSniffEnabled(false);
    return;
  }

  if (command == "mdb_sniff_recent") {
    uartService_.deactivate();
    mdbService_.requestSniffRecent();
    return;
  }

  if (command == "mdb_sniff_summary") {
    uartService_.deactivate();
    mdbService_.requestSniffSummary();
    return;
  }

  if (command == "mdb_sniff_stats") {
    uartService_.deactivate();
    mdbService_.requestSniffStats();
    return;
  }

  if (command == "mdb_sniff_clear") {
    uartService_.deactivate();
    mdbService_.requestSniffClear();
    return;
  }

  if (command == "mdb_set_expected_address") {
    uartService_.deactivate();
    const int address =
        payloadNode["payload"]["expected_address"].is<int>()
            ? payloadNode["payload"]["expected_address"].as<int>()
            : -1;
    mdbService_.setExpectedAddress(address);
    return;
  }

  if (command == "mdb_set_cashless_address") {
    uartService_.deactivate();
    const int address =
        payloadNode["payload"]["cashless_address"].is<int>()
            ? payloadNode["payload"]["cashless_address"].as<int>()
            : 2;
    mdbService_.setCashlessAddress(address);
    return;
  }

  if (command == "mdb_gateway_profile") {
    uartService_.deactivate();
    const int profileId =
        payloadNode["payload"]["profile_id"].is<int>()
            ? payloadNode["payload"]["profile_id"].as<int>()
            : 0;
    mdbService_.setGatewayCompatResponseProfile(
        static_cast<uint8_t>(profileId < 0 ? 0 : profileId));
    return;
  }

  if (command == "mdb_setup_response_experiment") {
    uartService_.deactivate();
    const bool enabled = payloadNode["payload"]["enabled"].is<bool>()
                             ? payloadNode["payload"]["enabled"].as<bool>()
                             : true;
    const int currencyHi =
        payloadNode["payload"]["currency_code_hi"].is<int>()
            ? payloadNode["payload"]["currency_code_hi"].as<int>()
            : 0;
    const int currencyLo =
        payloadNode["payload"]["currency_code_lo"].is<int>()
            ? payloadNode["payload"]["currency_code_lo"].as<int>()
            : 0;
    const int responseTime =
        payloadNode["payload"]["max_response_time"].is<int>()
            ? payloadNode["payload"]["max_response_time"].as<int>()
            : 1;
    const int options =
        payloadNode["payload"]["options"].is<int>()
            ? payloadNode["payload"]["options"].as<int>()
            : 0;
    const String label = String(payloadNode["payload"]["label"] | "");
    mdbService_.configureSetupResponseExperiment(
        enabled, static_cast<uint8_t>(currencyHi < 0 ? 0 : currencyHi & 0xFF),
        static_cast<uint8_t>(currencyLo < 0 ? 0 : currencyLo & 0xFF),
        static_cast<uint8_t>(responseTime < 0 ? 0 : responseTime & 0xFF),
        static_cast<uint8_t>(options < 0 ? 0 : options & 0xFF), label);
    return;
  }


  if (command == "mdb_experiment_enable") {
    uartService_.deactivate();
    mdbService_.setExperimentEnabled(true);
    return;
  }

  if (command == "mdb_experiment_disable") {
    uartService_.deactivate();
    mdbService_.setExperimentEnabled(false);
    return;
  }

  if (command == "mdb_experiment_fire_once") {
    uartService_.deactivate();
    mdbService_.requestExperimentFireOnce();
    return;
  }

  if (command == "mdb_experiment_configure") {
    uartService_.deactivate();
    const uint8_t expectedAddress =
        payloadNode["payload"]["expected_address"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["expected_address"].as<int>())
            : 12;
    const uint8_t triggerAddress =
        payloadNode["payload"]["trigger_address"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["trigger_address"].as<int>())
            : 12;
    const uint8_t triggerCommand =
        payloadNode["payload"]["trigger_command"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["trigger_command"].as<int>())
            : 6;
    const uint8_t replyByte =
        payloadNode["payload"]["reply_byte"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["reply_byte"].as<int>())
            : 0x00;
    const unsigned long replyDelayMs =
        payloadNode["payload"]["reply_delay_ms"].is<unsigned long>()
            ? payloadNode["payload"]["reply_delay_ms"].as<unsigned long>()
            : 25;
    const unsigned long cooldownMs =
        payloadNode["payload"]["cooldown_ms"].is<unsigned long>()
            ? payloadNode["payload"]["cooldown_ms"].as<unsigned long>()
            : 45000;
    const uint8_t maxRepliesPerSession =
        payloadNode["payload"]["max_replies_per_session"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["max_replies_per_session"].as<int>())
            : 1;
    const uint8_t baselineSeriesCount =
        payloadNode["payload"]["baseline_series_count"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["baseline_series_count"].as<int>())
            : 0;
    const char* experimentMode =
        payloadNode["payload"]["experiment_mode"].is<const char*>()
            ? payloadNode["payload"]["experiment_mode"].as<const char*>()
            : "single_byte_probe";
    const uint8_t protocolProbeCandidateId =
        payloadNode["payload"]["protocol_probe_candidate_id"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["protocol_probe_candidate_id"].as<int>())
            : 0;
    uint8_t encodedBaselineSeriesCount = baselineSeriesCount;
    if (strcmp(experimentMode, "protocol_shaped_probe") == 0 &&
        protocolProbeCandidateId > 0) {
      encodedBaselineSeriesCount =
          static_cast<uint8_t>(0x80 | (protocolProbeCandidateId & 0x7F));
    }
    const unsigned long observationWindowMs =
        payloadNode["payload"]["observation_window_ms"].is<unsigned long>()
            ? payloadNode["payload"]["observation_window_ms"].as<unsigned long>()
            : 45000;
    const bool disableOnAnyError =
        payloadNode["payload"]["disable_on_any_error"].is<bool>()
            ? payloadNode["payload"]["disable_on_any_error"].as<bool>()
            : true;
    mdbService_.configureExperiment(
        expectedAddress, triggerAddress, triggerCommand, replyByte, replyDelayMs,
        cooldownMs, maxRepliesPerSession, encodedBaselineSeriesCount,
        observationWindowMs, disableOnAnyError);
    return;
  }

  if (command == "mdb_credit_flow_start") {
    uartService_.deactivate();
    const unsigned long amountMinor =
        payloadNode["payload"]["amount_minor"].is<unsigned long>()
            ? payloadNode["payload"]["amount_minor"].as<unsigned long>()
            : 1000;
    mdbService_.startCreditFlowStrategy(
        static_cast<uint16_t>(amountMinor > 0xFFFFUL ? 0xFFFFU : amountMinor));
    return;
  }

  if (command == "mdb_credit_flow_stop") {
    uartService_.deactivate();
    mdbService_.stopCreditFlowStrategy();
    return;
  }

  if (command == "mdb_experiment_configure_protocol_probe") {
    uartService_.deactivate();
    const uint8_t expectedAddress =
        payloadNode["payload"]["expected_address"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["expected_address"].as<int>())
            : 12;
    const uint8_t triggerAddress =
        payloadNode["payload"]["trigger_address"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["trigger_address"].as<int>())
            : 12;
    const uint8_t triggerCommand =
        payloadNode["payload"]["trigger_command"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["trigger_command"].as<int>())
            : 6;
    const uint8_t protocolProbeCandidateId =
        payloadNode["payload"]["protocol_probe_candidate_id"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["protocol_probe_candidate_id"].as<int>())
            : 1;
    const unsigned long replyDelayMs =
        payloadNode["payload"]["reply_delay_ms"].is<unsigned long>()
            ? payloadNode["payload"]["reply_delay_ms"].as<unsigned long>()
            : 25;
    const unsigned long cooldownMs =
        payloadNode["payload"]["cooldown_ms"].is<unsigned long>()
            ? payloadNode["payload"]["cooldown_ms"].as<unsigned long>()
            : 45000;
    const uint8_t maxRepliesPerSession =
        payloadNode["payload"]["max_replies_per_session"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["max_replies_per_session"].as<int>())
            : 1;
    const unsigned long observationWindowMs =
        payloadNode["payload"]["observation_window_ms"].is<unsigned long>()
            ? payloadNode["payload"]["observation_window_ms"].as<unsigned long>()
            : 45000;
    const bool disableOnAnyError =
        payloadNode["payload"]["disable_on_any_error"].is<bool>()
            ? payloadNode["payload"]["disable_on_any_error"].as<bool>()
            : true;
    mdbService_.configureExperiment(
        expectedAddress, triggerAddress, triggerCommand, 0xAA, replyDelayMs,
        cooldownMs, maxRepliesPerSession,
        static_cast<uint8_t>(0x80 | (protocolProbeCandidateId & 0x7F)),
        observationWindowMs, disableOnAnyError);
    return;
  }

  if (command == "mdb_experiment_run_protocol_probe_once") {
    uartService_.deactivate();
    mdbService_.requestExperimentFireOnce();
    return;
  }

  if (command == "mdb_probe_tx") {
    uartService_.deactivate();
    mdbService_.requestProbeTx();
    return;
  }

  if (command == "mdb_rx_invert_on") {
    uartService_.deactivate();
    mdbService_.setRxInvertEnabled(true);
    return;
  }

  if (command == "mdb_rx_invert_off") {
    uartService_.deactivate();
    mdbService_.setRxInvertEnabled(false);
    return;
  }

  if (command == "mdb_pulse_test") {
    uartService_.deactivate();
    mdbService_.requestPulseTest();
    return;
  }

  if (command == "mdb_tx_hold_low_test") {
    uartService_.deactivate();
    mdbService_.requestHoldTxLowTest();
    return;
  }

  if (command == "mdb_monitor_stop") {
    uartService_.deactivate();
    mdbService_.setMonitorEnabled(false);
    return;
  }

  if (command == "mdb_raw_send") {
    uartService_.deactivate();
    const char* hexPayload = payloadNode["payload"]["hex"] | "";
    mdbService_.sendRawHex(String(hexPayload));
    return;
  }

  if (command == "uart_probe") {
    mdbService_.deactivate();
    uartService_.requestProbe();
    return;
  }

  if (command == "uart_monitor_start") {
    mdbService_.deactivate();
    uartService_.setMonitorEnabled(true);
    return;
  }

  if (command == "uart_monitor_stop") {
    mdbService_.deactivate();
    uartService_.setMonitorEnabled(false);
    return;
  }

  if (command == "uart_probe_tx") {
    mdbService_.deactivate();
    uartService_.requestProbeTx();
    return;
  }

  if (command == "uart_raw_send") {
    mdbService_.deactivate();
    const char* hexPayload = payloadNode["payload"]["hex"] | "";
    uartService_.sendRawHex(String(hexPayload));
    return;
  }

  mdbService_.emitControlEvent(
      "command_rejected",
      String("{\"command\":\"") + command +
          "\",\"reason\":\"unsupported_command\"}");
  logSerialLine(String("Unsupported command: ") + command);
}

// Возвращает текущую MDB-сводку для debug/API-слоя.
String CommandService::buildMdbDebugStateJson() const {
  return mdbService_.buildDebugStateJson();
}
