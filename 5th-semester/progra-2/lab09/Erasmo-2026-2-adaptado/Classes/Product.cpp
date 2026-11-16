//
// Created by zincronit on 11/16/26.
//

#include "Product.hpp"

double Product::get_weight() const { return weight; }

double Product::get_value() const { return value; }

Product::Product()
{
    code = "null";
    name = "null";
    weight = 0.0;
    value = 0.0;
}

void Product::read(std::ifstream& input)
{
    std::getline(input, code, ',');
    std::getline(input, name, ',');
    weight = Utils::read_double(input);
    value = Utils::read_double(input);
}

void Product::print(std::ofstream& output) const
{
    output << std::fixed << std::setprecision(2);
    Utils::print_text(output , code , WIDTH);
    Utils::print_text(output, name , WIDTH);
    output << std::setw(WIDTH) <<  weight;
    output << value << std::endl;
}
