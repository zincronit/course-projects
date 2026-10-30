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
