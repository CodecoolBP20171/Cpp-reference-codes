cmake_minimum_required(VERSION 3.8)
project(cipher)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/decipher.cpp)
add_executable(cipher ${SOURCE_FILES})

add_subdirectory(test)