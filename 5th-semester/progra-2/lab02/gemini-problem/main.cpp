//
// Created by zincronit on 9/10/26.
//

#include "Libraries/Utils/Functions.hpp"

int main()
{
    char** warehouses;
    int** inventory_data;
    loadInventory("../Files/Data/inventario.csv", warehouses, inventory_data);

    std::cout << inventory_data[1][5] << std::endl;
    return 0;
}
