//
// Created by zincronit on 9/24/26.
//

#include <iostream>
#define N 10


int canario_ancestral(int matriz[N][N], int possible, int contrincante)
{
    if (contrincante == N) return possible;
    if (matriz[contrincante][possible] == 0)
        possible = canario_ancestral(matriz, contrincante, contrincante + 1);
    possible = canario_ancestral(matriz, possible, contrincante + 1);
    return possible;
}

int main()
{
    int matriz[N][N] = {
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 0, 1, 0, 1, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 1},
    };
    int possible = canario_ancestral(matriz, 0, 1);
    int x = 0 ;
    int y = 0 ;
    for (int i = 0; i < N; i++)
    {
        if (matriz[possible][i] > 0) y++;
        if (matriz[i][possible] > 0) x++;
    }

    std::cout << x << " " << y << std::endl;
    if (x == N and y == 1) std::cout << possible + 1 <<std::endl;
    else std::cout << -1;

    // std::cout << possible;
    return 0;
}
