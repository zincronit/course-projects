//
// Created by zincronit on 11/5/26.
//

#include "OnlineSale.hpp"
OnlineSale::OnlineSale()
{
    shipping_city = "" ;
    shipping_cost = 0.0;
}
std::string OnlineSale::get_shipping_city() const { return shipping_city; }
void OnlineSale::set_shipping_city(const std::string& shipping_city) { this->shipping_city = shipping_city; }
double OnlineSale::get_shipping_cost() const { return shipping_cost; }
void OnlineSale::set_shipping_cost(const double shipping_cost) { this->shipping_cost = shipping_cost; }
void OnlineSale::read_sale(std::ifstream& input)
{
    Sale::read_sale(input);
    std::getline(input , shipping_city , ',');
    shipping_cost = Utils::read_double(input);
}
void OnlineSale::print_sale(std::ofstream& output) const
{
    Sale::print_sale(output);
    Utils::print_text(output, shipping_city, LINE_WIDTH/5);
    output << std::fixed << std::setprecision(2);
    output << Sale::get_base_amount() + shipping_cost;
    output << std::endl;
}