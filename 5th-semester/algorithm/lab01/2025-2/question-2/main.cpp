#include <iostream>
#include <cmath>
#define N 6
#define M 11

void minar(int mina[N + 1][M + 1], int x, int y, int n, int m, int numero, int estado);

void print_mina(int mina[N + 1][M + 1], int n , int m );

int main()
{
    int mina[N + 1][M + 1]{};
    int n = N ;
    int m = M ;
    // mina[3][5] = -1;
    mina[4][5] = -1;
    mina[5][5] = -1;
    // mina[4][6] = - 1;
    // mina[5][6] = - 1;
    mina[5][0] = -1;
    mina[4][0] = -1;
    mina[2][5] = -1;
    mina[N - 1][M - 1] = -1;
    minar(mina, n - 1, 0, n, m, 1, 0);
    print_mina(mina, n , m);
    return 0;
}

void minar(int mina[N + 1][M + 1], int x, int y, int n, int m, int numero, int estado)
{
    if (estado == 0)
    {
        if (x < 0) return;
        if (mina[x][0] == 0)
        {
            mina[x][0] = numero;
            minar(mina, x, 0, n, m, numero, 1);
        } else
        {
            minar(mina, x - 1, 0, n, m, numero, 0);
        }
        return;
    }
    if (y == m - 1)
    {
        minar(mina, n - 1, 0, n, m, numero + 1, 0);
        return;
    }
    if (x + 1 < n and mina[x + 1][y] == 0)
    {
        mina[x + 1][y] = numero;
        minar(mina, x + 1, y, n, m, numero, 1);
    } else if (y + 1 < m and mina[x][y + 1] == 0)
    {
        mina[x][y + 1] = numero;
        minar(mina, x, y + 1, n, m, numero, 1);
    } else if (x - 1 >= 0 and mina[x - 1][y] == 0)
    {
        mina[x - 1][y] = numero;
        minar(mina, x - 1, y, n, m, numero, 1);
    }
}

void print_mina(int mina[N + 1][M + 1], int n , int m )
{
    // Arreglo para registrar qué galerías llegaron a la última columna (M - 1)
    bool galeria_completa[N + 1]{};

    // Registrar cuáles números sí llegaron hasta el extremo derecho[cite: 1]
    for (int i = 0; i < n; i++)
    {
        if (mina[i][m - 1] > 0)
        {
            galeria_completa[mina[i][m - 1]] = true;
        }
    }

    // Impresión condicionada: Si la galería no está completa, se muestra como vacía [ ]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = mina[i][j];

            if (val == -1)
                std::cout << "[*]";
            else if (val > 0 && galeria_completa[val])
                std::cout << '[' << val << ']';
            else
                std::cout << "[ ]"; // Si era 0 o una galería incompleta, imprime espacio vacío
        }
        std::cout << std::endl;
    }
}
