#include "ListaCircular.h"

int main(){
    ListaCircular Lista;
    Lista = LCVacia();

    Lista = LCInsertar(Lista, 2);
    Lista = LCInsertar(Lista, 3);
    Lista = LCInsertar(Lista, 4);
    Lista = LCInsertar(Lista, 5);
    Lista = LCInsertar(Lista, 6);
    MostrarLC(Lista);
    printf("\n");

    Lista = LCBorrar(Lista);
    Lista = LCBorrar(Lista);
    Lista = LCBorrar(Lista);
    Lista = LCBorrar(Lista);
    MostrarLC(Lista);
    printf("\n");

    Lista = LCInsertar(Lista, 5);
    Lista = LCInsertar(Lista, 5);
    Lista = LCInsertar(Lista, 5);
    Lista = LCInsertar(Lista, 3);
    Lista = LCInsertar(Lista, 5);
    MostrarLC(Lista);
    printf("\n");

    printf("Cuenta de 5: %d\n", LCContarK(Lista, 5, Lista.Longitud));

    Lista = LCBorrarKRecursivo(Lista, 5, Lista.Longitud);
//    Lista = LCBorrarK(Lista, 5);
    MostrarLC(Lista);
    printf("\n");

    ListaCircular Lista2 = LCVacia();
    Lista2 = LCInsertar(Lista2, 5);
    Lista2 = LCInsertar(Lista2, 3);
    Lista2 = LCInsertar(Lista2, 6);
    Lista2 = LCInsertar(Lista2, 4);
    MostrarLC(Lista2);
    printf("\n");

    Lista2 = LCRotar(Lista2);
    Lista2 = LCRotar(Lista2);
    MostrarLC(Lista2);
    printf("\n");

    ListaCircular Lista3 = LCUnir(Lista, Lista2);
    MostrarLC(Lista3);
    printf("\n");

    return 0;
}