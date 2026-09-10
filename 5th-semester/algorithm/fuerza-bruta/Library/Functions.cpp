//
// Created by zincronit on 9/5/26.
//

#include "Functions.hpp"

void bagg_problem()
{
    int pesos[] = {15, 5, 19, 4, 6};
    int size = sizeof(pesos) / sizeof(pesos[0]);
    int usado[] = {0, 0, 0, 0, 0};
    int bag_number = 1;
    int weight = 39;
    int best_gen = 0;
    int best_weight = 0;
    for (int i = 0; i < pow(2, size) - 1; i++)
    {
        llenar_arreglo(i, usado, size);
        get_the_best(pesos, usado, i, size, best_gen, best_weight, weight);
    }
    std::cout << size << std::endl;
    std::cout << "mejor gen: " << best_gen << std::endl;
    std::cout << "peso:" << best_weight << std::endl;
    for (int i = 0; i < size; i++)
    {
        llenar_arreglo(best_gen, usado, size);
        if (usado[i] ) std::cout << pesos[i] << std::endl;
    }
}

void llenar_arreglo(int number, int* usado, int size)
{
    for (int i = 0; i < size; i++) usado[i] = 0;
    int i = 0;
    while (number > 0)
    {
        usado[i] = number % 2;
        number = number / 2;
        i++;
    }
}

void get_the_best(int* pesos, int* usado, int gen, int size, int& best_gen, int& best_weight, int bag_weight)
{
    int weight = 0;
    for (int i = 0; i < size; i++)
    {
        weight += pesos[i] * usado[i];
        if (weight > best_weight and weight <= bag_weight)
        {
            best_weight = weight;
            best_gen = gen;
        }
    }
}
