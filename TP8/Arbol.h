#ifndef ALGORITMO_ARBOL_H
#define ALGORITMO_ARBOL_H

#endif //ALGORITMO_ARBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char Indefinido = '@';

typedef char Item;

typedef struct Nodo{
    struct Nodo* Izquierda;
    struct Nodo* Derecha;
    Item Raiz;
} Nodo;

typedef Nodo* Arbol;

Arbol ABVacio();
Arbol ArmarAB(Arbol Izquierda, Arbol Derecha, Item Objeto);
bool EsABVacio(Arbol TArbol);
Arbol ABIzquierda(Arbol TArbol);
Arbol ABDerecha(Arbol TArbol);
Item ABRaiz(Arbol TArbol);
bool Pertenece(Arbol TArbol, Item Objeto);

bool EsABVacio(Arbol TArbol){
    return TArbol == NULL;
}

Arbol ABVacio (){
    return NULL;
}

Arbol ArmarAB(Arbol Izquierda, Arbol Derecha, Item Objeto){
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
    return EsABVacio(TArbol) ? Indefinido : TArbol->Raiz;
}

bool Pertenece(Arbol TArbol, Item Objeto){
    if(EsABVacio(TArbol)){
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

/*
 * Se debe mandar un contador en cero (0)
 */
void MostrarArbol(Arbol TArbol, int contador){
    if(EsABVacio(TArbol)){
        return;
    }
    else{
        MostrarArbol(TArbol->Derecha, contador + 1);

        for(unsigned int i = 0; i < contador; i++){
            printf("   ");
        }

        printf("%c\n", TArbol->Raiz);
        MostrarArbol(TArbol->Izquierda, contador + 1);
    }
}

