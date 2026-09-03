//
// Created by zincronit on 9/2/26.
//

#ifndef USING_STATIC_LIBRARY_REPORTPROCESSORS_HPP
#define USING_STATIC_LIBRARY_REPORTPROCESSORS_HPP

#include "../Overloads/overloads.hpp"

void read_book_file(const char* filepath, struct Book*& books, int& book_count);

void read_customer_file(const char* filepath, struct Customer*& customers, int& customer_count);

void read_order_file(const char* filepath,
                     struct Book* books,
                     struct Customer* customers,
                     int customer_count);

int find_customer_index(struct Customer* customers, int count, int dni);

void assign_customer_book(std::ifstream& fin,
                          struct Customer* customers,
                          struct Book* books,
                          int index,
                          int order);

void print_book_report(const char* filepath,
                       const struct Book* books,
                       int book_count);

void print_customer_report(const char* filepath,
                           const struct Customer* customers,
                           int customer_count);

#endif //USING_STATIC_LIBRARY_REPORTPROCESSORS_HPP
