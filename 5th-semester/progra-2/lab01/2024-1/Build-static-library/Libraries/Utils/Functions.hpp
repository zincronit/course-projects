//
// Created by zincronit on 8/30/26.
//

#ifndef BUILD_STATIC_LIBRARY_FUNCTIONS_HPP
#define BUILD_STATIC_LIBRARY_FUNCTIONS_HPP

#include "Utils.hpp"

void open_output_file(std::ofstream& fout, const char* filepath);

void open_input_file(std::ifstream& fin, const char* filepath);

void print_line(std::ofstream& fout, int width, char character);

void print_title(std::ofstream& fout, const char* title, int width);

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right = false);

void print_space(std::ofstream& fout, int extra, int width);

int read_int(std::ifstream& fin, bool can_read_character = true);

double read_double(std::ifstream& fin, bool can_read_character = true);

char* read_string(std::ifstream& fin, char character = ',');

char* allocate_string(const char* text);


#endif //BUILD_STATIC_LIBRARY_FUNCTIONS_HPP
