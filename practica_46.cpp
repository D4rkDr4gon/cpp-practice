#include <iostream> 
#include <string> 
using namespace std;
 
// Definición del struct Alumno 
struct Alumno { 
    string nombre; 
    int edad; 
}; 
 
int main() { 
    // Declaración de un puntero a un Alumno 
    Alumno* alumnoDinamico; 
 
    // Asignación dinámica de memoria para un Alumno 
    alumnoDinamico = new Alumno; 
 
    // Asignar valores al Alumno dinámico 
    alumnoDinamico->nombre = "Juan"; 
    alumnoDinamico->edad = 20; 
 
// Imprimir los valores del Alumno dinámico 
    std::cout << "Nombre del Alumno: " << alumnoDinamico->nombre << std::endl; 
    std::cout << "Edad del Alumno: " << alumnoDinamico->edad << " años" << std::endl; 
 
    // Liberar la memoria asignada dinámicamente 
    delete alumnoDinamico; 
 
    return 0; 
}
