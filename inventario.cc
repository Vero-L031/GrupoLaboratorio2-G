#include <iostream>
#include <string>

struct producto {
    std::string codigo;
    std::string nombre;
    float precio;
};

struct nodo {
    producto info_product;
    nodo *siguiente;
    nodo *anterior;
};

void insertarFinal(nodo *&lista, producto p);

int main() {
    nodo *lista = nullptr;
    producto nuevo_producto;
    int opcion;

    do {
        std::cout << "\ninventario tiendita pro" << std::endl;
        std::cout << "1. Registrar un nuevo producto" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cin.ignore();
                std::cout << "Ingrese el codigo del producto: ";
                std::getline(std::cin, nuevo_producto.codigo);
                std::cout << "Ingrese el nombre del producto: ";
                std::getline(std::cin, nuevo_producto.nombre);
                std::cout << "Ingrese el precio del producto: ";
                std::cin >> nuevo_producto.precio;
                
                insertarFinal(lista, nuevo_producto);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 4);

    while (lista != nullptr) {
        nodo *temporal = lista;
        lista = lista->siguiente;
        delete temporal;
    }

    return 0;
}

void insertarFinal(nodo *&lista, producto p) {
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->info_product = p;
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;

    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else {
        nodo *temporal = lista;
        
        while (temporal->siguiente != nullptr) {
            temporal = temporal->siguiente;
        }
      
        temporal->siguiente = nuevo_nodo; 
        nuevo_nodo->anterior = temporal;
    }
    std::cout << "Producto enlistado." << std::endl;
}
