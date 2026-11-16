//
// Created by zincronit on 11/16/26.
//

#ifndef ERASMO_2026_2_ADAPTADO_UTILS_HPP
#define ERASMO_2026_2_ADAPTADO_UTILS_HPP

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>

#define LINE_WIDTH 200
#define COLUMNS 8
#define WIDTH LINE_WIDTH/COLUMNS

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


#endif //ERASMO_2026_2_ADAPTADO_UTILS_HPP
