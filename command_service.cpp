#include "command_service.h"

#include <ArduinoJson.h>
#include <cstring>

#include "logging_utils.h"
#include "mdb_service.h"
#include "ota_manager.h"
#include "pulse_config_service.h"
#include "pulse_service.h"

namespace
{
  constexpr bool kLogIncomingWsText = false;

  bool containsRawToken(const uint8_t *payload, size_t length, const char *token)
  {
    if (payload == nullptr || token == nullptr)
    {
      return false;
    }

    const size_t tokenLen = strlen(token);
    if (tokenLen == 0 || length < tokenLen)
    {
      return false;
    }

    for (size_t i = 0; i + tokenLen <= length; ++i)
    {
      if (memcmp(payload + i, token, tokenLen) == 0)
      {
        return true;
      }
    }
    return false;
  }

  bool isIgnorableTransportNoiseRaw(const uint8_t *payload, size_t length)
  {
    return containsRawToken(payload, length, "\"type\":\"connected\"") ||
           containsRawToken(payload, length, "\"type\":\"disconnected\"") ||
           containsRawToken(payload, length, "\"type\":\"ping\"") ||
           containsRawToken(payload, length, "\"type\":\"pong\"") ||
           containsRawToken(payload, length, "\"type\":\"hello\"") ||
           containsRawToken(payload, length, "\"type\":\"welcome\"") ||
           containsRawToken(payload, length, "\"type\":\"status\"") ||
           containsRawToken(payload, length, "\"type\":\"keepalive\"");
  }

  bool isIgnorableTransportType(const String &messageType)
  {
    return messageType == "connected" || messageType == "disconnected" ||
           messageType == "ping" || messageType == "pong" ||
           messageType == "hello" || messageType == "welcome" ||
           messageType == "status" || messageType == "keepalive";
  }
} // namespace

CommandService::CommandService(PulseService &pulseService, MdbService &mdbService,
                               PulseConfigService &pulseConfigService,
                               OtaManager &otaService)
    : pulseService_(pulseService),
      mdbService_(mdbService),
      pulseConfigService_(pulseConfigService),
      otaService_(otaService) {}

// Разбирает JSON-команду от backend и маршрутизирует её в нужный сервис.
void CommandService::handleTextMessage(const uint8_t *payload, size_t length)
{
  if (kLogIncomingWsText)
  {
    logSerialText("WS text: ");
    logSerialBytes(payload, length);
    logSerialLine("");
  }

  // Ранний отсев служебного websocket-мусора даже если он приходит
  // фрагментами/повторами и не является полноценным JSON-командным пакетом.
  if (isIgnorableTransportNoiseRaw(payload, length))
  {
    return;
  }

  JsonDocument doc;
  const auto error = deserializeJson(doc, payload, length);
  if (error)
  {
    logSerialLine(String("WS JSON parse failed: ") + error.c_str());
    mdbService_.emitControlEvent(
        "transport_error",
        String("{\"reason\":\"json_parse_failed\",\"error\":\"") +
            error.c_str() + "\",\"length\":" + length + "}");
    return;
  }

  const String messageType = String(doc["type"] | "");
  if (messageType != "command")
  {
    if (isIgnorableTransportType(messageType))
    {
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
  if (!payloadNode.is<JsonObject>())
  {
    mdbService_.emitControlEvent(
        "command_rejected",
        "{\"command\":\"\",\"reason\":\"missing_payload_object\"}");
    return;
  }

  const char *commandName = payloadNode["command"] | "";
  const String command = String(commandName);
  mdbService_.emitControlEvent(
      "command_received",
      String("{\"command\":\"") + command + "\",\"length\":" + length + "}");

  if (command == "pay")
  {
    const unsigned long amountMinor =
        payloadNode["payload"]["amount"].is<unsigned long>()
            ? payloadNode["payload"]["amount"].as<unsigned long>()
            : 0;
    const String transport =
        String(payloadNode["payload"]["transport"] | "pulse");

    if (transport == "pulse")
    {
      pulseService_.requestPulse(amountMinor);
      return;
    }

    if (transport == "mdb")
    {
      const String transactionId =
          String(payloadNode["payload"]["transaction_id"] | "");
      // This VMC uses a gateway protocol where credit is injected via the 0xFE
      // compat poll byte — standard cashless BEGIN SESSION flow is not used.
      // requestCoinPayment queues coinChangerPendingScaled_ which sendCoinChangerPollResponse
      // emits as coin-in bytes on the next 0xFE poll, regardless of operating mode.
      mdbService_.requestCoinPayment(amountMinor, transactionId);
      return;
    }

    if (transport == "uart")
    {
      mdbService_.emitControlEvent(
          "command_rejected",
          "{\"command\":\"pay\",\"reason\":\"uart_transport_disabled_mdb_only\"}");
      return;
    }

    logSerialLine(String("Unsupported pay transport: ") + transport);
    return;
  }

  if (command == "reboot")
  {
    pulseService_.requestReboot();
    return;
  }

  if (command == "refresh_pulse_config")
  {
    logSerialLine("Pulse config refresh requested");
    pulseConfigService_.requestRefresh();
    return;
  }

  if (command == "ota_update")
  {
    const char *url = payloadNode["payload"]["url"] | "";
    const char *version = payloadNode["payload"]["version"] | "";
    const char *sha256 = payloadNode["payload"]["sha256"] | "";
    otaService_.requestUpdate(String(url), String(version), String(sha256));
    return;
  }

  if (command == "mdb_probe")
  {
    mdbService_.requestProbe();
    return;
  }

  if (command == "mdb_irq_snapshot")
  {
    mdbService_.requestIrqSnapshot();
    return;
  }

  if (command == "phy_decoder_status")
  {
    mdbService_.requestPhyDecoderStatus();
    return;
  }

  if (command == "mdb_clear_session")
  {
    mdbService_.requestClearSession();
    return;
  }

  if (command == "mdb_approve")
  {
    const unsigned long amountMinor =
        payloadNode["payload"]["amount"].is<unsigned long>()
            ? payloadNode["payload"]["amount"].as<unsigned long>()
            : 0;
    const String transactionId =
        String(payloadNode["payload"]["transaction_id"] | "");
    mdbService_.requestApproveCredit(amountMinor, transactionId);
    return;
  }

  if (command == "mdb_monitor_start")
  {
    mdbService_.setMonitorEnabled(true);
    return;
  }

  if (command == "mdb_passive_sniff_on")
  {
    mdbService_.setPassiveSniffEnabled(true);
    return;
  }

  if (command == "mdb_passive_sniff_off")
  {
    mdbService_.setPassiveSniffEnabled(false);
    return;
  }

  if (command == "mdb_sniff_recent")
  {
    mdbService_.requestSniffRecent();
    return;
  }

  if (command == "mdb_sniff_summary")
  {
    mdbService_.requestSniffSummary();
    return;
  }

  if (command == "mdb_sniff_stats")
  {
    mdbService_.requestSniffStats();
    return;
  }

  if (command == "mdb_sniff_clear")
  {
    mdbService_.requestSniffClear();
    return;
  }

  if (command == "mdb_set_expected_address")
  {
    const int address =
        payloadNode["payload"]["expected_address"].is<int>()
            ? payloadNode["payload"]["expected_address"].as<int>()
            : -1;
    mdbService_.setExpectedAddress(address);
    return;
  }

  if (command == "mdb_set_cashless_address")
  {
    const int address =
        payloadNode["payload"]["cashless_address"].is<int>()
            ? payloadNode["payload"]["cashless_address"].as<int>()
            : 2;
    mdbService_.setCashlessAddress(address);
    return;
  }

  if (command == "mdb_gateway_profile")
  {
    const int profileId =
        payloadNode["payload"]["profile_id"].is<int>()
            ? payloadNode["payload"]["profile_id"].as<int>()
            : 0;
    mdbService_.setGatewayCompatResponseProfile(
        static_cast<uint8_t>(profileId < 0 ? 0 : profileId));
    return;
  }

  if (command == "mdb_setup_response_experiment")
  {
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

  if (command == "mdb_setup_variant_cycle_on")
  {
    const int startIndex = payloadNode["payload"]["start_index"] | 0;
    mdbService_.setSetupResponseVariantCycle(
        true,
        static_cast<uint8_t>(startIndex < 0 ? 0 : startIndex));
    return;
  }

  if (command == "mdb_setup_variant_cycle_off")
  {
    mdbService_.setSetupResponseVariantCycle(false);
    return;
  }

  if (command == "mdb_mode_cashless")
  {
    mdbService_.setMdbOperatingMode(MdbService::MdbOperatingMode::Cashless);
    return;
  }

  if (command == "mdb_mode_coin_changer")
  {
    mdbService_.setMdbOperatingMode(MdbService::MdbOperatingMode::CoinChanger);
    return;
  }

  if (command == "mdb_experiment_enable")
  {
    mdbService_.setExperimentEnabled(true);
    return;
  }

  if (command == "mdb_experiment_disable")
  {
    mdbService_.setExperimentEnabled(false);
    return;
  }

  if (command == "mdb_experiment_fire_once")
  {
    mdbService_.requestExperimentFireOnce();
    return;
  }

  if (command == "mdb_experiment_configure")
  {
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
    const char *experimentMode =
        payloadNode["payload"]["experiment_mode"].is<const char *>()
            ? payloadNode["payload"]["experiment_mode"].as<const char *>()
            : "single_byte_probe";
    const uint8_t protocolProbeCandidateId =
        payloadNode["payload"]["protocol_probe_candidate_id"].is<int>()
            ? static_cast<uint8_t>(
                  payloadNode["payload"]["protocol_probe_candidate_id"].as<int>())
            : 0;
    uint8_t encodedBaselineSeriesCount = baselineSeriesCount;
    if (strcmp(experimentMode, "protocol_shaped_probe") == 0 &&
        protocolProbeCandidateId > 0)
    {
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

  if (command == "mdb_credit_flow_start")
  {
    const unsigned long amountMinor =
        payloadNode["payload"]["amount_minor"].is<unsigned long>()
            ? payloadNode["payload"]["amount_minor"].as<unsigned long>()
            : 1000;
    mdbService_.startCreditFlowStrategy(
        static_cast<uint16_t>(amountMinor > 0xFFFFUL ? 0xFFFFU : amountMinor));
    return;
  }

  if (command == "mdb_credit_flow_stop")
  {
    mdbService_.stopCreditFlowStrategy();
    return;
  }

  if (command == "mdb_experiment_configure_protocol_probe")
  {
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

  if (command == "mdb_experiment_run_protocol_probe_once")
  {
    mdbService_.requestExperimentFireOnce();
    return;
  }

  if (command == "mdb_probe_tx")
  {
    mdbService_.requestProbeTx();
    return;
  }

  if (command == "mdb_rx_invert_on")
  {
    mdbService_.setRxInvertEnabled(true);
    return;
  }

  if (command == "mdb_rx_invert_off")
  {
    mdbService_.setRxInvertEnabled(false);
    return;
  }

  if (command == "mdb_pulse_test")
  {
    mdbService_.requestPulseTest();
    return;
  }

  if (command == "mdb_tx_hold_low_test")
  {
    mdbService_.requestHoldTxLowTest();
    return;
  }

  if (command == "mdb_monitor_stop")
  {
    mdbService_.setMonitorEnabled(false);
    return;
  }

  if (command == "mdb_raw_send")
  {
    const char *hexPayload = payloadNode["payload"]["hex"] | "";
    mdbService_.sendRawHex(String(hexPayload));
    return;
  }

  if (command == "uart_probe" || command == "uart_monitor_start" ||
      command == "uart_monitor_stop" || command == "uart_probe_tx" ||
      command == "uart_raw_send")
  {
    mdbService_.emitControlEvent(
        "command_rejected",
        String("{\"command\":\"") + command +
            "\",\"reason\":\"uart_service_disabled_mdb_only\"}");
    return;
  }

  mdbService_.emitControlEvent(
      "command_rejected",
      String("{\"command\":\"") + command +
          "\",\"reason\":\"unsupported_command\"}");
  logSerialLine(String("Unsupported command: ") + command);
}

// Возвращает текущую MDB-сводку для debug/API-слоя.
String CommandService::buildMdbDebugStateJson() const
{
  return mdbService_.buildDebugStateJson();
}
