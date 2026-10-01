//
// Created by zincronit on 9/27/26.
//

#ifndef INC_2026_1_INTEGERLIBRARY_HPP
#define INC_2026_1_INTEGERLIBRARY_HPP

#include "../Utils/Functions.hpp"

void* read_integer(std::ifstream&);
int compare_integer(const void* , const void* );
int validate_integer(void*  , void* );
void print_integer(std::ofstream& , void*);

#endif //INC_2026_1_INTEGERLIBRARY_HPP
