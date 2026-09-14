//
// Created by zincronit on 9/13/26.
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

int* read_int(std::ifstream& fin, bool read_character)
{
    int *value, aux;
    fin >> aux;
    if (fin.eof()) return nullptr;
    value = new int;
    *value = aux;
    if (read_character) fin.get();
    return value;
}

double* read_double(std::ifstream& fin, bool read_character)
{
    double* value = new double;
    fin >> *value;
    if (read_character) fin.get();
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
    char* string;
    char buffer[TEXT_LENGTH]{};
    fin.getline(buffer, TEXT_LENGTH, character);
    if (fin.eof()) return nullptr;
    string = allocate_string(buffer);
    return string;
}

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right)
{
    fout << std::left;
    if (should_align_right) fout << std::right;
    fout << std::setw(width) << text;
}

void print_line(std::ofstream& fout, char character, int width)
{
    for (int i = 0; i < width; i++) fout.put(character);
    fout << std::endl;
}

void load_patients(const char* filepath, void*& patients)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    void *patient, **aux_patients = nullptr;
    int count = 0, capacity = 0;
    while (true)
    {
        // 30001001,H. Glasspool,69,M
        patient = read_patient(fin);
        if (fin.eof()) break;
        if (count >= capacity - 1)
            append_patient_capacity(aux_patients, capacity, count);
        aux_patients[count] = patient;
        count++;
    }
    patients = aux_patients;
    fin.close();
}

void* read_patient(std::ifstream& fin)
{
    int *id, *age;
    char *name, *genre;
    id = read_int(fin);
    if (fin.eof()) return nullptr;
    fin.get();
    // 30001001,H. Glasspool,69,M
    name = read_string(fin);
    age = read_int(fin);
    genre = new char;
    fin.get(*genre);
    fin.get();
    void** aux = new void *[6]{};
    aux[0] = id;
    aux[1] = name;
    aux[2] = age;
    aux[3] = genre;
    aux[5] = new double(0);
    return aux;
}

void append_patient_capacity(void**& patients, int& capacity, int count)
{
    capacity += INCREASE;
    void** aux = new void *[capacity]{};
    if (capacity == INCREASE)
    {
        patients = aux;
        return;
    }
    for (int i = 0; i < count; i++) aux[i] = patients[i];
    delete [] patients;
    patients = aux;
}


void load_attention(const char* filepath, void* patients)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int *date, *time, *id, trash, hour;
    double* cost;
    while (true)
    {
        // 2026-04-01,08:00,30001001,75.00
        date = read_date(fin);
        if (fin.eof()) break;
        time = read_time(fin);
        id = read_int(fin);
        cost = read_double(fin);

    }
    fin.close();
}

int* read_date(std::ifstream& fin)
{
    int* date;
    int dd, mm, yy;
    char c;
    fin >> yy >> c >> mm >> c >> dd >> c;
    if (fin.eof()) return nullptr;
    date = new int;
    *date = yy * 1000 + mm * 100 + dd;
    return date;
}

int* read_time(std::ifstream& fin)
{
    int* time = new int;
    int hh , mm;
    char c;
    fin >> hh >> c >> mm >> c;
    *time = hh*3600 + mm*60 ;
    return time;
}
