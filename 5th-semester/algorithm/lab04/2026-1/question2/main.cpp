//
// Created by zincronit on 11/8/26.
//

#include <iostream>
#include <climits>
#include <iomanip>

struct City
{
    char name[100];
    int distance;
};

void merge(struct City* cities, int left, int mid, int right)
{
    struct City L[mid - left + 2];
    struct City R[right - mid + 1];

    int count_left = 0, count_right = 0;
    for (int i = left; i <= mid; i++) L[count_left++] = cities[i];
    for (int i = mid + 1; i <= right; i++) R[count_right++] = cities[i];

    L[count_left].distance = INT_MAX;
    R[count_right].distance = INT_MAX;

    int k = 0, j = 0;
    for (int i = left; i <= right; i++)
    {
        if (L[k].distance <= R[j].distance)
            cities[i] = L[k++];
        else
            cities[i] = R[j++];
    }
}

void merge_sort(struct City* cities, int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;

    merge_sort(cities, left, mid);
    merge_sort(cities, mid + 1, right);

    merge(cities, left, mid, right);
}

void print_cities(struct City* cities, int left , int right)
{
    std::cout << std::left;
    for (int i = left; i <= right; i++)
        std::cout << std::setw(20) << cities[i].name << ": " << cities[i].distance << "km\n";
}

int find_near_number(struct City* cities, int left, int right, int number , bool wanna_find_min)
{
    if (left > right) return -1;
    if (wanna_find_min)
    {
        int mid = (left + right) / 2;
        if (cities[mid].distance >= number)
        {
            int result = find_near_number(cities, left, mid - 1, number , true);
            return result == -1 ? mid : result;
        }
        return find_near_number(cities, mid + 1, right, number , true);
    }
    else
    {
        int mid = (left + right) / 2;
        if (cities[mid].distance <= number)
        {
            int result =  find_near_number(cities, mid + 1 , right, number , false);
            return result == -1 ? mid : result;
        }
        return find_near_number(cities, left, mid - 1, number , false);
    }
}


void find_cities(struct City* cities, int size, int min_limit, int max_limit)
{
    int min = find_near_number(cities, 0, size - 1, min_limit, true);
    int max = find_near_number(cities, 0, size - 1, max_limit, false);

    if (max == -1 or min == -1 or min > max )
    {
        std::cout << "\nNo hay ciudades en ese rango \n" ;
        return;
    }
    int count = max - min + 1;
    std::cout << "\nCiudades entre "<< min_limit << " km y "<< max_limit <<" km \n";
    print_cities(cities, min, max);
    std::cout << "\nTotal: " << count << " ciudades\n";
}

int main()
{
    City cities[] = {
        {"Lima", 34},
        {"Cusco", 12},
        {"Arequipa", 67},
        {"Trujillo", 8},
        {"Piura", 45},
        {"Iquitos", 23},
        {"Tacna", 89},
        {"Puno", 5}
    };
    int size = sizeof(cities) / sizeof(cities[0]);
    print_cities(cities, 0,size -1);
    merge_sort(cities, 0, size - 1);
    std::cout << std::endl;
    print_cities(cities, 0,size -1);

    int min_limit = 90;
    int max_limit = 100;

    find_cities(cities, size, min_limit, max_limit);

    return 0;
}
