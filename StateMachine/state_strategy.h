#ifndef CONCURRENT_STATE_STRATEGY_H
#define CONCURRENT_STATE_STRATEGY_H
#include <any>
#include "order_status.h"
#include "state_machine.h"


class StateMachine;

// 策略接口：每种状态只关心自己能处理哪些事件
class IStateStrategy {
    public:
    virtual ~IStateStrategy() = default;
    virtual Status handleEvent(StateMachine& sm,const std::any& event) = 0;
    [[nodiscard]] virtual Status status() const = 0;
};

#endif //CONCURRENT_STATE_STRATEGY_H