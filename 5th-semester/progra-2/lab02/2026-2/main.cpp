//
// Created by zincronit on 9/12/26.
//

#include "Libraries/Functions.hpp"

int main()
{
    char*** sales;
    char**** text_data;
    int*** int_data;
    load_sales("../Files/Data/Ventas.csv", sales);
    // std::cout << sales[4][3] << std::endl;
    print_report(
        "../Files/Reports/sales_report.txt",
        sales,
        text_data,
        int_data,
        false
    );

    load_sale_detail(
        "../Files/Data/DetalleVentas.csv",
        sales,
        text_data,
        int_data
    );

    print_report(
        "../Files/Reports/sales_report_width_details.txt",
        sales,
        text_data,
        int_data,
        true
    );

    complete_data_detail(
        "../Files/Data/Productos.csv",
        text_data,
        int_data
    );

    print_report(
        "../Files/Reports/final_report.txt",
        sales,
        text_data,
        int_data,
        true
    );

    // std::cout << text_data[5][1][3] << std::endl;

    return 0;
}
