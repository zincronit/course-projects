//
// Created by zincronit on 9/4/26.
//

#include "Functions.hpp"

#include <algorithm>

void load_information(const char* filepath, int*& dates, char****& text_data, int***& int_data, double***& double_data)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    // 6/04/2024,864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
    int date, admision_time, discharge_time, systolic_presure, diastolic_presure;
    int *attention_capacity, *attention_count;
    double temperature;
    char patient_id[TEXT_LENGTH], name[TEXT_LENGTH], speciality[TEXT_LENGTH];
    int date_count = 0, date_capacity = 0;
    while (true)
    {
        date = read_date(fin);
        if (fin.eof()) break;
        fin.getline(patient_id, TEXT_LENGTH, ',');
        fin.getline(name, TEXT_LENGTH, ',');
        admision_time = read_time(fin);
        temperature = read_double(fin);
        systolic_presure = read_int(fin);
        diastolic_presure = read_int(fin);
        discharge_time = read_time(fin);
        fin.getline(speciality, TEXT_LENGTH, '\n');
        int index = find_index(dates, date, date_count);
        if (index == NOT_FOUND)
        {
            if (date_count >= date_capacity - 1)
                append_date_capacity(
                    dates,
                    text_data,
                    int_data,
                    double_data,
                    date_capacity,
                    date_count,
                    attention_capacity,
                    attention_count
                );
            index = insert_new_date(
                dates,
                text_data,
                int_data,
                double_data,
                date_count,
                date,
                attention_capacity,
                attention_count
            );
        }
        append_attention(
            text_data[index],
            int_data[index],
            double_data[index],
            attention_capacity[index],
            attention_count[index],
            admision_time,
            discharge_time,
            systolic_presure,
            diastolic_presure,
            temperature,
            patient_id,
            name,
            speciality);
    }
    shrink_date_capacity(dates, text_data, int_data, double_data, date_count + 1, attention_count);
    fin.close();
}

int find_index(const int* dates, int date, int date_count)
{
    for (int i = 0; i < date_count; i++)
        if (dates[i] == date) return i;
    return NOT_FOUND;
}

void append_date_capacity(
    int*& dates,
    char****& text_data,
    int***& int_data,
    double***& double_data,
    int& capacity,
    int& count,
    int*& attention_capacity,
    int*& attention_count)
{
    capacity += INCREASE;
    if (capacity == INCREASE)
    {
        dates = new int[capacity]{};
        text_data = new char ***[capacity]{};
        int_data = new int **[capacity]{};
        double_data = new double **[capacity]{};
        attention_capacity = new int[capacity]{};
        attention_count = new int[capacity]{};
        return;
    }
    change_pointer(
        dates,
        text_data,
        int_data,
        double_data,
        capacity,
        count,
        attention_capacity,
        attention_count
    );
}

void change_pointer(
    int*& dates,
    char****& text_data,
    int***& int_data,
    double***& double_data,
    int capacity,
    int count,
    int*& attention_capacity,
    int*& attention_count)
{
    int *aux_date = new int[capacity]{}, *aux_count = new int[capacity]{}, *aux_capacity = new int[capacity]{};
    char**** aux_char = new char ***[capacity]{};
    int*** aux_int = new int **[capacity]{};
    double*** aux_double = new double **[capacity]{};
    for (int i = 0; i < count; i++)
    {
        aux_date[i] = dates[i];
        aux_char[i] = text_data[i];
        aux_int[i] = int_data[i];
        aux_double[i] = double_data[i];
        aux_capacity[i] = attention_capacity[i];
        aux_count[i] = attention_count[i];
    }
    delete[] dates;
    delete[] text_data;
    delete[] int_data;
    delete[] double_data;
    delete[] attention_capacity;
    delete[] attention_count;
    dates = aux_date;
    text_data = aux_char;
    int_data = aux_int;
    double_data = aux_double;
    attention_capacity = aux_capacity;
    attention_count = aux_count;
}

int insert_new_date(
    int* dates,
    char**** text_data,
    int*** int_data,
    double*** double_data,
    int& count,
    int date,
    int* attention_capacity,
    int* attention_count)
{
    int i = count - 1;
    while (i >= 0 and dates[i] > date)
    {
        dates[i + 1] = dates[i];
        text_data[i + 1] = text_data[i];
        int_data[i + 1] = int_data[i];
        double_data[i + 1] = double_data[i];
        attention_capacity[i + 1] = attention_capacity[i];
        attention_count[i + 1] = attention_count[i];
        --i;
    }
    dates[i + 1] = date;
    attention_capacity[i + 1] = 0;
    attention_count[i + 1] = 0;
    ++count;
    return i + 1;
}

void append_attention(
    char***& attentions,
    int**& int_data,
    double**& double_data,
    int& capacity,
    int& count,
    int admision_time,
    int discharge_time,
    int systolic_presure,
    int diastolic_presure,
    double temperature,
    char* id,
    char* name,
    char* speciality)
{
    if (count >= capacity - 1)
    {
        append_attention_capacity(attentions, int_data, double_data, capacity, count);
    }
    char** aux_char = new char *[3]{};
    int* aux_int = new int[5]{};
    double* aux_double = new double[2]{};
    aux_char[0] = allocate_string(id);
    aux_char[1] = allocate_string(name);
    aux_char[2] = allocate_string(speciality);
    aux_int[0] = admision_time;
    aux_int[1] = discharge_time;
    aux_int[2] = systolic_presure;
    aux_int[3] = diastolic_presure;
    aux_double[0] = temperature;

    attentions[count] = aux_char;
    int_data[count] = aux_int;
    double_data[count] = aux_double;
    ++count;
}

void append_attention_capacity(char***& attentions, int**& int_data, double**& double_data, int& capacity, int count)
{
    capacity += INCREASE;
    if (capacity == INCREASE)
    {
        attentions = new char **[capacity]{};
        int_data = new int *[capacity]{};
        double_data = new double *[capacity]{};
        return;
    }
    char*** aux_char = new char **[capacity]{};
    int** aux_int = new int *[capacity]{};
    double** aux_double = new double *[capacity]{};
    for (int i = 0; i < count; i++)
    {
        aux_char[i] = attentions[i];
        aux_int[i] = int_data[i];
        aux_double[i] = double_data[i];
    }
    delete[] attentions;
    delete[] int_data;
    delete[] double_data;
    attentions = aux_char;
    int_data = aux_int;
    double_data = aux_double;
}

void shrink_date_capacity(int*& dates,
                          char****& text_data,
                          int***& int_data,
                          double***& double_data,
                          int count,
                          const int* attention_count)
{
    int* aux_dates = new int[count + 1]{};
    char**** aux_text = new char ***[count + 1]{};
    int*** aux_int = new int **[count + 1]{};
    double*** aux_double = new double **[count + 1]{};
    for (int i = 0; i < count; i++)
    {
        aux_dates[i] = dates[i];
        // Recortamos el subarreglo de la fecha actual
        shrink_single_date_attentions(text_data[i], int_data[i], double_data[i], attention_count[i]);
        aux_text[i] = text_data[i];
        aux_int[i] = int_data[i];
        aux_double[i] = double_data[i];
    }
    delete[] dates;
    delete[] text_data;
    delete[] int_data;
    delete[] double_data;
    dates = aux_dates;
    text_data = aux_text;
    int_data = aux_int;
    double_data = aux_double;
}

void shrink_single_date_attentions(char***& text_data, int**& int_data, double**& double_data, int attention_count)
{
    char*** aux_attentions = new char **[attention_count + 1]{};
    int** aux_int = new int *[attention_count + 1]{};
    double** aux_double = new double *[attention_count + 1]{};

    for (int j = 0; j < attention_count; j++)
    {
        aux_attentions[j] = text_data[j];
        aux_int[j] = int_data[j];
        aux_double[j] = double_data[j];
    }

    delete[] text_data;
    delete[] int_data;
    delete[] double_data;

    text_data = aux_attentions;
    int_data = aux_int;
    double_data = aux_double;
}

void attention_report(const char* filepath, int* dates, char**** text_data, int*** int_data, double*** double_data)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    print_title(fout);
    for (int i = 0; text_data[i] != nullptr; i++)
    {
        fout << "FECHA:  " << dates[i] << std::endl;
        fout << "REGISTRO DE ATENCIONES: \n";
        print_line(fout, LINE_WIDTH, '-');
        print_header(fout);
        print_information(fout, text_data[i], int_data[i], double_data[i]);
        print_line(fout, LINE_WIDTH);
    }
    fout.close();
}

void print_title(std::ofstream& fout)
{
    char title[TEXT_LENGTH] = "CLINICA DE URGENCIAS POR2_SALUD\n";
    char subtitle[TEXT_LENGTH] = "REGISTRO DE ATENCIONES\n";
    print_text(fout, title, (std::strlen(title) + LINE_WIDTH) / 2, true);
    print_text(fout, subtitle, (std::strlen(subtitle) + LINE_WIDTH) / 2, true);
    print_line(fout, LINE_WIDTH);
}

void print_header(std::ofstream& fout)
{
    int width = LINE_WIDTH / COLUMNS;
    print_text(fout, "DURACION DE", width * 5, true);
    fout << "  COSTO DE LA ATENCION\n";
    print_text(fout, "ID", width);
    print_text(fout, "NOMBRE", width);
    print_text(fout, "INGRESO", width);
    print_text(fout, "ALTA", width);
    print_text(fout, "LA ATENCION", width);
    print_text(fout, "ATENCION", width);
    print_text(fout, "TEMPERATURA", width);
    print_text(fout, "PRESION ARTERIAL", width);
    print_text(fout, "ESPECIALIDAD", width);
    fout << std::endl;
}

void print_information(std::ofstream& fout, char*** text_data, int** int_data, double** double_data)
{
    fout << std::fixed << std::setprecision(2);
    int width = LINE_WIDTH / COLUMNS;
    for (int i = 0; double_data[i] != nullptr; i++)
    {
        char** aux_char = text_data[i];
        int* aux_int = int_data[i];
        double* aux_double = double_data[i];
        print_text(fout, aux_char[0], width);
        print_text(fout, aux_char[1], width);
        print_time(fout, aux_int[0], width);
        print_time(fout, aux_int[1], width);
        print_time(fout, aux_int[1], width);
        fout << std::setw(width) << aux_double[0] << std::setw(width) << aux_double[0];
        fout << aux_int[2] << '/' << aux_int[3];
        print_text(fout, aux_char[2], width, true);
        fout << std::endl;
    }
}

void print_time(std::ofstream& fout, int time, int width)
{
    fout << std::right << std::setfill('0') << std::setw(2) << time / 3600 << ':';
    fout << std::setw(2) << time % 3600 / 60 << ':';
    fout << std::setw(2) << time % 60 << std::setfill(' ') << std::left;
    print_spaces(fout, 9, width);
}
