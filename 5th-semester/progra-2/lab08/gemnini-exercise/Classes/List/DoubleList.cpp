//
// Created by zincronit on 11/12/26.
//

#include "DoubleList.hpp"

DoubleList::DoubleList() { head = nullptr; }
DoubleList::~DoubleList() { destroy(); }

void DoubleList::insert(const class SaleDetail& new_detail)
{
    insert_sort(head, nullptr, new_detail);
}

void DoubleList::destroy()
{
    destroy_node(head);
}

void DoubleList::reverse()
{
    head = reverse_node(head);
}

void DoubleList::insert_sort(
    class ListNode*& current,
    class ListNode* prev,
    const class SaleDetail& new_detail
)
{
    if (current != nullptr
        and current->detail.get_dispatch_key() == new_detail.get_dispatch_key())
    {
        current->detail.add_quantity(new_detail.get_quantity());
        return;
    } else if (current == nullptr
               or current->detail.get_dispatch_key() > new_detail.get_dispatch_key())
    {
        class ListNode* new_node = new ListNode(new_detail);
        new_node->next = current;
        new_node->previous = prev;
        if (current != nullptr)
            current->previous = new_node;
        current = new_node;
        return;
    }
    insert_sort(current->next, current, new_detail);
}

void DoubleList::destroy_node(class ListNode*& current)
{
    if (current == nullptr) return;
    destroy_node(current->next);
    current->next = nullptr;
    current->previous = nullptr;
    delete current;
}

class ListNode* DoubleList::reverse_node(class ListNode* current)
{
    if (current == nullptr) return nullptr;
    class ListNode* next_node = current->next;
    if (current->next ==  nullptr)
    {

        current->next = current->previous;
        current->previous = next_node;
        return current;
    }
    class ListNode* new_head = reverse_node(current->next);
    current->next = current->previous;
    current->previous = next_node;
    return new_head;
}
