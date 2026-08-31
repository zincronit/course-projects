//
// Created by zincronit on 8/30/26.
//

#ifndef BUILD_STATIC_LIBRARY_OVERLOADS_HPP
#define BUILD_STATIC_LIBRARY_OVERLOADS_HPP

#include "../Utils/Functions.hpp"
#include "../Structs/Book.hpp"
#include "../Structs/Customer.hpp"
#include "../Structs/RequestedBook.hpp"

bool operator >>(std::ifstream& fin, struct Book& book);

bool operator >>(std::ifstream& fin, struct Customer& customer);

bool operator >>(struct RequestedBook& requested_book, struct Book* books);

bool operator <<(struct Customer& customer, struct RequestedBook& requested_book);

void operator ++(struct Customer& customer);

void operator <<(std::ofstream& fout, const struct Book& book);

void operator <<(std::ofstream& fout, const struct Customer& customer);

#endif //BUILD_STATIC_LIBRARY_OVERLOADS_HPP
