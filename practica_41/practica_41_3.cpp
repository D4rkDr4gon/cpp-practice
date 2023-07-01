#include <iostream>
#include <cstring>
using namespace std;

struct Estudiante {
    int codigo;
    char nombre[50];
    int edad;
};

int buscarEstudiante(const char* nombreBuscado) {
    
    //abre el archivo de practica_41_1
    FILE* archivo = fopen("estudiantes_binarios.dat", "rb");
    
    if (archivo != NULL) {
    
        Estudiante estudiante;
        
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1) {
            
            if (strcmp(estudiante.nombre, nombreBuscado) == 0) {
                cout << "Estudiante encontrado:" << endl;
                cout << "Código: " << estudiante.codigo << endl;
                cout << "Nombre: " << estudiante.nombre << endl;
                cout << "Edad: " << estudiante.edad << endl;
                fclose(archivo);
                return 1;
            }
        }
        //cierra el archivo
        fclose(archivo);
    
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
    return 0;
}

int main() {
    char nombre[50];
    
    cout << "Ingrese el nombre del estudiante a buscar: ";
    cin >> nombre;

    if (!buscarEstudiante(nombre)) {
        cout << "Estudiante no encontrado." << endl;
    }
    
    return 0;
}