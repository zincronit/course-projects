//
// Created by zincronit on 10/2/26.
//

#include "Pet.hpp"

#include <charconv>

Pet::Pet()
{
    owner_dni = 0;
    name = nullptr;
    specie = nullptr;
    age = 0;
    weight = 0;
    veterinary_id = nullptr;
    vaccine_count = 0;
}

Pet::~Pet()
{
    delete[] name;
    delete[] specie;
    delete[] veterinary_id;
}

int Pet::get_owner_dni() const { return owner_dni; }
void Pet::set_owner_dni(const int owner_dni) { this->owner_dni = owner_dni; }

void Pet::get_name(char* name) const
{
    if (this->name == nullptr)
    {
        name[0] = '\0';
        return;
    }
    std::strcpy(name, this->name);
}

void Pet::set_name(char* const name)
{
    if (this->name != nullptr) delete[] this->name;
    this->name = Utils::allocate_string(name);
}

void Pet::get_specie(char* specie) const
{
    if (this->specie == nullptr)
    {
        specie[0] = '\0';
        return;
    }
    std::strcpy(specie, this->specie);
}

void Pet::set_specie(char* const specie)
{
    if (this->specie != nullptr) delete[] this->specie;
    this->specie = Utils::allocate_string(specie);
}

int Pet::get_age() const { return age; }
void Pet::set_age(const int age) { this->age = age; }

double Pet::get_weight() const { return weight; }
void Pet::set_weight(const double weight) { this->weight = weight; }

void Pet::get_veterinary_id(char* id) const
{
    if (this->veterinary_id == nullptr)
    {
        id[0] = '\0';
        return;
    }
    std::strcpy(id, this->veterinary_id);
}

void Pet::set_veterinary_id(char* const veterinary_id)
{
    if (this->veterinary_id != nullptr) delete[] this->veterinary_id;
    this->veterinary_id = Utils::allocate_string(veterinary_id);
}

int Pet::get_vaccine_count() const { return vaccine_count; }
void Pet::set_vaccine_count(const int vaccine_count) { this->vaccine_count = vaccine_count; }

void Pet::read_pet(std::ifstream& input)
{
    owner_dni = Utils::read_int(input);
    if (input.eof()) return;
    name = Utils::read_string(input);
    specie = Utils::read_string(input);
    age = Utils::read_int(input);
    weight = Utils::read_double(input);
    veterinary_id = Utils::read_string(input, '\n');
}


Pet& Pet::operator =(const class Pet& other)
{
    if (this == &other) return *this;
    this->owner_dni = other.get_owner_dni();
    set_name(other.name);
    set_specie(other.specie);
    this->age = other.get_age();
    this->weight = other.get_weight();
    set_veterinary_id(other.veterinary_id);
    for (int i = 0; i < other.vaccine_count; i++)
        this->vaccine_list[i] = other.vaccine_list[i]; // tengo que crear esta sobrecarga
    this->vaccine_count = other.get_vaccine_count();
    return *this;
}

void Pet::operator +=(const class AppliedVaccine& vaccine)
{
    vaccine_list[vaccine_count] = vaccine;
    vaccine_count++;
}

bool Pet::operator ~() const
{
    for (int i = 0; i < vaccine_count; i++)
    {
        for (int j = i + 1; j < vaccine_count; j++)
            if (vaccine_list[i] == vaccine_list[j]) return true;
    }
    return false;
}

void Pet::print_vaccine_list(std::ofstream& output) const
{
    for (int i = 0 ; i < vaccine_count; i++)
        output << vaccine_list[i];
}

void operator >>(std::ifstream& input, class Pet& pet)
{
    pet.read_pet(input);
}

void operator <<(std::ofstream& output,const class Pet& pet)
{
    output << std::fixed << std::setprecision(2);
    char name[TEXT_LENGTH], specie[TEXT_LENGTH];
    pet.get_name(name);
    pet.get_specie(specie);
    output << "Mascota :" << name << "(" << specie << ", ";
    output << pet.get_age() << " anios, " << pet.get_weight() << " kg" << ")";

    if (~pet) output << "\n** ALERTA: cartilla con registros duplicados ** \n\n";
    pet.print_vaccine_list(output);
}
