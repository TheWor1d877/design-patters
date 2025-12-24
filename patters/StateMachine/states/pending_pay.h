#ifndef CONCURRENT_PENDING_PAY_H
#define CONCURRENT_PENDING_PAY_H

#pragma once
#include <any>
#include "../state_strategy.h"
#include "../order_status.h"
#include "../order_event.h"
class StateMachine;

class PendingPay : public IStateStrategy {
public:
    Status handleEvent(StateMachine& sm, const std::any& event) override {
        if (event.type() == typeid(Payed))   return Status::PAID;
        if (event.type() == typeid(Cancel))  return Status::COMPLETED; // 关闭订单
        return status();
    }
    [[nodiscard]] Status status() const override { return Status::PENDING_PAY; }
};

#endif //CONCURRENT_PENDING_PAY_H