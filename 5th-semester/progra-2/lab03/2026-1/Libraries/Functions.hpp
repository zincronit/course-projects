//
// Created by zincronit on 9/13/26.
//

#ifndef INC_2026_1_FUNCTIONS_HPP
#define INC_2026_1_FUNCTIONS_HPP

#include "Utils.hpp"


void open_input_file(std::ifstream& , const char* );
void open_output_file(std::ofstream& , const char* );
int* read_int(std::ifstream& ,bool read_character = true);
double* read_double(std::ifstream& , bool read_character = true);
char* allocate_string(const char* );
char* read_string(std::ifstream& , char character = ',');
void print_text(std::ofstream& , const char* , int , bool should_align_right = false);
void print_line(std::ofstream& , char character = '=' , int width = LINE_WIDTH);

void load_patients(const char* , void*& );

void* read_patient(std::ifstream& );
void append_patient_capacity(void**& , int& , int);

void load_attentions(const char* , void* );

int* read_date(std::ifstream& );

int* read_time(std::ifstream& );

int find_index(void** , int* );
bool is_equal(void**, int*);
void append_attentions(void** , int, int* , int* , int* ,int*, double*);
void append_attention_capacity(void**&, int& , int);
void* insert_data( int* , int* , double*);
void make_report(const char* ,void* );
void print_title(std::ofstream& );
void print_header(std::ofstream& );
void print_patients(std::ofstream& , void**);
#endif //INC_2026_1_FUNCTIONS_HPP
