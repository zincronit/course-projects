//
// Created by zincronit on 10/2/26.
//

#ifndef INC_2026_1_PETS_HPP
#define INC_2026_1_PETS_HPP

#include "AppliedVaccine.hpp"

class Pet
{
public:
    Pet();

    ~Pet();

    int get_owner_dni() const;

    void set_owner_dni(const int);

    void get_name(char*) const;

    void set_name(const char*);

    void get_specie(char*) const;

    void set_specie(const char*);

    int get_age() const;

    void set_age(const int);

    double get_weight() const;

    void set_weight(const double);

    void get_veterinary_code(char*) const;

    void set_veterinary_code(const char*);

    int get_vaccine_count() const;

    void set_vaccine_count(const int);

    void read_pet(std::istream&);

    Pet& operator =(const class Pet&);

    void operator +=(const class AppliedVaccine&);

private:
    int owner_dni;
    char* name;
    char* specie;
    int age;
    double weight;
    char* veterinary_code;
    AppliedVaccine vaccine_list[20];
    int vaccine_count;
};

void operator >>(std::istream&, Pet&);

#endif //INC_2026_1_PETS_HPP
