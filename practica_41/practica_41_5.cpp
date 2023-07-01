#include <iostream>
#include <string>
#include <cstring>

using namespace std;
    struct Estudiante {
    int codigo;
    char nombre[50];
    int edad;
};

void editarEdadEstudiante(int codigoBuscado, int nuevaEdad) {

    FILE* archivo = fopen("estudiantes_binarios.dat", "rb+");

    if (archivo != NULL) {

        Estudiante estudiante;
        bool encontrado = false;

        while (!encontrado && fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1) {

            if (estudiante.codigo == codigoBuscado) {
                encontrado = true;
                estudiante.edad = nuevaEdad;
                fseek(archivo, -sizeof(Estudiante), SEEK_CUR);
                fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
                cout << "Edad actualizada exitosamente." << endl;
            }
        }

        if (!encontrado) {
        cout << "No se encontró un estudiante con ese código." << endl;
        }

        fclose(archivo);

    } else {
        cout << "No se pudo abrir el archivo para lectura y escritura." << endl;
    }
}

int main() {
    int codigoBuscado, nuevaEdad;

    cout << "Ingrese el código del estudiante a buscar: ";
    cin >> codigoBuscado;
    cout << "Ingrese la nueva edad: ";
    cin >> nuevaEdad;

    editarEdadEstudiante(codigoBuscado, nuevaEdad);

    return 0;
}