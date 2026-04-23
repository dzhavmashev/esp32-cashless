#include "pulse_config_service.h"

#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "connection_service.h"
#include "device_config.h"
#include "pulse_service.h"
#include "logging_utils.h"

namespace {
PulsePayType parsePulsePayType(const String& rawValue) {
  if (rawValue == "cash") {
    return PulsePayType::Cash;
  }
  if (rawValue == "coin") {
    return PulsePayType::Coin;
  }
  return PulsePayType::All;
}
}

PulseConfigService::PulseConfigService(ConnectionService& connectionService,
                                       PulseService& pulseService)
    : connectionService_(connectionService), pulseService_(pulseService) {}

// Поддерживает актуальность pulse-конфига после подключения и по запросу.
void PulseConfigService::update() {
  if (!connectionService_.isWifiConnected()) {
    lastWebSocketConnected_ = false;
    return;
  }

  const bool websocketConnected = connectionService_.isWebSocketConnected();
  const bool wsJustConnected = websocketConnected && !lastWebSocketConnected_;
  lastWebSocketConnected_ = websocketConnected;

  if (!websocketConnected) {
    return;
  }

  if (!configLoaded_ || refreshRequested_ || wsJustConnected) {
    configLoaded_ = fetchConfig();
    refreshRequested_ = false;
  }
}

// Помечает конфиг как требующий немедленного обновления.
void PulseConfigService::requestRefresh() {
  refreshRequested_ = true;
}

// Загружает pulse-конфиг с backend и применяет его локально.
bool PulseConfigService::fetchConfig() {
  HTTPClient http;
  WiFiClient client;
  const String portStr = SERVER_PORT == 0 ? "" : ":" + String(SERVER_PORT);
  const String path = String("/devices/") + connectionService_.deviceId() +
                      PULSE_CONFIG_PATH_SUFFIX;
  const String url = String(SERVER_SCHEME) + "://" + SERVER_HOST + portStr + path;

  client.setTimeout(15000);
  http.setReuse(false);

  if (!http.begin(client, url)) {
    logSerialLine("Pulse config HTTP begin failed");
    return false;
  }

  const int httpCode = http.GET();
  if (httpCode != 200) {
    logSerialLine(String("Pulse config HTTP failed: ") + httpCode);
    http.end();
    return false;
  }

  const String body = http.getString();
  http.end();

  JsonDocument doc;
  const auto error = deserializeJson(doc, body);
  if (error) {
    logSerialLine(String("Pulse config JSON parse failed: ") + error.c_str());
    return false;
  }

  PulseConfig config;
  config.payType = parsePulsePayType(String(doc["pay_type"] | "all"));
  const unsigned long legacyMinorUnitsPerPulse =
      doc["minor_units_per_pulse"] | MINOR_UNITS_PER_PULSE_DEFAULT;
  const unsigned long legacyPulseOnTimeMs =
      doc["pulse_on_time_ms"] | PULSE_ON_TIME_MS_DEFAULT;
  const unsigned long legacyPulseOffTimeMs =
      doc["pulse_off_time_ms"] | PULSE_OFF_TIME_MS_DEFAULT;

  config.bill.minorUnitsPerPulse =
      doc["bill_minor_units_per_pulse"] | BILL_MINOR_UNITS_PER_PULSE_DEFAULT;
  config.bill.pulseOnTimeMs =
      doc["bill_pulse_on_time_ms"] | legacyPulseOnTimeMs;
  config.bill.pulseOffTimeMs =
      doc["bill_pulse_off_time_ms"] | legacyPulseOffTimeMs;

  config.coin.minorUnitsPerPulse =
      doc["coin_minor_units_per_pulse"] | legacyMinorUnitsPerPulse;
  config.coin.pulseOnTimeMs =
      doc["coin_pulse_on_time_ms"] | legacyPulseOnTimeMs;
  config.coin.pulseOffTimeMs =
      doc["coin_pulse_off_time_ms"] | legacyPulseOffTimeMs;

  pulseService_.applyConfig(config);
  return true;
}
