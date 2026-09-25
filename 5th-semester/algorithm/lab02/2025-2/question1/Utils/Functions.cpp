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

void insert_front(struct List& list, const struct Data data)
{
    Node* new_node = new Node{};
    new_node->data = data;
    new_node->next = list.head;
    list.head = new_node;
    list.size++;
}

void insert_back(struct List& list, const struct Data data)
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
                << current->data.position << "] ";
        current = current->next;
    }
    std::cout << std::endl;
}

void reorder_list(struct List& list)
{
    if (list.head == nullptr or list.head->next == nullptr) return;
    struct Node* current = list.head;
    struct Node* goalkeeper_head = nullptr;
    struct Node* goalkeeper_tail = nullptr;
    struct Node* defender_head = nullptr;
    struct Node* defender_tail = nullptr;
    struct Node* midfielder_head = nullptr;
    struct Node* midfielder_tail = nullptr;
    struct Node* forward_head = nullptr;
    struct Node* forward_tail = nullptr;

    while (current != nullptr)
    {
        struct Node* next = current->next;
        current->next = nullptr;
        if (current->data.position = )
    }
}
