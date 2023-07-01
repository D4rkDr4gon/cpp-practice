#include <iostream>
#include <cstring>
using namespace std;

struct Estudiante {
int codigo;
char nombre[50];
int edad;
};

//muestra el archivo q creamos en practica_41_1
int mostrarEstudiantes() {

    //abre el archivo
    FILE* archivo = fopen("estudiantes_binarios.dat", "rb");
 
    if (archivo != NULL) {
        Estudiante estudiante;
        
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1) {
        
        cout << "Estudiante encontrado:" << endl;
        cout << "Código: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Edad: " << estudiante.edad << endl;
        
        }
        
        //cierra el archivo
        fclose(archivo);
    
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
    
    return 0;
}
int main() {
    
    mostrarEstudiantes();
    
    return 0;
}