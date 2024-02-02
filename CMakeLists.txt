cmake_minimum_required(VERSION 3.28)
project(CADEX_Task)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_library(curves curves.cpp)

add_executable(CADEX_Task main.cpp
        types.hpp)

target_link_libraries(CADEX_Task curves)
