#include <stdio.h>
#include "Pila.h"

int main(){

    Pila Primera;
    Pila Segunda;

    Primera = PilaVacia();
    Primera = Push(Primera, 1);
    Primera = Push(Primera, 2);
    Primera = Push(Primera, 3);

    Segunda = PilaVacia();
    Segunda = Push(Segunda, 5);
    Segunda = Push(Segunda, 1);
    Segunda = Push(Segunda, 2);
    Segunda = Push(Segunda, 5);
    Segunda = Push(Segunda, 3);
    Segunda = Push(Segunda, 5);

    printf("Fondo1: %d Fondo2: %d\n", Fondo(Primera), Fondo(Segunda));
    printf("Incluida: %d\n", IncluidaRecursiva(Primera, Segunda));

//    while(!EsPilaVacia(Primera)){
//        printf("Valor: %d\n", Top(Primera));
//        Primera = Pop(Primera);
//    }

//    int Valor = Top(Vacia);
//    printf("Top de vacio: %d\n", Valor);

    return 0;
}
