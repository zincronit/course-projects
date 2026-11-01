//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_APPOINTMENT_HPP
#define INC_2026_1_APPOINTMENT_HPP

#include "Pet.hpp"
class Appointment
{
public:
    int get_date() const;

    void set_date(const int date);

    int get_hour() const;

    void set_hour(const int hour);

    Appointment();
    ~Appointment();
    void read_appointment(std::ifstream& );
    void print_appointment(std::ofstream& ) const;
private:
    int date;
    int hour;
    class Pet pet;
};


#endif //INC_2026_1_APPOINTMENT_HPP
