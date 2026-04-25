#include "status_leds.h"

#include "device_config.h"

namespace {
bool isConfiguredPin(int pin) { return pin >= 0; }

void configureOutputIfNeeded(int pin) {
  if (isConfiguredPin(pin)) {
    pinMode(pin, OUTPUT);
  }
}

void writeIfConfigured(int pin, bool enabled) {
  if (isConfiguredPin(pin)) {
    digitalWrite(pin, enabled ? HIGH : LOW);
  }
}
}  // namespace

// Инициализирует GPIO светодиодов и стартовое состояние индикации.
void StatusLeds::begin() {
  configureOutputIfNeeded(GREEN_LED_PIN);
  configureOutputIfNeeded(RED_LED_PIN);
  configureOutputIfNeeded(YELLOW_LED_PIN);
  setLeds(false, false);
  setYellowLed(true);
}

// Обновляет индикацию по состоянию Wi‑Fi, WebSocket и активности команд.
void StatusLeds::update(bool wifiConnected, bool websocketConnected) {
  const unsigned long now = millis();

  if (!wifiConnected) {
    if (now - lastYellowBlinkAt_ >= WIFI_LED_BLINK_INTERVAL_MS) {
      yellowState_ = !yellowState_;
      lastYellowBlinkAt_ = now;
    }
    setYellowLed(yellowState_);
    setLeds(false, false);
    redState_ = false;
    return;
  }

  if (now < commandBlinkUntil_) {
    if (now - lastYellowBlinkAt_ >= WIFI_LED_BLINK_INTERVAL_MS) {
      yellowState_ = !yellowState_;
      lastYellowBlinkAt_ = now;
    }
    setYellowLed(yellowState_);
  } else {
    setYellowLed(false);
    yellowState_ = false;
  }

  if (websocketConnected) {
    setLeds(true, false);
    redState_ = false;
    return;
  }

  if (now - lastRedBlinkAt_ >= WEBSOCKET_LED_BLINK_INTERVAL_MS) {
    redState_ = !redState_;
    lastRedBlinkAt_ = now;
  }
  setLeds(false, redState_);
}

// Устанавливает состояние зелёного и красного светодиодов.
void StatusLeds::setLeds(bool greenOn, bool redOn) {
  writeIfConfigured(GREEN_LED_PIN, greenOn);
  writeIfConfigured(RED_LED_PIN, redOn);
}

// Устанавливает состояние жёлтого светодиода.
void StatusLeds::setYellowLed(bool enabled) {
  writeIfConfigured(YELLOW_LED_PIN, enabled);
}

// Включает временную индикацию получения команды.
void StatusLeds::notifyCommandReceived() {
  commandBlinkUntil_ = millis() + LED_ON_TIME_MS;
  lastYellowBlinkAt_ = 0;
  yellowState_ = false;
}
