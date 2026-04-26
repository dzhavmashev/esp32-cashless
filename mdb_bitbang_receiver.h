#pragma once

#include <Arduino.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>

struct MdbFrame {
  static constexpr size_t kMaxBytes = 40;

  uint8_t bytes[kMaxBytes] = {};
  bool modeBits[kMaxBytes] = {};
  size_t length = 0;
  bool checksumOk = false;
  uint8_t checksumExpected = 0;
  uint8_t checksumActual = 0;
  uint32_t startedAtUs = 0;
  uint32_t endedAtUs = 0;
};

// Default frame handler. Define your own non-weak function with the same
// signature if you want to route frames somewhere else.
void handleMdbFrame(const MdbFrame& frame);

class MdbBitBangReceiver {
 public:
  explicit MdbBitBangReceiver(gpio_num_t rxPin = GPIO_NUM_14);

  bool begin(bool inverted = true, uint32_t baudRate = 9600);
  void update();
  void printDiagnostics();

  uint32_t rawEdges() const;
  uint32_t invalidBitTimes() const;
  uint32_t decodedWords() const;
  uint32_t frames() const;
  uint32_t queueOverflows() const;
  int physicalLevel() const;
  int logicalLevel() const;

 private:
  struct DecodedWord {
    uint8_t value = 0;
    bool mode = false;
    bool stopOk = false;
    uint32_t startedAtUs = 0;
    uint32_t completedAtUs = 0;
  };

  static constexpr uint8_t kDataBits = 8;
  static constexpr uint8_t kModeBitIndex = 8;
  static constexpr uint8_t kStopBitIndex = 9;
  static constexpr uint8_t kSamplesPerWord = 10;
  static constexpr size_t kQueueLength = 32;
  static constexpr uint32_t kDefaultFrameGapUs = 5000;
  static constexpr uint32_t kStartGuardUs = 24;

  static void IRAM_ATTR gpioIsrThunk(void* arg);
  static void IRAM_ATTR timerIsrThunk();

  void IRAM_ATTR handleGpioEdgeIsr(uint32_t nowUs, uint8_t physicalLevel);
  void IRAM_ATTR handleTimerIsr();

  bool IRAM_ATTR physicalToLogical(uint8_t physicalLevel) const;
  bool IRAM_ATTR edgeDeltaLooksLikeBitTime(uint32_t deltaUs) const;
  void IRAM_ATTR armTimer(uint32_t delayUs, bool autoreload);
  void processWord(const DecodedWord& word);
  void finalizeFrame();
  void resetFrame();
  void printHex(const uint8_t* bytes, size_t length) const;

  gpio_num_t rxPin_;
  bool inverted_ = true;
  uint32_t bitTimeUs_ = 104;
  uint32_t firstSampleUs_ = 156;
  uint32_t sampleToleranceUs_ = 34;
  uint32_t debounceUs_ = 35;
  uint32_t frameGapUs_ = kDefaultFrameGapUs;

  hw_timer_t* timer_ = nullptr;
  QueueHandle_t wordQueue_ = nullptr;
  StaticQueue_t wordQueueStruct_ = {};
  uint8_t wordQueueStorage_[kQueueLength * sizeof(DecodedWord)] = {};

  volatile bool receiving_ = false;
  volatile bool periodicTimerArmed_ = false;
  volatile uint8_t sampleIndex_ = 0;
  volatile uint16_t sampledWord_ = 0;
  volatile uint32_t wordStartedAtUs_ = 0;
  volatile uint32_t lastEdgeAtUs_ = 0;
  volatile uint32_t rawEdges_ = 0;
  volatile uint32_t invalidBitTimes_ = 0;
  volatile uint32_t decodedWords_ = 0;
  volatile uint32_t frames_ = 0;
  volatile uint32_t queueOverflows_ = 0;

  MdbFrame currentFrame_ = {};
  uint32_t lastWordAtUs_ = 0;
  uint32_t lastDiagAtMs_ = 0;

  portMUX_TYPE isrMux_ = portMUX_INITIALIZER_UNLOCKED;
};
