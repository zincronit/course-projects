//
// Created by zincronit on 9/3/26.
//
#include "AuxiliaryFunctions.hpp"

void open_input_file(std::ifstream& fin, const char* filepath)
{
    fin.open(filepath);
    if (not fin.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

void open_output_file(std::ofstream& fout, const char* filepath)
{
    fout.open(filepath);
    if (not fout.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

int read_int(std::ifstream& fin, bool can_read)
{
    int value;
    fin >> value;
    if (can_read) fin.get();
    return value;
}

double read_double(std::ifstream& fin, bool can_read)
{
    double value;
    fin >> value;
    if (can_read) fin.get();
    return value;
}

char* read_string(std::ifstream& fin, char character)
{
    char* string = nullptr;
    char buffer[TEXT_LENGTH]{};
    fin.getline(buffer, TEXT_LENGTH, character);
    if (fin.eof()) return string;
    string = new char[std::strlen(buffer) + 1];
    std::strcpy(string, buffer);
    return string;
}

char* allocate_string(const char* text)
{
    char* string = new char[std::strlen(text) + 1];
    std::strcpy(string, text);
    return string;
}

void print_text(std::ofstream& fout, const char* text, int width)
{
    fout << std::left << std::setw(width) << text;
}

struct Student assign_student(struct Student& student)
{
    struct Student a;
    a.code = student.code;
    a.name = allocate_string(student.name);
    a.type = student.type;
    return a;
}
