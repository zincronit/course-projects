//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_URGENCY_HPP
#define BST_EXERCISE_URGENCY_HPP

#include "Attention.hpp"
class Urgency : public Attention
{
public:
    Urgency();
    ~Urgency() override ;
    void read(std::ifstream& )override;
    void print(std::ofstream& ) const override;
    int get_key() const override;
    Attention* clone() const override;
private:
    std::string injury_zone;
    bool require_xray;
};


#endif //BST_EXERCISE_URGENCY_HPP
