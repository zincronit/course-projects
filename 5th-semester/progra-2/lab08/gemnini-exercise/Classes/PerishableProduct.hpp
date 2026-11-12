//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_PERISHABLEPRODUCT_HPP
#define GEMNINI_EXERCISE_PERISHABLEPRODUCT_HPP

#include "Product.hpp"
class PerishableProduct : public Product
{
public:
    PerishableProduct();
    ~PerishableProduct() override;
    int get_priority() const override;
    std::string get_type_name() const override;
    Product* clone() const override;
    void read(std::ifstream& ) override;
    void print(std::ofstream& ) override;
private:
    int shelf_life_days;
    bool requires_cold_chain;
};


#endif //GEMNINI_EXERCISE_PERISHABLEPRODUCT_HPP
