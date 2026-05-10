#include "mdb_service.h"

#include <cstring>
#include <driver/gpio.h>
#include <freertos/task.h>
#include <freertos/portmacro.h>
#include <freertos/semphr.h>

#include "connection_service.h"
#include "logging_utils.h"

// Per-core critical section — disables interrupts on core 0 only.
// Core 1 (Arduino loop, WebSocket, Serial) is completely unaffected.
// Do NOT use vTaskSuspendAll here: it suspends the scheduler on both cores
// and will freeze core 1 if it calls any blocking FreeRTOS API.
static portMUX_TYPE s_mdb_mux = portMUX_INITIALIZER_UNLOCKED;

const char * const MdbService::MANUFACTURER_CYCLE[] = {
  "JOF", "CFM", "MEI", "NRI", "AZK", "TST", "USA", "ESP",
};

// ISR runs on whatever core gpio_install_isr_service was called from (core 1,
// during Arduino setup). Core 1 interrupts are NOT disabled by core 0's
// portENTER_CRITICAL, so this fires freely during frame reads and unblocks
// the pump task via a binary semaphore.
void IRAM_ATTR MdbService::rxEdgeISR(void *arg)
{
  MdbService *self = static_cast<MdbService *>(arg);
  BaseType_t woken = pdFALSE;
  xSemaphoreGiveFromISR(self->rxStartSem_, &woken);
  portYIELD_FROM_ISR(woken);
}

MdbService::MdbService(ConnectionService &connectionService)
    : connectionService_(connectionService)
{
}

void MdbService::begin()
{
  RX_INVERT = false;
  TX_INVERT = true;
  ACK_MODE_BIT = true;
  state_ = ST_INACTIVE;
  justResetPending_ = false;
  cardPresent_ = false;
  cardBalance_ = 0;
  clearRx();
  rxMuteUntilUs_ = 0;
  lastStartUs_ = micros();
  rxInitialized_ = false;
  prevLogical_ = false;
  pinMode(MDB_RX_PIN, INPUT);
  pinMode(MDB_TX_PIN, OUTPUT);
  txIdle();

  if (rxStartSem_ == nullptr)
    rxStartSem_ = xSemaphoreCreateBinary();
  // ESP_ERR_INVALID_STATE is returned if already installed — that is fine.
  gpio_install_isr_service(0);
  gpio_set_intr_type(static_cast<gpio_num_t>(MDB_RX_PIN), GPIO_INTR_ANYEDGE);
  gpio_isr_handler_add(static_cast<gpio_num_t>(MDB_RX_PIN), rxEdgeISR, this);

  active_ = true;
}

void MdbService::startRealtimeRx()
{
  active_ = true;
}

void MdbService::update()
{
  if (active_)
    heartbeat();
}

bool MdbService::shouldReportStatus()
{
  const CashlessState cur = state_;  // volatile read; aligned uint8_t is atomic on LX6
  if (cur != lastReportedState_)
  {
    lastReportedState_ = cur;
    lastStatusReportMs_ = millis();
    return true;
  }
  const uint32_t now = millis();
  if (now - lastStatusReportMs_ >= STATUS_REPORT_INTERVAL_MS)
  {
    lastStatusReportMs_ = now;
    return true;
  }
  return false;
}

bool MdbService::getStatusJson(String &outJson) const
{
  outJson = statusJson();
  return outJson.length() > 0;
}

void MdbService::deactivate()
{
  active_ = false;
  txIdle();
}

void MdbService::start()
{
  state_ = ST_INACTIVE;
  justResetPending_ = false;
  cardPresent_ = false;
  cardBalance_ = 0;
  clearRx();
  rxMuteUntilUs_ = 0;
  lastStartUs_ = micros();
  rxInitialized_ = false;
  prevLogical_ = false;
  cntRxBytes_ = 0;
  cntRxOurFrames_ = 0;
  cntTxBytes_ = 0;
  cntResetReceived_ = 0;
  cntPollReceived_ = 0;
  cntAckSent_ = 0;
  firstByteSeen_ = false;
  firstOurFrameSeen_ = false;
  firstOurFrameCmd_ = 0;
  readerEnabledLogged_ = false;
  lastHeartbeatMs_ = millis();
  lastHeartbeatRxBytes_ = 0;
  lastHeartbeatPolls_ = 0;
  hasPendingLog_ = false;
  lastReportedState_ = static_cast<CashlessState>(0xFF);
  lastStatusReportMs_ = 0;
  txIdle();
  active_ = true;
}

void MdbService::startTask()
{
  if (taskHandle_ != nullptr)
  {
    return;
  }

  taskShouldRun_ = true;
  const BaseType_t result = xTaskCreatePinnedToCore(
      &MdbService::taskEntry,
      "mdb_pump",
      4096,
      this,
      configMAX_PRIORITIES - 2,
      &taskHandle_,
      0);

  if (result != pdPASS)
  {
    taskHandle_ = nullptr;
    taskShouldRun_ = false;
    logSerialLine("[MDB] FAILED to create pump task");
    return;
  }

  logSerialLine(String("[MDB] pump task started on core 0, tick_hz=") +
                configTICK_RATE_HZ);
}

void MdbService::stopTask()
{
  taskShouldRun_ = false;
  if (taskHandle_ != nullptr)
  {
    for (int i = 0; i < 100 && taskHandle_ != nullptr; i++)
    {
      vTaskDelay(pdMS_TO_TICKS(10));
    }
    if (taskHandle_ != nullptr)
    {
      vTaskDelete(taskHandle_);
      taskHandle_ = nullptr;
    }
  }
  logSerialLine("[MDB] pump task stopped");
}

void MdbService::shutdown()
{
  active_ = false;
  txIdle();
}

void MdbService::setHeartbeatEnabled(bool enabled)
{
  heartbeatEnabled_ = enabled;
}

void MdbService::setPeripheralId(const char *manuf3, const char *serial12,
                                  const char *model12, uint8_t verHi, uint8_t verLo)
{
  for (int i = 0; i < 3; i++)
    manufCode_[i] = (manuf3 != nullptr && manuf3[i] != '\0') ? manuf3[i] : ' ';
  manufCode_[3] = '\0';

  for (int i = 0; i < 12; i++)
    serialNumber_[i] = (serial12 != nullptr && serial12[i] != '\0') ? serial12[i] : ' ';
  serialNumber_[12] = '\0';

  for (int i = 0; i < 12; i++)
    modelNumber_[i] = (model12 != nullptr && model12[i] != '\0') ? model12[i] : ' ';
  modelNumber_[12] = '\0';

  swVerHi_ = verHi;
  swVerLo_ = verLo;
}

void MdbService::cycleManufacturerCode()
{
  constexpr size_t kCount = sizeof(MANUFACTURER_CYCLE) / sizeof(MANUFACTURER_CYCLE[0]);
  manufCycleIndex_ = (manufCycleIndex_ + 1) % kCount;
  const char *code = MANUFACTURER_CYCLE[manufCycleIndex_];
  manufCode_[0] = code[0];
  manufCode_[1] = code[1];
  manufCode_[2] = code[2];
  manufCode_[3] = '\0';
  char buf[80];
  snprintf(buf, sizeof(buf),
           "[MDB] manufacturer changed to \"%s\" (%u/%u), restarting handshake",
           code, (unsigned)(manufCycleIndex_ + 1), (unsigned)kCount);
  logSerialLine(buf);
  start();
}

void MdbService::taskEntry(void *arg)
{
  static_cast<MdbService *>(arg)->taskLoop();
}

void MdbService::taskLoop()
{
  while (taskShouldRun_)
  {
    if (active_)
    {
      // Block until RX edge (ISR) or 2 ms timeout. Lets WiFi and other core-0
      // tasks run freely between MDB frames. The 2 ms fallback catches any
      // edge the ISR might miss (e.g., very first idle-state sampling).
      xSemaphoreTake(rxStartSem_, pdMS_TO_TICKS(2));
      pump();
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(10));
    }
  }
  taskHandle_ = nullptr;
  vTaskDelete(nullptr);
}

void MdbService::heartbeat()
{
  if (!heartbeatEnabled_)
    return;
  const uint32_t now = millis();
  if (now - lastHeartbeatMs_ < HEARTBEAT_INTERVAL_MS)
    return;

  const uint32_t rxDelta = cntRxBytes_ - lastHeartbeatRxBytes_;
  const uint32_t pollDelta = cntPollReceived_ - lastHeartbeatPolls_;

  char buf[120];
  snprintf(buf, sizeof(buf),
           "[MDB-HB] state=%s rxBytes=+%lu (total %lu) polls=+%lu ourFrames=%lu",
           stateName(state_),
           (unsigned long)rxDelta,
           (unsigned long)cntRxBytes_,
           (unsigned long)pollDelta,
           (unsigned long)cntRxOurFrames_);
  logSerialLine(buf);

  lastHeartbeatMs_ = now;
  lastHeartbeatRxBytes_ = cntRxBytes_;
  lastHeartbeatPolls_ = cntPollReceived_;
}

bool MdbService::isSafeForOta() const
{
  return !cardPresent_ && state_ != ST_VEND;
}

bool MdbService::emitControlEvent(const char *eventType, const String &details,
                                  String *deliveryMode)
{
  const String deviceId = connectionService_.deviceId();
  String message = String("{\"type\":\"mdb_event\",\"event\":\"") + eventType +
                   "\",\"device_id\":\"" + deviceId + "\",\"details\":" +
                   details + "}";
  Serial.println(message);
  String mode = "serial_only";
  if (connectionService_.isWebSocketConnected())
  {
    mode = connectionService_.sendText(message) ? "serial_and_ws"
                                                : "serial_ws_enqueue_failed";
  }
  if (deliveryMode != nullptr)
  {
    *deliveryMode = mode;
  }
  return true;
}

String MdbService::buildDebugStateJson() const
{
  return statusJson();
}

bool MdbService::readRxLogical() const
{
  const bool raw = digitalRead(MDB_RX_PIN);
  return RX_INVERT ? !raw : raw;
}

void MdbService::writeTxLogical(bool logicalHigh)
{
  const bool gpioLevel = TX_INVERT ? !logicalHigh : logicalHigh;
  digitalWrite(MDB_TX_PIN, gpioLevel ? HIGH : LOW);
}

void MdbService::txIdle()
{
  writeTxLogical(true);
}

void MdbService::queueLog(const char *message)
{
  if (hasPendingLog_ || message == nullptr)
  {
    return;
  }
  strncpy(pendingLog_, message, sizeof(pendingLog_) - 1);
  pendingLog_[sizeof(pendingLog_) - 1] = '\0';
  hasPendingLog_ = true;
}

void MdbService::flushLog()
{
  if (hasPendingLog_)
  {
    Serial.println(pendingLog_);
    hasPendingLog_ = false;
  }
}

void IRAM_ATTR MdbService::sendWord(uint8_t value, bool ninth)
{
  writeTxLogical(false);
  delayMicroseconds(BIT_US);
  for (uint8_t i = 0; i < 8; i++)
  {
    writeTxLogical((value >> i) & 0x01);
    delayMicroseconds(BIT_US);
  }
  writeTxLogical(ninth);
  delayMicroseconds(BIT_US);
  writeTxLogical(true);
  delayMicroseconds(BIT_US);
  cntTxBytes_++;
}

void MdbService::muteRxAfterTx()
{
  rxMuteUntilUs_ = micros() + RX_MUTE_AFTER_TX_US;
}

void MdbService::sendAck()
{
  sendWord(0x00, ACK_MODE_BIT);
  muteRxAfterTx();
  cntAckSent_++;
  queueLog("[TX] ACK");
}

void MdbService::sendNak()
{
  sendWord(0xFF, true);
  muteRxAfterTx();
  queueLog("[TX] NAK");
}

void MdbService::sendDataWithChecksum(const uint8_t *data, size_t len,
                                      const char *label)
{
  uint16_t sum = 0;
  for (size_t i = 0; i < len; i++)
  {
    sum += data[i];
  }
  const uint8_t checksum = static_cast<uint8_t>(sum & 0xFF);
  for (size_t i = 0; i < len; i++)
  {
    sendWord(data[i], false);
  }
  sendWord(checksum, true);
  muteRxAfterTx();
  char buf[80];
  snprintf(buf, sizeof(buf), "[TX] %s", label);
  queueLog(buf);
}

void MdbService::respondJustReset()
{
  static const uint8_t payload[] = {0x00};
  sendDataWithChecksum(payload, sizeof(payload), "JUST_RESET");
  justResetPending_ = false;
}

void MdbService::respondReaderConfig()
{
  const uint8_t payload[] = {0x01, 0x01, 0x00, 0x07, 0x01, 0x02, 0x05, 0x00};
  sendDataWithChecksum(payload, sizeof(payload), "READER_CONFIG");
}

void MdbService::respondPeripheralId()
{
  uint8_t payload[30];
  payload[0] = 0x09;
  for (int i = 0; i < 3; i++)  payload[1 + i]  = manufCode_[i];
  for (int i = 0; i < 12; i++) payload[4 + i]  = serialNumber_[i];
  for (int i = 0; i < 12; i++) payload[16 + i] = modelNumber_[i];
  payload[28] = swVerHi_;
  payload[29] = swVerLo_;
  sendDataWithChecksum(payload, sizeof(payload), "PERIPHERAL_ID");
}

void MdbService::respondBeginSession(uint16_t funds)
{
  const uint8_t payload[] = {0x03, static_cast<uint8_t>((funds >> 8) & 0xFF),
                             static_cast<uint8_t>(funds & 0xFF)};
  sendDataWithChecksum(payload, sizeof(payload), "BEGIN_SESSION");
}

void MdbService::respondVendApproved(uint16_t amount)
{
  const uint8_t payload[] = {0x05, static_cast<uint8_t>((amount >> 8) & 0xFF),
                             static_cast<uint8_t>(amount & 0xFF)};
  sendDataWithChecksum(payload, sizeof(payload), "VEND_APPROVED");
}

void MdbService::respondVendDenied()
{
  const uint8_t payload[] = {0x06};
  sendDataWithChecksum(payload, sizeof(payload), "VEND_DENIED");
}

void MdbService::respondEndSession()
{
  const uint8_t payload[] = {0x07};
  sendDataWithChecksum(payload, sizeof(payload), "END_SESSION");
}

void MdbService::respondCancelled()
{
  const uint8_t payload[] = {0x08};
  sendDataWithChecksum(payload, sizeof(payload), "CANCELLED");
}

const char *MdbService::stateName(CashlessState state) const
{
  switch (state)
  {
  case ST_INACTIVE: return "INACTIVE";
  case ST_DISABLED: return "DISABLED";
  case ST_ENABLED: return "ENABLED";
  case ST_SESSION_IDLE: return "SESSION_IDLE";
  case ST_VEND: return "VEND";
  default: return "?";
  }
}

void MdbService::setState(CashlessState state)
{
  if (state == state_)
    return;
  char buf[80];
  snprintf(buf, sizeof(buf), "[MDB] state %s -> %s", stateName(state_), stateName(state));
  queueLog(buf);
  state_ = state;
}

bool MdbService::checksumOk(const uint8_t *data, size_t len) const
{
  if (len < 2)
  {
    return false;
  }
  uint16_t sum = 0;
  for (size_t i = 0; i < len - 1; i++)
  {
    sum += data[i];
  }
  return (sum & 0xFF) == data[len - 1];
}

void MdbService::handleOurFrame(const uint8_t *data, size_t len)
{
  cntRxOurFrames_++;
  if (len >= 2 && !checksumOk(data, len))
  {
    queueLog("[RX] checksum FAIL");
    return;
  }

  const uint8_t addr = data[0] & MDB_OPCODE_MASK;
  const uint8_t cmd = data[0] & MDB_CMD_MASK;
  if (addr != MDB_ADDR_CASHLESS1)
  {
    return;
  }

  if (!firstOurFrameSeen_)
  {
    firstOurFrameSeen_ = true;
    firstOurFrameCmd_ = data[0];
  }

  switch (cmd)
  {
  case 0x00:
    cntResetReceived_++;
    setState(ST_INACTIVE);
    justResetPending_ = true;
    sendAck();
    break;

  case 0x01:
    if (len < 2)
    {
      sendNak();
    }
    else if (data[1] == 0x00)
    {
      respondReaderConfig();
      if (state_ == ST_INACTIVE)
      {
        setState(ST_DISABLED);
      }
    }
    else if (data[1] == 0x01)
    {
      sendAck();
    }
    else
    {
      sendNak();
    }
    break;

  case 0x02:
    cntPollReceived_++;
    if (justResetPending_)
    {
      respondJustReset();
    }
    else if (state_ == ST_ENABLED && cardPresent_)
    {
      respondBeginSession(cardBalance_);
      setState(ST_SESSION_IDLE);
    }
    else
    {
      sendAck();
    }
    break;

  case 0x03:
    if (len < 2)
    {
      sendNak();
    }
    else if (data[1] == 0x00 && len >= 7)
    {
      const uint16_t price = (static_cast<uint16_t>(data[2]) << 8) | data[3];
      if (state_ != ST_SESSION_IDLE || price > cardBalance_)
      {
        respondVendDenied();
      }
      else
      {
        cardBalance_ -= price;
        respondVendApproved(price);
        setState(ST_VEND);
      }
    }
    else if (data[1] == 0x01)
    {
      respondVendDenied();
    }
    else if (data[1] == 0x02)
    {
      sendAck();
      setState(ST_SESSION_IDLE);
    }
    else if (data[1] == 0x03)
    {
      sendAck();
      setState(ST_SESSION_IDLE);
    }
    else if (data[1] == 0x04)
    {
      respondEndSession();
      cardPresent_ = false;
      setState(ST_ENABLED);
    }
    else if (data[1] == 0x05)
    {
      sendAck();
    }
    else
    {
      sendNak();
    }
    break;

  case 0x04:
  {
    char readerBuf[64];
    snprintf(readerBuf, sizeof(readerBuf),
             "[MDB] READER cmd received sub=%02X len=%u",
             (unsigned)(len >= 2 ? data[1] : 0xFF), (unsigned)len);
    queueLog(readerBuf);

    if (len < 2)
    {
      sendNak();
    }
    else if (data[1] == 0x00)
    {
      sendAck();
      if (state_ == ST_ENABLED || state_ == ST_SESSION_IDLE)
      {
        setState(ST_DISABLED);
      }
    }
    else if (data[1] == 0x01)
    {
      sendAck();
      if (state_ == ST_DISABLED)
      {
        setState(ST_ENABLED);
        queueLog("[!!!] READER LIVE");
        readerEnabledLogged_ = true;
      }
    }
    else if (data[1] == 0x02)
    {
      respondCancelled();
    }
    else
    {
      sendNak();
    }
    break;
  }

  case 0x07:
    if (len >= 2 && data[1] == 0x00)
    {
      respondPeripheralId();
    }
    else
    {
      sendAck();
    }
    break;

  default:
    sendNak();
    break;
  }
}

bool MdbService::readMdbWord(uint8_t &outByte, bool &outNinth)
{
  const uint32_t now = micros();
  if (static_cast<int32_t>(now - rxMuteUntilUs_) < 0)
  {
    return false;
  }
  if (static_cast<uint32_t>(now - lastStartUs_) < MIN_START_GAP_US)
  {
    return false;
  }
  lastStartUs_ = now;
  delayMicroseconds(HALF_BIT_US + BIT_US);

  uint8_t value = 0;
  for (uint8_t i = 0; i < 8; i++)
  {
    if (readRxLogical())
    {
      value |= (1U << i);
    }
    delayMicroseconds(BIT_US);
  }
  const bool ninth = readRxLogical();
  delayMicroseconds(BIT_US);

  outByte = value;
  outNinth = ninth;
  cntRxBytes_++;
  firstByteSeen_ = true;
  return true;
}

void MdbService::clearRx()
{
  rxLen_ = 0;
}

void MdbService::onRxWord(uint8_t value, bool ninth)
{
  if (ninth)
  {
    if (rxLen_ > 0)
    {
      handleOurFrame(rxBuf_, rxLen_);
      clearRx();
    }
    const uint8_t addr = value & MDB_OPCODE_MASK;
    if (addr != MDB_ADDR_CASHLESS1)
    {
      clearRx();
      return;
    }
    rxBuf_[0] = value;
    rxLen_ = 1;
    rxLastByteUs_ = micros();
  }
  else
  {
    if (rxLen_ == 0)
    {
      return;
    }
    if (rxLen_ < sizeof(rxBuf_))
    {
      rxBuf_[rxLen_++] = value;
      rxLastByteUs_ = micros();
    }
    else
    {
      clearRx();
      return;
    }
    if (rxLen_ >= 2 && checksumOk(rxBuf_, rxLen_))
    {
      handleOurFrame(rxBuf_, rxLen_);
      clearRx();
    }
  }
}

void MdbService::pump()
{
  flushLog();
  const bool logical = readRxLogical();
  if (!rxInitialized_)
  {
    prevLogical_ = logical;
    rxInitialized_ = true;
    return;
  }

  if (prevLogical_ != true || logical != false)
  {
    prevLogical_ = logical;
    return;
  }

  // Falling edge detected — receive the whole frame inside one critical section.
  // portENTER_CRITICAL disables interrupts on core 0, prevents WiFi tick preemption between bytes.
  const bool wasFirstByte = firstByteSeen_;
  const bool wasFirstFrame = firstOurFrameSeen_;
  const bool wasReaderEnabled = readerEnabledLogged_;

  portENTER_CRITICAL(&s_mdb_mux);

  uint8_t value = 0;
  bool ninth = false;
  if (readMdbWord(value, ninth))
    onRxWord(value, ninth);

  // Keep reading bytes until frame completes or inter-byte timeout.
  // Interrupts on core 0 remain disabled throughout — prevents WiFi task
  // preemption between bytes. Core 1 is unaffected.
  while (rxLen_ > 0)
  {
    const uint32_t t0 = micros();
    while (readRxLogical())
    {
      if ((uint32_t)(micros() - t0) >= RX_FRAME_TIMEOUT_US)
        break;
    }
    if ((uint32_t)(micros() - t0) >= RX_FRAME_TIMEOUT_US)
    {
      if (rxLen_ >= 2 && checksumOk(rxBuf_, rxLen_))
        handleOurFrame(rxBuf_, rxLen_);
      clearRx();
      break;
    }
    if (readMdbWord(value, ninth))
      onRxWord(value, ninth);
  }

  portEXIT_CRITICAL(&s_mdb_mux);

  if (!wasFirstByte && firstByteSeen_)
    queueLog("[MDB] first byte from VMC seen - bus is active");
  if (!wasFirstFrame && firstOurFrameSeen_)
  {
    char fbuf[80];
    snprintf(fbuf, sizeof(fbuf),
             "[MDB] first frame for 0x10 received (cmd=%02X)", firstOurFrameCmd_);
    queueLog(fbuf);
  }
  if (!wasReaderEnabled && readerEnabledLogged_)
    queueLog("[MDB] *** READER ENABLED - ready for cards ***");

  prevLogical_ = readRxLogical();
}

const char *MdbService::diagnosis() const
{
  if (cntRxBytes_ == 0)
    return "RX silent - check VMC power & RX wiring";
  if (cntRxOurFrames_ == 0)
    return "RX works but no frames for 0x10 - cashless not enabled in VMC menu?";
  if (cntResetReceived_ > 0 && cntPollReceived_ == 0)
    return "VMC sees us RESET arrives but doesn't accept ACK / TX polarity or hardware problem";
  if (cntPollReceived_ > 0)
    return "Handshake progressing";
  return "";
}

void MdbService::setCard(uint16_t amountMinor)
{
  cardBalance_ = amountMinor;
  cardPresent_ = true;
  Serial.print("[CMD] card balance=");
  Serial.println(cardBalance_);
}

void MdbService::removeCard()
{
  cardPresent_ = false;
  cardBalance_ = 0;
  Serial.println("[CMD] removed");
}

void MdbService::reset()
{
  setState(ST_INACTIVE);
  justResetPending_ = true;
  cardPresent_ = false;
  cardBalance_ = 0;
  Serial.println("[CMD] forced INACTIVE");
}

String MdbService::statusJson() const
{
  String json;
  json.reserve(360);
  json = "{\"type\":\"mdb_status\",\"state\":\"";
  json += stateName(state_);
  json += "\",\"justReset\":";
  json += justResetPending_ ? "true" : "false";
  json += ",\"cardPresent\":";
  json += cardPresent_ ? "true" : "false";
  json += ",\"cardBalance\":";
  json += cardBalance_;
  json += ",\"rxInvert\":";
  json += RX_INVERT ? "true" : "false";
  json += ",\"txInvert\":";
  json += TX_INVERT ? "true" : "false";
  json += ",\"ackModeBit\":";
  json += ACK_MODE_BIT ? "true" : "false";
  json += ",\"rxBytes\":";
  json += cntRxBytes_;
  json += ",\"rxOurFrames\":";
  json += cntRxOurFrames_;
  json += ",\"txBytes\":";
  json += cntTxBytes_;
  json += ",\"acksSent\":";
  json += cntAckSent_;
  json += ",\"resetsGot\":";
  json += cntResetReceived_;
  json += ",\"pollsGot\":";
  json += cntPollReceived_;
  json += ",\"diagnosis\":\"";
  json += diagnosis();
  json += "\"}";
  return json;
}

void MdbService::emitStatus()
{
  const String json = statusJson();
  Serial.println(json);
  if (connectionService_.isWebSocketConnected())
  {
    connectionService_.sendText(json);
  }
}

void MdbService::printStatus()
{
  Serial.println("---- STATUS ----");
  Serial.print("state=");
  Serial.println(stateName(state_));
  Serial.print("justReset=");
  Serial.println(justResetPending_ ? "Y" : "N");
  Serial.print("card=");
  Serial.print(cardPresent_ ? "Y" : "N");
  Serial.print(" balance=");
  Serial.println(cardBalance_);
  Serial.print("RX_INVERT=");
  Serial.print(RX_INVERT ? "Y" : "N");
  Serial.print(" TX_INVERT=");
  Serial.print(TX_INVERT ? "Y" : "N");
  Serial.print(" ACK_MODE_BIT=");
  Serial.println(ACK_MODE_BIT ? "1" : "0");
  Serial.println("---- COUNTERS ----");
  Serial.print("RX bytes:    ");
  Serial.println(cntRxBytes_);
  Serial.print("RX our frm:  ");
  Serial.println(cntRxOurFrames_);
  Serial.print("TX bytes:    ");
  Serial.println(cntTxBytes_);
  Serial.print("ACKs sent:   ");
  Serial.println(cntAckSent_);
  Serial.print("RESETs got:  ");
  Serial.println(cntResetReceived_);
  Serial.print("POLLs got:   ");
  Serial.println(cntPollReceived_);
  Serial.println("DIAGNOSIS:");
  Serial.print("  ");
  Serial.println(diagnosis());
  Serial.println("------------------");
}

void MdbService::holdTxLow()
{
  writeTxLogical(false);
  Serial.println("[CMD] TX held LOW. Measure MDB SIGNAL with multimeter (DC).");
}

void MdbService::holdTxHigh()
{
  writeTxLogical(true);
  Serial.println("[CMD] TX held HIGH. Measure MDB SIGNAL with multimeter (DC).");
}

void MdbService::toggleTxInvert()
{
  TX_INVERT = !TX_INVERT;
  txIdle();
  Serial.print("[CMD] TX_INVERT=");
  Serial.println(TX_INVERT ? "Y" : "N");
}

void MdbService::toggleRxInvert()
{
  RX_INVERT = !RX_INVERT;
  Serial.print("[CMD] RX_INVERT=");
  Serial.println(RX_INVERT ? "Y" : "N");
}

void MdbService::setAckMode(bool enabled)
{
  ACK_MODE_BIT = enabled;
  Serial.print("[CMD] ACK_MODE_BIT=");
  Serial.println(ACK_MODE_BIT ? "1" : "0");
}

void MdbService::selfTest()
{
  Serial.println("[SELFTEST] sending 100 alternating bytes (0xAA)...");
  Serial.println("[SELFTEST] measure DC voltage on MDB SIGNAL during this time");
  Serial.println("[SELFTEST] expected: ~half of supply if TX works");
  delay(1000);
  for (int i = 0; i < 100; i++)
  {
    sendWord(0xAA, (i & 1) == 0);
    delay(2);
  }
  txIdle();
  Serial.println("[SELFTEST] done");
}
