//
// Created by zincronit on 11/12/26.
//

#include "SaleDetail.hpp"
int SaleDetail::get_quantity() const { return quantity; }

SaleDetail::SaleDetail()
{
    product = nullptr;
    units_per_pack = 0;
    quantity = 0;
}

SaleDetail::~SaleDetail() { delete product; }

int SaleDetail::get_dispatch_key() const
{
    int product_number = Utils::get_number(product->get_code());
    return product->get_priority() * 10000 + product_number;
}

void SaleDetail::add_quantity(int extra_quantity)
{
    quantity += extra_quantity;
}

SaleDetail& SaleDetail::operator=(const class SaleDetail& other)
{
    if (this == &other) return *this;
    product = other.product->clone();
    units_per_pack = other.units_per_pack;
    quantity = other.quantity;
    return *this;
}
