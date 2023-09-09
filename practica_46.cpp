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
 
