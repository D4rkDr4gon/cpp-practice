#include <iostream>
#include <cstring>
using namespace std;

struct Estudiante {
int codigo;
char nombre[50];
int edad;
};

Estudiante dameEstudiante(int codigo) {
    Estudiante estudiante;
    estudiante.codigo = codigo;
    cout << "Ingrese el nombre del estudiante: ";
    cin.getline(estudiante.nombre, sizeof(estudiante.nombre));
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;
    cin.ignore(); // Ignorar el salto de línea pendiente en el búfer
    return estudiante;
}

int main() {
    //array
    Estudiante estudiantes[3];
    
    for (int i = 0; i < 3; i++) {
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        estudiantes[i] = dameEstudiante(i + 1);
    }
    
    //crea archivo
    FILE* archivo = fopen("estudiantes_binarios.dat", "wb");
    
    if (archivo != NULL) {
        //escribe en el archivo
        fwrite(estudiantes, sizeof(Estudiante), 3, archivo);
        //cierra el archivo
        fclose(archivo);
        cout << "Archivo creado exitosamente." << endl;
    } else {
        cout << "No se pudo crear el archivo." << endl;
    }

    return 0;
}