//
// Created by zincronit on 9/24/26.
//

#include "Utils/Functions.hpp"

int main()
{
    struct List list;
    insert_back(list, {7, "Martinez", "Delantero"});
    insert_back(list, {1, "Ramirez", "Portero"});
    insert_back(list, {5, "Perez", "Defensa"});
    insert_back(list, {8, "Torres", "Mediocampo"});
    insert_back(list, {9, "Lopez", "Delantero"});
    insert_back(list, {3, "Gomez", "Defensa"});
    print_list(list);


    return 0;
}
