//
// Created by zincronit on 11/16/26.
//

#ifndef ERASMO_2026_2_ADAPTADO_STANDARDPACKAGE_HPP
#define ERASMO_2026_2_ADAPTADO_STANDARDPACKAGE_HPP

#include "Package.hpp"
class StandardPackage : public Package
{
public:
    StandardPackage();
    ~StandardPackage() override ;
    bool is_urgent() const;
    void read(std::ifstream&) override;
    double calculate_cost() const override;
    bool can_dispatch() const override;
    void print_details(std::ofstream&) const override;
private: bool urgent;
};


#endif //ERASMO_2026_2_ADAPTADO_STANDARDPACKAGE_HPP
