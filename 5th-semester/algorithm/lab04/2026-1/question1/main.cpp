//
// create by zincronit
//

#include <iostream>
#define N 8


int numero_elementos(char* array, int left, int right, char letter)
{
    // int count = 0;
    // for (int i = left; i <= right ; i++)
    //     if (array[i] == letter) count ++;
    // return count;

    if (left > right) return 0;
    if (left == right)return array[left] == letter ? 1 : 0;

    int mid = (left + right) / 2;
    return numero_elementos(array, mid + 1, right, letter) + numero_elementos(array, left, mid, letter);

}

void encontrar_polo(char* almacen, int left, int right, char& polo, int& cant)
{
    if (left > right) return;
    if (left == right)
    {
        polo = almacen[left];
        cant = 1;
        return;
    }
    int right_count, left_count;
    int mid = (left + right) / 2;
    char max_left, max_right;
    encontrar_polo(almacen, left, mid, max_left, left_count);
    encontrar_polo(almacen, mid + 1, right, max_right, right_count);


    if (max_left == max_right)
    {
        polo = max_left;
        cant = left_count + right_count;
        return;
    }

    left_count += numero_elementos(almacen, mid + 1, right, max_left);
    right_count += numero_elementos(almacen, left, mid, max_right);

    if (left_count >= right_count)
    {
        polo = max_left;
        cant = left_count;
    } else
    {
        polo = max_right;
        cant = right_count;
    }
}


int main()
{
    char almacen[N] = {'A', 'A', 'A', 'K', 'F', 'C', 'C', 'F'};
    char polo;
    int cant = 0;
    encontrar_polo(almacen, 0, N - 1, polo, cant);
    std::cout << "Polo con mas unidades: " << polo << std::endl;
    std::cout << "Cantidad de polo: " << cant << std::endl;
    return 0;
}
