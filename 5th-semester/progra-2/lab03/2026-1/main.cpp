//
// Created by zincronit on 9/13/26.
//

#include "Libraries/Functions.hpp"

int main()
{
    void* patients;
    std::cout << ID ;
    load_patients("../Files/Data/pacientes.csv", patients);
    load_attentions("../Files/Data/visitas.csv", patients);
    make_report("../Files/Reports/system_report.txt", patients);
    return 0;
}