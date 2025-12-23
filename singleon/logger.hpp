#pragma once 
#include "singleton.hpp"
#include<fstream>
#include <string_view>
#include<mutex>

class Logger : public Singleton<Logger>{
    friend class Singleton<Logger>;
public:
    void log(std::string_view msg){
        std::lock_guard fg(mu_);
        file_ << "[LOG]" << msg << "\n";
    }
private:
    Logger() : file_("app.log",std::ios::app){
    }
    std::ofstream file_;
    std::mutex mu_;
};