//
// Created by zincronit on 9/13/26.
//


#include "Libraries/Functions.hpp"


int main()
{
    void* patients;
    load_patients("../Files/Data/pacientes.csv", patients);
    load_attentions("../Files/Data/visitas.csv", patients);
    std::cout << ID << std::endl;
    make_report("../Files/Reports/report.txt", patients);
    return 0;
}