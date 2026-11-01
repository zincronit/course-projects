//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_VETERINARY_HPP
#define INC_2026_1_VETERINARY_HPP

#include "Checkup.hpp"
#include "Surgery.hpp"
#include "Vaccine.hpp"

class Veterinary
{
public:
    Veterinary();

    ~Veterinary();

    int get_checkup_count() const;

    void set_checkup_count(const int checkup_count);

    int get_checkup_capacity() const;

    void set_checkup_capacity(const int checkup_capacity);

    void load_appointments(const char* );

    void append_capacity_checkup();

    void show_appointments(const char* );
private:
    class Checkup* checkup_list;
    class Surgery surgery_list[50];
    class Vaccine vaccine_list[50];
    int checkup_count;
    int checkup_capacity;
};


#endif //INC_2026_1_VETERINARY_HPP
