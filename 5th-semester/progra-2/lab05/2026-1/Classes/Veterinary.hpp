//
// Created by zincronit on 10/2/26.
//

#ifndef INC_2026_1_VETERINARY_HPP
#define INC_2026_1_VETERINARY_HPP

#include "Pet.hpp"

class Veterinary
{
public:
    Veterinary();

    ~Veterinary();

    int get_pet_count() const;
    void set_pet_count(const int );

    void append_pet_capacity( int& );

    void operator <= (  const char*);

    void operator <<= ( const char*);

    int find_pet_index(const char* , int) const;
private:
    class Pet* pet_list;
    int pet_count;
};

#endif //INC_2026_1_VETERINARY_HPP
