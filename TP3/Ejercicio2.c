#include <stdio.h>

void Separar(int digito);
int Contar(int numero, int digito);

int main(){

    printf("%d", Contar(1222, 2));
    return 0;
}

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