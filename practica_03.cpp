#include <iostream>
using namespace std;

int main()
{
    int maximo;
    cout << "ingrese 10 numeros: " << endl;

    // bucle for
    for (int i = 0; i < 10; i++)
    {
        int numero;

        if (i == 0)
        {
            cout << "ingrese el primer numero: " << endl;
            cin >> maximo;
            maximo = numero;
        }
        else
        {
            cout << "ingrese el siguiente: " << endl;
            cin >> numero;

            if (numero > maximo)
            {
                maximo = numero;
            }
        }
    }

    cout << "el mayor es: " << maximo << endl;

    return 0;
}