#pragma once

#include <Arduino.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "mdb_settings_store.h"

class ConnectionService;

class MdbService
{
public:
  explicit MdbService(ConnectionService &connectionService);

  void begin();
  void startRealtimeRx();
  void start();
  void startTask();
  void stopTask();
  void shutdown();
  void update();
  void deactivate();

  bool isSafeForOta() const;
  bool emitControlEvent(const char *eventType, const String &details,
                        String *deliveryMode = nullptr);
  String buildDebugStateJson() const;

  // Called from core 1 (main loop READY phase). Thread-safe: reads volatile state_.
  bool shouldReportStatus();
  bool getStatusJson(String &outJson) const;

  void setCard(uint16_t amountMinor);
  void removeCard();
  void reset();
  void printStatus();
  String statusJson() const;
  void emitStatus();
  void holdTxLow();
  void holdTxHigh();
  void txIdle();
  void toggleTxInvert();
  void toggleRxInvert();
  void setAckMode(bool enabled);
  void selfTest();
  void setHeartbeatEnabled(bool enabled);

  void setPeripheralId(const char *manuf3, const char *serial12,
                       const char *model12, uint8_t verHi, uint8_t verLo);
  void setSettings(const MdbSettingsStore::Settings &s);
  void reportSettingsApplied(const MdbSettingsStore::Settings &s,
                             const char *source);

private:
  static constexpr int MDB_RX_PIN = 14;
  static constexpr int MDB_TX_PIN = 19;
  static constexpr uint16_t BIT_US = 104;
  static constexpr uint16_t HALF_BIT_US = 52;
  static constexpr uint32_t RX_MUTE_AFTER_TX_US = 1500;
  static constexpr uint32_t MIN_START_GAP_US = 650;
  static constexpr uint32_t RX_FRAME_TIMEOUT_US = 5000;
  static constexpr uint8_t MDB_ADDR_CASHLESS1 = 0x10;
  static constexpr uint8_t MDB_OPCODE_MASK = 0xF8;
  static constexpr uint8_t MDB_CMD_MASK = 0x07;

  enum CashlessState : uint8_t
  {
    ST_INACTIVE = 0,
    ST_DISABLED,
    ST_ENABLED,
    ST_SESSION_IDLE,
    ST_VEND,
  };

  bool readRxLogical() const;
  void writeTxLogical(bool logicalHigh);
  void queueLog(const char *message);
  void flushLog();
  void heartbeat();
  void sendWord(uint8_t value, bool ninth);
  void muteRxAfterTx();
  void sendAck();
  void sendNak();
  void sendDataWithChecksum(const uint8_t *data, size_t len,
                            const char *label);
  void respondJustReset();
  void respondReaderConfig();
  void respondPeripheralId();
  void respondBeginSession(uint16_t funds);
  void respondVendApproved(uint16_t amount);
  void respondVendDenied();
  void respondEndSession();
  void respondCancelled();
  const char *stateName(CashlessState state) const;
  void setState(CashlessState state);
  bool checksumOk(const uint8_t *data, size_t len) const;
  void handleOurFrame(const uint8_t *data, size_t len);
  bool readMdbWord(uint8_t &outByte, bool &outNinth);
  void clearRx();
  void onRxWord(uint8_t value, bool ninth);
  void pump();
  const char *diagnosis() const;
  static void taskEntry(void *arg);
  void taskLoop();
  static void IRAM_ATTR rxEdgeISR(void *arg);

  ConnectionService &connectionService_;
  volatile bool active_ = true;
  TaskHandle_t taskHandle_ = nullptr;
  volatile bool taskShouldRun_ = false;
  SemaphoreHandle_t rxStartSem_ = nullptr;

  volatile bool RX_INVERT = false;
  volatile bool TX_INVERT = true;
  volatile bool ACK_MODE_BIT = true;

  volatile CashlessState state_ = ST_INACTIVE;
  bool justResetPending_ = false;
  bool cardPresent_ = false;
  uint16_t cardBalance_ = 0;

  char manufCode_[4]     = {'E', 'S', 'P', '\0'};
  char serialNumber_[13] = {'0','0','0','0','0','0','0','0','0','0','0','1','\0'};
  char modelNumber_[13]  = {'M','D','B','-','C','A','S','H','L','E','S','S','\0'};
  uint8_t swVerHi_ = 0x00;
  uint8_t swVerLo_ = 0x01;
  uint8_t featureLevel_ = 1;
  uint16_t countryCode_ = 7;
  uint8_t scaleFactor_ = 1;
  uint8_t decimalPlaces_ = 2;
  uint8_t maxResponseSec_ = 5;

  uint8_t rxBuf_[36] = {};
  size_t rxLen_ = 0;
  uint32_t rxLastByteUs_ = 0;
  uint32_t rxMuteUntilUs_ = 0;
  uint32_t lastStartUs_ = 0;
  bool rxInitialized_ = false;
  bool prevLogical_ = false;

  uint32_t cntRxBytes_ = 0;
  uint32_t cntRxOurFrames_ = 0;
  uint32_t cntTxBytes_ = 0;
  uint32_t cntResetReceived_ = 0;
  uint32_t cntPollReceived_ = 0;
  uint32_t cntAckSent_ = 0;

  static constexpr uint32_t HEARTBEAT_INTERVAL_MS = 5000;
  static constexpr uint32_t STATUS_REPORT_INTERVAL_MS = 60000;

  CashlessState lastReportedState_ = static_cast<CashlessState>(0xFF);
  uint32_t lastStatusReportMs_ = 0;

  bool firstByteSeen_ = false;
  bool firstOurFrameSeen_ = false;
  uint8_t firstOurFrameCmd_ = 0;
  bool readerEnabledLogged_ = false;
  bool heartbeatEnabled_ = true;
  uint32_t lastHeartbeatMs_ = 0;
  uint32_t lastHeartbeatRxBytes_ = 0;
  uint32_t lastHeartbeatPolls_ = 0;

  char pendingLog_[80] = {};
  volatile bool hasPendingLog_ = false;
};
