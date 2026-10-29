//
// Created by zincronit on 10/2/26.
//

#ifndef INC_2026_1_VETERINARY_HPP
#define INC_2026_1_VETERINARY_HPP

#include "Pet.hpp"

class Veterinary
{
public:
    // class Pet* get_pet_list() const;
    //
    // void set_pet_list(class Pet* const pet_list);
    Veterinary();

    ~Veterinary();

    int get_pet_count() const;

    void set_pet_count(const int pet_count);

    void operator <=(const char* filepath);

    void append_pet_capacity(int& capacity);

    void operator <<=(const char* filepath);

    int find_index(const int, const char* ) const;

    void operator <<(const char* filepath) const;
private:
    class Pet* pet_list;
    int pet_count;
};



#endif //INC_2026_1_VETERINARY_HPP
