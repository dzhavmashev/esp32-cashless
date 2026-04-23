#pragma once

#include <Arduino.h>

// Печатает многострочное диагностическое сообщение в Serial.
void logMessage(const String& line1, const String& line2 = "",
                const String& line3 = "", const String& line4 = "");

// Печатает одну строку в Serial под общим mutex, чтобы вывод из разных задач не смешивался.
void logSerialLine(const String& line);

// Печатает C-строку в Serial под общим mutex.
void logSerialText(const char* text);

// Печатает сырой буфер в Serial под общим mutex.
void logSerialBytes(const uint8_t* data, size_t length);
