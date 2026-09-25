//
// Created by zincronit on 9/20/26.
//

#ifndef LISTS_FUNCTIONS_HPP
#define LISTS_FUNCTIONS_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Structs/List.hpp"

void initialize_list(struct List& list);
bool is_empty_list(const struct List list);
void insert_front(struct List& list, const struct Data data);
void insert_back(struct List& list, const struct Data data);
void print_list(const struct List list);
struct Node* get_last_node(const struct List list);
void delete_node(struct List& list, const struct Data);
void invert_list(struct List& list);
void build_deck(struct List& list);
struct Node* extract_in_position(List& , int);
void shuffle(struct List& deck);
void destroy_deck(struct List& deck);

#endif //LISTS_FUNCTIONS_HPP
