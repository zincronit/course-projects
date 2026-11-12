//
// Created by zincronit on 11/11/26.
//

#include "Urgency.hpp"

Urgency::Urgency()
{
    injury_zone = "null";
    require_xray = false;
}

Urgency::~Urgency()
{
    std::cout << "Destroying Urgency" << std::endl;
}

void Urgency::read(std::ifstream& input)
{
    Attention::read(input);
    std::getline(input, injury_zone, ',');
    input >> require_xray;
    input.ignore();
}

void Urgency::print(std::ofstream& output) const
{
    output << std::setw(WIDTH) << get_key();
    Attention::print(output);
    Utils::print_text(output, injury_zone, WIDTH);
    require_xray ? output << "SI" : output << "NO";
    output << std::endl;
}

int Urgency::get_key() const
{
    return URGENCY * 10000 + Attention::get_code();
}

Attention* Urgency::clone() const
{
    return new Urgency(*this);
}
