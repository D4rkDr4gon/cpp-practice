#include <iostream>
using namespace std;

void mostrarArr(int Array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << i << ", " << Array[i] << endl; 
    }
}

//ordenamiento simple
void OrdenSimple (int Array[], int size) {
    //variable auxiliar
    int aux;

    int i, j, ord = 0;

    for(i = 0; i < size -1 && ord == 0; i++) {
        //no esta ordenada
        ord = 1;

        for(j = 0; j < size; j++) {
            
            if (Array[j] > Array[j + 1]) {
               
                aux = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] =  aux;
                //esta ordenada
                ord = 0;

                //muestra cada cambio q hace en el array
                mostrarArr(Array, size);
                cout << "------------------" << endl;
            }
        }
    }
    
}

//busqueda lineal
void BusquedaLineal(int Array[], int size, int valor) {
    for (int i = 0; i < size; i++) {
        if (Array[i] == valor) {
            cout << "la poscision: " << i << " la variable: " << Array[i] << endl;
        }
    }
}

//busqueda binaria
int BusquedaBin(const int Array[], int size, int Valor) {
    int inicio = 0;
    int fin = size -1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (Array[medio] == Valor) {
            return medio + 1;
        } else if (Array[medio] < Valor) {
            
        }
    }


    return -1;
}

//insertar ordenado
void InsertarOrd(int Array[], int size, int elemento) {
    int i = size -1;

    //desplaza elementos mayores a la derecha
    while (i >= 0 && Array[i] < elemento) {
        Array[i + 1] = Array[i];
        i--;
    }

    //elemento a su valor original
    Array[i + 1] = elemento;
}

int main() {
        //array
        int Array[10];
        int elemento;
        
        //algoritmos para ordenar
        /*
        OrdenSimple(Array, 10);
        cout << "-----------------------------" << endl;
        mostrarArr(Array, 10);
        */

       for (int i = 0; i < 10; i++ ) {
        cin >> elemento;
        InsertarOrd(Array, 10, elemento);
       }

       mostrarArr(Array, 10);


    return 0;
}