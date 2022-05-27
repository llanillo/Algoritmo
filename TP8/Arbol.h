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
bool EsHoja(Arbol Arbol);
Arbol ArmarAB(Arbol Izquierda, Arbol Derecha, Item Objeto);
bool EsABVacio(Arbol Arbol);
Arbol ABIzquierda(Arbol Arbol);
Arbol ABDerecha(Arbol Arbol);
Item ABRaiz(Arbol Arbol);
bool Pertenece(Arbol Arbol, Item Objeto);

bool EsABVacio(Arbol Arbol){
    return Arbol == NULL;
}

bool EsHoja(Arbol Arbol)
{
    if(!EsABVacio(Arbol)){
        return Arbol->Derecha == NULL && Arbol->Izquierda == NULL ? true : false;
        }
    else{
        return false;
    }

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

Arbol ABIzquierda(Arbol Arbol){
    return Arbol->Izquierda;
}

Arbol ABDerecha(Arbol Arbol){
    return Arbol->Derecha;
}

Item ABRaiz(Arbol Arbol){
    return EsABVacio(Arbol) ? Indefinido : Arbol->Raiz;
}

bool Pertenece(Arbol Arbol, Item Objeto){
    if(EsABVacio(Arbol)){
        return false;
    }
    else{
        if(Arbol->Raiz == Objeto){
            return true;
        }
        else{
            bool LadoDerecho = Pertenece(ABDerecha(Arbol), Objeto);
            bool LadoIzquierdo = Pertenece(ABDerecha(Arbol), Objeto);
            return LadoDerecho || LadoIzquierdo;
        }
    }
}

/*
 * Se debe mandar un Contador en cero (0)
 */
void MostrarArbol(Arbol Arbol, int Contador){
    if(EsABVacio(Arbol)){
        return;
    }
    else{
        MostrarArbol(Arbol->Derecha, Contador + 1);

        for(unsigned int i = 0; i < Contador; i++){
            printf("   ");
        }

        printf("%c\n", Arbol->Raiz);
        MostrarArbol(Arbol->Izquierda, Contador + 1);
    }
}

