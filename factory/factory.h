#ifndef CONCURRENT_FACTORY_H
#define CONCURRENT_FACTORY_H
#include <memory>

#include "button.h"

class Factory {
public:
    virtual ~Factory() = default;
    virtual std::unique_ptr<IButton> createButton() = 0;
};
#endif //CONCURRENT_FACTORY_H