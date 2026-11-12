//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_ATTENTION_HPP
#define BST_EXERCISE_ATTENTION_HPP

#include "../Utilities/Utils.hpp"
class Attention
{
public:
    Attention();
    virtual ~Attention() = default;
    int get_code() const;
    virtual void read(std::ifstream& );
    virtual void print(std::ofstream& ) const;
    virtual int get_key() const = 0;
    virtual Attention* clone() const = 0;
private:
    int priority;
    int code;
    std::string name;
    std::string description;
};


#endif //BST_EXERCISE_ATTENTION_HPP
