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

bool BorrarInicio();
void Imprimir(nodo *lista);
nodo* cabeza = nullptr;
void insertarFinal(nodo *&lista, producto p);

int main() {
    nodo *lista = nullptr;
    producto nuevo_producto;
    int opcion;

    do {
        std::cout << "\ninventario tiendita pro" << std::endl;
        std::cout << "1. Registrar un nuevo producto" << std::endl;
        std::cout << "2. Mostrar productos" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (std::cin.eof()) {
            break;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                std::cin.ignore(1000, '\n');
                std::cout << "Ingrese el codigo del producto: ";
                std::getline(std::cin, nuevo_producto.codigo);
                std::cout << "Ingrese el nombre del producto: ";
                std::getline(std::cin, nuevo_producto.nombre);
                std::cout << "Ingrese el precio del producto: ";
                std::cin >> nuevo_producto.precio;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Precio no valido. Producto no registrado." << std::endl;
                    break;
                }

                insertarFinal(lista, nuevo_producto);
                break;
            case 2:
                Imprimir(lista);
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

void Imprimir(nodo *lista) {
    if (lista == nullptr) {
        std::cout << "No hay productos enlistados." << std::endl;
        return;
    }
    nodo *actual = lista;
    while (actual != nullptr) {
        std::cout << "\nCodigo: " << actual->info_product.codigo;
        std::cout << "\nNombre: " << actual->info_product.nombre;
        std::cout << "\nPrecio: $" << actual->info_product.precio;
        std::cout << "\n------------------------";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}