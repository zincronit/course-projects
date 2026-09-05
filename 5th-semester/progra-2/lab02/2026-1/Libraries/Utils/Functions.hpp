//
// Created by zincronit on 9/4/26.
//

#ifndef INC_2026_1_FUNCTIONS_HPP
#define INC_2026_1_FUNCTIONS_HPP

#include "Utils.hpp"

void open_input_file(std::ifstream& fin, const char* filepath);

void open_output_file(std::ofstream& fout, const char* filepath);

void print_line(std::ofstream& fout, int width, char character = '=');

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right = false);

void print_spaces(std::ofstream& fout, int extra, int width);

int read_int(std::ifstream& fin, bool can_read = true);

double read_double(std::ifstream& fin, bool can_read = true);

char* allocate_string(const char* text);

char* read_string(std::ifstream&, char delimiter = ',');

int read_date(std::ifstream& fin);

int read_code(std::ifstream& fin);

int read_time(std::ifstream& fin);

void load_information(const char* filepath,
                      int* & dates,
                      char**** & text_data,
                      int*** & int_data,
                      double*** & double_data);

void append_date_capacity(int* & dates,
                          char**** & text_data,
                          int*** & int_data,
                          double*** & double_data,
                          int count);

// void append_attention_capacity(char**** & text_data, )

void change_pointer(int* & dates,
                    char**** & text_data,
                    int*** & int_data,
                    double*** & double_data,
                    int& size);

int find_date_index(int date, int* dates);

void insert_new_attention_date(std::ifstream&,
                               int date,
                               int* dates,
                               char**** text_data,
                               int*** int_data,
                               double*** double_data,
                               int& date_count,
                               int& attention_count);

void swap_char_pointer(char***&, char***&);

void swap_int_pointer(int**&, int**&);

void swap_double_pointer(double**&, double**&);

void read_attention(std::ifstream&,
                    char***,
                    int**,
                    double**);

void append_attention_to_date(std::ifstream&,
                              char**** text_data,
                              int*** int_data,
                              double*** double_data,
                              int& attention_count,
                              int index);

#endif //INC_2026_1_FUNCTIONS_HPP
