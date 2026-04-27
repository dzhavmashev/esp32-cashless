#include <Arduino.h>
#include <esp_system.h>
#include <driver/gpio.h>
#include <string.h>

#include "device_config.h"

#define MDB_RX_ONLY_SNIFFER 1

#if MDB_RX_ONLY_SNIFFER
#include "mdb_bitbang_receiver.h"

static constexpr uint8_t MDB_TEST_TX_PIN = MDB_TX_PIN;

// GPIO LOW  = линия отпущена / MDB logical HIGH
// GPIO HIGH = линия притянута вниз / MDB logical LOW
// Если VMC не реагирует на ответы, первым делом попробуй поменять true -> false.
static constexpr bool MDB_TX_GPIO_HIGH_ASSERTS_LOW = true;
static constexpr uint32_t MDB_BIT_US = 92;
static constexpr uint32_t MDB_INTER_BYTE_GAP_US = 0;
static constexpr size_t MDB_TEST_MAX_TX_BYTES = 40;
static constexpr bool MDB_SLAVE_DATA_CHECKSUM_MODE_BIT = true;
// A/B switch for POLL->JUST_RESET response.
// true  => single byte: 0B raw9=10B
// false => data block: 0B 0B raw9=0B 10B
static constexpr bool MDB_JUST_RESET_SINGLE_BYTE = true;

// HOT PATH NOTE:
// Any Serial.print() inside handleMdbFrame() can delay processing of the next MDB
// command. Keep these false while testing authorization. Turn on one by one only
// after the VMC reaches SETUP/TUBE/COIN_TYPE reliably.
static constexpr bool MDB_LOG_TX_TIMING = false;
static constexpr bool MDB_LOG_TX_FRAME = false;
static constexpr bool MDB_LOG_AUTH_TX_FRAME = false;
static constexpr bool MDB_LOG_AUTH_STATE = false;
static constexpr bool MDB_LOG_VMC_RX = false;
static constexpr bool MDB_LOG_IGNORED_SINGLE_BYTE = false;
static constexpr bool MDB_LOG_BAD_CHECKSUM = false;

// Safe non-hot-path summary. Printed from loop() periodically, not from
// the immediate MDB response branches.
static constexpr bool MDB_LOG_PERIODIC_SUMMARY = true;
static constexpr uint32_t MDB_SUMMARY_PERIOD_MS = 2000;
static constexpr uint32_t MDB_SUMMARY_IDLE_GUARD_US = 2000000;
static constexpr bool MDB_ALLOW_POLL_BOOTSTRAP_JUST_RESET = true;

// Still collect timing internally; do not print it in the hot path.
static uint32_t currentRxFrameEndedAtUs = 0;
static uint32_t lastResponseDelayUs = 0;
static uint32_t maxResponseDelayUs = 0;
static uint32_t lastMdbActivityAtUs = 0;

static uint32_t statMasterAck = 0;
static uint32_t statMasterRet = 0;
static uint32_t statMasterNak = 0;
static uint32_t statCoinReset = 0;
static uint32_t statCoinPoll = 0;
static uint32_t statCoinSetup = 0;
static uint32_t statCoinTubeStatus = 0;
static uint32_t statCoinType = 0;
static uint32_t statCoinExpansion = 0;
static uint32_t statTxAck = 0;
static uint32_t statTxResetAck = 0;
static uint32_t statTxJustReset = 0;
static uint32_t statTxSetup = 0;
static uint32_t statTxTubeStatus = 0;
static uint32_t statTxCoinTypeAck = 0;
static uint32_t statTxCredit100 = 0;
static uint32_t statTxExpansion = 0;
static uint32_t lastSummaryAtMs = 0;

static bool coinResetSeen = false;
static bool coinJustResetPending = false;
static bool coinJustResetSent = false;

static bool coinSetupSeen = false;
static bool coinTubeStatusSeen = false;
static bool coinTypeSeen = false;

static bool coinJustResetAccepted = false;
static bool coinSetupAccepted = false;
static bool coinTubeStatusAccepted = false;
static bool coinTypeAccepted = false;
static bool coinAuthorizedInVmc = false;

static uint8_t coinPollsBeforeReset = 0;

// One-shot payment test.
// Do not send credit at boot. Arm it only after VMC ACKs JUST RESET.
static bool coinCredit100MinorPending = false;
static bool coinCredit100MinorSent = false;

// One-shot test credit should be armed only after VMC completes init:
// RESET/POLL-JUST_RESET/SETUP/TUBE_STATUS/COIN_TYPE.
static bool coinCredit100MinorArmedAfterInit = false;
static char rxOnlyConsoleBuffer[96] = {};
static size_t rxOnlyConsoleLength = 0;

// Safety fallback: some VMCs do not send COIN TYPE in this reduced test.
// If true, credit can be armed after SETUP + TUBE STATUS.
// If false, waits for COIN TYPE / enable command too.
static constexpr bool MDB_ARM_CREDIT_AFTER_TUBE_STATUS = false;

static uint8_t lastTxBytes[MDB_TEST_MAX_TX_BYTES] = {};
static bool lastTxModeBits[MDB_TEST_MAX_TX_BYTES] = {};
static size_t lastTxLength = 0;
static const char *lastTxReason = "none";

enum class LastCoinTxKind
{
  None,
  Ack,
  JustReset,
  Setup,
  TubeStatus,
  CoinTypeAck,
  ExpansionId,
  Credit100Minor,
};

static LastCoinTxKind lastCoinTxKind = LastCoinTxKind::None;

static void setMdbTxLogical(bool logicalHigh)
{
  const int level = MDB_TX_GPIO_HIGH_ASSERTS_LOW
                        ? (logicalHigh ? 0 : 1)
                        : (logicalHigh ? 1 : 0);

  gpio_set_level(static_cast<gpio_num_t>(MDB_TEST_TX_PIN), level);
}

static void releaseMdbTxLine()
{
  setMdbTxLogical(true);
}

static void assertMdbTxLow()
{
  setMdbTxLogical(false);
}

static void sendMdbWordBits(uint8_t value, bool modeBit)
{
  // start bit = 0
  assertMdbTxLow();
  delayMicroseconds(MDB_BIT_US);

  // 8 data bits, LSB first
  for (uint8_t i = 0; i < 8; ++i)
  {
    const bool bit = ((value >> i) & 0x01) != 0;
    setMdbTxLogical(bit);
    delayMicroseconds(MDB_BIT_US);
  }

  // mode bit / 9th bit
  setMdbTxLogical(modeBit);
  delayMicroseconds(MDB_BIT_US);

  // stop bit = 1
  releaseMdbTxLine();
  delayMicroseconds(MDB_BIT_US);
}

static void rememberLastTx(const uint8_t *bytes, const bool *modeBits, size_t length,
                           const char *reason)
{
  if (bytes == nullptr || modeBits == nullptr || length == 0)
  {
    lastTxLength = 0;
    lastTxReason = "none";
    return;
  }

  if (length > MDB_TEST_MAX_TX_BYTES)
  {
    length = MDB_TEST_MAX_TX_BYTES;
  }

  for (size_t i = 0; i < length; ++i)
  {
    lastTxBytes[i] = bytes[i];
    lastTxModeBits[i] = modeBits[i];
  }

  lastTxLength = length;
  lastTxReason = reason == nullptr ? "unknown" : reason;
}

static void sendPreparedMdbFrameRaw(const uint8_t *bytes, const bool *modeBits,
                                    size_t length, const char *reason,
                                    bool remember)
{
  if (bytes == nullptr || modeBits == nullptr || length == 0)
  {
    return;
  }

  if (remember)
  {
    rememberLastTx(bytes, modeBits, length, reason);
  }

  const uint32_t txStartUs = micros();
  const uint32_t responseDelayUs =
      currentRxFrameEndedAtUs == 0
          ? 0
          : static_cast<uint32_t>(txStartUs - currentRxFrameEndedAtUs);

  lastResponseDelayUs = responseDelayUs;
  if (responseDelayUs > maxResponseDelayUs)
  {
    maxResponseDelayUs = responseDelayUs;
  }

  noInterrupts();

  for (size_t i = 0; i < length; ++i)
  {
    sendMdbWordBits(bytes[i], modeBits[i]);

    if (MDB_INTER_BYTE_GAP_US > 0)
    {
      delayMicroseconds(MDB_INTER_BYTE_GAP_US);
    }
  }

  interrupts();

  const uint32_t txEndUs = micros();
  lastMdbActivityAtUs = txEndUs;

  if (reason != nullptr)
  {
    if (length == 1 && bytes[0] == 0x00)
    {
      statTxAck++;
    }

    if (strcmp(reason, "coin_reset_ack") == 0)
    {
      statTxResetAck++;
    }
    else if (strcmp(reason, "coin_just_reset") == 0)
    {
      statTxJustReset++;
    }
    else if (strcmp(reason, "coin_setup_no_change") == 0)
    {
      statTxSetup++;
    }
    else if (strcmp(reason, "coin_tube_status_no_tubes") == 0)
    {
      statTxTubeStatus++;
    }
    else if (strcmp(reason, "coin_type_ack") == 0)
    {
      statTxCoinTypeAck++;
    }
    else if (strcmp(reason, "coin_credit_100_minor_once") == 0)
    {
      statTxCredit100++;
    }
    else if (strcmp(reason, "coin_expansion_id") == 0)
    {
      statTxExpansion++;
    }
  }

  if (MDB_LOG_TX_TIMING)
  {
    Serial.print("[ESP_TX_TIMING] reason=");
    Serial.print(reason == nullptr ? "unknown" : reason);
    Serial.print(" bytes=");
    Serial.print(length);
    Serial.print(" bit_us=");
    Serial.print(MDB_BIT_US);
    Serial.print(" gap_us=");
    Serial.print(MDB_INTER_BYTE_GAP_US);
    Serial.print(" response_delay_us=");
    Serial.print(responseDelayUs);
    Serial.print(" duration_us=");
    Serial.println(txEndUs - txStartUs);
  }
}
static uint8_t checksum8(const uint8_t *payload, size_t payloadLen)
{
  uint8_t checksum = 0;
  for (size_t i = 0; i < payloadLen; ++i)
  {
    checksum = static_cast<uint8_t>(checksum + payload[i]);
  }
  return checksum;
}

static void printHexByte(uint8_t value)
{
  if (value < 0x10)
  {
    Serial.print('0');
  }
  Serial.print(value, HEX);
}

static void printFrameHex(const MdbFrame &frame)
{
  for (size_t i = 0; i < frame.length; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }
    printHexByte(frame.bytes[i]);
  }
}

static void printRaw9List(const uint8_t *bytes, const bool *modeBits, size_t length)
{
  for (size_t i = 0; i < length; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }

    if (modeBits[i])
    {
      Serial.print('1');
    }

    printHexByte(bytes[i]);
  }
}

static bool txFrameUsesExpected9BitFormat(const uint8_t *bytes, const bool *modeBits, size_t length);
static void printMdbSummaryIfDue(bool force = false);

static bool authReasonContains(const char *reason, const char *needle)
{
  return reason != nullptr && needle != nullptr && strstr(reason, needle) != nullptr;
}

static const char *authStepFromTxReason(const char *reason)
{
  if (authReasonContains(reason, "coin_reset_ack"))
  {
    return "RESET_ACK";
  }

  if (authReasonContains(reason, "coin_just_reset"))
  {
    return "JUST_RESET";
  }

  if (authReasonContains(reason, "coin_setup"))
  {
    return "SETUP";
  }

  if (authReasonContains(reason, "coin_tube_status"))
  {
    return "TUBE_STATUS";
  }

  if (authReasonContains(reason, "coin_type"))
  {
    return "COIN_TYPE";
  }

  if (authReasonContains(reason, "coin_expansion"))
  {
    return "EXPANSION_ID";
  }

  if (authReasonContains(reason, "coin_credit"))
  {
    return "CREDIT_100_MINOR";
  }

  if (authReasonContains(reason, "master_ret"))
  {
    return "RETRANSMIT_RET";
  }

  if (authReasonContains(reason, "master_nak"))
  {
    return "RETRANSMIT_NAK";
  }

  if (authReasonContains(reason, "ack"))
  {
    return "ACK";
  }

  return "TX";
}

static bool authTxFrameUsesExpected9BitFormat(const uint8_t *bytes,
                                              const bool *modeBits,
                                              size_t length)
{
  if (bytes == nullptr || modeBits == nullptr || length == 0)
  {
    return false;
  }

  // Single-byte MDB control response: final byte must have 9th bit = 1.
  if (length == 1)
  {
    return modeBits[0];
  }

  // MDB data block response: payload bytes mode=0, checksum/final byte mode=1.
  for (size_t i = 0; i + 1 < length; ++i)
  {
    if (modeBits[i])
    {
      return false;
    }
  }

  return modeBits[length - 1];
}

static void logAuthTxFrame(const char *reason,
                           const uint8_t *bytes,
                           const bool *modeBits,
                           size_t length)
{
  if (!MDB_LOG_AUTH_TX_FRAME)
  {
    return;
  }

  if (bytes == nullptr || modeBits == nullptr || length == 0)
  {
    return;
  }

  Serial.print("[AUTH_TX_FRAME] ");
  Serial.print(authStepFromTxReason(reason));

  Serial.print(" reason=");
  Serial.print(reason == nullptr ? "unknown" : reason);

  Serial.print(" bytes=");
  Serial.print(length);

  Serial.print(" hex=");
  for (size_t i = 0; i < length; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }
    printHexByte(bytes[i]);
  }

  Serial.print(" raw9=");
  printRaw9List(bytes, modeBits, length);

  Serial.print(" checksum=");
  if (length > 1)
  {
    printHexByte(bytes[length - 1]);
  }
  else
  {
    Serial.print("none");
  }

  Serial.print(" last_mode=");
  Serial.print(modeBits[length - 1] ? 1 : 0);

  Serial.print(" 9bit=");
  Serial.print(authTxFrameUsesExpected9BitFormat(bytes, modeBits, length) ? "ok" : "fail");

  Serial.println();
}

static void logTxPrepared(const char *reason, const uint8_t *bytes,
                          const bool *modeBits, size_t length)
{
  if (!MDB_LOG_TX_FRAME)
  {
    return;
  }

  Serial.print("[ESP_TX] ");
  Serial.print(reason == nullptr ? "unknown" : reason);

  Serial.print(" hex=");
  for (size_t i = 0; i < length; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }
    printHexByte(bytes[i]);
  }

  Serial.print(" raw9=");
  printRaw9List(bytes, modeBits, length);

  Serial.print(" 9bit=");
  Serial.print(txFrameUsesExpected9BitFormat(bytes, modeBits, length) ? "ok" : "fail");

  Serial.println();
  logAuthTxFrame(reason, bytes, modeBits, length);
}

static void sendMdbAckRaw(const char *reason)
{
  const uint8_t bytes[] = {0x00};
  const bool modeBits[] = {true}; // raw9=100

  if (reason != nullptr && strcmp(reason, "coin_type_ack") == 0)
  {
    lastCoinTxKind = LastCoinTxKind::CoinTypeAck;
  }
  else
  {
    lastCoinTxKind = LastCoinTxKind::Ack;
  }

  sendPreparedMdbFrameRaw(bytes, modeBits, 1, reason, true);
  logTxPrepared(reason, bytes, modeBits, 1);
}

static void sendMdbDataBlockRaw(const uint8_t *payload, size_t payloadLen,
                                const char *reason)
{
  if (payload == nullptr || payloadLen == 0)
  {
    return;
  }

  if (payloadLen + 1 > MDB_TEST_MAX_TX_BYTES)
  {
    Serial.print("[ESP_TX_ERROR] ");
    Serial.print(reason == nullptr ? "unknown" : reason);
    Serial.println(" payload_too_large");
    return;
  }

  uint8_t bytes[MDB_TEST_MAX_TX_BYTES] = {};
  bool modeBits[MDB_TEST_MAX_TX_BYTES] = {};

  for (size_t i = 0; i < payloadLen; ++i)
  {
    bytes[i] = payload[i];
    modeBits[i] = false;
  }

  bytes[payloadLen] = checksum8(payload, payloadLen);
  modeBits[payloadLen] = MDB_SLAVE_DATA_CHECKSUM_MODE_BIT;

  const size_t length = payloadLen + 1;
  sendPreparedMdbFrameRaw(bytes, modeBits, length, reason, true);
  logTxPrepared(reason, bytes, modeBits, length);
}

static void sendLastTxAgainRaw(const char *reason)
{
  if (lastTxLength == 0)
  {
    sendMdbAckRaw("ret_no_previous_ack");
    return;
  }

  sendPreparedMdbFrameRaw(lastTxBytes, lastTxModeBits, lastTxLength,
                          lastTxReason, false);

  if (MDB_LOG_TX_FRAME)
  {
    Serial.print("[ESP_TX] ");
    Serial.print(reason == nullptr ? "retx" : reason);
    Serial.print(" previous=");
    Serial.print(lastTxReason);
    Serial.print(" hex=");
    for (size_t i = 0; i < lastTxLength; ++i)
    {
      if (i != 0)
      {
        Serial.print(' ');
      }
      printHexByte(lastTxBytes[i]);
    }
    Serial.print(" raw9=");
    printRaw9List(lastTxBytes, lastTxModeBits, lastTxLength);
    Serial.println();
  }

  logAuthTxFrame(lastTxReason, lastTxBytes, lastTxModeBits, lastTxLength);
}

static void sendCoinJustResetRaw()
{
  if (MDB_JUST_RESET_SINGLE_BYTE)
  {
    // A/B diagnostic variant:
    // VMC -> POLL 0B 0B
    // Coin -> JUST RESET 0B
    //
    // Expected:
    //   hex  = 0B
    //   raw9 = 10B
    const uint8_t bytes[] = {0x0B};
    const bool modeBits[] = {true};

    sendPreparedMdbFrameRaw(bytes, modeBits, 1, "coin_just_reset", true);
    logTxPrepared("coin_just_reset", bytes, modeBits, 1);
  }
  else
  {
    // Standard data-block variant:
    // VMC -> POLL 0B 0B
    // Coin -> 0B 0B
    //
    // Expected:
    //   hex  = 0B 0B
    //   raw9 = 0B 10B
    const uint8_t payload[] = {0x0B};
    sendMdbDataBlockRaw(payload, sizeof(payload), "coin_just_reset");
  }

  lastCoinTxKind = LastCoinTxKind::JustReset;
}

static void sendCoinCredit100MinorRaw()
{
  // 100 minor:
  // scale factor = 100
  // coin type 0 = 1 scaled unit
  //
  // coin event:
  // 0x40 | coin_type(0) = 0x40
  //
  // second byte = tube status/count = 0x00
  //
  // checksum:
  // 0x40 + 0x00 = 0x40
  //
  // expected:
  // hex  = 40 00 40
  // raw9 = 40 00 140
  const uint8_t payload[] = {0x40, 0x00};

  sendMdbDataBlockRaw(payload, sizeof(payload), "coin_credit_100_minor_once");

  lastCoinTxKind = LastCoinTxKind::Credit100Minor;
  coinCredit100MinorSent = true;
  coinCredit100MinorPending = false;
}

static void sendCoinSetupNoChangeRaw()
{
  static const uint8_t payload[] = {
      0x01, // feature level = 1
      0x14,
      0x17, // currency/country code, как на рабочем устройстве
      0x64, // scaling factor = 100
      0x02, // decimal places = 2

      0x00,
      0x00, // routing mask = no tubes / no change

      // 16 coin type credits
      0x01, // coin type 0 = 1.00
      0x05, // coin type 1 = 5.00
      0x0A, // coin type 2 = 10.00
      0x32, // coin type 3 = 50.00
      0x64, // coin type 4 = 100.00
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
  };

  sendMdbDataBlockRaw(payload, sizeof(payload), "coin_setup_no_change");
  lastCoinTxKind = LastCoinTxKind::Setup;
}

static void sendCoinTubeStatusNoTubesRaw()
{
  static const uint8_t payload[] = {
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
  };

  sendMdbDataBlockRaw(payload, sizeof(payload), "coin_tube_status_no_tubes");
  lastCoinTxKind = LastCoinTxKind::TubeStatus;
}
static void sendCoinExpansionIdRaw()
{
  // Coin changer EXPANSION IDENTIFICATION response.
  // Separate from SETUP. SETUP remains the 23-byte coin config block.
  static const uint8_t payload[] = {
      'M',
      'E',
      'I',
      '3',
      '7',
      '6',
      '9',
      'G',
      '6',
      '0',
      '0',
      '3',
      '5',
      '1',
      ' ',
      'C',
      'F',
      '7',
      '9',
      '0',
      '0',
      'M',
      'D',
      'B',
      ' ',
      ' ',
      ' ',
      0x01,
      0x00,
      0x00,
      0x00,
      0x00,
      0x00,
  };

  sendMdbDataBlockRaw(payload, sizeof(payload), "coin_expansion_id");
  lastCoinTxKind = LastCoinTxKind::ExpansionId;
}

static void logVmcFrame(const char *label, const MdbFrame &frame,
                        uint8_t addr5, uint8_t cmd3)
{
  if (!MDB_LOG_VMC_RX)
  {
    return;
  }

  if (!MDB_LOG_IGNORED_SINGLE_BYTE && label != nullptr &&
      strcmp(label, "single_byte_ignored") == 0)
  {
    return;
  }

  Serial.print("[VMC_RX] ");
  Serial.print(label);
  Serial.print(" ok=");
  Serial.print(frame.checksumOk ? 1 : 0);
  Serial.print(" addr5=");
  Serial.print(addr5);
  Serial.print(" cmd3=");
  Serial.print(cmd3);
  Serial.print(" hex=");
  printFrameHex(frame);
  Serial.println();
}

static const char *lastCoinTxKindToAuthStep()
{
  switch (lastCoinTxKind)
  {
  case LastCoinTxKind::Ack:
    return "ACK";
  case LastCoinTxKind::JustReset:
    return "JUST_RESET";
  case LastCoinTxKind::Setup:
    return "SETUP";
  case LastCoinTxKind::TubeStatus:
    return "TUBE_STATUS";
  case LastCoinTxKind::CoinTypeAck:
    return "COIN_TYPE_ACK";
  case LastCoinTxKind::ExpansionId:
    return "EXPANSION_ID";
  case LastCoinTxKind::Credit100Minor:
    return "CREDIT_100_MINOR";
  case LastCoinTxKind::None:
  default:
    return "NONE";
  }
}

static void logAuthStep(const char *step, const char *status, const char *detail = nullptr)
{
  if (!MDB_LOG_AUTH_STATE)
  {
    return;
  }

  Serial.print("[AUTH] ");
  Serial.print(step == nullptr ? "UNKNOWN" : step);
  Serial.print(" - ");
  Serial.print(status == nullptr ? "unknown" : status);

  if (detail != nullptr && detail[0] != '\0')
  {
    Serial.print(" detail=");
    Serial.print(detail);
  }

  Serial.print(" flags={reset_seen:");
  Serial.print(coinResetSeen ? 1 : 0);
  Serial.print(",just_reset_ack:");
  Serial.print(coinJustResetAccepted ? 1 : 0);
  Serial.print(",setup_seen:");
  Serial.print(coinSetupSeen ? 1 : 0);
  Serial.print(",setup_ok:");
  Serial.print(coinSetupAccepted ? 1 : 0);
  Serial.print(",tube_seen:");
  Serial.print(coinTubeStatusSeen ? 1 : 0);
  Serial.print(",tube_ok:");
  Serial.print(coinTubeStatusAccepted ? 1 : 0);
  Serial.print(",coin_type_seen:");
  Serial.print(coinTypeSeen ? 1 : 0);
  Serial.print(",coin_type_ok:");
  Serial.print(coinTypeAccepted ? 1 : 0);
  Serial.print(",authorized:");
  Serial.print(coinAuthorizedInVmc ? 1 : 0);
  Serial.println("}");
}

static bool txFrameUsesExpected9BitFormat(const uint8_t *bytes, const bool *modeBits,
                                          size_t length)
{
  if (bytes == nullptr || modeBits == nullptr || length == 0)
  {
    return false;
  }

  // MDB single-byte ACK/NAK/RET response: one byte with mode bit = 1.
  if (length == 1)
  {
    return modeBits[0];
  }

  // MDB data block response: payload bytes mode=0, checksum/final byte mode=1.
  for (size_t i = 0; i + 1 < length; ++i)
  {
    if (modeBits[i])
    {
      return false;
    }
  }

  return modeBits[length - 1];
}

static bool coinReadyForCredit()
{
  if (MDB_ARM_CREDIT_AFTER_TUBE_STATUS)
  {
    return coinSetupAccepted && coinTubeStatusAccepted;
  }

  return coinSetupAccepted && coinTubeStatusAccepted && coinTypeAccepted;
}

static void markAuthorizedIfReady(const char *source)
{
  (void)source;
  if (coinAuthorizedInVmc)
  {
    return;
  }

  if (!coinReadyForCredit())
  {
    return;
  }

  coinAuthorizedInVmc = true;
}

static void armCredit100MinorIfReady(const char *source)
{
  markAuthorizedIfReady(source);

  if (coinCredit100MinorSent || coinCredit100MinorPending)
  {
    return;
  }

  if (!coinReadyForCredit())
  {
    return;
  }

  coinCredit100MinorPending = true;
  coinCredit100MinorArmedAfterInit = true;
}

static void runManualMdbTxLineTest()
{
  Serial.println("[MDB_TX_LINE_TEST] phase=release duration_ms=3000");
  releaseMdbTxLine();
  delay(3000);
  Serial.println("[MDB_TX_LINE_TEST] phase=assert_low duration_ms=3000");
  assertMdbTxLow();
  delay(3000);
  Serial.println("[MDB_TX_LINE_TEST] phase=release duration_ms=3000");
  releaseMdbTxLine();
  delay(3000);
  Serial.println("[MDB_TX_LINE_TEST] done");
}

static void handleRxOnlyConsoleLine(const String &rawLine)
{
  String line = rawLine;
  line.trim();
  if (line.isEmpty())
  {
    return;
  }

  if (line == "help" || line == "?")
  {
    Serial.println("RX-only commands:");
    Serial.println("  help");
    Serial.println("  tx_line_test");
    Serial.println("  summary_now");
    return;
  }

  if (line == "tx_line_test")
  {
    runManualMdbTxLineTest();
    return;
  }

  if (line == "summary_now")
  {
    lastSummaryAtMs = 0;
    printMdbSummaryIfDue(true);
    return;
  }

  Serial.print("rx_only_cmd_error: unsupported command: ");
  Serial.println(line);
}

static void handleRxOnlyConsole()
{
  while (Serial.available() > 0)
  {
    const int rawChar = Serial.read();
    if (rawChar < 0)
    {
      return;
    }

    const char ch = static_cast<char>(rawChar);
    if (ch == '\r')
    {
      continue;
    }

    if (ch == '\n')
    {
      rxOnlyConsoleBuffer[rxOnlyConsoleLength] = '\0';
      handleRxOnlyConsoleLine(String(rxOnlyConsoleBuffer));
      rxOnlyConsoleLength = 0;
      rxOnlyConsoleBuffer[0] = '\0';
      continue;
    }

    if (rxOnlyConsoleLength + 1 >= sizeof(rxOnlyConsoleBuffer))
    {
      Serial.println("rx_only_cmd_error: command too long");
      rxOnlyConsoleLength = 0;
      rxOnlyConsoleBuffer[0] = '\0';
      continue;
    }

    rxOnlyConsoleBuffer[rxOnlyConsoleLength++] = ch;
    rxOnlyConsoleBuffer[rxOnlyConsoleLength] = '\0';
  }
}

static void printMdbSummaryIfDue(bool force)
{
  if (!MDB_LOG_PERIODIC_SUMMARY)
  {
    return;
  }

  const uint32_t nowMs = millis();
  if (!force && nowMs - lastSummaryAtMs < MDB_SUMMARY_PERIOD_MS)
  {
    return;
  }

  const uint32_t nowUs = micros();
  if (!force && lastMdbActivityAtUs != 0 &&
      static_cast<uint32_t>(nowUs - lastMdbActivityAtUs) < MDB_SUMMARY_IDLE_GUARD_US)
  {
    return;
  }
  lastSummaryAtMs = nowMs;

  Serial.print("[MDB_SUMMARY] rx={reset:");
  Serial.print(statCoinReset);
  Serial.print(",poll:");
  Serial.print(statCoinPoll);
  Serial.print(",setup:");
  Serial.print(statCoinSetup);
  Serial.print(",tube:");
  Serial.print(statCoinTubeStatus);
  Serial.print(",coin_type:");
  Serial.print(statCoinType);
  Serial.print(",expansion:");
  Serial.print(statCoinExpansion);
  Serial.print(",ack:");
  Serial.print(statMasterAck);
  Serial.print(",ret:");
  Serial.print(statMasterRet);
  Serial.print(",nak:");
  Serial.print(statMasterNak);

  Serial.print("} tx={ack:");
  Serial.print(statTxAck);
  Serial.print(",reset_ack:");
  Serial.print(statTxResetAck);
  Serial.print(",just_reset:");
  Serial.print(statTxJustReset);
  Serial.print(",setup:");
  Serial.print(statTxSetup);
  Serial.print(",tube:");
  Serial.print(statTxTubeStatus);
  Serial.print(",coin_type_ack:");
  Serial.print(statTxCoinTypeAck);
  Serial.print(",expansion:");
  Serial.print(statTxExpansion);
  Serial.print(",credit100:");
  Serial.print(statTxCredit100);

  Serial.print("} state={reset_seen:");
  Serial.print(coinResetSeen ? 1 : 0);
  Serial.print(",just_reset_ok:");
  Serial.print(coinJustResetAccepted ? 1 : 0);
  Serial.print(",setup_ok:");
  Serial.print(coinSetupAccepted ? 1 : 0);
  Serial.print(",tube_ok:");
  Serial.print(coinTubeStatusAccepted ? 1 : 0);
  Serial.print(",coin_type_ok:");
  Serial.print(coinTypeAccepted ? 1 : 0);
  Serial.print(",authorized:");
  Serial.print(coinAuthorizedInVmc ? 1 : 0);

  Serial.print("} timing={last_response_us:");
  Serial.print(lastResponseDelayUs);
  Serial.print(",max_response_us:");
  Serial.print(maxResponseDelayUs);
  Serial.println("}");
}
#else
// #include "command_service.h"
// #include "connection_service.h"
// #include "firmware_version.h"
// #include "logging_utils.h"
// #include "mdb_service.h"
// #include "ota_manager.h"
// #include "pulse_config_service.h"
// #include "pulse_service.h"
// #include "status_leds.h"
// #include "uart_service.h"
#endif

#if MDB_RX_ONLY_SNIFFER
void handleMdbFrame(const MdbFrame &frame)
{
  if (frame.length == 0)
  {
    return;
  }

  currentRxFrameEndedAtUs = frame.endedAtUs;
  lastMdbActivityAtUs = currentRxFrameEndedAtUs;

  const uint8_t first = frame.bytes[0];
  const uint8_t addr5 = static_cast<uint8_t>((first >> 3) & 0x1F);
  const uint8_t cmd3 = static_cast<uint8_t>(first & 0x07);

  // Master ACK from VMC after our response.
  if (frame.length == 1 && first == 0x00)
  {
    statMasterAck++;

    if (lastCoinTxKind == LastCoinTxKind::JustReset)
    {
      coinJustResetPending = false;
      coinJustResetSent = false;
      coinJustResetAccepted = true;
      logAuthStep("JUST_RESET", "ok", "master_ack_00");
    }
    else if (lastCoinTxKind == LastCoinTxKind::Setup)
    {
      coinSetupAccepted = true;
      logAuthStep("SETUP", "ok", "master_ack_00");
      armCredit100MinorIfReady("setup_ack");
    }
    else if (lastCoinTxKind == LastCoinTxKind::TubeStatus)
    {
      coinTubeStatusAccepted = true;
      logAuthStep("TUBE_STATUS", "ok", "master_ack_00");
      armCredit100MinorIfReady("tube_status_ack");
    }
    else if (lastCoinTxKind == LastCoinTxKind::CoinTypeAck)
    {
      logAuthStep("COIN_TYPE", "ok", "master_ack_after_coin_type_ack");
    }
    else if (lastCoinTxKind == LastCoinTxKind::ExpansionId)
    {
      logAuthStep("EXPANSION_ID", "ok", "master_ack_00");
    }
    else if (lastCoinTxKind == LastCoinTxKind::Credit100Minor)
    {
      logAuthStep("CREDIT_100_MINOR", "ok", "master_ack_00");
    }
    else
    {
      logAuthStep("ACK", "ok", "master_ack_00");
    }

    logVmcFrame("master_ack", frame, addr5, cmd3);
    return;
  }

  // Master RET: VMC asks to repeat the previous response.
  if (frame.length == 1 && first == 0xAA)
  {
    statMasterRet++;

    // MDB timing first: retransmit immediately, log after TX.
    sendLastTxAgainRaw("master_ret_retx");
    logAuthStep(lastCoinTxKindToAuthStep(), "retry", "master_ret_AA");
    logVmcFrame("master_ret", frame, addr5, cmd3);
    return;
  }

  // Master NAK: treat it like "repeat previous" for this diagnostic test.
  if (frame.length == 1 && first == 0xFF)
  {
    statMasterNak++;

    // MDB timing first: retransmit immediately, log after TX.
    sendLastTxAgainRaw("master_nak_retx");
    logAuthStep(lastCoinTxKindToAuthStep(), "fail", "master_nak_FF_retransmit");
    logVmcFrame("master_nak", frame, addr5, cmd3);
    return;
  }

  // Any other single-byte frame is not a complete MDB master command.
  // Examples: 08, 10, 60 may be partial captures or bus artifacts.
  // Do not answer to them.
  if (frame.length == 1)
  {
    logVmcFrame("single_byte_ignored", frame, addr5, cmd3);
    return;
  }

  // Ignore broken frames. Logging them during active response tests is expensive.
  if (!frame.checksumOk)
  {
    if (MDB_LOG_BAD_CHECKSUM && addr5 == 1)
    {
      logVmcFrame("bad_checksum", frame, addr5, cmd3);
    }
    return;
  }

  // Master -> Peripheral command must have mode bit on first byte only.
  // Example: 08 08 must be mode=10.
  // Example: 09 09 must be mode=10.
  // Example: 19 03 01 00 1D must be mode=10000.
  if (!frame.modeBits[0] || frame.modeBits[frame.length - 1])
  {
    logVmcFrame("bad_master_mode", frame, addr5, cmd3);
    return;
  }

  // Coin changer RESET: 08 08.
  // Correct order: ACK reset first, then report JUST RESET on the next POLL.
  if (addr5 == 1 && cmd3 == 0)
  {
    statCoinReset++;

    coinResetSeen = true;
    coinJustResetPending = true;
    coinJustResetSent = false;
    coinPollsBeforeReset = 0;

    // New reset means init must be repeated.
    coinJustResetAccepted = false;
    coinSetupSeen = false;
    coinTubeStatusSeen = false;
    coinTypeSeen = false;
    coinSetupAccepted = false;
    coinTubeStatusAccepted = false;
    coinTypeAccepted = false;
    coinAuthorizedInVmc = false;
    coinCredit100MinorPending = false;
    coinCredit100MinorArmedAfterInit = false;

    sendMdbAckRaw("coin_reset_ack");
    logAuthStep("RESET", "ok", "rx_08_08_ack_sent");
    logVmcFrame("coin_reset", frame, addr5, cmd3);
    return;
  }

  // Coin changer SETUP: 09 09.
  // VMC asks for changer configuration.
  if (addr5 == 1 && cmd3 == 1)
  {
    statCoinSetup++;

    const bool justResetInferredBySetup =
        coinJustResetPending && !coinJustResetAccepted;

    if (justResetInferredBySetup)
    {
      // If SETUP arrived, VMC accepted JUST RESET even if we did not see master ACK.
      // Do not log before TX: Serial output can break MDB response timing.
      coinJustResetPending = false;
      coinJustResetSent = false;
      coinJustResetAccepted = true;
    }

    coinSetupSeen = true;

    // MDB timing first: send response immediately, log after TX.
    sendCoinSetupNoChangeRaw();

    if (justResetInferredBySetup)
    {
      logAuthStep("JUST_RESET", "ok", "inferred_by_setup_09_09");
    }

    logAuthStep("SETUP", "pending", "rx_09_09_sent_profile_14_17");
    logVmcFrame("coin_setup", frame, addr5, cmd3);
    armCredit100MinorIfReady("coin_setup_seen");
    return;
  }

  // Coin changer TUBE STATUS: 0A 0A.
  // VMC asks tube full flags and tube counts. For no-change mode all values are zero.
  if (addr5 == 1 && cmd3 == 2)
  {
    statCoinTubeStatus++;

    const bool setupInferredByTubeStatus = coinSetupSeen && !coinSetupAccepted;

    if (setupInferredByTubeStatus)
    {
      // If TUBE STATUS arrived, VMC accepted SETUP even if we missed master ACK.
      // Do not log before TX.
      coinSetupAccepted = true;
    }

    coinTubeStatusSeen = true;

    // MDB timing first: send response immediately, log after TX.
    sendCoinTubeStatusNoTubesRaw();

    if (setupInferredByTubeStatus)
    {
      logAuthStep("SETUP", "ok", "inferred_by_tube_status_0A_0A");
    }

    logAuthStep("TUBE_STATUS", "pending", "rx_0A_0A_sent_zero_tubes");
    logVmcFrame("coin_tube_status", frame, addr5, cmd3);
    armCredit100MinorIfReady("coin_tube_status_seen");
    return;
  }

  // Coin changer POLL: 0B 0B.
  if (addr5 == 1 && cmd3 == 3)
  {
    statCoinPoll++;

    // Some VMCs may POLL before sending an explicit RESET.
    // For this machine, synthetic JUST RESET on the first POLL can block
    // authorization completely, so keep bootstrap disabled by default and
    // answer with plain ACK until a real RESET or SETUP arrives.
    if (!coinResetSeen && !coinJustResetPending &&
        MDB_ALLOW_POLL_BOOTSTRAP_JUST_RESET)
    {
      coinPollsBeforeReset++;

      if (coinPollsBeforeReset >= 1)
      {
        coinResetSeen = true;
        coinJustResetPending = true;
        coinJustResetSent = false;
        // No Serial log before JUST_RESET TX.
        logAuthStep("RESET", "pending", "bootstrap_from_poll_no_08_08");
      }
    }

    if (!coinResetSeen && !coinJustResetPending)
    {
      sendMdbAckRaw("coin_ack_waiting_reset");
      logVmcFrame("coin_poll_waiting_reset", frame, addr5, cmd3);
      return;
    }

    if (coinJustResetPending)
    {
      // Repeat JUST_RESET on every POLL until VMC ACKs it or moves to SETUP.
      // Do not switch to ACK here: ACK means "no event" and can hide reset.
      sendCoinJustResetRaw();
      coinJustResetSent = true;
      logAuthStep("JUST_RESET", "pending", "sent_status_0B_waiting_ack_or_setup");
      logVmcFrame("coin_poll_just_reset_pending", frame, addr5, cmd3);
      return;
    }

    const bool tubeStatusInferredByPoll =
        coinTubeStatusSeen && !coinTubeStatusAccepted;

    if (tubeStatusInferredByPoll)
    {
      // If polling resumes after tube status, treat tube response as accepted.
      // Do not log before a possible credit response.
      coinTubeStatusAccepted = true;
    }

    // Arm state without printing before a possible MDB credit response.
    if (!coinCredit100MinorSent && !coinCredit100MinorPending && coinReadyForCredit())
    {
      coinAuthorizedInVmc = true;
      coinCredit100MinorPending = true;
      coinCredit100MinorArmedAfterInit = true;
    }

    if (coinCredit100MinorPending && !coinCredit100MinorSent)
    {
      sendCoinCredit100MinorRaw();

      if (tubeStatusInferredByPoll)
      {
        logAuthStep("TUBE_STATUS", "ok", "inferred_by_poll_after_tube_status");
      }

      logAuthStep("VMC_AUTH", "ok", "ready_for_credit_before_credit_tx");
      logVmcFrame("coin_poll_credit_100_minor_once", frame, addr5, cmd3);
      return;
    }

    if (tubeStatusInferredByPoll)
    {
      logAuthStep("TUBE_STATUS", "ok", "inferred_by_poll_after_tube_status");
    }

    armCredit100MinorIfReady("coin_poll");

    sendMdbAckRaw(coinResetSeen ? "coin_ack_no_event" : "coin_ack_waiting_reset");
    logVmcFrame("coin_poll", frame, addr5, cmd3);
    return;
  }

  if (addr5 == 1 && cmd3 == 4)
  {
    statCoinType++;

    const bool tubeStatusInferredByCoinType =
        coinTubeStatusSeen && !coinTubeStatusAccepted;

    if (tubeStatusInferredByCoinType)
    {
      // Do not log before ACK.
      coinTubeStatusAccepted = true;
    }

    coinTypeSeen = true;
    coinTypeAccepted = true;

    // MDB timing first: ACK immediately, log after TX.
    sendMdbAckRaw("coin_type_ack");

    // Authorization point for this diagnostic flow:
    // VMC sent COIN TYPE and ESP accepted it with ACK.
    coinAuthorizedInVmc = true;

    if (tubeStatusInferredByCoinType)
    {
      logAuthStep("TUBE_STATUS", "ok", "inferred_by_coin_type_cmd");
    }

    logAuthStep("COIN_TYPE", "ok", "rx_cmd3_4_ack_sent");
    logVmcFrame("coin_type_enable", frame, addr5, cmd3);
    armCredit100MinorIfReady("coin_type_seen");
    return;
  }

  // Other valid frames: ignore in active coin test.
  return;
}
#endif

namespace
{
#if MDB_RX_ONLY_SNIFFER
  MdbBitBangReceiver mdbRx(static_cast<gpio_num_t>(MDB_RX_PIN));
#else
  // Глобальные экземпляры сервисов, живущие весь срок работы устройства.
  PulseService pulseService;
  ConnectionService connectionService;
  MdbService mdbService(connectionService);
  UartService uartService(connectionService);
  OtaManager otaService(connectionService);
  PulseConfigService pulseConfigService(connectionService, pulseService);
  CommandService commandService(pulseService, mdbService, pulseConfigService,
                                uartService, otaService);
  StatusLeds statusLeds;
  esp_reset_reason_t bootResetReason = ESP_RST_UNKNOWN;
  bool deviceInfoSentForCurrentWsSession = false;
  constexpr size_t kSerialCommandBufferSize = 192;
  char serialCommandBuffer[kSerialCommandBufferSize] = {};
  size_t serialCommandLength = 0;

  const char *resetReasonToString(esp_reset_reason_t reason);
  void handleSerialConsole();
  void dispatchSerialConsoleLine(const String &line);
  void dispatchSerialCommand(const String &command,
                             const String &payloadJson = "{}");
  void printSerialConsoleHelp();

  // Отправляет backend информацию об устройстве после каждого нового WS-подключения.
  void sendDeviceInfoIfNeeded()
  {
    if (!connectionService.isWebSocketConnected())
    {
      deviceInfoSentForCurrentWsSession = false;
      return;
    }

    if (deviceInfoSentForCurrentWsSession)
    {
      return;
    }

    const String payload = String("{\"type\":\"device_info\",\"device_id\":\"") +
                           connectionService.deviceId() + "\",\"details\":{\"firmware_version\":\"" +
                           FIRMWARE_VERSION + "\",\"reset_reason\":\"" +
                           resetReasonToString(bootResetReason) + "\",\"boot_millis\":" +
                           millis() + "}}";
    if (connectionService.sendText(payload))
    {
      deviceInfoSentForCurrentWsSession = true;
    }
  }

  // Передаёт входящие команды из WebSocket в прикладной dispatcher.
  void handleWebSocketText(const uint8_t *payload, size_t length)
  {
    statusLeds.notifyCommandReceived();
    commandService.handleTextMessage(payload, length);
  }

  // Выполняет локальную команду через тот же JSON-dispatcher, что и WebSocket.
  void dispatchSerialCommand(const String &command, const String &payloadJson)
  {
    const String message = String("{\"type\":\"command\",\"payload\":{\"command\":\"") +
                           command + "\",\"payload\":" + payloadJson + "}}";
    statusLeds.notifyCommandReceived();
    commandService.handleTextMessage(
        reinterpret_cast<const uint8_t *>(message.c_str()), message.length());
  }

  // Печатает короткую справку по локальным USB-командам.
  void printSerialConsoleHelp()
  {
    Serial.println("USB commands:");
    Serial.println("  help");
    Serial.println("  mdb_probe");
    Serial.println("  mdb_irq_snapshot");
    Serial.println("  phy_decoder_status");
    Serial.println("  mdb_probe_tx");
    Serial.println("  mdb_pulse_test");
    Serial.println("  mdb_tx_hold_low_test");
    Serial.println("  mdb_monitor_start");
    Serial.println("  mdb_monitor_stop");
    Serial.println("  mdb_sniff_clear");
    Serial.println("  mdb_sniff_recent");
    Serial.println("  mdb_sniff_summary");
    Serial.println("  mdb_sniff_stats");
    Serial.println("  mdb_passive_sniff_on");
    Serial.println("  mdb_passive_sniff_off");
    Serial.println("  mdb_rx_invert_on");
    Serial.println("  mdb_rx_invert_off");
    Serial.println("  mdb_gateway_profile <0|1|2>");
    Serial.println("  mdb_set_cashless_address <n>");
    Serial.println("  mdb_set_expected_address <n>");
    Serial.println("  mdb_raw_send <HEX>");
    Serial.println("  {json command payload}");
  }

  // Разбирает одну строку команды, пришедшую по USB Serial.
  void dispatchSerialConsoleLine(const String &rawLine)
  {
    String line = rawLine;
    line.trim();
    if (line.isEmpty())
    {
      return;
    }

    if (line.startsWith("{"))
    {
      statusLeds.notifyCommandReceived();
      commandService.handleTextMessage(
          reinterpret_cast<const uint8_t *>(line.c_str()), line.length());
      return;
    }

    const int separator = line.indexOf(' ');
    const String command =
        separator >= 0 ? line.substring(0, separator) : line;
    String arg = separator >= 0 ? line.substring(separator + 1) : "";
    arg.trim();

    if (command == "help" || command == "?")
    {
      printSerialConsoleHelp();
      return;
    }

    if (command == "mdb_set_cashless_address")
    {
      dispatchSerialCommand(
          command, String("{\"cashless_address\":") +
                       (arg.isEmpty() ? "2" : arg) + "}");
      return;
    }

    if (command == "mdb_gateway_profile")
    {
      dispatchSerialCommand(
          command, String("{\"profile_id\":") +
                       (arg.isEmpty() ? "0" : arg) + "}");
      return;
    }

    if (command == "mdb_set_expected_address")
    {
      dispatchSerialCommand(
          command, String("{\"expected_address\":") +
                       (arg.isEmpty() ? "-1" : arg) + "}");
      return;
    }

    if (command == "mdb_raw_send")
    {
      if (arg.isEmpty())
      {
        Serial.println("usb_cmd_error: mdb_raw_send requires HEX payload");
        return;
      }
      dispatchSerialCommand(command,
                            String("{\"hex\":\"") + arg + "\"}");
      return;
    }

    if (command == "mdb_probe" || command == "mdb_irq_snapshot" ||
        command == "phy_decoder_status" ||
        command == "mdb_probe_tx" ||
        command == "mdb_pulse_test" || command == "mdb_tx_hold_low_test" ||
        command == "mdb_monitor_start" || command == "mdb_monitor_stop" ||
        command == "mdb_sniff_clear" || command == "mdb_sniff_recent" ||
        command == "mdb_sniff_summary" || command == "mdb_sniff_stats" ||
        command == "mdb_passive_sniff_on" ||
        command == "mdb_passive_sniff_off" ||
        command == "mdb_rx_invert_on" || command == "mdb_rx_invert_off")
    {
      dispatchSerialCommand(command);
      return;
    }

    mdbService.emitControlEvent(
        "command_rejected",
        String("{\"command\":\"") + command +
            "\",\"reason\":\"unsupported_usb_console_command\"}");
    Serial.print("usb_cmd_error: unsupported command: ");
    Serial.println(command);
    printSerialConsoleHelp();
  }

  // Обрабатывает строки из USB Serial как локальные сервисные команды.
  void handleSerialConsole()
  {
    while (Serial.available() > 0)
    {
      const int rawChar = Serial.read();
      if (rawChar < 0)
      {
        return;
      }

      const char ch = static_cast<char>(rawChar);
      if (ch == '\r')
      {
        continue;
      }

      if (ch == '\n')
      {
        serialCommandBuffer[serialCommandLength] = '\0';
        dispatchSerialConsoleLine(String(serialCommandBuffer));
        serialCommandLength = 0;
        serialCommandBuffer[0] = '\0';
        continue;
      }

      if (serialCommandLength + 1 >= kSerialCommandBufferSize)
      {
        Serial.println("usb_cmd_error: command too long");
        serialCommandLength = 0;
        serialCommandBuffer[0] = '\0';
        continue;
      }

      serialCommandBuffer[serialCommandLength++] = ch;
      serialCommandBuffer[serialCommandLength] = '\0';
    }
  }

  // Переводит код причины сброса ESP32 в строку для логов и backend.
  const char *resetReasonToString(esp_reset_reason_t reason)
  {
    switch (reason)
    {
    case ESP_RST_POWERON:
      return "POWERON";
    case ESP_RST_EXT:
      return "EXT";
    case ESP_RST_SW:
      return "SW";
    case ESP_RST_PANIC:
      return "PANIC";
    case ESP_RST_INT_WDT:
      return "INT_WDT";
    case ESP_RST_TASK_WDT:
      return "TASK_WDT";
    case ESP_RST_WDT:
      return "WDT";
    case ESP_RST_DEEPSLEEP:
      return "DEEPSLEEP";
    case ESP_RST_BROWNOUT:
      return "BROWNOUT";
    case ESP_RST_SDIO:
      return "SDIO";
    default:
      return "UNKNOWN";
    }
  }
#endif
} // namespace

void setup()
{
#if MDB_RX_ONLY_SNIFFER
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("MDB bit-bang RX-only sniffer + coin responder test");
  Serial.println(String("RX GPIO") + MDB_RX_PIN + ", TX GPIO" + MDB_TEST_TX_PIN);
  Serial.println("Lines: [VMC_RX], [ESP_TX], [AUTH]");
  Serial.println("HOT PATH logs disabled: TX_TIMING=off, TX_FRAME=off, AUTH=off, VMC_RX=off");
  Serial.println("Periodic summary enabled: [MDB_SUMMARY] every 2s");
  Serial.println("TX 9-bit format: ACK mode=1; data bytes mode=0; checksum/final byte mode=1");
  Serial.println(MDB_JUST_RESET_SINGLE_BYTE
                     ? "JUST_RESET variant: repeat single-byte 0B raw9=10B"
                     : "JUST_RESET variant: repeat data-block 0B 0B raw9=0B 10B");
  Serial.print("TX bit_us=");
  Serial.println(MDB_BIT_US);
  Serial.print("TX checksum_mode_bit=");
  Serial.println(MDB_SLAVE_DATA_CHECKSUM_MODE_BIT ? "true" : "false");
  Serial.println("Coin SETUP profile: feature=01 currency=14 17 scale=64 decimals=02 routing=0000 credits=1,5,10,50,100");
  Serial.println("Coin EXPANSION ID: MEI / 3769G600351 / CF7900MDB");
  Serial.println("Authorization point: COIN TYPE 0C -> ACK");
  Serial.println("Auth log format: [AUTH] SETUP - ok/fail/pending ...");
  Serial.println("RX-only commands: help, tx_line_test, summary_now");
  Serial.println("RX polarity: U1 6N137 inverted=true");

  gpio_set_direction(static_cast<gpio_num_t>(MDB_TEST_TX_PIN), GPIO_MODE_OUTPUT);
  releaseMdbTxLine();
  delay(20);

  mdbRx.begin(true, 9600);
#else
  // Начальная инициализация железа, сервисов и сетевого стека.
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  delay(200);
  bootResetReason = esp_reset_reason();

  mdbService.begin();
  vTaskDelay(pdMS_TO_TICKS(100));
  mdbService.startRealtimeRx();
  statusLeds.begin();
  pulseService.begin();
  uartService.begin();
  otaService.begin();
  otaService.setCanStartUpdateCallback([]()
                                       { return mdbService.isSafeForOta(); });
  connectionService.begin();
  connectionService.setMessageHandler(handleWebSocketText);

  Serial.println("ESP32 booting...");
  Serial.print("Reset reason: ");
  Serial.println(resetReasonToString(bootResetReason));
  Serial.print("Firmware version: ");
  Serial.println(FIRMWARE_VERSION);
  Serial.print("Device MAC: ");
  Serial.println(connectionService.rawMacAddress());
  Serial.print("Device ID: ");
  Serial.println(connectionService.deviceId());
  Serial.println("USB console ready. Type 'help' for local commands.");
#endif
}

void loop()
{
#if MDB_RX_ONLY_SNIFFER
  // Do not delay here: even delay(1) can add a full millisecond before
  // the next queued MDB frame is processed.
  handleRxOnlyConsole();
  mdbRx.update();
  printMdbSummaryIfDue();
  // mdbRx.printDiagnostics();
#else
  // Основной цикл устройства: связь, логика оплаты, OTA и индикация.
  handleSerialConsole();
  connectionService.update();
  sendDeviceInfoIfNeeded();
  pulseConfigService.update();
  pulseService.update();
  mdbService.update();
  uartService.update();
  otaService.update();
  statusLeds.update(connectionService.isWifiConnected(),
                    connectionService.isWebSocketConnected());
  delay(50);
#endif
}