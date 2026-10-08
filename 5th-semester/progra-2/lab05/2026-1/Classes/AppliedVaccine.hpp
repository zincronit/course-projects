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

    void get_name(char*) const;

    void set_name(const char*);

    int get_date() const;

    void set_date(const int);

    double get_dose() const;

    void set_dose(const double);

    void get_veterinary_license(char*) const;

    void set_veterinary_license(const char*);

    void read_applied_vaccine(std::istream& );

    AppliedVaccine& operator = (const class AppliedVaccine&);
private:
    char* name;
    int date;
    double dose;
    char* veterinary_license;
};

void operator >> (std::istream& , AppliedVaccine&);


#endif //INC_2026_1_APPLIEDVACCINE_HPP
