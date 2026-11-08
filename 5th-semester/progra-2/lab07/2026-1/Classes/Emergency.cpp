//
// Created by zincronit on 11/7/26.
//

#include "Emergency.hpp"

Emergency::Emergency()
{
    requires_rcp = false;
    minutes_without_pulse = 0;
}

Emergency& Emergency::operator=(const class Emergency& other)
{
    if (this == &other) return *this;
    Attention::operator=(other);
    requires_rcp = other.requires_rcp;
    minutes_without_pulse = other.minutes_without_pulse;
    return *this;
}
bool Emergency::is_requires_rcp() const { return requires_rcp; }
void Emergency::set_requires_rcp(const bool requires_rcp) { this->requires_rcp = requires_rcp; }
int Emergency::get_minutes_without_pulse() const { return minutes_without_pulse; }

void Emergency::set_minutes_without_pulse(const int minutes_without_pulse)
{
    this->minutes_without_pulse = minutes_without_pulse;
}

void Emergency::read(std::ifstream& input,const int hour)
{
    Attention::read(input, hour);
    input >> requires_rcp;
    input.ignore();
    minutes_without_pulse = Utils::read_int(input);
}
void Emergency::print(std::ofstream& output) const
{
    Attention::print(output);
    int width = LINE_WIDTH/COLUMNS;
    output << std::setw(width);
    requires_rcp ? output << "SI" : output << "NO";
    output << std::setw(width) << minutes_without_pulse<< std::endl;
}

int Emergency::get_priority(){return 1;}
