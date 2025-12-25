#ifndef CONCURRENT_WINBUTTON_H
#define CONCURRENT_WINBUTTON_H
#include <iostream>
#include <ostream>

#include "button.h"


class WinButton : public IButton {
    [[nodiscard]] std::string name() const override {
        return "Windows Button";
    };
    void click() override {
        std::cout<<"Clicked Window Button"<<std::endl;
    };
};

#endif //CONCURRENT_WINBUTTON_H