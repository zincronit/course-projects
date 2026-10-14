//
// Created by zincronit on 10/9/26.
//

#ifndef QUESTION2_FUNCTIONS_HPP
#define QUESTION2_FUNCTIONS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Structs.hpp"

void initStack(Stack&);

bool isStackEmpty(const Stack&);

void push(Stack&, int);

int pop(Stack&);

int top(const Stack&);

void initQueue(Queue&);

bool isQueueEmpty(const Queue&);

void enqueue(Queue&, int);

int dequeue(Queue&);

int front(const Queue&);

bool has_insert_sort(struct Queue& , struct Queue&);

#endif //QUESTION2_FUNCTIONS_HPP
