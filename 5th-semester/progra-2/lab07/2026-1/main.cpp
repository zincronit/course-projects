//
// Created by zincronit on 11/7/26.
//
#include "Classes/CareManager.hpp"
int main()
{
    class CareManager hospital;
    hospital.process_day("2026-01-01");
    hospital.generate_report("../Files/Reports/2026-01-01.txt");
    hospital.process_day("1992-01-23");
    hospital.generate_report("../Files/Reports/1992-01-23.txt");
    return 0;
}