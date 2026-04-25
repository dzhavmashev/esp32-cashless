#pragma once

#include <Arduino.h>

namespace machine {

// Максимальное число байтов в одном собранном кадре диагностики.
constexpr size_t kMaxFrameBytes = 64;

enum class MdbDirection : uint8_t {
  Unknown = 0,
  MasterToPeripheral = 1,
  PeripheralToMaster = 2,
};

enum class MdbFrameKind : uint8_t {
  Invalid = 0,
  DataBlock = 1,
  Ack = 2,
  Nak = 3,
  Ret = 4,
};

// Один байт линии с сохранением сырого значения и служебных признаков.
struct RawByte {
  uint8_t raw = 0;
  uint8_t value7 = 0;
  bool highBit = false;
  unsigned long tsMs = 0;
  unsigned long tsUs = 0;
  unsigned long gapBeforeMs = 0;
};

// Нормализованный кадр, собранный из последовательности RawByte.
struct Frame {
  RawByte bytes[kMaxFrameBytes] = {};
  size_t length = 0;
  unsigned long startedAtMs = 0;
  unsigned long endedAtMs = 0;
  unsigned long startedAtUs = 0;
  unsigned long endedAtUs = 0;
  unsigned long finalizedAtUs = 0;
  unsigned long frameGapBeforeMs = 0;
  unsigned long frameGapAfterMs = 0;
  uint8_t normalized[kMaxFrameBytes] = {};
  size_t normalizedLength = 0;
  bool hasHighBit = false;
  bool truncated = false;
  bool maybePartial = false;
  bool maybeMerged = false;
  bool looksLikePoll = false;
  bool looksLikeCommand = false;
  bool parseOk = false;
  bool checksumValid = false;
  bool hasCandidateAddress = false;
  uint8_t candidateAddress = 0;
  uint8_t candidateCommand = 0;
  MdbDirection decodedDirection = MdbDirection::Unknown;
  MdbFrameKind decodedKind = MdbFrameKind::Invalid;
  uint8_t checksumExpected = 0;
  uint8_t checksumReceived = 0;
  bool strictModeBitsOk = false;
  bool relaxedDecodeUsed = false;
  bool singleByteCommand = false; bool standardMdbValid = false; bool compatCandidate = false;
  uint8_t endReasonCode = 0;
  uint8_t captureQuality = 0;
  bool continuationAttempted = false;
  unsigned long continuationWaitStartedMs = 0;
  unsigned long continuationWaitMs = 0;
  size_t continuationAppendedBytes = 0;
  uint8_t continuationResultCode = 0;
  uint8_t continuationFailReasonCode = 0;
  bool rebootGapDetected = false;
  bool sessionBreakGapDetected = false;
};

// Строит диагностический кадр и вычисляет базовые признаки протокола.
void buildFrame(const RawByte* source, size_t length, Frame& out);
// Преобразует сырой кадр в HEX-строку.
String rawHex(const Frame& frame);
// Преобразует нормализованный кадр в HEX-строку.
String normalizedHex(const Frame& frame);
// Возвращает label направления, определенного high-level MDB decoder.
const char* directionToString(MdbDirection direction);
// Возвращает label типа кадра, определенного high-level MDB decoder.
const char* frameKindToString(MdbFrameKind kind);

}  // namespace machine
