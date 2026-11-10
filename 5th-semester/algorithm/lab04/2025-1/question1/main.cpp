//
// Created by zincronit on 11/9/26.
//


#include <iostream>
#include <ostream>

int find_max_day(int* array, int left, int right)
{
    if (left > right) return -1;
    if (left == right) return left;
    int mid = (left + right) / 2;

    if (array[mid] >= array[mid + 1])
        return find_max_day(array, left, mid);
    return find_max_day(array, mid + 1, right);
}

int find_near_value(int* array, int left, int right, int value)
{
    if (left > right) return -1;
    int mid = (left + right) / 2;

    if (array[mid] >= value)
    {
        int number = find_near_value(array, left, mid - 1, value);
        return number == -1 ? mid : number;
    }
    return find_near_value(array, mid + 1, right, value);
}


int main()
{
    int ventas_original[] = {20, 50, 80, 120, 200, 150, 90};
    int ventas_nueva[] = {10, 20, 30, 80, 150, 220, 250, 256, 300};
    int size_sales = sizeof(ventas_original) / sizeof(ventas_original[0]);
    int size_new_sales = sizeof(ventas_nueva) / sizeof(ventas_nueva[0]);
    int max_day = find_max_day(ventas_original, 0, size_sales - 1) ;
    std::cout << max_day << "  " << ventas_original[max_day] << std::endl;
    int near_day = find_near_value(ventas_nueva, 0, size_new_sales - 1, ventas_original[max_day]);
    std::cout << near_day << "  " << ventas_nueva[near_day] << std::endl;
    return 0;
}
