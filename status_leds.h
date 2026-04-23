#pragma once

#include <Arduino.h>

// Управляет светодиодной индикацией статуса связи и входящих команд.
class StatusLeds {
 public:
  // Инициализирует GPIO светодиодов.
  void begin();
  // Обновляет состояние индикаторов по текущему состоянию сети и WS.
  void update(bool wifiConnected, bool websocketConnected);
  // Запускает краткую индикацию получения команды.
  void notifyCommandReceived();

 private:
  // Устанавливает состояние зелёного и красного светодиодов.
  void setLeds(bool greenOn, bool redOn);
  // Устанавливает состояние жёлтого светодиода.
  void setYellowLed(bool enabled);

  unsigned long lastYellowBlinkAt_ = 0;
  unsigned long lastRedBlinkAt_ = 0;
  unsigned long commandBlinkUntil_ = 0;
  bool yellowState_ = false;
  bool redState_ = false;
};
