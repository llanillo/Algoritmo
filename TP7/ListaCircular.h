#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
const Item Indefinido = -9999;

typedef struct Nodo{
    struct Nodo* Siguiente;
    Item Dato;
} Nodo;

typedef struct ListaCircular{
    struct Nodo* Cabecera;
    int Longitud;
} ListaCircular;

ListaCircular LCVacia();
bool EsLCVacia(ListaCircular Lista);
Item LCValor(ListaCircular Lista);
ListaCircular LCInsertar(ListaCircular Lista, Item Dato);
ListaCircular LCBorrar(ListaCircular Lista);
ListaCircular LCRotar(ListaCircular Lista);
bool LCPertenece(ListaCircular Lista, Item Objeto);

void MostrarLC(ListaCircular Lista);
ListaCircular LCUnir(ListaCircular Primera, ListaCircular Segunda);
ListaCircular LCBorrarK(ListaCircular Lista, Item Dato);
int LCContarK(ListaCircular Lista, Item Dato, int Contador);

ListaCircular LCVacia(){
    ListaCircular Temporal;
    Temporal.Cabecera = NULL;
    Temporal.Longitud = 0;
    return Temporal;
}

bool EsLCVacia(ListaCircular Lista){
    return Lista.Cabecera == NULL;
}

Item LCValor(ListaCircular Lista){
    return EsLCVacia(Lista) ? Indefinido : Lista.Cabecera->Siguiente->Dato;
}

ListaCircular LCInsertar(ListaCircular Lista, Item Dato){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(struct Nodo));
    Auxiliar->Dato = Dato;
    Auxiliar->Siguiente = NULL;

    if(EsLCVacia(Lista)){
        Lista.Cabecera = Auxiliar;
        Lista.Cabecera->Siguiente = Lista.Cabecera;
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

        if(Lista.Cabecera == Lista.Cabecera->Siguiente){
            Lista.Cabecera = NULL;
        }
        else{
            Lista.Cabecera->Siguiente = Lista.Cabecera->Siguiente->Siguiente;
        }

        free(Auxiliar);
        Lista.Longitud--;
    }

    return Lista;
}

bool LCPertenece(ListaCircular Lista, Item Dato){
    int Auxiliar = Lista.Longitud;

    for(unsigned int i = 0; i < Lista.Longitud; i++){
        if(LCValor(Lista) == Dato){
            return true;
        }

        Lista = LCRotar(Lista);
    }

    return false;
}

ListaCircular LCRotar(ListaCircular Lista){
    if(!EsLCVacia(Lista)){
        Lista.Cabecera = Lista.Cabecera->Siguiente;
    }

    return Lista;
}

void MostrarLC(ListaCircular Lista){
    for(unsigned int i = 0; i < Lista.Longitud; i++){
        printf("%d -> ", LCValor(Lista));
        Lista = LCRotar(Lista);
    }

    printf("NULL");
}

ListaCircular LCUnir(ListaCircular Primera, ListaCircular Segunda){
    if(EsLCVacia(Segunda)){
        return Primera;
    }
    else{
        return LCUnir(LCInsertar(Primera, LCValor(Segunda)), LCBorrar(Segunda));
    }
}

ListaCircular LCBorrarK(ListaCircular Lista, Item Dato){
    int Auxiliar = Lista.Longitud;

    while(Auxiliar){
        if(LCValor(Lista) == Dato){
            Lista = LCBorrar(Lista);
        }
        else{
            Lista = LCRotar(Lista);
        }

        Auxiliar--;
    }

    return Lista;
}

ListaCircular LCBorrarKRecursivo(ListaCircular Lista, Item Dato, int Contador){
    if(Contador == 0){
        return Lista;
    }
    else{
        if(LCValor(Lista) == Dato){
            return LCBorrarKRecursivo(LCBorrar(Lista), Dato, Contador - 1);
        }
        else{
            return LCBorrarKRecursivo(LCRotar(Lista), Dato, Contador - 1);
        }
    }
}

/*
 * Cuenta las veces que se repite el Dato en la Lista.
 * Se debe mandar un Contador inicial en cero.
 */
int LCContarK(ListaCircular Lista, Item Dato, int Contador){
    if(Contador == 0){
        return 0;
    }
    else{
        if(LCValor(Lista) == Dato){
            return 1 + LCContarK(LCRotar(Lista), Dato, Contador - 1);
        }
        else{
            return LCContarK(LCRotar(Lista), Dato, Contador - 1);
        }
    }
}