cmake_minimum_required(VERSION 3.8)
project(cpp_lightning_fast_word_finder_dojo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LightningWordFinder.hpp)
add_executable(cpp_lightning_fast_word_finder_dojo ${SOURCE_FILES})