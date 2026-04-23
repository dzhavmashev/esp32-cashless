#include "mdb_codec.h"

namespace mdb {

// Вычисляет 8-битную checksum как сумму байтов по модулю 256.
uint8_t checksum(const uint8_t* data, size_t length) {
  uint16_t sum = 0;
  for (size_t i = 0; i < length; ++i) {
    sum += data[i];
  }
  return static_cast<uint8_t>(sum & 0xFF);
}

// Разбирает master-блок на адрес, команду и данные с проверкой checksum.
bool parseMasterBlock(const uint8_t* data, size_t length, MasterBlock& out) {
  if (length == 0) {
    return false;
  }

  if (length == 1) {
    out.address = data[0] >> 3;
    out.command = data[0] & 0x07;
    out.dataLength = 0;
    out.checksumValid = true;
    return true;
  }

  if (length < 2 || length > 36) {
    return false;
  }

  out.address = data[0] >> 3;
  out.command = data[0] & 0x07;
  out.dataLength = length - 2;

  for (size_t i = 0; i < out.dataLength; ++i) {
    out.data[i] = data[i + 1];
  }

  out.checksumValid = checksum(data, length - 1) == data[length - 1];
  return true;
}

// Формирует slave-блок с полезной нагрузкой и checksum.
size_t buildSlaveBlock(const uint8_t* payload, size_t payloadLength, uint8_t* out,
                       size_t outCapacity) {
  if (payloadLength == 0 || outCapacity < payloadLength + 1) {
    return 0;
  }

  for (size_t i = 0; i < payloadLength; ++i) {
    out[i] = payload[i];
  }
  out[payloadLength] = checksum(payload, payloadLength);
  return payloadLength + 1;
}

// Формирует одиночный служебный ответ ACK/NAK/RET.
size_t buildSingleByteResponse(uint8_t value, uint8_t* out, size_t outCapacity) {
  if (outCapacity == 0) {
    return 0;
  }
  out[0] = value;
  return 1;
}

}  // namespace mdb
