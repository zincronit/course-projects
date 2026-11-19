//
// Created by zincronit on 11/16/26.
//

#include "StandardPackage.hpp"
StandardPackage::StandardPackage() { urgent = false; }

StandardPackage::~StandardPackage()
{
    std::cout << "Destroying standard package" << std::endl;
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

void StandardPackage::print_details(std::ofstream& output) const
{
    output << "PACKAGE TYPE: STANDARD\n";
    output << "Package: " << Package::get_code() << std::endl;
    output << "Distance: " << Package::get_distance() << " Km\n";
    output << "Urgent: ";
    urgent ? output << "Yes\n": output << "No\n";
    output << "Total weight: " << Package::get_total_weight() << "kg\n";
    output << "Total value: S/ " << Package::get_total_value() << "\n";
    output << "Shipping cost: S/" << calculate_cost()<< "\n";
    output << "Status: Dispatch \n\n";
    Package::print_products(output);
    Utils::print_line(output, '-');
}

bool StandardPackage::is_urgent() const { return urgent; }

void StandardPackage::read(std::ifstream& input)
{
    Package::read(input);
    input >> urgent;
    input.ignore();
}
