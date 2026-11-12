cmake_minimum_required(VERSION 4.3)
project(BST_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(BST_exercise
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/Attention.cpp
        Classes/Attention.hpp
        Classes/Emergency.cpp
        Classes/Emergency.hpp
        Classes/Urgency.cpp
        Classes/Urgency.hpp
        Classes/NonUrgency.cpp
        Classes/NonUrgency.hpp
        Classes/AttentionManager.cpp
        Classes/AttentionManager.hpp
        Classes/SearchBinaryTree.cpp
        Classes/SearchBinaryTree.hpp
        Classes/TreeNode.cpp
        Classes/TreeNode.hpp)
