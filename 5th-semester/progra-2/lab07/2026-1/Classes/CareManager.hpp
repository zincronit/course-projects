//
// Created by zincronit on 11/7/26.
//

#ifndef INC_2026_1_CAREMANAGER_HPP
#define INC_2026_1_CAREMANAGER_HPP

#include "Attention.hpp"
#include "Emergency.hpp"
#include "NotUrgent.hpp"
#include "Urgency.hpp"

class CareManager
{
public:
    CareManager();

    ~CareManager();

    int get_count() const;

    void set_count(const int count);

    int get_capacity() const;

    void set_capacity(const int capacity);

    void append_attention_capacity();

    void append_attention(class Attention* );

    class Attention* allocate_attention_memory(const char );

    void load_attentions(const std::string& ,const int  );

    void process_day(const std::string& );

    void generate_report(const std::string& ) const ;
private:
    class Attention** attentions;
    int count;
    int capacity;
};



#endif //INC_2026_1_CAREMANAGER_HPP
