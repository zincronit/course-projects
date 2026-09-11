cmake_minimum_required(VERSION 4.3)
project(gemini_problem)

set(CMAKE_CXX_STANDARD 14)

add_executable(gemini_problem
        main.cpp
        Libraries/Tools/tools.hpp
        Libraries/Utils/Utils.hpp
        Libraries/Utils/Functions.hpp
        Libraries/Utils/Functions.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Tools")

target_link_libraries(gemini_problem PRIVATE Tools)