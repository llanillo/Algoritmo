#ifndef ALGORITMO_ARBOL_H
#define ALGORITMO_ARBOL_H

#endif //ALGORITMO_ARBOL_H

#include <stdlib.h>
#include <stdbool.h>

const int Indefinido = -9999;

typedef int Item;

typedef struct Nodo{
    struct Nodo* Izquierda;
    struct Nodo* Derecha;
    Item Raiz;
} Nodo;

typedef Nodo* Arbol;

Arbol ABVacio(Arbol Izquierda, Arbol Derecha, Item Objeto);
bool EsArbolVacio(Arbol TArbol);
Arbol ABIzquierda(Arbol TArbol);
Arbol ABDerecha(Arbol TArbol);
Item ABRaiz(Arbol TArbol);
bool Pertenece(Arbol TArbol, Item Objeto);

bool EsArbolVacio(Arbol TArbol){
    return TArbol == NULL;
}

Arbol ABVacio(Arbol Izquierda, Arbol Derecha, Item Objeto){
    Nodo* Temporal = (Arbol) malloc(sizeof(struct Nodo));
    Temporal->Raiz = Objeto;
    Temporal->Derecha = Derecha;
    Temporal->Izquierda = Izquierda;
    return Temporal;
}

Arbol ABIzquierda(Arbol TArbol){
    return TArbol->Izquierda;
}

Arbol ABDerecha(Arbol TArbol){
    return TArbol->Derecha;
}

Item ABRaiz(Arbol TArbol){
    return EsArbolVacio(TArbol) ? Indefinido : TArbol->Raiz;
}

bool Pertenece(Arbol TArbol, Item Objeto){
    if(EsArbolVacio(TArbol)){
        return false;
    }
    else{
        if(TArbol->Raiz == Objeto){
            return true;
        }
        else{
            bool LadoDerecho = Pertenece(ABDerecha(TArbol), Objeto);
            bool LadoIzquierdo = Pertenece(ABDerecha(TArbol), Objeto);
            return LadoDerecho || LadoIzquierdo;
        }
    }
}