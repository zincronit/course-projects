//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_GENERALPRODUCT_HPP
#define GEMNINI_EXERCISE_GENERALPRODUCT_HPP

#include "Product.hpp"
class GeneralProduct : public Product
{
public:
    GeneralProduct();
    ~GeneralProduct() override;
    int get_priority() const override;
    std::string get_type_name() const override;
    Product* clone() const override;
    void read(std::ifstream& ) override;
    void print(std::ofstream& ) override;

private:
    int warranty_months;
    bool fragile_flag;
};


#endif //GEMNINI_EXERCISE_GENERALPRODUCT_HPP
