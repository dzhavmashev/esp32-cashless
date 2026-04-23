#pragma once

#include <Arduino.h>

// Управляет жизненным циклом кредитной cashless-сессии на стороне устройства.
class CashlessSession {
 public:
  // Состояния высокоуровневой cashless-сессии.
  enum class State {
    kBoot,
    kWaitLink,
    kDisabled,
    kReadyNoFunds,
    kFundsPendingApproval,
    kFundsApproved,
    kSessionActive,
    kVendInProgress,
    kWaitVendResult,
    kSessionComplete,
    kErrorRecovery,
  };

  // Снимок текущего состояния сессии для логирования и REST-диагностики.
  struct Snapshot {
    State state = State::kBoot;
    unsigned long pendingAmountMinor = 0;
    unsigned long approvedAmountMinor = 0;
    unsigned long reservedAmountMinor = 0;
    String pendingTransactionId;
    String approvedTransactionId;
    unsigned long lastTransitionAt = 0;
  };

  // Результат решения по запросу vend.
  struct VendDecision {
    bool approved = false;
    unsigned long requestedAmountMinor = 0;
  };

  // Инициализирует сессию при старте прошивки.
  void begin(bool linkUp, unsigned long now);
  // Обновляет состояние при изменении связи с backend.
  void update(bool linkUp, unsigned long now);
  // Регистрирует полученный платёж, но не делает его видимым для автомата.
  bool recordPayment(unsigned long amountMinor, const String& transactionId,
                     unsigned long now, String& reason, bool& changed);
  // Переводит pending-платёж в активный кредит для автомата.
  bool approvePayment(unsigned long amountMinor, const String& transactionId,
                      unsigned long now, String& reason, bool& changed);
  // Полностью очищает текущую сессию и все суммы.
  void clear(unsigned long now);
  // Переводит сессию в состояние, соответствующее включению ридера.
  void onReaderEnabled(unsigned long now);
  // Переводит сессию в состояние отключённого ридера.
  void onReaderDisabled(unsigned long now);
  // Принимает решение по запросу vend от автомата.
  VendDecision onVendRequest(unsigned long requestedAmountMinor, unsigned long now);
  // Завершает успешную продажу и списывает резерв.
  void onVendSuccess(unsigned long now);
  // Обрабатывает неуспешную продажу и снимает резерв.
  void onVendFailure(unsigned long now);
  // Возвращает признак, можно ли безопасно запускать OTA.
  bool isSafeForOta() const;
  // Возвращает актуальный снимок состояния.
  const Snapshot& snapshot() const;
  // Преобразует enum состояния в строку для логов и API.
  static const char* stateToString(State state);

 private:
  // Выполняет переход между состояниями и фиксирует время перехода.
  void transitionTo(State state, unsigned long now);

  Snapshot snapshot_ = {};
};
