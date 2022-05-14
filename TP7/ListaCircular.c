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
    Lista = LCInsertar(Lista, 5);
    Lista = LCInsertar(Lista, 5);
    MostrarLC(Lista);
    printf("\n");

    printf("Cuenta de 5: %d\n", LCContarK(Lista, 5, 0));
    return 0;
}