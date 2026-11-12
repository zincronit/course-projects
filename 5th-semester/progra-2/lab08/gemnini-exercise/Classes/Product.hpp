//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_PRODUCT_HPP
#define GEMNINI_EXERCISE_PRODUCT_HPP

#include "../Utilities/Utils.hpp"
class Product
{
public:
    Product ();
    virtual ~Product () = default;
    virtual int get_priority() const = 0;
    virtual std::string get_type_name() const = 0;
    virtual Product* clone() const = 0;
    virtual void read(std::ifstream& );
    virtual void print(std::ofstream& );
    std::string get_code() const;
private:
    std::string code;
    std::string description;
    std::string category;
    double unit_cost;
    double unit_price;
};


#endif //GEMNINI_EXERCISE_PRODUCT_HPP
