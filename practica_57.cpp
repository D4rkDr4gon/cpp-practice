//practica de final
//creamos una cola principal de 5 miembros y cada uno apunta a una cola de pacientes
#include <iostream>
#include <string>
using namespace std;

struct NodoCola {
    string nombre;
    NodoCola* siguiente;
};

/*
prioridades:
    0 = riesgo de vida
    1 = emergencia grave
    2 = emergencia leve
    3 = urgencia
    4 = dolencia menor
*/

struct TipoInfoPrioridades {
    NodoCola* frente;
    NodoCola* final;
};

struct NodoPrioridad {
    TipoInfoPrioridades info;
    NodoPrioridad* siguiente;
};


/*
Retorna el puntero a una lista con cinco nodos, en cada uno de los cuales <ene un puntero 
al  frente  y  otro  al  fin  de  la  cola  de  pacientes  según  la  prioridad.  El  primer  nodo 
corresponde a prioridad 0 (cero) y el quinto nodo al de prioridad 4 (cuatro).
*/

NodoPrioridad* CrearNodoPrioridad() {
    NodoPrioridad* nuevo = new NodoPrioridad;
    nuevo->info.frente = NULL;
    nuevo->info.final = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

NodoPrioridad* CrearColaPrioridad() {
    NodoPrioridad* colaprioridad = nullptr;
    for (int i = 0; i <5; i++) {
        NodoPrioridad* nuevo = CrearNodoPrioridad();
        nuevo->siguiente = colaprioridad;
        colaprioridad = nuevo;
    }
    return colaprioridad;
}


/*
Inserta  la  cadena  representada  con  char*  (el  nombre  de  un  paciente)  en  la  prioridad 
indicada por el entero. Precondicion: la cadena no debe ser vacia y la prioridad esta en el 
rango [0..4].
*/

void InsertarEnPrioridad(NodoPrioridad* &colaPrioridad, int prioridad, string nombre) {
   NodoCola* nuevo = new NodoCola;
   nuevo -> nombre = nombre;
   nuevo -> siguiente = NULL;
   if (colaPrioridad == NULL) {
       colaPrioridad = CrearColaPrioridad();
   }
    NodoPrioridad* aux = colaPrioridad;
    for (int i = 0; i < prioridad; i++) {
        aux = aux->siguiente;
    }
    if (aux->info.frente == NULL) {
        aux->info.frente = nuevo;
        aux->info.final = nuevo;
    } else {
        aux->info.final->siguiente = nuevo;
        aux->info.final = nuevo;
    }
}

/*
Recibe el puntero a la lista que contiene las colas. Retorna el puntero al nodo que contiene 
el puntero a la cola no vacia de la mayor prioridad. Precondicion:al menos una cola No 
vacia
*/

NodoPrioridad* ElementoMinimo (NodoPrioridad* &colaPrioridad) {
    NodoPrioridad* aux = colaPrioridad;

    while (aux != NULL) {
        if (aux->info.frente == NULL) {
            aux = aux->siguiente;
        }else {
            return aux;
        }
    }

    return NULL;
}

/*
Retorna  el  nombre  del  paciente  de  la  cola  de  mayor  prioridad.  
Precondicion:  existe  al menos una cola no vacia
*/

string QuitarMinimo (NodoPrioridad* &colaPrioridad) {
    NodoPrioridad* minimo = ElementoMinimo(colaPrioridad);
    NodoCola* aux = minimo->info.frente;
    string nombre = aux->nombre;
    minimo->info.frente = aux->siguiente;
    delete aux;
    return nombre;
}

/*
Recibe  como  parametro  un  puntero  al  inicio  de  la  lista  que  contiene  las  colas  de 
prioridades. Retorna(todas las colas vacias?1:0).
*/

int PrioridadVacia (NodoPrioridad* &colaPrioridad) {
    NodoPrioridad* aux = colaPrioridad;
    while (aux != NULL) {
        if (aux->info.frente != NULL) {
            return 0;
        }
        aux = aux->siguiente;
    }
    return 1;
}

int main() {
    NodoPrioridad* colaPrioridad = NULL;

    cout << "Bienvenido al sistema de emergencias" << endl;

    while(true) {
        int opcion;
        cout << "[==================================]" << endl;
        cout << "opciones del sistema:" << endl;
        cout << "1. Ingresar paciente" << endl;
        cout << "2. Atender paciente" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "[==================================]" << endl;
        
        if (PrioridadVacia(colaPrioridad) == 1 && opcion != 3) {
            cout << "No hay pacientes en espera" << endl;
        } 

        if (opcion == 1) {
            string nombre;
            int prioridad;
            cout << "Ingrese el nombre del paciente: ";
            cin >> nombre;
            cout << "Ingrese la prioridad del paciente: " << endl
                 << "0 = riesgo de vida" << endl
                 << "1 = emergencia grave" << endl
                 << "2 = emergencia leve" << endl
                 << "3 = urgencia" << endl
                 << "4 = dolencia menor" << endl;
            cin >> prioridad;
            InsertarEnPrioridad(colaPrioridad, prioridad, nombre);
        } else if (opcion == 2) {
            if (PrioridadVacia(colaPrioridad)) {
                cout << "No hay pacientes en espera" << endl;
            } else {
                string nombre = QuitarMinimo(colaPrioridad);
                cout << "El paciente " << nombre << " ha sido atendido" << endl;
            }
        } else if (opcion == 3) {
            cout << "Gracias por usar el sistema de emergencias" << endl;
            break;
        } else {
            cout << "Opcion invalida" << endl;
        }

    }

    return 0;
}