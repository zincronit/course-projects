//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_UTILS_HPP
#define BST_EXERCISE_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define LINE_WIDTH 180
#define COLUMNS 8
#define WIDTH LINE_WIDTH/COLUMNS

enum {HELLO, EMERGENCY , URGENCY , NON_URGENCY};

class Utils
{
public:
    static void open_input_file(std::ifstream& , const std::string& );
    static void open_output_file(std::ofstream& , const std::string& );
    static int read_int(std::ifstream& );
    static double read_double(std::ifstream& );
    static void print_text(std::ofstream& , const std::string& , int width , bool should_align_right = false);
    static void print_line(std::ofstream& , char character = '=' , int width = LINE_WIDTH - 60);
    static void print_title(std::ofstream& );
};


#endif //BST_EXERCISE_UTILS_HPP
