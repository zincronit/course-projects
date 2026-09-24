//
// Created by zincronit on 9/13/26.
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

int* read_int(std::ifstream& fin, bool can_read)
{
    int *value, aux;
    fin >> aux;
    if (fin.eof()) return nullptr;
    if (can_read) fin.get();
    value = new int{aux};
    return value;
}

double* read_double(std::ifstream& fin, bool can_read)
{
    double *value, aux;
    fin >> aux;
    if (can_read) fin.get();
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
    fin.getline(buffer,TEXT_LENGTH, character);
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
    fout << std::left;
    if (should_align_right) fout << std::right;
    fout << std::setw(width) << text;
}

int* read_time(std::ifstream& fin)
{
    int* time;
    int hh, mm;
    char c;
    fin >> hh >> c >> mm >> c;
    time = new int{hh * 3600 + mm * 60};
    return time;
}

int* read_date(std::ifstream& fin)
{
    int* date;
    int dd, mm, yy;
    char c;
    fin >> yy;
    if (fin.eof()) return nullptr;
    fin >> c >> mm >> c >> dd >> c;
    date = new int{yy * 10000 + mm * 100 + dd};
    return date;
}

void load_patients(const char* filepath, void*& patients)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    void **aux_patients = nullptr, *patient = nullptr;
    int capacity = 0, count = 0;
    while (true)
    {
        patient = read_patient(fin);
        if (fin.eof()) break;
        if (count >= capacity - 1)
            append_patient_capacity(aux_patients, capacity, count);
        aux_patients[count] = patient;
        count++;
    }
    shrink_patient_capacity(aux_patients, count);
    patients = aux_patients;
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

void shrink_patient_capacity(void**& patients, int count)
{
    void** aux = new void *[count + 1]{};
    for (int i = 0; i < count; i++) aux[i] = patients[i];
    delete[] patients;
    patients = aux;
}

void load_attentions(const char* filepath, void* patients)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int *date, *time, *id, index;
    double* cost;
    int capacity[MAX_ATTENTIONS]{}, count[MAX_ATTENTIONS]{};
    while (true)
    {
        // 2026-04-01,08:00,30001001,75.00
        date = read_date(fin);
        if (fin.eof()) break;
        time = read_time(fin);
        id = read_int(fin);
        cost = read_double(fin);
        index = find_index(static_cast<void **>(patients), id);
        if (index == NOT_FOUND)
        {
            delete date;
            delete time;
            delete id;
            delete cost;
            continue;
        }
        append_attention(
            static_cast<void **>(patients),
            index,
            capacity[index],
            count[index],
            date,
            time,
            cost
        );
        delete id;
    }
    fin.close();
}

int find_index(void** patients, int* id)
{
    for (int i = 0; patients[i] != nullptr; i++)
        if (has_same_id(patients[i], id)) return i;
    return NOT_FOUND;
}

bool has_same_id(void* patient, int* id)
{
    void** aux_patient = static_cast<void **>(patient);
    int* patient_id = static_cast<int *>(aux_patient[ID]);
    return *patient_id == *id;
}

void append_attention(void** patients, int index, int& capacity, int& count, int* date, int* time, double* cost)
{
    void** patient = static_cast<void **>(patients[index]);
    void** attentions = static_cast<void **>(patient[ATTENTIONS]);
    if (count >= capacity - 1)
    {
        append_patient_capacity(attentions, capacity, count);
        patient[ATTENTIONS] = attentions;
    }
    *static_cast<double *>(patient[TOTAL_COST]) += *cost;
    attentions[count] = insert_data(date, time, cost);
    count++;
}

void append_attention_capacity(void**& attentions, int& capacity, int count)
{
    capacity += INCREASE;
    void** aux = new void *[capacity]{};
    if (capacity == INCREASE)
    {
        attentions = aux;
        return;
    }
    for (int i = 0; i < count; i++) aux[i] = attentions[i];
    delete[] attentions;
    attentions = aux;
}

void* insert_data(int* date, int* time, double* cost)
{
    void** attention = new void *[3]{};
    attention[DATE] = date;
    attention[TIME] = time;
    attention[ATTENTION_COST] = cost;
    return attention;
}

void make_report(const char* filepath, void* patients)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    fout << std::fixed << std::setprecision(2);
    print_title(fout);
    int width = LINE_WIDTH / COLUMNS;
    const char* headers[] = {"ID", "Nombre", "Edad", "Genero", "Visitas", "Total (S/)"};
    print_line(fout, '-');
    for (int i = 0; i < sizeof(headers) / sizeof(headers[0]); i++) print_text(fout, headers[i], width);
    fout << std::endl;
    print_line(fout, '-');
    void** aux_patients = static_cast<void **>(patients);
    for (int i = 0; aux_patients[i] != nullptr; i++) print_patient(fout, static_cast<void **>(aux_patients[i]));
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

void print_patient(std::ofstream& fout, void** patient)
{
    int attention_count = 0;
    void** attentions = static_cast<void **>(patient[ATTENTIONS]);
    for (int i = 0; attentions[i] != nullptr; i++) attention_count++;

    int width = LINE_WIDTH / COLUMNS;
    fout << std::setw(width) << *static_cast<int *>(patient[ID]);
    fout << std::setw(width) << static_cast<char *>(patient[NAME]);
    fout << std::setw(width) << *static_cast<int *>(patient[AGE]);
    fout << std::setw(width) << *static_cast<char *>(patient[GENRE]);
    fout << std::setw(width) << attention_count;
    fout << *static_cast<double *>(patient[TOTAL_COST]) << std::endl;
}
