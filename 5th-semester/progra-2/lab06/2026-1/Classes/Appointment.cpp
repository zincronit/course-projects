//
// Created by zincronit on 10/29/26.
//

#include "Appointment.hpp"


int Appointment::get_date() const { return date; }

void Appointment::set_date(const int date) { this->date = date; }

int Appointment::get_hour() const { return hour; }

void Appointment::set_hour(const int hour) { this->hour = hour; }

Appointment::Appointment()
{
    date = 0;
    hour = 0;
}
Appointment::~Appointment(){}

void Appointment::read_appointment(std::ifstream& input)
{
    int mm , yy , dd ;
    char c ;
    input >> dd >> c >> mm >> c >> yy >> c;
    date = yy*10000 + dd*100 + dd;
    hour = Utils::read_int(input);
    pet.read_pet(input);
}

void Appointment::print_appointment(std::ofstream& output) const
{
    int width = LINE_WIDTH / 6;
    output << std::setw(width) << date;
    output << std::setw(width) << hour;
    pet.print_pet(output);
}