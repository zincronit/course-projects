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
        std::cout << '[' << current->data.id << "] ";
        current = current->next;
    }
    std::cout << std::endl;
}

void insert_sorted(struct List& list, const struct Data data)
{
    struct Node *current = list.head, *prev = nullptr;
    struct Node* new_node = new Node{};
    new_node->data = data;
    new_node->next = nullptr;
    while (current != nullptr)
    {
        if (current->data.id >= data.id) break;
        prev = current;
        current = current->next;
    }
    if (prev == nullptr)
    {
        list.head = new_node;
        new_node->next = current;
    } else
    {
        prev->next = new_node;
        new_node->next = current;
    }
    if (current == nullptr) list.tail = new_node;
    list.size++;
}

void merge_list(struct List& list1, struct List list2)
{
    if (is_empty_list(list1) and is_empty_list(list2)) return;
    if (list1.tail->data.id < list2.head->data.id)
    {
        list1.tail->next = list2.head;
        list1.tail = list2.tail;
    } else if (list2.tail->data.id < list1.head->data.id)
    {
        list2.tail->next = list1.head;
        list1.head = list2.head;
    } else
    {
        merge_nodes(list1, list2);
    }
}

void merge_nodes(struct List& list1, struct List list2)
{
    struct Node *head = nullptr, *tail = nullptr;

    while (not is_empty_list(list1) and not is_empty_list(list2))
    {
        if (list1.head->data.id <= list2.head->data.id)
        {
            if (head == nullptr)
            {
                head = list1.head;
                tail = list1.head;
            } else
            {
                tail->next = list1.head;
                tail = list1.head;
            }
            list1.head = list1.head->next;
        } else
        {
            if (head == nullptr)
            {
                head = list2.head;
                tail = list2.head;
            } else
            {
                tail->next = list2.head;
                tail = list2.head;
            }
            list2.head = list2.head->next;
        }
    }
    if (not is_empty_list(list1))
    {
        if (tail == nullptr)
        {
            head = list1.head;
            tail = list1.tail;
        } else
        {
            tail->next = list1.head;
            tail = list1.tail;
        }
    } else if (not is_empty_list(list2))
    {
        if (tail == nullptr)
        {
            head = list2.head;
            tail = list2.tail;
        } else
        {
            tail->next = list2.head;
            tail = list2.tail;
        }
    }
    list1.head = head;
    list1.tail = tail;
    list1.size += list2.size;
}


struct Node* find_head(struct Node* node)
{
    if (node == nullptr) return nullptr;
    if (node->next == nullptr) return node;
    struct Node* new_node = find_head(node->next);
    node->next->next = node;
    return new_node;
}

void invert_list(struct List& list)
{
    struct Node* new_head = find_head(list.head);
    list.head->next = nullptr;
    list.head = new_head;
}
