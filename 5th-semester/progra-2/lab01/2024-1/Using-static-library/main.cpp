//
// created by zincronit on 9/02/26.
//

#include "Libraries/Processors/ReportProcessors.hpp"

int main()
{
    struct Book* books;
    int book_count = 0;

    read_book_file(
        "../Files/Data/books.csv",
        books,
        book_count
    );
    print_book_report(
        "../Files/Reports/first_book_report.txt",
        books,
        book_count
    );
    struct Customer* customers;
    int customer_count = 0;
    read_customer_file(
        "../Files/Data/customers.csv",
        customers,
        customer_count
    );

    read_order_file(
        "../Files/Data/orders.txt",
        books,
        customers,
        customer_count
    );
    print_customer_report(
        "../Files/Reports/customer_report.txt",
        customers,
        customer_count
    );
    print_book_report(
        "../Files/Reports/final_book_report.txt",
        books,
        book_count
    );
    return 0;
}
