cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(2026_1
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/Pet.cpp
        Classes/Pet.hpp
        Classes/Appointment.cpp
        Classes/Appointment.hpp
        Classes/Checkup.cpp
        Classes/Checkup.hpp
        Classes/Surgery.cpp
        Classes/Surgery.hpp
        Classes/Vaccine.cpp
        Classes/Vaccine.hpp
        Classes/Veterinary.cpp
        Classes/Veterinary.hpp)
