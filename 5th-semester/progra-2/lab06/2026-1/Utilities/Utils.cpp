//
// Created by zincronit on 10/29/26.
//

#include "Utils.hpp"

void Utils::open_input_file(std::ifstream& input, const char* filepath)
{
    input.open(filepath);
    if (not input.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        std::exit(1);
    }
}

void Utils::open_output_file(std::ofstream& output, const char* filepath)
{
    output.open(filepath);
    if (not output.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        std::exit(1);
    }
}

int Utils::read_int(std::ifstream& input)
{
    int value;
    input >> value;
    input.ignore();
    return value;
}

double Utils::read_double(std::ifstream& input)
{
    double value;
    input >> value;
    input.ignore();
    return value;
}


void Utils::print_text(
    std::ofstream& output,
    std::string text,
    int width,
    bool should_align_right)
{
    should_align_right ? output<< std::right : output << std::left;
    output << std::setw(width) << text;
}
