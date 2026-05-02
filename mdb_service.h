#pragma once

#include <Arduino.h>

#include "cashless_session.h"
#include "machine_phy.h"

class ConnectionService;

struct GatewayCompatProfileConfig
{
  uint8_t profileId;
  const char *profileLabel;
  const char *currencyProfileLabel;
  uint8_t responseTime;
  uint8_t options;
  uint8_t currencyCountryCodeHi;
  uint8_t currencyCountryCodeLo;
  const char *currencyEncodingModeLabel;
  const char *semanticSuspectFieldLabel;
  bool currencyEncodingChangedFromProfile1;
};

// Основной сервис MDB-like интеграции с кофемашиной.
class MdbService
{
public:
  static constexpr size_t kStrategyCount = 5;
  static constexpr size_t kSniffHistorySize = 120;
  static constexpr size_t kStoredFrameBytes = 24;

  struct StrategyView
  {
    char name = 'A';
    uint8_t bytes[kStoredFrameBytes] = {};
    size_t length = 0;
    bool parseOk = false;
    bool checksumValid = false;
    bool plausible = false;
    bool hasCandidateAddress = false;
    uint8_t candidateAddress = 0;
    uint8_t candidateCommand = 0;
    uint8_t confidence = 0;
  };

  struct SniffFrameRecord
  {
    bool used = false;
    unsigned long startedAtMs = 0;
    unsigned long endedAtMs = 0;
    unsigned long frameGapBeforeMs = 0;
    unsigned long frameGapAfterMs = 0;
    size_t length = 0;
    uint8_t raw[kStoredFrameBytes] = {};
    uint8_t normalized[kStoredFrameBytes] = {};
    bool highBit[kStoredFrameBytes] = {};
    unsigned long tsMs[kStoredFrameBytes] = {};
    unsigned long gapBeforeMs[kStoredFrameBytes] = {};
    bool truncated = false;
    bool maybePartial = false;
    bool maybeMerged = false;
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
    uint8_t expectedAddress = 0xFF;
    bool expectedAddressConfigured = false;
    StrategyView strategies[kStrategyCount] = {};
  };

  enum class ExperimentMode : uint8_t
  {
    PassiveOnly = 0,
    SelectiveReplyProbe = 1,
    ProtocolShapedProbe = 2,
  };

  struct ExperimentConfig
  {
    bool enabled = false;
    uint8_t expectedAddress = 12;
    uint8_t triggerAddress = 12;
    uint8_t triggerCommand = 6;
    uint8_t replyByte = 0x00;
    uint8_t replyBytes[2] = {0x00, 0x00};
    uint8_t replyLength = 1;
    uint8_t protocolProbeCandidateId = 0;
    unsigned long replyDelayMs = 25;
    unsigned long cooldownMs = 45000;
    uint8_t maxRepliesPerSession = 1;
    uint8_t baselineSeriesCount = 0;
    unsigned long observationWindowMs = 45000;
    bool disableOnAnyError = true;
  };

  enum class ResponsePathState : uint8_t
  {
    Idle = 0,
    RxFrameReady = 1,
    ResponseDecision = 2,
    TxPending = 3,
    TxSending = 4,
    TxDone = 5,
    TxReleased = 6,
    TxTimeout = 7,
    TxAbort = 8,
  };

  enum class TxScope : uint8_t
  {
    None = 0,
    MdbResponse = 1,
    DebugCommand = 2,
    Experiment = 3,
  };

  struct BusFrameSnapshot
  {
    bool valid = false;
    uint16_t raw9 = 0;
    uint8_t dataByte = 0;
    bool ninthBit = false;
    unsigned long timestampUs = 0;
    String hex;
  };

  enum class DialogueDirection : uint8_t
  {
    RxFromMachine = 0,
    TxToMachine = 1,
  };

  enum class DialogueKind : uint8_t
  {
    Unknown = 0,
    Reset = 1,
    Setup = 2,
    ExpansionId = 3,
    Enable = 4,
    Disable = 5,
    Poll = 6,
    Ack = 7,
    Nak = 8,
    JustReset = 9,
    ReaderConfig = 10,
    ReaderStateChange = 11,
  };

  enum class MdbOperatingMode : uint8_t
  {
    Cashless = 0,
    CoinChanger = 1,
  };

  enum class ReaderState : uint8_t
  {
    Uninitialized = 0,
    ResetSeen = 1,
    SetupSeen = 2,
    SetupResponded = 3,
    ExpansionPending = 4,
    Disabled = 5,
    Enabled = 6,
    PollActive = 7,
    SessionIdle = 8,
    SessionActive = 9,
    Error = 10,
  };

  enum class WrapperFsmState : uint8_t
  {
    Idle = 0,
    SetupConfigSeen = 1,
    ReaderConfigSent = 2,
    WaitingForContinuation = 3,
    ContinuationTimeout = 4,
    ResetObserved = 5,
    RetryObserved = 6,
    ContinuedToStandardFlow = 7,
  };

  enum class WrapperAckSemanticsMode : uint8_t
  {
    StandardSetupAck = 0,
    WrapperContinuationOnly = 1,
  };

  static constexpr size_t kDialogueHistorySize = 60;
  static constexpr size_t kDialogueReasonSize = 40;

  struct DialogueEvent
  {
    bool used = false;
    uint32_t tsUs = 0;
    uint8_t direction = 0;
    uint8_t kind = 0;
    uint16_t raw9 = 0;
    uint8_t dataByte = 0;
    bool ninthBit = false;
    uint8_t stateBefore = 0;
    uint8_t stateAfter = 0;
    char decision[kDialogueReasonSize] = {};
  };

  // Создаёт сервис и привязывает его к транспортному слою backend.
  explicit MdbService(ConnectionService &connectionService);

  // Инициализирует PHY и стартовое состояние cashless-сессии.
  void begin();
  // Поздно запускает high-priority RX task после полной инициализации setup().
  void startRealtimeRx();
  // Выполняет приём/разбор кадров и прикладную MDB-like логику.
  void update();
  // Логически отключает сервис.
  void deactivate();

  // Сохраняет новый платёж как pending.
  void requestRecordPayment(unsigned long amountMinor,
                            const String &transactionId = "");
  // Ставит платёж в очередь для отправки через coin changer POLL compat (0xFE).
  void requestCoinPayment(unsigned long amountMinor,
                          const String &transactionId = "");
  // Переводит pending-платёж в активный кредит.
  void requestApproveCredit(unsigned long amountMinor,
                            const String &transactionId = "");
  // Сбрасывает текущую сессию и суммы.
  void requestClearSession();
  // Публикует диагностическую информацию о конфигурации сервиса.
  void requestProbe();
  // Публикует service-level debug/control event.
  bool emitControlEvent(const char *eventType, const String &details,
                        String *deliveryMode = nullptr);
  // Отправляет тестовый кадр в линию автомата.
  void requestProbeTx();
  // Выполняет электрический pulse-тест TX-линии.
  void requestPulseTest();
  // Удерживает TX активным для измерения на стороне автомата.
  void requestHoldTxLowTest();
  // Публикует снимок RX GPIO: текущий уровень, число фронтов и последние IRQ.
  void requestIrqSnapshot();
  // Публикует сводку software decoder: paths, mode scores и захваченные символы.
  void requestPhyDecoderStatus();
  // Выгружает последние сохранённые кадры диагностики.
  void requestSniffRecent();
  // Выгружает агрегированную сводку по последним кадрам.
  void requestSniffSummary();
  // Выгружает статистику парсера и классификации кадров.
  void requestSniffStats();
  // Очищает историю sniff-кадров и статистику.
  void requestSniffClear();
  // Задаёт ожидаемый адрес периферии для классификации кадров.
  void setExpectedAddress(int address);
  // Задаёт MDB cashless address, на который прошивка отвечает как reader.
  void setCashlessAddress(int address);
  // Переключает response profile только для gateway-compat setup wrapper.
  void setGatewayCompatResponseProfile(uint8_t profileId);
  // Задаёт экспериментальные значения полей READER CONFIG для подбора.
  void configureSetupResponseExperiment(bool enabled,
                                        uint8_t currencyCountryCodeHi,
                                        uint8_t currencyCountryCodeLo,
                                        uint8_t responseTime,
                                        uint8_t options,
                                        const String &label = "");
  // Включает автоматический перебор таблицы вариантов SETUP response.
  // На каждый RESET после отправки setup_response (если VMC не принял) индекс
  // автоматически сдвигается на следующий вариант. При получении ENABLE
  // вариант фиксируется и выводится событие setup_response_variant_accepted.
  void setSetupResponseVariantCycle(bool enabled, uint8_t startIndex = 0);
  // Переключает режим работы MDB: cashless (адрес 0x02) или coin_changer (адрес 0x01).
  // В режиме CoinChanger cashless-команды игнорируются и наоборот.
  void setMdbOperatingMode(MdbOperatingMode mode);
  MdbOperatingMode mdbOperatingMode() const { return mdbOperatingMode_; }
  // Включает или выключает инверсию RX.
  void setRxInvertEnabled(bool enabled);
  // Включает или выключает подробный монитор кадров.
  void setMonitorEnabled(bool enabled);
  // Переключает passive sniff без автоматических ответов.
  void setPassiveSniffEnabled(bool enabled);
  // Отправляет произвольную HEX-последовательность в линию.
  void sendRawHex(const String &hexPayload);
  // Включает или выключает controlled selective-reply experiment.
  void setExperimentEnabled(bool enabled);
  // Обновляет конфигурацию controlled experiment.
  void configureExperiment(uint8_t expectedAddress, uint8_t triggerAddress,
                           uint8_t triggerCommand, uint8_t replyByte,
                           unsigned long replyDelayMs,
                           unsigned long cooldownMs, uint8_t maxRepliesPerSession,
                           uint8_t baselineSeriesCount,
                           unsigned long observationWindowMs,
                           bool disableOnAnyError);
  // Вооружает одноразовый экспериментальный ответ на следующий anchor.
  void requestExperimentFireOnce();
  // Планирует BEGIN SESSION на следующий POLL.
  void initiateBeginSession(uint16_t amountMinor);
  // Жёстко сбрасывает runtime-состояние cashless/wrapper handshake.
  void resetCashlessRuntimeState(bool justResetPending);
  // Запускает CreditFlowStrategy до подтверждённого BEGIN SESSION ACK.
  void startCreditFlowStrategy(uint16_t amountMinor);
  // Принудительно останавливает CreditFlowStrategy.
  void stopCreditFlowStrategy();

  // Возвращает признак активности сервиса.
  bool isActive() const;
  // Возвращает признак, можно ли запускать OTA без риска сорвать vend.
  bool isSafeForOta() const;
  // Возвращает JSON-сводку состояния для backend.
  String buildDebugStateJson() const;

private:
  // Возвращает строковую метку состояния response path.
  static const char *responsePathStateLabel(ResponsePathState state);
  // Возвращает строковую метку области TX-логирования.
  static const char *txScopeLabel(TxScope scope);
  // Возвращает строковую метку направления dialogue trace.
  static const char *dialogueDirectionLabel(DialogueDirection direction);
  // Возвращает строковую метку high-level вида кадра/ответа.
  static const char *dialogueKindLabel(DialogueKind kind);
  // Возвращает строковую метку high-level reader FSM.
  static const char *readerStateLabel(ReaderState state);
  // Возвращает текущую фазу диалога для probe/debug.
  const char *currentDialoguePhaseLabel() const;
  static constexpr size_t kTxAuditKindBucketCount = 10;
  // Возвращает строковую метку audit-bucket для MDB-TX kind.
  static const char *txAuditKindBucketLabel(size_t index);
  // Возвращает индекс audit-bucket для MDB-TX kind.
  static size_t txAuditKindBucketFor(const char *txKind, DialogueKind kind);
  // Включает PHY при первом реальном использовании.
  void activate();
  // Классифицирует RX-кадр со стороны автомата.
  DialogueKind classifyRxFrameKind(const machine::Frame &frame) const;
  // Возвращает true, если входящий адрес/команда допустимы для нашего cashless dialogue.
  bool matchesCashlessDialogueAddress(uint8_t address, uint8_t command) const;
  // Возвращает true, если кадр адресован coin changer emulator.
  bool matchesCoinChangerDialogueAddress(uint8_t address, uint8_t command) const;
  // Классифицирует TX-кадр со стороны reader.
  DialogueKind classifyTxFrameKind(const uint8_t *frame, size_t length,
                                   const char *txKind) const;
  // Сохраняет один high-level dialogue event в ring buffer и публикует его.
  void appendDialogueEvent(DialogueDirection direction, DialogueKind kind,
                           uint16_t raw9, uint8_t dataByte, bool ninthBit,
                           ReaderState stateBefore, ReaderState stateAfter,
                           const char *decision, unsigned long tsUs);
  // Меняет reader dialogue state с явным логом причины.
  void transitionReaderState(ReaderState newState, const char *reason,
                             unsigned long tsUs);
  // Возвращает JSON истории последних событий диалога.
  String buildDialogueHistoryJson() const;
  // Возвращает JSON телеметрии high-level dialogue state.
  String buildDialogueTelemetryJson() const;
  // Возвращает фазу post-reset progression.
  const char *postResetPhaseLabel() const;
  // Возвращает ожидаемый следующий RX-kind для текущего protocol state.
  String expectedNextRxKindLabel() const;
  // Возвращает ожидаемый следующий TX-kind для текущего protocol state.
  String expectedNextTxKindLabel() const;
  // Возвращает краткий blocker дальнейшего protocol progression.
  String protocolProgressBlockerLabel() const;
  // Возвращает расширенную причину неизвестного RX-кадра.
  String buildUnknownRxReason(const machine::Frame &frame) const;
  // Возвращает tentative-kind для неизвестного RX-кадра.
  String buildUnknownTentativeKind(const machine::Frame &frame) const;
  // Возвращает вариант SETUP-пакета для диагностики progression.
  String buildSetupVariantLabel(const machine::Frame &frame) const;
  // Возвращает классификационную причину, почему SETUP отнесён к выбранному варианту.
  String buildSetupClassificationReason(const machine::Frame &frame) const;
  // Возвращает MDB subcommand/setup byte, если он присутствует.
  int16_t setupSubcommandValue(const machine::Frame &frame) const;
  // Возвращает активный глобально-сконфигурированный profile для gateway compat setup.
  const GatewayCompatProfileConfig &gatewayCompatProfileConfig() const;
  // Возвращает label выбранного response-profile для gateway compat setup.
  const char *gatewayCompatResponseProfileIdLabel() const;
  // Возвращает label выбранного Currency/Country Code profile для gateway compat setup.
  const char *gatewayCurrencyCountryCodeProfileIdLabel() const;
  // Возвращает response time для текущего gateway compat profile.
  uint8_t gatewayCompatResponseTime() const;
  // Возвращает options byte для текущего gateway compat profile.
  uint8_t gatewayCompatResponseOptions() const;
  // Возвращает старший байт packed BCD поля Currency/Country Code для gateway profile.
  uint8_t gatewayCompatCurrencyCountryCodeHi() const;
  // Возвращает младший байт packed BCD поля Currency/Country Code для gateway profile.
  uint8_t gatewayCompatCurrencyCountryCodeLo() const;
  // Возвращает режим кодирования поля Currency/Country Code.
  const char *gatewayCurrencyCountryCodeEncodingModeLabel() const;
  // Возвращает HEX-строку packed BCD поля Currency/Country Code для текущего gateway profile.
  String gatewayCurrencyCountryCodeBytesHex() const;
  // Возвращает true, если кодирование поля Currency/Country Code отличается от profile 1.
  bool gatewayCurrencyCountryCodeChangedFromProfile1() const;
  // Возвращает наиболее подозрительное поле текущего gateway compat profile.
  const char *gatewayCompatSemanticSuspectFieldLabel() const;
  // Возвращает true, если повтор setup похож на долгий wrapper watchdog/retry cycle.
  bool gatewayWrapperRetryAfterLongSilence() const;
  // Возвращает ожидаемое wrapper-specific следующее действие после gateway setup.
  String gatewayWrapperExpectedNextActionLabel() const;
  // Возвращает гипотезу о недостающем wrapper-specific шаге.
  String gatewayWrapperMissingStepHypothesisLabel() const;
  // Возвращает агрегированное состояние принятия gateway-wrapper setup.
  String gatewayWrapperAcceptanceStateLabel() const;
  // Возвращает текущую фазу wrapper-handshake для gateway-style setup.
  String gatewayWrapperPhaseLabel() const;
  // Возвращает строковую метку dedicated wrapper FSM.
  static const char *wrapperFsmStateLabel(WrapperFsmState state);
  // Возвращает строковую метку режима ACK-semantics для wrapper setup.
  static const char *wrapperAckSemanticsModeLabel(
      WrapperAckSemanticsMode mode);
  // Возвращает ожидаемый wrapper-specific следующий RX-kind до входа в standard flow.
  String wrapperExpectedNextRxKindLabel() const;
  // Возвращает ожидаемое wrapper-specific следующее действие.
  String wrapperExpectedNextActionLabel() const;
  // Возвращает true, если wrapper follow-up так и не был получен вовремя.
  bool gatewayWrapperFollowupMissing() const;
  // Возвращает true, если observed long retry cycle уже указывает на wrapper watchdog.
  bool gatewayWrapperLongRetryObserved() const;
  // Возвращает true, если после длинной тишины wrapper дошёл до RESET.
  bool gatewayWrapperResetAfterSilence() const;
  // Возвращает краткий blocker pre-reset setup progression.
  String setupProgressionBlockerLabel() const;
  // Возвращает оценку, влияет ли foreign traffic на текущий progression blocker.
  String foreignTrafficCausalLabel() const;
  // Фиксирует наблюдение setup-варианта и repeated-setup диагностику.
  void noteSetupObserved(const machine::Frame &frame, unsigned long tsUs,
                         const char *handlerReason);
  // Вооружает диагностику первого meaningful follow-up после gateway compat setup response.
  void armGatewayCompatFollowupTracking(unsigned long txStartUs);
  // Фиксирует первый meaningful RX после gateway compat setup response.
  void noteGatewayCompatFollowup(const machine::Frame &frame, DialogueKind kind);
  // Фиксирует отсутствие meaningful follow-up после gateway compat setup response.
  void noteGatewayCompatFollowupTimeout(unsigned long nowUs);
  // Переводит wrapper continuation FSM в новое состояние и фиксирует причину.
  void setWrapperFsmState(WrapperFsmState newState, const char *reason,
                          unsigned long tsUs);
  // Публикует текущее ожидание по protocol progression.
  void emitProtocolProgressExpectation(const char *reason, unsigned long tsUs);
  // Публикует текущее ожидание post-reset progression.
  void emitPostResetProgressionExpectation(const char *reason,
                                           unsigned long tsUs);
  // Сохраняет краткую причину отсутствия ответа.
  void noteNoResponse(const char *reason, unsigned long tsUs,
                      DialogueKind kind);
  // Копирует краткую строку причины в фиксированный буфер.
  static void copyReasonText(char *target, size_t capacity,
                             const char *source);
  // Публикует текущий probe snapshot, когда response path свободен.
  void emitProbeEvent(const char *snapshotMode = "direct",
                      const char *trigger = "mdb_probe");
  // Строит компактный probe snapshot для безопасной доставки при большом full probe.
  String buildCompactProbeJson(const char *snapshotMode, const char *trigger,
                               size_t fullProbeLength,
                               const String &fullProbeHash,
                               const char *compactReason) const;
  // Публикует одноразовый маркер готовности debug/control transport.
  void emitDebugTransportReadyIfNeeded(unsigned long nowMs);
  // Если probe был отложен во время MDB-ответа, публикует его после возврата в idle.
  void flushPendingProbeIfIdle();
  // Обновляет внутренний snapshot последнего принятого RX-кадра без тяжёлого логирования.
  DialogueKind prepareAcceptedRxFrame(const machine::Frame &frame);
  // Публикует RX trace уже после обработки кадра, чтобы не задерживать MDB-ответ.
  void emitAcceptedRxFrameTrace(const machine::Frame &frame, DialogueKind kind);
  // Сохраняет принятый RX-кадр для телеметрии response path.
  void recordAcceptedRxFrame(const machine::Frame &frame);
  // Прогоняет уже собранный валидный кадр через тот же high-level pipeline,
  // что и обычный RX путь: accepted trace, fast-path, processFrame, counters.
  void dispatchAcceptedFrame(const machine::Frame &frame, unsigned long now,
                             bool clearSplitPrefix = false);
  // Публикует решение response layer: отвечаем или намеренно молчим.
  void recordResponseDecision(const char *reason, bool willRespond,
                              unsigned long tsUs);
  // Фиксирует ожидаемый MDB-TX для текущего RX kind/state.
  void noteExpectedTxKind(DialogueKind rxKind, ReaderState stateBefore,
                          const char *expectedTxKind, unsigned long tsUs,
                          bool required, const char *reason,
                          bool emitAuditEvent = true);
  // Фиксирует фактически начатую MDB-TX отправку и сверяет с ожиданием.
  void noteActualTxKind(const char *actualTxKind, DialogueKind kind,
                        ReaderState stateBefore, unsigned long tsUs);
  // Фиксирует завершение MDB-TX по kind.
  void noteTxCompleted(const char *txKind, DialogueKind kind);
  // Фиксирует abort MDB-TX по kind.
  void noteTxAbortForKind(const char *txKind, DialogueKind kind,
                          const char *reason, unsigned long tsUs);
  // Фиксирует timeout MDB-TX по kind.
  void noteTxTimeoutForKind(const char *txKind, DialogueKind kind,
                            const char *reason, unsigned long tsUs);
  // Сбрасывает текущее ожидание expected TX audit.
  void clearExpectedTxAudit();
  // Переводит response path в новое состояние и логирует переход.
  void setResponsePathState(ResponsePathState state, unsigned long tsUs,
                            const char *reason);
  // Собирает отладочный снимок MDB response/TX path.
  String buildResponseTelemetryJson() const;
  // Собирает JSON-объект counters по audit-buckets TX kinds.
  String buildTxAuditCountJson(const uint8_t *counters) const;
  // Отправляет MDB-ответ с полным response/TX trace.
  unsigned long transmitResponseFrame(const char *decisionReason,
                                      const char *txKind,
                                      const uint8_t *frame, size_t length,
                                      unsigned long rxEndedUs = 0);
  // Отправляет debug/experiment кадр с отдельной областью TX-логов.
  unsigned long transmitDebugFrame(TxScope scope, const char *txKind,
                                   const uint8_t *frame, size_t length);
  // Публикует один побайтный TX trace с учётом текущего контекста передачи.
  void emitObservedTxByte(TxScope scope, uint32_t frameId, size_t byteIndex,
                          uint8_t value, uint8_t ninthBit,
                          unsigned long tsUs);
  // Отправляет одно диагностическое MDB-событие в backend.
  bool emitEvent(const char *eventType, const String &details,
                 String *deliveryMode = nullptr,
                 String *failureReason = nullptr);
  // Логирует все RX-байты внутри принятого кадра отдельными событиями.
  void emitObservedRxBytes(const machine::Frame &frame);
  // Публикует изменение состояния cashless-сессии.
  void emitStateChanged();
  // Сохраняет кадр в кольцевой буфер истории.
  void storeSniffFrame(const machine::Frame &frame);
  // Считает стратегии нормализации для одного кадра.
  void populateStrategyViews(const machine::Frame &frame, SniffFrameRecord &record) const;
  // Возвращает JSON с последними кадрами диагностики.
  String buildSniffRecentJson() const;
  // Возвращает JSON со сводной диагностикой кадров.
  String buildSniffSummaryJson() const;
  // Возвращает JSON со статистикой парсера и классификации.
  String buildSniffStatsJson() const;
  // Возвращает JSON с одним кратким кадром для recent-выгрузки.
  String buildSniffRecentFrameJson(const SniffFrameRecord &record, size_t index) const;
  // Возвращает JSON с meta-данными recent-выгрузки.
  String buildSniffRecentMetaJson(size_t returnedFrames) const;
  // Возвращает JSON с meta-данными summary-выгрузки.
  String buildSniffSummaryMetaJson() const;
  // Возвращает JSON с одним summary-family элементом.
  String buildSniffSummaryFamilyJson(uint8_t address, uint8_t command, uint16_t seen,
                                     uint8_t bestStrategyIndex,
                                     uint16_t bestChecksumPass,
                                     uint16_t bestPlausible) const;
  // Обрабатывает один уже собранный кадр линии.
  void processFrame(const machine::Frame &frame, unsigned long now,
                    bool cashlessFastReplyHandled = false);
  // Обрабатывает команды, адресованные coin changer emulator.
  bool handleCoinChangerCommand(const machine::Frame &frame, unsigned long now,
                                bool fastPath,
                                bool coinFamily08AddressBypass = false);
  // Ранний dispatch по raw MDB address family до фильтрации текущего режима.
  bool handleRawMdbAddressFamily(const machine::Frame &frame, unsigned long now,
                                 bool fastPath, bool emitTelemetry);
  // Логирует первый raw MDB byte/family после решения/TX, чтобы не тормозить hot path.
  void emitRawMdbFamilySeen(const machine::Frame &frame, bool handled);
  // Логирует одиночный compat-tail byte, на который намеренно не отвечаем.
  void emitCompatTailIgnored(const machine::Frame &frame, const char *reason);
  // Логирует отключённый FE compat poll без TX.
  void emitFeCompatIgnoredPreHandshake(const machine::Frame &frame,
                                       const char *reason);
  // Обрабатывает coin-like family 0x08..0x0F.
  bool handleCoinLikeFamily08Command(uint8_t command,
                                     const machine::Frame &frame,
                                     unsigned long now, bool fastPath);
  // Обрабатывает bill-validator family 0x30..0x37.
  bool handleBillValidatorFamily30Command(uint8_t command,
                                          const machine::Frame &frame,
                                          unsigned long now, bool fastPath);
  // Разбирает cashless-команды, адресованные нашему устройству.
  void handleCashlessCommand(uint8_t address, uint8_t command,
                             const machine::Frame &frame, unsigned long now);
  // Обрабатывает активные Level 1 команды cashless reader.
  bool handleLevel1CashlessFrame(const machine::Frame &frame, unsigned long now);
  // Наблюдает за post-BEGIN-SESSION кадрами и ACK VMC.
  void observeCreditFlowFrame(const machine::Frame &frame, unsigned long now);
  // Пытается отправить критичный hijack-ответ до любых логов и тяжёлой обработки.
  bool tryFastCreditFlowReply(const machine::Frame &frame, unsigned long now);
  // Завершает CreditFlowStrategy и публикует итоговый результат.
  void finalizeCreditFlowStrategy(unsigned long now, const char *status,
                                  const char *reason);
  // Начинает буферизацию PHY TX telemetry, чтобы логировать её уже после отправки.
  void beginDeferredTxTrace();
  // Сбрасывает отложенный TX trace в mdb/events постфактум.
  void flushDeferredTxTrace();
  // Публикует отложенные fast-path события после выхода из критичного TX пути.
  void flushDeferredFastPathEvents();
  // Реакция на кадр сразу при его финализации в PHY.
  void handleFastFrameObserved(const machine::Frame &frame,
                               unsigned long finalizedAtMs);
  // Быстрый ACK для текущего startup RESET, который ESP временно видит как FE/FC.
  bool sendCompatMisdecodedResetAck(unsigned long rxEndedUs, unsigned long now,
                                    const char *responseReason);
  // Сбрасывает runtime-состояние coin changer protocol.
  void resetCoinChangerProtocolState(bool justResetPending);
  // Очищает очередь активного coin-платежа.
  void clearCoinChangerPendingPayment();
  // Возвращает true, если есть queued coin payment или локально отправленный,
  // но ещё не подтверждённый VMC кредит.
  bool hasCoinChangerUnresolvedPayment() const;
  // Возвращает локально отправленный кредит обратно в pending-очередь.
  void requeueCoinChangerAwaitingAcceptance(const char *reason);
  // Возвращает true, если кадр попал в compat-tail окно после coin poll.
  bool shouldIgnoreCoinCompatTail(const machine::Frame &frame,
                                  unsigned long *deltaUs = nullptr) const;
  // Возвращает true, если одиночный address-byte стоит подождать как префикс split-frame.
  bool shouldTrackCashlessSplitPrefix(const machine::Frame &frame) const;
  // Пытается склеить отложенный cashless address-byte с payload-кадром.
  bool tryBuildCashlessSplitFrame(const machine::Frame &payloadFrame,
                                  machine::Frame &combined) const;
  // Сбрасывает отложенный префикс split-frame.
  void clearPendingCashlessSplitPrefix();
  // Добавляет сырое UART-наблюдение в fallback-окно cashless-команд.
  void appendObservedRawStatusByte(uint8_t value, bool ninthBit, unsigned long tsUs);
  // Пытается собрать из fallback-окна валидный cashless master-frame.
  bool tryHandleObservedRawStatusWindow(unsigned long tsUs);
  // Пытается разрезать слепившийся master-frame по повторному mode-bit.
  bool tryHandleMergedCashlessFrame(const machine::Frame &frame, unsigned long now);
  // Очищает fallback-окно сырых UART-байтов.
  void clearObservedRawStatusWindow();
  // Публикует накопительную сводку по одному режиму decoder matrix.
  void emitDecoderModeScore(uint8_t mode, const char *reason);
  // Проверяет, совпадают ли первые байты нормализованного кадра с командой.
  bool frameStartsWith(const machine::Frame &frame, uint8_t firstByte,
                       int secondByte = -1, int thirdByte = -1) const;
  // Собирает первый байт MDB master-команды для выбранного cashless address.
  uint8_t cashlessCommandByte(uint8_t command) const;
  // Обрабатывает селективный experiment trigger на основании лучшей стратегии.
  void handleExperimentTrigger(const StrategyView &view, const machine::Frame &frame,
                               unsigned long now);
  // Выполняет отложенную экспериментальную передачу.
  void processExperiment(unsigned long now);
  // Собирает кадры в observation window после экспериментального ответа.
  void observeExperimentFrame(const StrategyView &view, unsigned long now);
  // Завершает post-reply observation и публикует результат сравнения.
  void finalizeExperimentObservation(unsigned long now, const char *reason);
  // Возвращает строковую метку текущего experiment candidate.
  String buildExperimentCandidateLabel() const;
  // Аварийно выключает experiment mode и возвращается в passive-only.
  void disableExperimentDueToError(const char *reason, unsigned long now);
  // Возвращает краткий путь последних семей для pre/post контекста.
  String buildRecentFamilyPath(size_t limit) const;
  // Возвращает имя режима controlled experiment.
  const char *experimentModeToString(ExperimentMode mode) const;
  // Возвращает bytes для жёстко разрешённого protocol-shaped candidate.
  bool resolveProtocolProbeCandidate(uint8_t candidateId, uint8_t *outBytes,
                                     uint8_t &outLength) const;
  // Отправляет Reader Setup (11 00) response для Cashless Level 1 и
  // возвращает timestamp первого переданного байта.
  unsigned long sendReaderSetupResponse(unsigned long rxEndedUs,
                                        const char *responseReason =
                                            "setup_response");
  // Отправляет Reader Expansion ID (11 01) response.
  unsigned long sendReaderExpansionIdResponse(
      const char *responseReason = "expansion_response");
  // Отправляет SETUP response coin changer emulator.
  unsigned long sendCoinChangerSetupResponse(
      const char *responseReason = "coin_setup_response");
  // Отправляет TUBE STATUS response coin changer emulator.
  unsigned long sendCoinChangerTubeStatusResponse(
      const char *responseReason = "coin_tube_status");
  // Отправляет POLL response coin changer emulator.
  unsigned long sendCoinChangerPollResponse(
      const char *responseReason = "coin_poll_response",
      bool compatMode = false);
  // Отправляет EXPANSION/ID response coin changer emulator.
  unsigned long sendCoinChangerExpansionIdResponse(
      const char *responseReason = "coin_expansion_response");
  // Отправляет EXPANSION diagnostic status response coin changer emulator.
  unsigned long sendCoinChangerDiagnosticStatusResponse(
      const char *responseReason = "coin_diag_status");
  // Отправляет SETUP response для MDB bill-validator family 0x30.
  unsigned long sendBillValidatorSetupResponse(
      const char *responseReason = "bill_validator_setup_response");
  // Отправляет POLL response для MDB bill-validator family 0x30.
  unsigned long sendBillValidatorPollResponse(
      const char *responseReason = "bill_validator_poll_response");
  // Отправляет STACKER STATUS response для MDB bill-validator family 0x30.
  unsigned long sendBillValidatorStackerStatusResponse(
      const char *responseReason = "bill_validator_stacker_status");
  // Отправляет EXPANSION ID response для MDB bill-validator family 0x30.
  unsigned long sendBillValidatorExpansionIdResponse(
      const char *responseReason = "bill_validator_expansion_response");
  // Выбирает самый крупный разрешённый coin type для остатка платежа.
  bool selectCoinChangerCoinType(unsigned long remainingScaled,
                                 uint8_t &coinType,
                                 uint8_t &coinValue) const;
  // Выбирает и отправляет немедленный ответ на POLL без лишних логов до TX.
  unsigned long sendCashlessPollReply(unsigned long now, unsigned long rxEndedUs,
                                      uint8_t &replyKind, bool &readerEnabled);
  // Отправляет байт статуса JUST RESET без публикации событий.
  unsigned long sendJustResetRaw(
      const char *responseReason = "just_reset_status");
  // Отправляет статус JUST RESET (0x00) для принудительного re-setup со стороны VMC.
  void sendJustResetStatus();
  // Отправляет ACK без публикации событий и возвращает timestamp первого TX-байта.
  unsigned long sendAckRaw(const char *responseReason = "ack");
  // Отправляет ACK.
  void sendAck();
  // Включает ожидание ACK после отправки SETUP RESPONSE.
  void markSetupResponseSent(unsigned long firstTxUs, bool awaitAck);
  // Завершает ожидание ACK после SETUP RESPONSE c логированием результата.
  void markSetupResponseAckReceived(unsigned long ackTsUs);
  void markSetupResponseAckMissing(const char *reason,
                                   const String &extraJson = "");
  // Публикует сводный audit при признаках отклонения SETUP RESPONSE со стороны VMC.
  void emitSetupResponseRejectionAudit(const char *basis, unsigned long tsUs,
                                       const machine::Frame *followupFrame = nullptr,
                                       const char *followupKind = nullptr,
                                       const String &extraJson = "");
  // Отправляет NAK.
  void sendNak();
  // Отправляет RET.
  void sendRet();
  // Отправляет подтверждение vend с суммой.
  unsigned long sendVendApproved(unsigned long amountMinor,
                                 const char *responseReason = "vend_approved");
  // Отправляет отказ vend с суммой.
  void sendVendDenied(unsigned long amountMinor);
  // Отправляет минимальный VEND DENIED без суммы для сброса застрявшего VEND.
  void sendVendDeniedMinimal();
  // Отправляет минимальный REVALUE LIMIT = 0.
  void sendRevalueLimitZero();
  // Отправляет END SESSION (0x04) для принудительного завершения застрявшей сессии.
  void sendEndSession();
  // Отправляет завершение сессии.
  void sendSessionComplete();
  // Отправляет BEGIN SESSION с суммой.
  unsigned long sendBeginSession(uint16_t amountMinor,
                                 const char *responseReason = "begin_session");
  // Фиксирует отправку generic BEGIN SESSION и включает ожидание ACK.
  void markBeginSessionSent(unsigned long firstTxUs, uint16_t amountMinor);
  // Фиксирует получение ACK на generic BEGIN SESSION.
  void markBeginSessionAckReceived(unsigned long ackTsUs);
  // Фиксирует отсутствие ACK на generic BEGIN SESSION.
  void markBeginSessionAckMissing(const char *reason, unsigned long nowMs);
  // Переcобирает заранее подготовленные ответы для критичного fast-path.
  void rebuildPrecomputedFrames();
  // Разбирает HEX-строку в массив байтов.
  bool parseHexPayload(const String &hexPayload, uint8_t *buffer, size_t &length);
  // Применяет отложенные переходы состояния и сетевые зависимости.
  void applyDesiredState(unsigned long now);
  // Преобразует состояние FSM в строку.
  const char *stateToString(CashlessSession::State state) const;
  // Статический adapter для PHY TX observer.
  static void handlePhyTxObservedThunk(void *context, uint32_t frameId,
                                       size_t byteIndex, uint8_t value,
                                       uint8_t ninthBit,
                                       unsigned long tsUs);
  // Статический adapter для PHY status observer.
  static void handlePhyStatusObservedThunk(void *context, const char *eventName,
                                           unsigned long tsUs,
                                           UBaseType_t priority,
                                           BaseType_t coreId,
                                           uint32_t auxValue);
  // Статический adapter для PHY frame observer.
  static void handleFastFrameObservedThunk(void *context,
                                           const machine::Frame &frame,
                                           unsigned long finalizedAtMs);
  // Получает побайтный callback от PHY для TX loopback-логирования.
  void handlePhyTxObserved(uint32_t frameId, size_t byteIndex, uint8_t value,
                           uint8_t ninthBit, unsigned long tsUs);
  // Получает статус внутренней UART task.
  void handlePhyStatusObserved(const char *eventName, unsigned long tsUs,
                               UBaseType_t priority, BaseType_t coreId,
                               uint32_t auxValue);

  ConnectionService &connectionService_;
  MachinePhy phy_;
  CashlessSession session_;
  volatile bool active_ = true;
  bool monitorEnabled_ = false;
  bool passiveSniffEnabled_ = false;
  bool rxInvertEnabled_ = false;
  ExperimentMode experimentMode_ = ExperimentMode::PassiveOnly;
  ExperimentConfig experimentConfig_ = {};
  bool experimentArmed_ = false;
  bool experimentReplyPending_ = false;
  bool experimentObservationActive_ = false;
  bool experimentFireOnceRequested_ = false;
  unsigned long experimentLastReplyAt_ = 0;
  unsigned long experimentTriggerAt_ = 0;
  unsigned long experimentScheduledReplyAt_ = 0;
  unsigned long experimentObservationEndsAt_ = 0;
  unsigned long experimentLastDisableAt_ = 0;
  uint32_t experimentRunCounter_ = 0;
  uint32_t experimentActiveRunId_ = 0;
  uint8_t experimentRepliesThisSession_ = 0;
  uint8_t experimentPostReplyFrameCount_ = 0;
  uint8_t experimentUnexpectedFamilyCount_ = 0;
  uint8_t experimentAnchorSeenAfterReply_ = 0;
  bool experimentSequenceObservedEmitted_ = false;
  bool experimentMachineChangeEmitted_ = false;
  bool experimentObservationClosedEmitted_ = false;
  uint8_t experimentObservationTriggerAddress_ = 0;
  uint8_t experimentObservationTriggerCommand_ = 0;
  String experimentLastTriggerFamily_;
  String experimentLastPreContext_;
  String experimentLastReplyHex_;
  String experimentObservationCandidateLabel_;
  String experimentObservedPostFamilies_;
  String experimentObservationReason_;
  uint8_t baselineSeriesIndex_ = 0;
  bool baselineSeriesActive_ = false;
  bool baselineSeriesCompleted_ = false;
  bool clearSessionPending_ = false;
  bool probeRequestPending_ = false;
  bool stateDirty_ = true;
  unsigned long lastApprovedAt_ = 0;
  unsigned long lastRxFrameAt_ = 0;
  unsigned long lastProbeTxAt_ = 0;
  bool debugTransportReadyEmitted_ = false;
  unsigned long rxFrameCount_ = 0;
  unsigned long rxFramesAfterProbeTx_ = 0;
  int expectedAddress_ = -1;
  uint8_t cashlessAddress_ = 2;
  unsigned long totalFramesSeen_ = 0;
  unsigned long checksumPassCount_ = 0;
  unsigned long checksumFailCount_ = 0;
  unsigned long expectedMatchCount_ = 0;
  unsigned long foreignFrameCount_ = 0;
  unsigned long ambiguousFrameCount_ = 0;
  unsigned long invalidFrameCount_ = 0;
  bool coinChangerJustResetPending_ = true;
  uint16_t coinChangerEnabledMask_ = 0;
  uint16_t coinChangerManualDispenseMask_ = 0xFFFFU;
  uint32_t coinChangerFeatureEnableMask_ = 0;
  unsigned long lastCoinCompatPollObservedUs_ = 0;
  unsigned long lastCoinCompatPollReplyTxUs_ = 0;
  unsigned long coinCompatTailIgnoreUntilUs_ = 0;
  unsigned long coinChangerPendingAmountMinor_ = 0;
  unsigned long coinChangerPendingScaled_ = 0;
  unsigned long coinChangerAwaitingVmcAmountMinor_ = 0;
  unsigned long coinChangerAwaitingVmcScaled_ = 0;
  unsigned long coinChangerLastCreditReplyTxUs_ = 0;
  // Legacy 5x-repeat state: bytes to resend, remaining repeat count, per-type counter.
  uint8_t coinChangerCreditRepeatPayload_[2] = {};
  uint8_t coinChangerCreditRepeatRemaining_ = 0;
  uint8_t coinChangerPerTypeSendCount_[16] = {};
  unsigned long coinChangerQueuedAtMs_ = 0;
  String coinChangerPendingTransactionId_;
  String coinChangerAwaitingVmcTransactionId_;
  bool billValidatorJustResetPending_ = true;
  uint16_t billValidatorBillEnableMask_ = 0;
  uint16_t billValidatorEscrowEnableMask_ = 0;
  bool isReaderEnabled_ = false;
  bool cashlessJustResetPending_ = true;
  bool cashlessSetupSeen_ = false;
  bool cashlessSetupMaxMinSeen_ = false;
  bool cashlessSetupResponsePending_ = false;
  bool cashlessSetupResponseAwaitingAck_ = false;
  bool cashlessExpansionSeen_ = false;
  unsigned long cashlessSetupResponseSentAtMs_ = 0;
  unsigned long cashlessSetupResponseSentUs_ = 0;
  unsigned long lastSetupResponseReplyDelayUs_ = 0;
  unsigned long lastSetupResponseTxUs_ = 0;
  unsigned long lastSetupRxTsUs_ = 0;
  unsigned long lastSetupRxEndUs_ = 0;
  unsigned long lastSetupDecisionTsUs_ = 0;
  unsigned long lastSetupFrameBuiltTsUs_ = 0;
  unsigned long lastSetupQueueEnqueueTsUs_ = 0;
  unsigned long lastSetupTxDoneUs_ = 0;
  unsigned long lastSetupReleaseUs_ = 0;
  unsigned long lastSetupDecisionToTxUs_ = 0;
  unsigned long lastSetupBuildToTxUs_ = 0;
  unsigned long lastSetupTotalResponseUs_ = 0;
  unsigned long lastSetupToRepeatUs_ = 0;
  uint8_t lastSetupResponseChecksum_ = 0;
  uint8_t lastSetupResponseOptions_ = 0;
  uint8_t lastSetupResponseResponseTime_ = 0;
  uint8_t lastSetupResponseCountryCodeHi_ = 0;
  uint8_t lastSetupResponseCountryCodeLo_ = 0;
  bool setupFastPathEnabled_ = true;
  bool lastSetupFastPathUsed_ = false;
  bool currentSetupResponseGatewayCompat_ = false;
  // Default to the repo-like gateway profile first. Keep the runtime pinned
  // to profile 1 for now: profile 2 (telephone-country-code variant 09 96)
  // is rejected by the observed VMC with a RESET after READER CONFIG.
  uint8_t gatewayCompatResponseProfileId_ = 1;
  unsigned long gatewayCompatLastSetupResponseUs_ = 0;
  unsigned long gatewayCompatFollowupTimeoutUs_ = 250000UL;
  bool gatewayCompatFollowupActive_ = false;
  bool gatewayCompatFirstFollowupCaptured_ = false;
  unsigned long gatewayCompatTotalFramesSeenAtArm_ = 0;
  bool gatewayCompatBusAliveAfterSetup_ = false;
  unsigned long lastUnknownRxAfterSetupExpectationUs_ = 0;
  uint16_t suppressedUnknownRxAfterSetupCount_ = 0;
  WrapperFsmState wrapperFsmState_ = WrapperFsmState::Idle;
  WrapperAckSemanticsMode wrapperAckSemanticsMode_ =
      WrapperAckSemanticsMode::StandardSetupAck;
  bool wrapperStandardFlowEntered_ = false;
  bool wrapperAckSemanticsSuspect_ = false;
  uint16_t wrapperContinuationTimeoutCount_ = 0;
  String wrapperExpectedNextRxKind_;
  String wrapperExpectedNextAction_;
  String wrapperTransitionReason_;
  String wrapperContinuationKind_;
  uint16_t wrapperContinuationRaw9_ = 0;
  unsigned long wrapperContinuationDeltaUs_ = 0;
  String wrapperContinuationInterpretation_;
  String setupResponseRejectedByVmc_ = "unknown";
  String setupRejectionBasis_;
  unsigned long lastNakAfterSetupTsUs_ = 0;
  uint16_t lastNakAfterSetupRaw9_ = 0;
  unsigned long lastNakAfterSetupDeltaUs_ = 0;
  uint16_t repeatedSetupCount_ = 0;
  uint16_t repeatedSetupSamePayloadCount_ = 0;
  uint16_t repeatedSetupVariantCount_ = 0;
  unsigned long lastSetupSeenUs_ = 0;
  uint16_t lastSetupRaw9_ = 0;
  int16_t lastSetupSubcommand_ = -1;
  String lastSetupVariant_;
  String lastSetupHex_;
  String lastRepeatedSetupReasonGuess_;
  String previousSetupVariant_;
  uint16_t previousSetupRaw9_ = 0;
  unsigned long previousSetupTimestampUs_ = 0;
  String repeatedSetupInterpretation_;
  String setupResponseProfileId_;
  String setupResponseSuspectField_;
  String gatewayCurrencyCountryCodeProfileId_;
  String currencyCountryCodeEncodingMode_;
  bool setupResponseExperimentEnabled_ = false;
  uint8_t setupResponseExperimentCurrencyCountryCodeHi_ = 0;
  uint8_t setupResponseExperimentCurrencyCountryCodeLo_ = 0;
  uint8_t setupResponseExperimentResponseTime_ = 0;
  uint8_t setupResponseExperimentOptions_ = 0;
  String setupResponseExperimentLabel_;
  volatile bool setupResponseVariantCycleEnabled_ = false;
  volatile uint8_t setupResponseVariantIndex_ = 0;
  volatile bool setupResponseVariantAccepted_ = false;
  String gatewayCompatExpectedFollowup_;
  String gatewayCompatRetryInterpretation_;
  String gatewayCompatLastOutcome_;
  String gatewayCompatSemanticSuspectField_;
  String firstFollowupKindAfterSetup_;
  uint16_t firstFollowupRaw9AfterSetup_ = 0;
  unsigned long firstFollowupDeltaUs_ = 0;
  String firstFollowupInterpretation_;
  String setupNakCausal_ = "unknown";
  String setupNakInterpretation_;
  uint16_t resetSeenCount_ = 0;
  uint16_t resetAckSentCount_ = 0;
  uint16_t justResetSentCount_ = 0;
  uint16_t justResetAcknowledgedCount_ = 0;
  uint16_t resetAfterSetupRetryCount_ = 0;
  uint16_t pollMissingAfterResetCount_ = 0;
  unsigned long lastResetTsUs_ = 0;
  unsigned long lastResetAckSentUs_ = 0;
  unsigned long lastResetAckPreparedUs_ = 0;
  unsigned long lastResetAckDoneUs_ = 0;
  unsigned long lastResetAckReleaseUs_ = 0;
  unsigned long lastPollAfterResetTsUs_ = 0;
  unsigned long lastJustResetSentUs_ = 0;
  unsigned long lastSetupResponseToResetUs_ = 0;
  unsigned long lastResetToAckUs_ = 0;
  unsigned long lastNextRxAfterResetTsUs_ = 0;
  bool repeatedSetupThenResetObserved_ = false;
  bool pollMissingAfterResetLogged_ = false;
  String lastResetCauseGuess_;
  String nextActionHypothesis_;
  bool beginSessionPending_ = false;
  uint16_t beginSessionAmountMinor_ = 0;
  bool beginSessionAwaitingAck_ = false;
  uint32_t beginSessionTxCount_ = 0;
  uint32_t beginSessionAckCount_ = 0;
  unsigned long lastBeginSessionTxUs_ = 0;
  unsigned long lastBeginSessionAckUs_ = 0;
  unsigned long lastBeginSessionSentAtMs_ = 0;
  String lastBeginSessionStatus_;
  uint32_t creditFlowRunCounter_ = 0;
  uint32_t creditFlowActiveRunId_ = 0;
  volatile bool creditFlowActive_ = false;
  volatile bool creditFlowCompleted_ = false;
  volatile bool creditFlowNeedsJustReset_ = false;
  volatile bool creditFlowJustResetSent_ = false;
  volatile bool creditFlowSessionHijackAttempted_ = false;
  volatile bool creditFlowVendDeniedSent_ = false;
  volatile bool creditFlowVendApprovedSent_ = false;
  volatile bool creditFlowSessionEndSent_ = false;
  volatile bool creditFlowSetupSeen_ = false;
  volatile bool creditFlowExpansionSeen_ = false;
  volatile bool creditFlowEnableSeen_ = false;
  volatile bool creditFlowBeginSessionSent_ = false;
  volatile bool creditFlowAwaitingAck_ = false;
  volatile bool creditFlowAckReceived_ = false;
  volatile bool creditFlowObservationActive_ = false;
  unsigned long creditFlowStartedAt_ = 0;
  unsigned long creditFlowObservationEndsAt_ = 0;
  unsigned long creditFlowResponseDelayUs_ = 0;
  unsigned long creditFlowExactReplyDelayUs_ = 0;
  unsigned long creditFlowLastRxByteUs_ = 0;
  unsigned long creditFlowFrameFinalizedUs_ = 0;
  unsigned long creditFlowFirstTxByteUs_ = 0;
  uint32_t creditFlowPhyLoopCounter_ = 0;
  uint32_t lastReportedRawGpioInterruptCount_ = 0;
  unsigned long lastReportedRawGpioSnapshotAtMs_ = 0;
  uint32_t decoderModeTraceCount_[MachinePhy::kSoftwareDecoderModes] = {};
  uint32_t decoderModeByteCount_[MachinePhy::kSoftwareDecoderModes] = {};
  uint8_t decoderModeLastPartial_[MachinePhy::kSoftwareDecoderModes] = {};
  uint8_t decoderModeLastByte_[MachinePhy::kSoftwareDecoderModes] = {};
  uint8_t decoderModeBestByte_[MachinePhy::kSoftwareDecoderModes] = {};
  uint8_t decoderModeBestDistanceTo10_[MachinePhy::kSoftwareDecoderModes] = {
      0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t decoderModeBestDistanceTo08_[MachinePhy::kSoftwareDecoderModes] = {
      0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t decoderModeLastPath_[MachinePhy::kSoftwareDecoderModes] = {};
  uint16_t creditFlowAmountMinor_ = 0;
  uint8_t creditFlowPostReplyFrameCount_ = 0;
  String creditFlowCandidateLabel_;
  String creditFlowCandidateBytes_;
  String creditFlowObservedFamilies_;
  ReaderState readerState_ = ReaderState::Uninitialized;
  DialogueKind lastRxKind_ = DialogueKind::Unknown;
  DialogueKind lastTxKindEnum_ = DialogueKind::Unknown;
  unsigned long txFrameCount_ = 0;
  unsigned long pollRxCount_ = 0;
  unsigned long pollTxCount_ = 0;
  unsigned long enableRxCount_ = 0;
  unsigned long enableAppliedCount_ = 0;
  unsigned long setupRxCount_ = 0;
  unsigned long setupTxCount_ = 0;
  unsigned long expansionRxCount_ = 0;
  unsigned long expansionTxCount_ = 0;
  unsigned long ackTxCount_ = 0;
  unsigned long noResponseCount_ = 0;
  unsigned long stateTransitionCount_ = 0;
  unsigned long lastRxToTxLatencyUs_ = 0;
  String lastNoResponseReason_;
  String lastStateTransitionReason_;
  DialogueEvent dialogueHistory_[kDialogueHistorySize] = {};
  size_t dialogueHistoryNext_ = 0;
  size_t dialogueHistoryCount_ = 0;
  ResponsePathState responsePathState_ = ResponsePathState::Idle;
  unsigned long responseStateChangedAtUs_ = 0;
  BusFrameSnapshot lastAcceptedRxFrame_ = {};
  BusFrameSnapshot lastUnknownRxFrame_ = {};
  int16_t lastUnknownCandidateAddress_ = -1;
  int16_t lastUnknownCandidateCommand_ = -1;
  String lastUnknownReason_;
  String lastResponseDecisionReason_;
  bool lastResponseDecisionWillRespond_ = false;
  BusFrameSnapshot lastTxFrame_ = {};
  String lastTxKind_;
  String lastExpectedTxKind_;
  String lastActualTxKind_;
  String lastTxAuditReason_;
  String lastRxToExpectedTxMapping_;
  String lastRxToActualTxMapping_;
  String lastTxErrorReason_;
  bool txExpectationPending_ = false;
  bool txExpectationRequired_ = false;
  unsigned long txExpectationSetAtUs_ = 0;
  DialogueKind txExpectationRxKind_ = DialogueKind::Unknown;
  ReaderState txExpectationReaderState_ = ReaderState::Uninitialized;
  uint16_t txDecisionMismatchCount_ = 0;
  uint16_t txMissingCount_ = 0;
  unsigned long txAttemptCount_ = 0;
  unsigned long txSuccessCount_ = 0;
  unsigned long txAbortCount_ = 0;
  unsigned long txTimeoutCount_ = 0;
  unsigned long lastTxStartUs_ = 0;
  unsigned long lastTxDoneUs_ = 0;
  unsigned long lastTxReleaseUs_ = 0;
  uint8_t txEmittedCountByKind_[kTxAuditKindBucketCount] = {};
  uint8_t txCompletedCountByKind_[kTxAuditKindBucketCount] = {};
  uint8_t txTimeoutCountByKind_[kTxAuditKindBucketCount] = {};
  uint8_t txAbortCountByKind_[kTxAuditKindBucketCount] = {};
  TxScope currentTxScope_ = TxScope::None;
  String currentTxKind_;
  bool deferTxObserverEvents_ = false;
  uint32_t deferredTxFrameId_ = 0;
  size_t deferredTxCount_ = 0;
  uint8_t deferredTxBytes_[kStoredFrameBytes] = {};
  uint8_t deferredTxNinthBits_[kStoredFrameBytes] = {};
  unsigned long deferredTxTimestampsUs_[kStoredFrameBytes] = {};
  bool deferredFastPathVendApproved_ = false;
  bool deferredFastPathBeginSession_ = false;
  uint8_t deferredFastPathCashlessKind_ = 0;
  unsigned long deferredFastPathCashlessTxUs_ = 0;
  bool deferredFastPathCashlessEnabled_ = false;
  bool deferredFastPathFinalizeCreditFlow_ = false;
  const char *deferredFastPathFinalizeStatus_ = nullptr;
  const char *deferredFastPathFinalizeReason_ = nullptr;
  uint8_t vendApprovedPayload_[3] = {};
  uint8_t vendApprovedFrame_[4] = {};
  size_t vendApprovedFrameLength_ = 0;
  uint8_t vendDeniedPayload_[1] = {0x06};
  uint8_t vendDeniedFrame_[2] = {};
  size_t vendDeniedFrameLength_ = 0;
  uint8_t ackFrame_[2] = {};
  size_t ackFrameLength_ = 0;
  uint8_t beginSessionPayload_[3] = {};
  uint8_t beginSessionFrame_[4] = {};
  size_t beginSessionFrameLength_ = 0;
  bool fastHandledFramePending_ = false;
  unsigned long fastHandledFrameEndedUs_ = 0;
  uint8_t fastHandledFrameAddress_ = 0;
  uint8_t fastHandledFrameCommand_ = 0;
  unsigned long coinCompatPollFastHandledAtUs_ = 0;
  bool pendingCashlessSplitPrefixActive_ = false;
  machine::Frame pendingCashlessSplitPrefixFrame_ = {};
  unsigned long pendingCashlessSplitPrefixCapturedAtMs_ = 0;
  machine::RawByte observedRawStatusBytes_[8] = {};
  size_t observedRawStatusLength_ = 0;
  uint8_t gatewaySetupCompatStage_ = 0;
  unsigned long gatewaySetupCompatStartedUs_ = 0;
  bool gatewaySetupCompatSawExplicitZero_ = false;
  unsigned long lastCapturedSymbolDumpAtMs_ = 0;
  SniffFrameRecord sniffHistory_[kSniffHistorySize] = {};
  size_t sniffHistoryNext_ = 0;
  size_t sniffHistoryCount_ = 0;

  bool postEnableExpansionProbePending_ = false;
  unsigned long postEnableExpansionProbeAtMs_ = 0;
  uint8_t postEnableExpansionProbeCount_ = 0;
  MdbOperatingMode mdbOperatingMode_ = MdbOperatingMode::Cashless;
};
