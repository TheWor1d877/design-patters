#include <iostream>
#include <memory>
#include <chrono>

class MyClass {};

void testMakeShared() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        auto ptr = std::make_shared<MyClass>();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "std::make_shared time: " << duration << " ms" << std::endl;
}

void testSharedPtrNew() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        auto ptr = std::shared_ptr<MyClass>(new MyClass);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "std::shared_ptr(new T) time: " << duration << " ms" << std::endl;
}

int main() {
    testMakeShared();
    testSharedPtrNew();
    return 0;
}