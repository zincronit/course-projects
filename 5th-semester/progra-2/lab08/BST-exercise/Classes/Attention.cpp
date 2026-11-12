//
// Created by zincronit on 11/11/26.
//

#include "Attention.hpp"

Attention::Attention()
{
    priority = 0;
    code = 0;
    name = "null";
    description = "null";
}

int Attention::get_code() const { return code; }

void Attention::read(std::ifstream& input)
{
    priority = Utils::read_int(input);
    code = Utils::read_int(input);
    std::getline(input, name, ',');
    std::getline(input, description, ',');
}

void Attention::print(std::ofstream& output) const
{
    output << std::setw(WIDTH - 5) << code;
    Utils::print_text(output, name, WIDTH - 4);
    Utils::print_text(output, description, WIDTH + 9);
}
