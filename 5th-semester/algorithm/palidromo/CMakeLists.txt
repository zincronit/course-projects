cmake_minimum_required(VERSION 4.3)
project(palidromo)

set(CMAKE_CXX_STANDARD 14)

add_executable(palidromo
        main.cpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.hpp
        BibliotecaCola/Cola.hpp)
