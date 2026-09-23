//
// Created by zincronit on 9/20/26.
//

#ifndef LISTS_FUNCTIONS_HPP
#define LISTS_FUNCTIONS_HPP

#include <iostream>
#include "Structs/List.hpp"

void initialize_list(struct List& list);
bool is_empty_list(const struct List list);
void insert_front(struct List& list, int data);
void insert_back(struct List& list, int data);
void invert_list(struct List& list);
void print_list(const struct List list);
struct Node* get_last_node(const struct List list);
void delete_node(struct List& list, int );

#endif //LISTS_FUNCTIONS_HPP
