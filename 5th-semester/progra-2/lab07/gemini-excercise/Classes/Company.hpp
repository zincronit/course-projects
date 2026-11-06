//
// Created by zincronit on 11/5/26.
//

#ifndef GEMINI_EXCERCISE_COMPANY_HPP
#define GEMINI_EXCERCISE_COMPANY_HPP

#include "OnlineSale.hpp"
#include "StoreSale.hpp"
#include "Wholesale.hpp"

class Company
{
public:
    Company();

    ~Company();
    int get_num_store() const;

    void set_num_store(const int num_store);

    int get_cap_store() const;

    void set_cap_store(const int cap_store);

    int get_num_online() const;

    void set_num_online(const int num_online);

    int get_num_wholesale() const;

    void set_num_wholesale(const int num_wholesale);

    void load_sales(const char* );

    void append_capacity_store();

    void print_sales(const char*) const;

    void print_headers(std::ofstream& ,const std::string* , int , int) const;
private:
    class StoreSale* store_sales;
    int num_store;
    int cap_store;
    class OnlineSale online_sales[50];
    int num_online;
    class Wholesale wholesales[50];
    int num_wholesale;
};


#endif //GEMINI_EXCERCISE_COMPANY_HPP
