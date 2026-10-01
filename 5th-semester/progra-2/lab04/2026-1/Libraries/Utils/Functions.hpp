//
// Created by zincronit on 9/27/26.
//

#ifndef INC_2026_1_FUNCTIONS_HPP
#define INC_2026_1_FUNCTIONS_HPP

#include "Utils.hpp"

void open_input_file(std::ifstream& , const char* );
void open_output_file(std::ofstream& , const char* );
int* read_int(std::ifstream& , bool can_read_character = true);
double* read_double(std::ifstream& , bool can_read_character = true);
char* allocate_string(const char* );
char* read_string(std::ifstream& , char character = ',');
int* read_date(std::ifstream& , bool can_read_character = true);
int* read_time(std::ifstream& , bool can_read_character = true);
void print_line(std::ofstream& , char character = '=' , int width = LINE_WIDTH);
void print_text(std::ofstream& , const char * , int , bool should_align_right = false);
void** get_last_node(void* list);
void print_date(std::ofstream& , int , int );
void print_time(std::ofstream& , int , int);
void print_spaces(std::ofstream& , int , int);




#endif //INC_2026_1_FUNCTIONS_HPP