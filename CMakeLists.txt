cmake_minimum_required(VERSION 3.28)
project(CADEX_Task)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

include_directories(
        include
)

add_library(curves src/curves.cpp)

add_executable(CADEX_Task src/main.cpp
        include/3d_curves_app/types.hpp)

target_link_libraries(CADEX_Task curves)
