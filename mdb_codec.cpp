#include "mdb_codec.h"

namespace mdb
{

  // Вычисляет 8-битную checksum как сумму байтов по модулю 256.
  uint8_t checksum(const uint8_t *data, size_t length)
  {
    if (data == nullptr || length == 0)
    {
      return 0;
    }

    uint16_t sum = 0;

    for (size_t i = 0; i < length; ++i)
    {
      sum = static_cast<uint16_t>(sum + data[i]);
    }

    return static_cast<uint8_t>(sum & 0xFFU);
  }

  // Разбирает master-блок на адрес, команду и данные с проверкой checksum.
  bool parseMasterBlock(const uint8_t *data, size_t length, MasterBlock &out)
  {
    out = MasterBlock{};

    if (data == nullptr || length == 0)
    {
      return false;
    }

    if (length == 1)
    {
      out.address = data[0] >> 3;
      out.command = data[0] & 0x07;
      out.dataLength = 0;
      out.checksumValid = true;
      return true;
    }

    if (length < 2 || length > 36)
    {
      return false;
    }

    out.address = data[0] >> 3;
    out.command = data[0] & 0x07;
    out.dataLength = length - 2;

    for (size_t i = 0; i < out.dataLength; ++i)
    {
      out.data[i] = data[i + 1];
    }

    const uint8_t expectedChecksum = checksum(data, length - 1);
    const uint8_t actualChecksum = data[length - 1];

    out.checksumValid = expectedChecksum == actualChecksum;
    return true;
  }

  // Формирует slave-блок с полезной нагрузкой и checksum.
  // В MDB slave response checksum считается только по payload,
  // без address byte.
  size_t buildSlaveBlock(
      const uint8_t *payload,
      size_t payloadLength,
      uint8_t *out,
      size_t outCapacity)
  {
    if (payload == nullptr || out == nullptr)
    {
      return 0;
    }

    if (payloadLength == 0)
    {
      return 0;
    }

    if (outCapacity < payloadLength + 1)
    {
      return 0;
    }

    // Чистим только доступный out-буфер, чтобы не оставался старый мусор.
    for (size_t i = 0; i < outCapacity; ++i)
    {
      out[i] = 0x00;
    }

    for (size_t i = 0; i < payloadLength; ++i)
    {
      out[i] = payload[i];
    }

    // Считаем checksum уже по out, то есть по фактическим байтам,
    // которые уйдут в линию.
    const uint8_t cs = checksum(out, payloadLength);
    out[payloadLength] = cs;

    return payloadLength + 1;
  }

  // Формирует одиночный служебный ответ ACK/NAK/RET.
  size_t buildSingleByteResponse(uint8_t value, uint8_t *out, size_t outCapacity)
  {
    if (out == nullptr || outCapacity == 0)
    {
      return 0;
    }

    out[0] = value;
    return 1;
  }

} // namespace mdb