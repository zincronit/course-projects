//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_NONURGENCY_HPP
#define BST_EXERCISE_NONURGENCY_HPP

#include "Attention.hpp"
class NonUrgency : public Attention
{
public:
    NonUrgency();
    ~NonUrgency() override ;
    void read(std::ifstream& ) override;
    void print(std::ofstream& ) const override;
    int get_key() const override;
    Attention* clone() const override;
private:
    std::string specialty;
    bool is_scheduled;
};


#endif //BST_EXERCISE_NONURGENCY_HPP
