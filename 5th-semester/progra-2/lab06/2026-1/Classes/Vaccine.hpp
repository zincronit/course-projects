//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_VACCINE_HPP
#define INC_2026_1_VACCINE_HPP

#include "Appointment.hpp"

class Vaccine : public Appointment
{
public:
    Vaccine();

    ~Vaccine();

    int get_dose() const;

    void set_dose(const int dose);

    int get_month() const;

    void set_month(const int month);

private:
    int month;
    int dose;
};


#endif //INC_2026_1_VACCINE_HPP
