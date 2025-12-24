#ifndef DECORATOR_COMPRESS_STREAM_H
#define DECORATOR_COMPRESS_STREAM_H
#pragma once
#include <memory>
#include <zlib.h>
#include <vector>
#include "stream.h"

class CompressStream : public IStream {   // 装饰器核心：继承接口 + 持有内部组件
public:
    explicit CompressStream(std::unique_ptr<IStream> inner)
        : inner_(std::move(inner)) {}
    void write(std::string_view data) override {
        z_stream zs{};                          // 极简 zlib 演示
        deflateInit(&zs, Z_BEST_SPEED);
        zs.next_in  = reinterpret_cast<Bytef*>(const_cast<char*>(data.data()));
        zs.avail_in = static_cast<uInt>(data.size());
        std::vector<char> out(data.size() + 16);
        zs.next_out  = reinterpret_cast<Bytef*>(out.data());
        zs.avail_out = static_cast<uInt>(out.size());
        deflate(&zs, Z_FINISH);
        auto compressed = std::string_view(out.data(), out.size() - zs.avail_out);
        inner_->write(compressed);                // 把压缩后数据写给内部组件
        deflateEnd(&zs);
    }
private:
    std::unique_ptr<IStream> inner_;
};

#endif //DECORATOR_COMPRESS_STREAM_H