//
// Created by zincronit on 11/7/26.
//

#include "NotUrgent.hpp"

NotUrgent::NotUrgent()
{
    specialty = "null";
    is_scheduled_appointment = false;
}

NotUrgent& NotUrgent::operator=(const class NotUrgent& other)
{
    if (this == &other) return *this;
    Attention::operator=(other);
    specialty = other.specialty;
    is_scheduled_appointment = other.is_scheduled_appointment;
    return *this;
}

std::string NotUrgent::get_specialty() const { return specialty; }
void NotUrgent::set_specialty(const std::string& specialty) { this->specialty = specialty; }
bool NotUrgent::get_is_scheduled_appointment() const { return is_scheduled_appointment; }

void NotUrgent::set_is_scheduled_appointment(const bool is_scheduled_appointment)
{
    this->is_scheduled_appointment = is_scheduled_appointment;
}

void NotUrgent::read(std::ifstream& input, const int hour)
{
    Attention::read(input, hour);
    std::getline(input, specialty, ',');
    input >> is_scheduled_appointment;
    input.ignore();
}

void NotUrgent::print(std::ofstream& output) const
{
    Attention::print(output);
    Utils::print_text(output, specialty, LINE_WIDTH / COLUMNS);
    is_scheduled_appointment ? output << "SI" : output << "NO";
}

int NotUrgent::get_priority() { return 3; }
