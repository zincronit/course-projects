//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_LISTNODE_HPP
#define GEMNINI_EXERCISE_LISTNODE_HPP

#include "../SaleDetail.hpp"
class ListNode
{
public:
    ListNode();
    ListNode(const class SaleDetail& );
    ~ListNode() = default;
    friend class DoubleList;
private:
    class SaleDetail detail;
    class ListNode* next;
    class ListNode* previous;
};


#endif //GEMNINI_EXERCISE_LISTNODE_HPP
