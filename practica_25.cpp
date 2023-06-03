<<<<<<< HEAD
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// structura
struct Estudiante
{
    string id;
    string nombre;
};

// funcion nuevo estudiante
void NuevoEstudiante(Estudiante &estudiante)
{
    cout << "nombre y apellido: " << endl;
    getline(cin, estudiante.nombre);
    cout << "nuevo id de estudiante: " << endl;
    getline(cin, estudiante.id);
}

// guardar en archivo
void Guardar(Estudiante estudiante)
{
    ofstream outputFile;
    outputFile.open("alumnos.txt", ios::app);
    outputFile << estudiante.nombre << "," << estudiante.id << endl;
    outputFile.close();
}

// funcion leer lista de estudiantes
void Leer()
{
    ifstream inputFile;
    inputFile.open("alumnos.txt");
    if (inputFile.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    else
    {
        string line;
        while (getline(inputFile, line))
        {
            cout << line << endl;
        }
    }
    inputFile.close();
}

int main()
{
    Estudiante estudiante;
    char option;

    do
    {
        cout << "bienvenido!!" << endl;
        cout << "que quiere hacer?" << endl
             << "nuevo alumno ==> N" << endl
             << "leer lista de alumno ==> L" << endl
             << "finalizar el programa ==> F" << endl;
        cin >> option;

        if (option == 'N' || option == 'n')
        {
            NuevoEstudiante(estudiante);
            Guardar(estudiante);
        }
        else if (option == 'L' || option == 'l')
        {
            Leer();
        }

    } while (option != 'F' || option != 'f');

    return 0;
=======
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// structura
struct Estudiante
{
    string id;
    string nombre;
};

// funcion nuevo estudiante
void NuevoEstudiante(Estudiante &estudiante)
{
    cout << "nombre y apellido: " << endl;
    getline(cin, estudiante.nombre);
    cout << "nuevo id de estudiante: " << endl;
    getline(cin, estudiante.id);
}

// guardar en archivo
void Guardar(Estudiante estudiante)
{
    ofstream outputFile;
    outputFile.open("alumnos.txt", ios::app);
    outputFile << estudiante.nombre << "," << estudiante.id << endl;
    outputFile.close();
}

// funcion leer lista de estudiantes
void Leer()
{
    ifstream inputFile;
    inputFile.open("alumnos.txt");
    if (inputFile.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    else
    {
        string line;
        while (getline(inputFile, line))
        {
            cout << line << endl;
        }
    }
    inputFile.close();
}

int main()
{
    Estudiante estudiante;
    char option;

    do
    {
        cout << "bienvenido!!" << endl;
        cout << "que quiere hacer?" << endl
             << "nuevo alumno ==> N" << endl
             << "leer lista de alumno ==> L" << endl
             << "finalizar el programa ==> F" << endl;
        cin >> option;

        if (option == 'N' || option == 'n')
        {
            NuevoEstudiante(estudiante);
            Guardar(estudiante);
        }
        else if (option == 'L' || option == 'l')
        {
            Leer();
        }

    } while (option != 'F' || option != 'f');

    return 0;
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
}