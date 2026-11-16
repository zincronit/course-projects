cmake_minimum_required(VERSION 4.3)
project(Erasmo_2026_2_adaptado)

set(CMAKE_CXX_STANDARD 14)

add_executable(Erasmo_2026_2_adaptado
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/Product.cpp
        Classes/Product.hpp
        Classes/Package.cpp
        Classes/Package.hpp
        Classes/StandardPackage.cpp
        Classes/StandardPackage.hpp
        Classes/RefrigeratedPackage.cpp
        Classes/RefrigeratedPackage.hpp
        Classes/PackageManager.cpp
        Classes/PackageManager.hpp
)
