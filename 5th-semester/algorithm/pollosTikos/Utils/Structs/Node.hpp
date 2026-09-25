//
// Created by zincronit on 9/24/26.
//

#ifndef POLLOSTIKOS_NODE_HPP
#define POLLOSTIKOS_NODE_HPP

#include "Data.hpp"

struct Node
{
    struct Data data;
    struct Node* next;
};

#endif //POLLOSTIKOS_NODE_HPP
