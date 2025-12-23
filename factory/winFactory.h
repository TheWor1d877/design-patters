#ifndef CONCURRENT_WINFACTORY_H
#define CONCURRENT_WINFACTORY_H
#include "factory.h"
#include "winButton.h"

class WinFactory : public Factory {
public:
    std::unique_ptr<IButton> createButton() override {
        return std::make_unique<WinButton>();
    };
};
#endif //CONCURRENT_WINFACTORY_H