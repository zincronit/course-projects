//
// Created by zincronit on 9/6/26.
//

#include <iostream>
#include <cmath>

#define ESTADOS 2

struct Control
{
    int costo;
    int beneficio;
    int falsos_negativos;
};

void llenar_gen(int*, int, int);
void encontrar_combinaciones(int* , int , int , int , struct Control*, int );

int main()
{
    struct Control controles[] = {
        {35000, 80, 1},
        {24000, 60, 3},
        {30000, 70, 2},
        {27000, 48, 1},
        {10000, 20, 1},
        {7000, 35, 2},
        {6000, 10, 1},
        {40000, 40, 3},
    };
    int size = sizeof(controles) / sizeof(controles[0]);
    int combinaciones = (int) pow(ESTADOS, size);
    int gen[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int P = 70000, B = 150, F = 5;
    for (int i = 0; i < combinaciones; i++)
    {
        llenar_gen(gen, i, size);
        encontrar_combinaciones(gen, P, B, F, controles, size);
    }

    return 0;
}

void llenar_gen(int* gen, int num, int size)
{
    for (int i = 0; i < size; i++) gen[i] = 0;
    int j = 0;
    while (num > 0)
    {
        gen[j] = num % ESTADOS;
        num = num / ESTADOS;
        ++j;
    }
}

void encontrar_combinaciones(int* gen, int P, int B, int F, struct Control* controles, int size)
{
    int costos = 0;
    int beneficio = 0;
    int falsos_negativos = 0;
    for (int i = 0; i < size; i++)
    {
        if (gen [i] == 0) continue;
        costos += controles[i].costo;
        beneficio += controles[i].beneficio;
        falsos_negativos += controles[i].falsos_negativos;
    }
    if ( costos <= P and beneficio >= B and falsos_negativos <= F)
    {
        std::cout << "Recursos: {" ;
        for (int i = 0; i < size; i++) if (gen[i] != 0) std::cout << i + 1 << ',';
        std::cout << "}, Costo total: "<< costos ;
        std::cout << ", Beneficio: "<< beneficio <<", Falsos negativos:"<< falsos_negativos<< std::endl;
    }
}
