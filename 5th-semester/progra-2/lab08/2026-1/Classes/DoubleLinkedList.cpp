//
// Created by zincronit on 11/11/26.
//

#include "DoubleLinkedList.hpp"
DoubleLinkedList::DoubleLinkedList() { head = nullptr; }

void DoubleLinkedList::insert(int key, class Attention* attention)
{
    insert_sort(head, nullptr, attention);
}

DoubleLinkedList::~DoubleLinkedList() { destroy(); }

void DoubleLinkedList::insert_sort(
    class DoubleListNode*& current,
    class DoubleListNode* previous,
    class Attention* attention
)
{
    if (current == nullptr or current->data.get_key() >= attention->generate_key())
    {
        class DoubleListNode* new_node = new DoubleListNode(attention);
        new_node->next = current;
        new_node->previous = previous;
        if (current != nullptr)
            current->previous = new_node;
        current = new_node;
        return;
    }
    insert_sort(current->next, current, attention);
}

void DoubleLinkedList::print(std::ofstream& output, int type) const
{
    print_list(output, head, type);
}


void DoubleLinkedList::print_list(std::ofstream& output, class DoubleListNode* current, int type) const
{
    if (current == nullptr) return;
    if (current->data.get_key() / 10000 == type)
        current->data.print(output);
    print_list(output, current->next, type);
}

void DoubleLinkedList::destroy()
{
    delete_node(head);
}

void DoubleLinkedList::delete_node(class DoubleListNode*& current)
{
    if (current == nullptr) return;
    delete_node(current->next);
    current->next = nullptr;
    current->previous = nullptr;
    delete current;
}
