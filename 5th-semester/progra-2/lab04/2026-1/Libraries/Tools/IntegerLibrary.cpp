//
// Created by zincronit on 10/1/26.
//

#include "IntegerLibrary.hpp"

void* read_integer(std::ifstream& fin)
{
    int* value = read_int(fin);
    if (fin.eof()) return nullptr;
    void** integers = new void *{};
    integers[0] = value;
    return integers;
}

int compare_integer(const void* a, const void* b)
{

    void* const * aux1 = static_cast<void * const*>(a);
    void* const * aux2 = static_cast<void * const*>(b);

    // Primero obtenemos el elemento original bidimensional (que es un void**)
    void** data1 = static_cast<void **>(aux1[0]);
    void** data2 = static_cast<void **>(aux2[0]);

    // Luego accedemos al índice 0 para obtener el int*
    int* integer1 = static_cast<int *>(data1[0]);
    int* integer2 = static_cast<int *>(data2[0]);
    return *integer1 - *integer2;
}


int validate_integer(void* a, void* b)
{
    void** aux1 = static_cast<void **>(a);
    void** aux2 = static_cast<void **>(b);

    int* integer1 = static_cast<int *>(aux1[0]);
    int* integer2 = static_cast<int *>(aux2[0]);
    return *integer1 - *integer2;
}

void print_integer(void* a, std::ofstream& fout)
{
    void** aux = static_cast<void **>(a);
    int* integer = static_cast<int *>(aux[0]);
    fout << *integer << std::endl;
}
