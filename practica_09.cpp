#include <iostream>
#include <string>
using namespace std;

// struct
struct Alumno
{
    string nombre;
    string legajo;
};

int main()
{
    // uso el struct en el main para declarar variable
    Alumno un_alumno;

    cout << "ingrese nombre: ";
    // trabajo la variable al definirla
    cin >> un_alumno.nombre;

    cout << "ingrese legajo: ";
    cin >> un_alumno.legajo;

    if (un_alumno.nombre == "lucciano" && un_alumno.legajo == "214.555-3")
    {
        cout << "bienvenido!! " << un_alumno.nombre;
    }
    else if (un_alumno.nombre == "admin" && un_alumno.legajo == "0000")
    {
        cout << "premiso de admin autorizado, bienvenido!!!";
    }
    else
    {
        cout << "no tiene acceso";
    }

    return 0;
}