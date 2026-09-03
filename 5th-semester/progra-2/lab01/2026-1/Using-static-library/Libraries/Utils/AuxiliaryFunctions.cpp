//
// Created by zincronit on 9/2/26.
//

#include "AuxiliaryFunctions.hpp"

void open_output_file(std::ofstream& fout, const char* filepath)
{
    fout.open(filepath);
    if (not fout.is_open())
    {
        std::cout << "Error opening fie " << filepath << std::endl;
        std::exit(1);
    }
}

void open_input_file(std::ifstream& fin, const char* filepath)
{
    fin.open(filepath);
    if (not fin.is_open())
    {
        std::cout << "Error opening fie " << filepath << std::endl;
        std::exit(1);
    }
}

int read_date(std::ifstream& fin)
{
    int yy, mm, dd;
    char c;
    fin >> dd >> c >> mm >> c >> yy;
    fin.get();
    return yy * 10000 + mm *100 + dd;
}

int read_int(std::ifstream& fin, bool can_read )
{
    int value;
    fin >> value;
    if (can_read) fin.get();
    return value;
}

double read_double(std::ifstream& fin, bool can_read )
{
    double value;
    fin >> value;
    if (can_read) fin.get();
    return value;
}

char* read_string(std::ifstream& fin, char delimiter )
{
    char* string = nullptr;
    char buffer[TEXT_LENGTH];
    fin.getline(buffer, TEXT_LENGTH, delimiter);
    if (fin.eof()) return string;
    string = new char[std::strlen(buffer) + 1];
    std::strcpy(string, buffer);
    return string;
}
