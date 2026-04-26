#pragma once

#include <Arduino.h>

// Глобальная конфигурация MDB: стек UART-задачи, детализация трассировки
// и принудительный выбор setup-response профиля для gateway-совместимости.

// Размер стека task `mdb_uart_evt`. Увеличен, чтобы убрать переполнение
// на плотных TX/setup-response сценариях.
constexpr size_t kMdbUartEvtTaskStackBytes = 20480;

// Детализация побайтного TX-трейса. Пока выключена, чтобы не раздувать
// стек и serial-лог при диагностике setup-response.
constexpr bool kMdbUartEvtVerboseTxByteTrace = false;

// Принудительный выбор стандартного gateway-setup профиля.
// 0 = стандартный ISO4217-профиль KGS (14 17).
constexpr bool kGatewayCompatForceStandardProfile = true;
constexpr uint8_t kGatewayCompatForcedProfileId = 0;

// Активные режимы MDB-эмуляции на устройстве.
// Для текущей схемы оставляем только coin changer emulator.
constexpr bool kMdbCashlessEnabled = false;
constexpr bool kMdbCoinChangerEnabled = true;

// Базовые MDB-адреса эмулируемых периферий.
// Важно: здесь храним именно числовой MDB-address после `command_byte >> 3`,
// а не сырое значение первого байта кадра.
constexpr uint8_t kMdbCashlessAddress = 2;
constexpr uint8_t kMdbCoinChangerAddress = 0x08;

// Таймаут удержания queued-платежа до первого POLL от VMC.
constexpr unsigned long kMdbCoinChangerPaymentTimeoutMs = 60000UL;

// Профиль coin changer emulator, снятый со старого устройства.
constexpr uint8_t kMdbCoinChangerFeatureLevel = 0x01;
constexpr uint8_t kMdbCoinChangerCurrencyCountryCodeHi = 0x14;
constexpr uint8_t kMdbCoinChangerCurrencyCountryCodeLo = 0x17;
constexpr uint8_t kMdbCoinChangerScalingFactor = 0x64;
constexpr uint8_t kMdbCoinChangerDecimalPlaces = 0x02;
constexpr uint16_t kMdbCoinChangerRoutingMask = 0x0000;
constexpr uint8_t kMdbCoinChangerCoinCredits[16] = {
    1, 5, 10, 50, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
constexpr char kMdbCoinChangerManufacturer[] = "MEI";
constexpr char kMdbCoinChangerSerial[] = "3769G600351 ";
constexpr char kMdbCoinChangerModel[] = "CF7900MDB   ";
constexpr uint32_t kMdbCoinChangerOptionalFeatureBits = 0x00000000UL;
