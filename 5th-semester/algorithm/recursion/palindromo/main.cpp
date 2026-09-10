//
// Created by zincronit on 9/5/26.
//

#include <iostream>
#include <cstring>

bool es_palindromo(char* ,int& , int );

int main()
{
    int i = 0;
    char word [100]{};
    std::cout << "Enter a word: " << std::endl;
    std::cin >> word ;
    // char word[] = { 'o', 'w', 'w', 'o'};
    int length = std::strlen(word);
    if (es_palindromo(word, i, length)) std::cout << "es palindromo" << std::endl;
    else std::cout << "Not es palindromo" << std::endl;
    return 0;
}

bool es_palindromo(char* word, int& i, int length)
{
    if (i > length - i -1) return true;
    if (word[i] != word[length-i-1]) return false;
    i++;
     return es_palindromo(word, i, length);
}