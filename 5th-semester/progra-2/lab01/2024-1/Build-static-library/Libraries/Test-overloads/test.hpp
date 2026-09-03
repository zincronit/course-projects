//
// Created by zincronit on 9/1/26.
//

#ifndef BUILD_STATIC_LIBRARY_TEST_HPP
#define BUILD_STATIC_LIBRARY_TEST_HPP

#include "../Overloads/overloads.hpp"

void read_book_file(const char* filepath, struct Book*& books, int& book_count);

void read_customer_file(const char* filepath, struct Customer*& customers, int& customer_count);

void read_order_file(const char* filepath,
                     struct Book* books,
                     struct Customer* customers);


#endif //BUILD_STATIC_LIBRARY_TEST_HPP
