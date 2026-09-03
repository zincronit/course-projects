cmake_minimum_required(VERSION 4.3)
project(Using_static_library)

set(CMAKE_CXX_STANDARD 20)

add_executable(Using_static_library main.cpp
        Libraries/Overloads/overloads.hpp
        Libraries/Utils/Utils.hpp
        Libraries/Utils/Functions.hpp
        Libraries/Utils/Functions.cpp
        Libraries/Structs/Book.hpp
        Libraries/Structs/Customer.hpp
        Libraries/Structs/RequestedBook.hpp
        Libraries/Processors/ReportProcessors.hpp
        Libraries/Processors/ReportProcessors.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Overloads")

target_link_libraries(Using_static_library PRIVATE Overloads)