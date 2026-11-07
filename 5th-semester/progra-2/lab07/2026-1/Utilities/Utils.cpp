//
// Created by zincronit on 11/7/26.
//

#include "Utils.hpp"

void Utils::open_input_file(std::ifstream& input, const std::string& filepath)
{
    input.open(filepath);
    if (not input.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

void Utils::open_output_file(std::ofstream& output, const std::string& filepath)
{
    output.open(filepath);
    if (not output.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
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

void Utils::print_text(std::ofstream& output, const std::string& text, int width, bool should_align_right)
{
    should_align_right ? output << std::right : output << std::left;
    output << std::setw(width) << text;
}

void Utils::print_line(std::ofstream& output, int width, char character)
{
    for (int i = 0; i < width; i++) output.put(character);
}

std::string Utils::generate_filepath(const std::string& date)
{
    std::string base_path = "../Files/Data/";
    for (int i = 0 ; i < date.length(); i++)
        date[i] == '-' ? base_path += '/' : base_path += date[i];
    return base_path;
}


