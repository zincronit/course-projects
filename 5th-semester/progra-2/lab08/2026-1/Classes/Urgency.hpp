//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_URGENCY_HPP
#define INC_2026_1_URGENCY_HPP

#include "Attention.hpp"
class Urgency : public Attention
{
public:
    Urgency();
    ~Urgency() override ;
    void read(std::ifstream& )override;
    void print(std::ofstream& ) const override;
    int generate_key() const override;
    Attention* clone() const override;
private:
    std::string injury_zone;
    bool require_xray;
};


#endif //INC_2026_1_URGENCY_HPP
