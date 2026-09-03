//
// Created by zincronit on 9/3/26.
//

#ifndef BUILD_STATIC_LIBRARY_SYSTEM_HPP
#define BUILD_STATIC_LIBRARY_SYSTEM_HPP

#include "Pet.hpp"
#include "Veterinary.hpp"
#include "Attention.hpp"

struct System
{
    struct Pet* pets;
    struct Veterinary* veterinaries;
    struct Attention* attentions;
    int pet_count;
    int veterinary_count;
    int attention_count;
};

#endif //BUILD_STATIC_LIBRARY_SYSTEM_HPP
