#include "status_leds.h"

#include "device_config.h"

// Инициализирует GPIO светодиодов и стартовое состояние индикации.
void StatusLeds::begin() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
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
  digitalWrite(GREEN_LED_PIN, greenOn ? HIGH : LOW);
  digitalWrite(RED_LED_PIN, redOn ? HIGH : LOW);
}

// Устанавливает состояние жёлтого светодиода.
void StatusLeds::setYellowLed(bool enabled) {
  digitalWrite(YELLOW_LED_PIN, enabled ? HIGH : LOW);
}

// Включает временную индикацию получения команды.
void StatusLeds::notifyCommandReceived() {
  commandBlinkUntil_ = millis() + LED_ON_TIME_MS;
  lastYellowBlinkAt_ = 0;
  yellowState_ = false;
}
