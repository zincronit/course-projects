//
// Created by zincronit on 11/7/26.
//

#ifndef INC_2026_1_UTILS_HPP
#define INC_2026_1_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define LINE_WIDTH 170
#define COLUMNS 6
#define INCREASE 5

class Utils
{
public:
    static void open_input_file(std::ifstream &, const std::string& );
    static void open_output_file(std::ofstream &, const std::string& );
    static int read_int(std::ifstream& );
    static double read_double(std::ifstream& );
    static void print_text(std::ofstream& , const std::string& , int , bool should_align_right = false);
    static void print_line(std::ofstream & , char character = '=', int width = LINE_WIDTH );
    static std::string generate_filepath(const std::string& );

};



#endif //INC_2026_1_UTILS_HPP
