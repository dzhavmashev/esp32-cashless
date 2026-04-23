#include "ota_service.h"

#include <HTTPClient.h>
#include <StreamString.h>
#include <Update.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <mbedtls/sha256.h>

#include "connection_service.h"

namespace {
constexpr unsigned long kProgressEmitIntervalMs = 1000;
constexpr unsigned long kFirstByteTimeoutMs = 8000;
constexpr unsigned long kChunkTimeoutMs = 15000;

// Возвращает JSON-представление булева значения без использования сериализатора.
String boolToJson(bool value) { return value ? "true" : "false"; }

// Возвращает текст последней ошибки библиотеки Update.
String updateErrorString() {
  StreamString error;
  Update.printError(error);
  error.trim();
  return String(error.c_str());
}
}  // namespace

OtaService::OtaService(ConnectionService& connectionService)
    : connectionService_(connectionService) {}

// Инициализирует OTA и подписывает callback прогресса.
void OtaService::begin() {
  Update.onProgress([this](size_t current, size_t total) {
    emitProgress(current, total);
  });
}

// Сохраняет callback, который запрещает обновление в критической фазе.
void OtaService::setCanStartUpdateCallback(std::function<bool()> callback) {
  canStartUpdate_ = std::move(callback);
}

// Главный цикл OTA: скачивание, проверка хэша, запись во flash и reboot.
void OtaService::update() {
  if (!updatePending_ || updateInProgress_) {
    return;
  }

  if (!connectionService_.isWifiConnected()) {
    lastErrorCode_ = -1;
    lastErrorMessage_ = "wifi_not_connected";
    updatePending_ = false;
    emitEvent("rejected", String("{\"reason\":\"wifi_not_connected\"}"));
    return;
  }

  if (canStartUpdate_ && !canStartUpdate_()) {
    if (!deferredNoticeSent_) {
      deferredNoticeSent_ = true;
      emitEvent("deferred", String("{\"reason\":\"busy_session\",\"version\":\"") +
                                 escapeForJson(pendingVersion_) + "\"}");
    }
    return;
  }

  updatePending_ = false;
  updateInProgress_ = true;
  deferredNoticeSent_ = false;
  lastUpdateStartedAt_ = millis();
  lastProgressPercent_ = -1;
  lastProgressEmitAt_ = 0;
  emitEvent("start", String("{\"url\":\"") + escapeForJson(pendingUrl_) +
                         "\",\"version\":\"" + escapeForJson(pendingVersion_) +
                         "\",\"sha256\":\"" + escapeForJson(pendingSha256_) + "\"}");

  WiFiClient client;
  HTTPClient http;
  http.setFollowRedirects(HTTPC_FORCE_FOLLOW_REDIRECTS);
  http.setTimeout(15000);
  if (!http.begin(client, pendingUrl_)) {
    lastErrorCode_ = -2001;
    lastErrorMessage_ = "http_begin_failed";
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  const int code = http.GET();
  if (code != HTTP_CODE_OK) {
    lastErrorCode_ = code;
    lastErrorMessage_ = String("http_get_failed:");
    lastErrorMessage_ += code;
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  const int contentLength = http.getSize();
  if (contentLength <= 0) {
    lastErrorCode_ = -2002;
    lastErrorMessage_ = "content_length_missing";
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  WiFiClient* stream = http.getStreamPtr();
  const unsigned long waitStartedAt = millis();
  while (stream->available() <= 0 && http.connected() &&
         millis() - waitStartedAt < kFirstByteTimeoutMs) {
    delay(10);
  }

  if (stream->available() <= 0) {
    lastErrorCode_ = -2003;
    lastErrorMessage_ = "first_byte_timeout";
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  const int firstByte = stream->read();
  if (firstByte != 0xE9) {
    lastErrorCode_ = -2004;
    lastErrorMessage_ = String("bad_magic_byte:");
    lastErrorMessage_ += firstByte;
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  if (!Update.begin(static_cast<size_t>(contentLength), U_FLASH)) {
    lastErrorCode_ = Update.getError();
    lastErrorMessage_ = updateErrorString();
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  uint8_t firstByteBuffer = static_cast<uint8_t>(firstByte);
  mbedtls_sha256_context shaContext;
  mbedtls_sha256_init(&shaContext);
  mbedtls_sha256_starts(&shaContext, 0);
  mbedtls_sha256_update(&shaContext, &firstByteBuffer, 1);

  if (Update.write(&firstByteBuffer, 1) != 1) {
    lastErrorCode_ = Update.getError();
    lastErrorMessage_ = updateErrorString();
    Update.abort();
    http.end();
    mbedtls_sha256_free(&shaContext);
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  size_t written = 1;
  unsigned long lastChunkAt = millis();
  uint8_t buffer[1024];
  while (written < static_cast<size_t>(contentLength)) {
    const size_t remaining = static_cast<size_t>(contentLength) - written;
    const size_t toRead =
        remaining > sizeof(buffer) ? sizeof(buffer) : remaining;
    const int read = stream->readBytes(buffer, toRead);
    if (read <= 0) {
      if (millis() - lastChunkAt >= kChunkTimeoutMs) {
        lastErrorCode_ = -2006;
        lastErrorMessage_ = "body_read_timeout";
        break;
      }
      delay(5);
      continue;
    }
    lastChunkAt = millis();
    mbedtls_sha256_update(&shaContext, buffer, static_cast<size_t>(read));
    if (Update.write(buffer, static_cast<size_t>(read)) !=
        static_cast<size_t>(read)) {
      break;
    }
    written += static_cast<size_t>(read);
  }

  uint8_t hash[32] = {};
  char hashHex[65] = {};
  mbedtls_sha256_finish(&shaContext, hash);
  mbedtls_sha256_free(&shaContext);
  for (size_t i = 0; i < sizeof(hash); ++i) {
    snprintf(hashHex + i * 2, 3, "%02x", hash[i]);
  }

  if (!pendingSha256_.isEmpty() &&
      !pendingSha256_.equalsIgnoreCase(String(hashHex))) {
    lastErrorCode_ = -2005;
    lastErrorMessage_ = "sha256_mismatch";
    Update.abort();
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"actual_sha256\":\"" +
                  hashHex + "\",\"expected_sha256\":\"" +
                  escapeForJson(pendingSha256_) + "\"}");
    return;
  }

  if (written != static_cast<size_t>(contentLength) || !Update.end()) {
    if (lastErrorCode_ == 0) {
      lastErrorCode_ = Update.getError();
      lastErrorMessage_ = updateErrorString();
    }
    Update.abort();
    http.end();
    lastUpdateFinishedAt_ = millis();
    updateInProgress_ = false;
    emitEvent("failed",
              String("{\"code\":") + lastErrorCode_ + ",\"message\":\"" +
                  escapeForJson(lastErrorMessage_) + "\",\"written\":" + written +
                  ",\"expected\":" + contentLength + ",\"url\":\"" +
                  escapeForJson(pendingUrl_) + "\"}");
    return;
  }

  http.end();
  lastUpdateFinishedAt_ = millis();
  updateInProgress_ = false;
  emitEvent("end", String("{\"url\":\"") + escapeForJson(pendingUrl_) + "\"}");
  emitEvent("rebooting", String("{\"url\":\"") + escapeForJson(pendingUrl_) + "\"}");
  delay(500);
  ESP.restart();
}

// Ставит новую прошивку в очередь на обновление.
void OtaService::requestUpdate(const String& url, const String& version,
                               const String& sha256) {
  if (url.isEmpty()) {
    emitEvent("rejected", String("{\"reason\":\"url_missing\"}"));
    return;
  }

  pendingUrl_ = url;
  pendingVersion_ = version;
  pendingSha256_ = sha256;
  updatePending_ = true;
  deferredNoticeSent_ = false;
  lastErrorCode_ = 0;
  lastErrorMessage_ = "";
  emitEvent("queued",
            String("{\"url\":\"") + escapeForJson(pendingUrl_) + "\",\"version\":\"" +
                escapeForJson(pendingVersion_) + "\",\"sha256\":\"" +
                escapeForJson(pendingSha256_) + "\"}");
}

// Возвращает JSON-сводку по состоянию OTA.
String OtaService::buildDebugStateJson() const {
  return String("{\"update_pending\":") + boolToJson(updatePending_) +
         ",\"update_in_progress\":" + boolToJson(updateInProgress_) +
        ",\"pending_url\":\"" + escapeForJson(pendingUrl_) + "\"" +
         ",\"pending_version\":\"" + escapeForJson(pendingVersion_) + "\"" +
         ",\"pending_sha256\":\"" + escapeForJson(pendingSha256_) + "\"" +
         ",\"last_update_started_at\":" + lastUpdateStartedAt_ +
         ",\"last_update_finished_at\":" + lastUpdateFinishedAt_ +
         ",\"last_error_code\":" + lastErrorCode_ + ",\"last_error_message\":\"" +
         escapeForJson(lastErrorMessage_) + "\"}";
}

// Отправляет OTA-событие в backend.
void OtaService::emitEvent(const char* eventType, const String& details) {
  if (!connectionService_.isWebSocketConnected()) {
    return;
  }

  const String message = String("{\"type\":\"ota_event\",\"event\":\"") + eventType +
                         "\",\"device_id\":\"" + connectionService_.deviceId() +
                         "\",\"details\":" + details + "}";
  connectionService_.sendText(message);
}

// Отправляет в backend обновление прогресса OTA.
void OtaService::emitProgress(size_t current, size_t total) {
  const unsigned long now = millis();
  const int percent =
      total == 0 ? 0 : static_cast<int>((current * 100U) / total);
  if (percent == lastProgressPercent_ &&
      now - lastProgressEmitAt_ < kProgressEmitIntervalMs) {
    return;
  }

  lastProgressPercent_ = percent;
  lastProgressEmitAt_ = now;
  emitEvent("progress", String("{\"current\":") + current + ",\"total\":" + total +
                             ",\"percent\":" + percent + "}");
}

// Экранирует строку для ручной сборки JSON.
String OtaService::escapeForJson(const String& text) {
  String escaped;
  escaped.reserve(text.length() + 8);
  for (size_t i = 0; i < text.length(); ++i) {
    const char ch = text[i];
    if (ch == '\\' || ch == '"') {
      escaped += '\\';
    }
    escaped += ch;
  }
  return escaped;
}
