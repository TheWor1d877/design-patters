// state_machine.hpp
#pragma once
#include "order_status.h"
#include <unordered_map>
#include <typeindex>
#include <any>
#include <functional>
#include "state_strategy.h"

class IStateStrategy;
class StateMachine {
    using EventKey = std::type_index;
    using TransMap = std::unordered_map<EventKey,
                                        std::unique_ptr<IStateStrategy>,
                                        std::hash<EventKey>>;

    std::unordered_map<Status, TransMap> rules_;
    Status current_;
public:
    explicit StateMachine(const Status init) : current_(init) {}

    // 注册转移：状态 s 遇到事件 E 跳到策略 target
    template <typename Event>
    void map(const Status s, std::unique_ptr<IStateStrategy> target) {
        rules_[s][std::type_index(typeid(Event))] = std::move(target);
    }

    // 触发事件：返回新状态
    template <typename Event>
    Status process(const Event& e) {
        auto& trans = rules_[current_];               // 当前状态的事件表
        const auto key = std::type_index(typeid(Event));
        const auto it  = trans.find(key);
        if (it == trans.end()) return current_;       // 无定义，保持原状
        current_ = it->second->handleEvent(*this, std::any(e));
        return current_;
    }

    Status status() const { return current_; }
};