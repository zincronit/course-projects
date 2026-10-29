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

    void set_owner_dni(const int owner_dni);

    void get_name(char* ) const;

    void set_name(char* const name);

    void get_specie(char* ) const;

    void set_specie(char* const specie);

    int get_age() const;

    void set_age(const int age);

    double get_weight() const;

    void set_weight(const double weight);

    void get_veterinary_id(char* ) const;

    void set_veterinary_id(char* const veterinary_id);

    int get_vaccine_count() const;

    void set_vaccine_count(const int vaccine_count);

    void read_pet(std::ifstream& );

    Pet& operator = (const class Pet& );

    void operator += (const class AppliedVaccine& );

    bool operator ~() const;

    void print_vaccine_list(std::ofstream& output) const;
private:
    int owner_dni;
    char* name;
    char* specie;
    int age;
    double weight;
    char* veterinary_id;
    class AppliedVaccine vaccine_list[20];
    int vaccine_count;
};

void operator >> (std::ifstream& , class Pet& );

void operator << (std::ofstream& ,const class Pet& );
#endif //INC_2026_1_PETS_HPP
