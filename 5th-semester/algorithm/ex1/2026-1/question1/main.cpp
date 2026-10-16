//
// Created by zincronit on 10/15/26.
//
#include <iostream>
#include <iomanip>
#define ROWS 4
#define COLUMNS 4

void print_matrix(int matrix[ROWS][COLUMNS])
{
    std::cout << "Matriz evaluada:" << std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_suspect(
    int count,
    int current_sum,
    int r1,
    int c1,
    int r2,
    int c2)
{
    std::cout << "bloque sospechoso " << count << std::endl;
    std::cout << "Fila inicial " << r1 << std::endl;
    std::cout << "Columna final " << c1 << std::endl;
    std::cout << "Fila final " << r2 << std::endl;
    std::cout << "Columna final " << c2 << std::endl;
    std::cout << "suma" << current_sum << std::endl << std::endl;
}

void find_suspect(int matrix[][COLUMNS], int rows, int columns, int amount)
{
    print_matrix(matrix);
    std::cout << "Altura maxima del bleque : " << rows << std::endl;
    std::cout << "Ancho maximo del bloque : " << columns << std::endl;
    std::cout << "umbral sospechoso :" << amount << std::endl;
    std::cout << std::endl;

    int count = 0;
    bool found = false;
    for (int r1 = 0; r1 < ROWS; r1++)
    {
        for (int c1 = 0; c1 < COLUMNS; c1++)
        {
            for (int r2 = r1; r2 < ROWS and (r2 - r1 + 1) <= rows; r2++)
            {
                for (int c2 = c1; c2 < COLUMNS and (c2 - c1 + 1) <= columns; c2++)
                {
                    int current_sum = 0;

                    for (int r3 = r1; r3 <= r2; r3++)
                    {
                        for (int c3 = c1; c3 <= c2; c3++)
                        {
                            current_sum += matrix[r3][c3];
                        }
                    }
                    if (current_sum > amount)
                    {
                        found = true;
                        count++;
                        print_suspect(
                            count,
                            current_sum,
                            r1,
                            c1,
                            r2,
                            c2);
                    }
                }
            }
        }
    }
    if (not found)
    {
        std::cout << "no se encontraron sospechosos " << std::endl;
    }
}

int main()
{
    int rows = 2;
    int columns = 2;
    int amount = 50;

    int matrix[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 20, 1, 2},
        {3, 25, 4, 1},
        {1, 2, 30, 3}
    };
    find_suspect(matrix, rows, columns, amount);

    return 0;
}
