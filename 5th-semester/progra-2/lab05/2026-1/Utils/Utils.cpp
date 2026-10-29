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

char* Utils::allocate_string(const char* text)
{
    char* string = new char[std::strlen(text) + 1];
    std::strcpy(string, text);
    return string;
}

int Utils::read_int(std::ifstream& input)
{
    int value;
    input >> value;
    input.get();
    return value;
}

double Utils::read_double(std::ifstream& input)
{
    double value;
    input >> value;
    input.get();
    return value;
}

char* Utils::read_string(std::ifstream& input, char delimiter)
{
    char buffer[TEXT_LENGTH];
    input.getline(buffer, TEXT_LENGTH, delimiter);
    if (input.eof()) return nullptr;
    char* string = allocate_string(buffer);
    return string;
}
