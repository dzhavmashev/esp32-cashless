#pragma once

#include <Arduino.h>

namespace mdb_json
{
  inline String escapeForJson(const String &text)
  {
    String escaped;
    escaped.reserve(text.length() + 8);
    for (size_t i = 0; i < text.length(); ++i)
    {
      const char ch = text[i];
      if (ch == '\\' || ch == '"')
      {
        escaped += '\\';
      }
      escaped += ch;
    }
    return escaped;
  }

  inline String boolToJson(bool value) { return value ? "true" : "false"; }

  inline void appendByteHex(String &out, uint8_t value)
  {
    if (!out.isEmpty())
    {
      out += ' ';
    }
    if (value < 0x10)
    {
      out += '0';
    }
    out += String(value, HEX);
  }

  inline String bytesToHex(const uint8_t *data, size_t length)
  {
    String out;
    for (size_t i = 0; i < length; ++i)
    {
      appendByteHex(out, data[i]);
    }
    out.toUpperCase();
    return out;
  }

  inline String byteToHex(uint8_t value)
  {
    String out;
    if (value < 0x10)
    {
      out += '0';
    }
    out += String(value, HEX);
    out.toUpperCase();
    return out;
  }

  inline String byteBitsLsbFirst(uint8_t value, uint8_t bitCount)
  {
    String out;
    for (uint8_t i = 0; i < bitCount; ++i)
    {
      out += ((value >> i) & 0x1U) ? '1' : '0';
    }
    return out;
  }

  inline String byteBitsMsbView(uint8_t value, uint8_t bitCount)
  {
    String out;
    for (int i = static_cast<int>(bitCount) - 1; i >= 0; --i)
    {
      out += ((value >> i) & 0x1U) ? '1' : '0';
    }
    return out;
  }

  inline uint16_t raw9Word(uint8_t value, bool ninthBit)
  {
    return static_cast<uint16_t>(value) | (ninthBit ? 0x100U : 0U);
  }
} // namespace mdb_json
