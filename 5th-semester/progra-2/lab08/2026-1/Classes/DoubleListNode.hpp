//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_DOUBLELISTNODE_HPP
#define INC_2026_1_DOUBLELISTNODE_HPP

#include "Pair.hpp"
#include "DoubleLinkedList.hpp"
class DoubleListNode
{
public:
    DoubleListNode();
    DoubleListNode(class Attention* attention);
    ~DoubleListNode();

    friend class DoubleLinkedList;
private:
    class Pair data;
    class DoubleListNode* next;
    class DoubleListNode* previous;
};


#endif //INC_2026_1_DOUBLELISTNODE_HPP
