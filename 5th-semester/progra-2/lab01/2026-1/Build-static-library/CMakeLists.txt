cmake_minimum_required(VERSION 4.3)
project(Build_static_library)

set(CMAKE_CXX_STANDARD 14)

add_library(Overloads STATIC Libraries/Overloads/overloads.cpp)

add_executable(Build_static_library
        main.cpp
        Libraries/Utils/Utils.hpp
        Libraries/Utils/AuxiliaryFunctions.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp
        Libraries/Overloads/overloads.hpp
        Libraries/Overloads/overloads.cpp
        Libraries/Structs/Pet.hpp
        Libraries/Structs/Veterinary.hpp
        Libraries/Structs/Attention.hpp
        Libraries/Structs/System.hpp)

target_link_libraries(Build_static_library Overloads)