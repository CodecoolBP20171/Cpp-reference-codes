cmake_minimum_required(VERSION 3.8)
project(cpp_2nd_tw_mighty_text_adventure_reference)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Room.cpp Room.h Area.hpp Game.cpp Game.h Player.cpp Player.h Commands.hpp Item.hpp Loot.hpp)
add_executable(cpp_2nd_tw_mighty_text_adventure_reference ${SOURCE_FILES})