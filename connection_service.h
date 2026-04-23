#pragma once

#include <Arduino.h>
#include <WebSocketsClient.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>

// Управляет Wi‑Fi и WebSocket-соединением устройства с backend.
class ConnectionService {
 public:
  // Тип callback-функции для входящих текстовых WS-сообщений.
  using TextMessageHandler = void (*)(const uint8_t* payload, size_t length);

  // Инициализирует сетевые подсистемы и вычисляет device_id.
  void begin();
  // Поддерживает подключение к Wi‑Fi и WebSocket.
  void update();
  // Назначает обработчик входящих текстовых WS-сообщений.
  void setMessageHandler(TextMessageHandler handler);

  // Возвращает признак активного Wi‑Fi-подключения.
  bool isWifiConnected() const;
  // Возвращает признак активного WS-подключения.
  bool isWebSocketConnected() const;
  // Возвращает локальный IP как строку.
  String localIpString() const;
  // Возвращает MAC-адрес устройства.
  String rawMacAddress() const;
  // Возвращает device_id, используемый в backend.
  const String& deviceId() const;
  // Отправляет текстовый пакет в backend по WebSocket.
  bool sendText(const String& message);
  // Возвращает текущую глубину WS outbox для диагностики.
  size_t outboxDepth() const;
  // Возвращает ёмкость WS outbox для диагностики.
  size_t outboxCapacity() const;

 private:
  static constexpr size_t kWebSocketOutboxSize = 8;

  // Статический мост для передачи событий из библиотеки в экземпляр класса.
  static void handleWebSocketEventStatic(WStype_t type, uint8_t* payload,
                                         size_t length);
  // Реальная обработка событий WebSocket внутри экземпляра.
  void handleWebSocketEvent(WStype_t type, uint8_t* payload, size_t length);
  // Формирует стабильный device_id из MAC-адреса.
  String buildDeviceId() const;
  // Пытается подключиться к Wi‑Fi.
  bool connectToWifi();
  // Пытается поднять WS-подключение, если оно разорвано.
  void ensureWebSocketConnected();
  // Ставит текстовый пакет в очередь, чтобы отправка шла только из update-thread.
  bool enqueueOutgoingText(const String& message);
  // Выгружает накопленные пакеты в WebSocket из безопасного контекста update().
  void drainWebSocketOutbox();
  // Очищает очередь исходящих пакетов при разрыве transport.
  void clearWebSocketOutbox();

  static ConnectionService* instance_;

  bool wifiLogged_ = false;
  bool wifiConnectStarted_ = false;
  bool wifiConnected_ = false;
  unsigned long lastWifiConnectAttemptAt_ = 0;
  bool websocketConnected_ = false;
  unsigned long lastWsReconnectAttemptAt_ = 0;
  String deviceId_;
  WebSocketsClient webSocket_;
  TextMessageHandler messageHandler_ = nullptr;
  SemaphoreHandle_t outboxMutex_ = nullptr;
  String webSocketOutbox_[kWebSocketOutboxSize];
  size_t webSocketOutboxHead_ = 0;
  size_t webSocketOutboxTail_ = 0;
  size_t webSocketOutboxCount_ = 0;
};
