//
// Created by zincronit on 9/27/26.
//

#include "GenericLibrary.hpp"


void array_process(void* array, void* (*read_data)(std::ifstream&), const char* filepath)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int count = 0;
    void *auxiliar, **aux_array = static_cast<void **>(array);
    while (true)
    {
        auxiliar = read_data(fin);
        if (fin.eof()) break;
        aux_array[count] = auxiliar;
        ++count;
    }
    fin.close();
}

void build_list(void* array, void*& list, int (*compare)(const void*, const void*))
{
    void** aux_array = static_cast<void **>(array);
    int size = 0;
    for (int i = 0; aux_array[i] != nullptr; ++i) size++;
    qsort(array, size, sizeof(void *), compare);
    list = initialize_list();
    for (int i = 0; aux_array[i] != nullptr; ++i)
        insert_back(list, aux_array[i]);

}

void fusion_list(void*& list1, void* list2, int (*function)(void*, void*))
{
    void** aux_list1 = static_cast<void **>(list1);
    void** aux_list2 = static_cast<void **>(list2);
    void** tail1 = get_last_node(list1);
    void** tail2 = get_last_node(list2);
    if (is_empty_list(list1) and is_empty_list(list2)) return;
    // if ()
}

void print_list(void* list, void (*print_data)(void*, std::ofstream&), const char* filepath)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    void** aux_list = static_cast<void **>(list);
    void** current = static_cast<void **>(aux_list[HEAD]);
    while (current != nullptr)
    {
        print_data(*current, fout);
        current[NEXT] = static_cast<void**>(current[NEXT]);
    }
    fout.close();
}
