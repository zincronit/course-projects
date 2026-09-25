//
// Created by zincronit on 9/24/26.
//

#include "Utils/Functions.hpp"

#include <cstdlib>
#include <ctime>


int main()
{
    struct List list1, list2, list3;

    initialize_list(list1);
    initialize_list(list2);
    initialize_list(list3);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number;
    for (int i = 0; i < 12; i++)
    {
        random_number = 1 + std::rand() % 24;
        insert_sorted(list1, {random_number});
    }
    for (int i = 0; i < 5; i++)
    {
        random_number = 1 + std::rand() % 24;
        insert_sorted(list2, {random_number});
    }
    for (int i = 0; i < 8; i++)
    {
        random_number = 1 + std::rand() % 24;
        insert_sorted(list3, {random_number});
    }
    print_list(list1);
    print_list(list2);
    print_list(list3);

    merge_list(list1 , list2);
    merge_list(list1 , list3);
    print_list(list1);
    std::cout << list1.size <<std::endl;
    invert_list(list1);
    print_list(list1);
    return 0;
}
