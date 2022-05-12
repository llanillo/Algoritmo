#ifndef ALGORITMO_FILA_H
#define ALGORITMO_FILA_H

#endif //ALGORITMO_FILA_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
const int Indefinido = -9999;

typedef struct Nodo{
    struct Nodo* Siguiente;
    Item Dato;
} Nodo;

typedef struct Fila{
    struct Nodo* Frente;
    struct Nodo* Final;
    int Longitud;
} Fila;

Fila FilaVacia(){
    Fila Temporal;
    Temporal.Frente = NULL;
    Temporal.Final = NULL;
    Temporal.Longitud = 0;
    return Temporal;
}

bool EsFilaVacia(Fila TFila){
    return TFila.Final && TFila.Frente;
}

Item Frente(Fila Fila){
    return !EsFilaVacia(Fila) ? Fila.Frente->Dato : Indefinido;
}

Fila Enfila(Fila Fila, Item Objeto){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(Nodo));
    Auxiliar->Dato = Objeto;
    Auxiliar->Siguiente = NULL;

    if(EsFilaVacia(Fila)){
        Fila.Frente = Auxiliar;
        Fila.Final = Auxiliar;
    }
    else{
        Fila.Final->Siguiente = Auxiliar;
        Fila.Final = Auxiliar;
    }
    return Fila;
}

Fila Defila(Fila Fila){
    if(!EsFilaVacia(Fila)){
        Nodo* Auxiliar = Fila.Frente;

        if(Fila.Frente == Fila.Final){
            Fila.Frente = NULL;
            Fila.Final = NULL;
            free(Auxiliar);
        }
        else{
            Fila.Frente = Fila.Frente->Siguiente;
            free(Auxiliar);
        }
    }

    return Fila;
}

