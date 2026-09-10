//
//Created by zincronit on 9/6/26.
//

#include <iostream>
#include <cmath>

#define ESTADOS 4

struct Diente
{
    int ubicaion;
    int tipo;
    int cant_caries;
};

struct Tipo
{
    int duracion;
    int ganancia;
};

void llenar_gen(int* gen, int numero, int cant_dientes);

void obtener_el_mejor(
    int* gen,
    int numero,
    int& best_gen,
    int& max_ganancia,
    struct Tipo* tipos,
    struct Diente* dientes,
    int* duracion_citas,
    int cant_dientes);

int main()
{
    struct Diente dientes[] = {
        {1, 1, 3},
        {2, 1, 1},
        {3, 2, 0},
        {4, 3, 1},
        {5, 3, 2},
        {6, 4, 1},
        {7, 4, 2},
        {8, 4, 3}
    };
    struct Tipo tipos[] = {
        {5, 20},
        {7, 30},
        {10, 35},
        {12, 42}
    };
    int duracion_citas[] = {60, 45, 50};
    int cant_dientes = sizeof(dientes) / sizeof(dientes[0]);
    int gen[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int combinaciones = (int) pow(ESTADOS, cant_dientes);
    int max_ganancia = 0;
    int best_gen = 0;
    for (int i = 0; i < combinaciones; i++)
    {
        llenar_gen(gen, i, cant_dientes);
        obtener_el_mejor(
            gen,
            i,
            best_gen,
            max_ganancia,
            tipos,
            dientes,
            duracion_citas,
            cant_dientes);
    }
    for (int i = 0; i < cant_dientes; i++) gen[i] = 0;
    llenar_gen(gen, best_gen, cant_dientes);
    for (int i = 0; i < cant_dientes; i++)
    {
        if (gen[i] == 1) std::cout << "Cita: 1 Diente " << i+1 << std::endl;
    }
    for (int i = 0; i < cant_dientes; i++)
    {
        if (gen[i] == 2) std::cout << "Cita: 2 Diente " << i+1 << std::endl;
    }
    for (int i = 0; i < cant_dientes; i++)
    {
        if (gen[i] == 3) std::cout << "Cita: 3 Diente " << i+1 << std::endl;
    }
    std::cout << "La ganancia maxima es "<< max_ganancia << std::endl;

    return 0;
}

void llenar_gen(int* gen, int numero, int cant_dientes)
{
    for (int i = 0; i < cant_dientes; i++) gen[i] = 0;
    int j = 0;
    while (numero > 0)
    {
        gen[j] = numero % ESTADOS;
        numero = numero / ESTADOS;
        ++j;
    }
}

void obtener_el_mejor(
    int* gen,
    int numero,
    int& best_gen,
    int& max_ganancia,
    struct Tipo* tipos,
    struct Diente* dientes,
    int* duracion_citas,
    int cant_dientes)
{
    int ganancia = 0;
    int t1 = 0, t2 = 0, t3 = 0;
    for (int i = 0; i < cant_dientes; i++)
    {
        int index_tipo = dientes[i].tipo - 1;
        int duracion = tipos[index_tipo].duracion * dientes[i].cant_caries;
        int ganancia_diente = dientes[i].cant_caries * tipos[index_tipo].ganancia;
        if (gen[i] == 1)
        {
            t1 += duracion;
            ganancia += ganancia_diente;
        }
        if (gen[i] == 2)
        {
            t2 += duracion;
            ganancia += ganancia_diente;
        }
        if (gen[i] == 3)
        {
            t3 += duracion;
            ganancia += ganancia_diente;
        }
    }
    if (t1 <= duracion_citas[0] and t2 <= duracion_citas[1] and t3 <= duracion_citas[2] and max_ganancia < ganancia)
    {
        max_ganancia = ganancia;
        best_gen = numero;
    }
}
