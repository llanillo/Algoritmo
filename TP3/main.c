#include <stdio.h>

#pragma region Ejercicio 2

void Separar(int digito);
int Contar(int numero, int digito);

#pragma endregion
#pragma region Ejercicio 4

int ValorAcumulado(int Vector[], int Izquierda, int Derecha);

#pragma endregion

int main(){

    // Test Ejercicio 2
//    printf("%d", Contar(1222, 2));

    // Test Ejercicio 4
    int Vector[] = {5, 5, 5, 5, 2, 2, 2, 2};
    int Valor = ValorAcumulado(Vector, 0, 7);
    printf("Respuesta %d\n", Valor);

    return 0;
}

#pragma region Ejercicio 2

void Separar(int digito){
    if(digito < 10){
        printf("%d ", digito);
    }
    else{
        Separar(digito / 10);
        printf("%d ", digito % 10);
    }
}

int Contar(int numero, int digito){
    if(numero == 0){
        return 0;
    }
    else{
        if(numero % 10 == digito){
            return Contar(numero / 10, digito) + 1;
        }
        else{
            return Contar(numero / 10, digito);
        }
    }
}

#pragma endregion

#pragma region Ejercicio 4

int ValorAcumulado(int Vector[], int Izquierda, int Derecha){
    int Medio = (Izquierda + Derecha) / 2;

    if(Izquierda == Derecha){
        if(Vector[Medio] % 2 == 0){
            return Vector[Medio];
        }
        else{
            return -Vector[Medio];
        }
    }
    else{
        int SumaIzquierda = ValorAcumulado(Vector, Izquierda, Medio);
        int SumaDerecha = ValorAcumulado(Vector, Medio + 1, Derecha);
        return SumaIzquierda + SumaDerecha;
    }
}

#pragma endregion