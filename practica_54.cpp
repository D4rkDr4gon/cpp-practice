#include <iostream>
using namespace std;

"Implementa un programa que permita agregar clientes a un árbol binario de búsqueda basado en su número de DNI. 
Cada cliente debe tener un nombre y un DNI. El programa debe proporcionar funciones para agregar clientes 
y mostrar la lista de clientes en orden (inorden) según su DNI"

struct Cliente {
    int DNI;
    string nombre;
};

struct Nodo {
    Cliente cliente;
    Nodo *izq, *der;
};

int main(){


    return 0;
}