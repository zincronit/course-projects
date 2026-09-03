//
// Created by zincronit on 9/3/26.
//

#ifndef USING_STATIC_LIBRARY_FUNCTIONS_HPP
#define USING_STATIC_LIBRARY_FUNCTIONS_HPP

#include "../Overloads/overloads.hpp"

void read_pet_file(const char* filepath, struct Pet*& pets, int& count);

void read_veterinary_file(const char* filepath, struct Veterinary*& veterinaries, int& count);

void read_attention_file(const char* filepath, struct Attention*& attentions, int& count);

void assign_attention(struct Attention& a, struct Attention& b);

char* allocate_string(const char* str);

void print_pet_report(const char* filepath, struct Pet* pets, int count);

void print_pet_attention(const char* filepath,
                         struct Pet* pets,
                         int pet_count,
                         struct Attention* attentions,
                         int attention_count);

void print_line(std::ofstream& fout, int width, char character);

void print_title(std::ofstream& fout, const char* title, int width);


#endif //USING_STATIC_LIBRARY_FUNCTIONS_HPP
