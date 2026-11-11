//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_ATTENTIONMANAGER_HPP
#define INC_2026_1_ATTENTIONMANAGER_HPP

#include "DoubleLinkedList.hpp"
#include "Emergency.hpp"
#include "Urgency.hpp"
#include "NonUrgency.hpp"
class AttentionManager
{
public:
    ~AttentionManager() ;
    void load_attentions(const std::string& );
    void print_attentions(const std::string& ) const;
    void print_emergency(std::ofstream& ) const;
    void print_urgency(std::ofstream& ) const;
    void print_non_urgency(std::ofstream& ) const;

private:
    class DoubleLinkedList priority_attentions;
};


#endif //INC_2026_1_ATTENTIONMANAGER_HPP
