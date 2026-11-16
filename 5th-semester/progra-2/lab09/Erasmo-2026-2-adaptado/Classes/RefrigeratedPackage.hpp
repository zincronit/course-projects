//
// Created by zincronit on 11/16/26.
//

#ifndef ERASMO_2026_2_ADAPTADO_REFRIGERATEDPACKAGE_HPP
#define ERASMO_2026_2_ADAPTADO_REFRIGERATEDPACKAGE_HPP

#include "Package.hpp"
class RefrigeratedPackage : public Package
{
public:
    RefrigeratedPackage();
    ~RefrigeratedPackage() override = default;
    void read(std::ifstream&) override;
    void print_products(std::ofstream&) const override;
    double calculate_cost() const override;
    bool can_dispatch() const override;
    void print_details(std::ofstream&) const override;
private:
    double tempeture;
};


#endif //ERASMO_2026_2_ADAPTADO_REFRIGERATEDPACKAGE_HPP
