//
// Created by zincronit on 11/16/26.
//

#include "Classes/PackageManager.hpp"
int main()
{
    PackageManager manager;
    manager.load_packages("../Files/Data/packages.csv","../Files/Data/products.csv");
    manager.process_dispatch("../Files/Reports/dispatch.txt", "../Files/Reports/pending.txt" );
    return 0;
}