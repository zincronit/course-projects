//
// Created by zincronit on 10/2/26.
//

#include "Veterinary.hpp"

Veterinary::Veterinary()
{
    pet_list = nullptr;
    pet_count = 0;
}

Veterinary::~Veterinary()
{
    delete[] pet_list;
}

int Veterinary::get_pet_count() const { return this->pet_count; }

void Veterinary::set_pet_count(const int count) { this->pet_count = count; }

void Veterinary::append_pet_capacity(int& capacity)
{
    capacity += INCREASE;
    class Pet* aux_pets = new Pet[capacity]{};
    if (capacity == INCREASE)
    {
        pet_list = aux_pets;
        return;
    }
    for (int i = 0; i < pet_count; i++) aux_pets[i] = pet_list[i];
    delete[] pet_list;
    pet_list = aux_pets;
}

void Veterinary::operator <=(const char* filepath)
{
    std::ifstream fin;
    Utils::open_input_file(fin, filepath);
    int capacity = 0;
    while (true)
    {
        class Pet pet;
        fin >> pet;
        if (fin.eof()) break;
        if (pet_count >= capacity)
            append_pet_capacity(capacity);
        pet_list[pet_count] = pet;
        pet_count++;
    }
    fin.close();
}

void Veterinary::operator <<=(const char* filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char pet_name[TEXT_LENGTH];
    int owner_dni, index;
    while (true)
    {
        class AppliedVaccine applied_vaccine;
        input.getline(pet_name, TEXT_LENGTH, ',');
        if (input.eof()) break;
        input >> owner_dni;
        input.get();
        index = find_pet_index(pet_name, owner_dni);
        if (index == -1)
        {
            input.ignore(100, '\n');
            continue;
        }
        input >> applied_vaccine;
        pet_list[index] += applied_vaccine;
    }
}

int Veterinary::find_pet_index(const char* name, int owner_dni) const
{
    char aux_name[TEXT_LENGTH];
    int aux_dni;
    for (int i = 0; i < pet_count; i++)
    {
        pet_list[i].get_name(aux_name);
        aux_dni = pet_list[i].get_owner_dni();
        if (std::strcmp(aux_name, name) == 0 and aux_dni == owner_dni) return i;
    }
    return -1;
}
