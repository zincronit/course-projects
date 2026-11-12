//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_CHEMICALPRODUCT_HPP
#define GEMNINI_EXERCISE_CHEMICALPRODUCT_HPP

#include "Product.hpp"
class ChemicalProduct : public Product
{
public:
    ChemicalProduct();
    ~ChemicalProduct() override;
    int get_priority() const override;
    std::string get_type_name() const override;
    Product* clone() const override;
    void read(std::ifstream& ) override;
    void print(std::ofstream& ) override;

private:
    std::string hazard_code;
    bool is_concentrate;

};


#endif //GEMNINI_EXERCISE_CHEMICALPRODUCT_HPP
