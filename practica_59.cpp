#include <iostream>
#include <string>
using namespace std;

struct NodoTarea {
   string descripcion;    
   NodoTarea* sgte;
};

struct ListaPorTipo {    
    NodoTarea pilaDeTareas;
    int codigoTipo;    
    NodoTarea* sgte;
};



//-----1-------
ListaPorTipo* AgregarNuevaListaPorTipo(ListaPorTipo* lista, int codigoTipo) {
    ListaPorTipo* nodo = new ListaPorTipo;
    nodo->codigoTipo = codigoTipo;
    nodo->sgte = nullptr;
    nodo->pilaDeTareas = nullptr;
    
    //agrega la nueva lista al final
    ListoPorTipo* anterior = nullptr;
    ListaPorTipo* aux = lista;

    if(lista == nullptr) {
        lista = nodo;
    } else {
        while(aux != nullptr) {
            anterior = aux;
            aux = aux-> sgte;
        }
    }
    return nodo;
}

//-----2-------
void AgregarTarea(ListaPorTipo* lista, int codigoTipo, string descripcion) {
    ListaPorTipo* aux = lista;
    ListaPorTipo* anterior = nullptr;

    //encuentra la lista
    while(aux !=nullptr && aux->codigoTipo != codigoTipo) {
        anterior = aux;
        aux = aux->sgte;
    }

    //en caso de no encontrarla
    if(lista == nullptr) {
        ListaPortipo* nuevaLista = AgregarNuevaListaPorTipo(lista, codigoTipo);
    }

    //agregar la tarea
    NodoTarea* nuevaTarea = new NodoTarea;
    nuevaTarea->descripcion = descripcion;
    nuevaTarea->sgte = aux-> pilaDeTareas;
    aux->pilaDeTareas = nuevaTarea;

}

//-----3-------
string dameProximaTarea(ListaPorTipo* lista, int codigoTipo) {
    ListaPorTipo* aux = lista;

    while(aux != nullptr) {
        if(aux->codigoTipo == codigoTipo) {
            return aux->pilaDeTareas->descripcion;
        }
        aux = aux->sgte;
    }

    return nullptr;
}

//-----4-------
int dameCantidadDePilasConTareasPendientes(ListaPorTipo* lista) {
    int cantidad = 0;
    ListaPorTipo* aux = lista;

    while(aux != nullptr) {
        if(aux->pilaDeTareas != nullptr) {
            cantidad++; // cantidad = cantidad + 1
        }
        aux = aux->sgte;
    }

    return cantidad;
}

int main() {
    while(true) {
        cout << "Bienvenidao al sistema de tareas Practica Parcial" << endl;
        cout << "1. Agregar tarea" << endl;
        cout << "2. Dame proxima tarea" << endl;
        cout << "3. Dame cantidad de pilas con tareas pendientes" << endl;
        cout << "4. Agregar lista por tipo" << endl; //agregado para probar el punto "1
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion;
        cin >> opcion;

        if(opcion == 1) {
            cout << "Ingrese el codigo de tipo de tarea: ";
            int codigoTipo;
            cin >> codigoTipo;
            cout << "Ingrese la descripcion de la tarea: ";
            string descripcion;
            getline(cin, descripcion);
            AgregarTarea(lista, codigoTipo, descripcion);
        } else if (opcion == 2) {
            cout << "Ingrese el codigo de tipo de tarea: ";
            int codigoTipo;
            cin >> codigoTipo;
            string descripcion = dameProximaTarea(lista, codigoTipo);
            if(descripcion == nullptr) {
                cout << "No hay tareas pendientes para el tipo de tarea ingresado" << endl;
            } else {
                cout << "La proxima tarea es: " << descripcion << endl;
            }
        } else if (opcion == 3) {
            int cantidad = dameCantidadDePilasConTareasPendientes(lista);
            cout << "La cantidad de pilas con tareas pendientes es: " << cantidad << endl;
        } else if (opcion == 4) {
            cout << "Ingrese el codigo de tipo de tarea: ";
            int codigoTipo;
            cin >> codigoTipo;
            AgregarNuevaListaPorTipo(lista, codigoTipo);
        } else if (opcion == 5) {
            cout << "Gracias por utilizar el sistema" << endl;
            break;
        } else {
            cout << "Opcion incorrecta" << endl;
        }
    }
}