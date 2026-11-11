//
// Created by zincronit on 11/9/26.
//

#include <algorithm>
#include <iostream>
#include <climits>
#define M 6
#define N 8
#define R 0.7


int find_product_number(char* array, int left , int right , char letter)
{
    if (left == right) return array[left] == letter ? 1 : 0;
    int mid = (left + right) / 2;
    // falta terminar
}

void print_matrix(char matrix[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}


void merge(char* array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid ;
    char* left_array = new char[n1 + 1];
    char* right_array = new char[n2 + 1];

    int counter1  = 0, counter2 = 0;
    for (int i = left; i <= mid ; i++) left_array[counter1++] = array[i];
    for (int i = mid + 1 ; i <= right ; i++) right_array[counter2++] = array[i];

    left_array[counter1] = CHAR_MIN;
    right_array[counter2] = CHAR_MIN;

    counter1 = 0; counter2 = 0;
    for (int i = left; i <= right; i++)
    {
        if (left_array[counter1] >= right_array[counter2])
            array[i] = left_array[counter1++];
        else
            array[i] = right_array[counter2++];
    }
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(char* array , int left , int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;
    merge_sort(array, left , mid);
    merge_sort(array, mid + 1, right);

    merge(array, left, mid, right);
}

int main()
{
    char matrix[M][N] = {
        {'F', 'F', 'F', 'C', 'C', 'F', ' ', ' '},
        {'C', 'F', 'C', 'C', 'C', 'F', 'C', 'F'},
        {'F', 'C', 'C', 'C', 'C', 'C', 'C', 'C'},
        {'C', 'C', 'C', 'C', 'C', 'F', 'C', ' '},
        {'C', 'F', 'F', 'F', 'F', 'C', ' ', ' '},
        {'C', 'C', 'F', 'C', 'F', 'C', 'C', ' '}
    };

    std::cout << static_cast<int>('C') << std::endl;
    std::cout << static_cast<int>('F') << std::endl;
    std::cout << static_cast<int>('\0') << std::endl;
    print_matrix(matrix);
    for (int i = 0; i < M; i++)
        merge_sort(matrix[i] , 0, N - 1);
    std::cout << std::endl;
    print_matrix(matrix);
    return 0;
}
