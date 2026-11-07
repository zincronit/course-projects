//
// Created by zincronit on 11/7/26.
//

#ifndef INC_2026_1_NOTURGENT_HPP
#define INC_2026_1_NOTURGENT_HPP

#include "Attention.hpp"

class NotUrgent : public Attention
{
public:
    NotUrgent();

    NotUrgent& operator=(const class NotUrgent& );

    virtual ~NotUrgent() = default;

    std::string get_specialty() const;

    void set_specialty(const std::string& specialty);

    bool get_is_scheduled_appointment() const;

    void set_is_scheduled_appointment(const bool is_scheduled_appointment);
    void read(std::ifstream&, const int) ;
    void print(std::ofstream&) const ;
    int get_priority();

private:
    std::string specialty;
    bool is_scheduled_appointment;
};


#endif //INC_2026_1_NOTURGENT_HPP
