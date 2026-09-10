//
// Created by zincronit on 9/5/26.
//

#include <iostream>
#include <cmath>

// int numero_mov(int& , char = 'C' );
//
// int main()
// {
//     int n = 3;
//
//     return 0;
// }
//
// int numero_mov(int& numero, char torre)
// {
//     if (numero == 1) return 1;
//     --numero;
//     numero_mov(numero, 'B');
//
// }

void solveHanoi(
    int diskCount,
    char originTower,
    char auxiliaryTower,
    char destinationTower
) {
    if (diskCount == 1) {
        std::cout << "Move disk 1 from " << originTower << " to " << destinationTower << std::endl;
        return;
    }

    solveHanoi(
        diskCount - 1,
        originTower,
        destinationTower,
        auxiliaryTower
    );

    std::cout << "Move disk " << diskCount << " from " << originTower << " to " << destinationTower << std::endl;

    solveHanoi(
        diskCount - 1,
        auxiliaryTower,
        originTower,
        destinationTower
    );
}

int main() {
    int totalDisks = 3;

    solveHanoi(
        totalDisks,
        'A',
        'B',
        'C'
    );

    return 0;
}