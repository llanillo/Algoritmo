#ifndef ALGORITMO_FILA_H
#define ALGORITMO_FILA_H

#endif //ALGORITMO_FILA_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
const int Indefinido = -999;

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
    if(!EsFilaVacia(Fila)){
        return Fila.Frente->Dato;
    }
    return Indefinido;
}

Fila Enfila(Fila Fila, Item Objeto){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(Nodo));
    Auxiliar->Dato = Objeto;

    if(EsFilaVacia(Fila)){
        Auxiliar->Siguiente = NULL;
        Fila.Frente = Auxiliar;
        Fila.Final = Fila.Frente;
        return Fila;
    }
    else{
        Auxiliar->Siguiente = Fila.Final;
        Fila.Final = Auxiliar;
        return Fila;
    }
}

Fila Defila(Fila TFila){

}