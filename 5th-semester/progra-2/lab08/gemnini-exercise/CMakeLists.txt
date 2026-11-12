cmake_minimum_required(VERSION 4.3)
project(gemnini_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(gemnini_exercise
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/SaleDetail.cpp
        Classes/SaleDetail.hpp
        Classes/Product.cpp
        Classes/Product.hpp
        Classes/PerishableProduct.cpp
        Classes/PerishableProduct.hpp
        Classes/ChemicalProduct.cpp
        Classes/ChemicalProduct.hpp
        Classes/GeneralProduct.cpp
        Classes/GeneralProduct.hpp
        Classes/List/DoubleList.cpp
        Classes/List/DoubleList.hpp
        Classes/List/ListNode.cpp
        Classes/List/ListNode.hpp
        Classes/SBT/SearchBinaryTree.cpp
        Classes/SBT/SearchBinaryTree.hpp
        Classes/SBT/TreeNode.cpp
        Classes/SBT/TreeNode.hpp
        Classes/Sale.cpp
        Classes/Sale.hpp
)
