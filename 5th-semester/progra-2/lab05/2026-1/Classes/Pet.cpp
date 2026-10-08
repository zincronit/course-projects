//
// Created by zincronit on 10/2/26.
//

#include "Pet.hpp"


Pet::Pet()
{
    owner_dni = 0;
    name = nullptr;
    specie = nullptr;
    age = 0;
    weight = 0.0;
    veterinary_code = nullptr;
    vaccine_count = 0;
}

Pet::~Pet()
{
    delete [] name;
    delete [] specie;
    delete [] veterinary_code;
}

int Pet::get_owner_dni() const { return this->owner_dni; }

void Pet::set_owner_dni(const int owner_dnI) { this->owner_dni = owner_dnI; }

void Pet::get_name(char* namE) const
{
    if (this->name == nullptr)
    {
        namE[0] = '\0';
        return;
    }
    std::strcpy(namE, this->name);
}

void Pet::set_name(const char* namE)
{
    if (this->name != nullptr) delete[] this->name;
    this->name = new char[std::strlen(namE) + 1];
    std::strcpy(this->name, namE);
}

void Pet::get_specie(char* speciE) const
{
    if (this->specie == nullptr)
    {
        speciE[0] = '\0';
        return;
    }
    std::strcpy(speciE, this->specie);
}

void Pet::set_specie(const char* speciE)
{
    if (this->specie != nullptr) delete[] this->specie;
    this->specie = new char[std::strlen(speciE) + 1];
    std::strcpy(this->specie, speciE);
}

int Pet::get_age() const { return this->age; }

void Pet::set_age(const int agE) { this->age = agE; }

double Pet::get_weight() const { return this->weight; }

void Pet::set_weight(const double weighT) { this->weight = weighT; }

void Pet::get_veterinary_code(char* veterinaryCode) const
{
    if (this->veterinary_code == nullptr)
    {
        veterinaryCode[0] = '\0';
        return;
    }
    std::strcpy(veterinaryCode, this->veterinary_code);
}

void Pet::set_veterinary_code(const char* veterinaryCode)
{
    if (this->veterinary_code != nullptr) delete[] this->veterinary_code;
    this->veterinary_code = new char[std::strlen(veterinaryCode) + 1];
    std::strcpy(this->veterinary_code, veterinaryCode);
}

int Pet::get_vaccine_count() const { return this->vaccine_count; }

void Pet::set_vaccine_count(const int vaccineCount) { this->vaccine_count = vaccineCount; }

void Pet::read_pet(std::istream& input)
{
    char aux_name[TEXT_LENGTH], aux_specie[TEXT_LENGTH], aux_veterinary_code[TEXT_LENGTH];
    input >> owner_dni;
    if (input.eof()) return;
    input.get();
    input.getline(aux_name, TEXT_LENGTH, ',');
    input.getline(aux_specie, TEXT_LENGTH, ',');
    input >> age;
    input.get();
    input >> weight;
    input.get();
    input.getline(aux_veterinary_code, TEXT_LENGTH, '\n');
    set_name(aux_name);
    set_specie(aux_specie);
    set_veterinary_code(aux_veterinary_code);
}

Pet& Pet::operator =(const class Pet& other)
{
    if (this == &other) return *this;
    char aux_name[TEXT_LENGTH], aux_specie[TEXT_LENGTH], aux_veterinary_code[TEXT_LENGTH];
    other.get_name(aux_name);
    other.get_specie(aux_specie);
    other.get_veterinary_code(aux_veterinary_code);
    set_name(aux_name);
    set_specie(aux_specie);
    set_veterinary_code(aux_veterinary_code);
    this->owner_dni = other.get_owner_dni();
    this->age = other.get_age();
    this->weight = other.get_weight();
    // veccine list =
    for (int i = 0; i < other.get_vaccine_count(); i++)
        this->vaccine_list[i] = other.vaccine_list[i];
    this->vaccine_count = other.get_vaccine_count();
    return *this;
}

void Pet::operator +=(const class AppliedVaccine& applied_vaccine)
{
    vaccine_list[vaccine_count] = applied_vaccine;
    vaccine_count++;
}

void operator >>(std::istream& input, Pet& pet)
{
    pet.read_pet(input);
}
