#include <iostream> 
using namespace std; 
 
// Definición del struct Alumno 
struct Alumno { 
    string nombre; 
    int edad; 
}; 
int main() { 
    // Declaración de un objeto Alumno y un puntero 
    Alumno juan; 
    juan.nombre = "Juan"; 
    juan.edad = 20; 
    int continuar; 
 
    Alumno* punteroPersona = &juan; 
 
    // Imprimimos la dirección de memoria y los valores almacenados en el objeto Alumno 
    cout << "Dirección de memoria del objeto Alumno 'juan': " << punteroPersona << endl; 
    cout << "Nombre del Alumno: " << punteroPersona->nombre << endl; 
    cout << "Edad del Alumno: " << punteroPersona->edad << " años" << endl; 
  cout << endl; 
    cout << endl; 
    cout << endl; 
 
    cout << "¿Qué pasa si cambio el nombre de juan desde juan.nombre? Poner nuevo nombre:" << endl; 
    cin >> juan.nombre; 
    cout << "juan.nombre: " << juan.nombre  << endl; 
    cout << "punteroPersona->nombre: " << punteroPersona->nombre << endl; 
    cout << endl; 
    cout << endl; 
    cout << endl; 
 
    cout << "¿Qué pasa si cambio el nombre de juan desde punteroPersona->nombre? Poner nuevo nombre:" << endl; 
    cin >> punteroPersona->nombre; 
    cout << "juan.nombre: " << juan.nombre  << endl; 
    cout << "punteroPersona->nombre: " << punteroPersona->nombre << endl; 
    cout << endl; 
    cout << endl; 
    cout << endl; 
    cout << "Ahora llegó un nuevo amigo llamado carlos y tiene 30 años." << endl; 
    
    Alumno carlos; 
    carlos.nombre = "Carlos"; 
    carlos.edad = 30; 
 
    cout << "¿Qué pasa si cambio el puntero y le asigno la dirección de carlos?" << endl; 
    punteroPersona = &carlos; 
    cout << "punteroPersona = &carlos;" << endl; 
    cout << "Coloca un número para continuar " << endl; 
    cin >> continuar; 
 
    cout << "juan.nombre: " << juan.nombre  << endl; 
    cout << "carlos.nombre: " << carlos.nombre  << endl; 
    cout << "punteroPersona->nombre: " << punteroPersona->nombre << endl; 
 
    cout << "Cómo quedaron las direcciones?. Coloca un número para continuar:" <<endl; 
    cin >> continuar; 
    cout << "&juan: " << &juan  << endl; 
    cout << "&carlos: " << &carlos  << endl; 
    cout << "punteroPersona: " << punteroPersona << endl; 
 
     
 
 
    return 0; 
}