//
// Created by zincronit on 10/7/26.
//

#include "Utils.hpp"


void Utils::open_input_file(std::ifstream& input, const char* filepath)
{
    input.open(filepath);
    if (not input.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

void Utils::open_output_file(std::ofstream& output, const char* filepath)
{
    output.open(filepath);
    if (not output.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}
