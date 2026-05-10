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
  // Возвращает true если конфиг был успешно загружен хотя бы раз.
  bool isLoaded() const;
  // Возвращает true если стоит флаг запроса на обновление конфига.
  bool isRefreshRequested() const;
  // Возвращает true если последний fetch упал и cooldown ещё не истёк.
  bool hasFailedRecently() const;

 private:
  // Выполняет HTTP-запрос к backend и применяет полученный конфиг.
  bool fetchConfig();

  static constexpr unsigned long RETRY_INTERVAL_MS = 30000;

  ConnectionService& connectionService_;
  PulseService& pulseService_;
  bool configLoaded_ = false;
  bool refreshRequested_ = false;
  bool lastWebSocketConnected_ = false;
  bool lastFetchFailed_ = false;
  unsigned long lastAttemptMs_ = 0;
};
