//
// Created by zincronit on 8/30/26.
//

#ifndef BUILD_STATIC_LIBRARY_CUSTOMER_HPP
#define BUILD_STATIC_LIBRARY_CUSTOMER_HPP

#include "RequestedBook.hpp"

struct Customer
{
    int dni;
    char* name;
    struct RequestedBook* requested_books;
    int book_count;
    double total_payment;
};

#endif //BUILD_STATIC_LIBRARY_CUSTOMER_HPP
