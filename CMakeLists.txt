cmake_minimum_required(VERSION 3.17)
project(base64)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp)

add_executable(base64 main.cpp ${SOURCE_FILES})