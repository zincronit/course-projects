//
// Created by zincronit on 9/2/26.
//

#ifndef BUILD_STATIC_LIBRARY_AUXILIARYFUNCTIONS_HPP
#define BUILD_STATIC_LIBRARY_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"

void open_output_file(std::ofstream& fout, const char* filepath);

void open_input_file(std::ifstream& fin, const char* filepath);

int read_date(std::ifstream& fin);

int read_int(std::ifstream& fin, bool can_read = true);

double read_double(std::ifstream& fin, bool can_read = true);

char* read_string(std::ifstream& fin, char delimiter = ',');

#endif //BUILD_STATIC_LIBRARY_AUXILIARYFUNCTIONS_HPP
