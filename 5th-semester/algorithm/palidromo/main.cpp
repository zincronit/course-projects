//
// Created by zincronit on 10/31/26.
//

#include "BibliotecaCola/funcionesCola.hpp"
#include "BibliotecaCola/Cola.hpp"
#include <cstring>

bool validarPlalidromo(struct Cola &cola) {
    // si la palabra es de long 1 es palidromo
    if (esColaVacia(cola)) return false;
    if (cola.longitud == 1) return true;
    while (not esColaVacia(cola)) {
        // para detener el bucle
        if (cola.longitud == 1) break;
        // deseconlor y hago un for para encontrar la ultima letra
        struct ElementoCola letra = desencolar(cola);
        for (int i = 0; i < cola.longitud - 1; i++) {
            // desencolo y vuelvo a encolar
            struct ElementoCola aux = desencolar(cola);
            encolar(cola, aux);
        }
        // desencolo la ultima letra y comparo
        struct ElementoCola aux1 = desencolar(cola);
        if (aux1.letra != letra.letra) return false;
        //el proceso se vuelve a repetir
    }
    return true;
}

int main() {
    struct Cola cola;
    construir(cola);
    cout << "ingrese la palabra " << std::endl;
    char palabra[100] ={'\0'};
    cin >> palabra;
    // const char *palabra = "RECONOCER";

    for (int i = 0; palabra[i] != '\0' ; i++) {
        encolar(cola, {palabra[i]});
    }
    imprimir(cola);

    if (validarPlalidromo(cola)) {
        std::cout << "es palidromo" << std::endl;
    } else {
        std::cout << "No palidromo" << std::endl;
    }


    return 0;
}