//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_EMERGENCY_HPP
#define BST_EXERCISE_EMERGENCY_HPP

#include "Attention.hpp"
class Emergency : public Attention
{
public:
    Emergency();
    ~Emergency() override ;
    void read(std::ifstream& ) override;
    void print(std::ofstream& )const override;
    int get_key() const override;
    Attention* clone() const override;
private:
    bool rcp3;
    int waiting_time;
};


#endif //BST_EXERCISE_EMERGENCY_HPP
