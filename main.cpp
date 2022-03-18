#include <iostream>
#include <string.h>

using item = int32_t;
struct Nodo{
    item dato;
    Nodo* siguiente;
};
using Lista = struct Nodo*;

Lista crearLista();
bool esListaVacia(Lista const lista);
void mostrar(Lista lista);
item primerElemento(Lista const lista);
Lista insertar(Lista lista, item objeto);
Lista borrar(Lista lista);
int32_t longitud(Lista lista);
bool pertenece(Lista lista, item objeto);
Lista borrarK(Lista lista, item objeto);

int main() {
    int32_t auxiliar = 1;
    int32_t opcion;

    Lista lista;

    while(auxiliar){
        std::cout << "\n------ Funciones de lista ------" << '\n';
        std::cout << "1. Crear Lista" << '\n';
        std::cout << "2. ¿Está la lista vacía?" << '\n';
        std::cout << "3. Mostrar lista" << '\n';
        std::cout << "4. Mostrar primer elemento" << '\n';
        std::cout << "5. Insertar elemento" << '\n';
        std::cout << "6. Borrar primer elemento" << '\n';
        std::cout << "7. Longitud de la lista" << '\n';
        std::cout << "8. Revisar si el elemento pertenece" << '\n';
        std::cout << "9. Borrar todos los elementos iguales a lo ingresado" << '\n';
        std::cout << "10. Salir del programa" << '\n';

        std::cin >> opcion;

        switch(opcion){
            case 1:
                lista = crearLista();
                std::cout << "Se creo correctamente la lista" << '\n';
                break;
            case 2:
                std::cout << ((esListaVacia(lista)) ? "La lista está vacía" : "La lista no está vacía") << '\n';
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                auxiliar++;
                break;
        }

    }
    return 0;
}

Lista crearLista(){
    return nullptr;
}

bool esListaVacia(Lista const lista){
    return lista == nullptr;
}

void mostrar(Lista lista){
    std::cout << "---- Lista ----" << '\n';
    while(!esListaVacia(lista)){
        std::cout << "Dato: " << lista->dato << '\n';
        lista = lista->siguiente;
    }
}

item primerElemento(Lista const lista){
    return esListaVacia(lista) ? NULL : lista->dato;
}

Lista insertar(Lista lista, item objeto){
    auto temporal = new struct Nodo;
    temporal->dato = objeto;
    temporal->siguiente = lista;
    lista = temporal;
    return lista;
}

Lista borrar(Lista lista){
    Lista temporal = lista->siguiente;
    lista = lista->siguiente->siguiente;
    delete temporal;
    return lista;
}

int32_t longitud(Lista lista){
    int32_t contador = 0;
    while(!esListaVacia(lista)){
        lista = lista->siguiente;
        contador++;
    }
    return contador;
}

bool pertenece(Lista lista, item objeto){
    while(!esListaVacia(lista)){
        if(lista->dato == objeto)
            return true;
        lista = lista->siguiente;
    }
    return false;
}

Lista borrarK(Lista lista, item objeto){
    Lista nueva = crearLista();

    while(!esListaVacia(lista)){
        if(lista->dato == objeto){
            nueva = borrar(lista);
        }
        lista = lista->siguiente;
    }
    return nueva;
}