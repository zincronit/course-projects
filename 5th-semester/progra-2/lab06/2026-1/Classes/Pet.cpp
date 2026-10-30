//
// Created by zincronit on 10/29/26.
//

#include "Pet.hpp"
Pet::Pet()
{
    code = 0;
    name = "";
    type = '\0';
}

Pet::~Pet() {};

int Pet::get_code() const { return code; }
void Pet::set_code(const int code) { this->code = code; }
std::string Pet::get_name() const { return name; }
void Pet::set_name(const std::string& name) { this->name = name; }
char Pet::get_type() const { return type; }
void Pet::set_type(const char type) { this->type = type; }
std::string Pet::get_breed() const { return breed; }
