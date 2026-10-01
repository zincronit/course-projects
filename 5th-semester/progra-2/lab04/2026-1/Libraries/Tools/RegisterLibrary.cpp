//
// Created by zincronit on 9/27/26.
//

#include "RegisterLibrary.hpp"

void* read_attention(std::ifstream& fin)
{
    // 101,7/4/2025,CONTROL,11:00,PROGRAMADA,Luna,Labrador,Negro,CANINO
    int* id = read_int(fin);
    if (fin.eof()) return nullptr;
    int* date = read_date(fin);
    char* reason = read_string(fin);
    int* time = read_time(fin);
    char* status = read_string(fin);
    char* name = read_string(fin);
    char* breed = read_string(fin);
    char* color = read_string(fin);
    char* species = read_string(fin, '\n');

    void** attention = new void *[9]{};
    attention[ID] = id;
    attention[DATE] = date;
    attention[REASON] = reason;
    attention[TIME] = time;
    attention[STATUS] = status;
    attention[NAME] = name;
    attention[BREED] = breed;
    attention[COLOR] = color;
    attention[SPECIES] = species;
    return attention;
}

int compare_data(const void* attention1, const void* attention2)
{
    void* const* aux1 = static_cast<void * const*>(attention1);
    void* const* aux2 = static_cast<void * const*>(attention2);

    void** data1 = static_cast<void **>(aux1[0]);
    void** data2 = static_cast<void **>(aux2[0]);

    int* date1 = static_cast<int *>(data1[DATE]);
    int* date2 = static_cast<int *>(data2[DATE]);

    if (*date1 != *date2) return *date1 - *date2 ;

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
    return *date1 - *date2;
}

void print_attention(void* attention, std::ofstream& fout)
{
    void** aux_attention = static_cast<void **>(attention);
    int width = LINE_WIDTH / COLUMNS;
    fout<<std::left;
    fout << std::setw(width) << *static_cast<int* >(aux_attention[DATE]);
    fout << std::setw(width) << *static_cast<int* >(aux_attention[TIME]);
    fout << std::setw(width) << *static_cast<int* >(aux_attention[ID]);
    print_text(fout, static_cast<char* >(aux_attention[NAME]), width);
    print_text(fout, static_cast<char* >(aux_attention[BREED]), width);
    print_text(fout, static_cast<char* >(aux_attention[COLOR]), width);
    fout << std::endl;
}
