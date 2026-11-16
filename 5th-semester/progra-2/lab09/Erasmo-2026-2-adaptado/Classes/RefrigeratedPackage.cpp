//
// Created by zincronit on 11/16/26.
//

#include "RefrigeratedPackage.hpp"
RefrigeratedPackage::RefrigeratedPackage() { tempeture = 0.0; }

void RefrigeratedPackage::read(std::ifstream& input)
{
    Package::read(input);
    tempeture = Utils::read_double(input);
}

void RefrigeratedPackage::print_products(std::ofstream& output) const
{
    Package::print_products(output);
}

double RefrigeratedPackage::calculate_cost() const
{
    double P = Package::get_total_weight();
    double D = Package::get_distance();
    double cost = 20 + 3*P + 0.08*D + 1.5*(8 - tempeture);
    return cost;
}
bool RefrigeratedPackage::can_dispatch() const
{
    double P = Package::get_total_weight();
    double D = Package::get_distance();
    return P <= 10 and D <= 300 and tempeture >= -10 and tempeture <= 8;
}

void RefrigeratedPackage::print_details(std::ofstream&) const {}
