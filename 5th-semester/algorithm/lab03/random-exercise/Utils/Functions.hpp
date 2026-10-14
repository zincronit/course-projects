//
// Created by zincronit on 10/8/26.
//

#ifndef RANDOM_EXERCISE_FUNCTIONS_HPP
#define RANDOM_EXERCISE_FUNCTIONS_HPP

#include "Utils.hpp"
#include "../Structs/List.hpp"

void build_list(struct List& );
bool is_empty_list(const struct List& );
struct Node* get_last_node(const struct List& );
struct Node* build_new_node(int );
void insert_front(struct List& , int );
void insert_back(struct List& , int );
void push(struct List& ,int);
int pop(struct List&);
void top(struct List*);
void print_list(const struct List& );
//
struct Node* reverse_list_recursive(struct Node* );
struct Node* reverse_list_iterative(struct Node* );
void insert_sorted(struct List& , int );
struct Node* detect_cycle(const struct List& );
bool is_valid_parentheses(const char* );


#endif //RANDOM_EXERCISE_FUNCTIONS_HPP
