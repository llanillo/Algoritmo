#include "Fila.h"

int main(){
    Fila Fila;
    Fila = FilaVacia();

    Fila = Enfila(Fila, 2);
    Fila = Enfila(Fila, 45);
    MostrarFila(Fila);
    
    printf("\n");

    Fila = Defila(Fila);
    MostrarFila(Fila);

    printf("\n");
    
    Fila = Defila(Fila);
    MostrarFila(Fila);
    return 0;
}