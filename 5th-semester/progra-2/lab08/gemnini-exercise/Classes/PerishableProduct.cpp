//
// Created by zincronit on 11/12/26.
//

#include "PerishableProduct.hpp"

PerishableProduct::PerishableProduct()
{
    shelf_life_days = 0;
    requires_cold_chain = false;
}

PerishableProduct::~PerishableProduct()
{
    std::cout << "Destroying PerishableProduct" << std::endl;
}

int PerishableProduct::get_priority() const { return 1;}
std::string PerishableProduct::get_type_name() const {return "PerishableProduct";}
Product* PerishableProduct::clone() const
{
    return new PerishableProduct(*this);
}

void PerishableProduct::read(std::ifstream& input)
{
    Product::read(input);
    shelf_life_days = Utils::read_int(input);
    input >> requires_cold_chain;
    input.ignore();
}

void PerishableProduct::print(std::ofstream& basic_ofstream)
{
    Product::print(basic_ofstream);
}
