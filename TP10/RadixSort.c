#include "Fila.h"
#include <math.h>

#define DECIMAL 10
#define MAX_CIFRAS 3

void OrdenarRadixSort(int CantidadTotal, int CantidadNumeros, int Arreglo [], Fila Filas []);
void MostrarArreglo(int Arreglo[], int Tamano);

int main(){

    Fila Filas [DECIMAL]; // Arreglo de filas del tamaño de nuestra base (decimal)
    int Aleatorio [] = {978, 1, 10, 25, 11, 202, 311, 125, 243}; // Arreglo con valores aleatorios de 3 digitos

    /*
     * Inicializo el arreglo de filas
     */
    for(unsigned int i = 0; i < DECIMAL; i++){
        Filas[i] = FilaVacia();
    }

    int TamanoArreglo = sizeof(Aleatorio) / sizeof(Aleatorio[0]);
    OrdenarRadixSort(TamanoArreglo, MAX_CIFRAS, Aleatorio, Filas);
    MostrarArreglo(Aleatorio, TamanoArreglo);

    return 0;
}

void OrdenarRadixSort(int CantidadTotal, int CantidadNumeros, int Arreglo [], Fila Filas []){
    for(unsigned int i = 1; i <= CantidadNumeros; i++){

        for(unsigned int j = 0; j < CantidadTotal; j++){
            int Auxiliar = Arreglo[j] / (int) pow(10, i - 1);
            Auxiliar = Auxiliar % 10;
            Filas[Auxiliar] = Enfila(Filas[Auxiliar], Arreglo[j]);
        }

        int Indice = 0;
        for(unsigned int j = 0; j < DECIMAL; j++){
            while(!EsFilaVacia(Filas[j])){
                Arreglo[Indice] = Frente(Filas[j]);
                Filas[j] = Defila(Filas[j]);
                Indice++;
            }
        }
    }
}

void MostrarArreglo(int Arreglo[], int Tamano){
    for(unsigned int i = 0; i < Tamano; i++){
        printf("%d ", Arreglo[i]);
    }
}