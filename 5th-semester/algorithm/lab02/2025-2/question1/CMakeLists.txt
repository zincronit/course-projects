cmake_minimum_required(VERSION 4.3)
project(question1)

set(CMAKE_CXX_STANDARD 14)

add_executable(question1
        main.cpp
        Utils/Functions.hpp
        Utils/Functions.cpp
        Utils/Structs/List.hpp
        Utils/Structs/Node.hpp
        Utils/Structs/Data.hpp)
