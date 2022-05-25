#include "Arbol.h"

int main(){
    Arbol TArbol0 = ArmarAB(NULL, NULL, 'a');
    Arbol TArbol1 = ArmarAB(NULL, NULL, 'b');
    Arbol TArbol2 = ArmarAB(TArbol1, TArbol0, 'c');
    Arbol TArbol3 = ArmarAB(NULL, TArbol2, 'd');
    Arbol TArbol4 = ArmarAB(TArbol3, NULL, 'e');
    Arbol TArbol5 = ArmarAB(TArbol4, ArmarAB(NULL, NULL, 'f'), 'g');

    MostrarArbol(TArbol5, 0);
    return 0;
}