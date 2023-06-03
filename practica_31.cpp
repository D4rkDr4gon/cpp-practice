#include <iostream>
using namespace std;

int main()
{
    // variable
    int CantAsig;
    float Sum;
    cout << "cantidad de asignaturas: ";
    cin >> CantAsig;

    // array
    float Asig[CantAsig];

    for (int i = 0; i < CantAsig; i++)
    {
        cout << "nota asignatura " << i << "? ";
        cin >> Asig[i];
    }

    // calcular el promedio al sumar los valores del array y dsp dividirlo por la CantAsig
    for (int i = 0; i < CantAsig; i++)
    {
        Sum += Asig[i];
    }

    cout << "tu promedio es: " << Sum / CantAsig;

    return 0;
}