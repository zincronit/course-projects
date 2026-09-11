//
// Created by zincronit on 9/9/26.
//

#ifndef INC_2026_1_TOOLS_HPP
#define INC_2026_1_TOOLS_HPP

#include "../Utils/Utils.hpp"

void open_input_file(std::ifstream& , const char* );

void open_output_file(std::ofstream& , const char* );

void print_line(std::ofstream& , int , char character = '=');

void print_text(std::ofstream& , const char* , int , bool should_align_right = false);

void print_spaces(std::ofstream& , int , int );

int read_int(std::ifstream& , bool can_read = true);

double read_double(std::ifstream& , bool can_read = true);

char* allocate_string(const char* );

char* read_string(std::ifstream&, char delimiter = ',');

int read_date(std::ifstream& );

int read_code(std::ifstream& );

int read_time(std::ifstream& );


#endif //INC_2026_1_TOOLS_HPP
