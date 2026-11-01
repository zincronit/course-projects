//
// Created by zincronit on 10/31/26.
//

#ifndef PALIDROMO_COLA_HPP
#define PALIDROMO_COLA_HPP

struct ElementoCola {
    char letra;
};

struct NodoCola {
    struct ElementoCola elemento;
    NodoCola * siguiente;
};

struct Cola {
    struct NodoCola * inicio;
    struct NodoCola * fin;
    int longitud;
};

#endif //PALIDROMO_COLA_HPP
