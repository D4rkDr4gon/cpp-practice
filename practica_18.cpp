#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));                       // Inicializar semilla para la generación de números aleatorios
    int numeroAleatorio = rand() % 1000 + 1; // Generar número aleatorio entre 1 y 1000
    int intentos = 0;
    int numeroUsuario;

    cout << "Bienvenido al juego de adivinanza" << endl;
    cout << "Tienes que adivinar un número entre 1 y 1000" << endl;

    do
    {
        cout << "Introduce un número: ";
        cin >> numeroUsuario;
        intentos++;

        if (numeroUsuario > numeroAleatorio)
        {
            cout << "El número es menor" << endl;
        }
        else if (numeroUsuario < numeroAleatorio)
        {
            cout << "El número es mayor" << endl;
        }
        else
        {
            cout << "¡Adivinaste el número en " << intentos << " intentos!" << endl;
        }
    } while (numeroUsuario != numeroAleatorio);

    return 0;
}
