cmake_minimum_required(VERSION 3.17)
project(base64)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp)

add_subdirectory(googletest)

add_executable(main main.cpp ${SOURCE_FILES})
add_executable(tests tests.cpp ${SOURCE_FILES})

target_include_directories(main PRIVATE source)
target_include_directories(tests PRIVATE source PRIVATE googletest/googletest/include/gtest)

target_link_libraries(tests gtest)