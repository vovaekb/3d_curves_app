cmake_minimum_required(VERSION 3.28)
project(CADEX_Task)

set(CMAKE_CXX_STANDARD 17)

add_executable(CADEX_Task main.cpp
        curves.cpp
        curves.h
        types.h)
