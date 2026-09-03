//
// Created by zincronit on 8/30/26.
//


#include "Libraries/Test-overloads/test.hpp"

int main()
{
    struct Book* books;
    int book_count = 0;
    read_book_file("../Files/Data/books.csv", books, book_count);

    struct Customer* customers;
    int customer_count = 0;
    read_customer_file("../Files/Data/customers.csv", customers, customer_count);

    struct RequestedBook requested_books[4]{};
    requested_books[0].book_code = allocate_string("JZC7527");
    requested_books[1].book_code = allocate_string("CST1133");
    requested_books[2].book_code = allocate_string("KSX7995");
    requested_books[3].book_code = allocate_string("DVR5984");


    for (int i = 0 ; i < 4 ; i++)
    {
        requested_books[i].order_number = 35;
        requested_books[i] >> books;
        customers[1] << requested_books[i];
    }
    ++customers[1];

    std::ofstream fout;
    open_output_file(fout, "../Files/Reports/test.txt");
    for (int i  = 0 ; i < book_count ; i++)
    {
        fout << books[i];
    }
    fout << customers[1];


    return 0;
}
