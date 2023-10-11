//pokedex
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//estructura q define los pokemon
struct Pokemon {
    int num;
    string nombre;
    string tipo;
    string subTipo;
    string desc;
}

//nodo de la estrucutra arborea
struct Nodo {
    Pokemon pokemon;
    Nodo* izq;
    Nodo* der;
}

//funcion para crear un nodo
Nodo* crearNodo(Pokemon pokemon) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->pokemon = pokemon;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

//funcion para insertar un nodo en el arbol
void insertarNodo(Nodo*& arbol, Pokemon pokemon) {
    if (arbol == NULL) {
        arbol = crearNodo(pokemon);
    }
    else if (pokemon.num < arbol->pokemon.num) {
        insertarNodo(arbol->izq, pokemon);
    }
    else {
        insertarNodo(arbol->der, pokemon);
    }
}

//funcion para crear pokemon
Pokemon crearPokemon() {
    Pokemon pokemon;
    cout << "Ingrese el numero del pokemon: ";
    cin >> pokemon.num;
    cout << "Ingrese el nombre del pokemon: ";
    cin >> pokemon.nombre;
    cout << "Ingrese el tipo del pokemon: ";
    cin >> pokemon.tipo;
    cout << "Ingrese el subtipo del pokemon: ";
    cin >> pokemon.subTipo;
    cout << "Ingrese la descripcion del pokemon: ";
    getline (cin, pokemon.desc);
    return pokemon;
}

//funcion para agregar pokemon a un arbol
void agregarPokemon(Nodo* &arbol) {
    Pokemon pokemon = crearPokemon();
    insertarNodo(arbol, pokemon);
}

//funcion para buscar pokemon en el arbol por nombre
void buscarPokemon(Nodo* arbol) {

    string nombre;

    cout << "-------Buscador de pokemon-------" << endl;
    cout << "Ingrese el nombre del pokemon: ";
    cin >> nombre;

    if (arbol == NULL) {
        cout << "No se encontro el pokemon" << endl;
    }
    else if (nombre == arbol->pokemon.nombre) {
        cout << "Pokemon encontrado" << endl;
        cout << "Numero: " << arbol->pokemon.num << endl;
        cout << "Nombre: " << arbol->pokemon.nombre << endl;
        cout << "Tipo: " << arbol->pokemon.tipo << endl;
        cout << "Subtipo: " << arbol->pokemon.subTipo << endl;
        cout << "Descripcion: " << arbol->pokemon.desc << endl;
    }
    else if (nombre < arbol->pokemon.nombre) {
        buscarPokemon(arbol->izq, nombre);
    }
    else {
        buscarPokemon(arbol->der, nombre);
    }
}

//funcion para mostrar el arbol inorder
void mostrarInorder(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarInorder(arbol->izq);
        cout << "Numero: " << arbol->pokemon.num << endl;
        cout << "Nombre: " << arbol->pokemon.nombre << endl;
        cout << "Tipo: " << arbol->pokemon.tipo << endl;
        cout << "Subtipo: " << arbol->pokemon.subTipo << endl;
        cout << "Descripcion: " << arbol->pokemon.desc << endl;
        mostrarInorder(arbol->der);
    }
}

//funcion para guardar los datos de los pokemon en un archivo de texto
void guardarDatos(Nodo* arbol) {
    FILE* archivo = fopen("pokedex.txt", "w");
    if (archivo == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    if (arbol != NULL) {
        guardarDatos(arbol->izq);
        fprintf(archivo, "Numero: %d\n", arbol->pokemon.num);
        fprintf(archivo, "Nombre: %s\n", arbol->pokemon.nombre);
        fprintf(archivo, "Tipo: %s\n", arbol->pokemon.tipo);
        fprintf(archivo, "Subtipo: %s\n", arbol->pokemon.subTipo);
        fprintf(archivo, "Descripcion: %s\n", arbol->pokemon.desc);
        guardarDatos(arbol->der);
    }

    fclose(archivo);
}

//funcion para cargar los datos de los pokemon desde un archivo de texto a un arbol
void cargarDatos(Nodo* &arbol) {
    Pokemon pokemon;
    FILE* archivo = fopen("pokedex.txt", "r");
    while (fread(&pokemon, sizeof(Pokemon), 1, archivo)) {
        insertarNodo(arbol, pokemon);
    }
    fclose(archivo);
}

//funcion para limpiar el terminal tras 30 segundos
void limpiarTerminal() {
    Sleep(30000);
    system("cls");
}

int main() {
    Nodo* arbol = NULL;
    cargarDatos(arbol);

    while(true) {
        
        cout << "-------Pokedex-------" << endl;
        cout << "1. Agregar pokemon" << endl;
        cout << "2. Buscar pokemon" << endl;
        cout << "3. Mostrar todos los pokemon" << endl;
        cout << "4. salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion;
        cin >> opcion;

        if(opcion == 1) {
            agregarPokemon(arbol);
            limpiarTerminal();
        }
        else if(opcion == 2) {
            buscarPokemon(arbol);
            limpiarTerminal();
        }
        else if(opcion == 3) {
            mostrarInorder(arbol);
            limpiarTerminal();
        }
        else if(opcion == 4) {
            guardarDatos(arbol);
            break;
        }
        else {
            cout << "Opcion invalida" << endl;
            limpiarTerminal();
        }
    }

}