cmake_minimum_required(VERSION 3.26)
project(NIMTwo)

set(CMAKE_CXX_STANDARD 14)

add_executable(NIMTwo main.cpp
        nim_cg.hpp
        nim_cg.cpp)
