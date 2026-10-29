//
// Created by zincronit on 10/2/26.
//

#include "Veterinary.hpp"

// class Pet* Veterinary::get_pet_list() const { return pet_list; }
// void Veterinary::set_pet_list(class Pet* const pet_list) { this->pet_list = pet_list; }
Veterinary::Veterinary()
{
    pet_list = nullptr;
    pet_count = 0;
}

Veterinary::~Veterinary()
{
    delete[] pet_list;
}

int Veterinary::get_pet_count() const { return pet_count; }

void Veterinary::set_pet_count(const int pet_count) { this->pet_count = pet_count; }

void Veterinary::append_pet_capacity(int& capacity)
{
    capacity += INCREASE;
    class Pet* aux = new Pet[capacity];
    if (capacity == INCREASE)
    {
        pet_list = aux;
        return;
    }
    for (int i = 0; i < pet_count; i++)
        aux[i] = pet_list[i];
    delete[] pet_list;
    pet_list = aux;
}

void Veterinary::operator <=(const char* filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    int capacity = 0;
    while (true)
    {
        class Pet pet;
        input >> pet;
        if (input.eof()) return;
        if (pet_count >= capacity - 1)
            append_pet_capacity(capacity);
        pet_list[pet_count] = pet; // falta hacer la sobrecargo del operador =
        pet_count++;
    }
    input.close();
}

void Veterinary::operator <<=(const char* filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char pet_name[TEXT_LENGTH];
    while (true)
    {
        class AppliedVaccine applied_vaccine;
        input.getline(pet_name, TEXT_LENGTH, ',');
        if (input.eof()) break;
        int owner_dni = Utils::read_int(input);
        int index = find_index(owner_dni, pet_name);
        if (index == NOT_FOUND)
        {
            input.ignore(500, '\n');
            continue;
        }
        input >> applied_vaccine;
        pet_list[index] += applied_vaccine;
    }
    input.close();
}

int Veterinary::find_index(const int owner_dni, const char* name) const
{
    char pet_name[TEXT_LENGTH];
    for (int i = 0; i < pet_count; i++)
    {
        pet_list[i].get_name(pet_name);
        if (pet_list[i].get_owner_dni() == owner_dni and
            std::strcmp(pet_name, name) == 0)
            return i;
    }
    return NOT_FOUND;
}

void Veterinary::operator <<(const char* filepath) const
{
    std::ofstream output;
    Utils::open_output_file(output, filepath);
    for (int i = 0; i < 60; i++) output.put('=');
    output << std::endl << "REPORTE DE CARTILLAS - VETIRINARIA HUELLITAS Y PLUMITAS" << std::endl;
    for (int i = 0; i < 60; i++) output.put('=');

    int current_dni = -1;
    for (int i = 0 ; i < pet_count; i++)
    {
        int owner_dni = pet_list[i].get_owner_dni();
        output << "\nDNI : " << owner_dni << std::endl << std::endl;
        output << pet_list[i];


    }

    output.close();
}
