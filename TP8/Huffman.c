#include "Arbol.h"
#include <string.h>

#define TAMANO 26

typedef struct Cadidatos{
    char Letra;
    float Frecuencia;
} Candidato;

typedef struct Huffman{
    Arbol Arbol;
    float Frecuencia;
} Huffman;

Arbol CrearArbolHuffman(Candidato Arreglo[], int Tamano);
int BuscarIndiceMenorFrecuencia(Huffman Arreglo[], int Tamano, int EvitarIndice);
void ImprimirCodigos(Arbol Arbol, int Auxiliar[], int Altura);
void ImprimirCodigoLetra(Arbol Arbol, int Auxiliar[], int Altura, char Letra);
void CodificarPalabra(Arbol Arbol, int Tamano, char Palabra []);

int main(){

    #pragma region Ejercicio1 - Crear árbol de Huffman

    Candidato Candidatos [] = {{'a', 0.110845f}, {'b', 0.010895f},
                               {'c', 0.048778f}, {'d', 0.049769f},
                               {'e', 0.133336f}, {'f', 0.007965f},
                               {'g', 0.011638f}, {'h', 0.006108f},
                               {'i', 0.077790f}, {'j', 0.002889f},
                               {'k', 0.000083f}, {'l', 0.053524f},
                               {'m', 0.026494f}, {'n', 0.073580f},
                               {'o', 0.093925f}, {'p', 0.026700f},
                               {'q', 0.008625f}, {'r', 0.061571f},
                               {'s', 0.079605f}, {'t', 0.051378f},
                               {'u', 0.041887f}, {'v', 0.009698f},
                               {'w', 0.000041f}, {'y', 0.008336f},
                               {'x', 0.001940f}, {'z', 0.002600f}};

    int Auxiliar[TAMANO];
    Arbol Final = CrearArbolHuffman(Candidatos, TAMANO);

    #pragma endregion

    #pragma region Ejercicio2 - Imprimir códigos de árbol de Huffman

    ImprimirCodigos(Final, Auxiliar, 0);

    #pragma endregion

    #pragma region Ejercicio3 - Codificar palabra con árbol de Huffman

    char Palabra [100];
    printf("Ingrese la palabra a codificar\n");
    fgets(Palabra, 100, stdin);

    CodificarPalabra(Final, TAMANO, Palabra);

    #pragma endregion

    return 0;
}

/*
 * Busca el índice del carácter con menor frecuencia en el arreglo de candidatos.
 * El últimmo parámetro indica que índice ignorar
 */
int BuscarIndiceMenorFrecuencia(Huffman Arreglo[], int Tamano, int EvitarIndice){
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
 *  Muestra los códigos de cada letra en la codificación Huffman.
 */
void ImprimirCodigos(Arbol Arbol, int Auxiliar[], int Altura){
    if(!EsABVacio(Arbol)){

        if(ABIzquierda(Arbol)){
            Auxiliar[Altura] = 0;
            ImprimirCodigos(ABIzquierda(Arbol), Auxiliar, Altura + 1);
        }

        if (ABDerecha(Arbol)){
            Auxiliar[Altura] = 1;
            ImprimirCodigos(ABDerecha(Arbol), Auxiliar, Altura + 1);
        }

        if (EsHoja(Arbol)){
            printf("Letra: %c  Codigo: ", Arbol->Raiz);

            for (unsigned int i = 0; i < Altura; i++) {
                printf("%d", Auxiliar[i]);
            }

            printf("\n");
        }
    }
}

/*
 * Devuelve el árbol creado con la codificación de Huffman dado el arreglo de Candidatos
 */
Arbol CrearArbolHuffman(Candidato Arreglo[], int Tamano){
    int IndicePrimerMenor, IndiceSegundoMenor;
    int CantidadSubArboles = Tamano;
    Huffman ArbolesHuffman [Tamano];
    Arbol Final;

    /*
    *  Creamos hojas con todos los carácteres y los guardamos en el arreglo de árboles
    */
    for(unsigned int i = 0; i < Tamano; i++){
        ArbolesHuffman[i].Arbol = ArmarAB(NULL, NULL, Arreglo[i].Letra);
        ArbolesHuffman[i].Frecuencia = Arreglo[i].Frecuencia;
    }

    /*
     * Iteramos mientras el tamaño del arreglo sea mayor que 1
     */
    while(CantidadSubArboles > 1){
        /*
         *  Buscamos los índices de los caracteres con menor frecuencia en el arreglo de Huffman.
         */
        IndicePrimerMenor = BuscarIndiceMenorFrecuencia(ArbolesHuffman, Tamano, -1);
        IndiceSegundoMenor = BuscarIndiceMenorFrecuencia(ArbolesHuffman, Tamano, IndicePrimerMenor);

        /*
         * Creamos un árbol con las dos hojas de los índices encontrados y lo guardamos
         * en el arreglo de arboles, luego aumentamos la frecuencia del segundo carácter
         * y asignamos a un valor alto la del primer carácter para que no se tome en cuenta.
         */
        Arbol Izquierda = ArbolesHuffman[IndicePrimerMenor].Arbol;
        Arbol Derecha = ArbolesHuffman[IndiceSegundoMenor].Arbol;
        Final = ArmarAB(Izquierda, Derecha, ' ');
        ArbolesHuffman[IndiceSegundoMenor].Arbol = Final;
        ArbolesHuffman[IndiceSegundoMenor].Frecuencia += ArbolesHuffman[IndicePrimerMenor].Frecuencia;
        ArbolesHuffman[IndicePrimerMenor].Frecuencia = 2;
        CantidadSubArboles--;
    }

    return Final;
}

/*
 *
 */
void CodificarPalabra(Arbol Arbol, int Tamano, char Palabra []){
    int CantidadLetras = (int) strlen(Palabra);

    printf("Codigo: ");

    for(unsigned int i = 0; i < CantidadLetras; i++){
        int Auxiliar[TAMANO];
        ImprimirCodigoLetra(Arbol, Auxiliar, 0, Palabra[i]);
    }

}

void ImprimirCodigoLetra(Arbol Arbol, int Auxiliar[], int Altura, char Letra){
    if(!EsABVacio(Arbol)){

        if(ABIzquierda(Arbol)){
            Auxiliar[Altura] = 0;
            ImprimirCodigoLetra(ABIzquierda(Arbol), Auxiliar, Altura + 1, Letra);
        }

        if (ABDerecha(Arbol)){
            Auxiliar[Altura] = 1;
            ImprimirCodigoLetra(ABDerecha(Arbol), Auxiliar, Altura + 1, Letra);
        }

        if (EsHoja(Arbol) && ABRaiz(Arbol) == Letra){
            for (unsigned int i = 0; i < Altura; i++) {
                printf("%d", Auxiliar[i]);
            }

            return;
        }
    }
}