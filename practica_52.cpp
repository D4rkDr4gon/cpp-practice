#include <iostream>
#include <string>
using namespace std;

struct NodoCanciones {
    string nombre;
    NodoCanciones* siguiente;
};

// Función para crear un nuevo nodo 
NodoCanciones* crearNodo(string valor) { 
    NodoCanciones* nuevoNodo = new NodoCanciones; 
    nuevoNodo->nombre = valor; 
    nuevoNodo->siguiente = nullptr; 
    return nuevoNodo; 
} 
 
 // Función para insertar un elemento en la pila 
void push(NodoCanciones*& pila, string valor) { 
    NodoCanciones* nuevoNodo = crearNodo(valor); 
    nuevoNodo->siguiente = pila; 
    pila = nuevoNodo;
}

// Función para eliminar y obtener el elemento en la cima de la pila 
string pop(NodoCanciones*& pila) { 
    if (pila == nullptr) { 
        cout << "La playlist está vacía." << endl; 
        return nullptr; // Valor de error 
    } 
    string valor = pila->nombre; 
    NodoCanciones* temp = pila; 
    pila = pila->siguiente; 
    delete temp; 
    return valor; 
} 

// Función para verificar si la pila está vacía 
bool isEmpty(NodoCanciones* pila) { 
    return pila == nullptr; 
}

//funcion para reproducir la primera cancion de la lista
void Reproducir (NodoCanciones*& pila, NodoCanciones*& historial) {
    string proximaCancion;

    proximaCancion = pop(pila);
    cout << "la cancion q se reproduce es: " << proximaCancion << endl;
    push(historial, proximaCancion);
}

//funcion q muestra la siguiente cancion
void Mostrar (NodoCanciones*& pila) {
    string proximaCancion;

    proximaCancion = pila -> nombre;
    cout << "la proxima cancion es: " << proximaCancion << endl;
    
}

//funcion para invertir la playlist
void Inversor(NodoCanciones*& pila) {
    //creo una pila temporal
    NodoCanciones* pilaAux = nullptr;
    //la igualo a la pila
    pilaAux = pila;

    //vaciar pila
    pila = nullptr;

    //pasamos los valores de la pila auxiliar a la pila
    while(!isEmpty(pilaAux)) {
        string valor = pop(pilaAux);
        push(pila, valor);
    }

}

int main(){
    //inicializar la pila
    NodoCanciones* pila = nullptr;
    NodoCanciones* historial = nullptr;
    

    //bucle de la interfaz
    while(true) {
        int opcion;
        
        cout << "-------Spotify----------" << endl;
        cout << "tu playlist:" << endl;
        cout << "1. Agregar Cancion" << endl;
        cout << "2. eliminar la primera cancion" << endl;
        cout << "3. tomar cancion para reproducir" << endl;
        cout << "4. invertir la playlist" << endl;
        cout << "5. ver historial de reproduccion" << endl;
        cout << "6. salir" << endl;
        cout << "que desea hacer? ";
        cin >> opcion;

        if (opcion == 1) {
            string cancion;
            cout << "-----agregar cancion-------" << endl;
            cout << "nombre de la cancion: ";
            getline(cin, cancion);
            //agrega a la pila
            push(pila, cancion);
            cout << cancion << "añadida con exito" << endl;
        } else if (opcion == 2) {
            pop(pila);
            cout << " primera cancion eliminada" << endl;
        } else if (opcion == 3) {
            cout << "------panel de reproduccion-------" << endl;
            Reproducir(pila);
            Mostrar(pila);
        } else if (opcion == 4) {
            Inversor(pila);
            cout << "pila invertida" << endl;
        } else if (opcion == 5) {
            cout << "reproduccion terminada" << endl;
            break;
        } else {
            cout << "opcion invalida" << endl;
        }
    }

    return 0;
}