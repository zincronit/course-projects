//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_CHECKUP_HPP
#define INC_2026_1_CHECKUP_HPP

#include "Appointment.hpp"
class Checkup :public Appointment
{
public:
    Checkup();

    ~Checkup();

    double get_cost() const;

    void set_cost(const double cost);

    int get_doctor_id() const;

    void set_doctor_id(const int doctor_id);

    void read_checkup(std::ifstream& );
private:
    double cost;
    int doctor_id;
};


#endif //INC_2026_1_CHECKUP_HPP
