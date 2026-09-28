//
// Created by zincronit on 9/25/26.
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
    int* value;
    int aux;
    fin >> aux;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    value = new int{aux};
    return value;
}

double* read_double(std::ifstream& fin, bool can_read_character)
{
    double* value;
    double aux;
    fin >> aux;
    if (fin.eof()) return nullptr;
    if (can_read_character) fin.get();
    value = new double{aux};
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
    char *string, buffer[TEXT_LENGTH];
    fin.getline(buffer, TEXT_LENGTH, character);
    if (fin.eof()) return nullptr;
    string = allocate_string(buffer);
    return string;
}

void print_line(std::ofstream& fout, char character, int width)
{
    for (int i = 0; i < width; i++) fout.put(character);
    fout << std::endl;;
}

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right)
{
    fout << std::left;
    if (should_align_right) fout << std::right;
    fout << std::setw(width) << text;
}


void function(const char* filepath, void*& products)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    void** aux_products = nullptr, *product = nullptr;
    int count = 0, capacity = 0;
    while (true)
    {
        product = read_product(fin);
        if (fin.eof()) break;
        if (count >= capacity - 1)
            append_product_capacity(aux_products, capacity, count);
        aux_products[count] = product;
        count++;
    }
    products = aux_products;
    fin.close();
}

void* read_product(std::ifstream & fin)
{
    return nullptr;
}

void append_product_capacity(void**& products, int& capacity, int count)
{
    capacity += INCREASE;
    void** aux = new void*[capacity]{};
    if (capacity == INCREASE)
    {
        products = aux;
        return;
    }
    for (int  i = 0; i < count; i++) aux[i] = products[i];
    delete[] products;
    products = aux;
}

