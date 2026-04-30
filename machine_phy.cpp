#include "machine_phy.h"

#include <driver/uart.h>
#include <driver/gpio.h>
#include <esp_intr_alloc.h>
#include <esp_rom_gpio.h>
#include <esp_log.h>
#include <soc/io_mux_reg.h>
#include <xtensa/core-macros.h>

#include "device_config.h"

namespace {
constexpr uart_port_t kMachineUartNum = UART_NUM_2;
constexpr int kForcedTxPin = MDB_TX_PIN;
constexpr int kForcedRxPin = MDB_RX_PIN;
constexpr unsigned long kContinuationWindowMs = 8;
constexpr unsigned long kFastFrameGapUs = 5000;
constexpr unsigned long kSessionBreakGapMs = 120000;
#ifndef BIT_PERIOD_US
#define BIT_PERIOD_US 104
#endif
constexpr unsigned long kMdbBitUs = BIT_PERIOD_US;
constexpr unsigned long kMdbHalfBitUs = kMdbBitUs / 2UL;
constexpr unsigned long kMdbCharacterTxUs = kMdbBitUs * 12UL;
constexpr uint8_t kStrictSoftwareDecoderMode = 3;
constexpr int kUartEventQueueSize = 20;
constexpr size_t kUartRxBufferSize = 1024;
constexpr UBaseType_t kUartTaskPriority = 5;
constexpr gpio_num_t kHeartbeatLedPin = GPIO_NUM_2;
constexpr const char* kPhyLogTag = "MachinePhy";
constexpr unsigned long kConfigOkRepeatMs = 10000;
constexpr uart_parity_t kMdbRxParityMode = UART_PARITY_EVEN;
constexpr int kMdbRxFullThreshold = 1;
constexpr int kMdbRxTimeoutChars = 1;
constexpr unsigned long kCpuCyclesPerUs = CONFIG_ESP32_DEFAULT_CPU_FREQ_MHZ;
constexpr unsigned long kDecoderIdleStableUs = (kMdbBitUs * 3UL) / 4UL;
constexpr unsigned long kDecoderPolarityMismatchUs = kMdbBitUs * 4UL;
constexpr unsigned long kDecoderFrameSpanUs = kMdbBitUs * 11UL;
constexpr unsigned long kDecoderFrameFinalizeUs = kDecoderFrameSpanUs + kMdbHalfBitUs;
constexpr unsigned long kDecoderTimingDriftUs = 48UL;
constexpr unsigned long kDecoderTooCloseEdgeUs = 12UL;
constexpr int32_t kDecoderPhaseAdjustWindowUs = 18;
constexpr int32_t kDecoderMaxPhaseCorrectionUs = 18;

uart_parity_t parityForNinthBitZero(uint8_t value) {
  const bool oddOnes = (__builtin_popcount(static_cast<unsigned int>(value)) & 0x01U) != 0;
  return oddOnes ? UART_PARITY_ODD : UART_PARITY_EVEN;
}

uart_parity_t parityForNinthBitOne(uint8_t value) {
  const bool oddOnes = (__builtin_popcount(static_cast<unsigned int>(value)) & 0x01U) != 0;
  return oddOnes ? UART_PARITY_EVEN : UART_PARITY_ODD;
}

inline unsigned long IRAM_ATTR isrMicros() {
  return static_cast<unsigned long>(xthal_get_ccount() / kCpuCyclesPerUs);
}

template <typename T>
T clampValue(T value, T lower, T upper) {
  if (value < lower) {
    return lower;
  }
  if (value > upper) {
    return upper;
  }
  return value;
}

}  // namespace

// Сохраняет параметры линии и активирует UART-интерфейс автомата.
void MachinePhy::begin(unsigned long baudRate, int rxPin, int txPin, bool rxInvert,
                       bool txInvert, unsigned long frameGapMs) {
  baudRate_ = baudRate;
  rxPin_ = rxPin;
  txPin_ = txPin;
  rxInvert_ = rxInvert;
  txInvert_ = txInvert;
  frameGapMs_ = frameGapMs;
  frameGapUs_ = kFastFrameGapUs;
  activate(true);
}

void MachinePhy::beginSniffer(int rxPin, int txPin) {
  deactivate();
  baudRate_ = 9600;
  rxPin_ = rxPin;
  txPin_ = txPin;
  rxInvert_ = false;
  txInvert_ = false;
  frameGapMs_ = 0;
  frameGapUs_ = 0;
  active_ = true;
  phyIsReady_ = true;
  phySawRxByte_ = false;
  phyConfigOkPending_ = false;
  rawGpioInterruptCount_ = 0;
  lastRawEdgeDumpAtMs_ = 0;
  pendingRxAddressBit_ = false;
  activeSoftwareDecoderMode_ = kStrictSoftwareDecoderMode;
  swLastEdgeTsUs_ = 0;
  for (size_t i = 0; i < kSoftwareDecoderPaths; ++i) {
    swDecoderFraming_[i] = false;
    swDecoderBitPos_[i] = 0;
    swDecoderValue_[i] = 0;
    swDecoderNinthBit_[i] = false;
    swDecoderLastActivityUs_[i] = 0;
    swDebugBitPos_[i] = 0;
    swDebugLastValue_[i] = 0;
    swDebugLastNinthBit_[i] = false;
    swDebugResetReason_[i] = 0;
  }
  recentRxInterruptWriteIndex_ = 0;
  recentRxInterruptWrapped_ = false;
  capturedSymbolWriteIndex_ = 0;
  capturedSymbolWrapped_ = false;
  for (size_t i = 0; i < kCapturedSymbolHistory; ++i) {
    capturedSymbols_[i] = {};
  }
  portENTER_CRITICAL(&stateLock_);
  resetDecoderRuntimeLocked(micros(), 1U);
  const uint8_t currentRawLevel =
      static_cast<uint8_t>(gpio_get_level(static_cast<gpio_num_t>(rxPin_)) & 0x1U);
  resetDecoderRuntimeLocked(micros(), normalizeRxLevel(currentRawLevel));
  portEXIT_CRITICAL(&stateLock_);

  uart_driver_delete(kMachineUartNum);
  uartConfigured_ = false;
  uartEventQueue_ = nullptr;
  gpio_reset_pin(static_cast<gpio_num_t>(txPin_));
  gpio_reset_pin(static_cast<gpio_num_t>(rxPin_));
  gpio_set_direction(static_cast<gpio_num_t>(txPin_), GPIO_MODE_OUTPUT);
  gpio_set_level(static_cast<gpio_num_t>(txPin_), 0);
  gpio_set_direction(static_cast<gpio_num_t>(rxPin_), GPIO_MODE_INPUT);
  gpio_set_pull_mode(static_cast<gpio_num_t>(rxPin_), GPIO_PULLUP_ONLY);
  gpio_set_intr_type(static_cast<gpio_num_t>(rxPin_), GPIO_INTR_ANYEDGE);
  const esp_err_t isrInstall = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
  if (isrInstall == ESP_OK || isrInstall == ESP_ERR_INVALID_STATE) {
    gpio_isr_handler_remove(static_cast<gpio_num_t>(rxPin_));
    gpio_isr_handler_add(static_cast<gpio_num_t>(rxPin_), &MachinePhy::rxGpioIsrThunk,
                         this);
  } else {
    lastInitError_ = static_cast<int>(isrInstall);
  }
  configuredRxPin_ = rxPin_;
  configuredTxPin_ = txPin_;
  configuredRxInvert_ = rxInvert_;
  configuredTxInvert_ = txInvert_;
  hasActivatedOnce_ = true;
}

// Включает PHY и применяет нужную инверсию линий.
esp_err_t MachinePhy::activate(bool forceReinit) {
  const bool configUnchanged =
      uartConfigured_ && configuredRxPin_ == static_cast<int>(kForcedRxPin) &&
      configuredTxPin_ == static_cast<int>(kForcedTxPin) &&
      configuredRxInvert_ == rxInvert_ && configuredTxInvert_ == txInvert_;
  if (active_ && !forceReinit && configUnchanged && phyIsReady_) {
    return ESP_OK;
  }

  const bool hadEventTask = uartEventTask_ != nullptr;
  const bool resetRawCounters = !hasActivatedOnce_ || forceReinit;
  active_ = true;
  phyIsReady_ = false;
  phySawRxByte_ = false;
  phyConfigOkPending_ = false;
  lastConfigOkAtMs_ = 0;
  pendingRxAddressBit_ = false;
  swLastEdgeTsUs_ = 0;
  for (size_t i = 0; i < kSoftwareDecoderPaths; ++i) {
    swDecoderFraming_[i] = false;
    swDecoderBitPos_[i] = 0;
    swDecoderValue_[i] = 0;
    swDecoderNinthBit_[i] = false;
    swDecoderLastActivityUs_[i] = 0;
    swDebugBitPos_[i] = 0;
    swDebugLastValue_[i] = 0;
    swDebugLastNinthBit_[i] = false;
    swDebugResetReason_[i] = 0;
  }
  swDebugLastDeltaUs_ = 0;
  activeSoftwareDecoderMode_ = kStrictSoftwareDecoderMode;
  if (resetRawCounters) {
    rawGpioInterruptCount_ = 0;
    lastRawEdgeDumpAtMs_ = 0;
    lastObservedRawGpioInterruptCount_ = 0;
    lastBusChangeAtMs_ = millis();
    reportedBusStuckLevel_ = -1;
    recentRxInterruptWriteIndex_ = 0;
    recentRxInterruptWrapped_ = false;
    for (size_t i = 0; i < kRecentRxInterrupts; ++i) {
      recentRxInterruptTsUs_[i] = 0;
      recentRxInterruptLevel_[i] = 0;
    }
    capturedSymbolWriteIndex_ = 0;
    capturedSymbolWrapped_ = false;
    for (size_t i = 0; i < kCapturedSymbolHistory; ++i) {
      capturedSymbols_[i] = {};
    }
  }
  portENTER_CRITICAL(&stateLock_);
  resetDecoderRuntimeLocked(micros(), 1U);
  portEXIT_CRITICAL(&stateLock_);
  clearContinuationState();
  if (hadEventTask) {
    vTaskDelete(uartEventTask_);
    uartEventTask_ = nullptr;
  }
  if (uartConfigured_ || uartEventQueue_ != nullptr) {
    uart_driver_delete(kMachineUartNum);
    uartConfigured_ = false;
    uartEventQueue_ = nullptr;
  }
  gpio_reset_pin(static_cast<gpio_num_t>(kForcedRxPin));
  gpio_reset_pin(static_cast<gpio_num_t>(kForcedTxPin));
  gpio_set_direction(static_cast<gpio_num_t>(kForcedTxPin), GPIO_MODE_OUTPUT);
  gpio_set_level(static_cast<gpio_num_t>(kForcedTxPin), 0);
  gpio_set_direction(static_cast<gpio_num_t>(kForcedRxPin), GPIO_MODE_INPUT);
  gpio_set_pull_mode(static_cast<gpio_num_t>(kForcedRxPin), GPIO_PULLUP_ONLY);
  txPin_ = static_cast<int>(kForcedTxPin);
  rxPin_ = static_cast<int>(kForcedRxPin);
  uart_config_t config = {};
  config.baud_rate = 9600;
  config.data_bits = UART_DATA_8_BITS;
  config.parity = kMdbRxParityMode;
  config.stop_bits = UART_STOP_BITS_1;
  config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
  config.rx_flow_ctrl_thresh = 0;
  config.source_clk = UART_SCLK_APB;
  lastInitError_ = uart_param_config(kMachineUartNum, &config);
  if (lastInitError_ != ESP_OK) {
    if (statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                      static_cast<uint32_t>(lastInitError_));
    }
    return lastInitError_;
  }
  lastInitError_ = uart_set_pin(kMachineUartNum, kForcedTxPin, kForcedRxPin,
                                UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
  if (lastInitError_ != ESP_OK) {
    if (statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                      static_cast<uint32_t>(lastInitError_));
    }
    return lastInitError_;
  }
  lastInitError_ = uart_driver_install(kMachineUartNum, kUartRxBufferSize, 0,
                                       kUartEventQueueSize, &uartEventQueue_, 0);
  if (lastInitError_ != ESP_OK) {
    if (statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                      static_cast<uint32_t>(lastInitError_));
    }
    return lastInitError_;
  }
  uartConfigured_ = true;
  lastInitError_ = uart_set_mode(kMachineUartNum, UART_MODE_UART);
  if (lastInitError_ != ESP_OK) {
    if (statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                      static_cast<uint32_t>(lastInitError_));
    }
    return lastInitError_;
  }
  restoreRxParityMode();
  uart_set_rx_full_threshold(kMachineUartNum, kMdbRxFullThreshold);
  uart_set_rx_timeout(kMachineUartNum, kMdbRxTimeoutChars);
  uart_flush_input(kMachineUartNum);
  applyLineInversion();
  esp_rom_gpio_pad_select_gpio(static_cast<gpio_num_t>(kForcedRxPin));
  PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[kForcedRxPin], PIN_FUNC_GPIO);
  gpio_set_direction(static_cast<gpio_num_t>(kForcedRxPin), GPIO_MODE_INPUT);
  gpio_set_pull_mode(static_cast<gpio_num_t>(kForcedRxPin), GPIO_PULLUP_ONLY);
  gpio_set_intr_type(static_cast<gpio_num_t>(kForcedRxPin), GPIO_INTR_ANYEDGE);
  esp_err_t isrInstall = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
  if (isrInstall != ESP_OK && isrInstall != ESP_ERR_INVALID_STATE) {
    lastInitError_ = static_cast<int>(isrInstall);
    if (statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                      static_cast<uint32_t>(lastInitError_));
    }
    return lastInitError_;
  }
  gpio_isr_handler_remove(static_cast<gpio_num_t>(kForcedRxPin));
  isrInstall = gpio_isr_handler_add(static_cast<gpio_num_t>(kForcedRxPin),
                                    &MachinePhy::rxGpioIsrThunk, this);
  if (isrInstall != ESP_OK) {
    lastInitError_ = static_cast<int>(isrInstall);
    if (statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                      static_cast<uint32_t>(lastInitError_));
    }
    return lastInitError_;
  }
  configuredRxPin_ = rxPin_;
  configuredTxPin_ = txPin_;
  configuredRxInvert_ = rxInvert_;
  configuredTxInvert_ = txInvert_;
  hasActivatedOnce_ = true;
  lastInitError_ = ESP_OK;
  phyIsReady_ = true;
  phyConfigOkPending_ = true;
  portENTER_CRITICAL(&stateLock_);
  const uint8_t currentRawLevel =
      static_cast<uint8_t>(gpio_get_level(static_cast<gpio_num_t>(kForcedRxPin)) & 0x1U);
  resetDecoderRuntimeLocked(micros(), normalizeRxLevel(currentRawLevel));
  portEXIT_CRITICAL(&stateLock_);
  if (hadEventTask) {
    startEventTask();
  }
  return ESP_OK;
}

void MachinePhy::startEventTask() {
  if (!active_ || uartEventTask_ != nullptr || !uartConfigured_) {
    return;
  }
  vTaskDelay(pdMS_TO_TICKS(100));
  xTaskCreatePinnedToCore(&MachinePhy::uartEventTaskThunk, "mdb_uart_evt", kMdbUartEvtTaskStackBytes,
                          this, kUartTaskPriority, &uartEventTask_, 1);
}

// Логически отключает PHY.
void MachinePhy::deactivate() {
  active_ = false;
  clearContinuationState();
  if (uartEventTask_ != nullptr) {
    vTaskDelete(uartEventTask_);
    uartEventTask_ = nullptr;
  }
  if (rxPin_ >= 0) {
    gpio_isr_handler_remove(static_cast<gpio_num_t>(rxPin_));
  }
  if (uartConfigured_ || uartEventQueue_ != nullptr) {
    uart_driver_delete(kMachineUartNum);
    uartEventQueue_ = nullptr;
    uartConfigured_ = false;
  }
}

esp_err_t MachinePhy::debugForceRawSniffer() {
  deactivate();
  rxPin_ = static_cast<int>(kForcedRxPin);
  txPin_ = static_cast<int>(kForcedTxPin);
  active_ = true;
  phyIsReady_ = false;
  phySawRxByte_ = false;
  phyConfigOkPending_ = false;
  rawGpioInterruptCount_ = 0;
  lastRawEdgeDumpAtMs_ = 0;
  recentRxInterruptWriteIndex_ = 0;
  recentRxInterruptWrapped_ = false;
  for (size_t i = 0; i < kRecentRxInterrupts; ++i) {
    recentRxInterruptTsUs_[i] = 0;
    recentRxInterruptLevel_[i] = 0;
  }
  portENTER_CRITICAL(&stateLock_);
  resetDecoderRuntimeLocked(micros(), 1U);
  const uint8_t currentRawLevel =
      static_cast<uint8_t>(
          gpio_get_level(static_cast<gpio_num_t>(kForcedRxPin)) & 0x1U);
  resetDecoderRuntimeLocked(micros(), normalizeRxLevel(currentRawLevel));
  portEXIT_CRITICAL(&stateLock_);

  gpio_reset_pin(static_cast<gpio_num_t>(kForcedRxPin));
  esp_rom_gpio_pad_select_gpio(static_cast<gpio_num_t>(kForcedRxPin));
  PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[kForcedRxPin], PIN_FUNC_GPIO);
  gpio_set_direction(static_cast<gpio_num_t>(kForcedRxPin), GPIO_MODE_INPUT);
  gpio_set_pull_mode(static_cast<gpio_num_t>(kForcedRxPin), GPIO_PULLUP_ONLY);
  gpio_set_intr_type(static_cast<gpio_num_t>(kForcedRxPin), GPIO_INTR_ANYEDGE);

  esp_err_t err = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
  if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
    lastInitError_ = static_cast<int>(err);
    return err;
  }
  gpio_isr_handler_remove(static_cast<gpio_num_t>(kForcedRxPin));
  err = gpio_isr_handler_add(static_cast<gpio_num_t>(kForcedRxPin),
                             &MachinePhy::rxGpioIsrThunk, this);
  if (err != ESP_OK) {
    lastInitError_ = static_cast<int>(err);
    return err;
  }

  lastInitError_ = ESP_OK;
  return ESP_OK;
}

// Возвращает признак активности PHY.
bool MachinePhy::isActive() const { return active_; }

// Перенастраивает инверсию RX на лету.
void MachinePhy::setRxInvert(bool enabled) {
  if (rxInvert_ == enabled) {
    return;
  }
  mdb_decoder_set_inversion(enabled);
  if (active_) {
    applyLineInversion();
  }
}

// Читает байты из UART и собирает кадры по межбайтовой паузе.
void MachinePhy::update() {
  // RX финализируется в отдельной UART event task; loop() здесь больше не нужен.
}

// Отдаёт следующий готовый кадр вызывающему коду.
bool MachinePhy::takeFrame(machine::Frame& out) {
  portENTER_CRITICAL(&stateLock_);
  if (!hasReadyFrame_) {
    portEXIT_CRITICAL(&stateLock_);
    return false;
  }

  out = readyFrame_;
  readyFrame_ = {};
  hasReadyFrame_ = false;
  currentFrameGapBeforeMs_ = out.frameGapAfterMs;
  portEXIT_CRITICAL(&stateLock_);
  return true;
}

uint32_t MachinePhy::rawGpioInterruptCount() const { return rawGpioInterruptCount_; }

int MachinePhy::currentRxLevel() const {
  if (rxPin_ < 0) {
    return -1;
  }
  return gpio_get_level(static_cast<gpio_num_t>(rxPin_)) & 0x1U;
}

uint8_t MachinePhy::activeSoftwareDecoderMode() const {
  portENTER_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  const uint8_t mode = activeSoftwareDecoderMode_;
  portEXIT_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  return mode;
}

unsigned long MachinePhy::softwareDecoderLastDeltaUs() const {
  portENTER_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  const unsigned long deltaUs = swDebugLastDeltaUs_;
  portEXIT_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  return deltaUs;
}

size_t MachinePhy::copySoftwareDecoderPathStates(
    SoftwareDecoderPathState* out, size_t maxCount) const {
  if (out == nullptr || maxCount == 0) {
    return 0;
  }
  const size_t count =
      kSoftwareDecoderPaths < maxCount ? kSoftwareDecoderPaths : maxCount;
  portENTER_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  for (size_t i = 0; i < count; ++i) {
    out[i].framing = swDecoderFraming_[i];
    out[i].bitPos = swDebugBitPos_[i];
    out[i].lastValue = swDebugLastValue_[i];
    out[i].ninthBit = swDebugLastNinthBit_[i];
    out[i].resetReason = swDebugResetReason_[i];
    out[i].lastActivityUs = swDecoderLastActivityUs_[i];
  }
  portEXIT_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  return count;
}

size_t MachinePhy::copyCapturedSymbols(CapturedSymbol* out, size_t maxCount) const {
  if (out == nullptr || maxCount == 0) {
    return 0;
  }
  portENTER_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  const size_t stored =
      capturedSymbolWrapped_ ? kCapturedSymbolHistory : capturedSymbolWriteIndex_;
  const size_t count = stored < maxCount ? stored : maxCount;
  const size_t start =
      capturedSymbolWrapped_
          ? (capturedSymbolWriteIndex_ + kCapturedSymbolHistory - count) %
                kCapturedSymbolHistory
          : (stored - count);
  for (size_t i = 0; i < count; ++i) {
    const size_t index = (start + i) % kCapturedSymbolHistory;
    out[i] = capturedSymbols_[index];
  }
  portEXIT_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  return count;
}

size_t MachinePhy::copyRecentRxInterrupts(unsigned long* tsUsOut, uint8_t* levelOut,
                                          size_t maxCount) const {
  if (tsUsOut == nullptr || levelOut == nullptr || maxCount == 0) {
    return 0;
  }
  portENTER_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  const size_t stored =
      recentRxInterruptWrapped_ ? kRecentRxInterrupts : recentRxInterruptWriteIndex_;
  const size_t count = stored < maxCount ? stored : maxCount;
  const size_t start =
      recentRxInterruptWrapped_
          ? (recentRxInterruptWriteIndex_ + kRecentRxInterrupts - count) % kRecentRxInterrupts
          : (stored - count);
  for (size_t i = 0; i < count; ++i) {
    const size_t index = (start + i) % kRecentRxInterrupts;
    tsUsOut[i] = recentRxInterruptTsUs_[index];
    levelOut[i] = recentRxInterruptLevel_[index];
  }
  portEXIT_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  return count;
}

uint8_t MachinePhy::normalizeRxLevel(uint8_t rawLevel) const {
  const uint8_t level = static_cast<uint8_t>(rawLevel & 0x1U);
  return rxInvert_ ? static_cast<uint8_t>(level == 0U ? 1U : 0U) : level;
}

void MachinePhy::resetDecoderCandidateLocked() {
  candidateEdgeCount_ = 0;
  candidateTimingDrift_ = false;
  candidateStartUs_ = 0;
  candidateLastEdgeUs_ = 0;
  candidateIdleBeforeStartUs_ = 0;
  candidateInitialLevelBeforeStart_ = 1U;
  candidatePhaseCorrectionUs_ = 0;
  candidateWorstPhaseErrorUs_ = 0;
  decoderStats_.currentCandidateTrace = {};
  decoderDebugBitPos_ = 0;
  swDecoderFraming_[0] = false;
  swDecoderBitPos_[0] = 0;
}

void MachinePhy::resetDecoderRuntimeLocked(unsigned long nowUs,
                                           uint8_t normalizedLevel) {
  decoderEdgeWriteIndex_ = 0;
  decoderEdgeReadIndex_ = 0;
  decoderEdgeSequence_ = 0;
  decodedFrameWriteIndex_ = 0;
  decodedFrameReadIndex_ = 0;
  resetDecoderCandidateLocked();
  decoderState_ = DecoderState::WaitingIdle;
  normalizedRxLevel_ = normalizedLevel != 0U ? 1U : 0U;
  normalizedLevelChangedUs_ = nowUs;
  idleSinceUs_ = normalizedRxLevel_ != 0U ? nowUs : 0;
  lineLowSinceUs_ = normalizedRxLevel_ == 0U ? nowUs : 0;
  decoderLastActivityUs_ = nowUs;
  polarityMismatchLatched_ = false;
  decoderDebugBitPos_ = 0;
  decoderDebugLastValue_ = 0;
  decoderDebugLastNinthBit_ = false;
  decoderDebugLastReason_ = 0;
  swLastEdgeTsUs_ = 0;
  swDebugLastDeltaUs_ = 0;
  activeSoftwareDecoderMode_ = kStrictSoftwareDecoderMode;
  traceGenerationCounter_ = 0;
  decoderStats_.currentCandidateTrace = {};
  decoderStats_.lastBadTrace = {};
  decoderStats_.debugFrameTrace = {};
  for (size_t i = 0; i < kSoftwareDecoderPaths; ++i) {
    swDecoderFraming_[i] = false;
    swDecoderBitPos_[i] = 0;
    swDecoderValue_[i] = 0;
    swDecoderNinthBit_[i] = false;
    swDecoderLastActivityUs_[i] = 0;
    swDebugBitPos_[i] = 0;
    swDebugLastValue_[i] = 0;
    swDebugLastNinthBit_[i] = false;
    swDebugResetReason_[i] = 0;
  }
}

bool MachinePhy::decoderIdleStableLocked(unsigned long tsUs) const {
  return normalizedRxLevel_ != 0U && idleSinceUs_ != 0 &&
         tsUs >= idleSinceUs_ &&
         (tsUs - idleSinceUs_) >= kDecoderIdleStableUs;
}

bool MachinePhy::shouldReportPolarityMismatchLocked(unsigned long nowUs) const {
  if (decoderState_ == DecoderState::Receiving ||
      decoderState_ == DecoderState::ResyncWaitIdle) {
    return false;
  }
  if (normalizedRxLevel_ != 0U || lineLowSinceUs_ == 0 || polarityMismatchLatched_) {
    return false;
  }
  if (nowUs < lineLowSinceUs_) {
    return false;
  }
  return (nowUs - lineLowSinceUs_) >= kDecoderPolarityMismatchUs;
}

void MachinePhy::beginCurrentCandidateTraceLocked(unsigned long startTsUs,
                                                  uint8_t initialLevelBeforeStart,
                                                  uint32_t startRingIndex) {
  DecoderFrameTrace& trace = decoderStats_.currentCandidateTrace;
  trace = {};
  trace.valid = true;
  trace.traceGenerationId = ++traceGenerationCounter_;
  trace.candidateStartTsUs = static_cast<uint32_t>(startTsUs);
  trace.initialLevelBeforeStart = initialLevelBeforeStart != 0U ? 1U : 0U;
  trace.frameWindowStartUs = startTsUs > kDecoderIdleStableUs
                                 ? static_cast<uint32_t>(startTsUs - kDecoderIdleStableUs)
                                 : 0U;
  trace.frameWindowEndUs =
      static_cast<uint32_t>(startTsUs + kDecoderFrameFinalizeUs);
  trace.traceUpdatedTsUs = static_cast<uint32_t>(startTsUs);
  trace.candidateFinalizeTsUs = 0;
  trace.latestEdgeTsSeenWhenFinalized = static_cast<uint32_t>(startTsUs);
  trace.firstRingIndex = startRingIndex;
  trace.lastRingIndex = startRingIndex;
  trace.ringWriteIndexAtCandidateCreate = decoderEdgeSequence_;
  trace.ringWriteIndexAtFrameFinalize = 0;
  trace.badReason = static_cast<uint8_t>(DecoderBadReason::None);
  trace.finalizedWithLiveRingTail = false;
  trace.scanStopReason =
      static_cast<uint8_t>(DecoderTraceScanStopReason::Unknown);
  syncCurrentCandidateTraceLocked(startTsUs);
}

void MachinePhy::syncCurrentCandidateTraceLocked(unsigned long updatedTsUs) {
  DecoderFrameTrace& trace = decoderStats_.currentCandidateTrace;
  if (!trace.valid || candidateStartUs_ == 0) {
    return;
  }

  trace.candidateStartTsUs = static_cast<uint32_t>(candidateStartUs_);
  trace.initialLevelBeforeStart = candidateInitialLevelBeforeStart_;
  trace.frameWindowStartUs = candidateStartUs_ > kDecoderIdleStableUs
                                 ? static_cast<uint32_t>(candidateStartUs_ - kDecoderIdleStableUs)
                                 : 0U;
  trace.frameWindowEndUs =
      static_cast<uint32_t>(candidateStartUs_ + kDecoderFrameFinalizeUs);
  trace.traceUpdatedTsUs = static_cast<uint32_t>(updatedTsUs);
  if (updatedTsUs > trace.latestEdgeTsSeenWhenFinalized) {
    trace.latestEdgeTsSeenWhenFinalized = static_cast<uint32_t>(updatedTsUs);
  }
  trace.idleDurationBeforeStartUs =
      static_cast<uint32_t>(candidateIdleBeforeStartUs_);
  trace.collectedEdgeCountTotal = trace.scannedEdgeCount;
  const uint32_t inWindow =
      static_cast<uint32_t>(trace.scannedEdgeCount) -
      static_cast<uint32_t>(trace.rejectBeforeWindowCount) -
      static_cast<uint32_t>(trace.rejectAfterWindowCount);
  trace.collectedEdgeCountInWindow = static_cast<uint16_t>(
      inWindow > 0xFFFFU ? 0xFFFFU : inWindow);
}

void MachinePhy::appendCurrentCandidateTraceEdgeLocked(
    unsigned long tsUs, uint8_t normalizedLevel, uint32_t ringIndex,
    DecoderTraceEdgeDecision decision) {
  DecoderFrameTrace& trace = decoderStats_.currentCandidateTrace;
  if (!trace.valid) {
    return;
  }

  syncCurrentCandidateTraceLocked(tsUs);
  trace.traceUpdatedTsUs = static_cast<uint32_t>(tsUs);
  if (trace.firstRingIndex == 0 || ringIndex < trace.firstRingIndex) {
    trace.firstRingIndex = ringIndex;
  }
  if (ringIndex > trace.lastRingIndex) {
    trace.lastRingIndex = ringIndex;
  }
  if (trace.scannedEdgeCount < 0xFFFFU) {
    trace.scannedEdgeCount++;
  }

  switch (decision) {
    case DecoderTraceEdgeDecision::Accepted:
      if (trace.acceptedEdgeCount < 0xFFFFU) {
        trace.acceptedEdgeCount++;
      }
      break;
    case DecoderTraceEdgeDecision::BeforeWindow:
      if (trace.rejectedEdgeCount < 0xFFFFU) {
        trace.rejectedEdgeCount++;
      }
      if (trace.rejectBeforeWindowCount < 0xFFFFU) {
        trace.rejectBeforeWindowCount++;
      }
      break;
    case DecoderTraceEdgeDecision::AfterWindow:
      if (trace.rejectedEdgeCount < 0xFFFFU) {
        trace.rejectedEdgeCount++;
      }
      if (trace.rejectAfterWindowCount < 0xFFFFU) {
        trace.rejectAfterWindowCount++;
      }
      break;
    case DecoderTraceEdgeDecision::Duplicate:
      if (trace.rejectedEdgeCount < 0xFFFFU) {
        trace.rejectedEdgeCount++;
      }
      if (trace.rejectDuplicateCount < 0xFFFFU) {
        trace.rejectDuplicateCount++;
      }
      break;
    case DecoderTraceEdgeDecision::TooClose:
      if (trace.rejectedEdgeCount < 0xFFFFU) {
        trace.rejectedEdgeCount++;
      }
      if (trace.rejectTooCloseCount < 0xFFFFU) {
        trace.rejectTooCloseCount++;
      }
      break;
    case DecoderTraceEdgeDecision::Overwritten:
      if (trace.rejectedEdgeCount < 0xFFFFU) {
        trace.rejectedEdgeCount++;
      }
      if (trace.rejectOverwrittenCount < 0xFFFFU) {
        trace.rejectOverwrittenCount++;
      }
      break;
    case DecoderTraceEdgeDecision::Unknown:
      break;
  }

  const size_t nextIndex = trace.edgeCountStored;
  if (nextIndex < kDecoderTraceEdges) {
    trace.edges[nextIndex].tsUs = static_cast<uint32_t>(tsUs);
    trace.edges[nextIndex].ringIndex = ringIndex;
    trace.edges[nextIndex].level = normalizedLevel;
    trace.edges[nextIndex].decision = static_cast<uint8_t>(decision);
    trace.edgeCountStored = static_cast<uint8_t>(nextIndex + 1U);
  }
}

void MachinePhy::rebuildTraceFromRingLocked(DecoderFrameTrace& trace) const {
  if (!trace.valid || trace.firstRingIndex == 0) {
    return;
  }

  trace.edgeCountStored = 0;
  trace.scannedEdgeCount = 0;
  trace.acceptedEdgeCount = 0;
  trace.rejectedEdgeCount = 0;
  trace.collectedEdgeCountTotal = 0;
  trace.collectedEdgeCountInWindow = 0;
  trace.rejectBeforeWindowCount = 0;
  trace.rejectAfterWindowCount = 0;
  trace.rejectDuplicateCount = 0;
  trace.rejectTooCloseCount = 0;
  trace.rejectOverwrittenCount = 0;
  trace.finalizedWithLiveRingTail = false;
  trace.scanStopReason =
      static_cast<uint8_t>(DecoderTraceScanStopReason::Unknown);

  const uint32_t scanFirst = trace.firstRingIndex;
  const uint32_t scanLast = decoderEdgeSequence_;
  trace.ringWriteIndexAtFrameFinalize = scanLast;
  trace.lastRingIndex = scanLast >= scanFirst ? scanLast : scanFirst;
  trace.candidateFinalizeTsUs = trace.traceUpdatedTsUs;

  bool sawOverwritten = false;
  uint32_t latestSeenTs = 0;
  for (uint32_t seq = scanFirst; seq <= scanLast; ++seq) {
    const size_t slot = static_cast<size_t>((seq - 1U) % kRxEdgeRingSize);
    const DecoderEdgeSample& sample = decoderEdgeRing_[slot];
    DecoderTraceEdgeDecision decision = DecoderTraceEdgeDecision::Unknown;
    uint32_t tsUs = 0;
    uint8_t normalizedLevel = 1U;

    if (sample.ringIndex != seq) {
      decision = DecoderTraceEdgeDecision::Overwritten;
      sawOverwritten = true;
      if (trace.rejectedEdgeCount < 0xFFFFU) {
        trace.rejectedEdgeCount++;
      }
      if (trace.rejectOverwrittenCount < 0xFFFFU) {
        trace.rejectOverwrittenCount++;
      }
    } else {
      tsUs = sample.tsUs;
      normalizedLevel = normalizeRxLevel(sample.rawLevel);
      if (tsUs > latestSeenTs) {
        latestSeenTs = tsUs;
      }

      bool matchedAccepted = false;
      for (size_t acceptedIndex = 0; acceptedIndex < candidateEdgeCount_;
           ++acceptedIndex) {
        if (candidateEdges_[acceptedIndex].ringIndex == seq) {
          matchedAccepted = true;
          break;
        }
      }

      if (matchedAccepted) {
        decision = DecoderTraceEdgeDecision::Accepted;
        if (trace.acceptedEdgeCount < 0xFFFFU) {
          trace.acceptedEdgeCount++;
        }
      } else if (tsUs < trace.frameWindowStartUs) {
        decision = DecoderTraceEdgeDecision::BeforeWindow;
        if (trace.rejectedEdgeCount < 0xFFFFU) {
          trace.rejectedEdgeCount++;
        }
        if (trace.rejectBeforeWindowCount < 0xFFFFU) {
          trace.rejectBeforeWindowCount++;
        }
      } else if (tsUs > trace.frameWindowEndUs) {
        decision = DecoderTraceEdgeDecision::AfterWindow;
        if (trace.rejectedEdgeCount < 0xFFFFU) {
          trace.rejectedEdgeCount++;
        }
        if (trace.rejectAfterWindowCount < 0xFFFFU) {
          trace.rejectAfterWindowCount++;
        }
      } else {
        decision = DecoderTraceEdgeDecision::Duplicate;
        if (trace.rejectedEdgeCount < 0xFFFFU) {
          trace.rejectedEdgeCount++;
        }
        if (trace.rejectDuplicateCount < 0xFFFFU) {
          trace.rejectDuplicateCount++;
        }
      }
    }

    if (trace.scannedEdgeCount < 0xFFFFU) {
      trace.scannedEdgeCount++;
    }
    if (trace.edgeCountStored < kDecoderTraceEdges) {
      DecoderTraceEdge& edge = trace.edges[trace.edgeCountStored];
      edge.tsUs = tsUs;
      edge.ringIndex = seq;
      edge.level = normalizedLevel;
      edge.decision = static_cast<uint8_t>(decision);
      trace.edgeCountStored++;
    }
  }

  trace.collectedEdgeCountTotal = trace.scannedEdgeCount;
  const uint32_t inWindow =
      static_cast<uint32_t>(trace.scannedEdgeCount) -
      static_cast<uint32_t>(trace.rejectBeforeWindowCount) -
      static_cast<uint32_t>(trace.rejectAfterWindowCount) -
      static_cast<uint32_t>(trace.rejectOverwrittenCount);
  trace.collectedEdgeCountInWindow = static_cast<uint16_t>(
      inWindow > 0xFFFFU ? 0xFFFFU : inWindow);
  trace.finalizedWithLiveRingTail = true;
  trace.scanStopReason = static_cast<uint8_t>(
      sawOverwritten ? DecoderTraceScanStopReason::RingOverwritten
                     : DecoderTraceScanStopReason::LiveRingTail);
  trace.latestEdgeTsSeenWhenFinalized = latestSeenTs;
}

void MachinePhy::captureBadFrameTraceLocked(DecoderBadReason reason,
                                            unsigned long tsUs,
                                            const uint8_t* sampledBits,
                                            const unsigned long* sampleTsUs,
                                            uint8_t dataByte, bool ninthBit,
                                            uint8_t stopBit,
                                            int32_t phaseErrorUs,
                                            size_t edgeCountUsedForFrame) {
  if (reason == DecoderBadReason::PolarityMismatch ||
      reason == DecoderBadReason::RingOverflow ||
      reason == DecoderBadReason::NoIdleBeforeStart) {
    return;
  }

  syncCurrentCandidateTraceLocked(tsUs);
  DecoderFrameTrace trace = decoderStats_.currentCandidateTrace;
  if (!trace.valid) {
    trace = {};
    trace.valid = true;
    trace.traceGenerationId = ++traceGenerationCounter_;
    trace.candidateStartTsUs =
        candidateStartUs_ != 0 ? static_cast<uint32_t>(candidateStartUs_)
                               : static_cast<uint32_t>(tsUs);
    trace.frameWindowStartUs = trace.candidateStartTsUs > kDecoderIdleStableUs
                                   ? trace.candidateStartTsUs - kDecoderIdleStableUs
                                   : 0U;
    trace.frameWindowEndUs =
        static_cast<uint32_t>(trace.candidateStartTsUs + kDecoderFrameFinalizeUs);
    trace.traceUpdatedTsUs = static_cast<uint32_t>(tsUs);
    trace.initialLevelBeforeStart = candidateInitialLevelBeforeStart_;
  }
  trace.sampledStart = sampledBits != nullptr ? sampledBits[0] : 1U;
  trace.sampledDataByte = dataByte;
  trace.sampledModeBit = ninthBit;
  trace.sampledStopBit = stopBit;
  trace.raw9 = static_cast<uint16_t>(dataByte | (ninthBit ? 0x100U : 0U));
  trace.badReason = static_cast<uint8_t>(reason);
  trace.phaseErrorUs = phaseErrorUs;
  trace.candidateFinalizeTsUs = static_cast<uint32_t>(tsUs);
  trace.idleDurationBeforeStartUs =
      static_cast<uint32_t>(candidateIdleBeforeStartUs_);
  trace.edgeCountUsedForFrame = static_cast<uint8_t>(
      edgeCountUsedForFrame > 0xFF ? 0xFF : edgeCountUsedForFrame);
  if (sampleTsUs != nullptr) {
    trace.frameWindowEndUs =
        static_cast<uint32_t>(sampleTsUs[MachinePhy::kDecoderSampleCount - 1] +
                              kMdbHalfBitUs);
  }
  if (sampledBits != nullptr && sampleTsUs != nullptr) {
    for (size_t i = 0; i < MachinePhy::kDecoderSampleCount; ++i) {
      trace.sampledBits[i] = sampledBits[i];
      trace.sampleTimestampsUs[i] = static_cast<uint32_t>(sampleTsUs[i]);
    }
  }
  rebuildTraceFromRingLocked(trace);
  decoderStats_.lastBadTrace = trace;
  decoderStats_.debugFrameTrace = trace;
}

void MachinePhy::noteBadFrameLocked(DecoderBadReason reason, unsigned long tsUs) {
  switch (reason) {
    case DecoderBadReason::StartBitInvalid:
    case DecoderBadReason::StopBitInvalid:
    case DecoderBadReason::TimingDrift:
    case DecoderBadReason::NoIdleBeforeStart:
    case DecoderBadReason::InsufficientEdgeContext:
      decoderStats_.framingErrorCount++;
      break;
    case DecoderBadReason::PolarityMismatch:
      decoderStats_.polarityMismatchCount++;
      polarityMismatchLatched_ = true;
      break;
    case DecoderBadReason::RingOverflow:
      decoderStats_.ringOverflowCount++;
      break;
    case DecoderBadReason::None:
      break;
  }
  decoderStats_.lastBadReason = static_cast<uint8_t>(reason);
  decoderDebugLastReason_ = static_cast<uint8_t>(reason);
  swDebugResetReason_[0] = static_cast<uint8_t>(reason);
  swDecoderLastActivityUs_[0] = tsUs;
  resetDecoderCandidateLocked();
  decoderState_ = DecoderState::ResyncWaitIdle;
}

void MachinePhy::pushDecodedFrameLocked(const DecoderFrame& frame) {
  const size_t nextWrite =
      (decodedFrameWriteIndex_ + 1U) % kDecodedFrameQueueSize;
  if (nextWrite == decodedFrameReadIndex_) {
    decodedFrameReadIndex_ =
        (decodedFrameReadIndex_ + 1U) % kDecodedFrameQueueSize;
  }
  decodedFrameQueue_[decodedFrameWriteIndex_] = frame;
  decodedFrameWriteIndex_ = nextWrite;
}

bool MachinePhy::popEdgeLocked(unsigned long& tsUs, uint8_t& rawLevel,
                               uint32_t& ringIndex) {
  if (decoderEdgeReadIndex_ == decoderEdgeWriteIndex_) {
    return false;
  }
  const DecoderEdgeSample& sample = decoderEdgeRing_[decoderEdgeReadIndex_];
  tsUs = sample.tsUs;
  rawLevel = sample.rawLevel;
  ringIndex = sample.ringIndex;
  decoderEdgeReadIndex_ = (decoderEdgeReadIndex_ + 1U) % kRxEdgeRingSize;
  return true;
}

void MachinePhy::updateIdleTrackingLocked(unsigned long tsUs,
                                          uint8_t normalizedLevel) {
  const uint8_t previousLevel = normalizedRxLevel_;
  if (previousLevel != normalizedLevel) {
    normalizedRxLevel_ = normalizedLevel;
    normalizedLevelChangedUs_ = tsUs;
  }

  if (normalizedLevel != 0U) {
    if (previousLevel == 0U || idleSinceUs_ == 0) {
      idleSinceUs_ = tsUs;
    }
    lineLowSinceUs_ = 0;
    polarityMismatchLatched_ = false;
    return;
  }

  idleSinceUs_ = 0;
  if (previousLevel != 0U || lineLowSinceUs_ == 0) {
    lineLowSinceUs_ = tsUs;
  }
}

uint8_t MachinePhy::sampleCandidateLevelAtUsLocked(unsigned long sampleTsUs) const {
  uint8_t level = candidateInitialLevelBeforeStart_;
  for (size_t i = 0; i < candidateEdgeCount_; ++i) {
    if (candidateEdges_[i].tsUs > sampleTsUs) {
      break;
    }
    level = candidateEdges_[i].normalizedLevel;
  }
  return level;
}

size_t MachinePhy::reconstructCandidateSamplesLocked(unsigned long* sampleTsUs,
                                                     uint8_t* sampledBits) const {
  if (sampleTsUs == nullptr || sampledBits == nullptr) {
    return 0;
  }

  uint8_t reconstructedLevel = candidateInitialLevelBeforeStart_;
  size_t edgeIndex = 0;
  for (size_t i = 0; i < MachinePhy::kDecoderSampleCount; ++i) {
    while (edgeIndex < candidateEdgeCount_ &&
           candidateEdges_[edgeIndex].tsUs <= sampleTsUs[i]) {
      reconstructedLevel = candidateEdges_[edgeIndex].normalizedLevel;
      ++edgeIndex;
    }
    sampledBits[i] = reconstructedLevel;
  }
  return edgeIndex;
}

void MachinePhy::maybeFinalizeDecoder(unsigned long nowUs) {
  if (decoderState_ != DecoderState::Receiving || candidateStartUs_ == 0 ||
      nowUs < (candidateStartUs_ + kDecoderFrameFinalizeUs)) {
    return;
  }

  unsigned long sampleTsUs[MachinePhy::kDecoderSampleCount] = {};
  uint8_t sampled[MachinePhy::kDecoderSampleCount] = {};
  for (size_t i = 0; i < MachinePhy::kDecoderSampleCount; ++i) {
    const unsigned long nominalOffsetUs =
        (static_cast<unsigned long>(i) * kMdbBitUs) + kMdbHalfBitUs;
    const long correctedSampleUs =
        static_cast<long>(candidateStartUs_) +
        static_cast<long>(nominalOffsetUs) + candidatePhaseCorrectionUs_;
    sampleTsUs[i] = correctedSampleUs > 0 ? static_cast<unsigned long>(correctedSampleUs) : 0UL;
  }
  syncCurrentCandidateTraceLocked(sampleTsUs[MachinePhy::kDecoderSampleCount - 1]);
  const size_t edgeCountUsedForFrame =
      reconstructCandidateSamplesLocked(sampleTsUs, sampled);

  uint8_t dataByte = 0;
  for (size_t i = 0; i < 8; ++i) {
    if (sampled[1 + i] != 0U) {
      dataByte |= static_cast<uint8_t>(1U << i);
    }
  }
  const bool ninthBit = sampled[9] != 0U;
  const bool stopOk = sampled[10] != 0U;

  decoderDebugBitPos_ = 0;
  decoderDebugLastValue_ = dataByte;
  decoderDebugLastNinthBit_ = ninthBit;
  swDebugBitPos_[0] = 0;
  swDebugLastValue_[0] = dataByte;
  swDebugLastNinthBit_[0] = ninthBit;
  swDecoderValue_[0] = dataByte;
  swDecoderNinthBit_[0] = ninthBit;
  swDecoderLastActivityUs_[0] = sampleTsUs[10];

  DecoderBadReason badReason = DecoderBadReason::None;
  if (sampled[0] != 0U) {
    badReason = DecoderBadReason::StartBitInvalid;
  } else if (candidateTimingDrift_) {
    badReason = DecoderBadReason::TimingDrift;
  } else if (!stopOk && edgeCountUsedForFrame <= 1U) {
    badReason = DecoderBadReason::InsufficientEdgeContext;
  } else if (!stopOk) {
    badReason = DecoderBadReason::StopBitInvalid;
  }

  if (badReason != DecoderBadReason::None) {
    captureBadFrameTraceLocked(badReason, sampleTsUs[10], sampled, sampleTsUs,
                               dataByte, ninthBit, sampled[10],
                               candidateWorstPhaseErrorUs_,
                               edgeCountUsedForFrame);
    noteBadFrameLocked(badReason, sampleTsUs[10]);
    return;
  }

  DecoderFrame frame = {};
  frame.dataByte = dataByte;
  frame.ninthBit = ninthBit;
  frame.raw9 = static_cast<uint16_t>(dataByte | (ninthBit ? 0x100U : 0U));
  frame.stopOk = true;
  frame.timestampUs = static_cast<uint32_t>(sampleTsUs[10]);
  frame.valid = true;
  pushDecodedFrameLocked(frame);
  decoderStats_.lastGoodFrame = frame;
  decoderStats_.lastBadReason = static_cast<uint8_t>(DecoderBadReason::None);
  decoderDebugLastReason_ = 0;
  swDebugResetReason_[0] = 0;
  capturedSymbols_[capturedSymbolWriteIndex_].data = frame.raw9;
  capturedSymbols_[capturedSymbolWriteIndex_].timestampUs = frame.timestampUs;
  capturedSymbolWriteIndex_ =
      (capturedSymbolWriteIndex_ + 1U) % kCapturedSymbolHistory;
  if (capturedSymbolWriteIndex_ == 0U) {
    capturedSymbolWrapped_ = true;
  }
  resetDecoderCandidateLocked();
  decoderState_ = decoderIdleStableLocked(nowUs) ? DecoderState::WaitingStart
                                                 : DecoderState::WaitingIdle;
}

void MachinePhy::processDecoderEdge(unsigned long tsUs, uint8_t rawLevel,
                                    uint32_t ringIndex) {
  portENTER_CRITICAL(&stateLock_);
  const uint8_t previewNormalizedLevel = normalizeRxLevel(rawLevel);
  if (decoderState_ == DecoderState::Receiving && candidateStartUs_ != 0 &&
      tsUs > (candidateStartUs_ + kDecoderFrameFinalizeUs)) {
    appendCurrentCandidateTraceEdgeLocked(
        tsUs, previewNormalizedLevel, ringIndex,
        DecoderTraceEdgeDecision::AfterWindow);
  }
  maybeFinalizeDecoder(tsUs);

  const uint8_t previousLevel = normalizedRxLevel_;
  const unsigned long idleBeforeEdgeUs = idleSinceUs_;
  const bool wasIdleStable = decoderIdleStableLocked(tsUs);
  const uint8_t normalizedLevel = previewNormalizedLevel;
  swDebugLastDeltaUs_ = swLastEdgeTsUs_ == 0 ? 0 : (tsUs - swLastEdgeTsUs_);
  swLastEdgeTsUs_ = tsUs;
  updateIdleTrackingLocked(tsUs, normalizedLevel);
  decoderLastActivityUs_ = tsUs;

  if (decoderState_ == DecoderState::ResyncWaitIdle) {
    if (decoderIdleStableLocked(tsUs)) {
      decoderState_ = DecoderState::WaitingStart;
      decoderStats_.resyncCount++;
    }
    portEXIT_CRITICAL(&stateLock_);
    return;
  }

  if (decoderState_ == DecoderState::WaitingIdle &&
      previousLevel != 0U && normalizedLevel == 0U && !wasIdleStable) {
    candidateIdleBeforeStartUs_ =
        idleBeforeEdgeUs != 0 && tsUs >= idleBeforeEdgeUs ? (tsUs - idleBeforeEdgeUs) : 0;
    candidateInitialLevelBeforeStart_ = previousLevel;
    captureBadFrameTraceLocked(DecoderBadReason::NoIdleBeforeStart, tsUs, nullptr,
                               nullptr, 0U, false, 1U, 0, 0);
    noteBadFrameLocked(DecoderBadReason::NoIdleBeforeStart, tsUs);
    portEXIT_CRITICAL(&stateLock_);
    return;
  }

  if (decoderState_ == DecoderState::WaitingIdle && decoderIdleStableLocked(tsUs)) {
    decoderState_ = DecoderState::WaitingStart;
  }

  if (decoderState_ == DecoderState::WaitingStart) {
    if (previousLevel != 0U && normalizedLevel == 0U && wasIdleStable) {
      resetDecoderCandidateLocked();
      candidateStartUs_ = tsUs;
      candidateLastEdgeUs_ = tsUs;
      candidateIdleBeforeStartUs_ =
          idleBeforeEdgeUs != 0 && tsUs >= idleBeforeEdgeUs ? (tsUs - idleBeforeEdgeUs) : 0;
      candidateInitialLevelBeforeStart_ = previousLevel;
      candidateEdges_[0].tsUs = static_cast<uint32_t>(tsUs);
      candidateEdges_[0].ringIndex = ringIndex;
      candidateEdges_[0].normalizedLevel = 0U;
      candidateEdgeCount_ = 1;
      beginCurrentCandidateTraceLocked(tsUs, previousLevel, ringIndex);
      appendCurrentCandidateTraceEdgeLocked(
          tsUs, 0U, ringIndex, DecoderTraceEdgeDecision::Accepted);
      decoderState_ = DecoderState::Receiving;
      swDecoderFraming_[0] = true;
      swDecoderBitPos_[0] = 0;
      swDebugResetReason_[0] = 0;
    } else if (previousLevel != 0U && normalizedLevel == 0U && !wasIdleStable) {
      candidateIdleBeforeStartUs_ =
          idleBeforeEdgeUs != 0 && tsUs >= idleBeforeEdgeUs ? (tsUs - idleBeforeEdgeUs) : 0;
      candidateInitialLevelBeforeStart_ = previousLevel;
      captureBadFrameTraceLocked(DecoderBadReason::NoIdleBeforeStart, tsUs, nullptr,
                                 nullptr, 0U, false, 1U, 0, 0);
      noteBadFrameLocked(DecoderBadReason::NoIdleBeforeStart, tsUs);
    }
    portEXIT_CRITICAL(&stateLock_);
    return;
  }

  if (decoderState_ == DecoderState::Receiving) {
    if (candidateEdgeCount_ >= (sizeof(candidateEdges_) / sizeof(candidateEdges_[0]))) {
      appendCurrentCandidateTraceEdgeLocked(
          tsUs, normalizedLevel, ringIndex,
          DecoderTraceEdgeDecision::Overwritten);
      captureBadFrameTraceLocked(DecoderBadReason::TimingDrift, tsUs, nullptr,
                                 nullptr, swDecoderValue_[0], swDecoderNinthBit_[0],
                                 normalizedLevel, candidateWorstPhaseErrorUs_,
                                 candidateEdgeCount_);
      noteBadFrameLocked(DecoderBadReason::TimingDrift, tsUs);
      portEXIT_CRITICAL(&stateLock_);
      return;
    }

    if (normalizedLevel == previousLevel) {
      candidateTimingDrift_ = true;
      const DecoderTraceEdgeDecision rejectionDecision =
          (candidateLastEdgeUs_ != 0 && (tsUs - candidateLastEdgeUs_) <= kDecoderTooCloseEdgeUs)
              ? DecoderTraceEdgeDecision::TooClose
              : DecoderTraceEdgeDecision::Duplicate;
      appendCurrentCandidateTraceEdgeLocked(
          tsUs, normalizedLevel, ringIndex, rejectionDecision);
    } else if (candidateEdgeCount_ == 1 &&
               normalizedLevel == candidateInitialLevelBeforeStart_ &&
               candidateStartUs_ != 0 &&
               (tsUs - candidateStartUs_) < kMdbBitUs) {
      // Start-bit bounce: the line returned to the pre-start idle level within
      // one bit period while no data-bit edges have been accepted yet.
      // This is RC/capacitance ringing on the RX line, not a real data edge.
      appendCurrentCandidateTraceEdgeLocked(
          tsUs, normalizedLevel, ringIndex, DecoderTraceEdgeDecision::TooClose);
    } else {
      const int32_t correctedDeltaUs =
          static_cast<int32_t>(tsUs - candidateStartUs_) - candidatePhaseCorrectionUs_;
      int32_t nearestBoundaryIndex =
          (correctedDeltaUs >= 0)
              ? ((correctedDeltaUs + static_cast<int32_t>(kMdbHalfBitUs)) /
                 static_cast<int32_t>(kMdbBitUs))
              : ((correctedDeltaUs - static_cast<int32_t>(kMdbHalfBitUs)) /
                 static_cast<int32_t>(kMdbBitUs));
      nearestBoundaryIndex = clampValue<int32_t>(nearestBoundaryIndex, 1, 10);
      const int32_t expectedBoundaryUs =
          static_cast<int32_t>(candidateStartUs_) +
          (nearestBoundaryIndex * static_cast<int32_t>(kMdbBitUs)) +
          candidatePhaseCorrectionUs_;
      const int32_t phaseErrorUs = static_cast<int32_t>(tsUs) - expectedBoundaryUs;
      const int32_t absPhaseErrorUs =
          phaseErrorUs >= 0 ? phaseErrorUs : -phaseErrorUs;
      const int32_t absWorstPhaseErrorUs =
          candidateWorstPhaseErrorUs_ >= 0 ? candidateWorstPhaseErrorUs_
                                           : -candidateWorstPhaseErrorUs_;
      if (absPhaseErrorUs > absWorstPhaseErrorUs) {
        candidateWorstPhaseErrorUs_ = phaseErrorUs;
      }
      if (absPhaseErrorUs > static_cast<int32_t>(kDecoderTimingDriftUs)) {
        candidateTimingDrift_ = true;
      } else if (absPhaseErrorUs <= kDecoderPhaseAdjustWindowUs) {
        candidatePhaseCorrectionUs_ = clampValue<int32_t>(
            candidatePhaseCorrectionUs_ + (phaseErrorUs / 2),
            -kDecoderMaxPhaseCorrectionUs, kDecoderMaxPhaseCorrectionUs);
      }
      candidateEdges_[candidateEdgeCount_].tsUs = tsUs;
      candidateEdges_[candidateEdgeCount_].ringIndex = ringIndex;
      candidateEdges_[candidateEdgeCount_].normalizedLevel = normalizedLevel;
      candidateEdgeCount_++;
      candidateLastEdgeUs_ = tsUs;
      appendCurrentCandidateTraceEdgeLocked(
          tsUs, normalizedLevel, ringIndex,
          DecoderTraceEdgeDecision::Accepted);
      syncCurrentCandidateTraceLocked(tsUs);
      const unsigned long deltaUs = tsUs - candidateStartUs_;
      const unsigned long progressedBits =
          deltaUs > kMdbHalfBitUs ? ((deltaUs - kMdbHalfBitUs) / kMdbBitUs) : 0U;
      const uint8_t bitPos =
          static_cast<uint8_t>(progressedBits > 9U ? 9U : progressedBits);
      decoderDebugBitPos_ = bitPos;
      swDebugBitPos_[0] = bitPos;
    }
  }
  portEXIT_CRITICAL(&stateLock_);
}

void IRAM_ATTR MachinePhy::mdb_rx_isr_edge(uint8_t rawLevel, unsigned long tsUs) {
  BaseType_t higherPriorityTaskWoken = pdFALSE;
  portENTER_CRITICAL_ISR(&stateLock_);
  const size_t nextWrite = (decoderEdgeWriteIndex_ + 1U) % kRxEdgeRingSize;
  if (nextWrite == decoderEdgeReadIndex_) {
    decoderStats_.ringOverflowCount++;
    decoderStats_.lastBadReason =
        static_cast<uint8_t>(DecoderBadReason::RingOverflow);
    decoderDebugLastReason_ =
        static_cast<uint8_t>(DecoderBadReason::RingOverflow);
    swDebugResetReason_[0] =
        static_cast<uint8_t>(DecoderBadReason::RingOverflow);
    resetDecoderCandidateLocked();
    decoderState_ = DecoderState::ResyncWaitIdle;
  } else {
    decoderEdgeRing_[decoderEdgeWriteIndex_].tsUs = static_cast<uint32_t>(tsUs);
    decoderEdgeRing_[decoderEdgeWriteIndex_].ringIndex = ++decoderEdgeSequence_;
    decoderEdgeRing_[decoderEdgeWriteIndex_].rawLevel =
        static_cast<uint8_t>(rawLevel & 0x1U);
    decoderEdgeWriteIndex_ = nextWrite;
  }
  portEXIT_CRITICAL_ISR(&stateLock_);
  if (uartEventTask_ != nullptr) {
    vTaskNotifyGiveFromISR(uartEventTask_, &higherPriorityTaskWoken);
  }
  if (higherPriorityTaskWoken == pdTRUE) {
    portYIELD_FROM_ISR();
  }
}

void MachinePhy::mdb_decoder_process() {
  unsigned long tsUs = 0;
  uint8_t rawLevel = 1;
  uint32_t ringIndex = 0;
  while (true) {
    portENTER_CRITICAL(&stateLock_);
    const bool hasEdge = popEdgeLocked(tsUs, rawLevel, ringIndex);
    portEXIT_CRITICAL(&stateLock_);
    if (!hasEdge) {
      break;
    }
    processDecoderEdge(tsUs, rawLevel, ringIndex);
  }

  const unsigned long nowUs = micros();
  portENTER_CRITICAL(&stateLock_);
  maybeFinalizeDecoder(nowUs);
  if (decoderState_ == DecoderState::ResyncWaitIdle && decoderIdleStableLocked(nowUs)) {
    decoderState_ = DecoderState::WaitingStart;
    decoderStats_.resyncCount++;
  } else if (decoderState_ == DecoderState::WaitingIdle &&
             decoderIdleStableLocked(nowUs)) {
    decoderState_ = DecoderState::WaitingStart;
  }
  if (shouldReportPolarityMismatchLocked(nowUs)) {
    noteBadFrameLocked(DecoderBadReason::PolarityMismatch, nowUs);
  }
  portEXIT_CRITICAL(&stateLock_);
}

bool MachinePhy::mdb_decoder_pop_frame(DecoderFrame& out) {
  portENTER_CRITICAL(&stateLock_);
  if (decodedFrameReadIndex_ == decodedFrameWriteIndex_) {
    portEXIT_CRITICAL(&stateLock_);
    return false;
  }
  out = decodedFrameQueue_[decodedFrameReadIndex_];
  decodedFrameReadIndex_ =
      (decodedFrameReadIndex_ + 1U) % kDecodedFrameQueueSize;
  portEXIT_CRITICAL(&stateLock_);
  return true;
}

void MachinePhy::mdb_decoder_set_inversion(bool enabled) {
  rxInvert_ = enabled;
  const unsigned long nowUs = micros();
  const uint8_t currentRawLevel =
      rxPin_ >= 0
          ? static_cast<uint8_t>(
                gpio_get_level(static_cast<gpio_num_t>(rxPin_)) & 0x1U)
          : 1U;
  portENTER_CRITICAL(&stateLock_);
  resetDecoderRuntimeLocked(nowUs, normalizeRxLevel(currentRawLevel));
  portEXIT_CRITICAL(&stateLock_);
}

MachinePhy::DecoderStats MachinePhy::mdb_decoder_get_stats() const {
  portENTER_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  const DecoderStats stats = decoderStats_;
  portEXIT_CRITICAL(const_cast<portMUX_TYPE*>(&stateLock_));
  return stats;
}

void MachinePhy::setTxObserver(TxObserver observer, void* context) {
  txObserver_ = observer;
  txObserverContext_ = context;
}

void MachinePhy::setFrameObserver(FrameObserver observer, void* context) {
  frameObserver_ = observer;
  frameObserverContext_ = context;
}

void MachinePhy::setStatusObserver(StatusObserver observer, void* context) {
  statusObserver_ = observer;
  statusObserverContext_ = context;
  if (statusObserver_ != nullptr && lastInitError_ != ESP_OK) {
    statusObserver_(statusObserverContext_, "phy_init_error", micros(), 0, 0,
                    static_cast<uint32_t>(lastInitError_));
  }
}

void MachinePhy::uartEventTaskThunk(void* context) {
  if (context == nullptr) {
    vTaskDelete(nullptr);
    return;
  }
  static_cast<MachinePhy*>(context)->uartEventTaskLoop();
}

void IRAM_ATTR MachinePhy::rxGpioIsrThunk(void* context) {
  if (context == nullptr) {
    return;
  }
  MachinePhy* self = static_cast<MachinePhy*>(context);
  const unsigned long tsUs = isrMicros();
  const uint8_t level =
      static_cast<uint8_t>(gpio_get_level(static_cast<gpio_num_t>(kForcedRxPin)) & 0x1U);
  portENTER_CRITICAL_ISR(&self->stateLock_);
  self->rawGpioInterruptCount_++;
  self->recentRxInterruptTsUs_[self->recentRxInterruptWriteIndex_] = tsUs;
  self->recentRxInterruptLevel_[self->recentRxInterruptWriteIndex_] = level;
  self->recentRxInterruptWriteIndex_ =
      (self->recentRxInterruptWriteIndex_ + 1) % kRecentRxInterrupts;
  if (self->recentRxInterruptWriteIndex_ == 0) {
    self->recentRxInterruptWrapped_ = true;
  }
  portEXIT_CRITICAL_ISR(&self->stateLock_);
  self->mdb_rx_isr_edge(level, tsUs);
}

void MachinePhy::uartEventTaskLoop() {
  gpio_reset_pin(kHeartbeatLedPin);
  gpio_set_direction(kHeartbeatLedPin, GPIO_MODE_OUTPUT);
  for (int i = 0; i < 3; ++i) {
    gpio_set_level(kHeartbeatLedPin, 1);
    vTaskDelay(pdMS_TO_TICKS(60));
    gpio_set_level(kHeartbeatLedPin, 0);
    vTaskDelay(pdMS_TO_TICKS(60));
  }
  ESP_LOGI(kPhyLogTag, "UART event task alive on core %ld prio %lu",
           static_cast<long>(xPortGetCoreID()),
           static_cast<unsigned long>(kUartTaskPriority));
  vTaskDelay(pdMS_TO_TICKS(20));
  if (statusObserver_ != nullptr) {
    statusObserver_(statusObserverContext_, "phy_gpio_init_level", micros(),
                    kUartTaskPriority, xPortGetCoreID(),
                    static_cast<uint32_t>(
                        gpio_get_level(static_cast<gpio_num_t>(kForcedRxPin))));
  }
  if (statusObserver_ != nullptr) {
    statusObserver_(statusObserverContext_, "phy_gpio_check", micros(),
                    kUartTaskPriority, xPortGetCoreID(),
                    static_cast<uint32_t>(gpio_get_level(static_cast<gpio_num_t>(kForcedRxPin))));
  }
  gpio_drive_cap_t rxDriveCap = GPIO_DRIVE_CAP_DEFAULT;
  if (gpio_get_drive_capability(static_cast<gpio_num_t>(kForcedRxPin), &rxDriveCap) == ESP_OK &&
      statusObserver_ != nullptr) {
    statusObserver_(statusObserverContext_, "phy_gpio14_drive_capability", micros(),
                    kUartTaskPriority, xPortGetCoreID(),
                    static_cast<uint32_t>(rxDriveCap));
  }
  if (statusObserver_ != nullptr) {
    statusObserver_(statusObserverContext_, "phy_tx_idle_check", micros(),
                    kUartTaskPriority, xPortGetCoreID(),
                    static_cast<uint32_t>(gpio_get_level(static_cast<gpio_num_t>(kForcedTxPin))));
  }
  if (statusObserver_ != nullptr && phyConfigOkPending_ && phyIsReady_) {
    statusObserver_(statusObserverContext_, "phy_config_ok", micros(),
                    kUartTaskPriority, xPortGetCoreID(), 1);
    phyConfigOkPending_ = false;
    lastConfigOkAtMs_ = millis();
  }
  if (statusObserver_ != nullptr) {
    statusObserver_(statusObserverContext_, "phy_task_alive", micros(),
                    kUartTaskPriority, xPortGetCoreID(), phyLoopCounter_);
  }
  if (statusObserver_ != nullptr) {
    statusObserver_(statusObserverContext_, "phy_decoder_mode", micros(),
                    kUartTaskPriority, xPortGetCoreID(), kStrictSoftwareDecoderMode);
  }
  uart_event_t event;
  uint8_t buffer[64];
  while (active_) {
    const unsigned long nowMs = millis();
    DecoderFrame decoded = {};
    DecoderFrame decodedBatch[kDecodedFrameQueueSize] = {};
    size_t decodedBatchLength = 0;
    mdb_decoder_process();
    while (mdb_decoder_pop_frame(decoded)) {
      if (decoded.valid) {
        appendReceivedByte(decoded.dataByte, decoded.ninthBit, decoded.timestampUs,
                           decoded.timestampUs / 1000UL);
        phySawRxByte_ = true;
      }
      if (decodedBatchLength < kDecodedFrameQueueSize) {
        decodedBatch[decodedBatchLength++] = decoded;
      }
    }
    if (rxLength_ > 0 && !hasReadyFrame_ &&
        lastRxByteAtUs_ != 0 && (micros() - lastRxByteAtUs_) >= frameGapUs_) {
      handleRxIdle(millis());
    }
    bool canEmitSoftDiagnostics = false;
    portENTER_CRITICAL(&stateLock_);
    canEmitSoftDiagnostics = rxLength_ == 0;
    portEXIT_CRITICAL(&stateLock_);
    if (statusObserver_ != nullptr && canEmitSoftDiagnostics) {
      for (size_t decodedIndex = 0; decodedIndex < decodedBatchLength; ++decodedIndex) {
        const DecoderFrame& loggedDecoded = decodedBatch[decodedIndex];
        const uint8_t partialByte =
            static_cast<uint8_t>(loggedDecoded.dataByte & 0x1FU);
        const uint32_t tracePacked =
            static_cast<uint32_t>(partialByte) |
            (0UL << 9U) |
            (static_cast<uint32_t>(kStrictSoftwareDecoderMode) << 11U);
        statusObserver_(statusObserverContext_, "phy_soft_bit_trace",
                        loggedDecoded.timestampUs, kUartTaskPriority,
                        xPortGetCoreID(), tracePacked);

        const uint32_t bytePacked =
            static_cast<uint32_t>(loggedDecoded.dataByte) |
            (loggedDecoded.ninthBit ? (1UL << 8U) : 0U) |
            (0UL << 9U) |
            (static_cast<uint32_t>(kStrictSoftwareDecoderMode) << 11U);
        statusObserver_(statusObserverContext_, "phy_soft_byte",
                        loggedDecoded.timestampUs, kUartTaskPriority,
                        xPortGetCoreID(), bytePacked);
      }
    }
    if (statusObserver_ != nullptr && (phyLoopCounter_ % 256U) == 0U) {
      for (size_t i = 0; i < 1; ++i) {
        const uint32_t packed =
            static_cast<uint32_t>(swDebugBitPos_[i]) |
            (static_cast<uint32_t>(swDebugLastValue_[i]) << 8U) |
            (swDebugLastNinthBit_[i] ? (1UL << 16U) : 0U) |
            (static_cast<uint32_t>(swDebugResetReason_[i]) << 17U) |
            (static_cast<uint32_t>(i) << 24U) |
            (static_cast<uint32_t>(activeSoftwareDecoderMode_) << 26U);
        statusObserver_(statusObserverContext_, "phy_decoder_state",
                        micros(), kUartTaskPriority, xPortGetCoreID(), packed);
      }
    }
    ++phyLoopCounter_;
    const uint32_t currentInterruptCount = rawGpioInterruptCount_;
    const int currentBusLevel =
        gpio_get_level(static_cast<gpio_num_t>(kForcedRxPin)) & 0x1U;
    if (statusObserver_ != nullptr &&
        (lastRawEdgeDumpAtMs_ == 0 || (nowMs - lastRawEdgeDumpAtMs_) >= 1000UL)) {
      statusObserver_(statusObserverContext_, "phy_raw_edge_count", micros(),
                      kUartTaskPriority, xPortGetCoreID(), currentInterruptCount);
      lastRawEdgeDumpAtMs_ = nowMs;
    }
    if (currentInterruptCount != lastObservedRawGpioInterruptCount_) {
      lastObservedRawGpioInterruptCount_ = currentInterruptCount;
      lastBusChangeAtMs_ = nowMs;
      reportedBusStuckLevel_ = -1;
    } else if (reportedBusStuckLevel_ != currentBusLevel &&
               (nowMs - lastBusChangeAtMs_) >= 500UL &&
               statusObserver_ != nullptr) {
      statusObserver_(statusObserverContext_, "MDB_BUS_STUCK", micros(),
                      kUartTaskPriority, xPortGetCoreID(),
                      static_cast<uint32_t>(currentBusLevel & 0x1U));
      reportedBusStuckLevel_ = currentBusLevel;
    }
    if (statusObserver_ != nullptr && (phyLoopCounter_ % 512U) == 0U) {
      const uint32_t pinLevel =
          static_cast<uint32_t>(currentBusLevel) & 0x1U;
      const uint32_t packed = (phyLoopCounter_ << 1U) | pinLevel;
      statusObserver_(statusObserverContext_, "phy_task_tick", micros(),
                      kUartTaskPriority, xPortGetCoreID(), packed);
    }
    if (statusObserver_ != nullptr && phyIsReady_ && !phySawRxByte_ &&
        (nowMs - lastConfigOkAtMs_) >= kConfigOkRepeatMs) {
      statusObserver_(statusObserverContext_, "phy_config_ok", micros(),
                      kUartTaskPriority, xPortGetCoreID(), 1);
      statusObserver_(statusObserverContext_, "phy_tx_idle_check", micros(),
                      kUartTaskPriority, xPortGetCoreID(),
                      static_cast<uint32_t>(gpio_get_level(static_cast<gpio_num_t>(kForcedTxPin))));
      lastConfigOkAtMs_ = nowMs;
    }
    if (xQueueReceive(uartEventQueue_, &event, 0) == pdTRUE) {
      switch (event.type) {
        case UART_DATA: {
          int remaining = static_cast<int>(event.size);
          while (remaining > 0) {
            const int chunk = remaining > static_cast<int>(sizeof(buffer))
                                  ? static_cast<int>(sizeof(buffer))
                                  : remaining;
            const int read = uart_read_bytes(kMachineUartNum, buffer, chunk, 0);
            if (read <= 0) {
              if (statusObserver_ != nullptr) {
                statusObserver_(statusObserverContext_, "phy_read_status", micros(),
                                kUartTaskPriority, xPortGetCoreID(),
                                static_cast<uint32_t>(read == 0 ? 0 : 0xFFFFFFFFu));
              }
              break;
            }
            if (statusObserver_ != nullptr) {
              const uint32_t packed =
                  static_cast<uint32_t>(buffer[0]) |
                  (pendingRxAddressBit_ ? (1UL << 8U) : 0UL);
              statusObserver_(statusObserverContext_, "phy_rx_raw_debug", micros(),
                              kUartTaskPriority, xPortGetCoreID(), packed);
            }
            phySawRxByte_ = true;
            pendingRxAddressBit_ = false;
            remaining -= read;
          }
          if (event.timeout_flag) {
            handleRxIdle(millis());
          }
          break;
        }
        case UART_FIFO_OVF:
        case UART_BUFFER_FULL:
          frameOverflowed_ = true;
          uart_flush_input(kMachineUartNum);
          xQueueReset(uartEventQueue_);
          handleRxIdle(millis());
          break;
        case UART_FRAME_ERR:
          if (statusObserver_ != nullptr) {
            size_t bufferedLength = 0;
            uart_get_buffered_data_len(kMachineUartNum, &bufferedLength);
            if (bufferedLength > 0) {
              uint8_t errorByte = 0;
              const int read =
                  uart_read_bytes(kMachineUartNum, &errorByte, 1, pdMS_TO_TICKS(1));
              if (read == 1) {
                statusObserver_(statusObserverContext_, "phy_rx_error_byte", micros(),
                                kUartTaskPriority, xPortGetCoreID(), errorByte);
              }
            }
          }
          if (statusObserver_ != nullptr) {
            statusObserver_(statusObserverContext_, "phy_uart_error", micros(),
                            kUartTaskPriority, xPortGetCoreID(), UART_FRAME_ERR);
          }
          break;
        case UART_PARITY_ERR:
          pendingRxAddressBit_ = true;
          if (statusObserver_ != nullptr) {
            size_t bufferedLength = 0;
            uart_get_buffered_data_len(kMachineUartNum, &bufferedLength);
            if (bufferedLength > 0) {
              uint8_t errorByte = 0;
              const int read =
                  uart_read_bytes(kMachineUartNum, &errorByte, 1, pdMS_TO_TICKS(1));
              if (read == 1) {
                statusObserver_(statusObserverContext_, "phy_rx_error_byte", micros(),
                                kUartTaskPriority, xPortGetCoreID(),
                                static_cast<uint32_t>(errorByte | (1U << 8U)));
              }
            }
          }
          if (statusObserver_ != nullptr) {
            statusObserver_(statusObserverContext_, "phy_uart_error", micros(),
                            kUartTaskPriority, xPortGetCoreID(),
                            static_cast<uint32_t>(UART_PARITY_ERR | (1U << 8U)));
          }
          break;
        default:
          break;
      }
    } else {
      if (continuationActive_ && millis() >= continuationDeadlineAt_) {
        handleRxIdle(millis());
      }
      ulTaskNotifyTake(pdTRUE, pdMS_TO_TICKS(1));
    }
  }
  vTaskDelete(nullptr);
}

void MachinePhy::appendReceivedByte(uint8_t value, bool modeBit,
                                    unsigned long byteNowUs,
                                    unsigned long byteNowMs) {
  bool finalizeImmediate = false;
  bool storeImmediateFrame = false;
  machine::RawByte immediateRaw[2] = {};
  portENTER_CRITICAL(&stateLock_);
  if (rxLength_ < machine::kMaxFrameBytes) {
    machine::RawByte& rawByte = rxBuffer_[rxLength_++];
    rawByte.raw = value;
    rawByte.value7 = value;
    rawByte.highBit = modeBit;
    rawByte.tsMs = byteNowMs;
    rawByte.tsUs = byteNowUs;
    rawByte.gapBeforeMs =
        rxLength_ == 1 ? currentFrameGapBeforeMs_ : (byteNowMs - lastRxByteAt_);
  } else {
    frameOverflowed_ = true;
  }
  lastRxByteAt_ = byteNowMs;
  lastRxByteAtUs_ = byteNowUs;
  if (rxLength_ == 2 && rxBuffer_[0].highBit) {
    const uint8_t commandByte = rxBuffer_[0].value7;
    const uint8_t checksumByte = rxBuffer_[1].value7;
    const uint8_t address = commandByte >> 3U;
    const uint8_t command = commandByte & 0x07U;
    // RESET (cmd=0) must always be handled immediately so ACK is sent within
    // the MDB 5ms response window regardless of pending ready frame state.
    // POLL (cmd=2) also gets the fast path but only when no frame is pending.
    const bool isReset = address == 2U && command == 0U;
    const bool isPoll =
        address == 2U && command == 2U && checksumByte == commandByte;
    finalizeImmediate = isReset || (!hasReadyFrame_ && isPoll);
    if (finalizeImmediate) {
      immediateRaw[0] = rxBuffer_[0];
      immediateRaw[1] = rxBuffer_[1];
      storeImmediateFrame = !hasReadyFrame_;
      rxLength_ = 0;
      frameOverflowed_ = false;
      lastFrameEndedAt_ = byteNowMs;
      currentFrameGapBeforeMs_ = frameGapMs_;
    }
  }
  portEXIT_CRITICAL(&stateLock_);
  if (finalizeImmediate) {
    machine::Frame immediateFrame;
    machine::buildFrame(immediateRaw, 2, immediateFrame);
    immediateFrame.finalizedAtUs = micros();
    immediateFrame.frameGapAfterMs = 0;
    immediateFrame.truncated = false;
    immediateFrame.endReasonCode = 5;
    immediateFrame.rebootGapDetected =
        immediateFrame.frameGapBeforeMs >= kSessionBreakGapMs;
    immediateFrame.sessionBreakGapDetected = immediateFrame.rebootGapDetected;
    if (frameObserver_ != nullptr) {
      frameObserver_(frameObserverContext_, immediateFrame, byteNowMs);
    }
    if (storeImmediateFrame) {
      portENTER_CRITICAL(&stateLock_);
      if (!hasReadyFrame_) {
        readyFrame_ = immediateFrame;
        hasReadyFrame_ = true;
        rxLength_ = 0;
        frameOverflowed_ = false;
        lastFrameEndedAt_ = byteNowMs;
        currentFrameGapBeforeMs_ = frameGapMs_;
      }
      portEXIT_CRITICAL(&stateLock_);
    }
    clearContinuationState();
  }
}

void MachinePhy::handleRxIdle(unsigned long nowMs) {
  portENTER_CRITICAL(&stateLock_);
  const bool skip = !active_ || hasReadyFrame_ || rxLength_ == 0;
  portEXIT_CRITICAL(&stateLock_);
  if (skip) {
    return;
  }

  machine::Frame candidateFrame;
  machine::buildFrame(rxBuffer_, rxLength_, candidateFrame);
  candidateFrame.frameGapAfterMs = nowMs - lastRxByteAt_;
  candidateFrame.truncated = frameOverflowed_;
  candidateFrame.rebootGapDetected = currentFrameGapBeforeMs_ >= kSessionBreakGapMs;
  candidateFrame.sessionBreakGapDetected = candidateFrame.rebootGapDetected;

  if (!continuationActive_ && isTargetPartialCandidate(candidateFrame)) {
    continuationActive_ = true;
    continuationStartedAt_ = nowMs;
    continuationDeadlineAt_ = nowMs + kContinuationWindowMs;
    continuationInitialLength_ = rxLength_;
    return;
  }

  if (continuationActive_ && nowMs < continuationDeadlineAt_) {
    return;
  }

  if (continuationActive_) {
    const size_t appendedBytes =
        rxLength_ > continuationInitialLength_ ? rxLength_ - continuationInitialLength_ : 0;
    const bool continuationSucceeded =
        appendedBytes > 0 && !isTargetPartialCandidate(candidateFrame);
    finalizeFrame(nowMs, continuationSucceeded ? 3 : 4,
                  continuationSucceeded ? 1 : 2,
                  continuationSucceeded ? 0 : (appendedBytes == 0 ? 1 : 2));
    return;
  }

  finalizeFrame(nowMs, frameOverflowed_ ? 2 : 1, 0, 0);
}

void MachinePhy::finalizeFrame(unsigned long now, uint8_t endReasonCode,
                               uint8_t continuationResultCode,
                               uint8_t continuationFailReasonCode) {
  const unsigned long finalizedAtUs = micros();
  machine::buildFrame(rxBuffer_, rxLength_, readyFrame_);
  readyFrame_.finalizedAtUs = finalizedAtUs;
  readyFrame_.frameGapAfterMs = now - lastRxByteAt_;
  readyFrame_.truncated = frameOverflowed_;
  readyFrame_.endReasonCode = endReasonCode;
  readyFrame_.continuationAttempted = continuationActive_;
  readyFrame_.continuationWaitStartedMs = continuationStartedAt_;
  readyFrame_.continuationWaitMs =
      continuationActive_ ? (now - continuationStartedAt_) : 0;
  readyFrame_.continuationAppendedBytes =
      continuationActive_ && rxLength_ > continuationInitialLength_
          ? (rxLength_ - continuationInitialLength_)
          : 0;
  readyFrame_.continuationResultCode = continuationResultCode;
  readyFrame_.continuationFailReasonCode = continuationFailReasonCode;
  readyFrame_.rebootGapDetected = currentFrameGapBeforeMs_ >= kSessionBreakGapMs;
  readyFrame_.sessionBreakGapDetected = readyFrame_.rebootGapDetected;
  if (readyFrame_.truncated) {
    readyFrame_.maybeMerged = true;
    if (readyFrame_.captureQuality > 30) {
      readyFrame_.captureQuality = 30;
    }
  }
  if (readyFrame_.continuationAttempted && !readyFrame_.checksumValid &&
      readyFrame_.continuationAppendedBytes == 0) {
    readyFrame_.maybePartial = true;
  }
  if (frameObserver_ != nullptr) {
    frameObserver_(frameObserverContext_, readyFrame_, now);
  }
  portENTER_CRITICAL(&stateLock_);
  hasReadyFrame_ = true;
  rxLength_ = 0;
  frameOverflowed_ = false;
  lastFrameEndedAt_ = now;
  currentFrameGapBeforeMs_ = frameGapMs_;
  portEXIT_CRITICAL(&stateLock_);
  clearContinuationState();
}

bool MachinePhy::isTargetPartialCandidate(const machine::Frame& frame) const {
  return frame.length == 2 && frame.maybePartial && frame.hasCandidateAddress &&
         frame.candidateAddress == 12 && frame.candidateCommand == 7 &&
         frame.bytes[0].raw == 0xE7 && frame.bytes[1].raw == 0x0F &&
         frame.normalized[0] == 0x67 && frame.normalized[1] == 0x0F;
}

void MachinePhy::clearContinuationState() {
  continuationActive_ = false;
  continuationStartedAt_ = 0;
  continuationDeadlineAt_ = 0;
  continuationInitialLength_ = 0;
}

void MachinePhy::restoreRxParityMode() {
  uart_set_parity(kMachineUartNum, kMdbRxParityMode);
}

// Отправляет ответ периферии: завершающий байт маркируется 9-м битом.
unsigned long MachinePhy::write(const uint8_t* data, size_t length) {
  if (!active_ || data == nullptr || length == 0) {
    return 0;
  }
  const uint32_t frameId = ++txFrameCounter_;
  unsigned long firstTxUs = 0;
  for (size_t i = 0; i < length; ++i) {
    // MDB peripheral responses are data bytes; the master owns address/mode
    // bytes on the bus. Keep the 9th bit low for ACK, status, payload, and
    // checksum bytes.
    const unsigned long txUs = writeSlaveByte(frameId, i, data[i], 0U);
    if (firstTxUs == 0 && txUs != 0) {
      firstTxUs = txUs;
    }
  }
  restoreRxParityMode();
  return firstTxUs;
}

unsigned long MachinePhy::writeSingleByte(uint8_t value, bool ninthBit) {
  if (!active_) {
    return 0;
  }
  const uint32_t frameId = ++txFrameCounter_;
  const unsigned long txUs = writeSlaveByte(frameId, 0, value, ninthBit ? 1U : 0U);
  restoreRxParityMode();
  return txUs;
}

unsigned long MachinePhy::txBitPeriodUs() const {
  if (baudRate_ == 0) {
    return 0;
  }
  return (1000000UL + (baudRate_ / 2UL)) / baudRate_;
}

unsigned long MachinePhy::txCharacterUs() const {
  const unsigned long bitUs = txBitPeriodUs();
  return bitUs == 0 ? 0 : (bitUs * 12UL);
}

unsigned long MachinePhy::writeSlaveByte(uint32_t frameId, size_t byteIndex,
                                         uint8_t value, uint8_t ninthBit) {
  const uint8_t requestedNinthBit = ninthBit != 0U ? 1U : 0U;
  const uint8_t physicalNinthBit =
      kMdbTxParityBitInvert ? static_cast<uint8_t>(requestedNinthBit ^ 0x01U)
                            : requestedNinthBit;
  uart_set_parity(kMachineUartNum,
                  physicalNinthBit != 0U ? parityForNinthBitOne(value)
                                         : parityForNinthBitZero(value));
  const unsigned long txUs = micros();
  uart_write_bytes(kMachineUartNum, reinterpret_cast<const char*>(&value), 1);
  const esp_err_t waitResult =
      uart_wait_tx_done(kMachineUartNum, pdMS_TO_TICKS(4));
  if (waitResult != ESP_OK) {
    delayMicroseconds(static_cast<unsigned int>(kMdbCharacterTxUs));
  }
  if (txObserver_ != nullptr) {
    txObserver_(txObserverContext_, frameId, byteIndex, value, requestedNinthBit,
                txUs);
  }
  return txUs;
}

// Выполняет простой pulse-тест TX-линии для проверки железа.
void MachinePhy::pulseTest(int txPin) {
  activate();
  pinMode(txPin, OUTPUT);
  digitalWrite(txPin, HIGH);
  delay(40);
  digitalWrite(txPin, LOW);
  delay(40);
  digitalWrite(txPin, HIGH);
  delay(40);
  digitalWrite(txPin, LOW);
  activate(true);
}

// Удерживает TX в активном состоянии, чтобы мультиметр успел показать просадку.
void MachinePhy::holdActiveTest(int txPin, unsigned long activeMs) {
  activate();
  pinMode(txPin, OUTPUT);
  digitalWrite(txPin, HIGH);
  delay(activeMs);
  digitalWrite(txPin, LOW);
  activate(true);
}

// Применяет аппаратную инверсию RX/TX для UART2.
void MachinePhy::applyLineInversion() const {
  uint32_t mask = UART_SIGNAL_INV_DISABLE;
  if (rxInvert_) {
    mask |= UART_SIGNAL_RXD_INV;
  }
  if (txInvert_) {
    mask |= UART_SIGNAL_TXD_INV;
  }
  uart_set_line_inverse(kMachineUartNum, mask);
}
