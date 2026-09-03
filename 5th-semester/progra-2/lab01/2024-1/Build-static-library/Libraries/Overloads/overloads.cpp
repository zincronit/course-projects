//
// Created by zincronit on 8/30/26.
//

#include "overloads.hpp"

bool operator >>(std::ifstream& fin, struct Book& book)
{
    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    book.code = read_string(fin);
    if (fin.eof()) return false;
    book.title = read_string(fin);
    book.author = read_string(fin);
    book.stock = read_int(fin);
    book.price = read_double(fin);
    return true;
}

bool operator >>(std::ifstream& fin, struct Customer& customer)
{
    // 54393647,Reyes Tang Edward
    customer.dni = read_int(fin);
    if (fin.eof()) return false;
    customer.name = read_string(fin, '\n');
    customer.requested_books = new struct RequestedBook[MAX_ORDERS]{};
    customer.book_count = 0;
    customer.total_payment = 0.0;
    return true;
}

bool operator >>(struct RequestedBook& requested_book, struct Book* books)
{
    for (int i = 0; std::strcmp(books[i].code, "END") != 0; i++)
    {
        if (std::strcmp(books[i].code, requested_book.book_code) == 0)
        {
            if (books[i].stock > 0)
            {
                books[i].stock--;
                requested_book.price = books[i].price;
                requested_book.fulfilled = true;
                return true;
            }
            requested_book.fulfilled = false;
            return false;
        }
    }
    return false;
}

bool operator <<(struct Customer& customer, struct RequestedBook& requested_book)
{
    if (customer.book_count > 30) return false;
    int books_count = customer.book_count;
    customer.requested_books[books_count].order_number = requested_book.order_number;
    customer.requested_books[books_count].book_code = allocate_string(requested_book.book_code);
    customer.requested_books[books_count].price = requested_book.price;
    customer.requested_books[books_count].fulfilled = requested_book.fulfilled;
    customer.book_count++;
    return true;
}

void operator ++(struct Customer& customer)
{
    for (int i = 0; i < customer.book_count; i++)
    {
        if (customer.requested_books[i].fulfilled)
        {
            customer.total_payment += customer.requested_books[i].price;
        }
    }
}

void operator <<(std::ofstream& fout, const struct Book& book)
{
    fout << std::fixed << std::setprecision(2);
    int width = LINE_WIDTH / COLUMNS;
    print_text(fout, book.code, width - 10);
    print_text(fout, book.title, width + 35);
    print_text(fout, book.author, width + 5);
    fout << std::setw(width) << book.stock;
    fout << book.price << std::endl;
}

void operator <<(std::ofstream& fout, const struct Customer& customer)
{
    fout << std::fixed << std::setprecision(2);
    int width = (LINE_WIDTH - 50)/ COLUMNS2;
    fout << std::left << std::setw(12) << customer.dni << customer.name << std::endl;
    fout << "Books Delivered" << std::endl;
    print_header_customer(fout);
    for (int i = 0; i < customer.book_count; i++)
    {
        if (customer.requested_books[i].fulfilled)
        {
            fout << std::right << std::setw(width) << customer.requested_books[i].order_number;
            print_text(fout, customer.requested_books[i].book_code, width, true);
            fout << std::setw(width) << customer.requested_books[i].price << std::endl;
        }
    }
    fout << "Total Payment: " << customer.total_payment << std::endl;
    fout << "Books not Delivered duo to lack of stock" << std::endl;
    print_header_customer(fout, false);
    for (int i = 0; i < customer.book_count; i++)
    {
        if (not customer.requested_books[i].fulfilled)
        {
            fout << std::right << std::setw(width) << customer.requested_books[i].order_number;
            print_text(fout, customer.requested_books[i].book_code, width, true);
        }
    }
    fout << std::endl;
}
