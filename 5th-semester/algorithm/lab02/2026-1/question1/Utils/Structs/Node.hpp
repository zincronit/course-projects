//
// Created by zincronit on 9/20/26.
//

#ifndef LISTS_NODE_HPP
#define LISTS_NODE_HPP

#include "Data.hpp"

struct Node
{
    Data data;
    struct Node* next;
};

#endif //LISTS_NODE_HPP
