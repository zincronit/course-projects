//
// Created by zincronit on 10/2/26.
//

#include "AppliedVaccine.hpp"

AppliedVaccine::AppliedVaccine()
{
    name = nullptr;
    date = 0;
    dose = 0.0;
    veterinary_license = nullptr;
}

AppliedVaccine::~AppliedVaccine()
{
    delete [] name;
    delete [] veterinary_license;
}

void AppliedVaccine::get_name(char* namE) const
{
    if (this->name == nullptr) namE[0] = '\0';
    else std::strcpy(namE, this->name);
}

void AppliedVaccine::set_name(const char* namE)
{
    if (this->name != nullptr) delete [] name;
    this->name = new char[std::strlen(namE) + 1];
    std::strcpy(this->name, namE);
}

int AppliedVaccine::get_date() const { return this->date; }

void AppliedVaccine::set_date(const int datE) { this->date = datE; }

double AppliedVaccine::get_dose() const { return this->dose; }

void AppliedVaccine::set_dose(const double dosE) { this->dose = dosE; }

void AppliedVaccine::get_veterinary_license(char* veterinaryLicense) const
{
    if (this->veterinary_license == nullptr) veterinaryLicense[0] = '\0';
    else std::strcpy(veterinaryLicense, this->veterinary_license);
}

void AppliedVaccine::set_veterinary_license(const char* veterinaryLicense)
{
    if (this->veterinary_license != nullptr) delete [] veterinary_license;
    this->veterinary_license = new char[std::strlen(veterinaryLicense) + 1];
    std::strcpy(this->veterinary_license, veterinaryLicense);
}

void AppliedVaccine::read_applied_vaccine(std::istream& input)
{
    char aux_name[TEXT_LENGTH], aux_veterinary_license[TEXT_LENGTH];
    input.getline(aux_name, TEXT_LENGTH, ',');
    set_name(aux_name);
    input >> date;
    input.get();
    input >> dose;
    input.get();
    input.getline(aux_veterinary_license, TEXT_LENGTH, '\n');
    set_veterinary_license(aux_veterinary_license);
}

AppliedVaccine& AppliedVaccine::operator =(const class AppliedVaccine& other)
{
    if (this == &other) return *this;
    char aux_name[TEXT_LENGTH], aux_veterinary_license[TEXT_LENGTH];
    other.get_name(aux_name);
    other.get_veterinary_license(aux_veterinary_license);
    set_name(aux_name);
    set_veterinary_license(aux_veterinary_license);
    this->date = other.get_date();
    this->dose = other.get_dose();
    return *this;
}

void operator >>(std::istream& input, AppliedVaccine& applied_vaccine)
{
    applied_vaccine.read_applied_vaccine(input);
}
