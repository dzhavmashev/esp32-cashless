#pragma once

#include <Arduino.h>
#include <functional>

class ConnectionService;

// Выполняет удалённое OTA-обновление прошивки по HTTP.
class OtaService {
 public:
  // Создаёт сервис OTA, привязанный к каналу связи с backend.
  explicit OtaService(ConnectionService& connectionService);

  // Инициализирует OTA-подсистему и callback прогресса.
  void begin();
  // Запускает и обслуживает отложенное OTA-обновление.
  void update();
  // Ставит новую версию в очередь на скачивание и установку.
  void requestUpdate(const String& url, const String& version,
                     const String& sha256 = "");
  // Назначает проверку, можно ли стартовать обновление прямо сейчас.
  void setCanStartUpdateCallback(std::function<bool()> callback);
  // Возвращает JSON-сводку по состоянию OTA.
  String buildDebugStateJson() const;

 private:
  // Отправляет OTA-событие в backend.
  void emitEvent(const char* eventType, const String& details);
  // Отправляет событие прогресса OTA.
  void emitProgress(size_t current, size_t total);
  // Экранирует строку для безопасной передачи в JSON.
  static String escapeForJson(const String& text);

  ConnectionService& connectionService_;
  std::function<bool()> canStartUpdate_;
  bool updatePending_ = false;
  bool updateInProgress_ = false;
  bool deferredNoticeSent_ = false;
  String pendingUrl_;
  String pendingVersion_;
  String pendingSha256_;
  int lastProgressPercent_ = -1;
  unsigned long lastProgressEmitAt_ = 0;
  unsigned long lastUpdateStartedAt_ = 0;
  unsigned long lastUpdateFinishedAt_ = 0;
  int lastErrorCode_ = 0;
  String lastErrorMessage_;
};
