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

void Veterinary::load_apointments(const char* filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char type;
    while (true)
    {
        input >> type;
        if (input.eof()) break;
        input.get();
        if (type == 'C'){}
        else if (type == 'O'){}
        else {}
    }
    input.close();
}