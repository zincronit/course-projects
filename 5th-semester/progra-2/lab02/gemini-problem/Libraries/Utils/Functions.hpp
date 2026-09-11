//
// Created by zincronit on 9/10/26.
//

#ifndef GEMINI_PROBLEM_FUNCTIONS_HPP
#define GEMINI_PROBLEM_FUNCTIONS_HPP

#include "../Tools/tools.hpp"

void loadInventory(const char*, char**&, int**&);

int find_index(char**,const char*,  int);

void append_warehouse_capacity(int**&, int&, int, int*&, int*&);

void insert_inventory_data(int*&, int&, int&, int , int);

#endif //GEMINI_PROBLEM_FUNCTIONS_HPP
