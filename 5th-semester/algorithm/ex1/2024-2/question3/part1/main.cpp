//
// Created by zincronit on 10/16/26.
//

#include <iostream>

struct Node
{
    int element;
    Node* next;
};

struct List
{
    Node* head;
};

void listInit(List& list)
{
    list.head = nullptr;
}

void listAppend(List& list, int val)
{
    Node* newNode = new Node{val, nullptr};
    if (list.head == nullptr)
    {
        list.head = newNode;
        return;
    }
    Node* curr = list.head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

bool listRemove(List& list, int val)
{
    if (list.head == nullptr) return false;

    if (list.head->element == val)
    {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
        return true;
    }

    Node* curr = list.head;
    while (curr->next != nullptr && curr->next->element != val)
    {
        curr = curr->next;
    }

    if (curr->next != nullptr)
    {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return true;
    }

    return false;
}

int main()
{
    return 0;
}
