#include <Arduino.h>
#include <esp_system.h>
#include <driver/gpio.h>
#include <string.h>

#include "device_config.h"
#include "command_service.h"
#include "connection_service.h"
#include "firmware_version.h"
#include "mdb_service.h"
#include "ota_manager.h"
#include "pulse_config_service.h"
#include "pulse_service.h"
#include "status_leds.h"

namespace
{
  // Глобальные экземпляры сервисов, живущие весь срок работы устройства.
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

  const char *resetReasonToString(esp_reset_reason_t reason);
  void handleSerialConsole();

  static uint32_t cashCtrlParseU32Token(const String &source, int index, uint32_t fallback)
  {
    int start = 0;
    int tokenIndex = 0;

    while (start < source.length())
    {
      while (start < source.length() && source[start] == ' ')
      {
        start++;
      }

      if (start >= source.length())
      {
        break;
      }

      int end = source.indexOf(' ', start);
      if (end < 0)
      {
        end = source.length();
      }

      if (tokenIndex == index)
      {
        return static_cast<uint32_t>(source.substring(start, end).toInt());
      }

      tokenIndex++;
      start = end + 1;
    }

    return fallback;
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
    {
      return;
    }

    const gpio_num_t pin = static_cast<gpio_num_t>(CASH_ACCEPTOR_CTRL_GPIO);
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    gpio_set_pull_mode(pin, GPIO_FLOATING);
    gpio_set_level(pin, enabled ? cashAcceptorCtrlActiveLevel() : cashAcceptorCtrlInactiveLevel());
  }

  static void cashAcceptorCtrlPrintStatus(const char *tag)
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

  void dispatchSerialConsoleLine(const String &line);
  void dispatchSerialCommand(const String &command,
                             const String &payloadJson = "{}");
  void printSerialConsoleHelp();

  // Отправляет backend информацию об устройстве после каждого нового WS-подключения.
  void sendDeviceInfoIfNeeded()
  {
    if (!connectionService.isWebSocketConnected())
    {
      deviceInfoSentForCurrentWsSession = false;
      return;
    }

    if (deviceInfoSentForCurrentWsSession)
    {
      return;
    }

    const String payload = String("{\"type\":\"device_info\",\"device_id\":\"") +
                           connectionService.deviceId() + "\",\"details\":{\"firmware_version\":\"" +
                           FIRMWARE_VERSION + "\",\"reset_reason\":\"" +
                           resetReasonToString(bootResetReason) + "\",\"boot_millis\":" +
                           millis() + "}}";
    if (connectionService.sendText(payload))
    {
      deviceInfoSentForCurrentWsSession = true;
    }
  }

  // Передаёт входящие команды из WebSocket в прикладной dispatcher.
  void handleWebSocketText(const uint8_t *payload, size_t length)
  {
    statusLeds.notifyCommandReceived();
    commandService.handleTextMessage(payload, length);
  }

  // Выполняет локальную команду через тот же JSON-dispatcher, что и WebSocket.
  void dispatchSerialCommand(const String &command, const String &payloadJson)
  {
    const String message = String("{\"type\":\"command\",\"payload\":{\"command\":\"") +
                           command + "\",\"payload\":" + payloadJson + "}}";
    statusLeds.notifyCommandReceived();
    commandService.handleTextMessage(
        reinterpret_cast<const uint8_t *>(message.c_str()), message.length());
  }

  // Печатает короткую справку по локальным USB-командам.
  void printSerialConsoleHelp()
  {
    Serial.println("USB commands:");
    Serial.println("  help");
    Serial.println("  mdb_probe");
    Serial.println("  mdb_irq_snapshot");
    Serial.println("  phy_decoder_status");
    Serial.println("  mdb_probe_tx");
    Serial.println("  mdb_pulse_test");
    Serial.println("  mdb_tx_hold_low_test");
    Serial.println("  mdb_monitor_start");
    Serial.println("  mdb_monitor_stop");
    Serial.println("  mdb_sniff_clear");
    Serial.println("  mdb_sniff_recent");
    Serial.println("  mdb_sniff_summary");
    Serial.println("  mdb_sniff_stats");
    Serial.println("  mdb_passive_sniff_on");
    Serial.println("  mdb_passive_sniff_off");
    Serial.println("  mdb_rx_invert_on");
    Serial.println("  mdb_rx_invert_off");
    Serial.println("  mdb_gateway_profile <0|1|2>");
    Serial.println("  mdb_set_cashless_address <n>");
    Serial.println("  mdb_set_expected_address <n>");
    Serial.println("  mdb_raw_send <HEX>");
    Serial.println("  {json command payload}");
  }

  // Разбирает одну строку команды, пришедшую по USB Serial.
  void dispatchSerialConsoleLine(const String &rawLine)
  {
    String line = rawLine;
    line.trim();
    if (line.isEmpty())
    {
      return;
    }

    if (line.startsWith("{"))
    {
      statusLeds.notifyCommandReceived();
      commandService.handleTextMessage(
          reinterpret_cast<const uint8_t *>(line.c_str()), line.length());
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
      const uint32_t onSettleMs = cashCtrlParseU32Token(arg, 1, CASH_ACCEPTOR_CTRL_BOOT_SETTLE_MS);
      cashAcceptorCtrlPulse(offMs, onSettleMs);
      return;
    }

    if (command == "mdb_set_cashless_address")
    {
      dispatchSerialCommand(
          command, String("{\"cashless_address\":") +
                       (arg.isEmpty() ? "2" : arg) + "}");
      return;
    }

    if (command == "mdb_gateway_profile")
    {
      dispatchSerialCommand(
          command, String("{\"profile_id\":") +
                       (arg.isEmpty() ? "0" : arg) + "}");
      return;
    }

    if (command == "mdb_set_expected_address")
    {
      dispatchSerialCommand(
          command, String("{\"expected_address\":") +
                       (arg.isEmpty() ? "-1" : arg) + "}");
      return;
    }

    if (command == "mdb_raw_send")
    {
      if (arg.isEmpty())
      {
        Serial.println("usb_cmd_error: mdb_raw_send requires HEX payload");
        return;
      }
      dispatchSerialCommand(command,
                            String("{\"hex\":\"") + arg + "\"}");
      return;
    }

    if (command == "mdb_probe" || command == "mdb_irq_snapshot" ||
        command == "phy_decoder_status" ||
        command == "mdb_probe_tx" ||
        command == "mdb_pulse_test" || command == "mdb_tx_hold_low_test" ||
        command == "mdb_monitor_start" || command == "mdb_monitor_stop" ||
        command == "mdb_sniff_clear" || command == "mdb_sniff_recent" ||
        command == "mdb_sniff_summary" || command == "mdb_sniff_stats" ||
        command == "mdb_passive_sniff_on" ||
        command == "mdb_passive_sniff_off" ||
        command == "mdb_rx_invert_on" || command == "mdb_rx_invert_off")
    {
      dispatchSerialCommand(command);
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

  // Обрабатывает строки из USB Serial как локальные сервисные команды.
  void handleSerialConsole()
  {
    while (Serial.available() > 0)
    {
      const int rawChar = Serial.read();
      if (rawChar < 0)
      {
        return;
      }

      const char ch = static_cast<char>(rawChar);
      if (ch == '\r')
      {
        continue;
      }

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

  // Переводит код причины сброса ESP32 в строку для логов и backend.
  const char *resetReasonToString(esp_reset_reason_t reason)
  {
    switch (reason)
    {
    case ESP_RST_POWERON:
      return "POWERON";
    case ESP_RST_EXT:
      return "EXT";
    case ESP_RST_SW:
      return "SW";
    case ESP_RST_PANIC:
      return "PANIC";
    case ESP_RST_INT_WDT:
      return "INT_WDT";
    case ESP_RST_TASK_WDT:
      return "TASK_WDT";
    case ESP_RST_WDT:
      return "WDT";
    case ESP_RST_DEEPSLEEP:
      return "DEEPSLEEP";
    case ESP_RST_BROWNOUT:
      return "BROWNOUT";
    case ESP_RST_SDIO:
      return "SDIO";
    default:
      return "UNKNOWN";
    }
  }
} // namespace

void setup()
{
  // Начальная инициализация железа, сервисов и сетевого стека.
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  delay(200);
  bootResetReason = esp_reset_reason();

  mdbService.begin();
  vTaskDelay(pdMS_TO_TICKS(100));
  mdbService.startRealtimeRx();
  statusLeds.begin();
  pulseService.begin();
  otaService.begin();
  otaService.setCanStartUpdateCallback([]()
                                       { return mdbService.isSafeForOta(); });
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
  // Основной цикл устройства: связь, логика оплаты, OTA и индикация.
  handleSerialConsole();
  connectionService.update();
  sendDeviceInfoIfNeeded();
  pulseConfigService.update();
  pulseService.update();
  mdbService.update();
  otaService.update();
  statusLeds.update(connectionService.isWifiConnected(),
                    connectionService.isWebSocketConnected());
  delay(1);
}