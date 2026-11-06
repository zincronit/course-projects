//
// Created by zincronit on 11/5/26.
//

#include "Wholesale.hpp"
Wholesale::Wholesale()
{
    tax_id = "";
    volume_discount = 0.0;
}
std::string Wholesale::get_tax_id() const { return tax_id; }
void Wholesale::set_tax_id(const std::string& tax_id) { this->tax_id = tax_id; }
double Wholesale::get_volume_discount() const { return volume_discount; }
void Wholesale::set_volume_discount(const double volume_discount) { this->volume_discount = volume_discount; }
void Wholesale::read_sale(std::ifstream& input)
{
    Sale::read_sale(input);
    std::getline(input, tax_id, ',');
    volume_discount = Utils::read_double(input);
}
void Wholesale::print_sale(std::ofstream& output) const
{
    Sale::print_sale(output);
    Utils::print_text(output, tax_id, LINE_WIDTH/5);
    output << std::fixed << std::setprecision(2);
    output << Sale::get_base_amount() - (Sale::get_base_amount() *volume_discount) / 100;
    output << std::endl;
}