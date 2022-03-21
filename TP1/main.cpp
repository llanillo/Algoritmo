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
    int8_t vacia = 0;
    int32_t opcion;

    Lista lista;
    item objeto;

    while(auxiliar){
        std::cout << '\n';
        std::cout << "1. Crear Lista" << '\n';
        if (vacia){
            std::cout << "2. Revisar si la lista esta vacia" << '\n';
            std::cout << "3. Mostrar lista" << '\n';
            std::cout << "4. Mostrar primer elemento" << '\n';
            std::cout << "5. Insertar elemento" << '\n';
            std::cout << "6. Borrar primer elemento" << '\n';
            std::cout << "7. Longitud de la lista" << '\n';
            std::cout << "8. Revisar si el elemento pertenece" << '\n';
            std::cout << "9. Borrar todos los elementos iguales a lo ingresado" << '\n';
            std::cout << "10. Salir del programa" << '\n' << '\n';
        }

        std::cin >> opcion;
        std::cout << '\n';

        switch(opcion){
            case 1:
                lista = crearLista();
                std::cout << "Se creo correctamente la lista\n";
                vacia++;
                break;
            case 2:
                std::cout << ((esListaVacia(lista)) ? "La lista esta vacia" : "La lista no esta vacia") << '\n';
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                std::cout << "Primer elemento  " << primerElemento(lista) << '\n';
                break;
            case 5:
                std::cin >> objeto;
                lista = insertar(lista, objeto);
                mostrar(lista);
                break;
            case 6:
                lista = borrar(lista);
                std::cout << "Se eliminó correctamente el primer elemento" << '\n';
                mostrar(lista);
                break;
            case 7:
                std::cout << "Longitud de la lista  " << longitud(lista) << '\n';
                break;
            case 8:
                std::cout << "Ingrese elemento a buscar\n \n";
                std::cin >> objeto;
                std::cout << '\n' << ((pertenece(lista, objeto)) ? "Si pertenece" : "No pertenece") << '\n';
                break;
            case 9:
                std::cout << "Ingrese elemento a eliminar\n \n" ;
                std::cin >> objeto;
                std::cout << '\n';
                lista = borrarK(lista, objeto);
//                mostrar(lista);
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
    std::cout << "\n---- Lista ----\n";
    while(!esListaVacia(lista)){
        std::cout << lista->dato << "  ";
        lista = lista->siguiente;
    }
    std::cout << '\n';
}

item primerElemento(Lista const lista){
    return esListaVacia(lista) ? NULL : lista->dato;
}

Lista insertar(Lista lista, item objeto){
    auto temporal = new struct Nodo;
    temporal->dato = objeto;
    temporal->siguiente = lista;
    return temporal;    
}

Lista borrar(Lista lista){
    Lista temporal = lista;
    lista = lista->siguiente;
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
    Lista cabecera = lista;

    while (!esListaVacia(lista)) {
        if(cabecera->dato == objeto){
            cabecera = borrar(cabecera);
            lista = lista->siguiente;
        }
        else{
            if(lista->siguiente != nullptr && lista->siguiente->dato == objeto){
                lista->siguiente = borrar(lista->siguiente);
            }
            else{
                lista = lista->siguiente;
            }
        }
    }

    return cabecera;
}

bool estaContenida(Lista primera, Lista segunda){
    int32_t contador = 0;
    int32_t longitudSegunda = longitud(segunda);
    int32_t longitudPrimera = longitud(primera);

    if(longitudPrimera > longitudSegunda) return false;

    while(!esListaVacia(segunda)){
        if(pertenece(segunda, primerElemento(primera)))
            contador++;
        primera = borrar(primera);
    }
    return true;
}