//
// Created by zincronit on 9/24/26.
//

#include "Utils/Functions.hpp"

int main()
{
    struct List list;
    initialize_list(list);

    insert_back(list , {17, "Messala", "Rojo"});
    insert_back(list , {4, "Ben-Hur", "Azul"});
    insert_back(list , {12, "Artax", "Verde"});
    insert_back(list , {7, "Drusus", "Negro"});
    insert_back(list , {8, "Samin", "Negro"});
    insert_back(list , {14, "Chambe", "Negro"});
    print_list(list);
    reorder_list(list);
    print_list(list);
    return 0;
}