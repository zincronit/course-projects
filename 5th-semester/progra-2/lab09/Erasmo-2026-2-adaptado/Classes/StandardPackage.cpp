//
// Created by zincronit on 11/16/26.
//

#include "StandardPackage.hpp"
StandardPackage::StandardPackage() { urgent = false; }

void StandardPackage::print_products(std::ofstream& output) const
{
    Package::print_products(output);
    std::cout << "HELLO" << std::endl;
}

double StandardPackage::calculate_cost() const
{
    double P = Package::get_total_weight();
    double D = Package::get_distance();
    double cost = 10 + 2 * P + 0.05 * D;
    urgent ? cost += 8 : cost += 0.0;
    return cost;
}

bool StandardPackage::can_dispatch() const
{
    double P = Package::get_total_weight();
    double D = Package::get_distance();
    return P <= 20 and D <= 500;
}

void StandardPackage::print_details(std::ofstream&) const {}

bool StandardPackage::is_urgent() const { return urgent; }

void StandardPackage::read(std::ifstream& input)
{
    Package::read(input);
    input >> urgent;
    input.ignore();
}
