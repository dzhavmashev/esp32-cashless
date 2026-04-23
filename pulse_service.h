#pragma once

#include <Arduino.h>

// Конфигурация pulse-выхода для режима импульсной оплаты.
struct PulseChannelConfig {
  unsigned long pulseOnTimeMs = 100;
  unsigned long pulseOffTimeMs = 100;
  unsigned long minorUnitsPerPulse = 100;
};

enum class PulsePayType : uint8_t {
  All = 0,
  Cash = 1,
  Coin = 2,
};

struct PulseConfig {
  PulsePayType payType = PulsePayType::All;
  PulseChannelConfig bill;
  PulseChannelConfig coin;
};

// Управляет формированием импульсов на выходе и безопасной перезагрузкой.
class PulseService {
 public:
  // Инициализирует GPIO и значения pulse-конфига по умолчанию.
  void begin();
  // Обслуживает активную последовательность импульсов.
  void update();
  // Запускает последовательность импульсов для указанной суммы.
  void requestPulse(unsigned long amountMinor);
  // Планирует безопасную перезагрузку после завершения импульсов.
  void requestReboot();
  // Возвращает признак активной pulse-последовательности.
  bool isActive() const;
  // Применяет новый pulse-конфиг.
  void applyConfig(const PulseConfig& config);
  // Возвращает текущий pulse-конфиг.
  const PulseConfig& config() const;

 private:
  struct PulsePlan {
    unsigned long billAmountMinor = 0;
    unsigned long billPulseCount = 0;
    unsigned long coinAmountMinor = 0;
    unsigned long coinPulseCount = 0;
  };

  struct PulsePhase {
    int pin = -1;
    const char* label = nullptr;
    unsigned long amountMinor = 0;
    unsigned long pulseCount = 0;
    unsigned long pulseOnTimeMs = 0;
    unsigned long pulseOffTimeMs = 0;
  };

  // Строит точный план разбиения суммы между bill и coin pulse-каналами.
  bool buildPulsePlan(unsigned long amountMinor, PulsePlan& plan) const;
  // Запускает одну фазу pulse-последовательности на выбранном канале.
  void startPhase(const PulsePhase& phase);
  // Переключает активный канал на следующую фазу, если она была запланирована.
  bool promoteQueuedPhase();
  // Физически переключает конкретный GPIO pulse-линии.
  void setPulseOutput(int pin, bool enabled);
  // Гарантированно опускает оба pulse-выхода.
  void setAllPulseOutputsLow();
  // Перезагружает устройство, если это уже безопасно.
  void restartIfReady();

  bool pulseActive_ = false;
  bool pulseOutputState_ = false;
  bool rebootRequested_ = false;
  bool queuedPhasePending_ = false;
  unsigned long pulseStateEndsAt_ = 0;
  unsigned long pulseRemainingTransitions_ = 0;
  PulsePhase activePhase_;
  PulsePhase queuedPhase_;
  PulseConfig config_;
};
