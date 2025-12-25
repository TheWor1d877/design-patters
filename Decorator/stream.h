#ifndef DECORATOR_STREAM_H
#define DECORATOR_STREAM_H

#include <string_view>

class IStream {
public:
    virtual ~IStream() = default;
    virtual void write(std::string_view data) = 0;
};

#endif //DECORATOR_STREAM_H