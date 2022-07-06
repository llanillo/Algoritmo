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

    printf("Suma Pares: %d\n", SumaPares(&Vacia));

    Fila Tercera = FilaVacia();
    Tercera = Enfila(Tercera, 6);
    Tercera = Enfila(Tercera, 7);
    Tercera = Enfila(Tercera, 8);
    Tercera = Enfila(Tercera, 9);
    MostrarFila(Tercera);
    printf("\n");

    printf("Pertenece '9': %d\n", Pertenece(&Tercera, 9));

    return 0;
}