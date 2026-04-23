#pragma once

// Глобальная конфигурация устройства: сеть, пины, тайминги и значения по умолчанию.

// Параметры Wi‑Fi.
constexpr char WIFI_SSID[] = "Denis";
constexpr char WIFI_PASSWORD[] = "481516231";
constexpr int WIFI_CHANNEL = 6;
constexpr unsigned long WIFI_CONNECT_TIMEOUT_MS = 15000;

// Параметры backend-сервера и путей API/WS.
constexpr char SERVER_SCHEME[] = "http";
constexpr char SERVER_HOST[] = "192.168.192.13";
constexpr uint16_t SERVER_PORT = 8000;
constexpr char SERVER_PATH[] = "/test";
constexpr char WEBSOCKET_PATH_PREFIX[] = "/ws/";
constexpr char PULSE_CONFIG_PATH_SUFFIX[] = "/pulse-config";

// Назначение GPIO и базовые системные тайминги.
constexpr int YELLOW_LED_PIN = 25;
constexpr int GREEN_LED_PIN = 26;
constexpr int RED_LED_PIN = 27;
constexpr int BILL_PULSE_OUTPUT_PIN = 32;
constexpr int COIN_PULSE_OUTPUT_PIN = 33;
constexpr int PULSE_OUTPUT_PIN = COIN_PULSE_OUTPUT_PIN;
constexpr int MDB_RX_PIN = 14;
constexpr int MDB_TX_PIN = 19;
constexpr unsigned long MDB_BAUD_RATE = 9600;
constexpr unsigned long MDB_FRAME_GAP_MS = 20;
constexpr bool MDB_RX_INVERT = false;
constexpr bool MDB_TX_INVERT = true;
constexpr unsigned long UART_BAUD_RATE = 9600;
constexpr unsigned long UART_FRAME_GAP_MS = 20;
constexpr unsigned long WIFI_LED_BLINK_INTERVAL_MS = 250;
constexpr unsigned long WEBSOCKET_RETRY_INTERVAL_MS = 3000;
constexpr unsigned long WEBSOCKET_LED_BLINK_INTERVAL_MS = 300;
constexpr unsigned long PULSE_ON_TIME_MS_DEFAULT = 100;
constexpr unsigned long PULSE_OFF_TIME_MS_DEFAULT = 100;
constexpr unsigned long MINOR_UNITS_PER_PULSE_DEFAULT = 100;
constexpr unsigned long BILL_PULSE_ON_TIME_MS_DEFAULT = PULSE_ON_TIME_MS_DEFAULT;
constexpr unsigned long BILL_PULSE_OFF_TIME_MS_DEFAULT = PULSE_OFF_TIME_MS_DEFAULT;
constexpr unsigned long BILL_MINOR_UNITS_PER_PULSE_DEFAULT = 1000;
constexpr unsigned long COIN_PULSE_ON_TIME_MS_DEFAULT = PULSE_ON_TIME_MS_DEFAULT;
constexpr unsigned long COIN_PULSE_OFF_TIME_MS_DEFAULT = PULSE_OFF_TIME_MS_DEFAULT;
constexpr unsigned long COIN_MINOR_UNITS_PER_PULSE_DEFAULT =
    MINOR_UNITS_PER_PULSE_DEFAULT;
constexpr unsigned long PULSE_CONFIG_REFRESH_INTERVAL_MS = 5000;
constexpr unsigned long LED_ON_TIME_MS = 3000;
constexpr unsigned long REQUEST_INTERVAL_MS = 3000;
