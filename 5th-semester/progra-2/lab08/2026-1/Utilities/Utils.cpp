//
// Created by zincronit on 11/11/26.
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

void Utils::print_line(std::ofstream& output, char character, int width)
{
    for (int i = 0; i < width; i++) output.put(character);
    output << std::endl;
}

void Utils::print_title(std::ofstream& output)
{
    const std::string title = "REPORTE DE ATENCIONES PRIORITARIAS\n";
    const std::string subtitle = "FECHA: 23-01-1990   HORA: 10 AM\n";
    Utils::print_text(output, title , (LINE_WIDTH + title.length())/2, true);
    Utils::print_text(output, subtitle , (LINE_WIDTH + subtitle.length())/2, true);
    Utils::print_line(output);
}