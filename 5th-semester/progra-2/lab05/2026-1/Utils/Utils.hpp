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

class Utils
{
public:
    static void open_input_file(std::ifstream&, const char*);

    static void open_output_file(std::ofstream&, const char*);
};


#endif //INC_2026_1_UTILS_HPP
