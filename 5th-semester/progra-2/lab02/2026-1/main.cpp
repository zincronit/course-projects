//
// Created by zincronit on 9/4/26.
//

#include "Libraries/Utils/Functions.hpp"

void sum(int& a ){a++;}

int main()
{
    std::cout << std::strlen("hello world") << std::endl;

    int* dates ;
    char**** text_data;
    int*** int_data;
    double*** double_data;

    for (int i = 0 ; i < 10 ; i++)
    {
        static int a = 0;
        sum(a);
        std::cout << ++a << std::endl;

    }

    return 0;
}