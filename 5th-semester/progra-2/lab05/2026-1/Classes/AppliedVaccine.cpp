//
// Created by zincronit on 10/2/26.
//

#include "AppliedVaccine.hpp"

AppliedVaccine::AppliedVaccine()
{
    name = nullptr;
    date = 0;
    dose = 0.0;
    veterinary_id = nullptr;
}

AppliedVaccine::~AppliedVaccine()
{
    delete[] name;
    delete[] veterinary_id;
}

void AppliedVaccine::get_name(char* name) const
{
    if (this->name == nullptr)
    {
        name[0] = '\0';
        return;
    }
    std::strcpy(name, this->name);
}

void AppliedVaccine::set_name(char* const name)
{
    if (this->name != nullptr) delete[] this->name;
    this->name = Utils::allocate_string(name);
}

int AppliedVaccine::get_date() const { return date; }

void AppliedVaccine::set_date(const int date) { this->date = date; }

double AppliedVaccine::get_dose() const { return dose; }

void AppliedVaccine::set_dose(const double dose) { this->dose = dose; }

void AppliedVaccine::get_veterinary_id(char* id) const
{
    if (this->veterinary_id == nullptr)
    {
        id[0] = '\0';
        return;
    }
    std::strcpy(id, this->veterinary_id);
}

void AppliedVaccine::set_veterinary_id(char* const veterinary_id)
{
    if (this->veterinary_id != nullptr) delete[] this->veterinary_id;
    this->veterinary_id = Utils::allocate_string(veterinary_id);
}

void AppliedVaccine::read_applied_vaccine(std::ifstream& input)
{
    // input.ignore(TEXT_LENGTH, ',');
    // input.ignore(TEXT_LENGTH, ',');
    name = Utils::read_string(input);
    date = Utils::read_int(input);
    dose = Utils::read_double(input);
    veterinary_id = Utils::read_string(input, '\n');
}

AppliedVaccine& AppliedVaccine::operator =(const class AppliedVaccine& other)
{
    if (this == &other) return *this;
    set_name(other.name);
    set_date(other.date);
    set_dose(other.dose);
    set_veterinary_id(other.veterinary_id);
    return *this;
}

bool AppliedVaccine::operator ==(const class AppliedVaccine& other) const
{
    if (std::strcmp(name, other.name) != 0) return false;
    if (date != other.date) return false;
    if (dose != other.dose) return false;
    if (std::strcmp(veterinary_id, other.veterinary_id) != 0) return false;
    return true;
}

void operator >>(std::ifstream& input, class AppliedVaccine& applied_vaccine)
{
    applied_vaccine.read_applied_vaccine(input);
}

void operator >>(std::ofstream& output,const class AppliedVaccine& applied_vaccine)
{
    char name[TEXT_LENGTH] , veterinary_id[TEXT_LENGTH];
    applied_vaccine.get_name(name);
    applied_vaccine.get_veterinary_id(veterinary_id);
    output << name << " : " << applied_vaccine.get_date() << " (";
    output << applied_vaccine.get_dose() << "ml, ";
    output << veterinary_id << ")";
}
