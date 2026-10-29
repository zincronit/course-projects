//
// Created by zincronit on 10/2/26.
//

#include "Classes/Veterinary.hpp"
int main()
{
    class Veterinary veterinary;
    veterinary <= "../Files/Data/mascotas.csv";
    veterinary <<= "../Files/Data/vacunasAplicadas.csv";
    return 0;
}