//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_ATTENTION_HPP
#define INC_2026_1_ATTENTION_HPP

#include "../Utilities/Utils.hpp"
class Attention
{
public:

    Attention();
    virtual ~Attention() = default;
    int get_code() const;
    int get_priority() const;
    virtual void read(std::ifstream& );
    virtual void print(std::ofstream& ) const;
    virtual int generate_key() const = 0;
    virtual Attention* clone() const = 0;
private:
    int code;
    std::string patient_name;
    std::string description;
    int priority;
};


#endif //INC_2026_1_ATTENTION_HPP
