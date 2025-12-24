#ifndef DECORATOR_FILE_STREAM_H
#define DECORATOR_FILE_STREAM_H
#include <fstream>
#include <string>
#include "stream.h"

class FileStream : public IStream {
public:
    explicit FileStream(const std::string& path)
        :file_(path,std::ios::binary | std::ios::app){};

    ~FileStream() override { file_.close(); }

    void write(const std::string_view data) override {
        file_.write(data.data(),static_cast<long>(data.size()));
    }

private:
    std::ofstream file_;
    std::ifstream input_file_;
};
#endif //DECORATOR_FILE_STREAM_H