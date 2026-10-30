//
// Created by zincronit on 10/29/26.
//

#include "Checkup.hpp"

Checkup::Checkup()
{
    cost = 0.0;
    doctor_id = 0;
}
Checkup::~Checkup(){}
double Checkup::get_cost() const { return cost; }
void Checkup::set_cost(const double cost) { this->cost = cost; }
int Checkup::get_doctor_id() const { return doctor_id; }
void Checkup::set_doctor_id(const int doctor_id) { this->doctor_id = doctor_id; }
void Checkup::ead_checkup(std::ifstream& input)
{

}