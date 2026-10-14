//
// Created by zincronit on 10/9/26.
//

#ifndef QUESTION2_STRUCTS_HPP
#define QUESTION2_STRUCTS_HPP


struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

struct Queue {
    Node* front;
    Node* rear;
};

#endif //QUESTION2_STRUCTS_HPP
