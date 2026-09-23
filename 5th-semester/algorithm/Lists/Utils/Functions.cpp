//
// Created by zincronit on 9/20/26.
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

void insert_front(struct List& list, int data)
{
    Node* new_node = new Node{};
    new_node->data = data;
    new_node->next = list.head;
    list.head = new_node;
    list.size++;
}

void insert_back(struct List& list, int data)
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
    while (current != nullptr)
    {
        std::cout << '[' << current->data << "] ";
        current = current->next;
    }
}

struct Node* get_last_node(const struct List list)
{
    Node* current = list.head;
    while (current->next != nullptr) current = current->next;
    return current;
}

void delete_node(struct List& list, int data)
{
    Node *current = list.head, *previous = nullptr;
    while (current != nullptr)
    {
        if (current->data == data) break;
        previous = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        previous->next == nullptr ? list.head = current->next : previous->next = current->next;
        delete current;
        list.size--;
    }
}

void invert_list(struct List& list)
{
        
}
