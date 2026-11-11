//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_NONURGENCY_HPP
#define INC_2026_1_NONURGENCY_HPP

#include "Attention.hpp"
class NonUrgency :public Attention
{
public:
    NonUrgency();
    ~NonUrgency() override ;
    void read(std::ifstream& ) override;
    void print(std::ofstream& ) const override;
    int generate_key() const override;
    Attention* clone() const override;
private:
    std::string specialty;
    bool is_scheduled;
};


#endif //INC_2026_1_NONURGENCY_HPP
