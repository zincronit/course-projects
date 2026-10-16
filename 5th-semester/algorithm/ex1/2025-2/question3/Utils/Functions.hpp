//
// Created by zincronit on 10/14/26.
//

#ifndef QUESTION3_FUNCTIONS_HPP
#define QUESTION3_FUNCTIONS_HPP


#include "Structs.hpp"
#include <iostream>

void initialize_list(struct List& list);

bool is_empty_list(const struct List list);

void insert_front(struct List& list, const struct Data data);

void insert_back(struct List& list, const struct Data data);

void print_list(const struct List list);

struct Node* get_last_node(const struct List list);


#endif //QUESTION3_FUNCTIONS_HPP
