//
// Created by zincronit on 11/12/26.
//

#include "ListNode.hpp"
ListNode::ListNode()
{
    next = nullptr;
    previous = nullptr;
}

ListNode::ListNode(const class SaleDetail& new_detail)
{
    next = nullptr;
    previous = nullptr;
    detail = new_detail;
}
