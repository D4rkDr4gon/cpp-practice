#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Semilla para los números aleatorios
    srand(time(NULL));

    int dado1, dado2;
    char respuesta;

    do
    {
        // Generar valores aleatorios entre 1 y 6 para cada dado
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;

        // Mostrar resultado del lanzamiento
        cout << "El primer dado dio un valor de: " << dado1 << endl;
        cout << "El segundo dado dio un valor de: " << dado2 << endl;
        cout << "La suma de ambos dados es: " << dado1 + dado2 << endl;

        // Preguntar al usuario si desea lanzar los dados nuevamente
        cout << "Desea lanzar los dados nuevamente? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
