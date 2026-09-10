//
// Created by zincronit on 9/9/26.
//

#include "tools.hpp"

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

void print_line(std::ofstream& fout, int width, char character)
{
    for (int i = 0; i < width; i++) fout.put(character);
    fout << std::endl;
}

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right)
{
    fout << std::left;
    if (should_align_right) fout << std::right;
    fout << std::setw(width) << text;
}

void print_spaces(std::ofstream& fout, int extra, int width)
{
    for (int i = 0; i < width - extra; i++) fout.put(' ');
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

char* allocate_string(const char* text)
{
    char* string = new char[std::strlen(text) + 1];
    std::strcpy(string, text);
    return string;
}

char* read_string(std::ifstream& fin, char delimiter)
{
    char* string;
    char buffer[TEXT_LENGTH];
    fin.getline(buffer, TEXT_LENGTH, delimiter);
    if (fin.eof()) return nullptr;
    string = allocate_string(buffer);
    return string;
}

int read_date(std::ifstream& fin)
{
    int dd, mm, yy;
    char c;
    fin >> dd >> c >> mm >> c >> yy;
    fin.get();
    return yy * 10000 + mm * 100 + dd;
}

int read_code(std::ifstream& fin)
{
    int x, y, z;
    char c;
    fin >> x >> c >> y >> c >> z;
    fin.get();
    return x * 1000000 + y * 10000 + z;
}

int read_time(std::ifstream& fin)
{
    int hh, mm, ss;
    char c;
    fin >> hh >> c >> mm >> c >> ss;
    fin.get();
    return hh * 3600 + mm * 60 + ss;
}


