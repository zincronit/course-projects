//
// Created by zincronit on 9/13/26.
//

#include "Functions.hpp"

#include <algorithm>

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

int* read_date(std::ifstream& fin)
{
    int* date;
    int dd, mm, yy;
    char c;
    // 2026-04-01
    fin >> yy;
    if (fin.eof()) return nullptr;
    fin >> c >> mm >> c >> dd;
    fin.get();
    date = new int{yy * 10000 + mm * 100 + dd};
    return date;
}

int* read_time(std::ifstream& fin)
{
    int* time;
    int hh, mm;
    char c;
    // 08:00
    fin >> hh;
    if (fin.eof()) return nullptr;
    fin >> c >> mm;
    fin.get();
    time = new int{hh * 3600 + mm * 60};
    return time;
}

void load_patients(const char* filepath, void*& patients)
{
    std::ifstream fin;
    open_input_file(fin, filepath);

    int count = 0, capacity = 0;
    void **aux = nullptr, *patient;
    while (true)
    {
        patient = read_patient(fin);
        if (fin.eof()) break;
        if (count >= capacity - 1)
            append_patient_capacity(aux, capacity, count);
        aux[count] = patient;
        ++count;
    }
    patients = aux;
    fin.close();
}


void* read_patient(std::ifstream& fin)
{
    // 30001001,H. Glasspool,69,M
    int *id, *age;
    char *name, *genre;
    id = read_int(fin);
    if (fin.eof()) return nullptr;
    name = read_string(fin);
    age = read_int(fin);
    genre = read_string(fin, '\n');
    void** patient = new void *[6]{};
    patient[ID] = id;
    patient[NAME] = name;
    patient[AGE] = age;
    patient[GENRE] = genre;
    patient[ATTENTIONS] = nullptr;
    patient[TOTAL_COST] = new double{0.0};
    return patient;
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
    delete[] patients;
    patients = aux;
}

void load_attentions(const char* filepath, void* patients)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int count[MAX_ATTENTION]{}, capacity[MAX_ATTENTION]{};
    int *date, *time, *id, index;
    double* cost;
    while (true)
    {
        // 2026-04-01,08:00,30001001,75.00
        date = read_date(fin);
        if (fin.eof()) break;
        time = read_time(fin);
        id = read_int(fin);
        cost = read_double(fin);
        index = find_index((void **) patients, id);
        if (index == NOT_FOUND)
        {
            delete date;
            delete time;
            delete cost;
            delete id;
            continue;
        }
        append_attentions((void **) patients, index, capacity, count, date, time, cost);
        delete id;
    }

    fin.close();
}

int find_index(void** patients, int* id)
{
    for (int i = 0; patients[i] != nullptr; i++)
    {
        if (is_equal((void **) patients[i], id)) return i;
    }
    return NOT_FOUND;
}

bool is_equal(void** patient, int* id)
{
    return *(int *) patient[ID] == *id;
}

void append_attentions(
    void** patients,
    int index,
    int* capacity,
    int* count,
    int* date,
    int* time,
    double* cost)
{
    void** patient = (void **) patients[index];
    void** attentions = (void **) patient[ATTENTIONS];
    if (count[index] >= capacity[index] - 1)
    {
        append_attention_capacity(attentions, capacity[index], count[index]);
        patient[ATTENTIONS] = attentions;
    }
    *(double *) patient[TOTAL_COST] += *cost;
    attentions[count[index]] = insert_data(date, time, cost);
    ++count[index];
}

void* insert_data(int* date, int* time, double* cost)
{
    void** attention = new void *[3]{};
    attention[DATE] = date;
    attention[TIME] = time;
    attention[ATTENTION_COST] = cost;
    return attention;
}

void append_attention_capacity(void**& attentios, int& capacity, int count)
{
    capacity += INCREASE;
    void** aux = new void *[capacity]{};
    if (capacity == INCREASE)
    {
        attentios = aux;
        return;
    }
    for (int i = 0; i < count; i++) aux[i] = attentios[i];
    delete[] attentios;
    attentios = aux;
}

void make_report(const char* filepath, void* patients)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    fout << std::fixed << std::setprecision(2);
    print_title(fout);
    void** aux_patients = (void **) patients;
    print_header(fout);
    for (int i = 0; aux_patients[i] != nullptr; i++)
    {
        print_patients(fout, (void **) aux_patients[i]);
    }
    fout.close();
}

void print_title(std::ofstream& fout)
{
    char title[] = "REPORTE DEL SISTEMA DE URGENCIAS";
    print_line(fout);
    print_text(fout, title, (std::strlen(title) + LINE_WIDTH) / 2, true);
    fout << std::endl;
    print_line(fout);
    fout << std::endl;
}

void print_header(std::ofstream& fout)
{
    int width = LINE_WIDTH / COLUMNS;
    print_line(fout, '-');
    print_text(fout, "ID", width);
    print_text(fout, "Nombre", width);
    print_text(fout, "Edad", width);
    print_text(fout, "Genero", width);
    print_text(fout, "Visitas", width);
    print_text(fout, "Total", width);
    fout << std::endl;
    print_line(fout, '-');
}

void print_patients(std::ofstream& fout, void** patient)
{
    int width = LINE_WIDTH / COLUMNS;
    int attention_count = 0;
    fout << std::setw(width) << *(int *) patient[ID];
    print_text(fout, (char *) patient[NAME], width);
    fout << std::setw(width) << *(int *) patient[AGE];
    fout << std::setw(width) << *(char *) patient[GENRE];
    void** attentions = (void **) patient[ATTENTIONS];
    for (int i= 0 ; attentions[i] != nullptr; i++ ) attention_count++;
    fout << std::setw(width) << attention_count;
    fout << *(double*)patient[TOTAL_COST];
    fout << std::endl;
}
