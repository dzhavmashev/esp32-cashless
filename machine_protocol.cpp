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

struct DecodedFrameResult {
  bool structurallyValid = false;
  bool checksumValid = false;
  bool strictModeBitsOk = false;
  bool relaxedDecodeUsed = false;
  bool singleByteCommand = false;
  bool hasAddressCommand = false;
  MdbDirection direction = MdbDirection::Unknown;
  MdbFrameKind kind = MdbFrameKind::Invalid;
  uint8_t checksumExpected = 0;
  uint8_t checksumReceived = 0;
  uint8_t addressByte = 0;
  uint8_t address5 = 0;
  uint8_t command3 = 0;
};

uint8_t sum8(const RawByte* source, size_t count) {
  uint8_t sum = 0;
  for (size_t i = 0; i < count; ++i) {
    sum = static_cast<uint8_t>(sum + source[i].value7);
  }
  return sum;
}

bool classifySingleByteResponse(uint8_t value, MdbFrameKind& outKind) {
  if (value == mdb::kAck) {
    outKind = MdbFrameKind::Ack;
    return true;
  }
  if (value == mdb::kNak) {
    outKind = MdbFrameKind::Nak;
    return true;
  }
  if (value == mdb::kRet) {
    outKind = MdbFrameKind::Ret;
    return true;
  }
  outKind = MdbFrameKind::Invalid;
  return false;
}

bool strictMasterPattern(const RawByte* source, size_t length) {
  if (length == 0 || !source[0].highBit) {
    return false;
  }
  for (size_t i = 1; i < length; ++i) {
    if (source[i].highBit) {
      return false;
    }
  }
  return true;
}

bool strictPeripheralPattern(const RawByte* source, size_t length) {
  if (length == 0 || !source[length - 1].highBit) {
    return false;
  }
  for (size_t i = 0; i + 1 < length; ++i) {
    if (source[i].highBit) {
      return false;
    }
  }
  return true;
}

DecodedFrameResult decodeFrame(const RawByte* source, size_t length,
                               MdbDirection direction, bool strictModeBits) {
  DecodedFrameResult out;
  out.direction = direction;
  out.relaxedDecodeUsed = !strictModeBits;
  if (length == 0) {
    return out;
  }

  const bool masterPatternOk = strictMasterPattern(source, length);
  const bool peripheralPatternOk = strictPeripheralPattern(source, length);
  out.strictModeBitsOk =
      direction == MdbDirection::MasterToPeripheral ? masterPatternOk
                                                     : peripheralPatternOk;

  if (length == 1) {
    if (direction == MdbDirection::MasterToPeripheral) {
      if (strictModeBits && !masterPatternOk) {
        return out;
      }
      out.structurallyValid = true;
      out.checksumValid = true;
      out.singleByteCommand = true;
      out.hasAddressCommand = true;
      out.kind = MdbFrameKind::DataBlock;
      out.addressByte = source[0].value7;
      out.address5 = static_cast<uint8_t>((source[0].value7 >> 3U) & 0x1FU);
      out.command3 = static_cast<uint8_t>(source[0].value7 & 0x07U);
      return out;
    }

    if (strictModeBits && !peripheralPatternOk) {
      return out;
    }

    MdbFrameKind kind = MdbFrameKind::Invalid;
    if (!classifySingleByteResponse(source[0].value7, kind)) {
      return out;
    }
    out.structurallyValid = true;
    out.checksumValid = true;
    out.kind = kind;
    return out;
  }

  const size_t checksumIndex = length - 1;
  if (direction == MdbDirection::MasterToPeripheral) {
    if (strictModeBits && !masterPatternOk) {
      return out;
    }
    out.structurallyValid = true;
    out.kind = MdbFrameKind::DataBlock;
    out.hasAddressCommand = true;
    out.addressByte = source[0].value7;
    out.address5 = static_cast<uint8_t>((source[0].value7 >> 3U) & 0x1FU);
    out.command3 = static_cast<uint8_t>(source[0].value7 & 0x07U);
    out.checksumExpected = sum8(source, checksumIndex);
    out.checksumReceived = source[checksumIndex].value7;
    out.checksumValid = out.checksumExpected == out.checksumReceived;
    return out;
  }

  if (strictModeBits && !peripheralPatternOk) {
    return out;
  }
  out.structurallyValid = true;
  out.kind = MdbFrameKind::DataBlock;
  out.checksumExpected = sum8(source, checksumIndex);
  out.checksumReceived = source[checksumIndex].value7;
  out.checksumValid = out.checksumExpected == out.checksumReceived;
  return out;
}

int scoreDecodedFrame(const DecodedFrameResult& decoded, const RawByte* source,
                      size_t length) {
  if (!decoded.structurallyValid) {
    return -1;
  }

  int score = 0;
  if (decoded.strictModeBitsOk && !decoded.relaxedDecodeUsed) {
    score += 50;
  }
  if (decoded.checksumValid) {
    score += 40;
  }
  if (decoded.kind != MdbFrameKind::Invalid) {
    score += 20;
  }
  if (decoded.hasAddressCommand) {
    score += 10;
  }
  if (decoded.direction == MdbDirection::MasterToPeripheral) {
    score += 10;
  }
  if (decoded.kind == MdbFrameKind::Ack || decoded.kind == MdbFrameKind::Nak ||
      decoded.kind == MdbFrameKind::Ret) {
    score += 25;
  }
  if (decoded.singleByteCommand) {
    score += 5;
  }
  if (length == 1 && !source[0].highBit &&
      decoded.direction == MdbDirection::PeripheralToMaster &&
      (decoded.kind == MdbFrameKind::Ack || decoded.kind == MdbFrameKind::Nak ||
       decoded.kind == MdbFrameKind::Ret)) {
    score += 30;
  }
  return score;
}

DecodedFrameResult selectBestDecodedFrame(const RawByte* source, size_t length) {
  const DecodedFrameResult candidates[] = {
      decodeFrame(source, length, MdbDirection::MasterToPeripheral, true),
      decodeFrame(source, length, MdbDirection::PeripheralToMaster, true),
      decodeFrame(source, length, MdbDirection::MasterToPeripheral, false),
      decodeFrame(source, length, MdbDirection::PeripheralToMaster, false),
  };

  int bestScore = -1;
  DecodedFrameResult best;
  for (const DecodedFrameResult& candidate : candidates) {
    const int score = scoreDecodedFrame(candidate, source, length);
    if (score > bestScore) {
      bestScore = score;
      best = candidate;
    }
  }
  return best;
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

  if (length == 0) {
    return;
  }

  out.startedAtMs = source[0].tsMs;
  out.endedAtMs = source[length - 1].tsMs;
  out.startedAtUs = source[0].tsUs;
  out.endedAtUs = source[length - 1].tsUs;
  out.frameGapBeforeMs = source[0].gapBeforeMs;

  const DecodedFrameResult decoded = selectBestDecodedFrame(source, length);
  out.decodedDirection = decoded.direction;
  out.decodedKind = decoded.kind;
  out.checksumExpected = decoded.checksumExpected;
  out.checksumReceived = decoded.checksumReceived;
  out.strictModeBitsOk = decoded.strictModeBitsOk;
  out.relaxedDecodeUsed = decoded.relaxedDecodeUsed;
  out.singleByteCommand = decoded.singleByteCommand;

  if (decoded.hasAddressCommand) {
    out.hasCandidateAddress = true;
    out.candidateAddress = decoded.address5;
    out.candidateCommand = decoded.command3;
  } else {
    out.hasCandidateAddress = true;
    out.candidateAddress = out.normalized[0] >> 3U;
    out.candidateCommand = out.normalized[0] & 0x07U;
  }
  out.looksLikePoll = length <= 2 && out.candidateCommand == 0;
  out.looksLikeCommand = !out.looksLikePoll;
  out.parseOk = decoded.structurallyValid;
  out.checksumValid = decoded.checksumValid;

  if (!out.parseOk) {
    mdb::MasterBlock block;
    out.parseOk = mdb::parseMasterBlock(out.normalized, out.normalizedLength, block);
    out.checksumValid = out.parseOk && block.checksumValid;
  }

  out.maybePartial = !out.checksumValid && length <= 2;
  out.maybeMerged = length > 8;
  if (out.checksumValid && out.strictModeBitsOk && !out.relaxedDecodeUsed) {
    out.captureQuality = 100;
  } else if (out.checksumValid) {
    out.captureQuality = 80;
  } else if (out.parseOk) {
    out.captureQuality = 50;
  } else {
    out.captureQuality = 25;
  }
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

const char* directionToString(MdbDirection direction) {
  switch (direction) {
    case MdbDirection::MasterToPeripheral:
      return "master_to_peripheral";
    case MdbDirection::PeripheralToMaster:
      return "peripheral_to_master";
    case MdbDirection::Unknown:
    default:
      return "unknown";
  }
}

const char* frameKindToString(MdbFrameKind kind) {
  switch (kind) {
    case MdbFrameKind::DataBlock:
      return "data_block";
    case MdbFrameKind::Ack:
      return "ack";
    case MdbFrameKind::Nak:
      return "nak";
    case MdbFrameKind::Ret:
      return "ret";
    case MdbFrameKind::Invalid:
    default:
      return "invalid";
  }
}

}  // namespace machine
