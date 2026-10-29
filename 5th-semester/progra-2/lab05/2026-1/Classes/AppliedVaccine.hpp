//
// Created by zincronit on 10/2/26.
//


#ifndef INC_2026_1_APPLIEDVACCINE_HPP
#define INC_2026_1_APPLIEDVACCINE_HPP

#include "../Utils/Utils.hpp"

class AppliedVaccine
{
public:
    AppliedVaccine();

    ~AppliedVaccine();

    void get_name(char* name) const;

    void set_name(char* const name);

    int get_date() const;

    void set_date(const int date);

    double get_dose() const;

    void set_dose(const double dose);

    void get_veterinary_id(char* id) const;

    void set_veterinary_id(char* const veterinary_id);

    void read_applied_vaccine(std::ifstream&);

    AppliedVaccine& operator = (const class AppliedVaccine& );

    bool operator == (const class AppliedVaccine& ) const;
private:
    char* name;
    int date;
    double dose;
    char* veterinary_id;
};
void operator >> (std::ifstream& , class AppliedVaccine& );

void operator << (std::ofstream& ,const class AppliedVaccine& );

#endif //INC_2026_1_APPLIEDVACCINE_HPP
