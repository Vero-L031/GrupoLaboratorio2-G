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
