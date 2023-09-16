#include <iostream> 
 
// Definición de la estructura Nodo 
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
 
// Función para insertar un elemento en la cola 
void encolar(Nodo*& frente, Nodo*& final, int valor) { 
    Nodo* nuevoNodo = crearNodo(valor); 
    if (final == nullptr) { 
        frente = final = nuevoNodo; 
    } else { 
        final->siguiente = nuevoNodo; 
        final = nuevoNodo; 
    } 
} 
 
// Función para eliminar y obtener el elemento del frente de la cola 
int desencolar(Nodo*& frente, Nodo*& final) { 
    if (frente == nullptr) { 
        std::cerr << "La cola está vacía." << std::endl; 
        return -1; // Valor de error 
    } 
    int valor = frente->dato; 
    Nodo* temp = frente; 
    frente = frente->siguiente; 
    if (frente == nullptr) { 
        final = nullptr; // Si se elimina el último elemento, actualizar 'final' 
    } 
    delete temp; 
    return valor; 
} 
 
// Función para verificar si la cola está vacía 
bool isEmpty(Nodo* frente) { 
    return frente == nullptr; 
} 
 
int main() { 
    Nodo* frente = nullptr; 
    Nodo* final = nullptr; 
 
// Encolar elementos 
    encolar(frente, final, 10); 
    encolar(frente, final, 20); 
    encolar(frente, final, 30); 
 
    std::cout << "Elementos en la cola:" << std::endl; 
    while (!isEmpty(frente)) { 
        // Desencolar y mostrar el elemento del frente de la cola 
        int valor = desencolar(frente, final); 
        std::cout << valor << " "; 
    } 
    std::cout << std::endl; 
 
    return 0; 
}
