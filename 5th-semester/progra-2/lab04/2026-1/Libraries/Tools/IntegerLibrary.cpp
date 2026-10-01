//
// Created by zincronit on 10/1/26.
//

#include "IntegerLibrary.hpp"

void* read_integer(std::ifstream& fin)
{
    int* integer = read_int(fin);
    if (fin.eof()) return nullptr;
    void** aux = new void *{};
    aux[0] = integer;
    return aux;
}

int compare_integer(const void* a, const void* b)
{
    void* const* aux1 = static_cast<void * const*>(a);
    void* const* aux2 = static_cast<void * const*>(b);

    void** data1 = static_cast<void **>(aux1[0]);
    void** data2 = static_cast<void **>(aux2[0]);

    int* integer1 = static_cast<int *>(data1[0]);
    int* integer2 = static_cast<int *>(data2[0]);
    return *integer1 - *integer2;
}

int validate_integer(void* data1, void* data2)
{
    void** aux1 = static_cast<void **>(data1);
    void** aux2 = static_cast<void **>(data2);
    int* integer1 = static_cast<int *>(aux1[0]);
    int* integer2 = static_cast<int *>(aux2[0]);
    return *integer1 - *integer2;
}

void print_integer(std::ofstream& fout, void* data)
{
    void** aux = static_cast<void **>(data);
    int* integer = static_cast<int *>(aux[0]);
    fout << *integer << std::endl;
}
