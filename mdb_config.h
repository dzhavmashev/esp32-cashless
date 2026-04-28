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
constexpr bool kMdbCashlessEnabled = true;
constexpr bool kMdbCoinChangerEnabled = false;

// Базовые MDB-адреса эмулируемых периферий.
// Важно: здесь храним именно числовой MDB-address после `command_byte >> 3`,
// а не сырое значение первого байта кадра.
constexpr uint8_t kMdbCashlessAddress = 2;
// Old working ESP32 extraction: MDB Address = raw 0x10.
// This firmware stores decoded MDB address, therefore raw 0x10 >> 3 = 0x02.
constexpr uint8_t kMdbOldDeviceCompatRawAddress = 0x10;
constexpr uint8_t kMdbOldDeviceCompatDecodedAddress = 0x02;
// Coin changer raw command byte is 0x08, but decoded MDB address is 0x08 >> 3 = 0x01.
// machine::Frame::candidateAddress stores the decoded 5-bit address, not the raw byte.
constexpr uint8_t kMdbCoinChangerRawCommandBase = 0x08;
constexpr uint8_t kMdbCoinChangerAddress = 0x01;

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
// Expected lengths for MDB EXPANSION IDENTIFICATION fields.
// sizeof includes the terminating NUL, hence 4/13/13.
static_assert(sizeof(kMdbCoinChangerManufacturer) == 4, "MDB coin manufacturer must be 3 chars");
static_assert(sizeof(kMdbCoinChangerSerial) == 13, "MDB coin serial must be 12 chars");
static_assert(sizeof(kMdbCoinChangerModel) == 13, "MDB coin model must be 12 chars");

