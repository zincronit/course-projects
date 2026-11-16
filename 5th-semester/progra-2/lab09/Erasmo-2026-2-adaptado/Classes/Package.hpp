//
// Created by zincronit on 11/16/26.
//

#ifndef ERASMO_2026_2_ADAPTADO_PACKAGE_HPP
#define ERASMO_2026_2_ADAPTADO_PACKAGE_HPP

#include "Product.hpp"

class Package
{
public:
    std::string get_code() const;

    double get_distance() const;

    double get_total_weight() const;

    double get_total_value() const;

    Package();

    virtual ~Package() = default;

    void add_product(const Product& product);

    virtual void read(std::ifstream& );

    virtual void print_products(std::ofstream& ) const;

    virtual double calculate_cost() const = 0;

    virtual bool can_dispatch() const = 0;

    virtual void print_details(std::ofstream& ) const = 0;
private:
    std::string code;
    double distance;
    std::vector<Product> products;
    double total_weight;
    double total_value;
};


#endif //ERASMO_2026_2_ADAPTADO_PACKAGE_HPP
