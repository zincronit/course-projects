//
// Created by zincronit on 9/27/26.
//

#include "Libraries/Tools/GenericLibrary.hpp"
#include "Libraries/Tools/IntegerLibrary.hpp"
#include "Libraries/Tools/RegisterLibrary.hpp"


int main()
{
    void *array1[MAX]{}, *array2[MAX]{};
    void *list1, *list2;

    array_process(array1, read_integer, "../Files/Data/numbers1.txt");
    build_list(array1, list1, compare_integer);

    array_process(array2, read_integer, "../Files/Data/numbers2.txt");
    build_list(array2, list2, compare_integer);

    fusion_list(list1, list2, validate_integer);
    print_list(list1, print_integer, "../Files/Reports/report1.txt");


    array_process(array1, read_attention, "../Files/Data/Atenciones1.csv");
    build_list(array1, list1, compare_data);
    array_process(array2, read_attention, "../Files/Data/Atenciones2.csv");
    build_list(array2, list2, compare_data);
    fusion_list(list1, list2, validate_data);
    print_list(list1, print_attention, "../Files/Reports/report2.txt");
    return 0;
}
