cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(2026_1
        main.cpp
        Utils/Functions.hpp
        Utils/Functions.cpp
        Utils/Structs/List.hpp
        Utils/Structs/Node.hpp
        Utils/Structs/Data.hpp)
