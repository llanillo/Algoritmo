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
bool EsABVacio(Arbol Arbol);
Arbol ArmarAB(Arbol Izquierda, Arbol Derecha, Item Objeto);
Arbol ABIzquierda(Arbol Arbol);
Arbol ABDerecha(Arbol Arbol);
Item ABRaiz(Arbol Arbol);
bool Pertenece(Arbol Arbol, Item Objeto);

bool EsHoja(Arbol Arbol);
int NumeroHojas(Arbol Arbol);
void OrdenSimetrico(Arbol Arbol);
int CuentaItem(Arbol Arbol, Item Item);
int Altura(Arbol Arbol);
int Max(int num1, int num2);

void MostrarArbol(Arbol Arbol, int Contador);

bool EsABVacio(Arbol Arbol){
    return Arbol == NULL;
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
    return !EsABVacio(Arbol) ? Arbol->Izquierda : NULL;
}

Arbol ABDerecha(Arbol Arbol){
    return !EsABVacio(Arbol) ? Arbol->Derecha : NULL;
}

Item ABRaiz(Arbol Arbol){
    return !EsABVacio(Arbol) ? Arbol->Raiz : Indefinido;
}

bool Pertenece(Arbol Arbol, Item Objeto){
    if(EsABVacio(Arbol)){
        return false;
    }
    else{
        if(ABRaiz(Arbol) == Objeto){
            return true;
        }
        else{
            return Pertenece(ABDerecha(Arbol), Objeto) || Pertenece(ABIzquierda(Arbol), Objeto);
        }
    }
}

bool EsHoja(Arbol Arbol){
    return EsABVacio(ABIzquierda(Arbol)) && EsABVacio(ABIzquierda(Arbol));
}

int NumeroHojas(Arbol Arbol){
    if(EsABVacio(Arbol)){
        return 0;
    }
    else{
        if(EsHoja(Arbol)){
            return 1;
        }
        else{
            return NumeroHojas(ABIzquierda(Arbol)) + NumeroHojas(ABDerecha(Arbol));
        }
    }
}

void OrdenSimetrico(Arbol Arbol){
    if(!EsABVacio(Arbol)){
        OrdenSimetrico(ABIzquierda(Arbol));
        printf("Raíz: %d\b", Arbol->Raiz);
        OrdenSimetrico(ABDerecha(Arbol));
    }
}

/*
 * Cantidad de veces que se repite un ítem
 */
int CuentaItem(Arbol Arbol, Item Item){
    if(EsABVacio(Arbol)){
        return 0;
    }
    else{
        if(ABRaiz(Arbol) == Item){
            return 1 + CuentaItem(ABIzquierda(Arbol), Item) + CuentaItem(ABDerecha(Arbol), Item);
        }
        else{
            return CuentaItem(ABIzquierda(Arbol), Item) + CuentaItem(ABDerecha(Arbol), Item);
        }
    }
}

int Altura(Arbol Arbol){
    if(EsABVacio(Arbol) || EsHoja(Arbol)){
        return 0;
    }
    else{
        return 1 + Max(Altura(ABIzquierda(Arbol)) , Altura(ABDerecha(Arbol)));
    }
}

int Max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
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
