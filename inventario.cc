#include <iostream>
#include <string> 

struct Producto {
  int codigo;
  string nombre;
  double precio;
};

struct Nodo {
  Producto dato;
  Nodo* anterior;
  Nodo* siguiente;
};

bool BorrarInicio();
void mostrarLista(nodo lista);
Nodo* cabeza = nullptr;


int main() {


  return 0;
}


bool BorrarInicio() {
  if (cabeza == nullptr) {
    return false;
  }
  Nodo* a_borrar = cabeza;
  cabeza = cabeza->siguiente;
  if (cabeza != nullptr) {
    cabeza->anterior = nullptr;
  }
  delete a_borrar;
  return true;
}


/*/
void Imprimir(nodo lista){
if (lista == nullptr) {
std::cout << "No hay productos enlistados." << std::endl;
return;
}
nodo actual = lista;
while (actual != nullptr) {
std::cout << "
Codigo: " << actual->info_product.codigo;
std::cout << "
Nombre: " << actual->info_product.nombre;
std::cout << "
Precio: $" << actual->info_product.precio;
std::cout << "
------------------------";
actual = actual->siguiente;
}
std::cout << std::endl;
}/*/