cmake_minimum_required(VERSION 4.3)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test
        main.cpp
        Library/Functions.hpp
        Library/Functions.cpp)
