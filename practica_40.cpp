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

//algoritmo de busqueda binaria
int BuscarProducto(const Producto array[], int SIZE, const string& nombre, const string& marca) {
    int izq = 0;
    int der = SIZE - 1;

    while (izq <= der) {
        int mid = izq + (der - izq) / 2;

        // Comparar el nombre y marca del producto en la posición "mid" con el nombre y marca buscados
        if (array[mid].NomProduct == nombre && array[mid].marca == marca) {
            return mid;  // Se encontró el producto, devolver su índice
        } else if (array[mid].NomProduct < nombre || (array[mid].NomProduct == nombre && array[mid].marca < marca)) {
            izq = mid + 1;  // El producto buscado está en la mitad derecha del subarray
        } else {
            der = mid - 1;  // El producto buscado está en la mitad izquierda del subarray
        }
    }

    return -1;  // No se encontró el producto
}


int main() {
    //array
    Producto lista[4];
    //variables
    string nombre;
    string marca;

    //insertar productos
    InsertarProducto(lista, 4);

    //ordenar productos
    OrdenarLista(lista, 4);

    cout << "-------------------------" << endl;

    //buscar productos
    int indice = BuscarProducto(lista, 4, nombre, marca);
    
    cout << "nombre del producto a buscar: ";
    getline(cin, nombre);
    cout << "marca del producto a buscar: ";
    getline(cin, marca);
    
    if (indice != -1) {
        cout << "El producto se encuentra en la posición " << indice << endl;
    } else {
        cout << "El producto no fue encontrado" << endl;
    }


    cout << "-------------------------" << endl;

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
