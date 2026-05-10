// main.cpp  v2
// MDB Cashless Device #1 (address 0x10) emulator + self-diagnostic
// Target: Jofemar Bluetec G23
//
// ИЗМЕНЕНИЯ ОТ v1:
//   1. Логирование ПЕРЕНЕСЕНО на момент ПОСЛЕ TX (queueLog/flushLog).
//      Раньше Serial.print выполнялся ДО sendAck() и блокировал TX
//      на ~1ms на каждый UART-байт лога, ESP отвечал слишком поздно
//      (за 5ms окно t-response не успевал) — VMC игнорировала ответ.
//   2. Команды диагностики для МУЛЬТИМЕТРА:
//        tx0      - удерживает TX в LOW (start-bit уровень)
//        tx1      - удерживает TX в HIGH (idle уровень)
//        txinv    - переключает TX_INVERT на лету
//        rxinv    - переключает RX_INVERT на лету
//        ackmode 0|1 - переключает mode bit на ACK
//        selftest - шлёт 100 байт 0xAA для измерения среднего напряжения
//        status   - выводит счётчики RX/TX/RESET/POLL для диагностики
//   3. ACK_MODE_BIT можно изменить runtime (по умолчанию 1 как по спеку).
//
// ПОРЯДОК ДИАГНОСТИКИ С МУЛЬТИМЕТРОМ:
//   Шаг 1 (без VMC, или с VMC):
//     - Подключи мультиметр (DC) между MDB SIGNAL и GND
//     - В Serial Monitor: tx1
//     - Жди 5 секунд, запиши напряжение -> это IDLE level
//     - В Serial Monitor: tx0
//     - Жди 5 секунд, запиши напряжение -> это START-BIT level
//     - В Serial Monitor: txidle
//
//   Ожидаемые значения для классического MDB:
//     IDLE (tx1):  ~5V (или ~12V если MDB-V12)
//     START (tx0): ~0V (или близко к GND)
//
//   Если у тебя tx1=0V и tx0=5V -> TX_INVERT надо переключить (txinv).
//   Если оба одинаковые -> схема сломана (BC337 не открывается, или
//   обрыв в цепи между ESP GPIO и MDB SIGNAL).
//
//   Шаг 2 (с подключённой VMC):
//     - status показывает счётчики: RX bytes, RX our frames, TX bytes,
//       RESET received, POLL received
//     - Если RX bytes = 0 -> VMC вообще не общается с шиной (питание?)
//     - Если RX bytes > 0 но "our frames" = 0 -> RX работает,
//       но VMC не шлёт ничего на адрес 0x10 (cashless#1 отключён в меню?)
//     - Если "RESET received" растёт, но "POLL received" = 0 -> VMC видит
//       cashless, но НЕ принимает наш ACK на RESET. Это TX-проблема.

#include <Arduino.h>

// ===================== HARDWARE =====================

static const int MDB_RX_PIN = 14;
static const int MDB_TX_PIN = 19;

static const uint16_t BIT_US = 104;
static const uint16_t HALF_BIT_US = 52;

// Можно переключать командами txinv/rxinv runtime.
static volatile bool RX_INVERT = false;
static volatile bool TX_INVERT = true;

static const uint32_t RX_MUTE_AFTER_TX_US = 1500;
static const uint32_t MIN_START_GAP_US = 650;

// ===================== MDB ADDRESS =====================

static const uint8_t MDB_ADDR_CASHLESS1 = 0x10;
static const uint8_t MDB_OPCODE_MASK = 0xF8;
static const uint8_t MDB_CMD_MASK = 0x07;

static volatile bool ACK_MODE_BIT = true;

// ===================== STATE =====================

enum CashlessState : uint8_t
{
    ST_INACTIVE = 0,
    ST_DISABLED,
    ST_ENABLED,
    ST_SESSION_IDLE,
    ST_VEND,
};

static CashlessState state = ST_INACTIVE;
static bool justResetPending = false;
static bool cardPresent = false;
static uint16_t cardBalance = 0;

static uint8_t rxBuf[36];
static size_t rxLen = 0;
static uint32_t rxLastByteUs = 0;
static const uint32_t RX_FRAME_TIMEOUT_US = 5000;

static uint32_t rxMuteUntilUs = 0;
static uint32_t lastStartUs = 0;

static char cmdBuf[64];
static uint8_t cmdLen = 0;

// Diagnostic counters.
static uint32_t cntRxBytes = 0;
static uint32_t cntRxOurFrames = 0;
static uint32_t cntTxBytes = 0;
static uint32_t cntResetReceived = 0;
static uint32_t cntPollReceived = 0;
static uint32_t cntAckSent = 0;

// Deferred logging (printed in main loop, not from inside TX).
static char pendingLog[80];
static volatile bool hasPendingLog = false;

static inline void queueLog(const char *s)
{
    if (hasPendingLog)
        return; // не перезаписываем
    strncpy(pendingLog, s, sizeof(pendingLog) - 1);
    pendingLog[sizeof(pendingLog) - 1] = '\0';
    hasPendingLog = true;
}

static inline void flushLog()
{
    if (hasPendingLog)
    {
        Serial.println(pendingLog);
        hasPendingLog = false;
    }
}

// ===================== LOW-LEVEL IO =====================

static inline bool readRxLogical()
{
    const bool raw = digitalRead(MDB_RX_PIN);
    return RX_INVERT ? !raw : raw;
}

static inline void writeTxLogical(bool logicalHigh)
{
    const bool gpioLevel = TX_INVERT ? !logicalHigh : logicalHigh;
    digitalWrite(MDB_TX_PIN, gpioLevel ? HIGH : LOW);
}

static void txIdle() { writeTxLogical(true); }

static void printHex(uint8_t b)
{
    if (b < 0x10)
        Serial.print('0');
    Serial.print(b, HEX);
}

// ===================== TX 9-bit =====================

static void IRAM_ATTR sendWord(uint8_t b, bool ninth)
{
    writeTxLogical(false); // start
    delayMicroseconds(BIT_US);
    for (uint8_t i = 0; i < 8; i++)
    {
        writeTxLogical((b >> i) & 0x01);
        delayMicroseconds(BIT_US);
    }
    writeTxLogical(ninth); // 9th
    delayMicroseconds(BIT_US);
    writeTxLogical(true); // stop / idle
    delayMicroseconds(BIT_US);
    cntTxBytes++;
}

static void muteRxAfterTx() { rxMuteUntilUs = micros() + RX_MUTE_AFTER_TX_US; }

// ВАЖНО: send first, log later. Иначе Serial.print задержит TX > 5ms.
static void sendAck()
{
    sendWord(0x00, ACK_MODE_BIT);
    muteRxAfterTx();
    cntAckSent++;
    queueLog("[TX] ACK");
}

static void sendNak()
{
    sendWord(0xFF, true);
    muteRxAfterTx();
    queueLog("[TX] NAK");
}

static void sendDataWithChecksum(const uint8_t *data, size_t len, const char *label)
{
    uint16_t sum = 0;
    for (size_t i = 0; i < len; i++)
        sum += data[i];
    const uint8_t chk = static_cast<uint8_t>(sum & 0xFF);

    for (size_t i = 0; i < len; i++)
        sendWord(data[i], false);
    sendWord(chk, true);

    muteRxAfterTx();

    char buf[80];
    snprintf(buf, sizeof(buf), "[TX] %s", label);
    queueLog(buf);
}

// ===================== RESPONSES =====================

static void respondJustReset()
{
    static const uint8_t p[] = {0x00};
    sendDataWithChecksum(p, sizeof(p), "JUST_RESET");
    justResetPending = false;
}

static void respondReaderConfig()
{
    const uint8_t p[] = {
        0x01,       // marker
        0x01,       // feature level 1
        0x00, 0x07, // country
        0x01,       // scale
        0x02,       // decimals
        0x05,       // max response time, sec
        0x00        // misc options
    };
    sendDataWithChecksum(p, sizeof(p), "READER_CONFIG");
}

static void respondPeripheralId()
{
    uint8_t p[30];
    p[0] = 0x09;
    p[1] = 'E';
    p[2] = 'S';
    p[3] = 'P';
    for (int i = 0; i < 11; i++)
        p[4 + i] = '0';
    p[15] = '1';
    const char model[12] = {'M', 'D', 'B', '-', 'C', 'A', 'S', 'H', 'L', 'E', 'S', 'S'};
    for (int i = 0; i < 12; i++)
        p[16 + i] = model[i];
    p[28] = 0x00;
    p[29] = 0x01;
    sendDataWithChecksum(p, sizeof(p), "PERIPHERAL_ID");
}

static void respondBeginSession(uint16_t funds)
{
    const uint8_t p[] = {0x03, (uint8_t)((funds >> 8) & 0xFF), (uint8_t)(funds & 0xFF)};
    sendDataWithChecksum(p, sizeof(p), "BEGIN_SESSION");
}

static void respondVendApproved(uint16_t amt)
{
    const uint8_t p[] = {0x05, (uint8_t)((amt >> 8) & 0xFF), (uint8_t)(amt & 0xFF)};
    sendDataWithChecksum(p, sizeof(p), "VEND_APPROVED");
}

static void respondVendDenied()
{
    const uint8_t p[] = {0x06};
    sendDataWithChecksum(p, sizeof(p), "VEND_DENIED");
}

static void respondEndSession()
{
    const uint8_t p[] = {0x07};
    sendDataWithChecksum(p, sizeof(p), "END_SESSION");
}

static void respondCancelled()
{
    const uint8_t p[] = {0x08};
    sendDataWithChecksum(p, sizeof(p), "CANCELLED");
}

// ===================== STATE HELPERS =====================

static const char *stateName(CashlessState s)
{
    switch (s)
    {
    case ST_INACTIVE:
        return "INACTIVE";
    case ST_DISABLED:
        return "DISABLED";
    case ST_ENABLED:
        return "ENABLED";
    case ST_SESSION_IDLE:
        return "SESSION_IDLE";
    case ST_VEND:
        return "VEND";
    default:
        return "?";
    }
}

static void setState(CashlessState s)
{
    if (s != state)
    {
        char buf[64];
        snprintf(buf, sizeof(buf), "[STATE] %s -> %s", stateName(state), stateName(s));
        queueLog(buf);
        state = s;
    }
}

static bool checksumOk(const uint8_t *data, size_t len)
{
    if (len < 2)
        return false;
    uint16_t sum = 0;
    for (size_t i = 0; i < len - 1; i++)
        sum += data[i];
    return (sum & 0xFF) == data[len - 1];
}

// FAST: do not Serial.print here. queueLog only.
static void handleOurFrame(const uint8_t *data, size_t len)
{
    cntRxOurFrames++;

    if (len >= 2 && !checksumOk(data, len))
    {
        queueLog("[RX] checksum FAIL");
        return;
    }

    const uint8_t addr = data[0] & MDB_OPCODE_MASK;
    const uint8_t cmd = data[0] & MDB_CMD_MASK;

    if (addr != MDB_ADDR_CASHLESS1)
        return;

    switch (cmd)
    {
    case 0x00: // RESET
        cntResetReceived++;
        setState(ST_INACTIVE);
        justResetPending = true;
        sendAck();
        break;

    case 0x01: // SETUP
        if (len < 2)
        {
            sendNak();
            break;
        }
        if (data[1] == 0x00)
        {
            respondReaderConfig();
            if (state == ST_INACTIVE)
                setState(ST_DISABLED);
        }
        else if (data[1] == 0x01)
        {
            sendAck();
        }
        else
        {
            sendNak();
        }
        break;

    case 0x02: // POLL
        cntPollReceived++;
        if (justResetPending)
        {
            respondJustReset();
        }
        else if (state == ST_ENABLED && cardPresent)
        {
            respondBeginSession(cardBalance);
            setState(ST_SESSION_IDLE);
        }
        else
        {
            sendAck();
        }
        break;

    case 0x03: // VEND
        if (len < 2)
        {
            sendNak();
            break;
        }
        if (data[1] == 0x00 && len >= 7)
        {
            const uint16_t price = (data[2] << 8) | data[3];
            if (state != ST_SESSION_IDLE || price > cardBalance)
            {
                respondVendDenied();
            }
            else
            {
                cardBalance -= price;
                respondVendApproved(price);
                setState(ST_VEND);
            }
        }
        else if (data[1] == 0x01)
        {
            respondVendDenied();
        }
        else if (data[1] == 0x02)
        {
            sendAck();
            setState(ST_SESSION_IDLE);
        }
        else if (data[1] == 0x03)
        {
            sendAck();
            setState(ST_SESSION_IDLE);
        }
        else if (data[1] == 0x04)
        {
            respondEndSession();
            cardPresent = false;
            setState(ST_ENABLED);
        }
        else if (data[1] == 0x05)
        {
            sendAck();
        }
        else
        {
            sendNak();
        }
        break;

    case 0x04: // READER
        if (len < 2)
        {
            sendNak();
            break;
        }
        if (data[1] == 0x00)
        {
            sendAck();
            if (state == ST_ENABLED || state == ST_SESSION_IDLE)
                setState(ST_DISABLED);
        }
        else if (data[1] == 0x01)
        {
            sendAck();
            if (state == ST_DISABLED)
            {
                setState(ST_ENABLED);
                queueLog("[!!!] READER LIVE");
            }
        }
        else if (data[1] == 0x02)
        {
            respondCancelled();
        }
        else
        {
            sendNak();
        }
        break;

    case 0x07: // EXPANSION
        if (len >= 2 && data[1] == 0x00)
        {
            respondPeripheralId();
        }
        else
        {
            sendAck();
        }
        break;

    default:
        sendNak();
        break;
    }
}

// ===================== RX 9-bit =====================

static bool readMdbWord(uint8_t &outByte, bool &outNinth)
{
    const uint32_t now = micros();
    if ((int32_t)(now - rxMuteUntilUs) < 0)
        return false;
    if ((uint32_t)(now - lastStartUs) < MIN_START_GAP_US)
        return false;
    lastStartUs = now;

    delayMicroseconds(HALF_BIT_US + BIT_US);

    uint8_t b = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
        if (readRxLogical())
            b |= (1U << i);
        delayMicroseconds(BIT_US);
    }
    const bool ninth = readRxLogical();
    delayMicroseconds(BIT_US);

    outByte = b;
    outNinth = ninth;
    cntRxBytes++;
    return true;
}

static void clearRx() { rxLen = 0; }

static void onRxWord(uint8_t b, bool ninth)
{
    if (ninth)
    {
        if (rxLen > 0)
        {
            handleOurFrame(rxBuf, rxLen);
            clearRx();
        }
        const uint8_t addr = b & MDB_OPCODE_MASK;
        if (addr != MDB_ADDR_CASHLESS1)
        {
            clearRx();
            return;
        }
        rxBuf[0] = b;
        rxLen = 1;
        rxLastByteUs = micros();
    }
    else
    {
        if (rxLen == 0)
            return;
        if (rxLen < sizeof(rxBuf))
        {
            rxBuf[rxLen++] = b;
            rxLastByteUs = micros();
        }
        else
        {
            clearRx();
            return;
        }
        if (rxLen >= 2 && checksumOk(rxBuf, rxLen))
        {
            handleOurFrame(rxBuf, rxLen);
            clearRx();
        }
    }
}

// ===================== SERIAL =====================

static void printStatus()
{
    Serial.println("---- STATUS ----");
    Serial.print("state=");
    Serial.println(stateName(state));
    Serial.print("justReset=");
    Serial.println(justResetPending ? "Y" : "N");
    Serial.print("card=");
    Serial.print(cardPresent ? "Y" : "N");
    Serial.print(" balance=");
    Serial.println(cardBalance);
    Serial.print("RX_INVERT=");
    Serial.print(RX_INVERT ? "Y" : "N");
    Serial.print(" TX_INVERT=");
    Serial.print(TX_INVERT ? "Y" : "N");
    Serial.print(" ACK_MODE_BIT=");
    Serial.println(ACK_MODE_BIT ? "1" : "0");
    Serial.println("---- COUNTERS ----");
    Serial.print("RX bytes:    ");
    Serial.println(cntRxBytes);
    Serial.print("RX our frm:  ");
    Serial.println(cntRxOurFrames);
    Serial.print("TX bytes:    ");
    Serial.println(cntTxBytes);
    Serial.print("ACKs sent:   ");
    Serial.println(cntAckSent);
    Serial.print("RESETs got:  ");
    Serial.println(cntResetReceived);
    Serial.print("POLLs got:   ");
    Serial.println(cntPollReceived);
    Serial.println("DIAGNOSIS:");
    if (cntRxBytes == 0)
    {
        Serial.println("  RX silent - check VMC power & RX wiring");
    }
    else if (cntRxOurFrames == 0)
    {
        Serial.println("  RX works but no frames for 0x10 - cashless not enabled in VMC menu?");
    }
    else if (cntResetReceived > 0 && cntPollReceived == 0)
    {
        Serial.println("  *** VMC sees us (RESET arrives) but doesn't accept ACK ***");
        Serial.println("  *** This means TX is broken or polarity is wrong ***");
        Serial.println("  *** Run: tx0, tx1 with multimeter on MDB SIGNAL ***");
    }
    else if (cntPollReceived > 0)
    {
        Serial.println("  Handshake progressing - good!");
    }
    Serial.println("------------------");
}

static void printHelp()
{
    Serial.println("---- COMMANDS ----");
    Serial.println("DIAGNOSTIC (no VMC traffic interference):");
    Serial.println("  tx0      - hold TX LOW (start-bit level)");
    Serial.println("  tx1      - hold TX HIGH (idle level)");
    Serial.println("  txidle   - back to idle");
    Serial.println("  selftest - send 100 bytes 0xAA, ~50% duty");
    Serial.println("CONFIG (try if no response from VMC):");
    Serial.println("  txinv    - toggle TX_INVERT");
    Serial.println("  rxinv    - toggle RX_INVERT");
    Serial.println("  ackmode 0|1 - ACK mode bit");
    Serial.println("STATE:");
    Serial.println("  status   - show counters & diagnosis");
    Serial.println("  reset    - force INACTIVE");
    Serial.println("CARD:");
    Serial.println("  card N   - present card with balance N (e.g. card 100)");
    Serial.println("  remove   - remove card");
}

static void selftest()
{
    Serial.println("[SELFTEST] sending 100 alternating bytes (0xAA)...");
    Serial.println("[SELFTEST] measure DC voltage on MDB SIGNAL during this time");
    Serial.println("[SELFTEST] expected: ~half of supply if TX works");
    delay(1000);
    for (int i = 0; i < 100; i++)
    {
        sendWord(0xAA, (i & 1) == 0);
        delay(2);
    }
    txIdle();
    Serial.println("[SELFTEST] done");
}

static void processSerialLine(const char *line)
{
    String s(line);
    s.trim();
    s.toLowerCase();
    if (s.length() == 0)
        return;

    if (s.startsWith("card "))
    {
        const long amt = s.substring(5).toInt();
        if (amt <= 0 || amt > 65535)
        {
            Serial.println("[CMD] bad amount");
            return;
        }
        cardBalance = (uint16_t)amt;
        cardPresent = true;
        Serial.print("[CMD] card balance=");
        Serial.println(cardBalance);
    }
    else if (s == "remove")
    {
        cardPresent = false;
        cardBalance = 0;
        Serial.println("[CMD] removed");
    }
    else if (s == "status")
    {
        printStatus();
    }
    else if (s == "reset")
    {
        setState(ST_INACTIVE);
        justResetPending = true;
        cardPresent = false;
        cardBalance = 0;
        Serial.println("[CMD] forced INACTIVE");
    }
    else if (s == "txinv")
    {
        TX_INVERT = !TX_INVERT;
        txIdle();
        Serial.print("[CMD] TX_INVERT=");
        Serial.println(TX_INVERT ? "Y" : "N");
    }
    else if (s == "rxinv")
    {
        RX_INVERT = !RX_INVERT;
        Serial.print("[CMD] RX_INVERT=");
        Serial.println(RX_INVERT ? "Y" : "N");
    }
    else if (s == "tx0")
    {
        writeTxLogical(false);
        Serial.println("[CMD] TX held LOW. Measure MDB SIGNAL with multimeter (DC).");
    }
    else if (s == "tx1")
    {
        writeTxLogical(true);
        Serial.println("[CMD] TX held HIGH. Measure MDB SIGNAL with multimeter (DC).");
    }
    else if (s == "txidle")
    {
        txIdle();
        Serial.println("[CMD] TX -> idle");
    }
    else if (s.startsWith("ackmode "))
    {
        ACK_MODE_BIT = (s.substring(8).toInt() != 0);
        Serial.print("[CMD] ACK_MODE_BIT=");
        Serial.println(ACK_MODE_BIT ? "1" : "0");
    }
    else if (s == "selftest")
    {
        selftest();
    }
    else if (s == "help" || s == "?")
    {
        printHelp();
    }
    else
    {
        Serial.print("[CMD] unknown: ");
        Serial.println(s);
        printHelp();
    }
}

static void pumpSerial()
{
    while (Serial.available() > 0)
    {
        const char c = (char)Serial.read();
        if (c == '\r')
            continue;
        if (c == '\n')
        {
            cmdBuf[cmdLen] = '\0';
            processSerialLine(cmdBuf);
            cmdLen = 0;
        }
        else if (cmdLen < sizeof(cmdBuf) - 1)
        {
            cmdBuf[cmdLen++] = c;
        }
    }
}

// ===================== ARDUINO =====================

void setup()
{
    Serial.begin(115200);
    delay(500);

    pinMode(MDB_RX_PIN, INPUT);
    pinMode(MDB_TX_PIN, OUTPUT);
    txIdle();

    lastStartUs = micros();

    Serial.println();
    Serial.println("=========================================");
    Serial.println("MDB Cashless#1 emulator v2 + diagnostic");
    Serial.println("Target: Jofemar Bluetec G23");
    Serial.println("=========================================");
    Serial.print("RX=");
    Serial.print(MDB_RX_PIN);
    Serial.print(" TX=");
    Serial.print(MDB_TX_PIN);
    Serial.print(" BIT_US=");
    Serial.println(BIT_US);
    Serial.print("RX_INVERT=");
    Serial.print(RX_INVERT ? "Y" : "N");
    Serial.print(" TX_INVERT=");
    Serial.println(TX_INVERT ? "Y" : "N");
    Serial.println();
    Serial.println(">>> FIRST: do TX hardware check with multimeter <<<");
    Serial.println(">>> tx1 (measure idle), tx0 (measure low), txidle <<<");
    Serial.println();
    printHelp();
    Serial.println("=========================================");
    Serial.print("[STATE] ");
    Serial.println(stateName(state));
}

void loop()
{
    static bool initialized = false;
    static bool prevLogical = false;

    pumpSerial();
    flushLog();

    bool logical = readRxLogical();

    if (!initialized)
    {
        prevLogical = logical;
        initialized = true;
        return;
    }

    if (prevLogical == true && logical == false)
    {
        uint8_t b = 0;
        bool ninth = false;
        if (readMdbWord(b, ninth))
            onRxWord(b, ninth);
        logical = readRxLogical();
    }
    prevLogical = logical;

    if (rxLen > 0 && (uint32_t)(micros() - rxLastByteUs) > RX_FRAME_TIMEOUT_US)
    {
        if (rxLen >= 2 && checksumOk(rxBuf, rxLen))
            handleOurFrame(rxBuf, rxLen);
        clearRx();
    }
}