//
// Created by zincronit on 9/10/26.
//

#include "Functions.hpp"

void loadInventory(const char* filepath, char**& warehouse, int**& inventory_data)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int product_code, stock, index, count = 0, capacity = 0, *data_capacity{}, *data_count{};
    char warehouse_code[TEXT_LENGTH]{};
    char* buffer_warehouse[MAX_WAREHOUSE]{};
    while (true)
    {
        // 1,ALM02,1409
        product_code = read_int(fin);
        if (fin.eof()) break;
        fin.getline(warehouse_code, TEXT_LENGTH, ',');
        stock = read_int(fin);
        index = find_index(buffer_warehouse, warehouse_code, count);
        if (index == NOT_FOUND)
        {
            if (count >= capacity - 1)
                append_warehouse_capacity(
                    inventory_data,
                    capacity,
                    count,
                    data_capacity,
                    data_count
                );
            buffer_warehouse[count] = allocate_string(warehouse_code);
            index = count;
            ++count;
        }
        insert_inventory_data(
            inventory_data[index],
            data_capacity[index],
            data_count[index],
            product_code,
            stock
        );
    }
    warehouse = new char*[count + 1]{};
    for (int i = 0; i < count; i++)
    {
        warehouse[i] = buffer_warehouse[i];
    }
    delete[] data_capacity;
    delete[] data_count;
    fin.close();
}

int find_index(char** warehouse,const char* warehouse_code,  int count)
{
    for (int i = 0; i < count; i++)
        if (std::strcmp(warehouse[i], warehouse_code) == 0) return i;
    return NOT_FOUND;
}

void append_warehouse_capacity(
    int**& inventory_data,
    int& capacity,
    int count,
    int*& data_capacity,
    int*& data_count)
{
    capacity += INCREASE;
    int** aux_int = new int *[capacity]{};
    int* aux_count = new int[capacity]{};
    int* aux_capacity = new int[capacity]{};
    if (capacity == INCREASE)
    {
        inventory_data = aux_int;
        data_capacity = aux_capacity;
        data_count = aux_count;
        return;
    }
    for (int i = 0; i < count; i++)
    {
        aux_int[i] = inventory_data[i];
        aux_capacity[i] = data_capacity[i];
        aux_count[i] = data_count[i];
    }
    delete[] inventory_data;
    delete[] data_capacity;
    delete[] data_count;
    inventory_data = aux_int;
    data_capacity = aux_capacity;
    data_count = aux_count;
}

void insert_inventory_data(int*& data, int& capacity, int& count, int code, int stock)
{
    if (count >= capacity - 1)
    {
        capacity += INCREASE;
        int* aux = new int[capacity]{};
        if (capacity == INCREASE) data = aux;
        else
        {
            for (int i = 0; i < count; i++) aux[i] = data[i];
            delete[] data;
            data = aux;
        }
    }
    data[count] = code;
    data[count + 1] = stock;
    count += 2;
}
