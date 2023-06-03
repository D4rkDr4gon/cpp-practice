<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

// estructura
struct Alumno
{
    string Nombre;
    float Asig1;
    float Asig2;
    float Asig3;
};

int main()
{
    // array
    Alumno est[5];
    float promedio;

    for (int i = 0; i < 5; i++)
    {
        cout << "ingrese nombre: " << endl;
        cin >> est[i].Nombre;
        cout << "ingrese nota de Asignatura 1: " << endl;
        cin >> est[i].Asig1;
        cout << "ingrese nota de Asignatura 2: " << endl;
        cin >> est[i].Asig2;
        cout << "ingrese nota de Asignatura 3: " << endl;
        cin >> est[i].Asig3;

        // calcular promedio
        promedio = (est[i].Asig1 + est[i].Asig2 + est[i].Asig3) / 3;
        cout << est[i].Nombre << " tu promedio es: " << promedio << endl;
    }

    return 0;
=======
#include <iostream>
#include <string>
using namespace std;

// estructura
struct Alumno
{
    string Nombre;
    float Asig1;
    float Asig2;
    float Asig3;
};

int main()
{
    // array
    Alumno est[5];
    float promedio;

    for (int i = 0; i < 5; i++)
    {
        cout << "ingrese nombre: " << endl;
        cin >> est[i].Nombre;
        cout << "ingrese nota de Asignatura 1: " << endl;
        cin >> est[i].Asig1;
        cout << "ingrese nota de Asignatura 2: " << endl;
        cin >> est[i].Asig2;
        cout << "ingrese nota de Asignatura 3: " << endl;
        cin >> est[i].Asig3;

        // calcular promedio
        promedio = (est[i].Asig1 + est[i].Asig2 + est[i].Asig3) / 3;
        cout << est[i].Nombre << " tu promedio es: " << promedio << endl;
    }

    return 0;
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
}