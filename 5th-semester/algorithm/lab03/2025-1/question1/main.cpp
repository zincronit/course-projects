//
// Created by zincronit on 10/9/26.
//

#include "Utils/Functions.hpp"

int main()
{
    int tablero[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tablero[i][j] = 0;
        }
    }

    /* hello world */
    tablero[0][2] = -1;
    tablero[4][0] = -1;
    tablero[2][1] = -1;
    tablero[3][1] = -1;
    tablero[2][3] = -1;
    tablero[3][4] = -1;
    tablero[0][5] = -1;



    return 0;
}
