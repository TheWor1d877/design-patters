cmake_minimum_required(VERSION 4.1)
project(concurrent)

set(CMAKE_CXX_STANDARD 20)

add_executable(concurrent
        main.cpp
        order_event.h
        order_status.h
        state_strategy.h
        state_machine.h
        states/pending_pay.h
        states/paid.h
        states/delivering.h
        states/completed.h
)
