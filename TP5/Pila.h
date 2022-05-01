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
    struct Nodo* Siguiente;
} Pila;

Pila PilaVacia();
bool EsPilaVacia(Pila Cabecera);
Item Top(Pila Cabecera);
Pila Pop(Pila Cabecera);
Pila Push(Pila Cabecera, Item Dato);

Pila PilaVacia(){
    Pila Auxiliar;
    Auxiliar.Altura = 0;
    Auxiliar.Siguiente = NULL;
    return Auxiliar;
}

bool EsPilaVacia(Pila Cabecera){
    return Cabecera.Siguiente == NULL;
}

Item Top(Pila Cabecera){
    if(EsPilaVacia(Cabecera) || Cabecera.Altura < 0){
        return Indefinido;
    }
    else{
        return Cabecera.Siguiente->Dato;
    }
}

Pila Pop(Pila Cabecera){
    if(EsPilaVacia(Cabecera)){
        return PilaVacia();
    }
    else{
        Nodo* Auxiliar = Cabecera.Siguiente;
        Cabecera.Siguiente = Cabecera.Siguiente->Siguiente;
        Cabecera.Altura--;
        free(Auxiliar);
        return Cabecera;
    }
}

Pila Push(Pila Cabecera, Item Dato){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(Nodo));
    Auxiliar->Siguiente = Cabecera.Siguiente;
    Auxiliar->Dato = Dato;
    Cabecera.Siguiente = Auxiliar;
    Cabecera.Altura++;
    return Cabecera;
}

Item Fondo(Pila Cabecera){
    Item Fondo = Indefinido;

    while(!EsPilaVacia(Cabecera)){
        Fondo = Cabecera.Siguiente->Dato;
        Cabecera.Siguiente = Cabecera.Siguiente->Siguiente;
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
            Primera.Siguiente = Primera.Siguiente->Siguiente;
            Segunda.Siguiente = Segunda.Siguiente->Siguiente;
        }
        else{
            Segunda.Siguiente = Segunda.Siguiente->Siguiente;
        }
    }

    return EsPilaVacia(Primera);
}