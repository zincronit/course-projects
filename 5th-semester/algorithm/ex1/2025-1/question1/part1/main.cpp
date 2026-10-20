//
// Created by zincronit on 10/16/26.
//

#define COLUMNS 8
#define ROWS 12


#include <iostream>
#include <cstring>

struct Movement
{
    int x;
    int y;
};

bool is_valid(int row, int column)
{
    return row >= 0 && row < ROWS && column >= 0 && column < COLUMNS;
}


bool has_this_letter(char* word, char letter)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == letter)
        {
            word[i] = '-';
            return true;
        }
    }
    return false;
}

bool is_valid_word(char matrix[ROWS][COLUMNS], Movement movements[], char* word, int x, int y)
{

    for (int i = 0; i < 8; i++)
    {
        char aux[std::strlen(word) + 1];
        std::strcpy(aux, word);
        int first_x = x + movements[i].x;
        int first_y = y + movements[i].y;
        if (not is_valid(first_x, first_y)) continue;
        if (has_this_letter(aux, matrix[first_x][first_y]))
        {
            int secont_x = first_x + movements[i].x;
            int secont_y = first_y + movements[i].y;
            if (not is_valid(secont_x, secont_y)) continue;
            if (has_this_letter(aux, matrix[secont_x][secont_y]))
                return true;
        }
    }
    return false;
}

void find_filtrations(char matrix[ROWS][COLUMNS], struct Movement* movements, char* word)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            char aux_word[4]{};
            std::strcpy(aux_word, word);

            if (matrix[row][col] == 'D') continue;
            bool is_first_letter = has_this_letter(aux_word, matrix[row][col]);
            if (is_first_letter)
            {
                bool match = is_valid_word(matrix, movements, aux_word, row, col);
                if (match)
                {
                    std::cout << "(" << row << ", " << col << ") " << std::endl;
                }
            }
        }
    }
}


int main()
{
    char red[ROWS][COLUMNS] = {
        {'C', 'E', 'N', 'Z', 'Y', 'X', 'A', 'U'},
        {'D', 'Y', 'X', 'A', 'B', 'A', 'Y', 'U'},
        {'A', 'Z', 'Y', 'A', 'X', 'B', 'C', 'U'},
        {'B', 'Z', 'Z', 'A', 'E', 'E', 'Y', 'A'},
        {'Y', 'Y', 'B', 'X', 'N', 'C', 'Z', 'Y'},
        {'U', 'U', 'Y', 'Y', 'B', 'N', 'C', 'Z'},
        {'Z', 'Y', 'A', 'A', 'U', 'Y', 'Y', 'E'},
        {'Y', 'U', 'E', 'D', 'Z', 'B', 'B', 'N'},
        {'Z', 'C', 'B', 'X', 'U', 'B', 'A', 'Z'},
        {'N', 'Z', 'B', 'C', 'Y', 'Y', 'A', 'Y'},
        {'X', 'A', 'E', 'Z', 'Z', 'A', 'U', 'Z'},
        {'A', 'C', 'Z', 'X', 'X', 'Y', 'Y', 'Z'}
    };

    struct Movement movements[]
    {
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1}
    };
    char word[] = "ENC";

    find_filtrations(red, movements, word);

    return 0;
}
