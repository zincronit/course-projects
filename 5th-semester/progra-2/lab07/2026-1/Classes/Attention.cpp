//
// Created by zincronit on 11/7/26.
//

#include "Attention.hpp"

Attention::Attention()
{
    code = 0;
    patient = "null";
    description = "null";
    hour = 0;
}

Attention::Attention(const class Attention& other) { *this = other; }

Attention& Attention::operator=(const class Attention& other)
{
    if (this == &other) return *this;
    code = other.code;
    patient = other.patient;
    description = other.description;
    hour = other.hour;
    return *this;
}

int Attention::get_code() const { return code; }
void Attention::set_code(const int code) { this->code = code; }
std::string Attention::get_patient() const { return patient; }
void Attention::set_patient(const std::string& patient) { this->patient = patient; }
std::string Attention::get_description() const { return description; }

void Attention::set_description(const std::string& description)
{
    this->description = description;
}

int Attention::get_hour() const { return hour; }
void Attention::set_hour(const int hour) { this->hour = hour; }

void Attention::read(std::ifstream& input, const int hour)
{
    this->code = Utils::read_int(input);
    std::getline(input, this->patient, ',');
    std::getline(input, this->description, ',');
    this->hour = hour;
}

void Attention::print(std::ofstream& output) const
{
    int width = LINE_WIDTH / COLUMNS;
    output << std::left;
    output << std::setw(width) << code;
    output << std::setw(width) << patient;
    output << std::setw(width) << description;
}
