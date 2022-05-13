#ifndef ALGORITMO_FILA_H
#define ALGORITMO_FILA_H

#endif //ALGORITMO_FILA_H

#include <stdio.h>
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
    return TFila.Final == NULL && TFila.Frente == NULL;
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
    
    Fila.Longitud--;
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

    Fila.Longitud++;
    return Fila;
}

void MostrarFila(Fila TFila){
    while(!EsFilaVacia(TFila)){
        printf("%d -> ", Frente(TFila));
        if(TFila.Frente != TFila.Final){
            TFila.Frente = TFila.Frente->Siguiente;
        }
        else{
            break;
        }
    }
    
    printf("NULL");
}