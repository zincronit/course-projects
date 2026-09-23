cmake_minimum_required(VERSION 4.3)
project(Lists)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lists
        main.cpp
        Utils/Functions.hpp
        Utils/Functions.cpp
        Utils/Structs/List.hpp
        Utils/Structs/Node.hpp)
