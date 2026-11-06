//
// Created by zincronit on 11/5/26.
//

#include "StoreSale.hpp"
StoreSale::StoreSale()
{
    cashier_code = 0;
    local_discount = 0.0;
}
int StoreSale::get_cashier_code() const { return cashier_code; }
void StoreSale::set_cashier_code(const int cashier_code) { this->cashier_code = cashier_code; }
double StoreSale::get_local_discount() const { return local_discount; }
void StoreSale::set_local_discount(const double local_discount) { this->local_discount = local_discount; }
void StoreSale::read_sale(std::ifstream& input)
{
    Sale::read_sale(input);
    cashier_code = Utils::read_int(input);
    local_discount = Utils::read_double(input);
}

void StoreSale::print_sale(std::ofstream& output) const
{
    Sale::print_sale(output);
    output << std::fixed << std::setprecision(2);
    output << Sale::get_base_amount() - local_discount;
    output << std::endl;
}
