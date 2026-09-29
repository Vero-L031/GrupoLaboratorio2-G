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

nodo *lista = nullptr;

void insertarFinal(nodo *&lista, producto p);


int main() {
    producto producto;
    int opcion;

    do {
        std::cout << "\ninventario tiendita pro" << std::endl;
        std::cout << "1. Registrar un nuevo producto " << std::endl; //funcion 1- insertar al final
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cin.ignore();
                std::cout << "Ingrese el codigo del producto: ";
                std::getline(std::cin, producto.codigo);
                std::cout << "Ingrese el nombre del producto: ";
                std::getline(std::cin, producto.nombre);
                std::cout << "Ingrese el precio del producto: ";
                std::cin >> producto.precio;
                
                insertarFinal(lista, producto);
                break;
            case 2:
                
                break;
            case 3:
              
                break;
            case 4:
                
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}

void insertarFinal(nodo *&lista, producto p) {
    nodo *nuevo_nodo = new nodo(); nuevo_nodo->info_product = p;  nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;

    
    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else {
        nodo *temporal = lista;
        
        while (temporal->siguiente != nullptr) {
            temporal = temporal->siguiente;
        }
      
        temporal->siguiente = nuevo_nodo; nuevo_nodo->anterior = temporal;
    }
    std::cout << "Producto enlistado." << std::endl;
}

