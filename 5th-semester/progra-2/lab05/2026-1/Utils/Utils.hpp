//
// Created by zincronit on 10/7/26.
//

#ifndef INC_2026_1_UTILS_HPP
#define INC_2026_1_UTILS_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#define TEXT_LENGTH 100
#define INCREASE 5
#define NOT_FOUND -1
class Utils
{
public:
 static void open_input_file(std::ifstream& , const char* );

 static void open_output_file(std::ofstream& , const char* );

 static char* allocate_string(const char* text);

 static int read_int(std::ifstream& );

 static double read_double(std::ifstream& );

 static char* read_string(std::ifstream& , char delimiter = ',');
};


#endif //INC_2026_1_UTILS_HPP
