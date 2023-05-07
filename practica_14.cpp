#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct User
{
    string username;
    string password;
};

// Función para crear un nuevo usuario
void createUser(User &user)
{
    cout << "Ingrese un nombre de usuario: ";
    getline(cin, user.username);
    cout << "Ingrese una contraseña: ";
    getline(cin, user.password);
}

// Función para guardar los datos del usuario en un archivo de texto
void saveUser(User user)
{
    ofstream outputFile;
    outputFile.open("usuarios.txt", ios::app);
    outputFile << user.username << "," << user.password << endl;
    outputFile.close();
}

// Función para leer los datos del usuario desde el archivo de texto
void readUsers()
{
    ifstream inputFile;
    inputFile.open("usuarios.txt");
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
    User newUser;
    char option;

    do
    {
        createUser(newUser);
        saveUser(newUser);
        cout << "Usuario creado exitosamente." << endl;
        cout << "¿Desea crear otro usuario? (s/n): ";
        cin >> option;
        cin.ignore();
    } while (option == 's' || option == 'S');

    cout << "Usuarios registrados:" << endl;
    readUsers();

    return 0;
}
