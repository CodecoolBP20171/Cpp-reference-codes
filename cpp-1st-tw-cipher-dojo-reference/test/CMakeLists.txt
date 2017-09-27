add_subdirectory(gtest-1.8.0)
include_directories(gtest-1.8.0/googletest)

enable_testing()

set(SOURCE_FILES test.cpp ../src/decipher.cpp ../src/decipher.h)
add_executable(runUnitTests ${SOURCE_FILES} ../src/decipher.cpp ../src/decipher.h)
target_link_libraries(runUnitTests gtest gtest_main)

add_test(runUnitTests runUnitTests)