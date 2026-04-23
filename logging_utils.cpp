#include "logging_utils.h"

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>

namespace {
SemaphoreHandle_t serialLogMutex() {
  static SemaphoreHandle_t mutex = xSemaphoreCreateMutex();
  return mutex;
}

template <typename Fn>
void withSerialLock(Fn&& fn) {
  SemaphoreHandle_t mutex = serialLogMutex();
  if (mutex == nullptr) {
    fn();
    return;
  }
  xSemaphoreTake(mutex, portMAX_DELAY);
  fn();
  xSemaphoreGive(mutex);
}
}  // namespace

void logSerialLine(const String& line) {
  withSerialLock([&]() { Serial.println(line); });
}

void logSerialText(const char* text) {
  withSerialLock([&]() { Serial.print(text == nullptr ? "" : text); });
}

void logSerialBytes(const uint8_t* data, size_t length) {
  withSerialLock([&]() {
    if (data != nullptr && length > 0) {
      Serial.write(data, length);
    }
  });
}

// Печатает до четырёх строк диагностического сообщения в Serial.
void logMessage(const String& line1, const String& line2, const String& line3,
                const String& line4) {
  withSerialLock([&]() {
    Serial.println(line1);
    if (!line2.isEmpty()) {
      Serial.println(line2);
    }
    if (!line3.isEmpty()) {
      Serial.println(line3);
    }
    if (!line4.isEmpty()) {
      Serial.println(line4);
    }
  });
}
