//
// Created by zincronit on 11/5/26.
//

#include "Classes/Company.hpp"

int main()
{
    class Company company;
    company.load_sales("../Files/Data/sales.csv");
    company.print_sales("../Files/Reports/report.txt");

    return 0;
}