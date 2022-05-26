#include "Arbol.h"

#define TAMANO 25

typedef struct Cadidatos{
    char Letra;
    float Frecuencia;
} Candidato;

int BuscarIndiceMenorFrecuencia(Candidato Arreglo[], int Tamano, int EvitarIndice);
void VerCodigoLetras(Arbol Arbol, int contador);

int main(){

    #pragma region Ejercicio1
    int IndicePrimerMenor, IndiceSegundoMenor;
    int CantidadSubArboles = TAMANO;
    Arbol Arboles [TAMANO];
    Candidato Candidatos [] = {{'a', 0.110845}, {'b', 0.010895},
                               {'c', 0.048778}, {'d', 0.049769},
                               {'e', 0.133336}, {'f', 0.007965},
                               {'g', 0.011638}, {'h', 0.006108},
                               {'i', 0.077790}, {'j', 0.002889},
                               {'k', 0.000083}, {'l', 0.053524},
                               {'m', 0.026494}, {'n', 0.073580},
                               {'o', 0.093925}, {'p', 0.026700},
                               {'q', 0.008625}, {'r', 0.061571},
                               {'s', 0.079605}, {'t', 0.051378},
                               {'u', 0.041887}, {'v', 0.009698},
                               {'w', 0.000041}, {'y', 0.001940},
                               {'x', 0.008336}, {'z', 0.002600}};

    /*
     *  Creamos hojas con todos los carácteres y los guardamos en el arreglo de árboles
     */
    for(unsigned int i = 0; i < TAMANO; i++){
        Arboles[i] = ArmarAB(NULL, NULL, Candidatos[i].Letra);
    }

    /*
     * Iteramos mientras el tamaño del arreglo sea mayor que 1
     */
    while(CantidadSubArboles > 1){
        /*
         *  Buscamos los índices de los caracteres con menor frecuencia en el arreglo de candidatos.
         */
        IndicePrimerMenor = BuscarIndiceMenorFrecuencia(Candidatos, TAMANO, -1);
        IndiceSegundoMenor = BuscarIndiceMenorFrecuencia(Candidatos, TAMANO, IndicePrimerMenor);

        /*
         * Creamos un árbol con las dos hojas de los índices encontrados y lo guardamos
         * en el arreglo de arboles, luego aumentamos la frecuencia del segundo carácter
         * y asignamos a un valor alto la del primer carácter para que no se tome en cuenta.
         */
        Arboles[IndiceSegundoMenor] = ArmarAB(Arboles[IndicePrimerMenor], Arboles[IndiceSegundoMenor], ' ');
        Candidatos[IndiceSegundoMenor].Frecuencia += Candidatos[IndicePrimerMenor].Frecuencia;
        Candidatos[IndicePrimerMenor].Frecuencia = 2;
        CantidadSubArboles--;
    }

    /*
     * Buscamos el árbol final en el arreglo
     */
    Arbol Final = Arboles[IndiceSegundoMenor];
    MostrarArbol(Final, 0 );

    #pragma endregion

    #pragma region Ejercicio2

    VerCodigoLetras(Final, 0);

    #pragma endregion

    #pragma region Ejercicio3

    #pragma endregion

    return 0;
}

/*
 * Busca el índice del carácter con menor frecuencia en el arreglo de candidatos.
 * El últimmo parámetro indica que índice ignorar
 */
int BuscarIndiceMenorFrecuencia(Candidato Arreglo[], int Tamano, int EvitarIndice){
    int Indice = 0;
    float Menor = 20;

    for(unsigned int i = 0; i < Tamano; i++){
        if(i != EvitarIndice && Arreglo[i].Frecuencia < Menor){
            Indice = (int) i;
            Menor = Arreglo[i].Frecuencia;
        }
    }

    return Indice;
}

/*
 *  Muestra los códigos de cada letra en la codificación Huffman
 */
void VerCodigoLetras(Arbol Arbol, int contador){
    if(!EsABVacio(Arbol)){
        VerCodigoLetras(Arbol->Izquierda, contador * 10);

        if(Arbol->Raiz != ' '){
            printf("Letra: %c   Codigo: %d\n", Arbol->Raiz, contador);
        }

        VerCodigoLetras(Arbol->Derecha, contador * 10 + 1);
    }
}