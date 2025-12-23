#include "logger.hpp"
#include <cassert>
#include <fstream>

int main() {
    // 1. 基本写入
    Logger::instance().log("hello assert");
    assert(std::ifstream("app.log").good());

    // 2. 同一实例
    auto& a = Logger::instance();
    auto& b = Logger::instance();
    assert(&a == &b);
    return 0;
}