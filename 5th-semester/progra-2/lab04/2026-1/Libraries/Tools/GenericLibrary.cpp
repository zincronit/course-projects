//
// Created by zincronit on 9/27/26.
//

#include "GenericLibrary.hpp"

#include <list>

void array_process(void* array, void* (*read_data)(std::ifstream&), const char* filepath)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    void *data, **aux_array = static_cast<void **>(array);
    int count = 0;
    while (true)
    {
        data = read_data(fin);
        if (fin.eof()) break;
        aux_array[count] = data;
        count++;
    }
    aux_array[count] = nullptr;
    fin.close();
}

void build_list(void* array, void*& list, int (*compare)(const void*, const void*))
{
    void** aux_array = static_cast<void **>(array);
    int size = 0;
    for (int i = 0; aux_array[i] != nullptr; i++) size++;
    qsort(array, size, sizeof(void *), compare);
    list = initialize_list();
    for (int i = 0; aux_array[i] != nullptr; i++)
        insert_back(list, aux_array[i]);
}

void* initialize_list()
{
    void** list = new void *[2]{};
    list[HEAD] = nullptr;
    list[SIZE] = new int{0};
    return list;
}

void insert_back(void*& list, void* data)
{
    void** aux_list = static_cast<void **>(list);
    void** new_node = new void *[2]{};
    new_node[DATA] = data;
    new_node[NEXT] = nullptr;
    void** current = get_last_node(list);
    current == nullptr ? aux_list[HEAD] = new_node : current[NEXT] = new_node;
    *static_cast<int *>(aux_list[SIZE]) += 1;
}

void print_list(void* list, void (*print_data)(std::ofstream&, void*), const char* filepath)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    void** aux_list = static_cast<void **>(list);
    void** current = static_cast<void **>(aux_list[HEAD]);
    while (current != nullptr)
    {
        print_data(fout, current[DATA]);
        current = static_cast<void **>(current[NEXT]);
    }
    fout.close();
}

void fusion_list(void*& list1, void* list2, int (*compare)(void*, void*))
{
    void** aux_list1 = static_cast<void **>(list1);
    void** aux_list2 = static_cast<void **>(list2);
    void** head = nullptr;
    void** tail = nullptr;
    while (aux_list1[HEAD] != nullptr and aux_list2[HEAD] != nullptr)
    {
        void** node1 = static_cast<void **>(aux_list1[HEAD]);
        void** node2 = static_cast<void **>(aux_list2[HEAD]);
        if (compare(node1[DATA], node2[DATA]) <= 0)
        {
            if (head == nullptr)
            {
                head = node1;
                tail = node1;
            } else
            {
                tail[NEXT] = node1;
                tail = node1;
            }
            aux_list1[HEAD] = node1[NEXT];
        } else
        {
            if (head == nullptr)
            {
                head = node2;
                tail = node2;
            } else
            {
                tail[NEXT] = node2;
                tail = node2;
            }
            aux_list2[HEAD] = node2[NEXT];
        }
    }
    if (aux_list1[HEAD] != nullptr)
    {
        if (head == nullptr) head = static_cast<void **>(aux_list1[HEAD]);
        else tail[NEXT] = aux_list1[HEAD];
    } else if (aux_list2[HEAD] != nullptr)
    {
        if (head == nullptr) head = static_cast<void **>(aux_list2[HEAD]);
        else tail[NEXT] = aux_list2[HEAD];
    }
    aux_list1[HEAD] = head;
    *static_cast<int *>(aux_list2[SIZE]) += *static_cast<int *>(aux_list2[SIZE]);
    delete static_cast<int *>(aux_list2[SIZE]);
    delete [] aux_list2;
}
