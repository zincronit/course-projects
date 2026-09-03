//
// Created by zincronit on 9/1/26.
//

#include "test.hpp"

void read_book_file(const char* filepath, struct Book*& books, int& book_count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    books = new struct Book[MAX_BOOKS]{};
    while (true)
    {
        bool  can_read= fin >> books[book_count];
        if (not can_read) break;
        book_count++;
    }
    books[book_count].code = allocate_string("END");
    fin.close();
}

void read_customer_file(const char* filepath, struct Customer*& customers, int& customer_count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    customers = new struct Customer[MAX_CUSTOMERS]{};
    while (true)
    {
        bool can_read = fin >> customers[customer_count];
        if (not can_read) break;
        customer_count++;
    }
    fin.close();
}