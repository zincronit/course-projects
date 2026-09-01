//
// Created by zincronit on 8/30/26.
//


#include "Libraries/Test-overloads/test.hpp"

int main () {
    struct Book* books;
    read_book_file("../Files/Data/books.csv", books);

    struct Customer* customers;
    read_customer_file("../Files/Data/customers.csv", customers);
    return 0;
}
