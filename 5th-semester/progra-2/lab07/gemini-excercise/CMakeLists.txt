cmake_minimum_required(VERSION 4.3)
project(gemini_excercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(gemini_excercise
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/Sale.cpp
        Classes/Sale.hpp
        Classes/StoreSale.cpp
        Classes/StoreSale.hpp
        Classes/OnlineSale.cpp
        Classes/OnlineSale.hpp
        Classes/Wholesale.cpp
        Classes/Wholesale.hpp
        Classes/Company.cpp
        Classes/Company.hpp)
