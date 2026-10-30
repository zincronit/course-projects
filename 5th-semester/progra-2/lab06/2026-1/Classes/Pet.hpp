//
// Created by zincronit on 10/29/26.
//

#ifndef INC_2026_1_PET_HPP
#define INC_2026_1_PET_HPP

#include "../Utilities/Utils.hpp"

class Pet
{
public:

    Pet();

    ~Pet();

    int get_code() const;

    void set_code(const int code);

    std::string get_name() const;

    void set_name(const std::string& name);

    char get_type() const;

    void set_type(const char type);

    std::string get_breed() const;
private:
    int code;
    std::string name;
    char type;
    std::string breed;
};


#endif //INC_2026_1_PET_HPP
