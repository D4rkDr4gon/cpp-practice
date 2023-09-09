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
Operadores de Dirección y Desreferenciación
El operador  &  se utiliza para obtener la dirección de memoria de una variable, mientras que el operador 
*  se  utiliza para acceder al valor almacenado en una dirección de memoria.
#include <iostream> 
#include <string> 
 
// Definición del struct Alumno 
struct Alumno { 
    std::string nombre; 
    int edad; 
}; 
 
int main() { 
    // Declaración de un objeto Alumno y un puntero 
    Alumno juan; 
    juan.nombre = "Juan"; 
    juan.edad = 20; 
 
    Alumno* punteroJuan = &juan; 
 
    // Imprimimos la dirección de memoria y los valores almacenados en el objeto Alumno 
    std::cout << "Dirección de memoria del objeto Alumno 'juan': " << punteroJuan << std::endl; 
    std::cout << "Nombre del Alumno: " << punteroJuan->nombre << std::endl; 
    std::cout << "Edad del Alumno: " << punteroJuan->edad << " años" << std::endl; 
     
    delete punteroJuan; 
 
    return 0; 
}
Jugando con punteros
#include <iostream> 
using namespace std; 
 
// Definición del struct Alumno 
struct Alumno { 
    string nombre; 
    int edad; 
}; 
