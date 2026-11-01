//
// Created by zincronit on 10/29/26.
//

#include "Vaccine.hpp"

Vaccine::Vaccine()
{
    month = 0;
    dose = 0;
}

Vaccine::~Vaccine() {}
int Vaccine::get_dose() const { return dose; }
void Vaccine::set_dose(const int dose) { this->dose = dose; }
int Vaccine::get_month() const { return month; }
void Vaccine::set_month(const int month) { this->month = month; }


void Vaccine::read_vaccine(std::ifstream& input)
{
    read_appointment(input);
    dose = Utils::read_int(input);
    month = Utils::read_int(input);
}

void Vaccine::print_vaccine(std::ofstream& output)
{
    int width = LINE_WIDTH / 6;
    print_appointment(output);
    output << std::setw(width) << dose;
    output << month << std::endl;
}