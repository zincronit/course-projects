//
// Created by zincronit on 9/1/26.
//

#include "test.hpp"

void read_book_file(const char* filepath, struct Book*& books)
{
    std::ifstream fin(filepath);
    open_input_file(fin, filepath);
    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    books = new struct Book[MAX_BOOKS]{};
    int book_count = 0;
    while (true)
    {
        bool is_eof = fin >> books[book_count];
        if (is_eof) break;
        book_count++;
    }
    books[book_count].code = allocate_string("END");
    fin.close();
}

void read_customer_file(const char* filepath, struct Customer*& customers)
{
    std::ifstream fin(filepath);
    open_input_file(fin, filepath);
    customers = new struct Customer[MAX_CUSTOMERS]{};
    int customer_count = 0;
    while (true)
    {
        bool is_eof = fin >> customers[customer_count];
        if (is_eof) break;
        customer_count++;
    }

}

