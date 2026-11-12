//
// Created by zincronit on 11/12/26.
//

#include "Product.hpp"
Product::Product ()
{
    code = "null";
    description = "null";
    category = "null";
    unit_cost = 0.0;
    unit_price = 0.0;
}
void Product::read(std::ifstream& input)
{
    std::getline(input, code , ',');
    std::getline(input, description , ',');
    std::getline(input, category , ',');
    unit_cost = Utils::read_double(input);
    unit_price = Utils::read_double(input);
}
void Product::print(std::ofstream& output) {}
std::string Product::get_code() const { return code; }
