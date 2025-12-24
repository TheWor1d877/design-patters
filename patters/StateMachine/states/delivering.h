#ifndef CONCURRENT_DELIVERING_H
#define CONCURRENT_DELIVERING_H
#pragma once
#include <any>
#include "../state_strategy.h"
#include "../order_status.h"
#include "../order_event.h"

class Delivering: public IStateStrategy {
public:
    Status handleEvent(StateMachine& sm, const std::any& event) override {
        if (event.type() == typeid(Receive)) return Status::COMPLETED;
        return status();
    }
    [[nodiscard]] Status status() const override { return Status::DELIVERING; }
};
#endif //CONCURRENT_DELIVERING_H