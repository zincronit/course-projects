//
// Created by zincronit on 11/7/26.
//

#include "Urgency.hpp"

Urgency::Urgency()
{
    injury_zone = "null";
    requires_xray = false;
}

Urgency& Urgency::operator=(const class Urgency& other)
{
    if (this == &other) return *this;
    Attention::operator=(other);
    injury_zone = other.injury_zone;
    requires_xray = other.requires_xray;
    return *this;
}

std::string Urgency::get_injury_zone() const { return injury_zone; }

void Urgency::set_injury_zone(const std::string& injury_zone) { this->injury_zone = injury_zone; }

bool Urgency::is_requires_xray() const { return requires_xray; }

void Urgency::set_requires_xray(const bool requires_xray) { this->requires_xray = requires_xray; }

void Urgency::read(std::ifstream& input, const int hour)
{
    Attention::read(input, hour);
    std::getline(input, injury_zone);
    input >> requires_xray;
    input.ignore();
}

void Urgency::print(std::ofstream& output) const
{
    Attention::print(output);
    int width = LINE_WIDTH / COLUMNS;
    Utils::print_text(output, injury_zone, width);
    output << std::setw(width);
    requires_xray ? output << "SI" : output << "NO";
}

int Urgency::get_priority() { return 2; }
