//
// Created by zincronit on 9/24/26.
//


#include "Functions.hpp"

void initialize_list(struct List& list)
{
    list.head = nullptr;
    list.size = 0;
}

bool is_empty_list(const struct List list)
{
    return list.head == nullptr;
}

void insert_front(struct List& list, const struct Quadriga data)
{
    Node* new_node = new Node{};
    new_node->data = data;
    new_node->next = list.head;
    list.head = new_node;
    list.size++;
}

void insert_back(struct List& list, const struct Quadriga data)
{
    Node* new_node = new Node{};
    new_node->data = data;
    new_node->next = nullptr;
    if (list.head == nullptr)
    {
        list.head = new_node;
        list.size++;
        return;
    }
    Node* current = list.head;
    while (current->next != nullptr) current = current->next;
    current->next = new_node;
    list.size++;
}


void print_list(const struct List list)
{
    Node* current = list.head;
    if (list.head == nullptr)
    {
        std::cout << "empty list" << std::endl;
        return;
    }
    while (current != nullptr)
    {
        std::cout << '[' << current->data.id << ',' << current->data.name << ','
                << current->data.team << "] ";
        current = current->next;
    }
    std::cout << std::endl;
}

void reorder_list(struct List& list)
{
    if (list.head == nullptr or list.head->next == nullptr) return;

    struct Node* current = list.head;
    struct Node* even_head = nullptr;
    struct Node* even_tail = nullptr;
    struct Node* odd_head = nullptr;
    struct Node* odd_tail = nullptr;

    while (current != nullptr)
    {
        struct Node* next = current->next;
        current->next = nullptr;
        if (current->data.id % 2 == 0)
        {
            if (even_head == nullptr)
            {
                even_head = current;
                even_tail = current;
            } else
            {
                even_tail->next = current;
                even_tail = current;
            }
        } else
        {
            if (odd_head == nullptr)
            {
                odd_head = current;
                odd_tail = current;
            } else
            {
                odd_tail->next = current;
                odd_tail = current;
            }
        }
        current = next;
    }
    if (even_head != nullptr)
    {
        list.head = even_head;
        even_tail->next = odd_head;
    } else
        list.head = odd_head;
}
