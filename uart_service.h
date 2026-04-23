#pragma once

#include <Arduino.h>
#include <esp_err.h>

class ConnectionService;

// Отдельный сервис для vendor-specific UART-режима и диагностики линии.
class UartService {
 public:
  // Создаёт сервис UART-режима.
  explicit UartService(ConnectionService& connectionService);

  // Базовая инициализация сервиса.
  void begin();
  // Обслуживает приём/передачу UART-данных.
  void update();
  // Активирует UART-порт.
  void activate();
  // Логически отключает UART-порт.
  void deactivate();
  // Принудительно переводит GPIO14 в raw-sniffer режим без UART2.
  esp_err_t debug_force_raw_sniffer();
  // Запрашивает отправку PAY-команды в UART-режиме.
  void requestPay(unsigned long amountMinor);
  // Публикует диагностическую информацию о порте.
  void requestProbe();
  // Отправляет тестовую UART-последовательность.
  void requestProbeTx();
  // Включает или выключает мониторинг входящих кадров.
  void setMonitorEnabled(bool enabled);
  // Отправляет произвольную HEX-последовательность.
  void sendRawHex(const String& hexPayload);
  // Возвращает JSON-сводку состояния UART-сервиса.
  String buildDebugStateJson() const;

 private:
  // Отправляет UART-событие в backend.
  void emitEvent(const char* eventType, const String& details);
  // Сбрасывает собранный RX-кадр по тайм-ауту.
  void flushRxFrameIfReady(unsigned long now);
  // Разбирает HEX-строку в набор байтов.
  bool parseHexPayload(const String& hexPayload, uint8_t* buffer, size_t& length);
  // Настраивает UART-порт и инверсию линий.
  void configurePort();

  ConnectionService& connectionService_;
  bool active_ = false;
  bool monitorEnabled_ = false;
  bool payPending_ = false;
  unsigned long pendingAmountMinor_ = 0;
  unsigned long lastRxByteAt_ = 0;
  unsigned long lastRxFrameAt_ = 0;
  unsigned long lastProbeTxAt_ = 0;
  unsigned long rxFrameCount_ = 0;
  unsigned long rxFramesAfterProbeTx_ = 0;
  uint8_t rxFrame_[128] = {};
  size_t rxFrameLength_ = 0;
};
