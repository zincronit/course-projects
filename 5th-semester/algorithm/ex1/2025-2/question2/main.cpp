//
// Created by zincronit on 10/14/26.
//


#include <iostream>

void move_packages(
    int package_count,
    char origin,
    char auxiliary,
    char destination)
{
    if (package_count <= 0) return;

    move_packages(
        package_count - 1,
        origin,
        auxiliary,
        destination
    );

    std::cout << "Move package " << package_count
            << " del alamacen " << origin
            << " al almacen " << auxiliary << std::endl;

    move_packages(
        package_count - 1,
        destination,
        auxiliary,
        origin
    );

    std::cout << "Move package " << package_count
            << " del alamacen " << auxiliary
            << " al almacen " << destination << std::endl;

    move_packages(
        package_count - 1,
        origin,
        auxiliary,
        destination
    );
}


int main()
{
    int package_count = 2;
    // std::cout << "Enter the package count ";
    // std::cin >> package_count;

    move_packages(
        package_count,
        'A',
        'B',
        'C');
    return 0;
}
