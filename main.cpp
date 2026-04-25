#include <Arduino.h>
#include <esp_system.h>

#include "device_config.h"

#define MDB_RX_ONLY_SNIFFER 0

#if MDB_RX_ONLY_SNIFFER
#include "mdb_bitbang_receiver.h"
#else
#include "command_service.h"
#include "connection_service.h"
#include "firmware_version.h"
#include "logging_utils.h"
#include "mdb_service.h"
#include "ota_manager.h"
#include "pulse_config_service.h"
#include "pulse_service.h"
#include "status_leds.h"
#include "uart_service.h"
#endif

namespace {
#if MDB_RX_ONLY_SNIFFER
MdbBitBangReceiver mdbRx(static_cast<gpio_num_t>(MDB_RX_PIN));
#else
// Глобальные экземпляры сервисов, живущие весь срок работы устройства.
PulseService pulseService;
ConnectionService connectionService;
MdbService mdbService(connectionService);
UartService uartService(connectionService);
OtaManager otaService(connectionService);
PulseConfigService pulseConfigService(connectionService, pulseService);
CommandService commandService(pulseService, mdbService, pulseConfigService,
                              uartService, otaService);
StatusLeds statusLeds;
esp_reset_reason_t bootResetReason = ESP_RST_UNKNOWN;
bool deviceInfoSentForCurrentWsSession = false;
constexpr size_t kSerialCommandBufferSize = 192;
char serialCommandBuffer[kSerialCommandBufferSize] = {};
size_t serialCommandLength = 0;

const char* resetReasonToString(esp_reset_reason_t reason);
void handleSerialConsole();
void dispatchSerialConsoleLine(const String& line);
void dispatchSerialCommand(const String& command,
                           const String& payloadJson = "{}");
void printSerialConsoleHelp();

// Отправляет backend информацию об устройстве после каждого нового WS-подключения.
void sendDeviceInfoIfNeeded() {
  if (!connectionService.isWebSocketConnected()) {
    deviceInfoSentForCurrentWsSession = false;
    return;
  }

  if (deviceInfoSentForCurrentWsSession) {
    return;
  }

  const String payload = String("{\"type\":\"device_info\",\"device_id\":\"") +
                         connectionService.deviceId() + "\",\"details\":{\"firmware_version\":\"" +
                         FIRMWARE_VERSION + "\",\"reset_reason\":\"" +
                         resetReasonToString(bootResetReason) + "\",\"boot_millis\":" +
                         millis() + "}}";
  if (connectionService.sendText(payload)) {
    deviceInfoSentForCurrentWsSession = true;
  }
}

// Передаёт входящие команды из WebSocket в прикладной dispatcher.
void handleWebSocketText(const uint8_t* payload, size_t length) {
  statusLeds.notifyCommandReceived();
  commandService.handleTextMessage(payload, length);
}

// Выполняет локальную команду через тот же JSON-dispatcher, что и WebSocket.
void dispatchSerialCommand(const String& command, const String& payloadJson) {
  const String message = String("{\"type\":\"command\",\"payload\":{\"command\":\"") +
                         command + "\",\"payload\":" + payloadJson + "}}";
  statusLeds.notifyCommandReceived();
  commandService.handleTextMessage(
      reinterpret_cast<const uint8_t*>(message.c_str()), message.length());
}

// Печатает короткую справку по локальным USB-командам.
void printSerialConsoleHelp() {
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
void dispatchSerialConsoleLine(const String& rawLine) {
  String line = rawLine;
  line.trim();
  if (line.isEmpty()) {
    return;
  }

  if (line.startsWith("{")) {
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

  if (command == "help" || command == "?") {
    printSerialConsoleHelp();
    return;
  }

  if (command == "mdb_set_cashless_address") {
    dispatchSerialCommand(
        command, String("{\"cashless_address\":") +
                     (arg.isEmpty() ? "2" : arg) + "}");
    return;
  }

  if (command == "mdb_gateway_profile") {
    dispatchSerialCommand(
        command, String("{\"profile_id\":") +
                     (arg.isEmpty() ? "0" : arg) + "}");
    return;
  }

  if (command == "mdb_set_expected_address") {
    dispatchSerialCommand(
        command, String("{\"expected_address\":") +
                     (arg.isEmpty() ? "-1" : arg) + "}");
    return;
  }

  if (command == "mdb_raw_send") {
    if (arg.isEmpty()) {
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
      command == "mdb_rx_invert_on" || command == "mdb_rx_invert_off") {
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
void handleSerialConsole() {
  while (Serial.available() > 0) {
    const int rawChar = Serial.read();
    if (rawChar < 0) {
      return;
    }

    const char ch = static_cast<char>(rawChar);
    if (ch == '\r') {
      continue;
    }

    if (ch == '\n') {
      serialCommandBuffer[serialCommandLength] = '\0';
      dispatchSerialConsoleLine(String(serialCommandBuffer));
      serialCommandLength = 0;
      serialCommandBuffer[0] = '\0';
      continue;
    }

    if (serialCommandLength + 1 >= kSerialCommandBufferSize) {
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
const char* resetReasonToString(esp_reset_reason_t reason) {
  switch (reason) {
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
#endif
}  // namespace

void setup() {
#if MDB_RX_ONLY_SNIFFER
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("MDB bit-bang RX-only sniffer");
  Serial.println(String("GPIO") + MDB_RX_PIN +
                 ", 9600 baud, non-inverted test, 8 data + mode + stop");
  Serial.println("Lines: [MDB_DIAG] counters, [MDB] decoded VMC frames");
  mdbRx.begin(false, 9600);
#else
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
  uartService.begin();
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
#endif
}

void loop() {
#if MDB_RX_ONLY_SNIFFER
  mdbRx.update();
  mdbRx.printDiagnostics();
  delay(1);
#else
  // Основной цикл устройства: связь, логика оплаты, OTA и индикация.
  handleSerialConsole();
  connectionService.update();
  sendDeviceInfoIfNeeded();
  pulseConfigService.update();
  pulseService.update();
  mdbService.update();
  uartService.update();
  otaService.update();
  statusLeds.update(connectionService.isWifiConnected(),
                    connectionService.isWebSocketConnected());
  delay(50);
#endif
}
