#pragma once

#include<mutex>
#include<memory>

template<typename T>
class Singleton {
private:
    static std::once_flag flag_;
    static std::unique_ptr<T> instance_;

protected:
    Singleton()  = default;
    ~Singleton() = default;

public:
    static T& instance(){
        std::call_once(flag_,[](){
            instance_.reset(new T{});
        });
        return *instance_;
    }

    Singleton(const Singleton&) = delete;
    Singleton operator = (const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton operator = (Singleton&&) = delete;
};

template<typename T>
std::once_flag Singleton<T>::flag_;

template<typename T>
std::unique_ptr<T> Singleton<T>::instance_;