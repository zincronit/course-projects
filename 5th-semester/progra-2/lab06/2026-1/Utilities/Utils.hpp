//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_UTILS_HPP
#define INC_2026_1_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define LINE_WIDTH 100

class Utils
{
public:
    static void open_input_file(std::ifstream& , const char* );
    static void open_output_file(std::ofstream& , const char* );
    static int read_int(std::ifstream& );
    static double read_double(std::ifstream& );
    static void print_text(std::ofstream&  , std::string , int width = LINE_WIDTH , bool should_align_right = false);
};


#endif //INC_2026_1_UTILS_HPP
