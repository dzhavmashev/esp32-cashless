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

  unsigned long readAmountMinor(JsonVariantConst payload)
  {
    if (payload["amount_minor"].is<unsigned long>())
    {
      return payload["amount_minor"].as<unsigned long>();
    }
    if (payload["amount"].is<unsigned long>())
    {
      return payload["amount"].as<unsigned long>();
    }
    return 0;
  }
} // namespace

CommandService::CommandService(PulseService &pulseService, MdbService &mdbService,
                               PulseConfigService &pulseConfigService,
                               OtaManager &otaService)
    : pulseService_(pulseService),
      mdbService_(mdbService),
      pulseConfigService_(pulseConfigService),
      otaService_(otaService) {}

void CommandService::handleTextMessage(const uint8_t *payload, size_t length)
{
  if (kLogIncomingWsText)
  {
    logSerialText("WS text: ");
    logSerialBytes(payload, length);
    logSerialLine("");
  }

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
  JsonVariant payloadNode;
  if (messageType == "command")
  {
    payloadNode = doc["payload"];
  }
  else if (doc["command"].is<const char *>())
  {
    payloadNode = doc.as<JsonVariant>();
  }
  else
  {
    if (isIgnorableTransportType(messageType))
      return;

    if (messageType == "mdb_set_peripheral_id")
    {
      const char *manuf  = doc["manufacturer"] | "ESP";
      const char *serial = doc["serial"]       | "000000000001";
      const char *model  = doc["model"]        | "MDB-CASHLESS";
      const uint8_t verHi = static_cast<uint8_t>(doc["version_hi"] | 0);
      const uint8_t verLo = static_cast<uint8_t>(doc["version_lo"] | 1);
      mdbService_.setPeripheralId(manuf, serial, model, verHi, verLo);
      mdbService_.start();
      return;
    }

    mdbService_.emitControlEvent(
        "command_rejected",
        String("{\"command\":\"\",\"reason\":\"unsupported_message_type\","
               "\"type\":\"") +
            messageType + "\"}");
    return;
  }

  if (!payloadNode.is<JsonObject>())
  {
    mdbService_.emitControlEvent(
        "command_rejected",
        "{\"command\":\"\",\"reason\":\"missing_payload_object\"}");
    return;
  }

  const String command = String(payloadNode["command"] | "");
  mdbService_.emitControlEvent(
      "command_received",
      String("{\"command\":\"") + command + "\",\"length\":" + length + "}");

  if (command == "pay")
  {
    const unsigned long amountMinor = readAmountMinor(payloadNode["payload"]);
    const String transport = String(payloadNode["payload"]["transport"] | "pulse");

    if (transport == "pulse")
    {
      pulseService_.requestPulse(amountMinor);
      return;
    }

    if (transport == "mdb")
    {
      if (amountMinor == 0 || amountMinor > 65535UL)
      {
        mdbService_.emitControlEvent(
            "command_rejected",
            String("{\"command\":\"pay\",\"reason\":\"bad_amount\","
                   "\"transport\":\"mdb\",\"amount_minor\":") +
                amountMinor + "}");
        return;
      }
      mdbService_.setCard(static_cast<uint16_t>(amountMinor));
      return;
    }

    logSerialLine(String("Unsupported pay transport: ") + transport);
    return;
  }

  if (command == "mdb_pay" || command == "mdb_card")
  {
    const unsigned long amountMinor = readAmountMinor(payloadNode["payload"]);
    if (amountMinor == 0 || amountMinor > 65535UL)
    {
      mdbService_.emitControlEvent(
          "command_rejected",
          String("{\"command\":\"") + command +
              "\",\"reason\":\"bad_amount\",\"amount_minor\":" + amountMinor + "}");
      return;
    }
    mdbService_.setCard(static_cast<uint16_t>(amountMinor));
    return;
  }

  if (command == "mdb_pay100")
  {
    mdbService_.setCard(100);
    return;
  }

  if (command == "mdb_status")
  {
    mdbService_.emitStatus();
    return;
  }

  if (command == "mdb_remove")
  {
    mdbService_.removeCard();
    return;
  }

  if (command == "mdb_reset")
  {
    mdbService_.reset();
    return;
  }

  if (command == "mdb_tx0")
  {
    mdbService_.holdTxLow();
    return;
  }

  if (command == "mdb_tx1")
  {
    mdbService_.holdTxHigh();
    return;
  }

  if (command == "mdb_txidle")
  {
    mdbService_.txIdle();
    return;
  }

  if (command == "mdb_selftest")
  {
    mdbService_.selfTest();
    return;
  }

  if (command == "mdb_txinv")
  {
    mdbService_.toggleTxInvert();
    return;
  }

  if (command == "mdb_rxinv")
  {
    mdbService_.toggleRxInvert();
    return;
  }

  if (command == "mdb_ackmode")
  {
    const bool enabled =
        payloadNode["payload"]["enabled"].is<bool>()
            ? payloadNode["payload"]["enabled"].as<bool>()
            : ((payloadNode["payload"]["mode"].is<int>()
                    ? payloadNode["payload"]["mode"].as<int>()
                    : (payloadNode["payload"]["value"].is<int>()
                           ? payloadNode["payload"]["value"].as<int>()
                           : 1)) != 0);
    mdbService_.setAckMode(enabled);
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

  mdbService_.emitControlEvent(
      "command_rejected",
      String("{\"command\":\"") + command +
          "\",\"reason\":\"unsupported_command\"}");
  logSerialLine(String("Unsupported command: ") + command);
}

String CommandService::buildMdbDebugStateJson() const
{
  return mdbService_.statusJson();
}
