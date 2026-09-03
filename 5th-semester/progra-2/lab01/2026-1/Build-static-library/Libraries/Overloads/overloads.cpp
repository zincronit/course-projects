//
// Created by zincronit on 9/2/26.
//

#include "overloads.hpp"

void operator >>(std::ifstream& fin, struct Pet& pet)
{
    // 101,Luna,Labrador,Negro,CANINO,10/10/2024
    int id;
    id = read_int(fin);
    if (fin.eof()) return;
    pet.id = id;
    pet.name = read_string(fin);
    pet.color = read_string(fin);
    pet.breed = read_string(fin);
    pet.type = read_string(fin);
    pet.birthdate = read_date(fin);
}

void operator >>(std::ifstream& fin, struct Veterinary& veterinary)
{
    // 201,Miguel Perez,MedicinaGeneral
    int id;
    id = read_int(fin);
    if (fin.eof()) return;
    veterinary.id = id;
    veterinary.name = read_string(fin);
    veterinary.specialty = read_string(fin, '\n');
}

void operator >>(std::ifstream& fin, struct Attention& attention)
{
    // 101,204,7/4/2025,CONTROL,11:00,PROGRAMADA
    int pet_id;
    pet_id = read_int(fin);
    if (fin.eof()) return;
    attention.pet_id = pet_id;
    attention.veterinary_id = read_int(fin);
    attention.date = read_date(fin);
    attention.type = read_string(fin);
    attention.hour = read_int(fin);
    attention.minute = read_int(fin);
    attention.status = read_string(fin, '\n');
}

bool operator ==(struct Attention& attention, struct Attention& attention2)
{
    int value;
    // value = attention.pet_id - attention2.pet_id;
    value += attention.veterinary_id - attention2.veterinary_id;
    value += attention.date - attention2.date;
    // value += std::strcmp(attention.type, attention2.type);
    value += attention.hour - attention2.hour;
    value += attention.minute - attention2.minute;
    // value += std::strcmp(attention.status, attention2.status);
    if (value == 0) return true;
    return false;
}

bool operator <=(struct Pet& pet, int date)
{
    if (pet.birthdate <= date) return true;
    return false;
}

void operator <<(std::ofstream& fout, struct Pet& pet)
{
    fout << "ID: " << pet.id << std::endl;
    fout << "   Name: " << pet.name << std::endl;
    fout << "   Breed: " << pet.breed << std::endl;
    fout << "   Color: " << pet.color << std::endl;
    fout << "   Type: " << pet.type << std::endl;
}

void operator <<(std::ofstream& fout, struct Attention& attention)
{
    fout << "  Date: " << attention.date << ',';
    fout << "  ID:" << attention.id << ',';
    fout << "  Veterinary: " << attention.veterinary_id << ',';
    fout << "  Type: " << attention.type << ',';
    fout << "  Status: " << attention.status << std::endl;
}
