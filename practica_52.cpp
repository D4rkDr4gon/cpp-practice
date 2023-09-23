#include <iostream>
#include <string>
using namespace std;

struct Cancion {
    sting nombre;
    int puntuacion = 0;
};

struct NodoCanciones {
    Cancion nombre;
    NodoCanciones* siguiente;
};

// Función para crear un nuevo nodo 
NodoCanciones* crearNodo(string valor) { 
    NodoCanciones* nuevoNodo = new NodoCanciones; 
    nuevoNodo->nombre.nombre = valor; 
    nuevoNodo->siguiente = nullptr; 
    return nuevoNodo; 
} 

Nodo* CargarHistorial(NodoCanciones* inicio, Cancion valor) { 
    NodoCanciones* nuevoNodo = crearNodo(valor); 
    if (inicio == nullptr) { 
        inicio = nuevoNodo; 
    } else { 
        Nodo* actual = inicio; 
        while (actual->siguiente != nullptr) { 
            actual = actual->siguiente; 
        } 
        actual->siguiente = nuevoNodo; 
    } 
    return inicio; 
} 

// Función para imprimir una lista enlazada simple 
void ImprimirHistorial(NodoCanciones* inicio) { 
    NodoCanciones* actual = inicio; 
    while (actual != nullptr) { 
        cout << actual -> nombre.nombre << " " << actual -> nombre.puntuacion << endl; 
        actual = actual->siguiente; 
    } 
     
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
    Cancion proximaCancion;
    
    proximaCancion = pop(pila);
    cout << "la cancion q se reproduce es: " << proximaCancion << endl;
    cout << "puntuar la cancion: (1* - 5*)" << endl;
    cin >> proximaCancion.puntuacion;
    CargarHistorial(historial, proximaCancion);
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
    //inicializar la 
    NodoCanciones* pila = nullptr;
    NodoCanciones* listaHistorial = nullptr;
    

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
        } else if(opcion == 5) {
                ImprimirHistorial(historial);
        }
         else if (opcion == 6) {
            cout << "reproduccion terminada" << endl;
            break;
        } else {
            cout << "opcion invalida" << endl;
        }
    }

    return 0;
}