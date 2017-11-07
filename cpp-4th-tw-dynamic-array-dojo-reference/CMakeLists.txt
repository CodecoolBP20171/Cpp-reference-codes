cmake_minimum_required(VERSION 3.8)
project(cpp_dynamic_array_dojo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DynamicArray.cpp DynamicArray.h InvalidArrayIndex.hpp Tester.hpp)
add_executable(cpp_dynamic_array_dojo ${SOURCE_FILES})