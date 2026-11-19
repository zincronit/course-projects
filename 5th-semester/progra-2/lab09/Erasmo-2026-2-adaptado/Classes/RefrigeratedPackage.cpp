//
// Created by zincronit on 11/16/26.
//

#include "RefrigeratedPackage.hpp"
RefrigeratedPackage::RefrigeratedPackage() { temperature = 0.0; }

RefrigeratedPackage::~RefrigeratedPackage()
{
    std::cout << "Destroying refrigerated package" << std::endl;
}

void RefrigeratedPackage::read(std::ifstream& input)
{
    Package::read(input);
    temperature = Utils::read_double(input);
}

double RefrigeratedPackage::calculate_cost() const
{
    double P = Package::get_total_weight();
    double D = Package::get_distance();
    double cost = 20 + 3*P + 0.08*D + 1.5*(8 - temperature);
    return cost;
}
bool RefrigeratedPackage::can_dispatch() const
{
    double P = Package::get_total_weight();
    double D = Package::get_distance();
    return P <= 10 and D <= 300 and temperature >= -10 and temperature <= 8;
}

void RefrigeratedPackage::print_details(std::ofstream& output) const
{
    output << "PACKAGE TYPE: REFRIGERATED\n";
    output << "Package: " << Package::get_code() << std::endl;
    output << "Distance: " << Package::get_distance() << " Km\n";
    output << "Required temperature: " << temperature << " deg C\n";
    output << "Total weight: " << Package::get_total_weight() << "kg\n";
    output << "Total value: S/ " << Package::get_total_value() << "\n";
    output << "Shipping cost: S/" << calculate_cost()<< "\n";
    output << "Status: Dispatch \n\n";
    Package::print_products(output);
    Utils::print_line(output, '-');
}
