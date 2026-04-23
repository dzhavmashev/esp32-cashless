#include "uart_service.h"

#include <driver/gpio.h>
#include <driver/uart.h>
#include <esp_rom_gpio.h>
#include <soc/io_mux_reg.h>

#include "connection_service.h"
#include "device_config.h"

namespace {
constexpr uart_port_t kUartNum = UART_NUM_2;
volatile uint32_t gRawSnifferEdgeCount = 0;

void IRAM_ATTR rawSnifferIsrThunk(void* /*arg*/) { gRawSnifferEdgeCount++; }

// Преобразует набор байтов в HEX-строку для логов и событий.
String bytesToHexString(const uint8_t* data, size_t length) {
  String result;
  for (size_t i = 0; i < length; ++i) {
    if (i > 0) {
      result += ' ';
    }
    if (data[i] < 0x10) {
      result += '0';
    }
    result += String(data[i], HEX);
  }
  result.toUpperCase();
  return result;
}

// Применяет аппаратную инверсию RX/TX для UART2.
void applyUartLineInversion() {
  uart_set_line_inverse(kUartNum, UART_SIGNAL_TXD_INV | UART_SIGNAL_RXD_INV);
}
}  // namespace

UartService::UartService(ConnectionService& connectionService)
    : connectionService_(connectionService) {}

// В UART-режиме отдельной инициализации не требуется.
void UartService::begin() {}

// Настраивает UART-порт и инверсию линий.
void UartService::configurePort() {
  uart_driver_delete(kUartNum);
  uart_config_t config = {};
  config.baud_rate = static_cast<int>(UART_BAUD_RATE);
  config.data_bits = UART_DATA_8_BITS;
  config.parity = UART_PARITY_DISABLE;
  config.stop_bits = UART_STOP_BITS_1;
  config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
  config.rx_flow_ctrl_thresh = 0;
  config.source_clk = UART_SCLK_APB;
  uart_param_config(kUartNum, &config);
  uart_set_pin(kUartNum, MDB_TX_PIN, MDB_RX_PIN, UART_PIN_NO_CHANGE,
               UART_PIN_NO_CHANGE);
  uart_driver_install(kUartNum, 256, 0, 0, nullptr, 0);
  applyUartLineInversion();
}

// Активирует UART-режим.
void UartService::activate() {
  active_ = true;
  configurePort();
}

// Логически отключает UART-режим.
void UartService::deactivate() {
  if (active_) {
    uart_driver_delete(kUartNum);
  }
  active_ = false;
  rxFrameLength_ = 0;
}

esp_err_t UartService::debug_force_raw_sniffer() {
  deactivate();

  gpio_reset_pin(GPIO_NUM_14);
  esp_rom_gpio_pad_select_gpio(GPIO_NUM_14);
  PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[GPIO_NUM_14], PIN_FUNC_GPIO);

  gpio_config_t config = {};
  config.pin_bit_mask = (1ULL << GPIO_NUM_14);
  config.mode = GPIO_MODE_INPUT;
  config.pull_up_en = GPIO_PULLUP_ENABLE;
  config.pull_down_en = GPIO_PULLDOWN_DISABLE;
  config.intr_type = GPIO_INTR_ANYEDGE;
  esp_err_t err = gpio_config(&config);
  if (err != ESP_OK) {
    return err;
  }

  err = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
  if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
    return err;
  }

  gpio_isr_handler_remove(GPIO_NUM_14);
  gRawSnifferEdgeCount = 0;
  return gpio_isr_handler_add(GPIO_NUM_14, &rawSnifferIsrThunk, nullptr);
}

// Обслуживает приём кадров и отложенную отправку PAY-команды.
void UartService::update() {
  if (!active_) {
    return;
  }

  while (true) {
    uint8_t value = 0;
    const int read = uart_read_bytes(kUartNum, &value, 1, 0);
    if (read <= 0) {
      break;
    }

    if (rxFrameLength_ < sizeof(rxFrame_)) {
      rxFrame_[rxFrameLength_++] = value;
    }
    lastRxByteAt_ = millis();
  }

  flushRxFrameIfReady(millis());

  if (!payPending_) {
    return;
  }

  const String payload = String("PAY:") + pendingAmountMinor_ + "\n";
  uart_write_bytes(kUartNum, payload.c_str(), payload.length());
  emitEvent("pay_tx",
            String("{\"amount_minor\":") + pendingAmountMinor_ + ",\"text\":\"PAY:" +
                pendingAmountMinor_ + "\"}");
  payPending_ = false;
  pendingAmountMinor_ = 0;
}

// Ставит PAY-команду в очередь на отправку.
void UartService::requestPay(unsigned long amountMinor) {
  activate();
  if (amountMinor == 0) {
    emitEvent("pay_ignored", String("{\"reason\":\"amount_is_zero\"}"));
    return;
  }

  payPending_ = true;
  pendingAmountMinor_ = amountMinor;
}

// Публикует диагностическую конфигурацию UART-режима.
void UartService::requestProbe() {
  activate();
  emitEvent("probe", String("{\"baud_rate\":") + UART_BAUD_RATE + ",\"rx_pin\":" +
                         MDB_RX_PIN + ",\"tx_pin\":" + MDB_TX_PIN + "}");
}

// Отправляет тестовую UART-последовательность в линию.
void UartService::requestProbeTx() {
  activate();
  const uint8_t frame[] = {'U', 'A', 'R', 'T', '\n'};
  uart_write_bytes(kUartNum, reinterpret_cast<const char*>(frame), sizeof(frame));
  lastProbeTxAt_ = millis();
  rxFramesAfterProbeTx_ = 0;
  emitEvent("probe_tx",
            String("{\"hex\":\"") + bytesToHexString(frame, sizeof(frame)) + "\"}");
}

// Переключает режим мониторинга входящих UART-кадров.
void UartService::setMonitorEnabled(bool enabled) {
  activate();
  monitorEnabled_ = enabled;
  emitEvent(enabled ? "monitor_started" : "monitor_stopped", "{}");
}

// Отправляет произвольную HEX-последовательность в UART.
void UartService::sendRawHex(const String& hexPayload) {
  activate();
  uint8_t buffer[64] = {};
  size_t length = 0;
  if (!parseHexPayload(hexPayload, buffer, length)) {
    emitEvent("raw_send_failed", String("{\"reason\":\"invalid_hex\"}"));
    return;
  }

  uart_write_bytes(kUartNum, reinterpret_cast<const char*>(buffer), length);
  emitEvent("raw_tx", String("{\"hex\":\"") + bytesToHexString(buffer, length) + "\"}");
}

// Возвращает JSON-сводку по состоянию UART-сервиса.
String UartService::buildDebugStateJson() const {
  return String("{\"active\":") + (active_ ? "true" : "false") +
         ",\"monitor_enabled\":" + (monitorEnabled_ ? "true" : "false") +
         ",\"rx_frame_count\":" + rxFrameCount_ + ",\"last_rx_frame_at\":" +
         lastRxFrameAt_ + ",\"last_probe_tx_at\":" + lastProbeTxAt_ +
         ",\"rx_frames_after_probe_tx\":" + rxFramesAfterProbeTx_ +
         ",\"pay_pending\":" + (payPending_ ? "true" : "false") + "}";
}

// Отправляет одно UART-событие в backend.
void UartService::emitEvent(const char* eventType, const String& details) {
  if (!connectionService_.isWebSocketConnected()) {
    return;
  }

  const String message = String("{\"type\":\"uart_event\",\"event\":\"") + eventType +
                         "\",\"device_id\":\"" + connectionService_.deviceId() +
                         "\",\"details\":" + details + "}";
  connectionService_.sendText(message);
}

// Закрывает RX-кадр по межкадровой паузе.
void UartService::flushRxFrameIfReady(unsigned long now) {
  if (!monitorEnabled_ || rxFrameLength_ == 0) {
    return;
  }

  if (now - lastRxByteAt_ < UART_FRAME_GAP_MS) {
    return;
  }

  emitEvent("rx_frame",
            String("{\"hex\":\"") + bytesToHexString(rxFrame_, rxFrameLength_) +
                "\",\"length\":" + rxFrameLength_ + "}");
  rxFrameCount_++;
  lastRxFrameAt_ = now;
  if (lastProbeTxAt_ != 0 && now >= lastProbeTxAt_) {
    rxFramesAfterProbeTx_++;
  }
  rxFrameLength_ = 0;
}

// Разбирает HEX-строку в массив байтов.
bool UartService::parseHexPayload(const String& hexPayload, uint8_t* buffer,
                                  size_t& length) {
  String normalized;
  normalized.reserve(hexPayload.length());

  for (size_t i = 0; i < hexPayload.length(); ++i) {
    const char ch = hexPayload[i];
    if (ch == ' ' || ch == ':' || ch == '-' || ch == '\n' || ch == '\r' ||
        ch == '\t') {
      continue;
    }
    normalized += ch;
  }

  if (normalized.length() == 0 || (normalized.length() % 2) != 0) {
    return false;
  }

  length = normalized.length() / 2;
  if (length > 64) {
    return false;
  }

  auto parseNibble = [](char ch) -> int {
    if (ch >= '0' && ch <= '9') {
      return ch - '0';
    }
    if (ch >= 'a' && ch <= 'f') {
      return ch - 'a' + 10;
    }
    if (ch >= 'A' && ch <= 'F') {
      return ch - 'A' + 10;
    }
    return -1;
  };

  for (size_t i = 0; i < length; ++i) {
    const int hi = parseNibble(normalized[i * 2]);
    const int lo = parseNibble(normalized[i * 2 + 1]);
    if (hi < 0 || lo < 0) {
      return false;
    }
    buffer[i] = static_cast<uint8_t>((hi << 4) | lo);
  }

  return true;
}
