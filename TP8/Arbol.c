#include "Arbol.h"

int main(){
    Arbol Arbol1 = ArmarAB(NULL, NULL, 'a');
    Arbol Arbol2 = ArmarAB(NULL, NULL, 'b');
    Arbol Arbol3 = ArmarAB(Arbol2, Arbol1, 'c');
    Arbol Arbol4 = ArmarAB(NULL, Arbol3, 'd');
    Arbol Arbol5 = ArmarAB(Arbol4, Arbol1, 'e');
    Arbol Arbol6 = ArmarAB(Arbol5, ArmarAB(NULL, NULL, 'f'), 'g');
    OrdenPrevio(Arbol6);
    printf("\n");

    OrdenSimetrico(Arbol6);
    printf("\n");

    OrdenPosterior(Arbol6);
    printf("\n");

    printf("Pertenece 'r': %d\n", Pertenece(Arbol6, 'r'));
    printf("Numero de hojas: %d\n", NumeroHojas(Arbol6));
    printf("Cuenta item 'c': %d\n", CuentaItem(Arbol6, 'f'));
    printf("Altura: %d\n", Altura(Arbol6));

    MostrarArbol(Arbol6, 0);


    return 0;
}