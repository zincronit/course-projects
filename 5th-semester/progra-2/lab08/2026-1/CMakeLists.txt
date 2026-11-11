cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(2026_1
        main.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Classes/Pair.cpp
        Classes/Pair.hpp
        Classes/Attention.cpp
        Classes/Attention.hpp
        Classes/DoubleListNode.cpp
        Classes/DoubleListNode.hpp
        Classes/DoubleLinkedList.cpp
        Classes/DoubleLinkedList.hpp
        Classes/Emergency.cpp
        Classes/Emergency.hpp
        Classes/Urgency.cpp
        Classes/Urgency.hpp
        Classes/NonUrgency.cpp
        Classes/NonUrgency.hpp
        Classes/AttentionManager.cpp
        Classes/AttentionManager.hpp)
