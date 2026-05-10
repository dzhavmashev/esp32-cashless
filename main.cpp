#include <Arduino.h>
#include <esp_system.h>
#include <driver/gpio.h>
#include <string.h>

#include "device_config.h"
#include "command_service.h"
#include "connection_service.h"
#include "firmware_version.h"
#include "logging_utils.h"
#include "mdb_service.h"
#include "ota_manager.h"
#include "pulse_config_service.h"
#include "pulse_service.h"
#include "status_leds.h"

namespace
{
  PulseService pulseService;
  ConnectionService connectionService;
  MdbService mdbService(connectionService);
  OtaManager otaService(connectionService);
  PulseConfigService pulseConfigService(connectionService, pulseService);
  CommandService commandService(pulseService, mdbService, pulseConfigService,
                                otaService);
  StatusLeds statusLeds;
  esp_reset_reason_t bootResetReason = ESP_RST_UNKNOWN;
  bool deviceInfoSentForCurrentWsSession = false;
  constexpr size_t kSerialCommandBufferSize = 192;
  char serialCommandBuffer[kSerialCommandBufferSize] = {};
  size_t serialCommandLength = 0;

  enum class BootPhase : uint8_t
  {
    WIFI_CONNECTING,
    WS_CONNECTING,
    DEVICE_REGISTERING,
    FETCHING_CONFIGS,
    READY
  };
  BootPhase bootPhase = BootPhase::WIFI_CONNECTING;
  uint32_t fetchingConfigsEnteredAt = 0;

  const char* resetReasonToString(esp_reset_reason_t reason);
  void handleSerialConsole();
  void dispatchSerialConsoleLine(const String& line);
  void dispatchSerialCommand(const String& command,
                             const String& payloadJson = "{}");
  void printSerialConsoleHelp();
  void sendDeviceInfoIfNeeded();

  static uint32_t cashCtrlParseU32Token(const String& source, int index,
                                        uint32_t fallback)
  {
    int start = 0;
    int tokenIndex = 0;
    while (start < (int)source.length())
    {
      while (start < (int)source.length() && source[start] == ' ')
        start++;
      if (start >= (int)source.length())
        break;
      int end = source.indexOf(' ', start);
      if (end < 0)
        end = source.length();
      if (tokenIndex == index)
        return static_cast<uint32_t>(source.substring(start, end).toInt());
      tokenIndex++;
      start = end + 1;
    }
    return fallback;
  }

  static String parseStrToken(const String& source, int index)
  {
    int start = 0;
    int tokenIndex = 0;
    while (start < (int)source.length())
    {
      while (start < (int)source.length() && source[start] == ' ')
        start++;
      if (start >= (int)source.length())
        break;
      int end = source.indexOf(' ', start);
      if (end < 0)
        end = source.length();
      if (tokenIndex == index)
        return source.substring(start, end);
      tokenIndex++;
      start = end + 1;
    }
    return String();
  }

  static int cashAcceptorCtrlActiveLevel()
  {
    return CASH_ACCEPTOR_CTRL_ACTIVE_HIGH ? 1 : 0;
  }

  static int cashAcceptorCtrlInactiveLevel()
  {
    return CASH_ACCEPTOR_CTRL_ACTIVE_HIGH ? 0 : 1;
  }

  static void cashAcceptorCtrlSet(bool enabled)
  {
    if (!CASH_ACCEPTOR_CTRL_ENABLED)
      return;
    const gpio_num_t pin = static_cast<gpio_num_t>(CASH_ACCEPTOR_CTRL_GPIO);
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    gpio_set_pull_mode(pin, GPIO_FLOATING);
    gpio_set_level(pin, enabled ? cashAcceptorCtrlActiveLevel()
                                : cashAcceptorCtrlInactiveLevel());
  }

  static void cashAcceptorCtrlPrintStatus(const char* tag)
  {
    const gpio_num_t pin = static_cast<gpio_num_t>(CASH_ACCEPTOR_CTRL_GPIO);
    Serial.print("[");
    Serial.print(tag);
    Serial.print("] enabled=");
    Serial.print(CASH_ACCEPTOR_CTRL_ENABLED ? 1 : 0);
    Serial.print(" gpio=");
    Serial.print(CASH_ACCEPTOR_CTRL_GPIO);
    Serial.print(" active_high=");
    Serial.print(CASH_ACCEPTOR_CTRL_ACTIVE_HIGH ? 1 : 0);
    Serial.print(" level=");
    Serial.println(gpio_get_level(pin));
  }

  static void cashAcceptorCtrlInit()
  {
    if (!CASH_ACCEPTOR_CTRL_ENABLED)
    {
      Serial.println("[CASH_CTRL_INIT] disabled");
      return;
    }
    cashAcceptorCtrlSet(true);
    cashAcceptorCtrlPrintStatus("CASH_CTRL_INIT_ON");
    if (CASH_ACCEPTOR_CTRL_BOOT_SETTLE_MS > 0)
    {
      Serial.print("[CASH_CTRL_INIT] settle_ms=");
      Serial.println(CASH_ACCEPTOR_CTRL_BOOT_SETTLE_MS);
      delay(CASH_ACCEPTOR_CTRL_BOOT_SETTLE_MS);
    }
  }

  static void cashAcceptorCtrlPulse(uint32_t offMs, uint32_t onSettleMs)
  {
    if (!CASH_ACCEPTOR_CTRL_ENABLED)
    {
      Serial.println("[CASH_CTRL_PULSE] disabled");
      return;
    }
    Serial.print("[CASH_CTRL_PULSE] off_ms=");
    Serial.print(offMs);
    Serial.print(" on_settle_ms=");
    Serial.println(onSettleMs);
    cashAcceptorCtrlSet(false);
    cashAcceptorCtrlPrintStatus("CASH_CTRL_PULSE_OFF");
    delay(offMs);
    cashAcceptorCtrlSet(true);
    cashAcceptorCtrlPrintStatus("CASH_CTRL_PULSE_ON");
    delay(onSettleMs);
  }

  const char* bootPhaseName(BootPhase phase)
  {
    switch (phase)
    {
      case BootPhase::WIFI_CONNECTING:    return "WIFI_CONNECTING";
      case BootPhase::WS_CONNECTING:      return "WS_CONNECTING";
      case BootPhase::DEVICE_REGISTERING: return "DEVICE_REGISTERING";
      case BootPhase::FETCHING_CONFIGS:   return "FETCHING_CONFIGS";
      case BootPhase::READY:              return "READY";
      default:                            return "?";
    }
  }

  void setBootPhase(BootPhase next, const char* reason = nullptr)
  {
    String msg = String("[BOOT] ") + bootPhaseName(bootPhase) +
                 " -> " + bootPhaseName(next);
    if (reason != nullptr)
      msg += String("  (reason: ") + reason + ")";
    logSerialLine(msg);

    if (next == BootPhase::READY)
    {
      mdbService.start();
      mdbService.startTask();
    }
    else if (bootPhase == BootPhase::READY)
    {
      mdbService.stopTask();
      mdbService.shutdown();
    }

    if (next == BootPhase::FETCHING_CONFIGS)
      fetchingConfigsEnteredAt = millis();

    if (next == BootPhase::DEVICE_REGISTERING)
      deviceInfoSentForCurrentWsSession = false;

    bootPhase = next;
  }

  void sendDeviceInfoIfNeeded()
  {
    if (!connectionService.isWebSocketConnected())
    {
      deviceInfoSentForCurrentWsSession = false;
      return;
    }
    if (deviceInfoSentForCurrentWsSession)
      return;
    const String payload =
        String("{\"type\":\"device_info\",\"device_id\":\"") +
        connectionService.deviceId() +
        "\",\"details\":{\"firmware_version\":\"" + FIRMWARE_VERSION +
        "\",\"reset_reason\":\"" + resetReasonToString(bootResetReason) +
        "\",\"boot_millis\":" + millis() + "}}";
    if (connectionService.sendText(payload))
      deviceInfoSentForCurrentWsSession = true;
  }

  void handleWebSocketText(const uint8_t* payload, size_t length)
  {
    statusLeds.notifyCommandReceived();
    commandService.handleTextMessage(payload, length);
  }

  void dispatchSerialCommand(const String& command, const String& payloadJson)
  {
    const String message =
        String("{\"type\":\"command\",\"payload\":{\"command\":\"") +
        command + "\",\"payload\":" + payloadJson + "}}";
    statusLeds.notifyCommandReceived();
    commandService.handleTextMessage(
        reinterpret_cast<const uint8_t*>(message.c_str()), message.length());
  }

  void printSerialConsoleHelp()
  {
    Serial.println("USB commands:");
    Serial.println("  help / ?");
    Serial.println("  tx0");
    Serial.println("  tx1");
    Serial.println("  txidle");
    Serial.println("  selftest");
    Serial.println("  txinv");
    Serial.println("  rxinv");
    Serial.println("  ackmode 0|1");
    Serial.println("  status");
    Serial.println("  reset");
    Serial.println("  card N");
    Serial.println("  remove");
    Serial.println("  setid <manuf3> <serial12> <model12> <verhi> <verlo>");
    Serial.println("  cycleid");
    Serial.println("  {json command payload}");
  }

  void dispatchSerialConsoleLine(const String& rawLine)
  {
    String line = rawLine;
    line.trim();
    if (line.isEmpty())
      return;

    if (line.startsWith("{"))
    {
      statusLeds.notifyCommandReceived();
      commandService.handleTextMessage(
          reinterpret_cast<const uint8_t*>(line.c_str()), line.length());
      return;
    }

    const int separator = line.indexOf(' ');
    const String command =
        separator >= 0 ? line.substring(0, separator) : line;
    String arg = separator >= 0 ? line.substring(separator + 1) : "";
    arg.trim();

    if (command == "help" || command == "?")
    {
      printSerialConsoleHelp();
      return;
    }
    if (command == "card")
    {
      const long amount = arg.toInt();
      if (amount <= 0 || amount > 65535)
      {
        Serial.println("[CMD] bad amount");
        return;
      }
      mdbService.setCard(static_cast<uint16_t>(amount));
      return;
    }
    if (command == "remove") { mdbService.removeCard(); return; }
    if (command == "status") { mdbService.printStatus(); return; }
    if (command == "reset")  { mdbService.reset(); return; }
    if (command == "txinv")  { mdbService.toggleTxInvert(); return; }
    if (command == "rxinv")  { mdbService.toggleRxInvert(); return; }
    if (command == "tx0")    { mdbService.holdTxLow(); return; }
    if (command == "tx1")    { mdbService.holdTxHigh(); return; }
    if (command == "txidle")
    {
      mdbService.txIdle();
      Serial.println("[CMD] TX -> idle");
      return;
    }
    if (command == "ackmode")
    {
      mdbService.setAckMode(arg.toInt() != 0);
      return;
    }
    if (command == "selftest") { mdbService.selfTest(); return; }
    if (command == "setid")
    {
      const String manuf  = parseStrToken(arg, 0);
      const String serial = parseStrToken(arg, 1);
      const String model  = parseStrToken(arg, 2);
      const uint8_t verHi = static_cast<uint8_t>(cashCtrlParseU32Token(arg, 3, 0));
      const uint8_t verLo = static_cast<uint8_t>(cashCtrlParseU32Token(arg, 4, 1));
      if (manuf.isEmpty())
      {
        Serial.println("[CMD] usage: setid <manuf3> <serial12> <model12> <verhi> <verlo>");
        return;
      }
      mdbService.setPeripheralId(manuf.c_str(), serial.c_str(), model.c_str(), verHi, verLo);
      mdbService.start();
      Serial.println("[CMD] peripheral ID updated, handshake restarting");
      return;
    }
    if (command == "cycleid")
    {
      mdbService.cycleManufacturerCode();
      return;
    }
    if (command == "cash_ctrl_on")
    {
      cashAcceptorCtrlSet(true);
      cashAcceptorCtrlPrintStatus("CASH_CTRL_ON");
      return;
    }
    if (command == "cash_ctrl_off")
    {
      cashAcceptorCtrlSet(false);
      cashAcceptorCtrlPrintStatus("CASH_CTRL_OFF");
      return;
    }
    if (command == "cash_ctrl_status")
    {
      cashAcceptorCtrlPrintStatus("CASH_CTRL_STATUS");
      return;
    }
    if (command == "cash_ctrl_pulse")
    {
      const uint32_t offMs = cashCtrlParseU32Token(arg, 0, 1000UL);
      const uint32_t onSettleMs = cashCtrlParseU32Token(
          arg, 1, CASH_ACCEPTOR_CTRL_BOOT_SETTLE_MS);
      cashAcceptorCtrlPulse(offMs, onSettleMs);
      return;
    }

    mdbService.emitControlEvent(
        "command_rejected",
        String("{\"command\":\"") + command +
            "\",\"reason\":\"unsupported_usb_console_command\"}");
    Serial.print("usb_cmd_error: unsupported command: ");
    Serial.println(command);
    printSerialConsoleHelp();
  }

  void handleSerialConsole()
  {
    while (Serial.available() > 0)
    {
      const int rawChar = Serial.read();
      if (rawChar < 0)
        return;
      const char ch = static_cast<char>(rawChar);
      if (ch == '\r')
        continue;
      if (ch == '\n')
      {
        serialCommandBuffer[serialCommandLength] = '\0';
        dispatchSerialConsoleLine(String(serialCommandBuffer));
        serialCommandLength = 0;
        serialCommandBuffer[0] = '\0';
        continue;
      }
      if (serialCommandLength + 1 >= kSerialCommandBufferSize)
      {
        Serial.println("usb_cmd_error: command too long");
        serialCommandLength = 0;
        serialCommandBuffer[0] = '\0';
        continue;
      }
      serialCommandBuffer[serialCommandLength++] = ch;
      serialCommandBuffer[serialCommandLength] = '\0';
    }
  }

  const char* resetReasonToString(esp_reset_reason_t reason)
  {
    switch (reason)
    {
      case ESP_RST_POWERON:   return "POWERON";
      case ESP_RST_EXT:       return "EXT";
      case ESP_RST_SW:        return "SW";
      case ESP_RST_PANIC:     return "PANIC";
      case ESP_RST_INT_WDT:   return "INT_WDT";
      case ESP_RST_TASK_WDT:  return "TASK_WDT";
      case ESP_RST_WDT:       return "WDT";
      case ESP_RST_DEEPSLEEP: return "DEEPSLEEP";
      case ESP_RST_BROWNOUT:  return "BROWNOUT";
      case ESP_RST_SDIO:      return "SDIO";
      default:                return "UNKNOWN";
    }
  }
} // namespace

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  delay(200);
  bootResetReason = esp_reset_reason();

  disableCore0WDT();      // MDB pump task busy-polls core 0; idle task won't run
  mdbService.begin();
  mdbService.shutdown();  // MDB disabled until READY phase
  statusLeds.begin();
  pulseService.begin();
  otaService.begin();
  otaService.setCanStartUpdateCallback([]() { return mdbService.isSafeForOta(); });
  connectionService.begin();
  connectionService.setMessageHandler(handleWebSocketText);

  Serial.println("ESP32 booting...");
  Serial.print("Reset reason: ");
  Serial.println(resetReasonToString(bootResetReason));
  Serial.print("Firmware version: ");
  Serial.println(FIRMWARE_VERSION);
  Serial.print("Device MAC: ");
  Serial.println(connectionService.rawMacAddress());
  Serial.print("Device ID: ");
  Serial.println(connectionService.deviceId());
  Serial.println("USB console ready. Type 'help' for local commands.");
}

void loop()
{
  handleSerialConsole();
  connectionService.update();
  statusLeds.update(connectionService.isWifiConnected(),
                    connectionService.isWebSocketConnected());

  switch (bootPhase)
  {
    case BootPhase::WIFI_CONNECTING:
      if (connectionService.isWifiConnected())
        setBootPhase(BootPhase::WS_CONNECTING);
      break;

    case BootPhase::WS_CONNECTING:
      if (!connectionService.isWifiConnected())
      {
        setBootPhase(BootPhase::WIFI_CONNECTING, "wifi lost");
        break;
      }
      if (connectionService.isWebSocketConnected())
        setBootPhase(BootPhase::DEVICE_REGISTERING);
      break;

    case BootPhase::DEVICE_REGISTERING:
      if (!connectionService.isWifiConnected())
      {
        setBootPhase(BootPhase::WIFI_CONNECTING, "wifi lost");
        break;
      }
      if (!connectionService.isWebSocketConnected())
      {
        setBootPhase(BootPhase::WS_CONNECTING, "ws lost");
        break;
      }
      sendDeviceInfoIfNeeded();
      if (deviceInfoSentForCurrentWsSession)
        setBootPhase(BootPhase::FETCHING_CONFIGS);
      break;

    case BootPhase::FETCHING_CONFIGS:
      if (!connectionService.isWifiConnected())
      {
        setBootPhase(BootPhase::WIFI_CONNECTING, "wifi lost");
        break;
      }
      if (!connectionService.isWebSocketConnected())
      {
        setBootPhase(BootPhase::WS_CONNECTING, "ws lost");
        break;
      }
      pulseConfigService.update();
      // TODO: mdbConfigService.update() when added
      if (pulseConfigService.isLoaded())
      {
        const String reason = String("configs loaded in ") +
                              (millis() - fetchingConfigsEnteredAt) + " ms";
        setBootPhase(BootPhase::READY, reason.c_str());
      }
      else if (millis() - fetchingConfigsEnteredAt > 60000)
      {
        setBootPhase(BootPhase::READY, "timeout 60s, proceeding without config");
      }
      break;

    case BootPhase::READY:
      if (!connectionService.isWifiConnected())
      {
        setBootPhase(BootPhase::WIFI_CONNECTING, "wifi lost");
        break;
      }
      pulseService.update();
      mdbService.update();
      otaService.update();
      if (pulseConfigService.isRefreshRequested())
        pulseConfigService.update();
      if (mdbService.shouldReportStatus())
      {
        String statusJson;
        if (mdbService.getStatusJson(statusJson))
          connectionService.sendText(statusJson);
      }
      break;
  }

  delay(0);
}
