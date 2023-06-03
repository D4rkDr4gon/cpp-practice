<<<<<<< HEAD
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int option;
    double input, result;

    cout << "Seleccione la opción de conversión: " << endl;
    cout << "1. Millas a Kilómetros" << endl;
    cout << "2. Pies a Metros" << endl;
    cout << "3. Fahrenheit a Celsius" << endl;
    cin >> option;

    switch (option)
    {
    case 1: // Millas a Kilómetros
        cout << "Ingrese la cantidad de millas a convertir: ";
        cin >> input;
        result = input * 1.60934;
        cout << input << " millas son equivalentes a " << fixed << setprecision(2) << result << " kilómetros." << endl;
        break;
    case 2: // Pies a Metros
        cout << "Ingrese la cantidad de pies a convertir: ";
        cin >> input;
        result = input * 0.3048;
        cout << input << " pies son equivalentes a " << fixed << setprecision(2) << result << " metros." << endl;
        break;
    case 3: // Fahrenheit a Celsius
        cout << "Ingrese la cantidad de grados Fahrenheit a convertir: ";
        cin >> input;
        result = (input - 32) * 5 / 9;
        cout << input << " grados Fahrenheit son equivalentes a " << fixed << setprecision(2) << result << " grados Celsius." << endl;
        break;
    default:
        cout << "Opción inválida." << endl;
        break;
    }

    return 0;
}
=======
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int option;
    double input, result;

    cout << "Seleccione la opción de conversión: " << endl;
    cout << "1. Millas a Kilómetros" << endl;
    cout << "2. Pies a Metros" << endl;
    cout << "3. Fahrenheit a Celsius" << endl;
    cin >> option;

    switch (option)
    {
    case 1: // Millas a Kilómetros
        cout << "Ingrese la cantidad de millas a convertir: ";
        cin >> input;
        result = input * 1.60934;
        cout << input << " millas son equivalentes a " << fixed << setprecision(2) << result << " kilómetros." << endl;
        break;
    case 2: // Pies a Metros
        cout << "Ingrese la cantidad de pies a convertir: ";
        cin >> input;
        result = input * 0.3048;
        cout << input << " pies son equivalentes a " << fixed << setprecision(2) << result << " metros." << endl;
        break;
    case 3: // Fahrenheit a Celsius
        cout << "Ingrese la cantidad de grados Fahrenheit a convertir: ";
        cin >> input;
        result = (input - 32) * 5 / 9;
        cout << input << " grados Fahrenheit son equivalentes a " << fixed << setprecision(2) << result << " grados Celsius." << endl;
        break;
    default:
        cout << "Opción inválida." << endl;
        break;
    }

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
