cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    linked_list.cc
    single.cc
   )

add_library(linked_list STATIC ${SOURCES})

set(TEST_SOURCES
    list_tests.cc
   )

enable_testing()

find_package(GTest REQUIRED)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests linked_list GTest::GTest GTest::Main)

add_test(AllTests tests)
