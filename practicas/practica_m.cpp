#include <iostream>
#include <string>
using namespace std;

struct Cancion{
    string nomnbre;
    int puntacion;
};

struct NodoCanciones {
   Cancion nombre;
   NodoCanciones* sgte;        
};

NodoCanciones* CrearNodo(string nombre){
   NodoCanciones* NuevoNodo = new NodoCanciones;
   NuevoNodo->nombre.nomnbre = nombre;
   NuevoNodo->sgte = NULL;
   return NuevoNodo;
}  

//-------Funcion 1--------

void push(NodoCanciones*& pila, string nombre){
    NodoCanciones* NuevoNodo = CrearNodo(nombre);
    NuevoNodo->sgte = pila;
    pila = NuevoNodo;
}

void pushHistorial(NodoCanciones*& pila, string nombre, int puntuacion){
    NodoCanciones* NuevoNodo = CrearNodo(nombre);
    NuevoNodo->nombre.puntacion = puntuacion;
    NuevoNodo->sgte = pila;
    pila = NuevoNodo;
}

void Historial(NodoCanciones*& pila, NodoCanciones*& historial){
    string nombre = pila->nombre.nomnbre;
    NodoCanciones* NuevoNodo = CrearNodo(nombre);
    NuevoNodo->nombre.nomnbre = historial->nombre.nomnbre;
    historial = NuevoNodo;
}

//-------Funcion 2---------
void pop(NodoCanciones* &pila, NodoCanciones* &historial) {
    if(pila != nullptr) {
        // Mostrar el primer valor de la pila
        string nombre = pila->nombre.nomnbre;
        NodoCanciones* temp = pila;
        pila = pila->sgte;
        cout << "la cancion repodriucida es: " << temp->nombre.nomnbre << endl; 
        delete temp;       
        // Pedir una puntuación de 1-5
        int puntuacion;
        do {
            cout << "Por favor, ingresa una puntuación de 1 a 5: ";
            cin >> puntuacion;
        } while(puntuacion < 1 || puntuacion > 5);

        // Asignar la puntuación al historial
        pushHistorial(historial, nombre, puntuacion);


        
    } 
}

void Invertir(NodoCanciones*& pila){
    NodoCanciones* aux = nullptr;
    while(pila != nullptr){
        string nombre = pila->nombre.nomnbre;
        NodoCanciones* temp = pila;
        pila = pila->sgte;
        
        push(aux, nombre);
        delete temp;

    }
    pila = aux;

}

string popHistorial(NodoCanciones*& pila){
    
    if (pila == NULL){          
       return "el historial esta vacio";
    }
    
    string nombre = pila->nombre.nomnbre;
    NodoCanciones* temp = pila;
    pila = pila->sgte;
    cout << temp->nombre.nomnbre << " y la puntuacion es: " << temp->nombre.puntacion << endl;
    delete temp;
    return nombre;
}



int main(){
    NodoCanciones* pila = NULL;
    NodoCanciones* historial = nullptr;

    while(true){
        cout << "Playlist practica" << endl
             << "1. agregar cancion" << endl
             << "2. ver historial" << endl
             << "3. reproducir cancion" << endl
             << "4. invertir" << endl
             << "5. salir" << endl
             << "Elige opcion: " << endl;
        int opcion;
        cin >> opcion;
        cin.ignore();

        if(opcion == 1){
            cout << "nombre de la cancion: " << endl;
            string nombre;
            getline(cin, nombre);
            push(pila, nombre);
            cout << nombre << " añadida con exito." << endl;
        }else if(opcion == 2){
            cout << "historial...." << endl;
            while(historial != nullptr){
                popHistorial(historial);
            } 
            cout << "historial vacio" << endl;
        }else if(opcion == 3){
            pop(pila, historial);
        }else if(opcion == 4) {
            Invertir(pila);
        } else if(opcion == 5) {
            break;
        }else {
            cout << "tecla incorrecta" << endl;
        }
    }    
   
   
    return 0;  
}
