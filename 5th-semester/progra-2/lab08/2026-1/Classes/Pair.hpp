//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_PAIR_HPP
#define INC_2026_1_PAIR_HPP

#include "Attention.hpp"
class Pair
{
public:
    Pair();
    ~Pair();
    int get_key() const ;
    void print(std::ofstream& ) const;
    friend class DoubleListNode;

private:
    int key;
    class Attention* value;
};


#endif //INC_2026_1_PAIR_HPP
