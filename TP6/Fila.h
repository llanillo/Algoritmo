#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
const int Indefinido = -9999;

typedef struct Nodo{
    struct Nodo* Siguiente;
    Item Dato;
} Nodo;

typedef struct Fila{
    struct Nodo* Frente;
    struct Nodo* Final;
    int Longitud;
} Fila;

Fila FilaVacia();
bool EsFilaVacia(Fila Fila);
Item Frente(Fila Fila);
Fila Enfila(Fila Fila, Item Objeto);
Fila Defila(Fila Fila);

Item Final (Fila Fila);
bool Pertenece(Fila Fila, Item Dato);
bool IgualdadFilas(Fila Primera, Fila Segunda);
Fila ConcatenarFilas(Fila Primera, Fila Segunda);
void MostrarFila(Fila Fila);
Fila Invertir(Fila Original, Fila Vacia);
Fila Mezclar(Fila Primera, Fila Segunda);
int SumaPares(Fila Fila);

Fila FilaVacia(){
    Fila Temporal;
    Temporal.Frente = NULL;
    Temporal.Final = NULL;
    Temporal.Longitud = 0;
    return Temporal;
}

bool EsFilaVacia(Fila Fila){
    return Fila.Final == NULL && Fila.Frente == NULL;
}

Item Frente(Fila Fila){
    return !EsFilaVacia(Fila) ? Fila.Frente->Dato : Indefinido;
}

Item Final(Fila Fila){
    return !EsFilaVacia(Fila) ? Fila.Final->Dato : Indefinido;
}

Fila Enfila(Fila Fila, Item Objeto){
    Nodo* Auxiliar = (Nodo*) malloc(sizeof(Nodo));
    Auxiliar->Dato = Objeto;
    Auxiliar->Siguiente = NULL;

    if(EsFilaVacia(Fila)){
        Fila.Frente = Auxiliar;
        Fila.Final = Auxiliar;
    }
    else{
        Fila.Final->Siguiente = Auxiliar;
        Fila.Final = Auxiliar;
    }
    
    Fila.Longitud++;
    return Fila;
}

Fila Defila(Fila Fila){
    if(!EsFilaVacia(Fila)){
        Nodo* Auxiliar = Fila.Frente;

        if(Fila.Frente == Fila.Final){
            Fila.Frente = NULL;
            Fila.Final = NULL;
        }
        else{
            Fila.Frente = Fila.Frente->Siguiente;
        }

        free(Auxiliar);
        Fila.Longitud--;
    }

    return Fila;
}

/*
 * Modifica la fila, debe ser padada como puntero, pero entonces habría que
 * cambiar el Defila a que devuelve un puntero
 */
bool Pertenece(Fila Fila, Item Dato){
    if(EsFilaVacia(Fila)){
        return false;
    }
    else{
        return Frente(Fila) == Dato || Pertenece(Defila(Fila), Dato);
    }
}

bool IgualdadFilas(Fila Primera, Fila Segunda){
    if(EsFilaVacia(Primera) && EsFilaVacia(Segunda)){
        return true;
    }
    else{
        if(EsFilaVacia(Primera) || EsFilaVacia(Segunda)){
            return false;
        }
        else{
            return Frente(Primera) == Frente(Segunda) &&
                    IgualdadFilas(Defila(Primera), Defila(Segunda));
        }
    }
}

Fila ConcatenarFilas(Fila Primera, Fila Segunda){
    if(EsFilaVacia(Segunda)){
        return Primera;
    }
    else{
        return ConcatenarFilas(Enfila(Primera, Frente(Segunda)), Defila(Segunda));
    }
}

void MostrarFila(Fila TFila){
    while(!EsFilaVacia(TFila)){
        printf("%d -> ", Frente(TFila));

        if(TFila.Frente != TFila.Final){
            TFila.Frente = TFila.Frente->Siguiente;
        }
        else{
            break;
        }
    }

    printf("NULL");
}

Fila Invertir(Fila Original, Fila Vacia){
    if(!EsFilaVacia(Original)){
        Item Auxiliar = Frente(Original);
        Original = Defila(Original);
        Vacia =  Invertir(Original, Vacia);
        return Enfila(Vacia, Auxiliar);
    }

    return Original;
}

int SumaPares(Fila Fila){
    if(EsFilaVacia(Fila)){
        return 0;
    }
    else{
        int Dato = Frente(Fila);

        if(Dato % 2 == 0){
            return Dato + SumaPares(Defila(Fila));
        }
        else{
            return SumaPares((Defila(Fila)));
        }
    }
}

Fila Mezclar(Fila Primera, Fila Segunda){
    if(EsFilaVacia(Primera)){
        return Segunda;
    }
    else{
        if(EsFilaVacia(Segunda)){
            return Primera;
        }
        else{
            if(Frente(Primera) > Frente(Segunda)){
                if(Final(Primera) <= Final(Segunda)){
                    Primera = Enfila(Primera, Frente(Segunda));
                    Segunda = Defila(Segunda);
                }
                else{
                    Segunda = Enfila(Segunda, Frente(Primera));
                    Primera = Defila(Primera);
                }
            }
            else if(Frente(Primera) == Frente(Segunda)){
                Segunda = Enfila(Segunda, Frente(Segunda));
                Segunda = Enfila(Segunda, Frente(Primera));
                Segunda = Defila(Segunda);
                Primera = Defila(Primera);
            }
            else{
                if(Frente(Segunda) >= Final(Primera)){
                    Primera = Enfila(Primera, Frente(Segunda));
                    Segunda = Defila(Segunda);
                }
                else{
                    Segunda = Enfila(Segunda, Frente(Primera));
                    Primera = Defila(Primera);
                }
            }

            return Mezclar(Primera, Segunda);
        }
    }
}
