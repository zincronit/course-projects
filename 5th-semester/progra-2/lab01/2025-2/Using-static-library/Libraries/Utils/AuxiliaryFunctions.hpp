//
// Created by zincronit on 9/3/26.
//

#ifndef BUILD_STATIC_LIBRARY_AUXILIARYFUNCTIONS_HPP
#define BUILD_STATIC_LIBRARY_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"
#include "../Structs/Course.hpp"

void open_input_file(std::ifstream& fin, const char* filepath);

void open_output_file(std::ofstream& fout, const char* filepath);

int read_int(std::ifstream& fin, bool can_read = true);

double read_double(std::ifstream& fin, bool can_read = true);

char* read_string(std::ifstream& fin, char character = ',');

char* allocate_string(const char* text);

void print_text(std::ofstream& fout, const char* text, int width);

struct Student assign_student(struct Student& student);


#endif //BUILD_STATIC_LIBRARY_AUXILIARYFUNCTIONS_HPP
