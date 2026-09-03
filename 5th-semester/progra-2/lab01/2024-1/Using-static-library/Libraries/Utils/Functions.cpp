//
// Created by zincronit on 8/30/26.
//

#include "Functions.hpp"

void open_output_file(std::ofstream& fout, const char* filepath)
{
    fout.open(filepath);
    if (not fout.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

void open_input_file(std::ifstream& fin, const char* filepath)
{
    fin.open(filepath);
    if (not fin.is_open())
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

void print_title(std::ofstream& fout, const char* title, int width)
{
    fout << std::right << std::setw((std::strlen(title) + width) / 2) << title;
    fout << std::endl;
    print_line(fout , width, '=');
}

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right)
{
    fout << std::left;
    if (should_align_right) fout << std::right;
    fout << std::setw(width) << text;
}

void print_space(std::ofstream& fout, int extra, int width)
{
    for (int i = 0; i < width - extra; i++) fout.put(' ');
}

int read_int(std::ifstream& fin, bool can_read_character)
{
    int value;
    fin >> value;
    if (can_read_character) fin.get();
    return value;
}

double read_double(std::ifstream& fin, bool can_read_character)
{
    double value;
    fin >> value;
    if (can_read_character) fin.get();
    return value;
}

char* read_string(std::ifstream& fin, char character)
{
    char* string = nullptr;
    char buffer[TEXT_LENGTH];
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

void print_header_customer(std::ofstream& fout ,bool fulfilled)
{
    int width = (LINE_WIDTH - 50)/COLUMNS2;
    print_text(fout, "order No.", width, true);
    print_text(fout, "Code", width, true);
    if (fulfilled) print_text(fout, "Price", width, true);
    fout << std::endl;
}