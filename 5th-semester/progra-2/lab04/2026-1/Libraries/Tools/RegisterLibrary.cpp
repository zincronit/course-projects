//
// Created by zincronit on 9/27/26.
//


#include "RegisterLibrary.hpp"

void* read_register(std::ifstream& fin)
{
    // 101,7/4/2025,CONTROL,11:00,PROGRAMADA,Luna,Labrador,Negro,CANINO
    int* id = read_int(fin);
    if (fin.eof()) return nullptr;
    int* date = read_date(fin);
    fin.ignore(100, ',');
    int* time = read_time(fin);
    fin.ignore(100, ',');
    char* name = read_string(fin);
    char* breed = read_string(fin);
    char* color = read_string(fin);
    fin.ignore(100, '\n');

    void** attention = new void *[6]{};
    attention[ID] = id;
    attention[DATE] = date;
    attention[TIME] = time;
    attention[NAME] = name;
    attention[BREED] = breed;
    attention[COLOR] = color;
    return attention;
}

int compare_data(const void* a, const void* b)
{
    void* const* aux1 = static_cast<void * const *>(a);
    void* const* aux2 = static_cast<void * const *>(b);

    void** data1 = static_cast<void **>(aux1[0]);
    void** data2 = static_cast<void **>(aux2[0]);

    int* date1 = static_cast<int *>(data1[DATE]);
    int* date2 = static_cast<int *>(data2[DATE]);
    if (*date1 != *date2) return *date1 - *date2;

    int* time1 = static_cast<int *>(data1[TIME]);
    int* time2 = static_cast<int *>(data2[TIME]);
    return *time1 - *time2;
}

int validate_data(void* data1, void* data2)
{
    void** aux1 = static_cast<void **>(data1);
    void** aux2 = static_cast<void **>(data2);

    int* date1 = static_cast<int *>(aux1[DATE]);
    int* date2 = static_cast<int *>(aux2[DATE]);
    if (*date1 != *date2) return *date1 - *date2;

    int* time1 = static_cast<int *>(aux1[TIME]);
    int* time2 = static_cast<int *>(aux2[TIME]);
    return *time1 - *time2;
}

void print_register(std::ofstream& fout, void* attention)
{
    void** aux_attention = static_cast<void **>(attention);
    int width = LINE_WIDTH / COLUMNS;
    print_date(fout, *static_cast<int *>(aux_attention[DATE]), width);
    print_time(fout, *static_cast<int *>(aux_attention[TIME]), width);
    fout << std::setw(width) << *static_cast<int *>(aux_attention[ID]);
    print_text(fout, static_cast<char *>(aux_attention[NAME]), width);
    print_text(fout, static_cast<char *>(aux_attention[BREED]), width);
    print_text(fout, static_cast<char *>(aux_attention[COLOR]), width);
    fout << std::endl;
}
