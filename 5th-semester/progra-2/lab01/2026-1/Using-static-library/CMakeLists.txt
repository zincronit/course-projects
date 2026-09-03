cmake_minimum_required(VERSION 4.3)
project(Using_static_library)

set(CMAKE_CXX_STANDARD 14)


add_executable(Using_static_library
        main.cpp
        Libraries/Overloads/overloads.hpp
        Libraries/Structs/Attention.hpp
        Libraries/Structs/Pet.hpp
        Libraries/Structs/System.hpp
        Libraries/Structs/Veterinary.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp
        Libraries/Utils/AuxiliaryFunctions.hpp
        Libraries/Utils/Utils.hpp
        Libraries/Tools/Functions.hpp
        Libraries/Tools/Functions.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Overloads")

target_link_libraries(Using_static_library PRIVATE Overloads)