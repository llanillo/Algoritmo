#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
const Item Indefinido = -9999;

typedef struct Nodo{
    struct Nodo* Siguiente;
    Item Dato;
} Nodo;

typedef Nodo* Lista;

Lista CrearLista();
bool EsListaVacia(Lista Lista);
Item PrimerElemento(Lista Lista);
Lista Insertar(Lista Lista, Item Dato);
Lista Borrar(Lista Lista);
int Longitud(Lista Lista);

Lista CrearLista(){
    return NULL;
}

bool EsListaVacia(Lista Lista){
    return Lista == NULL;
}

Item PrimerElemento(Lista Lista){
    return !EsListaVacia(Lista) ? Lista->Dato : Indefinido;
}

Lista Insertar(Lista Lista, Item Dato){
    Nodo* Temporal = (Nodo*) malloc(sizeof(struct Nodo));
    Temporal->Siguiente = Lista;
    Temporal->Dato = Dato;
    return Temporal;
}

Lista Borrar(Lista Lista){
    if(!EsListaVacia(Lista)){
        Nodo* Temporal = Lista;
        Lista = Lista->Siguiente;
        free(Temporal);
    }

    return Lista;
}

int Longitud(Lista Lista){
    int Contador = 0;

    while(!EsListaVacia(Lista)){
        Contador++;
        Lista = Lista->Siguiente;
    }

    return Contador;
}