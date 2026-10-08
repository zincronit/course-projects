cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(2026_1
        main.cpp
        Classes/Pet.cpp
        Classes/Pet.hpp
        Classes/AppliedVaccine.cpp
        Classes/AppliedVaccine.hpp
        Classes/Veterinary.cpp
        Classes/Veterinary.hpp
        Utils/Utils.cpp
        Utils/Utils.hpp)
