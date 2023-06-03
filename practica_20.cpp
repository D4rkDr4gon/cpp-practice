<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

// estructura
struct Alumno
{
    string nombre;
    int edad;
};

// funcion declarada
Alumno Crear();

int main()
{
    // arrays
    Alumno alumnos[5];

    // bucles for
    for (int i = 0; i < 5; i++)
    {
        alumnos[i] = Crear();
    }

    cout << "lista de alumnos: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << alumnos[i].nombre << " y su edad es: " << alumnos[i].edad << endl;
    }

    return 0;
}

// definir funcion
Alumno Crear()
{
    Alumno alumnos;
    cout << "nombre del alumno: ";
    cin >> alumnos.nombre;

    cout << "edad del alumno: ";
    cin >> alumnos.edad;

    return alumnos;
=======
#include <iostream>
#include <string>
using namespace std;

// estructura
struct Alumno
{
    string nombre;
    int edad;
};

// funcion declarada
Alumno Crear();

int main()
{
    // arrays
    Alumno alumnos[5];

    // bucles for
    for (int i = 0; i < 5; i++)
    {
        alumnos[i] = Crear();
    }

    cout << "lista de alumnos: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << alumnos[i].nombre << " y su edad es: " << alumnos[i].edad << endl;
    }

    return 0;
}

// definir funcion
Alumno Crear()
{
    Alumno alumnos;
    cout << "nombre del alumno: ";
    cin >> alumnos.nombre;

    cout << "edad del alumno: ";
    cin >> alumnos.edad;

    return alumnos;
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
}