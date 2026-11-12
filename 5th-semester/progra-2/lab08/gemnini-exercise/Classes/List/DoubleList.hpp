//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_DOUBLELIST_HPP
#define GEMNINI_EXERCISE_DOUBLELIST_HPP

#include "ListNode.hpp"
class DoubleList
{
public:
    DoubleList();
    ~DoubleList();
    void insert(const class SaleDetail& );
    void destroy();
    void reverse();
private:
    class ListNode* head;
    void insert_sort(class ListNode*&,class ListNode* ,const class SaleDetail& );
    void destroy_node(class ListNode*& );
    class ListNode* reverse_node(class ListNode* );
};


#endif //GEMNINI_EXERCISE_DOUBLELIST_HPP
