#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
const Item Indefinido = -9999;

typedef struct Nodo{
    struct Nodo* Siguiente;
    Item Dato;
} Nodo;

typedef struct Lista{
    Nodo* Cabecera;
    int Posicion;
} Lista;

Lista ListaVacia();
bool EsListaVacia(Lista Lista);
Item Obtener(Lista Lista, int Posicion);
Lista Insertar(Lista Lista, int Posicion, Item Dato);
Lista Borrar(Lista Lista, int Posicion);
int Longitud(Lista Lista);

Lista ListaVacia(){
    Lista Temporal;
    Temporal.Cabecera = NULL;
    Temporal.Posicion = 0;
    return Temporal;
}

bool EsListaVacia(Lista Lista){
    return Lista.Cabecera == NULL;
}

Item Obtener(Lista Lista, int Posicion){
    while(!EsListaVacia(Lista)){
        if(Lista.Posicion == Posicion){
            return Lista.Cabecera->Dato;
        }

        Lista.Cabecera = Lista.Cabecera->Siguiente;
    }

    return Indefinido;
}

