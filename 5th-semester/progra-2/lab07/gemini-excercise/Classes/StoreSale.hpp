//
// Created by zincronit on 11/5/26.
//

#ifndef GEMINI_EXCERCISE_STORESALE_HPP
#define GEMINI_EXCERCISE_STORESALE_HPP

#include "Sale.hpp"

class StoreSale : public Sale
{
public:
    StoreSale();

    StoreSale(const class StoreSale&);

    virtual ~StoreSale();

    int get_cashier_code() const;

    void set_cashier_code(const int cashier_code);

    double get_local_discount() const;

    void set_local_discount(const double local_discount);

    void read_sale(std::ifstream&);

    void print_sale(std::ofstream&) const;

    StoreSale& operator=(const class StoreSale&);

private:
    int cashier_code;
    double local_discount;
};


#endif //GEMINI_EXCERCISE_STORESALE_HPP
