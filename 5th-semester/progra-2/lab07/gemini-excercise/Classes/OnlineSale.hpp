//
// Created by zincronit on 11/5/26.
//

#ifndef GEMINI_EXCERCISE_ONLINESALE_HPP
#define GEMINI_EXCERCISE_ONLINESALE_HPP

#include "Sale.hpp"
class OnlineSale: public Sale
{
public:
    OnlineSale();

    OnlineSale(const OnlineSale&);

    virtual ~OnlineSale();

    std::string get_shipping_city() const;

    void set_shipping_city(const std::string& shipping_city);

    double get_shipping_cost() const;

    void set_shipping_cost(const double shipping_cost);

    void read_sale(std::ifstream& );

    void print_sale(std::ofstream& ) const;

    OnlineSale& operator=(const OnlineSale&);
private:
    std::string shipping_city;
    double shipping_cost;
};


#endif //GEMINI_EXCERCISE_ONLINESALE_HPP
