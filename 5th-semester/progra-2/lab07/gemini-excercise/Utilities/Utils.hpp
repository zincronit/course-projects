//
// Created by zincronit on 11/5/26.
//

#ifndef GEMINI_EXCERCISE_UTILS_HPP
#define GEMINI_EXCERCISE_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define LINE_WIDTH 100
#define COLUMNS 8
#define INCREASE 5

class Utils
{
public:
    static void open_input_file(std::ifstream& , const char* );
    static void open_output_file(std::ofstream& , const char* );
    static int read_int(std::ifstream& );
    static double read_double(std::ifstream& );
    static void print_text(std::ofstream& ,const std::string , int , bool should_align_right = false);
    static void print_line(std::ofstream& , int width = LINE_WIDTH , char character = '=');
};


#endif //GEMINI_EXCERCISE_UTILS_HPP
