//gestion de la cola de pedidos en un restaurante de comida rapida
#include <iostream>
#include <string>
using namespace std;

//estructuras
struct Pedido {
    int numeroPedido;
    string descripcion;
    int complejidad;
    int urgencia;
};

struct NodoPedido {
    Pedido pedido;
    NodoPedido* sgte;
};

struct ColaPedidos {
    NodoPedido* frente;
    NodoPedido* fin;
};


//funciones 
//------1-------
void InicializarColas(ColaPedidos colas[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        colas[i].frente = NULL;
        colas[i].fin = NULL;
    }
}

//------2-------
//parametros de complejidad y urgencia 1 a 5 ordenar en funcion de la urgencia y complejidad
void AgregarPedido(ColaPedidos colas[], int numeroPedido, string descripcion, int complejidad, int urgencia) {
    NodoPedido* nuevo = new NodoPedido;
    nuevo->pedido.numeroPedido = numeroPedido;
    nuevo->pedido.descripcion = descripcion;
    nuevo->pedido.complejidad = complejidad;
    nuevo->pedido.urgencia = urgencia;
    nuevo->sgte = NULL;
    
    if (urgencia == 1) {
        if (colas[0].frente == NULL) {
            colas[0].frente = nuevo;
            colas[0].fin = nuevo;
        }
        else {
            colas[0].fin->sgte = nuevo;
            colas[0].fin = nuevo;
        }
    }
    else if (urgencia == 2) {
        if (colas[1].frente == NULL) {
            colas[1].frente = nuevo;
            colas[1].fin = nuevo;
        }
        else {
            colas[1].fin->sgte = nuevo;
            colas[1].fin = nuevo;
        }
    }
    else if (urgencia == 3) {
        if (colas[2].frente == NULL) {
            colas[2].frente = nuevo;
            colas[2].fin = nuevo;
        }
        else {
            colas[2].fin->sgte = nuevo;
            colas[2].fin = nuevo;
        }
    }
    else if (urgencia == 4) {
        if (colas[3].frente == NULL) {
            colas[3].frente = nuevo;
            colas[3].fin = nuevo;
        }
        else {
            colas[3].fin->sgte = nuevo;
            colas[3].fin = nuevo;
        }
    }
    else if (urgencia == 5) {
        if (colas[4].frente == NULL) {
            colas[4].frente = nuevo;
            colas[4].fin = nuevo;
        }
        else {
            colas[4].fin->sgte = nuevo;
            colas[4].fin = nuevo;
        }
    }
}

//------3-------
Pedido PedidoMasUrgente(ColaPedidos colas[]) {
    Pedido pedidoMasUrgente;
    pedidoMasUrgente.urgencia = 0;
    for (int i = 0; i < 5; i++) {
        if (colas[i].frente != NULL) {
            if (colas[i].frente->pedido.urgencia > pedidoMasUrgente.urgencia) {
                pedidoMasUrgente = colas[i].frente->pedido;
            }
        }
    }
    return pedidoMasUrgente;
}

//borrar el pedido una vez atendido
void BorrarPedido(ColaPedidos colas[], int numeroPedido) {
    for (int i = 0; i < 5; i++) {
        if (colas[i].frente != NULL) {
            if (colas[i].frente->pedido.numeroPedido == numeroPedido) {
                NodoPedido* aux = colas[i].frente;
                colas[i].frente = colas[i].frente->sgte;
                delete aux;
            }
        }
    }
}

//------4-------
//verifica si todas las colas estan vacias (1 = true, 0 = false)
int ColasVacia(ColaPedidos cola[]) {
    for (int i = 0; i < 5; i++) {
        if(cola[i].frente != NULL) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ColaPedidos colas[5];
    InicializarColas(colas, 5);
    while(true) {
        cout << "Bienvenido al sistema de pedidos" << endl;
        cout << "1. Agregar pedido" << endl;
        cout << "2. Atender pedido" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cin >> opcion;
        if(opcion == 1) {
            int numeroPedido;
            string descripcion;
            int complejidad;
            int urgencia;
            cout << "Ingrese el numero de pedido: ";
            cin >> numeroPedido;
            cout << "Ingrese la descripcion del pedido: ";
            cin >> descripcion;
            cout << "Ingrese la complejidad del pedido: ";
            cin >> complejidad;
            cout << "Ingrese la urgencia del pedido: ";
            cin >> urgencia;
            AgregarPedido(colas, numeroPedido, descripcion, complejidad, urgencia);
        } else if(opcion == 2) {
            if(ColasVacia(colas)) {
                cout << "No hay pedidos para atender" << endl;
            } else {
                Pedido pedidoMasUrgente = PedidoMasUrgente(colas);
                cout << "El pedido mas urgente es: " << pedidoMasUrgente.descripcion << endl;
                BorrarPedido(colas, pedidoMasUrgente.numeroPedido);
            }
        } else if(opcion == 3) {
            break;
        } else {
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}