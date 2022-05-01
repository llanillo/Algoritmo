#include <iostream>
#include <string>

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
bool estaContenida(Lista primera, Lista segunda);
Lista crearListaFija(int32_t opcion);

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
            std::cout << "10. Ejecutar funcion para comprobar si una lista esta contenida en otra" << '\n';
            std::cout << "11. Salir del programa" << '\n' << '\n';
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
                mostrar(lista);
                break;
            case 10:
                std::cout << '\n' << ((estaContenida(crearListaFija(1), crearListaFija(0))) ? "La primera lista esta contenida" : "La primera lista no esta contenida") << '\n';
                break;
            default:
                auxiliar = 0;
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
    if (lista == nullptr) return lista;

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
    Lista cabecera = lista; // Auxiliar que apunta al inicio de mi lista

    // lista es otro auxiliar para recorrer toda la lista

    // Pueden suceder dos casos, el número k se encuentra al inicio
    // o se encuentra en el medio
    while (!esListaVacia(lista)) {
        // Este es el primer caso, para ir moviendo la cabecera
        if(cabecera->dato == objeto){
            lista = lista->siguiente;
            cabecera = borrar(cabecera);
        }
        // Segundo caso, esta en el medio
        else{
            // pregunto si el siguiente del que me encuentro tiene el valor que quiero reemplazar
            // si es asi, lo borro
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

    if(esListaVacia(primera) && esListaVacia(segunda)){
        return true;
    }
    else{
        while(!esListaVacia(primera)){
            if(pertenece(segunda, primerElemento(primera))){
                primera = primera->siguiente;
            }
            else{
                return false;
            }
        }

        return true;
    }

    return esListaVacia(primera);
}

Lista crearListaFija(int32_t opcion) {
    Lista lista = crearLista();
    int32_t opcion1[] = {2, 3, 6};
    int32_t opcion2[] = {2, 5, 8,9};

    if(opcion){
        for (unsigned int i = 0; i < sizeof(opcion1) / sizeof(opcion1[0]); i++){
            lista = insertar(lista, opcion1[i]);
        }
        return lista;
    }
    else{
        for (unsigned int i = 0; i < sizeof(opcion2) / sizeof(opcion2[0]); i++){
            lista = insertar(lista, opcion2[i]);
        }
        return lista;
    }
}