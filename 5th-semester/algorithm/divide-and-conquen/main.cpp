//
// Created by zincronit on 10/29/26.
//

#include <iostream>
#include <climits>

int binary_search(int* array, int left, int right, int value)
{
    if (left > right) return -1;
    int middle = (left + right) / 2;
    if (array[middle] == value) return middle;
    else if (value < array[middle])
        return binary_search(array, left, middle - 1, value);
    else
        return binary_search(array, middle + 1, right, value);
}

void merge(int* array, int left, int mid, int right)
{
    int counter1 = mid - left + 1;
    int counter2 = right - mid;

    int L[counter1 + 1];
    int R[counter2 + 1];
    L[counter1] = INT_MAX;
    R[counter2] = INT_MAX;
    for (int i = 0; i < counter1; i++) L[i] = array[left + i];
    for (int j = 0; j < counter2; j++) R[j] = array[mid + 1 + j];

    int j = 0, k = 0;
    for (int i = left; i <= right; i++)
    {
        if (L[j] <= R[k])
            array[i] = L[j++];
        else
            array[i] = R[k++];
    }
}

void merge_sort(int* array, int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);
    // al final va el merge
    merge(array, left, mid, right);
}

int get_unique(int* array, int left, int right)
{
    if (left > right) return -1;
    if (left == right) return array[left];

    int mid = (left + right) / 2;

    if (mid % 2 == 0 )
    {
        if ( array[mid] == array[mid + 1])
            return get_unique(array, mid + 2, right);
        else
            return get_unique(array, left , mid);
    }
    else
    {
        if ( array[mid] == array[mid - 1])
            return get_unique(array, mid + 1, right);
        else
            return get_unique(array, left, mid);
    }
}

int main()
{
    int values[] = {45, 24, 19, 4, 5, 48, 45, 19, 57, 15, 23, 32, 12, 11, 40};
    int count = sizeof(values) / sizeof(values[0]);

    // int array[90]{};
    // int size = sizeof(array) / sizeof(array[0]);
    // for (int i = 0; i < size; i++)
    // {
    //     array[i] = i + 2;
    //     std::cout << array[i] << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << binary_search(array, 0, size - 1, 20) << std::endl;
    //
    // for (int i = 0; i < count; i++)
    //     std::cout << values[i] << ", ";
    // merge_sort(values, 0 , count -1);
    //
    // std::cout << std::endl;
    // for (int i = 0; i < count; i++)
    //     std::cout << values[i] << ", ";

    int array[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    std::cout << get_unique(array, 0, count -1) << std::endl;
    return 0;
}
