//
// Created by zincronit on 8/30/26.
//

#ifndef BUILD_STATIC_LIBRARY_REQUESTEDBOOK_HPP
#define BUILD_STATIC_LIBRARY_REQUESTEDBOOK_HPP

struct RequestedBook
{
    int order_number;
    char* book_code;
    double price;
    bool fulfilled;
};

#endif //BUILD_STATIC_LIBRARY_REQUESTEDBOOK_HPP
