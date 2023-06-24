#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string NomProduct;
    int codigo;
    string marca;
    int precio;
};

void InsertarProducto(Producto producto[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        //insertar datos
        cout << "nombre del producto: ";
        getline(cin, producto[i].NomProduct);
        cout << "marca: ";
        getline(cin, producto[i].marca);
        cout << "precio: ";
        cin >> producto[i].precio;
        cin.ignore(); // Ignorar el salto de línea después de leer el entero

       //organizar codigo
        if (producto[i].NomProduct == "martillo" || producto[i].NomProduct == "Martillo") {
            producto[i].codigo = 100; 
        } else if (producto[i].NomProduct == "destornillador" || producto[i].NomProduct == "Destornillador") {
            producto[i].codigo = 200;
        } else {
            // Si no se reconoce el nombre del producto, asignar un código por defecto
            producto[i].codigo = 0;
        }
    }
}

//algoritmo de ordenamiento burbuja
void OrdenarLista(Producto array[], int SIZE) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (array[j].codigo > array[j + 1].codigo || 
                (array[j].codigo == array[j + 1].codigo && array[j].NomProduct > array[j + 1].NomProduct)) {
                // Intercambio de elementos
                Producto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    Producto lista[4];

    //insertar productos
    InsertarProducto(lista, 4);
    OrdenarLista(lista, 4);

     //imprimir lista de productos
    for (int i = 0; i < 4; i++) {
        cout << "Producto " << i + 1 << ":" << endl;
        cout << "Nombre: " << lista[i].NomProduct << endl;
        cout << "Marca: " << lista[i].marca << endl;
        cout << "Precio: " << lista[i].precio << endl;
        cout << "Código: " << lista[i].codigo << endl;
        cout << endl;
    }

    return 0;
}
