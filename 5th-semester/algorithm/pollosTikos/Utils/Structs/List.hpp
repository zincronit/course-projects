//
// Created by zincronit on 9/24/26.
//

#ifndef POLLOSTIKOS_LIST_HPP
#define POLLOSTIKOS_LIST_HPP

#include "Node.hpp"

struct List
{
    struct Node* head;
    struct Node* tail;
    int size;
};

#endif //POLLOSTIKOS_LIST_HPP
