//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_SURGERY_HPP
#define INC_2026_1_SURGERY_HPP

#include "Appointment.hpp"
class Surgery: public Appointment
{
public:
    Surgery();

    ~Surgery();

    bool is_general_anesthesia() const;

    void set_general_anesthesia(const bool general_anesthesia);

    int get_doctor_count() const;

    void set_doctor_count(const int doctor_count);

    double get_cost() const;

    void set_cost(const double cost);

private:
    bool general_anesthesia;
    int doctor_count;
    double cost;
};


#endif //INC_2026_1_SURGERY_HPP
