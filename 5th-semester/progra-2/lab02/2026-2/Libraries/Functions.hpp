//
// Created by zincronit on 9/12/26.
//

#ifndef INC_2026_2_FUNCTIONS_HPP
#define INC_2026_2_FUNCTIONS_HPP

#include "Utils.hpp"

void open_input_file(std::ifstream&, const char*);

void open_output_file(std::ofstream&, const char*);

int read_int(std::ifstream&, bool can_read = true);

double read_double(std::ifstream&, bool can_read = true);

char* allocate_string(const char*);

char* read_string(std::ifstream&, char character = ',');

void print_text(std::ofstream&, const char*, int, bool should_align_right = false);

void print_line(std::ofstream&, int width = LINE_WIDTH, char character = '=');

void load_sales(const char*, char***&);

char** read_sale(std::ifstream&);

void load_sale_detail(const char*, char***, char****&, int***&);

int get_sale_size(char***);

int find_sale_index(char***, char*);

void append_data_capacity(char***&, int**&, int&, int);

void insert_data(std::ifstream&, char***, int**, int&);

void complete_data_detail(const char*, char****, int***);

void read_product(char****, int***, char*, char*, char*, int, int);

void print_report(const char*,char*** , char**** , int***, bool);

void print_title(std::ofstream& );

void print_sale_detail(std::ofstream& , char** );

void print_header_products(std::ofstream& );

void print_products(std::ofstream& , char*** ,int** , double& , double&);

void print_statistics(std::ofstream& , double& , double& , double);
#endif //INC_2026_2_FUNCTIONS_HPP
