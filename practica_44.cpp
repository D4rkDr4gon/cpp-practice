#include <iostream>
using namespace std;

/*Crea una estructura llamada "Factura" con los atributos "numero", "fecha" y "monto" e
implementa un sistema donde el usuario pueda ingresar los datos de 10 facturas.
Luego, el sistema solicitará al usuario que ingrese un número de factura a buscar. 
Utilizando un algoritmo de búsqueda adecuado, se determinará si la factura está presente en el conjunto de facturas cargadas.
Si se encuentra, se mostrará su número, fecha y monto. Además, se brindará información adicional según el enunciado.*/

struct Fecha {
    int dia;
    int mes;
    int año;
};


struct Factura {
    int numero;
    Fecha fecha;
    float monto;
};

//carga directa
void InsertarFactura (Factura facturas[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        //numero de orden
        facturas[i].numero = i;
        //fecha de la orden
        cout << "dia de hoy: ";
        cin >> facturas[i].fecha.dia;
        cout << "mes actual: ";
        cin >> facturas[i].fecha.mes;
        cout << "año actual: ";
        cin >> facturas[i].fecha.año;
        //monto de la orden
        cout << "precio de la orden: ";
        cin >> facturas[i].monto;
    }
}

//busqueda binaria
void BuscarFactura (Factura facturas[], int SIZE) {
    //ingrese valor buscado
    int valorBuscado;
    cout << "indique numero de factura: ";
    cin >> valorBuscado;

    //inicio y final
    int inicio = 0;
    int final = SIZE;

    while (inicio <= final) {
        int medio = (inicio + final) / 2;

        if(facturas[medio].numero == valorBuscado) {
            cout << "la factura buscada es: ";
            cout << facturas[medio].monto << endl 
                 << facturas[medio].numero << endl
                 << facturas[medio].fecha.dia << "/" << facturas[medio].fecha.mes << "/" << facturas[medio].fecha.año << endl;
        } else if (facturas[medio].numero < valorBuscado) {
            inicio = medio + 1; //convierte el inicio en el medio permitiendo reducir el espacio de busqueda
        } else if (facturas[medio].numero > valorBuscado) {
            final = medio - 1; //convierte el medio en el final permitiendo reducir el espacio de busquda
        }
    }

}


int main(){
    //variable tamaño immodificable
    const int SIZE = 10;
    //array
    Factura facturas[SIZE];
    char decision;

    cout << "buenos dias, iniciando sistema de facturacion" << endl
         << "---------------------------------------------" << endl
         << "sistema iniciado..." << endl;
    InsertarFactura(facturas, SIZE);
    cout << "dia finalizado, desea revisar las facturas? S/N" << endl;
    cin >> decision;
    if (decision == 'S' || decision == 's') {
        BuscarFactura(facturas, SIZE);
    } 

    return 0;
}