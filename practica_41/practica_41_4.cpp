//mismo q practica_41_3 pero con otro algoritmo

#include <iostream>
#include <cstring>
using namespace std;

struct Estudiante {
    int codigo;
    char nombre[50];
    int edad;
};
int buscarEstudiante(int codigoBuscado) {
    //abrir archivo de practica_41_1
    FILE* archivo = fopen("estudiantes_binarios.dat", "rb");
    
    if (archivo != NULL) {
        Estudiante estudiante;
        //funcion de buqueda directa
        fseek(archivo, (codigoBuscado - 1) * sizeof(Estudiante), SEEK_SET);
        
        if (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1) {
            cout << "Estudiante encontrado:" << endl;
            cout << "Código: " << estudiante.codigo << endl;
            cout << "Nombre: " << estudiante.nombre << endl;
            cout << "Edad: " << estudiante.edad << endl;
            fclose(archivo);
            return 1;
        }

        fclose(archivo);
        
        } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        }
        
        return 0;
    }

int main() {
    int codigo;
    
    cout << "Ingrese el código del estudiante a buscar: ";
    cin >> codigo;
    
    if (!buscarEstudiante(codigo)) {
        cout << "Estudiante no encontrado." << endl;
    }
    
    return 0;
}