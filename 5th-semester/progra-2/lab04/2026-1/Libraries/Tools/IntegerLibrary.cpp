//
// Created by zincronit on 10/1/26.
//

#include "IntegerLibrary.hpp"

void* read_integer(std::ifstream& fin)
{
    // int* integer = read_int(fin);
    // if (fin.eof()) return nullptr;
    // void** aux = new void *{};
    // aux[0] = integer;
    // void* aux = new int{*integer};
    // return integer;
    return read_int(fin);
}

int compare_integer(const void* a, const void* b)
{
    const void* const* aux1 = static_cast<const void * const*>(a);
    const void* const* aux2 = static_cast<const void * const*>(b);

    // void** data1 = static_cast<void **>(aux1[0]);
    // void** data2 = static_cast<void **>(aux2[0]);
    // void* data1 = *aux1;
    // void* data2 = *aux2;

    // int* integer1 = static_cast<int *>(data1[0]);
    // int* integer2 = static_cast<int *>(data2[0]);
    const int* integer1 = static_cast<const int *>(*aux1);
    const int* integer2 = static_cast<const int *>(*aux2);
    return *integer1 - *integer2;
}

int validate_integer(void* data1, void* data2)
{
    // void** aux1 = static_cast<void **>(data1);
    // void** aux2 = static_cast<void **>(data2);
    // int* integer1 = static_cast<int *>(aux1[0]);
    // int* integer2 = static_cast<int *>(aux2[0]);
    int* integer1 = static_cast<int *>(data1);
    int* integer2 = static_cast<int *>(data2);

    return *integer1 - *integer2;
}

void print_integer(std::ofstream& fout, void* data)
{
    // void** aux = static_cast<void **>(data);
    // int* integer = static_cast<int *>(aux[0]);
    // fout << *integer << std::endl;

    int* integer = static_cast<int *>(data);
    fout << *integer<< std::endl;
}
