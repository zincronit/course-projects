//
// Created by zincronit on 11/11/26.
//

#include "Attention.hpp"

int Attention::get_code() const { return code; }
int Attention::get_priority() const { return priority; }

Attention::Attention()
{
    code = 0;
    patient_name = "null";
    description = "null";
    priority = 0;
}

void Attention::read(std::ifstream& input)
{
    priority = Utils::read_int(input);
    code = Utils::read_int(input);
    std::getline(input, patient_name, ',');
    std::getline(input, description, ',');
}

void Attention::print(std::ofstream& output) const
{
    output << std::setw(WIDTH - 4) << code;
    Utils::print_text(output, patient_name, WIDTH - 4);
    Utils::print_text(output, description, WIDTH + 8 );
}
