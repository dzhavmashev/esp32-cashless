#pragma once

#include <Arduino.h>

class ConnectionService;
class PulseService;

// Загружает из backend конфигурацию pulse-режима и применяет её локально.
class PulseConfigService {
 public:
  // Создаёт сервис синхронизации pulse-конфига.
  PulseConfigService(ConnectionService& connectionService,
                     PulseService& pulseService);

  // Периодически проверяет, нужно ли перечитать конфиг с backend.
  void update();
  // Помечает конфиг как требующий немедленного обновления.
  void requestRefresh();

 private:
  // Выполняет HTTP-запрос к backend и применяет полученный конфиг.
  bool fetchConfig();

  ConnectionService& connectionService_;
  PulseService& pulseService_;
  bool configLoaded_ = false;
  bool refreshRequested_ = false;
  bool lastWebSocketConnected_ = false;
};
