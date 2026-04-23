#include "connection_service.h"

#include <WiFi.h>

#include "device_config.h"
#include "logging_utils.h"

ConnectionService* ConnectionService::instance_ = nullptr;

// Инициализирует сетевой стек и настраивает callback WebSocket-клиента.
void ConnectionService::begin() {
  instance_ = this;
  deviceId_ = buildDeviceId();
  if (outboxMutex_ == nullptr) {
    outboxMutex_ = xSemaphoreCreateMutex();
  }
  webSocket_.onEvent(handleWebSocketEventStatic);
  webSocket_.setReconnectInterval(0);
}

// Поддерживает Wi‑Fi и WebSocket в рабочем состоянии.
void ConnectionService::update() {
  if (!connectToWifi()) {
    websocketConnected_ = false;
    return;
  }

  ensureWebSocketConnected();
}

// Назначает обработчик текстовых WS-пакетов.
void ConnectionService::setMessageHandler(TextMessageHandler handler) {
  messageHandler_ = handler;
}

// Возвращает признак активного Wi‑Fi-подключения.
bool ConnectionService::isWifiConnected() const {
  return wifiConnected_;
}

// Возвращает признак активного WebSocket-подключения.
bool ConnectionService::isWebSocketConnected() const {
  return websocketConnected_;
}

// Возвращает локальный IP устройства.
String ConnectionService::localIpString() const {
  return WiFi.localIP().toString();
}

// Возвращает MAC-адрес в строковом виде.
String ConnectionService::rawMacAddress() const { return WiFi.macAddress(); }

// Возвращает вычисленный device_id устройства.
const String& ConnectionService::deviceId() const { return deviceId_; }

// Отправляет текстовое сообщение в backend по WebSocket.
bool ConnectionService::sendText(const String& message) {
  if (!websocketConnected_) {
    return false;
  }

  return enqueueOutgoingText(message);
}

size_t ConnectionService::outboxDepth() const { return webSocketOutboxCount_; }

size_t ConnectionService::outboxCapacity() const { return kWebSocketOutboxSize; }

// Статический мост из callback библиотеки в текущий экземпляр сервиса.
void ConnectionService::handleWebSocketEventStatic(WStype_t type,
                                                   uint8_t* payload,
                                                   size_t length) {
  if (instance_ != nullptr) {
    instance_->handleWebSocketEvent(type, payload, length);
  }
}

// Обрабатывает события подключения, отключения и входящие WS-сообщения.
void ConnectionService::handleWebSocketEvent(WStype_t type, uint8_t* payload,
                                             size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      websocketConnected_ = true;
      logMessage("WebSocket connected", deviceId_);
      break;
    case WStype_DISCONNECTED:
      websocketConnected_ = false;
      clearWebSocketOutbox();
      logMessage("WebSocket disconnected", deviceId_);
      break;
    case WStype_TEXT:
      if (messageHandler_ != nullptr) {
        messageHandler_(payload, length);
      }
      break;
    default:
      break;
  }
}

// Формирует device_id из MAC-адреса без разделителей.
String ConnectionService::buildDeviceId() const {
  String mac = WiFi.macAddress();
  mac.replace(":", "");
  mac.toLowerCase();
  return mac;
}

// Поддерживает подключение к Wi‑Fi и повторные попытки при обрыве.
bool ConnectionService::connectToWifi() {
  const wl_status_t status = WiFi.status();

  if (status == WL_CONNECTED) {
    wifiConnectStarted_ = false;
    if (!wifiConnected_) {
      wifiConnected_ = true;
      if (!wifiLogged_) {
        logMessage("WiFi connected", localIpString());
        wifiLogged_ = true;
      }
    }
    return true;
  }

  if (wifiConnected_) {
    wifiConnected_ = false;
    wifiLogged_ = false;
    websocketConnected_ = false;
    logMessage("WiFi disconnected");
  }

  const unsigned long now = millis();
  if (!wifiConnectStarted_ ||
      now - lastWifiConnectAttemptAt_ >= WIFI_CONNECT_TIMEOUT_MS) {
    logMessage("Connecting WiFi", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
    wifiConnectStarted_ = true;
    lastWifiConnectAttemptAt_ = now;
  }

  return false;
}

// Поднимает WebSocket-подключение, если оно ещё не установлено.
void ConnectionService::ensureWebSocketConnected() {
  webSocket_.loop();

  if (websocketConnected_) {
    drainWebSocketOutbox();
    return;
  }

  const unsigned long now = millis();
  if (now - lastWsReconnectAttemptAt_ < WEBSOCKET_RETRY_INTERVAL_MS) {
    return;
  }

  const String path = String(WEBSOCKET_PATH_PREFIX) + deviceId_;
  logMessage("Connecting WebSocket", path);
  webSocket_.disconnect();
  clearWebSocketOutbox();
  webSocket_.begin(SERVER_HOST, SERVER_PORT, path);
  lastWsReconnectAttemptAt_ = now;
}

bool ConnectionService::enqueueOutgoingText(const String& message) {
  if (outboxMutex_ == nullptr) {
    return false;
  }
  if (message.isEmpty()) {
    return false;
  }

  xSemaphoreTake(outboxMutex_, portMAX_DELAY);
  bool droppedOldest = false;
  if (webSocketOutboxCount_ >= kWebSocketOutboxSize) {
    webSocketOutbox_[webSocketOutboxHead_] = String();
    webSocketOutboxHead_ =
        (webSocketOutboxHead_ + 1U) % kWebSocketOutboxSize;
    webSocketOutboxCount_--;
    droppedOldest = true;
  }

  webSocketOutbox_[webSocketOutboxTail_] = message;
  if (webSocketOutbox_[webSocketOutboxTail_].length() != message.length()) {
    webSocketOutbox_[webSocketOutboxTail_] = String();
    xSemaphoreGive(outboxMutex_);
    return false;
  }
  webSocketOutboxTail_ =
      (webSocketOutboxTail_ + 1U) % kWebSocketOutboxSize;
  webSocketOutboxCount_++;
  xSemaphoreGive(outboxMutex_);
  return !droppedOldest;
}

void ConnectionService::drainWebSocketOutbox() {
  if (!websocketConnected_ || outboxMutex_ == nullptr) {
    return;
  }

  for (size_t sent = 0; sent < kWebSocketOutboxSize; ++sent) {
    String message;
    xSemaphoreTake(outboxMutex_, portMAX_DELAY);
    if (webSocketOutboxCount_ == 0) {
      xSemaphoreGive(outboxMutex_);
      break;
    }

    message = webSocketOutbox_[webSocketOutboxHead_];
    webSocketOutbox_[webSocketOutboxHead_] = String();
    webSocketOutboxHead_ =
        (webSocketOutboxHead_ + 1U) % kWebSocketOutboxSize;
    webSocketOutboxCount_--;
    xSemaphoreGive(outboxMutex_);

    const size_t messageLength = message.length();
    const char* cstr = message.c_str();
    if (messageLength == 0 || cstr == nullptr || cstr[0] == '\0') {
      continue;
    }

    if (!webSocket_.sendTXT(reinterpret_cast<uint8_t*>(const_cast<char*>(cstr)),
                            messageLength, false)) {
      websocketConnected_ = false;
      break;
    }
  }
}

void ConnectionService::clearWebSocketOutbox() {
  if (outboxMutex_ == nullptr) {
    return;
  }

  xSemaphoreTake(outboxMutex_, portMAX_DELAY);
  for (size_t i = 0; i < kWebSocketOutboxSize; ++i) {
    webSocketOutbox_[i] = String();
  }
  webSocketOutboxHead_ = 0;
  webSocketOutboxTail_ = 0;
  webSocketOutboxCount_ = 0;
  xSemaphoreGive(outboxMutex_);
}
