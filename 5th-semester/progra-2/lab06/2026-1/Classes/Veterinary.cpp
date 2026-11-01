//
// Created by zincronit on 10/29/26.
//

#include "Veterinary.hpp"
Veterinary::Veterinary()
{
    checkup_list = nullptr;
    checkup_count = 0;
    checkup_capacity = 0;
}

Veterinary::~Veterinary()
{
    delete[] checkup_list;
}

int Veterinary::get_checkup_count() const { return checkup_count; }

void Veterinary::set_checkup_count(const int checkup_count) { this->checkup_count = checkup_count; }

int Veterinary::get_checkup_capacity() const { return checkup_capacity; }

void Veterinary::set_checkup_capacity(const int checkup_capacity) { this->checkup_capacity = checkup_capacity; }

void Veterinary::load_appointments(const char* filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char type;
    int surgery_count = 0, vaccine_count = 0;
    while (true)
    {
        input.get(type);
        if (input.eof()) break;
        input.ignore();
        if (type == 'C')
        {
            class Checkup checkup;
            checkup.read_checkup(input);
            if (checkup_count >= checkup_capacity - 1)
                append_capacity_checkup();
            checkup_list[checkup_count++] = checkup;
        }
        else if (type == 'O')
            surgery_list[surgery_count++].read_surgery(input);
        else
            vaccine_list[vaccine_count++].read_vaccine(input);
    }
    input.close();
}

void Veterinary::append_capacity_checkup()
{
    checkup_capacity += 5;
    class Checkup* aux = new Checkup[checkup_capacity];
    if (checkup_capacity == 5)
    {
        checkup_list = aux;
        return;
    }
    for (int i = 0 ; i < checkup_count; i++)
        aux[i] = checkup_list[i];
    delete[] checkup_list;
    checkup_list = aux;
}

void Veterinary::show_appointments(const char* filepath)
{
    std::ofstream output;
    Utils::open_output_file(output, filepath);
    for (int i = 0 ; i < checkup_count ; i++)
        checkup_list[i].print_checkup(output);
    output << std::endl;
    for (int i = 0 ; vaccine_list[i].get_month() != 0 ; i++)
        vaccine_list[i].print_vaccine(output);
    output << std::endl;
    for (int i = 0 ; surgery_list[i].get_doctor_count() != 0 ; i++)
        surgery_list[i].print_surgery(output);
    output << std::endl;
    output.close();
}