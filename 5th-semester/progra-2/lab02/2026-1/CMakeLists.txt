cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_library(Tools STATIC Libraries/Tools/tools.cpp)

add_executable(2026_1
        main.cpp
        Libraries/Utils/Utils.hpp
        Libraries/Utils/Functions.hpp
        Libraries/Utils/Functions.cpp
        Libraries/Tools/tools.hpp
        Libraries/Tools/tools.cpp)

target_link_libraries(2026_1 Tools)


