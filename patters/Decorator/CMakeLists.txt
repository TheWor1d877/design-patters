cmake_minimum_required(VERSION 4.1)
project(decorator)
set(CMAKE_CXX_STANDARD 20)


find_package(ZLIB REQUIRED)

add_executable(decorator main.cpp
        stream.h
        file_stream.h
        compress_stream.h
        encrypt_stream.h)
target_link_libraries(decorator PRIVATE ZLIB::ZLIB)