//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_UTILS_HPP
#define GEMNINI_EXERCISE_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

#define LINE_WIDTH 100
#define COLUMNS 8
#define WIDTH LINE_WIDTH / COLUMNS

enum {HELLO , BOXSALE , PACKSALE , UNITSALE};
class Utils
{
public:
    static void open_input_file(std::ifstream& , const std::string& );
    static void open_output_file(std::ofstream& , const std::string& );
    static int read_int(std::ifstream& );
    static double read_double(std::ifstream& );
    static void print_text(std::ofstream& , const std::string& , int , bool should_align_right = false );
    static void print_line(std::ofstream& , char character = '=', int width = LINE_WIDTH);
    static void print_title(std::ofstream& );
    static int get_number(std::string);
};


#endif //GEMNINI_EXERCISE_UTILS_HPP
