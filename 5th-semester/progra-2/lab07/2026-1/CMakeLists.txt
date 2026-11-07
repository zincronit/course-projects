cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(2026_1
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/Attention.cpp
        Classes/Attention.hpp
        Classes/Urgency.cpp
        Classes/Urgency.hpp
        Classes/Emergency.cpp
        Classes/Emergency.hpp
        Classes/NotUrgent.cpp
        Classes/NotUrgent.hpp
        Classes/CareManager.cpp
        Classes/CareManager.hpp)
