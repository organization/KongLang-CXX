cmake_minimum_required(VERSION 3.16)
project(KongLang_CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(KongLang_CXX
        src/konglang/Interpreter.cpp
        src/main.cpp)
