//
// Created by zincronit on 11/11/26.
//

#include "NonUrgency.hpp"

NonUrgency::NonUrgency()
{
    specialty = "null";
    is_scheduled = false;
}

NonUrgency::~NonUrgency()
{
    std::cout << "Destroying NonUrgency" << std::endl;
}

void NonUrgency::read(std::ifstream& input)
{
    Attention::read(input);
    std::getline(input, specialty, ',');
    input >> is_scheduled;
    input.ignore();
}

void NonUrgency::print(std::ofstream& output) const
{
    output << std::setw(WIDTH) << generate_key();
    Attention::print(output);
    Utils::print_text(output , specialty, WIDTH);
    is_scheduled ? output << "SI" : output << "NO";
    output << std::endl;
}

int NonUrgency::generate_key() const
{
    return Attention::get_priority() * 10000 + Attention::get_code();
}

Attention* NonUrgency::clone() const
{
    return new NonUrgency(*this);
}
