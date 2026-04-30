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
// Работаем как cashless, как в старом бинарнике; coin changer MDB path заглушен.
constexpr bool kMdbCashlessEnabled = true;
constexpr bool kMdbCoinChangerEnabled = false;

// Низкоуровневые MDB-настройки активного cashless-канала.
// Старый бинарник подтвердил cashless raw address 0x10; inversion в нём не
// раскрыта, поэтому полярность хранится здесь как единый переключатель PHY.
constexpr unsigned long kMdbBaudRate = 9600;
constexpr unsigned long kMdbFrameGapMs = 20;
constexpr bool kMdbRxInvert = true;
constexpr bool kMdbTxInvert = true;
// Arduino sniffer on U2 pin6 showed the physical mode/parity bit inverted
// relative to the requested TX ninthBit. Keep this correction in config so the
// logical MDB ninthBit requested by MachinePhy matches the line observed by VMC.
constexpr bool kMdbTxParityBitInvert = true;

// Cashless EXPANSION ID profile. 12-byte reader id found in the old firmware.
// The old binary also contains "VN2600RU", but the current MDB cashless
// expansion response carries reader id plus a 3-byte version tuple.
constexpr char kMdbCashlessReaderId[] = "022290281967";
constexpr uint8_t kMdbCashlessVersionMajor = 0x01;
constexpr uint8_t kMdbCashlessVersionMinor = 0x01;
constexpr uint8_t kMdbCashlessVersionPatch = 0x01;
static_assert(sizeof(kMdbCashlessReaderId) == 13,
              "Cashless reader id must stay 12 chars");

// Базовые MDB-адреса эмулируемых периферий.
// Важно: здесь храним именно числовой MDB-address после `command_byte >> 3`,
// а не сырое значение первого байта кадра.
constexpr uint8_t kMdbCashlessAddress = 2;
// Standard MDB cashless address. Arduino sniffer on U1/GPIO14 confirmed VMC sends
// RESET as raw byte 0x10 (addr=2, cmd=0). The prior change to 31 was a misread.
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
