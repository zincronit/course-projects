//
// Created by zincronit on 11/9/26.
//

#include <iostream>

#define M 6
#define N 8
#define R 0.7


int find_product_number(char* array, int left , int right , char letter)
{
    if (left == right) return array[left] == letter ? 1 : 0;
    int mid = (left + right) / 2;


}

int merge_sort(char* array , int left , int right)
{

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

    std::cout << static_cast<int>('C');

    return 0;
}
