//
// Created by zincronit on 11/11/26.
//

#include "DoubleListNode.hpp"

DoubleListNode::DoubleListNode()
{
    next = nullptr;
    previous = nullptr;
}

DoubleListNode::DoubleListNode(class Attention* attention)
{
    next = nullptr;
    previous = nullptr;
    data.value = attention->clone();
    data.key = attention->generate_key();
}

DoubleListNode::~DoubleListNode()
{
    std::cout << "hello, I using this " << std::endl;
}


