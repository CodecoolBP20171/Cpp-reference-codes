cmake_minimum_required(VERSION 3.8)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Calculator.cpp Calculator.h RawValue.hpp Tester.hpp)
add_executable(calculator ${SOURCE_FILES})