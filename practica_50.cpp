#include <iostream> 
 
// Definición de la estructura Nodo para listas enlazadas simples 
struct Nodo { 
    int dato; 
    Nodo* siguiente; 
}; 
 
// Función para crear un nuevo nodo 
Nodo* crearNodo(int valor) { 
    Nodo* nuevoNodo = new Nodo; 
    nuevoNodo->dato = valor; 
    nuevoNodo->siguiente = nullptr; 
    return nuevoNodo; 
} 
 
// Función para imprimir una lista enlazada simple 
void imprimirListaSimple(Nodo* inicio) { 
    Nodo* actual = inicio; 
    while (actual != nullptr) { 
        std::cout << actual->dato << " "; 
        actual = actual->siguiente; 
    } 
    std::cout << std::endl; 
} 
 
int main() { 
    // Crear una lista enlazada simple 
    Nodo* listaSimple = crearNodo(10); 
    listaSimple->siguiente = crearNodo(20); 
    listaSimple->siguiente->siguiente = crearNodo(30); 
 
    // Imprimir la lista enlazada simple 
    std::cout << "Lista Simple: "; 
    imprimirListaSimple(listaSimple); 
 
    // Liberar la memoria al final del programa 
    delete listaSimple->siguiente->siguiente; 
    delete listaSimple->siguiente; 
    delete listaSimple; 
 
    return 0; 
}
