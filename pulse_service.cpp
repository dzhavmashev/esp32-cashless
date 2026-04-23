#include "pulse_service.h"

#include "device_config.h"

namespace {
const char* payTypeToString(PulsePayType payType) {
  switch (payType) {
    case PulsePayType::Cash:
      return "cash";
    case PulsePayType::Coin:
      return "coin";
    case PulsePayType::All:
    default:
      return "all";
  }
}
}

// Инициализирует выходы импульсов и значения конфига по умолчанию.
void PulseService::begin() {
  config_.payType = PulsePayType::All;
  config_.bill.pulseOnTimeMs = BILL_PULSE_ON_TIME_MS_DEFAULT;
  config_.bill.pulseOffTimeMs = BILL_PULSE_OFF_TIME_MS_DEFAULT;
  config_.bill.minorUnitsPerPulse = BILL_MINOR_UNITS_PER_PULSE_DEFAULT;

  config_.coin.pulseOnTimeMs = COIN_PULSE_ON_TIME_MS_DEFAULT;
  config_.coin.pulseOffTimeMs = COIN_PULSE_OFF_TIME_MS_DEFAULT;
  config_.coin.minorUnitsPerPulse = COIN_MINOR_UNITS_PER_PULSE_DEFAULT;

  pinMode(BILL_PULSE_OUTPUT_PIN, OUTPUT);
  pinMode(COIN_PULSE_OUTPUT_PIN, OUTPUT);
  setAllPulseOutputsLow();
}

// Обслуживает pulse-последовательность и отложенный reboot.
void PulseService::update() {
  if (pulseActive_) {
    if (millis() < pulseStateEndsAt_) {
      return;
    }

    if (pulseRemainingTransitions_ == 0) {
      pulseActive_ = false;
      pulseOutputState_ = false;
      if (activePhase_.pin >= 0) {
        setPulseOutput(activePhase_.pin, false);
      }
      Serial.print("Pulse phase completed: ");
      Serial.println(activePhase_.label == nullptr ? "unknown" : activePhase_.label);
      activePhase_ = PulsePhase();
      if (promoteQueuedPhase()) {
        return;
      }
      Serial.println("Pulse sequence completed");
      restartIfReady();
      return;
    }

    pulseOutputState_ = !pulseOutputState_;
    setPulseOutput(activePhase_.pin, pulseOutputState_);
    pulseRemainingTransitions_--;
    pulseStateEndsAt_ =
        millis() + (pulseOutputState_ ? activePhase_.pulseOnTimeMs
                                      : activePhase_.pulseOffTimeMs);
    return;
  }

  restartIfReady();
}

// Запускает импульсную последовательность для заданной суммы.
void PulseService::requestPulse(unsigned long amountMinor) {
  if (pulseActive_ || queuedPhasePending_) {
    Serial.print("Pulse request ignored, sequence in progress. Amount minor: ");
    Serial.println(amountMinor);
    return;
  }

  if (amountMinor == 0) {
    Serial.println("Pulse request ignored: amount is 0");
    return;
  }

  PulsePlan plan;
  if (!buildPulsePlan(amountMinor, plan)) {
    Serial.print("Pulse split failed, amount minor: ");
    Serial.println(amountMinor);
    Serial.print("bill.minorUnitsPerPulse: ");
    Serial.println(config_.bill.minorUnitsPerPulse);
    Serial.print("coin.minorUnitsPerPulse: ");
    Serial.println(config_.coin.minorUnitsPerPulse);
    return;
  }

  Serial.print("Pulse requested, amount minor: ");
  Serial.println(amountMinor);
  Serial.print("Pulse pay type: ");
  Serial.println(payTypeToString(config_.payType));
  Serial.print("Bill split amount minor: ");
  Serial.println(plan.billAmountMinor);
  Serial.print("Bill pulse count: ");
  Serial.println(plan.billPulseCount);
  Serial.print("Coin split amount minor: ");
  Serial.println(plan.coinAmountMinor);
  Serial.print("Coin pulse count: ");
  Serial.println(plan.coinPulseCount);
  const unsigned long ignoredAmountMinor =
      amountMinor - plan.billAmountMinor - plan.coinAmountMinor;
  if (ignoredAmountMinor > 0) {
    Serial.print("Ignored remainder minor: ");
    Serial.println(ignoredAmountMinor);
  }

  PulsePhase firstPhase;
  PulsePhase secondPhase;
  if (plan.billPulseCount > 0) {
    firstPhase.pin = BILL_PULSE_OUTPUT_PIN;
    firstPhase.label = "bill";
    firstPhase.amountMinor = plan.billAmountMinor;
    firstPhase.pulseCount = plan.billPulseCount;
    firstPhase.pulseOnTimeMs = config_.bill.pulseOnTimeMs;
    firstPhase.pulseOffTimeMs = config_.bill.pulseOffTimeMs;
  }
  if (plan.coinPulseCount > 0) {
    PulsePhase coinPhase;
    coinPhase.pin = COIN_PULSE_OUTPUT_PIN;
    coinPhase.label = "coin";
    coinPhase.amountMinor = plan.coinAmountMinor;
    coinPhase.pulseCount = plan.coinPulseCount;
    coinPhase.pulseOnTimeMs = config_.coin.pulseOnTimeMs;
    coinPhase.pulseOffTimeMs = config_.coin.pulseOffTimeMs;
    if (firstPhase.pin < 0) {
      firstPhase = coinPhase;
    } else {
      secondPhase = coinPhase;
    }
  }

  if (firstPhase.pin < 0 || firstPhase.pulseCount == 0) {
    Serial.println("Pulse request ignored: split produced no active phase");
    return;
  }

  queuedPhasePending_ = secondPhase.pin >= 0 && secondPhase.pulseCount > 0;
  queuedPhase_ = queuedPhasePending_ ? secondPhase : PulsePhase();
  startPhase(firstPhase);
}

// Планирует безопасную перезагрузку после завершения импульсов.
void PulseService::requestReboot() {
  rebootRequested_ = true;
  Serial.println("Reboot requested");
}

// Возвращает признак активной pulse-последовательности.
bool PulseService::isActive() const { return pulseActive_ || queuedPhasePending_; }

// Применяет новый pulse-конфиг с валидацией.
void PulseService::applyConfig(const PulseConfig& config) {
  const bool billEnabled = config.bill.minorUnitsPerPulse > 0;
  const bool coinEnabled = config.coin.minorUnitsPerPulse > 0;
  if (!billEnabled && !coinEnabled) {
    Serial.println("Rejected pulse config: both bill and coin channels are disabled");
    return;
  }

  if ((billEnabled &&
       (config.bill.pulseOnTimeMs == 0 || config.bill.pulseOffTimeMs == 0)) ||
      (coinEnabled &&
       (config.coin.pulseOnTimeMs == 0 || config.coin.pulseOffTimeMs == 0))) {
    Serial.println("Rejected pulse config with zero timing on enabled channel");
    return;
  }

  config_ = config;
}

// Возвращает действующий pulse-конфиг.
const PulseConfig& PulseService::config() const { return config_; }

// Собирает точный план разбиения суммы между bill и coin каналами.
bool PulseService::buildPulsePlan(unsigned long amountMinor, PulsePlan& plan) const {
  plan = {};
  if (amountMinor == 0) {
    return false;
  }

  const unsigned long billUnit = config_.bill.minorUnitsPerPulse;
  const unsigned long coinUnit = config_.coin.minorUnitsPerPulse;

  if (billUnit == 0 && coinUnit == 0) {
    return false;
  }

  if (config_.payType == PulsePayType::Cash) {
    if (billUnit == 0) {
      return false;
    }
    plan.billPulseCount = amountMinor / billUnit;
    if (plan.billPulseCount == 0) {
      return false;
    }
    plan.billAmountMinor = plan.billPulseCount * billUnit;
    return plan.billPulseCount > 0;
  }

  if (config_.payType == PulsePayType::Coin) {
    if (coinUnit == 0) {
      return false;
    }
    plan.coinPulseCount = amountMinor / coinUnit;
    if (plan.coinPulseCount == 0) {
      return false;
    }
    plan.coinAmountMinor = plan.coinPulseCount * coinUnit;
    return plan.coinPulseCount > 0;
  }

  if (billUnit == 0) {
    if (coinUnit == 0 || (amountMinor % coinUnit) != 0) {
      return false;
    }
    plan.coinAmountMinor = amountMinor;
    plan.coinPulseCount = amountMinor / coinUnit;
    return plan.coinPulseCount > 0;
  }

  if (coinUnit == 0) {
    if ((amountMinor % billUnit) != 0) {
      return false;
    }
    plan.billAmountMinor = amountMinor;
    plan.billPulseCount = amountMinor / billUnit;
    return plan.billPulseCount > 0;
  }

  const unsigned long maxBillPulses = amountMinor / billUnit;
  for (unsigned long candidate = maxBillPulses + 1; candidate-- > 0;) {
    const unsigned long billAmount = candidate * billUnit;
    const unsigned long remainder = amountMinor - billAmount;
    if ((remainder % coinUnit) != 0) {
      continue;
    }

    const unsigned long coinPulses = remainder / coinUnit;
    if (candidate == 0 && coinPulses == 0) {
      continue;
    }

    plan.billAmountMinor = billAmount;
    plan.billPulseCount = candidate;
    plan.coinAmountMinor = remainder;
    plan.coinPulseCount = coinPulses;
    return true;
  }

  return false;
}

// Запускает одну фазу pulse-последовательности.
void PulseService::startPhase(const PulsePhase& phase) {
  activePhase_ = phase;
  pulseActive_ = true;
  pulseOutputState_ = true;
  pulseRemainingTransitions_ = phase.pulseCount * 2UL - 1UL;
  pulseStateEndsAt_ = millis() + phase.pulseOnTimeMs;
  setAllPulseOutputsLow();
  setPulseOutput(phase.pin, true);
  Serial.print("Pulse phase started: ");
  Serial.print(phase.label == nullptr ? "unknown" : phase.label);
  Serial.print(", amount minor: ");
  Serial.print(phase.amountMinor);
  Serial.print(", pulse count: ");
  Serial.println(phase.pulseCount);
}

// Переключает сервис на следующую очередь импульсов.
bool PulseService::promoteQueuedPhase() {
  if (!queuedPhasePending_) {
    return false;
  }

  const PulsePhase nextPhase = queuedPhase_;
  queuedPhasePending_ = false;
  queuedPhase_ = PulsePhase();
  startPhase(nextPhase);
  return true;
}

// Физически переключает конкретный GPIO pulse-линии.
void PulseService::setPulseOutput(int pin, bool enabled) {
  if (pin < 0) {
    return;
  }
  digitalWrite(pin, enabled ? HIGH : LOW);
}

// Гарантированно опускает оба pulse-выхода.
void PulseService::setAllPulseOutputsLow() {
  digitalWrite(BILL_PULSE_OUTPUT_PIN, LOW);
  digitalWrite(COIN_PULSE_OUTPUT_PIN, LOW);
}

// Выполняет reboot, когда это уже безопасно.
void PulseService::restartIfReady() {
  if (!rebootRequested_ || pulseActive_ || queuedPhasePending_) {
    return;
  }

  Serial.println("Rebooting device");
  delay(100);
  ESP.restart();
}
