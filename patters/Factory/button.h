#ifndef CONCURRENT_BUTTON_H
#define CONCURRENT_BUTTON_H
#include<string>

class IButton {
public:
    virtual ~IButton() = default;
    [[nodiscard]] virtual std::string name() const = 0;
    virtual void click() = 0;
};
#endif //CONCURRENT_BUTTON_H
