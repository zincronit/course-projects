//
// Created by zincronit on 9/27/26.
//

#ifndef INC_2026_1_GENERICLIBRARY_HPP
#define INC_2026_1_GENERICLIBRARY_HPP

#include "../Utils/Functions.hpp"

void array_process(void* , void* (*)(std::ifstream& ), const char* );
void build_list(void* , void*& , int (*)(const void* , const void* ));
void* initialize_list();
void insert_back(void*& , void* );
void print_list(void* , void (*)(std::ofstream& , void* ), const char* );
void fusion_list(void*& , void* ,int (*) (void* , void*));

#endif //INC_2026_1_GENERICLIBRARY_HPP
