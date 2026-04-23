#include "ota_manager.h"

// Создаёт менеджер OTA и внутренний сервис обновления.
OtaManager::OtaManager(ConnectionService& connectionService)
    : service_(connectionService) {}

// Инициализирует OTA-подсистему.
void OtaManager::begin() { service_.begin(); }

// Обслуживает очередь OTA.
void OtaManager::update() { service_.update(); }

// Ставит OTA-обновление в очередь.
void OtaManager::requestUpdate(const String& url, const String& version,
                               const String& sha256) {
  service_.requestUpdate(url, version, sha256);
}

// Назначает callback проверки, можно ли стартовать OTA.
void OtaManager::setCanStartUpdateCallback(std::function<bool()> callback) {
  service_.setCanStartUpdateCallback(std::move(callback));
}

// Возвращает сводку OTA-состояния.
String OtaManager::buildDebugStateJson() const {
  return service_.buildDebugStateJson();
}
