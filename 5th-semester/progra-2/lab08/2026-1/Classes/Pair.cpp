//
// Created by zincronit on 11/11/26.
//

#include "Pair.hpp"

Pair::Pair()
{
    int key = 0;
    value = nullptr;
}

Pair::~Pair() { delete value; }

int Pair::get_key() const {return key;}
void Pair::print(std::ofstream& output) const
{
    value->print(output);
}
