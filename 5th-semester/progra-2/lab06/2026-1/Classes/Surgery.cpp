//
// Created by zincronit on 10/29/26.
//

#include "Surgery.hpp"

Surgery::Surgery()
{
    general_anesthesia = false;
    doctor_count = 0;
    cost = 0.0;
}

Surgery::~Surgery() {}
bool Surgery::is_general_anesthesia() const { return general_anesthesia; }
void Surgery::set_general_anesthesia(const bool general_anesthesia) { this->general_anesthesia = general_anesthesia; }
int Surgery::get_doctor_count() const { return doctor_count; }
void Surgery::set_doctor_count(const int doctor_count) { this->doctor_count = doctor_count; }
double Surgery::get_cost() const { return cost; }
void Surgery::set_cost(const double cost) { this->cost = cost; }
