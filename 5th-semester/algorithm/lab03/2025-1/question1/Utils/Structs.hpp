//
// Created by zincronit on 10/9/26.
//

#ifndef QUESTION1_STRUCTS_HPP
#define QUESTION1_STRUCTS_HPP


struct Position
{
    int row;
    int column;
};

struct Node
{
    struct Position position;
    Node* next;
};

struct Stack
{
    Node* top;
};

#endif //QUESTION1_STRUCTS_HPP
