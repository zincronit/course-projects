//
// Created by zincronit on 11/5/26.
//

#ifndef GEMINI_EXCERCISE_SALE_HPP
#define GEMINI_EXCERCISE_SALE_HPP

#include "../Utilities/Utils.hpp"
class Sale
{
public:
    Sale();

    virtual ~Sale() = default;

    std::string get_code() const;

    void set_code(const std::string& code);

    std::string get_date() const;

    void set_date(const std::string& date);

    std::string get_client_id() const;

    void set_client_id(const std::string& client_id);

    double get_base_amount() const;

    void set_base_amount(const double base_amount);

    void read_sale(std::ifstream& );

    void print_sale(std::ofstream& ) const;
private:
    std::string code;
    std::string date;
    std::string client_id;
    double base_amount;
};


#endif //GEMINI_EXCERCISE_SALE_HPP
