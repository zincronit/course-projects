//
// Created by zincronit on 11/11/26.
//

#ifndef INC_2026_1_DOUBLELINKEDLIST_HPP
#define INC_2026_1_DOUBLELINKEDLIST_HPP

#include "DoubleListNode.hpp"

class DoubleLinkedList
{
public:
    DoubleLinkedList();

    ~DoubleLinkedList() ;

    void insert(int, class Attention*);

    void print(std::ofstream& , int) const ;

    void destroy();
private:
    class DoubleListNode* head;

    void insert_sort(class DoubleListNode*&, class DoubleListNode* , class Attention*);
    void print_list(std::ofstream& , class DoubleListNode* , int ) const;
    void delete_node(class DoubleListNode*& );
};


#endif //INC_2026_1_DOUBLELINKEDLIST_HPP
