#ifndef ALGORITMO_LISTACIRCULAR_H
#define ALGORITMO_LISTACIRCULAR_H

#endif //ALGORITMO_LISTACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

const Item Indefinido = -9999;

typedef struct Nodo{
    Item Dato;
    struct Nodo* Siguiente;
} Nodo;

typedef struct ListaCircular{
    struct Nodo* Cabecera;
    int Longitud;
} ListaCircular;

bool EsLCVacia(ListaCircular Lista);
ListaCircular LCVacia();
Item LCValor(ListaCircular Lista);
void MostrarLC(ListaCircular Lista);
ListaCircular LCRotar(ListaCircular Lista);
bool LCPertenece(ListaCircular Lista, Item Objeto);
ListaCircular LCInsertar(ListaCircular Lista, Item Dato);
ListaCircular LCBorrar(ListaCircular Lista);
ListaCircular LCBorrarK(ListaCircular Lista, Item Objeto);

int ContarPares(ListaCircular Lista);

bool EsLCVacia(ListaCircular Lista){
    return Lista.Cabecera == NULL;
}

ListaCircular LCVacia(){
    ListaCircular Temporal;
    Temporal.Cabecera = NULL;
    Temporal.Longitud = 0;
    return Temporal;
}

Item LCValor(ListaCircular Lista){
    return EsLCVacia(Lista) ? Indefinido : Lista.Cabecera->Dato;
}

ListaCircular LCInsertar(ListaCircular Lista, Item Dato){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(struct Nodo));
    Auxiliar->Dato = Dato;

    if(EsLCVacia(Lista)){
        Lista.Cabecera = Auxiliar;
        Auxiliar->Siguiente = Lista.Cabecera;
    }
    else{
        Auxiliar->Siguiente = Lista.Cabecera->Siguiente;
        Lista.Cabecera->Siguiente = Auxiliar;
    }

    Lista.Longitud++;
    return Lista;
}

ListaCircular LCBorrar(ListaCircular Lista){
    if(!EsLCVacia(Lista)){
        Nodo* Auxiliar = Lista.Cabecera->Siguiente;

        if(Lista.Longitud == 1){
            Lista.Cabecera = NULL;
            free(Auxiliar);
        }
        else{
            Lista.Cabecera->Siguiente = Lista.Cabecera->Siguiente->Siguiente;
            free(Auxiliar);
        }

        Lista.Longitud--;
    }

    return Lista;
}

ListaCircular LCBorrarK(ListaCircular Lista, Item Objeto){
    int Longitud = Lista.Longitud;

    while(Longitud){
        if(Lista.Cabecera->Siguiente->Dato == Objeto){
            Lista = LCBorrar(Lista);
        }
        else{
            Lista.Cabecera = Lista.Cabecera->Siguiente;
        }

        Longitud--;
    }

    return Lista;
}

bool LCPertenece(ListaCircular Lista, Item Objeto){
    int Longitud = Lista.Longitud;

    while(Longitud){
        if(Lista.Cabecera->Dato == Objeto){
            return true;
        }
    }

    return false;
}

ListaCircular LCRotar(ListaCircular Lista){
    Lista.Cabecera = Lista.Cabecera->Siguiente;
    return Lista;
}

void MostrarLC(ListaCircular Lista){
    int Auxiliar = Lista.Longitud;

    while(Auxiliar){
        printf("%d -> ", Lista.Cabecera->Dato);
        Lista.Cabecera = Lista.Cabecera->Siguiente;
        Auxiliar--;
    }

    printf("NULL");
}

/*
 * Cuenta las veces que se repite el Numero en la Lista.
 * Se debe mandar un Contador inicial en cero.
 */
int LCContarK(ListaCircular Lista, int Numero, int Contador){
    if(Contador == Lista.Longitud){
        return 0;
    }
    else{
        if(LCValor(Lista) == Numero){
            return 1 + LCContarK(LCRotar(Lista), Numero, Contador + 1);
        }
        else{
            return LCContarK(LCRotar(Lista), Numero, Contador + 1);
        }
    }
}