//
// Created by zincronit on 11/5/26.
//

#include "Sale.hpp"

Sale::Sale()
{
    code = "";
    date = "";
    client_id = "";
    base_amount = 0.0;
}

std::string Sale::get_code() const { return code; }
void Sale::set_code(const std::string& code) { this->code = code; }
std::string Sale::get_date() const { return date; }
void Sale::set_date(const std::string& date) { this->date = date; }
std::string Sale::get_client_id() const { return client_id; }
void Sale::set_client_id(const std::string& client_id) { this->client_id = client_id; }
double Sale::get_base_amount() const { return base_amount; }
void Sale::set_base_amount(const double base_amount) { this->base_amount = base_amount; }
void Sale::read_sale(std::ifstream& input)
{
    std::getline(input, code , ',');
    std::getline(input , date, ',');
    std::getline(input , client_id, ',');
    base_amount = Utils::read_double(input);
}

void Sale::print_sale(std::ofstream& output) const
{
    int width = LINE_WIDTH/5;
    Utils::print_text(output, code , width);
    Utils::print_text(output, date , width);
    Utils::print_text(output, client_id , width);
}