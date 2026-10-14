//
// Created by zincronit on 10/14/26.
//

#ifndef QUESTION3_STRUCTS_HPP
#define QUESTION3_STRUCTS_HPP

struct Data
{
    int id;
    char type;
};


struct Node
{
    struct Data data;
    struct Node* next;
};

struct List
{
    struct Node* head;
};

#endif //QUESTION3_STRUCTS_HPP
