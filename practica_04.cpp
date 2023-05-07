#include <iostream>
using namespace std;

// funciones: bloques de codigo q se pueden reutilizar y que realizan actividades espcificas
float Suma(float a, float b)
{
    float Var = a + b;

    return Var;
}

float Resta(float a, float b)
{
    int Var = a - b;
    return Var;
}

float Multiplicar(float a, float b)
{
    float Var = a * b;

    return Var;
}

float Dividir(float a, float b)
{
    float Var = a / b;

    return Var;
}

int main()
{
    // variables
    float a;
    float b;
    float Resultado;
    int i;

    // datos a usuario
    cout << "ingresa un valor: ";
    cin >> a;

    cout << "ingresa otro valor: ";
    cin >> b;

    cout << "tipo de operacion a realizar: " << endl
         << "1 = suma" << endl
         << "2 = resta" << endl
         << "3 = multiplicacion" << endl
         << "4 = division" << endl;
    cin >> i;

    // switch
    switch (i)
    {

    // suma
    case 1:
        Resultado = Suma(a, b);

        cout << "resultado = " << Resultado << endl;

        break;

    // resta
    case 2:
        Resultado = Resta(a, b);

        cout << "resultado = " << Resultado << endl;

        break;

    // multiplicacion
    case 3:
        Resultado = Multiplicar(a, b);

        cout << "resultado = " << Resultado << endl;

        break;

    // division
    case 4:
        Resultado = Dividir(a, b);

        cout << "resultado = " << Resultado << endl;

        break;

    // invalido
    default:

        cout << "no es valido";

        break;
    }

    return 0;
}