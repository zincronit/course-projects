//
// Created by zincronit on 9/27/26.
//

#include "Functions.hpp"

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

int* read_int(std::ifstream& fin, bool can_read_character)
{
    int aux;
    fin >> aux;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    int* value = new int{aux};
    return value;
}

double* read_double(std::ifstream& fin, bool can_read_character)
{
    double aux;
    fin >> aux;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    double* value = new double{aux};
    return value;
}

char* allocate_string(const char* text)
{
    char* string = new char[std::strlen(text) + 1];
    std::strcpy(string, text);
    return string;
}

char* read_string(std::ifstream& fin, char character)
{
    char buffer[TEXT_LENGTH];
    fin.getline(buffer, TEXT_LENGTH, character);
    if (fin.eof()) return nullptr;
    char* string = allocate_string(buffer);
    return string;
}

int* read_date(std::ifstream& fin, bool can_read_character)
{
    int dd, mm, yy;
    char character;
    fin >> dd >> character >> mm >> character >> yy;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    int* date = new int{yy * 10000 + mm * 100 + dd};
    return date;
}

int* read_time(std::ifstream& fin, bool can_read_character)
{
    int hh, mm;
    char character;
    fin >> hh >> character >> mm;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    int* time = new int{hh * 3600 + mm * 60};
    return time;
}

void print_line(std::ofstream& fout, char character, int width)
{
    for (int i = 0; i < width; i++) fout.put(character);
    fout << std::endl;
}

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right)
{
    should_align_right ? fout << std::right : fout << std::left;
    fout << std::setw(width) << text;
}

void** get_last_node(void* list)
{
    void** aux_list = static_cast<void **>(list);
    void** current = static_cast<void **>(aux_list[HEAD]);
    if (aux_list[HEAD] == nullptr) return nullptr;
    while (current[NEXT] != nullptr)
        current = static_cast<void **>(current[NEXT]);
    return current;
}

void print_date(std::ofstream& fout, int date, int width)
{
    int yy = date / 10000;
    int mm = date % 10000 / 100;
    int dd = date % 100;
    fout << std::right << std::setfill('0') << std::setw(4) << yy << '/';
    fout << std::setw(2) << mm << '/';
    fout << std::setw(2) << dd << std::setfill(' ');
    print_spaces(fout, 8, width);
}

void print_time(std::ofstream& fout, int time, int width)
{
    int hh = time / 3600;
    int mm = time % 3600 / 60;
    fout << std::right << std::setfill('0') << std::setw(2) << hh << ':';
    fout << std::setw(2) << mm << std::setfill(' ') << std::left;
    print_spaces(fout, 5, width);
}

void print_spaces(std::ofstream& fout, int extra, int width)
{
    for (int i = 0; i < width - extra; i++) fout.put(' ');
}
