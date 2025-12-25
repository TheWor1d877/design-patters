#ifndef CONCURRENT_COMPLETED_H
#define CONCURRENT_COMPLETED_H

#pragma once
#include <any>
#include "../state_strategy.h"
#include "../order_status.h"
class StateMachine;

class Completed : public IStateStrategy {
public:
    Status handleEvent(StateMachine& sm, const std::any& event) override {
        return status();
    }
    [[nodiscard]] Status status() const override { return Status::COMPLETED; }
};
#endif //CONCURRENT_COMPLETED_H