//
// Created by zincronit on 9/4/26.
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

void print_line(std::ofstream& fout, int width, char character)
{
    for (int i = 0; i < width; i++) fout.put(character);
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
    return yy * 10000 + mm * 100 + dd;
}

int read_code(std::ifstream& fin)
{
    int x, y, z;
    char c;
    fin >> x >> c >> y >> c >> z;
    return x * 1000000 + y * 10000 + z;
}

int read_time(std::ifstream& fin)
{
    int hh, mm, ss;
    char c;
    fin >> hh >> c >> mm >> c >> ss;
    return hh * 3600 + mm * 60 + ss;
}

void load_information(const char* filepath,
                      int* & dates,
                      char**** & text_data,
                      int*** & int_data,
                      double*** & double_data)
{
    std::ifstream fin(filepath);
    open_input_file(fin, filepath);
    int date_count = 0, attention_count = 0, date;
    while (true)
    {
        append_date_capacity(
            dates,
            text_data,
            int_data,
            double_data,
            date_count
        );
        // 6/04/2024,864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
        date = read_date(fin);
        if (fin.eof()) break;
        int index = find_date_index(date, dates);
        if (index == NOT_FOUND)
        {
            insert_new_attention_date(
                fin,
                date,
                dates,
                text_data,
                int_data,
                double_data,
                date_count,
                attention_count
            );
        } else {}
    }
}

void append_date_capacity(int* & dates,
                          char**** & text_data,
                          int*** & int_data,
                          double*** & double_data,
                          int count)
{
    static int size = 0;
    if (size == 0)
    {
        size += INCREASE;
        dates = new int[size]{};
        text_data = new char ***[size]{};
        int_data = new int **[size]{};
        double_data = new double **[size]{};
    }
    if (size == count)
        change_pointer(
            dates,
            text_data,
            int_data,
            double_data,
            size
        );
}

void change_pointer(int* & dates,
                    char**** & text_data,
                    int*** & int_data,
                    double*** & double_data,
                    int& size)
{
    size += INCREASE;
    int* a = new int[size]{};
    char**** b = new char ***[size]{};
    int*** c = new int **[size]{};
    double*** d = new double **[size]{};
    for (int i = 0; dates[i] != 0; i++)
    {
        dates[i] = a[i];
        text_data[i] = b[i];
        int_data[i] = c[i];
        double_data[i] = d[i];
    }
    delete[] dates;
    delete[] text_data;
    delete[] int_data;
    delete[] double_data;
    dates = a;
    text_data = b;
    int_data = c;
    double_data = d;
}

int find_date_index(int date, int* dates)
{
    for (int i = 0; dates[i] != 0; i++)
    {
        if (dates[i] == date) return i;
    }
    return NOT_FOUND;
}

void insert_new_attenton_date(std::ifstream& fin,
                              int date,
                              int* dates,
                              char**** text_data,
                              int*** int_data,
                              double*** double_data,
                              int& date_count,
                              int& attention_count)
{
    int i = date_count - 1;
    while (i >= 0 and dates[i] > date)
    {
        dates[i + 1] = dates[i];
        swap_char_pointer(text_data[i + 1], text_data[i]);
        swap_int_pointer(int_data[i + 1], int_data[i]);
        swap_double_pointer(double_data[i + 1], double_data[i]);
        i--;
    }
    dates[i] = date;
    read_attention(fin, text_data[i], int_data[i], double_data[i]);
    date_count++;
}

void swap_char_pointer(char***& a, char***& b)
{
    char*** temp = a;
    a = b;
    b = temp;
}

void swap_int_pointer(int**& a, int**& b)
{
    int** temp = a;
    a = b;
    b = temp;
}

void swap_double_pointer(double**& a, double**& b)
{
    double** temp = a;
    a = b;
    b = temp;
}

void read_attention(std::ifstream& fin,
                    char***  text_data,
                    int** int_data,
                    double** double_data)
{
    // 864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
    *int_data[1] = 50;
    // hay que aprender el metodo de erasmo para la dereferencia
}

void append_new_attention_to_date(std::ifstream&,
                                  char**** text_data,
                                  int*** int_data,
                                  double*** double_data,
                                  int& attentiton_count,
                                  int index)
{
    return;
}
