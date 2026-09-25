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
        std::cout << '[' << current->data.number << ',' << current->data.palo << "] ";
        current = current->next;
    }
}

struct Node* get_last_node(const struct List list)
{
    Node* current = list.head;
    while (current->next != nullptr) current = current->next;
    return current;
}

void delete_node(struct List& list, const struct Data data)
{
    Node *current = list.head, *previous = nullptr;
    while (current != nullptr)
    {
        if (current->data.number == data.number) break;
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

// void invert_list(struct List& list) {}


void build_deck(struct List& list)
{
    struct Data data{};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            data.number = j + 1;
            if (i == 0) data.palo = 'C';
            else if (i == 1) data.palo = 'D';
            else if (i == 2) data.palo = 'T';
            else data.palo = 'E';
            insert_back(list, data);
        }
    }
}

struct Node* extract_in_position(List& deck, int position)
{
    struct Node* current = deck.head;
    struct Node* previous = nullptr;
    if (position < 1 or position > deck.size) return nullptr;
    if (position == 1)
    {
        deck.head = current->next;
        deck.size--;
        return current;
    }
    for (int i = 1; i < position; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    deck.size--;
    return current;
}

void shuffle(struct List& deck)
{
    // struct Node* tail = deck.head;
    // while (tail->next != nullptr) tail = tail->next;
    // struct Node* ;
    int shuffle_part = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number;
    while (shuffle_part <= deck.size)
    {
        random_number = std::rand() % deck.size + 1;
        insert_back(deck, extract_in_position(deck, random_number)->data);
        shuffle_part++;
    }
}

void destroy_deck(struct List& deck)
{
    struct Node *current = deck.head, *previous = nullptr;
    while (current != nullptr)
    {
        previous = current;
        current = current->next;
        delete previous;
    }
    deck.head = nullptr;
    deck.size = 0;
}
