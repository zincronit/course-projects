//
// Created by zincronit on 11/7/26.
//

#ifndef INC_2026_1_EMERGENCY_HPP
#define INC_2026_1_EMERGENCY_HPP

#include "Attention.hpp"

class Emergency : public Attention
{
public:
    Emergency();

    Emergency& operator= (const class Emergency& );

    virtual ~Emergency() =default;

    bool is_requires_rcp() const;

    void set_requires_rcp(const bool requires_rcp);

    int get_minutes_without_pulse() const;

    void set_minutes_without_pulse(const int minutes_without_pulse);

    void read(std::ifstream&, const int ) ;
    void print(std::ofstream& ) const;
    int get_priority();
private:
    bool requires_rcp;
    int minutes_without_pulse;
};


#endif //INC_2026_1_EMERGENCY_HPP
