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

void Surgery::read_surgery(std::ifstream& input)
{
    read_appointment(input);
    cost = Utils::read_double(input);
    input >> general_anesthesia;
    input.ignore();
    doctor_count = Utils::read_int(input);
}

void Surgery::print_surgery(std::ofstream& output) const
{
    int width = LINE_WIDTH / 6;
    print_appointment(output);
    general_anesthesia
        ? Utils::print_text(output, "Parcial", width)
        : Utils::print_text(output, "General", width);
    output << doctor_count << std::endl;
}
