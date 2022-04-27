#ifndef ALGORITMO_PILA_H
#define ALGORITMO_PILA_H

#endif //ALGORITMO_PILA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Item;
const int Indefinido = -9999;
typedef struct Nodo{
    Item Dato;
    struct Nodo* Siguiente;
} Nodo;

typedef struct Pila{
    int Altura;
    struct Nodo* Siguiente;
} Pila;
typedef Pila* Pilas;

Pilas PilvaVacia(){
    Pilas Auxiliar = (Pilas) malloc(sizeof(struct Pila));
    Auxiliar->Altura = 0;
    Auxiliar->Siguiente = NULL;
    return Auxiliar;
}

bool EsPilaVacia(Pilas Cabecera){
    return Cabecera->Siguiente == NULL;
}

Item Top(Pilas Cabecera){
    if(EsPilaVacia(Cabecera)){
        return Indefinido;
    }
    else{
        return Cabecera->Siguiente->Dato;
    }
}

Pilas Pop(Pilas Cabecera){
    if(EsPilaVacia(Cabecera)){
        return NULL;
    }
    else{
        Nodo* Auxiliar = Cabecera->Siguiente;
        Cabecera->Siguiente = Cabecera->Siguiente->Siguiente;
        Cabecera->Altura--;
        free(Auxiliar);
        return Cabecera;
    }
}

Pilas Push(Pilas Cabecera, Item Dato){
    if(EsPilaVacia(Cabecera)){
        return NULL;
    }
    else{
        Nodo* Auxiliar = (Nodo*) malloc(sizeof(Nodo));
        Auxiliar->Siguiente = Cabecera->Siguiente;
        Auxiliar->Dato = Dato;
        Cabecera->Siguiente = Auxiliar;
        Cabecera->Altura++;
        return Cabecera;
    }
}