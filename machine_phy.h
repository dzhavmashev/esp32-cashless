#pragma once

#include <Arduino.h>
#include <esp_err.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <freertos/task.h>

#include "machine_protocol.h"
#include "mdb_config.h"


// Низкоуровневый драйвер линии обмена с кофемашиной.
class MachinePhy {
 public:
  static constexpr size_t kRecentRxInterrupts = 10;
  static constexpr size_t kSoftwareDecoderPaths = 2;
  static constexpr size_t kSoftwareDecoderModes = 4;
  static constexpr size_t kCapturedSymbolHistory = 16;
  static constexpr size_t kRxEdgeRingSize = 256;
  static constexpr size_t kDecodedFrameQueueSize = 16;
  static constexpr size_t kDecoderSampleCount = 11;
  static constexpr size_t kDecoderTraceEdges = 24;
  using TxObserver = void (*)(void* context, uint32_t frameId, size_t byteIndex,
                              uint8_t value, uint8_t ninthBit,
                              unsigned long tsUs);
  using FrameObserver = void (*)(void* context, const machine::Frame& frame,
                                 unsigned long finalizedAtMs);
  using StatusObserver = void (*)(void* context, const char* eventName,
                                  unsigned long tsUs, UBaseType_t priority,
                                  BaseType_t coreId, uint32_t auxValue);
  struct CapturedSymbol {
    uint16_t data = 0;
    uint32_t timestampUs = 0;
  };
  struct SoftwareDecoderPathState {
    bool framing = false;
    uint8_t bitPos = 0;
    uint8_t lastValue = 0;
    bool ninthBit = false;
    uint8_t resetReason = 0;
    unsigned long lastActivityUs = 0;
  };
  enum class DecoderState : uint8_t {
    WaitingIdle = 0,
    WaitingStart = 1,
    Receiving = 2,
    ResyncWaitIdle = 3,
  };
  enum class DecoderBadReason : uint8_t {
    None = 0,
    RingOverflow = 1,
    PolarityMismatch = 2,
    StartBitInvalid = 3,
    StopBitInvalid = 4,
    TimingDrift = 5,
    NoIdleBeforeStart = 6,
    InsufficientEdgeContext = 7,
  };
  enum class DecoderTraceEdgeDecision : uint8_t {
    Unknown = 0,
    Accepted = 1,
    BeforeWindow = 2,
    AfterWindow = 3,
    Duplicate = 4,
    TooClose = 5,
    Overwritten = 6,
  };
  enum class DecoderTraceScanStopReason : uint8_t {
    Unknown = 0,
    LiveRingTail = 1,
    RingOverwritten = 2,
  };
  struct DecoderTraceEdge {
    uint32_t tsUs = 0;
    uint32_t ringIndex = 0;
    uint8_t level = 1;
    uint8_t decision = 0;
  };
  struct DecoderFrameTrace {
    bool valid = false;
    uint32_t traceGenerationId = 0;
    uint32_t candidateStartTsUs = 0;
    uint32_t frameWindowStartUs = 0;
    uint32_t frameWindowEndUs = 0;
    uint32_t traceUpdatedTsUs = 0;
    uint32_t candidateFinalizeTsUs = 0;
    uint32_t latestEdgeTsSeenWhenFinalized = 0;
    uint32_t firstRingIndex = 0;
    uint32_t lastRingIndex = 0;
    uint32_t ringWriteIndexAtCandidateCreate = 0;
    uint32_t ringWriteIndexAtFrameFinalize = 0;
    uint8_t initialLevelBeforeStart = 1;
    uint8_t sampledBits[kDecoderSampleCount] = {};
    uint32_t sampleTimestampsUs[kDecoderSampleCount] = {};
    uint8_t sampledStart = 1;
    uint8_t sampledDataByte = 0;
    bool sampledModeBit = false;
    uint8_t sampledStopBit = 1;
    uint16_t raw9 = 0;
    uint8_t badReason = 0;
    int32_t phaseErrorUs = 0;
    uint32_t idleDurationBeforeStartUs = 0;
    uint8_t edgeCountUsedForFrame = 0;
    uint8_t edgeCountStored = 0;
    uint16_t scannedEdgeCount = 0;
    uint16_t acceptedEdgeCount = 0;
    uint16_t rejectedEdgeCount = 0;
    uint16_t collectedEdgeCountTotal = 0;
    uint16_t collectedEdgeCountInWindow = 0;
    uint16_t rejectBeforeWindowCount = 0;
    uint16_t rejectAfterWindowCount = 0;
    uint16_t rejectDuplicateCount = 0;
    uint16_t rejectTooCloseCount = 0;
    uint16_t rejectOverwrittenCount = 0;
    bool finalizedWithLiveRingTail = false;
    uint8_t scanStopReason = 0;
    DecoderTraceEdge edges[kDecoderTraceEdges] = {};
  };
  struct DecoderFrame {
    uint8_t dataByte = 0;
    bool ninthBit = false;
    uint16_t raw9 = 0;
    bool stopOk = false;
    uint32_t timestampUs = 0;
    bool valid = false;
  };
  struct DecoderStats {
    uint32_t framingErrorCount = 0;
    uint32_t polarityMismatchCount = 0;
    uint32_t resyncCount = 0;
    uint32_t ringOverflowCount = 0;
    DecoderFrame lastGoodFrame = {};
    uint8_t lastBadReason = 0;
    DecoderFrameTrace currentCandidateTrace = {};
    DecoderFrameTrace lastBadTrace = {};
    DecoderFrameTrace debugFrameTrace = {};
  };

  // Инициализирует UART-параметры, пины и логику выделения кадров по тайм-ауту.
  void begin(unsigned long baudRate, int rxPin, int txPin, bool rxInvert,
             bool txInvert, unsigned long frameGapMs);
  // Включает физический интерфейс и настраивает UART.
  esp_err_t activate(bool forceReinit = false);
  // Запускает high-priority UART event task после полной инициализации системы.
  void startEventTask();
  // Логически отключает интерфейс.
  void deactivate();
  // Возвращает признак активности интерфейса.
  bool isActive() const;
  // Переключает инверсию RX-линии без полной переинициализации объекта.
  void setRxInvert(bool enabled);
  // Считывает байты из UART и группирует их в кадры.
  void update();
  // Возвращает следующий готовый кадр, если он есть.
  bool takeFrame(machine::Frame& out);
  // Возвращает число зарегистрированных GPIO-изменений на RX-пине.
  uint32_t rawGpioInterruptCount() const;
  // Копирует последние GPIO-фронты на RX-пине.
  size_t copyRecentRxInterrupts(unsigned long* tsUsOut, uint8_t* levelOut,
                                size_t maxCount) const;
  // Отправляет MDB peripheral->master блок.
  // Для cashless slave все байты ответа должны уходить как data bytes
  // с 9-м битом = 0. Если нужен специальный одиночный байт с явным
  // значением 9-го бита, используй writeSingleByte().
  unsigned long write(const uint8_t* data, size_t length);
  // Отправляет один MDB slave-байт с явным значением 9-го бита.
  unsigned long writeSingleByte(uint8_t value, bool ninthBit);
  // Возвращает расчётную длительность одного бита на MDB-TX.
  unsigned long txBitPeriodUs() const;
  // Возвращает расчётную длительность одного MDB-слова с start/data/parity/stop.
  unsigned long txCharacterUs() const;
  // Выполняет простой электрический pulse-тест TX-линии.
  void pulseTest(int txPin);
  // Держит TX-линию в активном состоянии достаточно долго для измерения.
  void holdActiveTest(int txPin, unsigned long activeMs);
  // Регистрирует observer для побайтного логирования TX.
  void setTxObserver(TxObserver observer, void* context);
  // Регистрирует observer для ultra-fast реакции на уже собранный кадр.
  void setFrameObserver(FrameObserver observer, void* context);
  // Регистрирует observer для статусов внутренней UART task.
  void setStatusObserver(StatusObserver observer, void* context);
  // Запускает минимальный GPIO sniffer без UART/backend-логики.
  void beginSniffer(int rxPin, int txPin);
  // Принудительно переводит RX в raw-sniffer режим без UART-драйвера.
  esp_err_t debugForceRawSniffer();
  // Возвращает текущий логический уровень на RX-пине.
  int currentRxLevel() const;
  // Возвращает активный режим software decoder.
  uint8_t activeSoftwareDecoderMode() const;
  // Возвращает последнюю дельту между RX-фронтами на software decoder path.
  unsigned long softwareDecoderLastDeltaUs() const;
  // Копирует текущее состояние software decoder paths.
  size_t copySoftwareDecoderPathStates(SoftwareDecoderPathState* out,
                                       size_t maxCount) const;
  // Копирует последние захваченные 9-битные символы.
  size_t copyCapturedSymbols(CapturedSymbol* out, size_t maxCount) const;
  // Low-level API strict MDB RX decoder: ISR stores only raw edges.
  void IRAM_ATTR mdb_rx_isr_edge(uint8_t rawLevel, unsigned long tsUs);
  // Обрабатывает накопленные фронты и собирает 9-битные кадры.
  void mdb_decoder_process();
  // Возвращает следующий декодированный кадр decoder-а.
  bool mdb_decoder_pop_frame(DecoderFrame& out);
  // Переключает полярность decoder-а без эвристик.
  void mdb_decoder_set_inversion(bool enabled);
  // Возвращает статистику decoder-а.
  DecoderStats mdb_decoder_get_stats() const;

 private:
  // Фоновая high-priority задача обработки UART событий.
  static void uartEventTaskThunk(void* context);
  // ISR для сырых GPIO-фронтов RX-пина.
  static void IRAM_ATTR rxGpioIsrThunk(void* context);
  // Основной цикл обработки UART событий.
  void uartEventTaskLoop();
  // Добавляет принятый байт в текущий кадр.
  void appendReceivedByte(uint8_t value, bool modeBit, unsigned long byteNowUs,
                          unsigned long byteNowMs);
  // Пытается финализировать кадр по аппаратному RX timeout.
  void handleRxIdle(unsigned long nowMs);
  // Применяет аппаратную инверсию UART-линий.
  void applyLineInversion() const;
  // Финализирует текущий буфер как готовый диагностический кадр.
  void finalizeFrame(unsigned long now, uint8_t endReasonCode,
                     uint8_t continuationResultCode,
                     uint8_t continuationFailReasonCode);
  // Восстанавливает parity-конфигурацию UART для MDB RX после TX.
  void restoreRxParityMode();
  // Отправляет один MDB slave-байт через UART с эмуляцией 9-го бита parity-битом.
  unsigned long writeSlaveByte(uint32_t frameId, size_t byteIndex, uint8_t value,
                               uint8_t ninthBit);
  // Проверяет, похож ли кадр на систематически обрезанный 12/7.
  bool isTargetPartialCandidate(const machine::Frame& frame) const;
  // Сбрасывает состояние continuation-window.
  void clearContinuationState();
  uint8_t normalizeRxLevel(uint8_t rawLevel) const;
  void resetDecoderRuntimeLocked(unsigned long nowUs, uint8_t normalizedLevel);
  void resetDecoderCandidateLocked();
  bool decoderIdleStableLocked(unsigned long tsUs) const;
  bool shouldReportPolarityMismatchLocked(unsigned long nowUs) const;
  void noteBadFrameLocked(DecoderBadReason reason, unsigned long tsUs);
  void beginCurrentCandidateTraceLocked(unsigned long startTsUs,
                                        uint8_t initialLevelBeforeStart,
                                        uint32_t startRingIndex);
  void syncCurrentCandidateTraceLocked(unsigned long updatedTsUs);
  void appendCurrentCandidateTraceEdgeLocked(
      unsigned long tsUs, uint8_t normalizedLevel, uint32_t ringIndex,
      DecoderTraceEdgeDecision decision);
  void rebuildTraceFromRingLocked(DecoderFrameTrace& trace) const;
  void captureBadFrameTraceLocked(DecoderBadReason reason, unsigned long tsUs,
                                  const uint8_t* sampledBits,
                                  const unsigned long* sampleTsUs,
                                  uint8_t dataByte, bool ninthBit,
                                  uint8_t stopBit, int32_t phaseErrorUs,
                                  size_t edgeCountUsedForFrame);
  void pushDecodedFrameLocked(const DecoderFrame& frame);
  bool popEdgeLocked(unsigned long& tsUs, uint8_t& rawLevel,
                     uint32_t& ringIndex);
  void processDecoderEdge(unsigned long tsUs, uint8_t rawLevel,
                          uint32_t ringIndex);
  void maybeFinalizeDecoder(unsigned long nowUs);
  size_t reconstructCandidateSamplesLocked(unsigned long* sampleTsUs,
                                           uint8_t* sampledBits) const;
  uint8_t sampleCandidateLevelAtUsLocked(unsigned long sampleTsUs) const;
  void updateIdleTrackingLocked(unsigned long tsUs, uint8_t normalizedLevel);

  volatile bool active_ = false;
  unsigned long baudRate_ = 9600;
  int rxPin_ = -1;
  int txPin_ = -1;
  bool rxInvert_ = false;
  bool txInvert_ = false;
  unsigned long frameGapMs_ = 20;
  unsigned long frameGapUs_ = 1500;
  machine::RawByte rxBuffer_[machine::kMaxFrameBytes] = {};
  size_t rxLength_ = 0;
  unsigned long lastRxByteAt_ = 0;
  unsigned long lastRxByteAtUs_ = 0;
  unsigned long lastFrameEndedAt_ = 0;
  unsigned long currentFrameGapBeforeMs_ = 0;
  bool frameOverflowed_ = false;
  bool continuationActive_ = false;
  unsigned long continuationStartedAt_ = 0;
  unsigned long continuationDeadlineAt_ = 0;
  size_t continuationInitialLength_ = 0;
  machine::Frame readyFrame_ = {};
  bool hasReadyFrame_ = false;
  TxObserver txObserver_ = nullptr;
  void* txObserverContext_ = nullptr;
  FrameObserver frameObserver_ = nullptr;
  void* frameObserverContext_ = nullptr;
  StatusObserver statusObserver_ = nullptr;
  void* statusObserverContext_ = nullptr;
  QueueHandle_t uartEventQueue_ = nullptr;
  TaskHandle_t uartEventTask_ = nullptr;
  uint32_t txFrameCounter_ = 0;
  uint32_t phyLoopCounter_ = 0;
  int lastInitError_ = 0;
  bool uartConfigured_ = false;
  bool hasActivatedOnce_ = false;
  int configuredRxPin_ = -1;
  int configuredTxPin_ = -1;
  bool configuredRxInvert_ = false;
  bool configuredTxInvert_ = false;
  volatile bool phyIsReady_ = false;
  volatile bool phySawRxByte_ = false;
  volatile bool phyConfigOkPending_ = false;
  unsigned long lastConfigOkAtMs_ = 0;
  volatile uint32_t rawGpioInterruptCount_ = 0;
  unsigned long lastRawEdgeDumpAtMs_ = 0;
  unsigned long recentRxInterruptTsUs_[kRecentRxInterrupts] = {};
  uint8_t recentRxInterruptLevel_[kRecentRxInterrupts] = {};
  size_t recentRxInterruptWriteIndex_ = 0;
  bool recentRxInterruptWrapped_ = false;
  volatile bool pendingRxAddressBit_ = false;
  volatile unsigned long swLastEdgeTsUs_ = 0;
  volatile bool swDecoderFraming_[kSoftwareDecoderPaths] = {};
  volatile uint8_t swDecoderBitPos_[kSoftwareDecoderPaths] = {};
  volatile uint8_t swDecoderValue_[kSoftwareDecoderPaths] = {};
  volatile bool swDecoderNinthBit_[kSoftwareDecoderPaths] = {};
  volatile unsigned long swDecoderLastActivityUs_[kSoftwareDecoderPaths] = {};
  volatile uint8_t swDebugBitPos_[kSoftwareDecoderPaths] = {};
  volatile uint8_t swDebugLastValue_[kSoftwareDecoderPaths] = {};
  volatile bool swDebugLastNinthBit_[kSoftwareDecoderPaths] = {};
  volatile uint8_t swDebugResetReason_[kSoftwareDecoderPaths] = {};
  volatile unsigned long swDebugLastDeltaUs_ = 0;
  uint8_t activeSoftwareDecoderMode_ = 0;
  uint32_t lastObservedRawGpioInterruptCount_ = 0;
  unsigned long lastBusChangeAtMs_ = 0;
  int reportedBusStuckLevel_ = -1;
  CapturedSymbol capturedSymbols_[kCapturedSymbolHistory] = {};
  size_t capturedSymbolWriteIndex_ = 0;
  bool capturedSymbolWrapped_ = false;
  struct DecoderEdgeSample {
    uint32_t tsUs = 0;
    uint32_t ringIndex = 0;
    uint8_t rawLevel = 1;
  };
  struct CandidateEdgeSample {
    uint32_t tsUs = 0;
    uint32_t ringIndex = 0;
    uint8_t normalizedLevel = 1;
  };
  DecoderEdgeSample decoderEdgeRing_[kRxEdgeRingSize] = {};
  volatile size_t decoderEdgeWriteIndex_ = 0;
  volatile size_t decoderEdgeReadIndex_ = 0;
  uint32_t decoderEdgeSequence_ = 0;
  DecoderFrame decodedFrameQueue_[kDecodedFrameQueueSize] = {};
  size_t decodedFrameWriteIndex_ = 0;
  size_t decodedFrameReadIndex_ = 0;
  CandidateEdgeSample candidateEdges_[24] = {};
  size_t candidateEdgeCount_ = 0;
  bool candidateTimingDrift_ = false;
  unsigned long candidateStartUs_ = 0;
  unsigned long candidateLastEdgeUs_ = 0;
  unsigned long candidateIdleBeforeStartUs_ = 0;
  uint8_t candidateInitialLevelBeforeStart_ = 1;
  int32_t candidatePhaseCorrectionUs_ = 0;
  int32_t candidateWorstPhaseErrorUs_ = 0;
  uint32_t traceGenerationCounter_ = 0;
  DecoderState decoderState_ = DecoderState::WaitingIdle;
  uint8_t normalizedRxLevel_ = 1;
  unsigned long normalizedLevelChangedUs_ = 0;
  unsigned long idleSinceUs_ = 0;
  unsigned long decoderLastActivityUs_ = 0;
  bool polarityMismatchLatched_ = false;
  unsigned long lineLowSinceUs_ = 0;
  DecoderStats decoderStats_ = {};
  uint8_t decoderDebugBitPos_ = 0;
  uint8_t decoderDebugLastValue_ = 0;
  bool decoderDebugLastNinthBit_ = false;
  uint8_t decoderDebugLastReason_ = 0;
  portMUX_TYPE stateLock_ = portMUX_INITIALIZER_UNLOCKED;
};
