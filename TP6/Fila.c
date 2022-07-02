#include "Fila.h"

int main(){
    Fila Primera;
    Fila Segunda;

    Primera = FilaVacia();
    Segunda = FilaVacia();

    Primera = Enfila(Primera, 2);
    Primera = Enfila(Primera, 45);
    MostrarFila(Primera);
    
    printf("\n");

    Primera = Defila(Primera);
    MostrarFila(Primera);

    printf("\n");

    Primera = Defila(Primera);
    Primera = Defila(Primera);
    MostrarFila(Primera);
    printf("\n");

    Primera = Enfila(Primera, 6);
    Primera = Enfila(Primera, 7);
    Primera = Enfila(Primera, 8);
    Primera = Enfila(Primera, 9);
    MostrarFila(Primera);
    printf("\n");

    Segunda = Enfila(Segunda, 6);
    Segunda = Enfila(Segunda, 7);
    Segunda = Enfila(Segunda, 8);
    Segunda = Enfila(Segunda, 9);
    MostrarFila(Segunda);
    printf("\n");

    Primera = Mezclar(Primera, Segunda);
    MostrarFila(Primera);
    printf("\n");

    Fila Vacia = Invertir(Primera, FilaVacia());
    MostrarFila(Vacia);
    printf("\n");

    printf("Suma Pares: %d ", SumaPares(Vacia));

    return 0;
}