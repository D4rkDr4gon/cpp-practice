#include <iostream>
#include <string>
using namespace std;

struct Cancion {
    string nombre;
    int puntuacion = 0;
};

struct NodoCanciones {
    Cancion cancion;
    NodoCanciones* siguiente = nullptr;
};

// Función para crear un nuevo nodo 
NodoCanciones* crearNodo(string valor) { 
    NodoCanciones* nuevoNodo = new NodoCanciones; 
    nuevoNodo->cancion.nombre = valor; 
    return nuevoNodo; 
} 

NodoCanciones* CargarHistorial(NodoCanciones* inicio, Cancion valor) { 
    NodoCanciones* nuevoNodo = crearNodo(valor.nombre); 
    nuevoNodo->cancion.puntuacion = valor.puntuacion; 
    if (inicio == nullptr) { 
        inicio = nuevoNodo; 
    } else { 
        NodoCanciones* actual = inicio; 
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
        cout << actual->cancion.nombre << " " << actual->cancion.puntuacion << endl; 
        actual = actual->siguiente; 
    } 
}

//busqueda de canciones por puntaje
NodoCanciones* BuscarCancionPuntuada(NodoCanciones* inicio, int puntuacion) { 
    NodoCanciones* actual = inicio; 
    while (actual != nullptr) { 
        if (actual->cancion.puntuacion == puntuacion) { 
            return actual; 
        } 
        actual = actual->siguiente; 
    } 
    return nullptr; 
}

//busqueda de canciones por nombre
NodoCanciones* BuscarCancionNombre(NodoCanciones* inicio, string nombre) { 
    NodoCanciones* actual = inicio; 
    while (actual != nullptr) { 
        if (actual->cancion.nombre == nombre) { 
            return actual; 
        } 
        actual = actual->siguiente; 
    } 
    return nullptr; 
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
        return ""; // Valor de error 
    } 
    string valor = pila->cancion.nombre; 
    NodoCanciones* temp = pila; 
    pila = pila->siguiente; 
    delete temp; 
    return valor; 
} 

// Función para verificar si la pila está vacía 
bool isEmpty(NodoCanciones* pila) { 
    return pila == nullptr; 
}

// Función para reproducir la primera canción de la lista
void Reproducir(NodoCanciones*& pila, NodoCanciones*& historial) {
    if (isEmpty(pila)) {
        cout << "La playlist está vacía." << endl;
        return;
    }

    string proximaCancion = pop(pila);
    cout << "La canción que se reproduce es: " << proximaCancion << endl;
    int puntuacion;
    cout << "Puntuar la canción (1* - 5*): ";
    cin >> puntuacion;

    // Verificar que la puntuación esté en el rango válido (1-5)
    if (puntuacion >= 1 && puntuacion <= 5) {
        historial = CargarHistorial(historial, {proximaCancion, puntuacion});
    } else {
        cout << "Puntuación no válida. La canción no será puntuada." << endl;
    }
}

// Función que muestra la siguiente canción
void Mostrar(NodoCanciones* pila) {
    if (isEmpty(pila)) {
        cout << "La playlist está vacía." << endl;
        return;
    }

    cout << "La próxima canción es: " << pila->cancion.nombre << endl;
}

// Función para invertir la playlist
void Inversor(NodoCanciones*& pila) {
    NodoCanciones* pilaAux = nullptr;
    while (!isEmpty(pila)) {
        string valor = pop(pila);
        push(pilaAux, valor);
    }
    pila = pilaAux;
}

int main() {
    NodoCanciones* pila = nullptr;
    NodoCanciones* listaHistorial = nullptr;

    while (true) {
        int opcion;
        cout << "-------Spotify----------" << endl;
        cout << "Tu playlist:" << endl;
        cout << "1. Agregar Cancion" << endl;
        cout << "2. Eliminar la primera cancion" << endl;
        cout << "3. Tomar cancion para reproducir" << endl;
        cout << "4. Invertir la playlist" << endl;
        cout << "5. Ver historial de reproduccion" << endl;
        cout << "6. buscar las canciones previamente puntuadas" << endl;
        cout << "7. buscar las canciones por nombre" << endl;
        cout << "8. Salir" << endl;
        cout << "¿Qué desea hacer? ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string cancion;
            cout << "-----Agregar canción-------" << endl;
            cout << "Nombre de la cancion: ";
            getline(cin, cancion);
            push(pila, cancion);
            cout << cancion << " añadida con exito." << endl;
        } else if (opcion == 2) {
            pop(pila);
            cout << "Primera cancion eliminada." << endl;
        } else if (opcion == 3) {
            cout << "------Panel de reproduccion-------" << endl;
            Reproducir(pila, listaHistorial);
            Mostrar(pila);
        } else if (opcion == 4) {
            Inversor(pila);
            cout << "Playlist invertida." << endl;
        } else if (opcion == 5) {
            ImprimirHistorial(listaHistorial);
        } else if(opcion == 6) {
            cout << "----- Busqueda en funcion de puntuacion-------" << endl;
            int puntuacion;
            
            cout << "ingrese la cantidad de estrellas: " << endl;
            cin >> puntuacion;
            cin.ignore();

            BuscarCancionPuntuada(listaHistorial, puntuacion);
        } else if(opcion == 7) {
            cout << "----- Busqueda en funcion de puntuacion-------" << endl;
            string nombre;
            
            cout << "ingrese la cantidad de estrellas: " << endl;
            cin >> nombre;
            cin.ignore();

            BuscarCancionNombre(listaHistorial, nombre);
        }else if (opcion == 8) {
            cout << "Reproduccion terminada." << endl;
            break;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}
