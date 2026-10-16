//
// Created by zincronit on 10/14/26.
//

#include "Functions.hpp"

void initialize_list(struct List& list)
{
    list.head = nullptr;
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
}

void insert_back(struct List& list, const struct Data data)
{
    Node* new_node = new Node{};
    new_node->data = data;
    new_node->next = nullptr;
    if (list.head == nullptr)
    {
        list.head = new_node;
        return;
    }
    Node* current = list.head;
    while (current->next != nullptr) current = current->next;
    current->next = new_node;
}


void print_list(const struct List list)
{
    Node* current = list.head;
    if (list.head == nullptr)
    {
        std::cout << "empty list" << std::endl;
        return;
    }
    std::cout << "[ ";

    bool flag = true;
    while (current != nullptr)
    {
        if (not flag)
        {
            std::cout << "-> ";
        }
        std::cout << "(" << current->data.id << "," << current->data.type << ") ";
        current = current->next;
        flag = false;
    }

    std::cout << "]" << std::endl;
}

struct Node* get_last_node(const struct List list)
{
    Node* current = list.head;
    while (current->next != nullptr) current = current->next;
    return current;
}
