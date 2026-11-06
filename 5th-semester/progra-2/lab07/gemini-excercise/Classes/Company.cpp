//
// Created by zincronit on 11/5/26.
//

#include "Company.hpp"
Company::Company()
{
    store_sales = nullptr;
    num_store = 0;
    cap_store = 0;
    num_online = 0;
    num_wholesale = 0;
}

Company::~Company()
{
    delete[] store_sales;
}
int Company::get_num_store() const { return num_store; }
void Company::set_num_store(const int num_store) { this->num_store = num_store; }
int Company::get_cap_store() const { return cap_store; }
void Company::set_cap_store(const int cap_store) { this->cap_store = cap_store; }
int Company::get_num_online() const { return num_online; }
void Company::set_num_online(const int num_online) { this->num_online = num_online; }
int Company::get_num_wholesale() const { return num_wholesale; }
void Company::set_num_wholesale(const int num_wholesale) { this->num_wholesale = num_wholesale; }

void Company::load_sales(const char* filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char type;
    while (true)
    {
        input.get(type);
        if (input.eof()) break;
        input.ignore();
        if (type == 'T')
        {
            if (num_store >= cap_store - 1)
                append_capacity_store();
            store_sales[num_store++].read_sale(input);
        }
        else if (type == 'O')
            online_sales[num_online++].read_sale(input);
        else if (type == 'M')
            wholesales[num_wholesale++].read_sale(input);
    }
    input.close();
}

void Company::append_capacity_store()
{
    cap_store += INCREASE;
    class StoreSale* aux = new StoreSale[cap_store];
    if (cap_store == INCREASE)
    {
        store_sales = aux;
        return;
    }
    for (int i = 0; i < num_store; i++)
        aux[i] = store_sales[i];
    delete[] store_sales;
    store_sales = aux;
}

void Company::print_sales(const char* filepath) const
{
    std::ofstream output;
    Utils::open_output_file(output, filepath);
    int width = LINE_WIDTH/5;
    const std::string title= "PACKMART SALES REPORT\n";
    Utils::print_line(output);
    Utils::print_text(output , title , (LINE_WIDTH + title.length())/2, true);
    Utils::print_line(output);
    output << "STORE SALES: " << std::endl;
    std::string store_headers[]= {"Code" , "Date" , "Client ID" , "Final Amount"};
    print_headers(output, store_headers, width, 4);
    for (int i = 0 ; i < num_store ; i++)
        store_sales[i].print_sale(output);
    output << "\nONLINE SALES: \n";
    std::string online_headers[]= {"Code" , "Date" , "Client ID", "City" , "Final Amount"};
    print_headers(output, online_headers, width, 5);
    for (int i = 0 ; i < num_online ; i++)
        online_sales[i].print_sale(output);
    output << "\nWHOLESALE SALES: \n";
    std::string wholesale_headers[]= {"Code" , "Date" , "Client ID", "Tax ID" , "Final Amount"};
    print_headers(output, wholesale_headers, width, 5);
    for (int i = 0 ; i < num_wholesale ; i++)
        wholesales[i].print_sale(output);
    output.close();
}

void Company::print_headers(std::ofstream& output , const std::string* headers, int width, int size) const
{
    for (int i = 0 ; i < size ; i++)
        Utils::print_text(output, headers[i] , width);
    output << std::endl;
}