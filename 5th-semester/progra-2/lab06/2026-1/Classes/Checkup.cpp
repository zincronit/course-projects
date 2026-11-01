//
// Created by zincronit on 10/29/26.
//

#include "Checkup.hpp"

Checkup::Checkup()
{
    cost = 0.0;
    doctor_id = 0;
}

Checkup::~Checkup() {}
double Checkup::get_cost() const { return cost; }
void Checkup::set_cost(const double cost) { this->cost = cost; }
int Checkup::get_doctor_id() const { return doctor_id; }
void Checkup::set_doctor_id(const int doctor_id) { this->doctor_id = doctor_id; }

void Checkup::read_checkup(std::ifstream& input)
{
    read_appointment(input);
    doctor_id = Utils::read_int(input);
    cost = Utils::read_double(input);
}

void Checkup::print_checkup(std::ofstream& output) const
{
    int width = LINE_WIDTH / 6;
    print_appointment(output);
    output << std::setw(width) << doctor_id;
    output << std::fixed << std::setprecision(2) << cost << std::endl;
}
