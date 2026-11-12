//
// Created by zincronit on 11/11/26.
//

#include "Emergency.hpp"

Emergency::Emergency()
{
    rcp3 = false;
    waiting_time = 0;
}

Emergency::~Emergency()
{
    std::cout << "Destroying Emergency" << std::endl;
}

void Emergency::read(std::ifstream& input)
{
    Attention::read(input);
    input >> rcp3;
    input.ignore();
    waiting_time = Utils::read_int(input);
}

void Emergency::print(std::ofstream& output) const
{
    output << std::setw(WIDTH) << get_key();
    Attention::print(output);
    output << std::setw(WIDTH);
    rcp3 ? output << "SI" : output << "NO";
    output << waiting_time;
    output << std::endl;
}

int Emergency::get_key() const
{
    return EMERGENCY* 10000 + Attention::get_code();
}

Attention* Emergency::clone() const
{
    return new Emergency(*this);
}


