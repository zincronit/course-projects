//
// Created by zincronit on 9/27/26.
//

#include "Functions.hpp"

void open_input_file(std::ifstream& fin, const char* filepath)
{
    fin.open(filepath);
    if (not fin.is_open())
    {
        std::cout << "Error opening file" << filepath << std::endl;
        std::exit(1);
    }
}

void open_output_file(std::ofstream& fout, const char* filepath)
{
    fout.open(filepath);
    if (not fout.is_open())
    {
        std::cout << "Error opening file" << filepath << std::endl;
        std::exit(1);
    }
}

int* read_int(std::ifstream& fin, bool can_read_character)
{
    int* pointer;
    int value;
    fin >> value;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    pointer = new int{value};
    return pointer;
}

double* read_double(std::ifstream& fin, bool can_read_character)
{
    double* pointer;
    double value;
    fin >> value;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    pointer = new double{value};
    return pointer;
}

char* allocate_string(const char* text)
{
    char* string = new char[std::strlen(text) + 1];
    std::strcpy(string, text);
    return string;
}

char* read_string(std::ifstream& fin, char character)
{
    char *string, buffer[TEXT_LENGTH];
    fin.getline(buffer, TEXT_LENGTH, character);
    if (fin.eof()) return nullptr;
    string = allocate_string(buffer);
    return string;
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

int* read_date(std::ifstream& fin, bool can_read_character)
{
    int dd, mm, yy;
    char character;
    fin >> dd >> character >> mm >> character >> yy;
    if (can_read_character) fin.get();
    int* date = new int{yy * 1000 + mm * 100 + dd};
    return date;
}

int* read_time(std::ifstream& fin, bool can_read_character)
{
    int hh, mm;
    char character;
    fin >> hh >> character >> mm;
    if (can_read_character) fin.get();
    int* time = new int{hh * 3600 + mm * 60};
    return time;
}

void* initialize_list()
{
    void** aux = new void *[2]{};
    aux[HEAD] = nullptr;
    aux[SIZE] = new int{0};
    return aux;
}

void insert_back(void* & list, void* data)
{
    void** aux_list = static_cast<void **>(list);
    void** new_node = new void *[2]{};
    new_node[DATA] = data;
    new_node[NEXT] = nullptr;
    void** last = get_last_node(list);
    last == nullptr ? aux_list[HEAD] = new_node : last[NEXT] = new_node;
    *static_cast<int *>(aux_list[SIZE]) += 1;
}


void** get_last_node(void* list)
{
    if (is_empty_list(list)) return nullptr;
    void** aux_list = static_cast<void **>(list);
    void** current = static_cast<void **>(aux_list[HEAD]);
    while (current[NEXT] != nullptr) current = static_cast<void **>(current[NEXT]);
    return current;
}

bool is_empty_list(void* list)
{
    void** aux_list = static_cast<void **>(list);
    return aux_list[HEAD] == nullptr;
}
