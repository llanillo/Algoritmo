#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Alumnos{
    char* Apellido;
    char* Nombre;
} Alumnos;

struct Nodo{
    Alumnos Alumno;
    struct Nodo* Siguiente;
};
typedef struct Nodo* Comisiones;

Comisiones ComisionVacia();
Comisiones AltaAlumno(Comisiones Comision, Alumnos Alumno);
bool EstaVacia(Comisiones Comision);
int Cantidad(Comisiones Comision);
Comisiones BajaAlumno(Comisiones Comision, Alumnos Alumno);
Comisiones BajaUltimo(Comisiones Comision);
Alumnos UltimoInscripto(Comisiones Comision);
bool Esta(Comisiones Comision, Alumnos Alumno);
bool HayComunes(Comisiones Comision1, Comisiones Comision2);
Comisiones Eliminar(Comisiones Comision);
int main(){

    /* Me dio paja probarlo */
    return 0;
}

Comisiones ComisionVacia(){
    return NULL;
}

Comisiones AltaAlumno(Comisiones Comision, Alumnos Alumno){
    Comisiones Auxiliar = (Comisiones) malloc(sizeof(struct Nodo));
    Auxiliar->Siguiente = Comision;
    Auxiliar->Alumno = Alumno;
    return Auxiliar;
}

bool EstaVacia(Comisiones Comision){
    return Comision == NULL;
}

int Cantidad(Comisiones Comision){
    int Temporal = 0;

    while(!EstaVacia(Comision)){
        Temporal++;
        Comision = Comision->Siguiente;
    }

    return Temporal;
}

Comisiones BajaAlumno(Comisiones Comision, Alumnos Alumno){
    Comisiones Cabecera = Comision;

    while(!EstaVacia(Comision)){
        if(Comision->Siguiente != NULL && strcmp(Comision->Siguiente->Alumno.Apellido, Alumno.Apellido) == 0){
            Comision->Siguiente = Eliminar(Comision->Siguiente);
        }

        Comision = Comision->Siguiente;
    }
}

Comisiones BajaUltimo(Comisiones Comision){
    return Eliminar(Comision);
}

Alumnos UltimoInscripto(Comisiones Comision){
    return Comision->Alumno;
}

bool Esta(Comisiones Comision, Alumnos Alumno){
    while(!EstaVacia(Comision)){

        if(strcmp(Comision->Alumno.Apellido, Alumno.Apellido) == 0){
            return true;
        }

        Comision = Comision->Siguiente;
    }

    return false;
}

bool HayComunes(Comisiones Comision1, Comisiones Comision2){

    if(EstaVacia(Comision1) || EstaVacia(Comision2)){
        return false;
    }
    else{
        while(!EstaVacia(Comision1)){
            if(Esta(Comision2, Comision1->Alumno)){
                return true;
            }
            Comision1 = Comision1->Siguiente;
        }
    }

    return false;
}

Comisiones Eliminar(Comisiones Comision){
    if(Comision == NULL){
        return Comision;
    }

    Comisiones Temporal = Comision;
    Comision = Comision->Siguiente;
    free(Temporal);
    return Comision;
}

