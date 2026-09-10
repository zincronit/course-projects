//
// Created by zincronit on 9/4/26.
//

#ifndef INC_2026_1_FUNCTIONS_HPP
#define INC_2026_1_FUNCTIONS_HPP

#include "../Tools/tools.hpp"

void load_information(const char*, int*&, char****&, int***&, double***&);

int find_index(const int*, int, int);

void append_date_capacity(int*&, char****&, int***&, double***&, int&, int&, int*&, int*&);

void change_pointer(int*&, char****&, int***&, double***&, int, int, int*&, int*&);

int insert_new_date(int*, char****, int***, double***, int&, int, int*, int*);

void append_attention(
    char***&,
    int**&,
    double**&,
    int&,
    int&,
    int,
    int,
    int,
    int,
    double,
    char*,
    char*,
    char*);

void append_attention_capacity(char***&, int**&, double**&, int&, int);

void attention_report(const char*, int*, char****, int***, double***);

void print_title(std::ofstream& );

void print_header(std::ofstream& );

void print_information(std::ofstream&  , char*** , int** , double**  );

void print_time(std::ofstream& , int, int);

void shrink_date_capacity(int*& ,char****& , int***& , double***& , int ,const int*);

void shrink_single_date_attentions(char***& , int**& , double**& , int );

#endif //INC_2026_1_FUNCTIONS_HPP
