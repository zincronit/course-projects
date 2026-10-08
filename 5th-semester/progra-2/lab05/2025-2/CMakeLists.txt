cmake_minimum_required(VERSION 4.3)
project(2025_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2025_2
        main.cpp
        Classes/Streamer.cpp
        Classes/Streamer.hpp
        Utils.hpp
        Classes/StreamerManager.cpp
        Classes/StreamerManager.hpp)
