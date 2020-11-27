cmake_minimum_required(VERSION 3.16)
project(test6)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(lib/googletest/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "test/*.cpp")

add_executable(test6 ${tests})
#add_executable(test6 main.cpp)
target_link_libraries(test6 src gtest gtest_main)