#pragma once

#include <Arduino.h>

namespace mdb {

// Базовые служебные ответы MDB/MDB-like протокола.
constexpr uint8_t kAck = 0x00;
constexpr uint8_t kNak = 0xFF;
constexpr uint8_t kRet = 0xAA;

// Разобранный master-блок после нормализации и проверки checksum.
struct MasterBlock {
  uint8_t address = 0;
  uint8_t command = 0;
  uint8_t data[34] = {};
  size_t dataLength = 0;
  bool checksumValid = false;
};

// Считает checksum для массива байтов.
uint8_t checksum(const uint8_t* data, size_t length);
// Разбирает входящий master-блок и проверяет checksum.
bool parseMasterBlock(const uint8_t* data, size_t length, MasterBlock& out);
// Формирует slave-блок с checksum.
size_t buildSlaveBlock(const uint8_t* payload, size_t payloadLength, uint8_t* out,
                       size_t outCapacity);
// Формирует одиночный служебный ответ ACK/NAK/RET.
size_t buildSingleByteResponse(uint8_t value, uint8_t* out, size_t outCapacity);

}  // namespace mdb
