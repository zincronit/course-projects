//
// Created by zincronit on 9/23/26.
//

#include "Utils/Functions.hpp"

int main()
{
    struct List deck;
    initialize_list(deck);
    build_deck(deck);
    print_list(deck);
    std::cout << deck.size << std::endl;
    extract_in_position(deck, 2);
    print_list(deck);
    std::cout << std::endl;
    shuffle(deck);
    shuffle(deck);
    shuffle(deck);
    print_list(deck);
    std::cout << std::endl;
    destroy_deck(deck);
    print_list(deck);
    return 0;
}