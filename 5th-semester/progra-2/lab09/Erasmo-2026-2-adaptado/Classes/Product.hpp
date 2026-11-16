//
// Created by zincronit on 11/16/26.
//

#ifndef ERASMO_2026_2_ADAPTADO_PRODUCT_HPP
#define ERASMO_2026_2_ADAPTADO_PRODUCT_HPP

#include "../Utilities/Utils.hpp"

class Product
{
public:
    double get_weight() const;

    double get_value() const;

    Product();

    ~Product() = default;

    void read(std::ifstream&);

    void print(std::ofstream&) const;

private:
    std::string code;
    std::string name;
    double weight;
    double value;
};


#endif //ERASMO_2026_2_ADAPTADO_PRODUCT_HPP
