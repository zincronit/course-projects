//
// Created by zincronit on 10/8/26.
//

#include "Functions.hpp"


void build_list(struct List& list)
{
    list.head = nullptr;
}

bool is_empty_list(const struct List& list)
{
    return list.head == nullptr;
}

struct Node* get_last_node(const struct List& list)
{
    Node* current = list.head;
    if (is_empty_list(list)) return current;
    while (current->next != nullptr) current = current->next;
    return current;
}

struct Node* build_new_node(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void insert_front(List& list, int data)
{
    Node* new_node = build_new_node(data);
    new_node->next = list.head;
    list.head = new_node;
}

void insert_back(struct List& list, int data)
{
    Node* new_node = build_new_node(data);
    Node* current = get_last_node(list);
    current == nullptr ? list.head = new_node : current->next = new_node;
}

void push(struct List& stack, int data)
{
    Node* new_node = build_new_node(data);
    new_node->next = stack.head;
    stack.head = new_node;
}

int pop(struct List& stack)
{
    if (is_empty_list(stack))
    {
        std::cout << "Error: Stack is empty" << std::endl;
        std::exit(2);
    }
    int data = stack.head->data;
    Node* current = stack.head;
    stack.head = stack.head->next;
    delete current;
    return data;
}

int top(struct List& stack)
{
    if (is_empty_list(stack))
    {
        std::cout << "Error: Stack is empty" << std::endl;
        std::exit(1);
    }
    return stack.head->data;
}

void print_list(const struct List& list)
{
    if (is_empty_list(list))
    {
        std::cout << "Error: ADT is empty" << std::endl;
        return;
    }
    Node* current = list.head;
    while (current != nullptr)
    {
        std::cout << "[" << current->data << "] ";
        current = current->next;
    }
    std::cout << std::endl;
}

//

struct Node* reverse_list_recursive(struct Node* head)
{
    if (head == nullptr || head->next == nullptr) return head;
    Node* new_head = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

struct Node* reverse_list_iterative(struct Node* head)
{
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr)
    {
        Node* next_temp = current->next;
        current->next = previous;
        previous = current;
        current = next_temp;
    }
    return previous;
}

void insert_sorted(struct List& list, int data)
{
    Node* new_node = build_new_node(data);
    Node* current = list.head;
    Node* previous = nullptr;
    while (current != nullptr)
    {
        if (current->data >= data) break;
        previous = current;
        current = current->next;
    }
    if (previous == nullptr)
    {
        list.head = new_node;
        new_node->next = current;
    } else
    {
        new_node->next = current;
        previous->next = new_node;
    }
}

struct Node* detect_cycle(const struct List& list)
{
    Node* slow = list.head;
    Node* fast = list.head;
    if (list.head == nullptr or list.head->next == nullptr) return nullptr;
    bool has_cycle = false;
    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            has_cycle = true;
            break;
        }
    }
    if (not has_cycle) return nullptr;
    Node* entry = list.head;
    while (entry != slow)
    {
        entry = entry->next;
        slow = slow->next;
    }
    return entry;
}

bool is_valid_parentheses(const char* string)
{
    List stack;
    build_list(stack);
    for (int i = 0; string[i] != '\0'; i++)
    {
        char current = string[i];
        if (current == '(' || current == '[' || current == '{')
        {
            push(stack, current);
        } else if (current == ')' || current == ']' || current == '}')
        {
            if (is_empty_list(stack))
            {
                return false;
            }
            char top_element = static_cast<char>(top(stack));
            if ((current == ')' && top_element == '(') ||
                (current == ']' && top_element == '[') ||
                (current == '}' && top_element == '{'))
            {
                pop(stack);
            } else
            {
                return false;
            }
        }
    }
    return is_empty_list(stack);
}
