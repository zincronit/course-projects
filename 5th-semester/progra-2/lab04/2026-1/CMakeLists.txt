cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(2026_1
        main.cpp
        Libraries/Utils/Functions.hpp
        Libraries/Utils/Utils.hpp
        Libraries/Utils/Functions.cpp
        Libraries/Tools/RegisterLibrary.hpp
        Libraries/Tools/IntegerLibrary.hpp
        Libraries/Tools/GenericLibrary.hpp
        Libraries/Tools/GenericLibrary.cpp
        Libraries/Tools/RegisterLibrary.cpp
        Libraries/Tools/IntegerLibrary.cpp
)
