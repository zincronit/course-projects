//
// Created by zincronit on 10/29/26.
//
#include "Classes/Veterinary.hpp"

int main()
{
    class Veterinary veterinary;
    veterinary.load_appointments("../Files/Data/attentions.csv");
    veterinary.show_appointments("../Files/Reports/report.txt");
    return 0;
}
