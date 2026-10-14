//
// Created by zincronit on 10/9/26.
//


#include "Utils/Functions.hpp"

int main()
{
    struct Queue queue1, queue2;
    initQueue(queue1);
    initQueue(queue2);
    int array[] = {7, 6, 5, 4, 1, 2, 3};
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++)
        enqueue(queue1, array[i]);

    has_insert_sort(queue1, queue2)
        ? std::cout << "si se puede ordenar\n"
        : std::cout << "no se puede ordenar\n";


    return 0;
}
