//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_UTILS_HPP
#define INC_2026_1_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define LINE_WIDTH 200
#define COLUMNS 8
#define WIDTH LINE_WIDTH/COLUMNS
#define INCREASE 5

enum {EMERGENCY, URGENCY, NON_URGENCY};

class Utils
{
public:
    static void open_input_file(std::ifstream&, const std::string&);

    static void open_output_file(std::ofstream&, const std::string&);

    static int read_int(std::ifstream&);

    static double read_double(std::ifstream&);

    static void print_text(std::ofstream&, const std::string&, int width , bool should_align_right = false);

    static void print_line(std::ofstream& , char character = '=', int width = LINE_WIDTH - 65);

    static void print_title(std::ofstream&);
};


#endif //INC_2026_1_UTILS_HPP
