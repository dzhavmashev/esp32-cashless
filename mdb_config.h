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
constexpr bool kGatewayCompatForceStandardProfile = false;
constexpr uint8_t kGatewayCompatForcedProfileId = 0;

// Активные режимы MDB-эмуляции на устройстве.
constexpr bool kMdbCashlessEnabled = true;
constexpr bool kMdbCoinChangerEnabled = true;

// Режим при старте. true = coin changer, false = cashless.
// This VMC does not have a standard coin changer slot (addr 1 never polled).
// 0xFE compat credit injection only works while the cashless session is active.
constexpr bool kMdbBootAsCoinChanger = false;

// Низкоуровневые MDB-настройки активного cashless-канала.
// Старый бинарник подтвердил cashless raw address 0x10; inversion в нём не
// раскрыта, поэтому полярность хранится здесь как единый переключатель PHY.
constexpr unsigned long kMdbBaudRate = 9600;
constexpr unsigned long kMdbFrameGapMs = 0;
constexpr bool kMdbRxInvert = false;
constexpr bool kMdbTxInvert = true;
// Arduino sniffer on U2 pin6 showed the physical mode/parity bit inverted
// relative to the requested TX ninthBit. Keep this correction in config so the
// logical MDB ninthBit requested by MachinePhy matches the line observed by VMC.
constexpr bool kMdbTxParityBitInvert = false;

// Cashless EXPANSION ID / reader identity profile.
// Старый бинарник содержит:
//   reader/serial: 022290281967
//   model:         VN2600RU
constexpr char kMdbCashlessManufacturer[] = "   ";        // 3 chars, пока неизвестно
constexpr char kMdbCashlessReaderId[] = "022290281967";   // 12 chars
constexpr char kMdbCashlessModel[] = "VN2600RU    ";      // 12 chars

constexpr uint8_t kMdbCashlessSoftwareVersionHi = 0x01;
constexpr uint8_t kMdbCashlessSoftwareVersionLo = 0x01;

// Оставь старые aliases, если где-то в коде ещё используются Major/Minor/Patch.
constexpr uint8_t kMdbCashlessVersionMajor = kMdbCashlessSoftwareVersionHi;
constexpr uint8_t kMdbCashlessVersionMinor = kMdbCashlessSoftwareVersionLo;
constexpr uint8_t kMdbCashlessVersionPatch = 0x01;

static_assert(sizeof(kMdbCashlessManufacturer) == 4,
              "MDB cashless manufacturer must be 3 chars");
static_assert(sizeof(kMdbCashlessReaderId) == 13,
              "MDB cashless reader id must be 12 chars");
static_assert(sizeof(kMdbCashlessModel) == 13,
              "MDB cashless model must be 12 chars");

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
// All 16 coin type bits = 1 → all coins routed to cashbox, none to change
// tubes. This signals to the VMC that no change can be dispensed.
constexpr uint16_t kMdbCoinChangerRoutingMask = 0xFFFF;
constexpr uint8_t kMdbCoinChangerCoinCredits[16] = {
    1,
    5,
    10,
    50,
    100,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
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
