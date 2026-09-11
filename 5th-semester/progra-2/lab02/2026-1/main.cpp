//
// Created by zincronit on 9/4/26.
//

#include "Libraries/Utils/Functions.hpp"


int main()
{
    int* dates;
    char**** text_data;
    int*** int_data;
    double*** double_data;

    load_information(
        "../Files/Data/ER_Final_Dataset_For_Students_Programacion_2.csv",
        dates,
        text_data,
        int_data,
        double_data
    );

    // for (int i = 0 ; text_data[i] != nullptr ; i++)
    // {
    //     std::cout << dates[i] << std::endl;
    // }
    std::cout << text_data[45][2][1] << std::endl;
    // std::cout << dates[0] << std::endl;
    // complete_information(
    //     dates,
    //     text_data,
    //     int_data,
    //     double_data
    // );
    attention_report(
        "../Files/Reports/report.txt",
        dates,
        text_data,
        int_data,
        double_data
    );


    return 0;
}
