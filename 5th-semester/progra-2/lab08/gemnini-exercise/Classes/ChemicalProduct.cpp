//
// Created by zincronit on 11/12/26.
//

#include "ChemicalProduct.hpp"

ChemicalProduct::ChemicalProduct()
{
    hazard_code = "null";
    is_concentrate = false;
}
ChemicalProduct::~ChemicalProduct()
{
    std::cout << "Destroying PerishableProduct " << std::endl;
}

int ChemicalProduct::get_priority() const { return 2; }
std::string ChemicalProduct::get_type_name() const { return "ChemicalProduct"; }
Product* ChemicalProduct::clone() const
{
    return new ChemicalProduct(*this);
}

void ChemicalProduct::read(std::ifstream& input)
{
    Product::read(input);
    std::getline(input, hazard_code, ',');
    input >> is_concentrate;
    input.ignore();
}

void ChemicalProduct::print(std::ofstream& basic_ofstream)
{
    Product::print(basic_ofstream);
}

