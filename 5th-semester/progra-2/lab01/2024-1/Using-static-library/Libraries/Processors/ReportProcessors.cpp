//
// Created by zincronit on 9/2/26.
//

#include "ReportProcessors.hpp"


void read_book_file(const char* filepath, struct Book*& books, int& book_count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    books = new struct Book[MAX_BOOKS]{};
    while (true)
    {
        bool can_read = fin >> books[book_count];
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

void read_order_file(const char* filepath,
                     struct Book* books,
                     struct Customer* customers,
                     int customer_count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int order, dni;
    while (true)
    {
        // 000001,34460612,  CRY6839    VYG3594
        order = read_int(fin);
        if (fin.eof()) break;
        dni = read_int(fin);
        int index = find_customer_index(customers, customer_count, dni);
        assign_customer_book(fin, customers, books, index, order);
    }
    for (int i = 0; i < customer_count; i++) ++customers[i];
    fin.close();
}

int find_customer_index(struct Customer* customers, int count, int dni)
{
    for (int i = 0; i < count; i++)
    {
        if (dni == customers[i].dni) return i;
    }
    return NOT_FOUND;
}

void assign_customer_book(std::ifstream& fin,
                          struct Customer* customers,
                          struct Book* books,
                          int index,
                          int order)
{
    while (true)
    {
        struct RequestedBook requested_book{};
        char buffer[TEXT_LENGTH]{};
        fin >> buffer;
        requested_book.book_code = allocate_string(buffer);
        requested_book.order_number = order;
        if (index == NOT_FOUND)
        {
            fin.ignore(200, '\n');
            continue;
        }
        requested_book >> books;
        customers[index] << requested_book;
        if (fin.get() == '\n') break;
    }
}

void print_book_report(const char* filepath,
                       const struct Book* books,
                       int book_count)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    print_title(fout, "Book report", LINE_WIDTH);
    for (int i = 0; i < book_count; i++) fout << books[i];
    fout.close();
}

void print_customer_report(const char* filepath,
                           const struct Customer* customers,
                           int customer_count)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    print_title(fout , "Customer report", LINE_WIDTH - 50);
    for ( int i = 0; i < customer_count ; i ++) fout << customers[i];
    fout.close();
}