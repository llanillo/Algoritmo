#ifndef ALGORITMO_PILA_H
#define ALGORITMO_PILA_H

#endif //ALGORITMO_PILA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Item;
const int Indefinido = -999;
typedef struct Nodo{
    Item Dato;
    struct Nodo* Siguiente;
} Nodo;

typedef struct{
    int Altura;
    struct Nodo* Cabecera;
} Pila;

Pila PilaVacia();
bool EsPilaVacia(Pila TPila);
Item Top(Pila TPila);
Pila Pop(Pila TPila);
Pila Push(Pila TPila, Item Dato);

Pila PilaVacia(){
    Pila Auxiliar;
    Auxiliar.Altura = 0;
    Auxiliar.Cabecera = NULL;
    return Auxiliar;
}

bool EsPilaVacia(Pila TPila){
    return TPila.Cabecera == NULL;
}

Item Top(Pila TPila){
    if(EsPilaVacia(TPila) || TPila.Altura < 0){
        return Indefinido;
    }
    else{
        return TPila.Cabecera->Dato;
    }
}

Pila Pop(Pila TPila){
    if(EsPilaVacia(TPila)){
        return PilaVacia();
    }
    else{
        Nodo* Auxiliar = TPila.Cabecera;
        TPila.Cabecera = TPila.Cabecera->Siguiente;
        TPila.Altura--;
        free(Auxiliar);
        return TPila;
    }
}

/*
 * Inserta objeto en la pila
 */
Pila Push(Pila TPila, Item Dato){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(Nodo));
    Auxiliar->Siguiente = TPila.Cabecera;
    Auxiliar->Dato = Dato;
    TPila.Cabecera = Auxiliar;
    TPila.Altura++;
    return TPila;
}

Item Fondo(Pila TPila){
    Item Fondo = Indefinido;

    while(!EsPilaVacia(TPila)){
        Fondo = TPila.Cabecera->Dato;
        TPila.Cabecera = TPila.Cabecera->Siguiente;
    }

    return Fondo;
}

bool IncluidaRecursiva(Pila Primera, Pila Segunda){
    if(EsPilaVacia(Primera)){
        return true;
    }
    else{
        if(EsPilaVacia(Segunda)){
            return false;
        }
        else{
            if(Top(Primera) == Top(Segunda)){
                return IncluidaRecursiva(Pop(Primera), Pop(Segunda));
            }
            else{
                return IncluidaRecursiva(Primera, Pop(Segunda));
            }
        }
    }
}

bool IncluidaIterativa(Pila Primera, Pila Segunda){
    while(!EsPilaVacia(Segunda)){
        if(Top(Primera) == Top(Segunda)){
            Primera.Cabecera = Primera.Cabecera->Siguiente;
            Segunda.Cabecera = Segunda.Cabecera->Siguiente;
        }
        else{
            Segunda.Cabecera = Segunda.Cabecera->Siguiente;
        }
    }

    return EsPilaVacia(Primera);
}