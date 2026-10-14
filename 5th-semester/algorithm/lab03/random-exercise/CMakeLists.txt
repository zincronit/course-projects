cmake_minimum_required(VERSION 4.3)
project(random_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(random_exercise
        main.cpp
        Utils/Utils.hpp
        Utils/Functions.cpp
        Utils/Functions.hpp
        Structs/List.hpp
        Structs/Node.hpp
)
