#ifndef CONCURRENT_PAID_H
#define CONCURRENT_PAID_H
// states/paid.hpp
#pragma once
#include <any>
#include "../state_strategy.h"
#include "../order_status.h"
#include "../order_event.h"

class Paid : public IStateStrategy {
public:
    Status handleEvent(StateMachine& sm, const std::any& event) override {
        if (event.type() == typeid(Deliver)) return Status::DELIVERING;
        if (event.type() == typeid(Cancel))  return Status::COMPLETED; // 退款关闭
        return status();
    }
    [[nodiscard]] Status status() const override { return Status::PAID; }
};
#endif //CONCURRENT_PAID_H