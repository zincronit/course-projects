//
// Created by zincronit on 10/8/26.
//

#include "Utils/Functions.hpp"

int main()
{
    int random_number, number;
    struct List list1, list2;
    build_list(list2);
    build_list(list1);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < 15; i++)
    {
        // random_number = 1 + std::rand() % 20;
        insert_sorted(list1, 1 + std::rand() % 20);
        insert_sorted(list2, 1 + std::rand() % 20);
    }

    print_list(list1);

    // Node* current =get_last_node(list1);
    // current->next = list1.head->next;

    // Node* entry =detect_cycle(list1);

    // std::cout << entry->data << std::endl;

    // list1.head = reverse_list_recursive(list1.head);
    // print_list(list1);
    // std::cout << std::endl;
    // print_list(list2);
    // list2.head = reverse_list_iterative(list2.head);
    // print_list(list2);


    return 0;
}
