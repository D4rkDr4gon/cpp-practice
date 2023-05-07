#include <iostream>
using namespace std;

// enumeracion
enum DiasSemana
{
    Lunes = 1,
    Martes = 2,
    Miercoles = 3,
    Jueves = 4,
    Viernes = 5,
    Sabado = 6,
    Domingo = 7
};

int main()
{
    int dia;
    cout << "¿Qué día de la semana es hoy? (1=Lunes, 2=Martes, etc.) ";
    cin >> dia;

    // switch
    switch (dia)
    {
    case Lunes:
        cout << "Hoy es lunes." << endl;
        break;
    case Martes:
        cout << "Hoy es martes." << endl;
        break;
    case Miercoles:
        cout << "Hoy es miércoles." << endl;
        break;
    case Jueves:
        cout << "Hoy es jueves." << endl;
        break;
    case Viernes:
        cout << "Hoy es viernes." << endl;
        break;
    case Sabado:
        cout << "Hoy es sábado." << endl;
        break;
    case Domingo:
        cout << "Hoy es domingo." << endl;
        break;
    default:
        cout << "Día inválido." << endl;
        break;
    }

    return 0;
}
