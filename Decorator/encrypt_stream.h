#ifndef DECORATOR_ENCRYPT_STREAM_H
#define DECORATOR_ENCRYPT_STREAM_H

#pragma once
#include <memory>
#include "stream.h"

class EncryptStream : public IStream {
public:
    explicit EncryptStream(std::unique_ptr<IStream> inner, char key = 0x5A)
        : inner_(std::move(inner)), key_(key) {}
    void write(const std::string_view data) override {
        std::string tmp(data);
        for (auto& ch : tmp) ch ^= key_;
        inner_->write(tmp);                       // 先加密，再写给内部
    }
private:
    std::unique_ptr<IStream> inner_;
    char key_;
};
#endif //DECORATOR_ENCRYPT_STREAM_H