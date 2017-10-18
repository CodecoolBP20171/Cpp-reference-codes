cmake_minimum_required(VERSION 3.8)
project(minesweeper)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Minesweeper.cpp Minesweeper.h)
add_executable(minesweeper ${SOURCE_FILES})