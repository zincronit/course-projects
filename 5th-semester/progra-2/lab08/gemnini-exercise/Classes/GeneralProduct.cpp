//
// Created by zincronit on 11/12/26.
//

#include "GeneralProduct.hpp"
GeneralProduct::GeneralProduct()
{
    warranty_months = 0;
    fragile_flag = false;
}
GeneralProduct::~GeneralProduct()
{
    std::cout << "Destroying GeneralProduct " << std::endl;
}
int GeneralProduct::get_priority() const { return 3; }
std::string GeneralProduct::get_type_name() const {return "GeneralProduct";}
Product* GeneralProduct::clone() const
{
    return new GeneralProduct(*this);
}

void GeneralProduct::read(std::ifstream& input)
{
    Product::read(input);
    warranty_months = Utils::read_int(input);
    input >> fragile_flag;
    input.ignore();
}

void GeneralProduct::print(std::ofstream& basic_ofstream)
{
    Product::print(basic_ofstream);
}
