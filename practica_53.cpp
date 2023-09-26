#include <iostream>
#include <string>
using namespace std;

struct NodoColaBanco {
    string nombre;
    NodoColaBanco* siguiente;
};

//crear nodo
NodoColaBanco* crearNodo(string valor) { 
    NodoColaBanco* nuevoNodo = new Nodo; 
    nuevoNodo -> nombre = valor; 
    nuevoNodo -> siguiente = nullptr; 
    return nuevoNodo; 
}

// Función para insertar un elemento en la cola 
void encolar(NodoColaBanco*& frente, NodoColaBanco*& final, string valor) { 
    NodoColaBanco* nuevoNodo = crearNodo(valor); 
    if (final == nullptr) { 
        frente = final = nuevoNodo; 
    } else { 
        final->siguiente = nuevoNodo; 
        final = nuevoNodo; 
    } 
}

// Función para eliminar y obtener el elemento del frente de la cola 
string desencolar(NodoColaBanco*& frente, NodoColaBanco*& final) { 
    if (frente == nullptr) { 
        cout << "La cola está vacía." << endl; 
        return nullptr; // Valor de error 
    } 
    string valor = frente-> nombre; 
    NodoColaBanco* temp = frente; 
    frente = frente->siguiente; 
    if (frente == nullptr) { 
        final = nullptr; // Si se elimina el último elemento, actualizar 'final' 
    } 
    delete temp; 
    return valor; 
}
 
// Función para verificar si la cola está vacía 
bool isEmpty(NodoColaBanco* frente) { 
    return frente == nullptr; 
}

int main() {
    //declaramos las colas
    NodoColaBanco* frente = nullptr; 
    NodoColaBanco* final = nullptr;

    while(true) {
        int opcion;

        cout << "---- cola del banco-----" << endl;
        cout << "1. nuevo cliente" << endl;
        cout << "2. primer cliente en la cola" << endl;
        cout << "3. cliente a la espera de ser atendido" << endl;
        cout << "4. salir" << endl;
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                string nombre;
                cout << "-----Saque turno-------" << endl;
                cout << "nombre: ";
                getline(cin, nombre);
                encolar(frente, final, nombre);
            case 2:
                desencolar(frente, final);
        }
    }

    return 0;
}