class EventBus {
    std::unordered_map<std::type_index, std::vector<std::function<void(const std::any&)>>> map_;
    std::mutex mu_;
public:
    template<typename E>
    void publish(const E& e) {                      // 广播
        std::lock_guard lg(mu_);
        auto& v = map_[typeid(E)];
        for (auto& f : v) f(e);
    }
    template<typename E>
    void subscribe(std::function<void(const E&)> f) { // 订阅
        std::lock_guard lg(mu_);
        map_[typeid(E)].emplace_back(
            [f](const std::any& a){ f(std::any_cast<const E&>(a)); });
    }
};

// 2. 使用（8 行）
EventBus bus;
bus.subscribe<TempReading>([](auto& t){                // 观察者1
    std::cout << t.celsius << "°C\n";
});
bus.publish(TempReading{28.5f});                      // 被观察者