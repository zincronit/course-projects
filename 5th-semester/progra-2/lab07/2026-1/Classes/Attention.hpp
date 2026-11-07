//
// Created by zincronit on 11/7/26.
//

#ifndef INC_2026_1_ATTENTION_HPP
#define INC_2026_1_ATTENTION_HPP

#include "../Utilities/Utils.hpp"

class Attention
{
public:
    Attention();

    Attention(const class Attention& );

    virtual Attention& operator=(const class Attention& );

    virtual ~Attention() = default;

    int get_code() const;

    void set_code(const int code);

    std::string get_patient() const;

    void set_patient(const std::string& patient);

    std::string get_description() const;

    void set_description(const std::string& description);

    int get_hour() const;

    void set_hour(const int hour);

    virtual void read(std::ifstream& , const int );

    virtual void print(std::ofstream& ) const;

    virtual int get_priority() = 0;

private:
    int code;
    std::string patient;
    std::string description;
    int hour;
};


#endif //INC_2026_1_ATTENTION_HPP
