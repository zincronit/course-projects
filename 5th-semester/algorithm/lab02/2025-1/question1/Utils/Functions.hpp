//
// Created by zincronit on 9/24/26.
//

#ifndef QUESTION1_FUNCTIONS_HPP
#define QUESTION1_FUNCTIONS_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Structs/List.hpp"

void initialize_list(struct List& );
bool is_empty_list(const struct List );
void insert_front(struct List& , const struct Quadriga );
void insert_back(struct List& , const struct Quadriga );
void print_list(const struct List );

void reorder_list(struct List& );

#endif //QUESTION1_FUNCTIONS_HPP
