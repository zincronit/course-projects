//
// Created by zincronit on 11/7/26.
//

#ifndef INC_2026_1_URGENCY_HPP
#define INC_2026_1_URGENCY_HPP

#include "Attention.hpp"
class Urgency : public Attention
{
public:
    Urgency();

    Urgency& operator=(const class Urgency& );

    virtual ~Urgency() = default;

    std::string get_injury_zone() const;

    void set_injury_zone(const std::string& injury_zone);

    bool is_requires_xray() const;

    void set_requires_xray(const bool requires_xray);

    void read(std::ifstream& , const int);

    void print(std::ofstream& ) const;

    int get_priority();
private:
    std::string injury_zone;
    bool requires_xray;
};


#endif //INC_2026_1_URGENCY_HPP
