//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_UTILS_HPP
#define INC_2026_1_UTILS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Utils
{
public:
    static void open_input_file(std::ifstream& , const char* );
    static void open_ouput_file(std::ofstream& , const char* );
    
};


#endif //INC_2026_1_UTILS_HPP
