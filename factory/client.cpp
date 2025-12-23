#include <iostream>
#include<memory>
#include "button.h"
#include "factory.h"

void showButton(Factory& factory) {
    const auto btn = factory.createButton();
    const auto name = btn->name();
    std::cout <<"name:" << name << std::endl;
    std::cout<<"click:"<<std::endl;
    btn->click();
}
