//
// Created by zincronit on 11/16/26.
//

#include "Package.hpp"
std::string Package::get_code() const { return code; }

double Package::get_distance() const { return distance; }

double Package::get_total_weight() const { return total_weight; }

double Package::get_total_value() const { return total_value; }

Package::Package()
{
    code = "null";
    distance = 0.0;
    total_weight = 0.0;
    total_value = 0.0;
}

void Package::add_product(const Product& product)
{
    products.push_back(product);
    total_weight += product.get_weight();
    total_value += product.get_value();
}

void Package::read(std::ifstream& input)
{
    std::getline(input , code, ',');
    distance = Utils::read_double(input);
    input.ignore();
    input.ignore();
}

void Package::print_products(std::ofstream& output) const
{
    output << "Products: \n";
    std::string headers[] = {"Code", "Name" , "Weight" , "Value"};
    for (std::string& header : headers)
        Utils::print_text(output ,header, WIDTH);
    output << std::endl;
    for (auto& product: products)
        product.print(output);
}
