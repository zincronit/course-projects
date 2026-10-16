//
// Created by zincronit on 10/14/26.
//

#include "Utils/Functions.hpp"


void order_list(struct List& list)
{
    struct Node* head_A = nullptr;
    struct Node* tail_A = nullptr;
    struct Node* head_B = nullptr;
    struct Node* tail_B = nullptr;
    struct Node* head_C = nullptr;
    struct Node* tail_C = nullptr;

    struct Node* current = list.head;
    if (is_empty_list(list) or list.head->next == nullptr) return;
    while (current != nullptr)
    {
        struct Node* temp = current->next;
        current->next = nullptr;
        if (current->data.type == 'A')
        {
            if (head_A == nullptr)
            {
                head_A = current;
                tail_A = current;
            } else
            {
                tail_A->next = current;
                tail_A = current;
            }
        } else if (current->data.type == 'B')
        {
            if (head_B == nullptr)
            {
                head_B = current;
                tail_B = current;
            } else
            {
                tail_B->next = current;
                tail_B = current;
            }
        } else if (current->data.type == 'C')
        {
            if (head_C == nullptr)
            {
                head_C = current;
                tail_C = current;
            } else
            {
                tail_C->next = current;
                tail_C = current;
            }
        }
        current = temp;
    }

    struct Node* new_head = nullptr;
    struct Node* new_tail = nullptr;

    while (head_A != nullptr or head_B != nullptr or head_C != nullptr)
    {
        if (head_A != nullptr)
        {
            Node* target = head_A->next;
            head_A->next = nullptr;
            if (new_head == nullptr)
            {
                new_head = head_A;
                new_tail = head_A;
            } else
            {
                new_tail->next = head_A;
                new_tail = head_A;
            }
            head_A = target;
        }
        if (head_B != nullptr)
        {
            Node* target = head_B->next;
            head_B->next = nullptr;
            if (new_head == nullptr)
            {
                new_head = head_B;
                new_tail = head_B;
            } else
            {
                new_tail->next = head_B;
                new_tail = head_B;
            }
            head_B = target;
        }
        if (head_C != nullptr)
        {
            Node* target = head_C->next;
            head_C->next = nullptr;
            if (new_head == nullptr)
            {
                new_head = head_C;
                new_tail = head_C;
            } else
            {
                new_tail->next = head_C;
                new_tail = head_C;
            }
            head_C = target;
        }
    }
    list.head = new_head;
}


int main()
{
    struct List list;

    initialize_list(list);

    insert_back(list, {7, 'B'});
    insert_back(list, {2, 'A'});
    insert_back(list, {9, 'C'});
    insert_back(list, {5, 'A'});
    insert_back(list, {6, 'B'});
    // insert_back(list, {7, 'B'});
    print_list(list);
    std::cout << std::endl;
    order_list(list);
    print_list(list);
}
