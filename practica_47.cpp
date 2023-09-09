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

