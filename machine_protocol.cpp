#include "machine_protocol.h"

#include "mdb_codec.h"

namespace machine {
namespace {
// Преобразует набор байтов в HEX-строку для логов и WS-событий.
String bytesToHex(const uint8_t* data, size_t length) {
  String result;
  for (size_t i = 0; i < length; ++i) {
    if (i > 0) {
      result += ' ';
    }
    if (data[i] < 0x10) {
      result += '0';
    }
    result += String(data[i], HEX);
  }
  result.toUpperCase();
  return result;
}
}  // namespace

// Строит нормализованный кадр из сырых байтов линии автомата.
void buildFrame(const RawByte* source, size_t length, Frame& out) {
  out = {};
  if (length > kMaxFrameBytes) {
    length = kMaxFrameBytes;
  }

  out.length = length;
  out.normalizedLength = length;
  for (size_t i = 0; i < length; ++i) {
    out.bytes[i] = source[i];
    out.normalized[i] = source[i].value7;
    out.hasHighBit = out.hasHighBit || source[i].highBit;
  }
  out.startedAtMs = source[0].tsMs;
  out.endedAtMs = source[length - 1].tsMs;
  out.startedAtUs = source[0].tsUs;
  out.endedAtUs = source[length - 1].tsUs;
  out.frameGapBeforeMs = source[0].gapBeforeMs;

  if (length == 0) {
    return;
  }

  out.hasCandidateAddress = true;
  out.candidateAddress = out.normalized[0] >> 3;
  out.candidateCommand = out.normalized[0] & 0x07;
  out.looksLikePoll = length <= 2 && out.candidateCommand == 0;
  out.looksLikeCommand = !out.looksLikePoll;

  mdb::MasterBlock block;
  out.parseOk = mdb::parseMasterBlock(out.normalized, out.normalizedLength, block);
  out.checksumValid = out.parseOk && block.checksumValid;
  out.maybePartial = !out.checksumValid && length <= 2;
  out.maybeMerged = length > 8;
  out.captureQuality = out.checksumValid ? 100 : (out.parseOk ? 60 : 25);
}

// Возвращает HEX-строку сырых байтов кадра.
String rawHex(const Frame& frame) {
  uint8_t buffer[kMaxFrameBytes] = {};
  for (size_t i = 0; i < frame.length; ++i) {
    buffer[i] = frame.bytes[i].raw;
  }
  return bytesToHex(buffer, frame.length);
}

// Возвращает HEX-строку нормализованных байтов кадра.
String normalizedHex(const Frame& frame) {
  return bytesToHex(frame.normalized, frame.normalizedLength);
}

}  // namespace machine
