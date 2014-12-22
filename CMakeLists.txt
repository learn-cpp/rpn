cmake_minimum_required(VERSION 2.8.4)
project(rpn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp rpn.cpp)
add_executable(rpn ${SOURCE_FILES})
