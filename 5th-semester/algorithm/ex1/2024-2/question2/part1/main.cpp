//
// Created by zincronit on 10/16/26.
//
#include <iostream>

#define ROWS 3
#define COLUMNS 3


void print_matrix(int matrix[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void paint(int matrix[][COLUMNS], int x , int y , int color)
{
    if (x >= 0 and x < ROWS and y >= 0 and y < COLUMNS) 
}

int main()
{
    int matrix[ROWS][COLUMNS]
    {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    print_matrix(matrix);


    return 0;
}
