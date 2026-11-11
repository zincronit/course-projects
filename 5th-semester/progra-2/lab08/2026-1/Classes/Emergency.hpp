//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_EMERGENCY_HPP
#define INC_2026_1_EMERGENCY_HPP

#include "Attention.hpp"
class Emergency : public Attention
{
public:
    Emergency();
    ~Emergency() override ;
    void read(std::ifstream& ) override;
    void print(std::ofstream& )const override;
    int generate_key() const override;
    Attention* clone() const override;

private:
    bool rcp3;
    int waiting_time;
};


#endif //INC_2026_1_EMERGENCY_HPP
