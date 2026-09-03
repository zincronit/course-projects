cmake_minimum_required(VERSION 4.3)
project(Using_static_library)

set(CMAKE_CXX_STANDARD 14)

include_directories(Libraries/Overloads)
include_directories(Libraries/Structs)
include_directories(Libraries/Utils)

add_executable(Using_static_library
        Libraries/Overloads/overloads.hpp
        Libraries/Structs/Course.hpp
        Libraries/Structs/Student.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp
        Libraries/Utils/AuxiliaryFunctions.hpp
        Libraries/Utils/Utils.hpp
        main.cpp
        Libraries/Tools/Functions.hpp
        Libraries/Tools/Functions.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Overloads")

target_link_libraries(Using_static_library PRIVATE Overloads)