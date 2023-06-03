<<<<<<< HEAD
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
=======
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
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
}