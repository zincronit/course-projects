//
// Created by zincronit on 11/7/26.
//
#include <iostream>
#include <string>
#include <cstring>
int main()
{
    // std::string name = "samin";
    // for (std::size_t i = 0 ; name[i] != '\0'; i++)
    // {
    //     std::cout << name[i] << " ";
    // }
    //
    // int length = name.length();
    // std::cout << name.capacity()<< std::endl;
    // const std::string filepath = "Data/2026/10/08.csv";
    // int hour;
    // std::string aux;
    // aux += filepath;
    // for (int i = 0 ; i < 4 ; i++) aux.pop_back();
    // std::string aux2;
    // int size =static_cast<int>(aux.length());
    // aux2 += aux[size-2];
    // aux2 += aux[size- 1];
    // std::cout << aux2 << std::endl;
    // hour = static_cast<int>(aux[size-2] - '0');
    // hour = 10*hour + static_cast<int>(aux[size-1] - '0');
    // std::cout << hour << std::endl;
    //
    //
    std::string hello = "hello";
    hello.push_back('0' + 2);
    std::cout << hello << std::endl;
    return 0;
}