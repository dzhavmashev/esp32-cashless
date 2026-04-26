#include "mdb_bitbang_receiver.h"

#include <esp_err.h>
#include <esp_timer.h>

namespace
{
  MdbBitBangReceiver *gReceiver = nullptr;

  uint8_t checksum8(const uint8_t *bytes, size_t length)
  {
    uint16_t sum = 0;
    for (size_t i = 0; i < length; ++i)
    {
      sum += bytes[i];
    }
    return static_cast<uint8_t>(sum & 0xFFU);
  }

  bool isSingleByteControl(uint8_t value)
  {
    return value == 0x00U || value == 0xFFU || value == 0xAAU;
  }

  bool isCompleteMasterFrame(const MdbFrame &frame)
  {
    if (frame.length < 2)
    {
      return false;
    }

    if (!frame.modeBits[0])
    {
      return false;
    }

    for (size_t i = 1; i < frame.length; ++i)
    {
      if (frame.modeBits[i])
      {
        return false;
      }
    }

    uint8_t sum = 0;
    for (size_t i = 0; i + 1 < frame.length; ++i)
    {
      sum = static_cast<uint8_t>(sum + frame.bytes[i]);
    }
    return sum == frame.bytes[frame.length - 1];
  }
} // namespace

MdbBitBangReceiver::MdbBitBangReceiver(gpio_num_t rxPin) : rxPin_(rxPin) {}

bool MdbBitBangReceiver::begin(bool inverted, uint32_t baudRate)
{
  inverted_ = inverted;
  bitTimeUs_ = baudRate == 0 ? 104 : (1000000UL + (baudRate / 2UL)) / baudRate;
  firstSampleUs_ = bitTimeUs_ + (bitTimeUs_ / 2UL);
  sampleToleranceUs_ = bitTimeUs_ / 3UL;
  debounceUs_ = bitTimeUs_ / 3UL;
  frameGapUs_ = kDefaultFrameGapUs;

  wordQueue_ = xQueueCreateStatic(kQueueLength, sizeof(DecodedWord),
                                  wordQueueStorage_, &wordQueueStruct_);
  if (wordQueue_ == nullptr)
  {
    Serial.println("[MDB_RX] queue allocation failed");
    return false;
  }

  gpio_reset_pin(rxPin_);
  gpio_set_direction(rxPin_, GPIO_MODE_INPUT);
  gpio_set_pull_mode(rxPin_, GPIO_PULLUP_ONLY);
  gpio_set_intr_type(rxPin_, GPIO_INTR_ANYEDGE);

  const esp_err_t isrInstall = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
  if (isrInstall != ESP_OK && isrInstall != ESP_ERR_INVALID_STATE)
  {
    Serial.print("[MDB_RX] gpio_install_isr_service failed: ");
    Serial.println(static_cast<int>(isrInstall));
    return false;
  }

  gpio_isr_handler_remove(rxPin_);
  const esp_err_t isrAdd = gpio_isr_handler_add(rxPin_, &gpioIsrThunk, this);
  if (isrAdd != ESP_OK)
  {
    Serial.print("[MDB_RX] gpio_isr_handler_add failed: ");
    Serial.println(static_cast<int>(isrAdd));
    return false;
  }

  timer_ = timerBegin(1, 80, true);
  if (timer_ == nullptr)
  {
    Serial.println("[MDB_RX] timerBegin failed");
    return false;
  }

  gReceiver = this;
  timerAttachInterruptFlag(timer_, &timerIsrThunk, true, ESP_INTR_FLAG_IRAM);
  timerAlarmDisable(timer_);
  timerWrite(timer_, 0);

  rawEdges_ = 0;
  invalidBitTimes_ = 0;
  decodedWords_ = 0;
  frames_ = 0;
  queueOverflows_ = 0;
  receiving_ = false;
  periodicTimerArmed_ = false;
  sampleIndex_ = 0;
  sampledWord_ = 0;
  lastEdgeAtUs_ = 0;
  resetFrame();

  Serial.println("[MDB_RX] bit-bang receiver started");
  Serial.print("[MDB_RX] gpio=");
  Serial.print(static_cast<int>(rxPin_));
  Serial.print(" baud=");
  Serial.print(baudRate);
  Serial.print(" bit_us=");
  Serial.print(bitTimeUs_);
  Serial.print(" inverted=");
  Serial.println(inverted_ ? "true" : "false");
  return true;
}

void MdbBitBangReceiver::update()
{
  if (wordQueue_ != nullptr)
  {
    DecodedWord word;
    while (xQueueReceive(wordQueue_, &word, 0) == pdTRUE)
    {
      processWord(word);
    }
  }

  if (currentFrame_.length > 0 && lastWordAtUs_ != 0)
  {
    const uint32_t nowUs = static_cast<uint32_t>(esp_timer_get_time());
    if (nowUs - lastWordAtUs_ >= frameGapUs_)
    {
      finalizeFrame();
    }
  }
}

void MdbBitBangReceiver::printDiagnostics()
{
  const uint32_t nowMs = millis();
  if (nowMs - lastDiagAtMs_ < 1000UL)
  {
    return;
  }
  lastDiagAtMs_ = nowMs;

  Serial.print("[MDB_DIAG] phys=");
  Serial.print(physicalLevel());
  Serial.print(" logical=");
  Serial.print(logicalLevel());
  Serial.print(" raw_edges=");
  Serial.print(rawEdges());
  Serial.print(" invalid_bit_times=");
  Serial.print(invalidBitTimes());
  Serial.print(" decoded_words=");
  Serial.print(decodedWords());
  Serial.print(" frames=");
  Serial.print(frames());
  Serial.print(" queue_overflows=");
  Serial.println(static_cast<uint32_t>(queueOverflows_));
}

uint32_t MdbBitBangReceiver::rawEdges() const { return rawEdges_; }

uint32_t MdbBitBangReceiver::invalidBitTimes() const
{
  return invalidBitTimes_;
}

uint32_t MdbBitBangReceiver::decodedWords() const { return decodedWords_; }

uint32_t MdbBitBangReceiver::frames() const { return frames_; }

uint32_t MdbBitBangReceiver::queueOverflows() const { return queueOverflows_; }

int MdbBitBangReceiver::physicalLevel() const
{
  return gpio_get_level(rxPin_);
}

int MdbBitBangReceiver::logicalLevel() const
{
  return physicalToLogical(static_cast<uint8_t>(physicalLevel())) ? 1 : 0;
}

void IRAM_ATTR MdbBitBangReceiver::gpioIsrThunk(void *arg)
{
  auto *receiver = static_cast<MdbBitBangReceiver *>(arg);
  if (receiver == nullptr)
  {
    return;
  }
  const uint32_t nowUs = static_cast<uint32_t>(esp_timer_get_time());
  const uint8_t level =
      static_cast<uint8_t>(gpio_get_level(receiver->rxPin_) & 0x1U);
  receiver->handleGpioEdgeIsr(nowUs, level);
}

void IRAM_ATTR MdbBitBangReceiver::timerIsrThunk()
{
  if (gReceiver != nullptr)
  {
    gReceiver->handleTimerIsr();
  }
}

void IRAM_ATTR MdbBitBangReceiver::handleGpioEdgeIsr(uint32_t nowUs,
                                                     uint8_t physicalLevel)
{
  rawEdges_++;

  const uint32_t previousEdgeUs = lastEdgeAtUs_;
  lastEdgeAtUs_ = nowUs;
  if (previousEdgeUs != 0)
  {
    const uint32_t deltaUs = nowUs - previousEdgeUs;
    if (deltaUs < debounceUs_ || !edgeDeltaLooksLikeBitTime(deltaUs))
    {
      invalidBitTimes_++;
    }
  }

  if (receiving_)
  {
    return;
  }

  // MDB idle is logical 1. Start bit is logical 0. With the optocoupler
  // inversion in this device, physical idle is 0 and start is usually 1.
  if (physicalToLogical(physicalLevel))
  {
    return;
  }

  const uint32_t guardUntilUs = nowUs + kStartGuardUs;
  while (static_cast<int32_t>(
             static_cast<uint32_t>(esp_timer_get_time()) - guardUntilUs) < 0)
  {
  }

  const uint8_t guardedPhysical =
      static_cast<uint8_t>(gpio_get_level(rxPin_) & 0x1U);
  if (physicalToLogical(guardedPhysical))
  {
    invalidBitTimes_++;
    return;
  }

  portENTER_CRITICAL_ISR(&isrMux_);
  receiving_ = true;
  periodicTimerArmed_ = false;
  sampleIndex_ = 0;
  sampledWord_ = 0;
  wordStartedAtUs_ = nowUs;
  portEXIT_CRITICAL_ISR(&isrMux_);

  const uint32_t firstTargetUs = nowUs + firstSampleUs_;
  const uint32_t nowAfterGuardUs = static_cast<uint32_t>(esp_timer_get_time());
  const uint32_t delayUs =
      firstTargetUs > nowAfterGuardUs ? firstTargetUs - nowAfterGuardUs : 1UL;
  armTimer(delayUs, false);
}

void IRAM_ATTR MdbBitBangReceiver::handleTimerIsr()
{
  if (!receiving_)
  {
    timerAlarmDisable(timer_);
    return;
  }

  const uint8_t index = sampleIndex_;
  const uint8_t physical =
      static_cast<uint8_t>(gpio_get_level(rxPin_) & 0x1U);
  const bool bit = physicalToLogical(physical);

  if (index < kDataBits)
  {
    if (bit)
    {
      sampledWord_ |= static_cast<uint16_t>(1U << index);
    }
  }
  else if (index == kModeBitIndex)
  {
    if (bit)
    {
      sampledWord_ |= static_cast<uint16_t>(1U << kModeBitIndex);
    }
  }
  else if (index == kStopBitIndex)
  {
    if (!bit)
    {
      invalidBitTimes_++;
    }
  }

  if (index == 0 && !periodicTimerArmed_)
  {
    periodicTimerArmed_ = true;
    armTimer(bitTimeUs_, true);
  }

  sampleIndex_ = static_cast<uint8_t>(index + 1U);
  if (sampleIndex_ < kSamplesPerWord)
  {
    return;
  }

  timerAlarmDisable(timer_);
  timerWrite(timer_, 0);

  DecodedWord word;
  word.value = static_cast<uint8_t>(sampledWord_ & 0xFFU);
  word.mode = ((sampledWord_ >> kModeBitIndex) & 0x1U) != 0;
  word.stopOk = bit;
  word.startedAtUs = wordStartedAtUs_;
  word.completedAtUs =
      wordStartedAtUs_ + firstSampleUs_ +
      (static_cast<uint32_t>(kStopBitIndex) * bitTimeUs_);

  decodedWords_++;

  BaseType_t higherPriorityTaskWoken = pdFALSE;
  if (wordQueue_ != nullptr &&
      xQueueSendFromISR(wordQueue_, &word, &higherPriorityTaskWoken) != pdTRUE)
  {
    queueOverflows_++;
  }

  receiving_ = false;
  periodicTimerArmed_ = false;
  sampleIndex_ = 0;
  sampledWord_ = 0;

  if (higherPriorityTaskWoken == pdTRUE)
  {
    portYIELD_FROM_ISR();
  }
}

bool IRAM_ATTR MdbBitBangReceiver::physicalToLogical(
    uint8_t physicalLevel) const
{
  const bool physicalHigh = (physicalLevel & 0x1U) != 0;
  return inverted_ ? !physicalHigh : physicalHigh;
}

bool IRAM_ATTR MdbBitBangReceiver::edgeDeltaLooksLikeBitTime(
    uint32_t deltaUs) const
{
  for (uint8_t bits = 1; bits <= 12; ++bits)
  {
    const uint32_t targetUs = bitTimeUs_ * bits;
    const uint32_t diffUs =
        deltaUs > targetUs ? deltaUs - targetUs : targetUs - deltaUs;
    if (diffUs <= sampleToleranceUs_)
    {
      return true;
    }
  }
  return false;
}

void IRAM_ATTR MdbBitBangReceiver::armTimer(uint32_t delayUs,
                                            bool autoreload)
{
  timerWrite(timer_, 0);
  timerAlarmWrite(timer_, delayUs == 0 ? 1 : delayUs, autoreload);
  timerAlarmEnable(timer_);
}

void MdbBitBangReceiver::processWord(const DecodedWord &word)
{
  if (word.mode && currentFrame_.length > 0)
  {
    finalizeFrame();
  }

  if (currentFrame_.length == 0)
  {
    currentFrame_.startedAtUs = word.startedAtUs;
  }

  if (currentFrame_.length >= MdbFrame::kMaxBytes)
  {
    finalizeFrame();
    currentFrame_.startedAtUs = word.startedAtUs;
  }

  const size_t index = currentFrame_.length++;
  currentFrame_.bytes[index] = word.value;
  currentFrame_.modeBits[index] = word.mode;
  currentFrame_.endedAtUs = word.completedAtUs;
  lastWordAtUs_ = word.completedAtUs;

  // Single-byte control replies from VMC should not wait the long frame gap.
  if (currentFrame_.length == 1 && isSingleByteControl(currentFrame_.bytes[0]))
  {
    finalizeFrame();
    return;
  }

  // Fast responder path:
  // finalize valid master frames immediately instead of waiting frameGapUs_.
  if (isCompleteMasterFrame(currentFrame_))
  {
    finalizeFrame();
    return;
  }
}

void MdbBitBangReceiver::finalizeFrame()
{
  if (currentFrame_.length == 0)
  {
    return;
  }

  if (currentFrame_.length == 1)
  {
    if (!isSingleByteControl(currentFrame_.bytes[0]))
    {
      resetFrame();
      return;
    }
    currentFrame_.checksumOk = true;
    currentFrame_.checksumExpected = currentFrame_.bytes[0];
    currentFrame_.checksumActual = currentFrame_.bytes[0];
  }
  else
  {
    currentFrame_.checksumExpected =
        checksum8(currentFrame_.bytes, currentFrame_.length - 1);
    currentFrame_.checksumActual = currentFrame_.bytes[currentFrame_.length - 1];
    currentFrame_.checksumOk =
        currentFrame_.checksumExpected == currentFrame_.checksumActual;
  }

  frames_++;
  handleMdbFrame(currentFrame_);
  resetFrame();
}

void MdbBitBangReceiver::resetFrame()
{
  currentFrame_ = {};
  lastWordAtUs_ = 0;
}

void MdbBitBangReceiver::printHex(const uint8_t *bytes, size_t length) const
{
  for (size_t i = 0; i < length; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }
    if (bytes[i] < 0x10)
    {
      Serial.print('0');
    }
    Serial.print(bytes[i], HEX);
  }
}

void __attribute__((weak)) handleMdbFrame(const MdbFrame &frame)
{
  Serial.print("[MDB] ");
  Serial.print(frame.checksumOk ? "OK" : "BAD_CHECKSUM");
  Serial.print(" len=");
  Serial.print(frame.length);
  Serial.print(" mode=");
  for (size_t i = 0; i < frame.length; ++i)
  {
    Serial.print(frame.modeBits[i] ? '1' : '0');
  }

  Serial.print(" full=");
  for (size_t i = 0; i < frame.length; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }
    if (frame.bytes[i] < 0x10)
    {
      Serial.print('0');
    }
    Serial.print(frame.bytes[i], HEX);
  }

  Serial.print(" payload=");
  const size_t payloadLength = frame.length > 1 ? frame.length - 1 : frame.length;
  for (size_t i = 0; i < payloadLength; ++i)
  {
    if (i != 0)
    {
      Serial.print(' ');
    }
    if (frame.bytes[i] < 0x10)
    {
      Serial.print('0');
    }
    Serial.print(frame.bytes[i], HEX);
  }

  if (frame.length > 1)
  {
    Serial.print(" checksum_expected=");
    if (frame.checksumExpected < 0x10)
    {
      Serial.print('0');
    }
    Serial.print(frame.checksumExpected, HEX);
    Serial.print(" checksum_actual=");
    if (frame.checksumActual < 0x10)
    {
      Serial.print('0');
    }
    Serial.print(frame.checksumActual, HEX);
  }

  Serial.println();
}
