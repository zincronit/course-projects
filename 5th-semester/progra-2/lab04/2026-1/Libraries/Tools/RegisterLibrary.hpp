//
// Created by zincronit on 9/27/26.
//

#ifndef INC_2026_1_REGISTERLIBRARY_HPP
#define INC_2026_1_REGISTERLIBRARY_HPP

#include "../Utils/Functions.hpp"

void* read_register(std::ifstream& );
int compare_data(const void*, const void* );
int validate_data(void* , void* );
void print_register(std::ofstream& , void* );


#endif //INC_2026_1_REGISTERLIBRARY_HPP
