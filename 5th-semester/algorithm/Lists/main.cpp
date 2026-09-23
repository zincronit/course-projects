//
// Created by zincronit on 9/20/26.
//


#include "Utils/Functions.hpp"

int main ()
{
    struct List list;
    initialize_list(list);
    for (int i=0 ; i < 20; i++) insert_back(list, i);
    print_list(list);
    size_t hello = 10;
    std::cout << hello << std::endl;
    return 0;
}
