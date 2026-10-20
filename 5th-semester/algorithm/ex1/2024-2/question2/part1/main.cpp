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
    std::cout << std::endl;
}

bool is_valid(int x, int y)
{
    return x >= 0 and x < ROWS and y >= 0 and y < COLUMNS;
}


void paint_recursive(int matrix[][COLUMNS], int x, int y, int new_color, int target_color)
{
    if (not is_valid(x, y)) return;
    if (matrix[x][y] != target_color) return;
    matrix[x][y] = new_color;
    paint_recursive(matrix, x - 1, y, new_color, target_color);
    paint_recursive(matrix, x, y - 1, new_color, target_color);
    paint_recursive(matrix, x + 1, y, new_color, target_color);
    paint_recursive(matrix, x, y + 1, new_color, target_color);
}


void paint(int matrix[][COLUMNS], int x, int y, int new_color)
{
    if (not is_valid(x, y)) return;
    int target_color = matrix[x][y];

    paint_recursive(matrix, x, y, new_color, target_color);
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
    paint(matrix, 1, 1, 2);
    print_matrix(matrix);

    return 0;
}
