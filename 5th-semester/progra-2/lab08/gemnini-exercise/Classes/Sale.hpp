//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_SALE_HPP
#define GEMNINI_EXERCISE_SALE_HPP

#include "../Utilities/Utils.hpp"
#include "List/DoubleList.hpp"
class Sale
{
public:
    Sale();
    ~Sale();
    void get_chronological_key() const;
    
private:
    std::string code;
    std::string date;
    class DoubleList details;
};


#endif //GEMNINI_EXERCISE_SALE_HPP
