//
// Created by zincronit on 9/6/26.
//


#include <iostream>
#include <cstring>
#include <climits>

#define M 10
#define N 10


int buscar_mina(char mina[M][N],
                int alcance,
                int x,
                int y,
                int inicioY,
                int inicioX,
                int n,
                int m,
                bool usado[M][N])
{
    int cant_minas = 0;
    if (x < 0 or x >= m or y < 0 or y >= n ) return cant_minas;

    if (abs(y - inicioY) > abs(x - inicioX)) return cant_minas;
    if (!usado[x][y])
    {
        if (mina[x][y] == 'A') cant_minas++;
        usado[x][y] = true;
        mina[x][y] = '*';
    }
    if (alcance == 0) return cant_minas;
    cant_minas += buscar_mina(mina, alcance - 1, x - 1, y - 1,inicioY, inicioX, n, m, usado);
    cant_minas += buscar_mina(mina, alcance - 1, x - 1, y + 0,inicioY, inicioX, n, m, usado);
    cant_minas += buscar_mina(mina, alcance - 1, x - 1, y + 1,inicioY, inicioX, n, m, usado);
    cant_minas += buscar_mina(mina, alcance - 1, x + 1, y + 1,inicioY, inicioX, n, m, usado);
    cant_minas += buscar_mina(mina, alcance - 1, x + 1, y + 0,inicioY, inicioX, n, m, usado);
    cant_minas += buscar_mina(mina, alcance - 1, x + 1, y - 1,inicioY, inicioX, n, m, usado);
    return cant_minas;
}

void print_tabero(char mina[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << '[' << mina[i][j] << ']';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int alcance = 3;
    int x = 4, y = 4;
    int n = N, m = M;
    char mina[M][N]{};
    bool usado[M][N]{};
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mina[i][j] = ' ';
            usado[i][j] = false;
        }
    }
    // estoy tomande como (0, 0) la parte superior izquierda
    // puse minas al azar
    mina[4][4] = 'A';
    mina[4][5] = 'A';
    mina[5][6] = 'A';
    mina[6][5] = 'A';
    mina[8][6] = 'A';
    mina[6][8] = 'A';
    // agreguele mas minas si quireres
    print_tabero(mina);
    int cant_minas = buscar_mina(mina, alcance, x, y, x, y, n, m, usado);
    print_tabero(mina);
    std::cout << cant_minas << std::endl;
    return 0;
}


