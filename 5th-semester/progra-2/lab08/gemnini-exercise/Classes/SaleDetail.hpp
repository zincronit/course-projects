//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_SALEDETAIL_HPP
#define GEMNINI_EXERCISE_SALEDETAIL_HPP

#include "Product.hpp"
class SaleDetail
{
public:
    int get_quantity() const;
    SaleDetail();
    ~SaleDetail() ;
    int get_dispatch_key() const;
    void add_quantity(int );
    SaleDetail& operator = (const class SaleDetail& );
private:
    class Product* product;
    int units_per_pack;
    int quantity;
};


#endif //GEMNINI_EXERCISE_SALEDETAIL_HPP
