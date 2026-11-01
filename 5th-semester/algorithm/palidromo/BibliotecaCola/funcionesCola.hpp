//
// Created by zincronit on 10/31/26.
//

#ifndef PALIDROMO_FUNCIONESCOLA_HPP
#define PALIDROMO_FUNCIONESCOLA_HPP

#include <iostream>
#include "Cola.hpp"

using namespace std;

void construir(struct Cola & colaTAD);
void encolar(struct Cola &cola, const struct ElementoCola &colaTAD);
struct ElementoCola desencolar(struct Cola & colaTAD);
bool esColaVacia(const struct Cola & colaTAD);
void imprimir(const struct Cola & colaTAD);


#endif //PALIDROMO_FUNCIONESCOLA_HPP
