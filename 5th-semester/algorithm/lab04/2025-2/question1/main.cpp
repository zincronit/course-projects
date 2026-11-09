//
// Created by zincronit on 11/8/26.
//

#include <iostream>
#include <iomanip>
#include <climits>

#define N 6

void merge(int* array, int left, int mid, int right)
{
    const int left_size = mid - left + 2;
    const int right_size = right - mid + 1;
    int L[left_size];
    int R[right_size];
    int count_left = 0, count_right = 0;
    for (int i = left; i <= mid; i++) L[count_left++] = array[i];
    for (int i = mid + 1; i <= right; i++) R[count_right++] = array[i];
    L[count_left] = INT_MAX;
    R[count_right] = INT_MAX;
    count_left = 0;
    count_right = 0;
    for (int i = left; i <= right; i++)
    {
        if (L[count_left] <= R[count_right])
            array[i] = L[count_left++];
        else
            array[i] = R[count_right++];
    }
}

void merge_sort(int* array, int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    merge(array, left, mid, right);
}

void print_matrix(int matrix[][N])
{
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
            std::cout << matrix[i][j] << ", ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void find_birds(int docker[][N])
{
    print_matrix(docker);
    for (int i = 0; i < N; i++)
        merge_sort(docker[i], 0, N - 1);

    

    print_matrix(docker);
}

int main()
{
    int docker[N][N] = {
        {INT_MAX, 3, 7, 2, 2, 7},
        {5, INT_MAX, 3, 1, 5, 3},
        {7, 7, 3, 6, 6, 3},
        {7, 4, INT_MAX, 7, 2, 4},
        {5, 1, 2, 5, 1, 2},
        {6, INT_MAX, 7, 4, 7, 4}
    };
    find_birds(docker);


    return 0;
}
