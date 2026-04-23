#include "cashless_session.h"

// Инициализирует FSM с учётом доступности backend.
void CashlessSession::begin(bool linkUp, unsigned long now) {
  snapshot_ = {};
  transitionTo(linkUp ? State::kReadyNoFunds : State::kWaitLink, now);
}

// Корректирует состояние сессии при смене связи или после завершения vend.
void CashlessSession::update(bool linkUp, unsigned long now) {
  if (!linkUp) {
    transitionTo(State::kDisabled, now);
    return;
  }

  switch (snapshot_.state) {
    case State::kBoot:
    case State::kWaitLink:
    case State::kDisabled:
      transitionTo(snapshot_.pendingAmountMinor > 0 ? State::kFundsPendingApproval
                                                    : (snapshot_.approvedAmountMinor > 0
                                                           ? State::kFundsApproved
                                                           : State::kReadyNoFunds),
                   now);
      break;
    case State::kSessionComplete:
      transitionTo(snapshot_.approvedAmountMinor > 0 ? State::kFundsApproved
                                                     : (snapshot_.pendingAmountMinor > 0
                                                            ? State::kFundsPendingApproval
                                                            : State::kReadyNoFunds),
                   now);
      break;
    default:
      break;
  }
}

// Сохраняет полученный платёж как pending, не показывая его автомату.
bool CashlessSession::recordPayment(unsigned long amountMinor, const String& transactionId,
                                    unsigned long now, String& reason,
                                    bool& changed) {
  changed = false;
  if (amountMinor == 0) {
    reason = "amount_is_zero";
    return false;
  }

  if (!transactionId.isEmpty() && snapshot_.pendingTransactionId == transactionId) {
    reason = "duplicate_payment";
    return true;
  }

  if (snapshot_.state == State::kSessionActive ||
      snapshot_.state == State::kVendInProgress ||
      snapshot_.state == State::kWaitVendResult) {
    reason = "session_already_active";
    return false;
  }

  snapshot_.pendingAmountMinor += amountMinor;
  if (!transactionId.isEmpty()) {
    snapshot_.pendingTransactionId = transactionId;
  }
  if (snapshot_.state == State::kReadyNoFunds ||
      snapshot_.state == State::kSessionComplete) {
    transitionTo(State::kFundsPendingApproval, now);
  }
  reason = "payment_recorded";
  changed = true;
  return true;
}

// Переводит pending-платёж в активный кредит автомата.
bool CashlessSession::approvePayment(unsigned long amountMinor, const String& transactionId,
                                     unsigned long now, String& reason,
                                     bool& changed) {
  changed = false;
  if (snapshot_.pendingAmountMinor == 0) {
    if (!transactionId.isEmpty() && snapshot_.approvedTransactionId == transactionId) {
      reason = "duplicate_approve";
      return true;
    }
    reason = "no_pending_payment";
    return false;
  }

  if (!transactionId.isEmpty() && !snapshot_.pendingTransactionId.isEmpty() &&
      snapshot_.pendingTransactionId != transactionId) {
    reason = "transaction_mismatch";
    return false;
  }

  if (amountMinor == 0) {
    amountMinor = snapshot_.pendingAmountMinor;
  }
  if (amountMinor > snapshot_.pendingAmountMinor) {
    reason = "amount_exceeds_pending";
    return false;
  }

  snapshot_.pendingAmountMinor -= amountMinor;
  snapshot_.approvedAmountMinor += amountMinor;
  snapshot_.approvedTransactionId =
      !transactionId.isEmpty() ? transactionId : snapshot_.pendingTransactionId;
  if (snapshot_.pendingAmountMinor == 0) {
    snapshot_.pendingTransactionId = "";
  }
  transitionTo(State::kFundsApproved, now);
  reason = "payment_approved";
  changed = true;
  return true;
}

// Полностью очищает текущую сессию и все суммы.
void CashlessSession::clear(unsigned long now) {
  snapshot_.pendingAmountMinor = 0;
  snapshot_.approvedAmountMinor = 0;
  snapshot_.reservedAmountMinor = 0;
  snapshot_.pendingTransactionId = "";
  snapshot_.approvedTransactionId = "";
  transitionTo(State::kReadyNoFunds, now);
}

// Реакция на включение ридера со стороны автомата.
void CashlessSession::onReaderEnabled(unsigned long now) {
  transitionTo(snapshot_.approvedAmountMinor > 0 ? State::kFundsApproved
                                                 : (snapshot_.pendingAmountMinor > 0
                                                        ? State::kFundsPendingApproval
                                                        : State::kReadyNoFunds),
               now);
}

// Реакция на отключение ридера со стороны автомата.
void CashlessSession::onReaderDisabled(unsigned long now) {
  transitionTo(State::kDisabled, now);
}

// Анализирует vend-запрос и при успехе резервирует сумму.
CashlessSession::VendDecision CashlessSession::onVendRequest(
    unsigned long requestedAmountMinor, unsigned long now) {
  VendDecision decision;
  decision.requestedAmountMinor = requestedAmountMinor;

  if (requestedAmountMinor == 0) {
    requestedAmountMinor = snapshot_.approvedAmountMinor;
    decision.requestedAmountMinor = requestedAmountMinor;
  }

  if (snapshot_.approvedAmountMinor == 0 ||
      snapshot_.approvedAmountMinor < requestedAmountMinor) {
    snapshot_.reservedAmountMinor = 0;
    transitionTo(snapshot_.approvedAmountMinor > 0 ? State::kFundsApproved
                                                   : State::kReadyNoFunds,
                 now);
    return decision;
  }

  snapshot_.reservedAmountMinor = requestedAmountMinor;
  transitionTo(State::kSessionActive, now);
  transitionTo(State::kVendInProgress, now);
  transitionTo(State::kWaitVendResult, now);
  decision.approved = true;
  return decision;
}

// Завершает успешный vend и списывает ранее зарезервированную сумму.
void CashlessSession::onVendSuccess(unsigned long now) {
  if (snapshot_.reservedAmountMinor > 0) {
    snapshot_.approvedAmountMinor =
        snapshot_.approvedAmountMinor > snapshot_.reservedAmountMinor
            ? snapshot_.approvedAmountMinor - snapshot_.reservedAmountMinor
            : 0;
  }
  snapshot_.reservedAmountMinor = 0;
  transitionTo(State::kSessionComplete, now);
}

// Завершает неуспешный vend без списания approved-кредита.
void CashlessSession::onVendFailure(unsigned long now) {
  snapshot_.reservedAmountMinor = 0;
  transitionTo(snapshot_.approvedAmountMinor > 0 ? State::kFundsApproved
                                                 : State::kReadyNoFunds,
               now);
}

// Возвращает признак, можно ли безопасно стартовать OTA.
bool CashlessSession::isSafeForOta() const {
  return snapshot_.state != State::kFundsApproved &&
         snapshot_.state != State::kSessionActive &&
         snapshot_.state != State::kVendInProgress &&
         snapshot_.state != State::kWaitVendResult;
}

// Возвращает актуальный снимок состояния FSM.
const CashlessSession::Snapshot& CashlessSession::snapshot() const {
  return snapshot_;
}

// Преобразует enum-состояние в строку для API и логов.
const char* CashlessSession::stateToString(State state) {
  switch (state) {
    case State::kBoot:
      return "boot";
    case State::kWaitLink:
      return "wait_link";
    case State::kDisabled:
      return "disabled";
    case State::kReadyNoFunds:
      return "ready_no_funds";
    case State::kFundsPendingApproval:
      return "funds_pending_approval";
    case State::kFundsApproved:
      return "funds_approved";
    case State::kSessionActive:
      return "session_active";
    case State::kVendInProgress:
      return "vend_in_progress";
    case State::kWaitVendResult:
      return "wait_vend_result";
    case State::kSessionComplete:
      return "session_complete";
    case State::kErrorRecovery:
      return "error_recovery";
    default:
      return "unknown";
  }
}

// Выполняет переход между состояниями и фиксирует момент перехода.
void CashlessSession::transitionTo(State state, unsigned long now) {
  if (snapshot_.state == state) {
    return;
  }
  snapshot_.state = state;
  snapshot_.lastTransitionAt = now;
}
