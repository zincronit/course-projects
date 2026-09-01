cmake_minimum_required(VERSION 4.3)
project(Build_static_library)

set(CMAKE_CXX_STANDARD 14)

add_executable(Build_static_library
        main.cpp
        Libraries/Overloads/overloads.hpp
        Libraries/Overloads/overloads.cpp
        Libraries/Utils/Utils.hpp
        Libraries/Utils/Functions.hpp
        Libraries/Utils/Functions.cpp
        Libraries/Structs/Book.hpp
        Libraries/Structs/Customer.hpp
        Libraries/Structs/RequestedBook.hpp
        Libraries/Test-overloads/test.hpp
        Libraries/Test-overloads/test.cpp)
