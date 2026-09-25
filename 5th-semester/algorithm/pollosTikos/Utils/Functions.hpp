//
// Created by zincronit on 9/24/26.
//

#ifndef POLLOSTIKOS_FUNCTIONS_HPP
#define POLLOSTIKOS_FUNCTIONS_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Structs/List.hpp"

void initialize_list(struct List& );
bool is_empty_list(const struct List );
void insert_front(struct List& , const struct Data );
void insert_back(struct List& , const struct Data );
void print_list(const struct List );
void reorder_list(struct List&);
void insert_sorted(struct List& , const struct Data);
void merge_list(struct List& , struct List );
void merge_nodes(struct List& , struct List);
struct Node* find_head(struct Node* );
void invert_list(struct List& );

#endif //POLLOSTIKOS_FUNCTIONS_HPP
