#include "file_stream.h"
#include "compress_stream.h"
#include "encrypt_stream.h"
#include <memory>

int main() {
    // 原始流：裸写文件
    auto s1 = std::make_unique<FileStream>("app187780801.log");

    // 运行时加功能：先压缩再加密再写文件
    auto s2 = std::make_unique<EncryptStream>(std::move(s1), 0xAB);
    const auto s3 = std::make_unique<CompressStream>(std::move(s1));

    s3->write("hello Decorator pattern\n");
    return 0;
}