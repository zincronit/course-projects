//
// Created by zincronit on 10/9/26.
//

#ifndef QUESTION1_FUNCTIONS_HPP
#define QUESTION1_FUNCTIONS_HPP


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Structs.hpp"

#define N 5
#define M 6

void initStack(Stack&);

bool isStackEmpty(const Stack&);

void push(struct Stack&, const struct Position&);

struct Position& pop(Stack&);

struct Position& top(const Stack&);

void finding_way(int [][M] , struct Position& );
#endif //QUESTION1_FUNCTIONS_HPP
