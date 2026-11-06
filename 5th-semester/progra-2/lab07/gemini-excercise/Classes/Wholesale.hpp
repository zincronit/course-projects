//
// Created by zincronit on 11/5/26.
//

#ifndef GEMINI_EXCERCISE_WHOLESALE_HPP
#define GEMINI_EXCERCISE_WHOLESALE_HPP

#include "Sale.hpp"
class Wholesale : public Sale
{
public:
    Wholesale();

    Wholesale(const Wholesale&);

    virtual ~Wholesale() ;

    std::string get_tax_id() const;

    void set_tax_id(const std::string& tax_id);

    double get_volume_discount() const;

    void set_volume_discount(const double volume_discount);

    void read_sale(std::ifstream& );

    void print_sale(std::ofstream& ) const;

    Wholesale& operator=(const Wholesale&);
private:
    std::string tax_id;
    double volume_discount;
};

#endif //GEMINI_EXCERCISE_WHOLESALE_HPP
