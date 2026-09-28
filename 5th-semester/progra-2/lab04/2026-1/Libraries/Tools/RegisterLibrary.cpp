//
// Created by zincronit on 9/27/26.
//

#include "RegisterLibrary.hpp"

void* read_attention(std::ifstream& fin)
{
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

int compare_date(const void* attention1, const void* attention2)
{
    void* const* aux1 = static_cast<void * const*>(attention1);
    void* const* aux2 = static_cast<void * const*>(attention2);

    int* date1 = static_cast<int *>(aux1[DATE]);
    int* date2 = static_cast<int *>(aux2[DATE]);
    return *date1 - *date2;
}
