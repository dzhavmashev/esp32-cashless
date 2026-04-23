#pragma once

#include <Arduino.h>
#include <functional>

#include "ota_service.h"

class ConnectionService;

// Тонкая обёртка над OTA-сервисом для изоляции от прикладного кода.
class OtaManager {
 public:
  // Создаёт менеджер OTA и внутренний сервис обновления.
  explicit OtaManager(ConnectionService& connectionService);

  // Инициализирует OTA-подсистему.
  void begin();
  // Выполняет обработку очереди OTA.
  void update();
  // Ставит OTA-обновление в очередь.
  void requestUpdate(const String& url, const String& version,
                     const String& sha256 = "");
  // Назначает callback, который решает, безопасно ли начинать обновление.
  void setCanStartUpdateCallback(std::function<bool()> callback);
  // Возвращает отладочную сводку OTA.
  String buildDebugStateJson() const;

 private:
  OtaService service_;
};
