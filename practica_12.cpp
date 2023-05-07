#include <iostream>
using namespace std;

double raizCuadrada(double x)
{
    double tolerancia = 0.0001; // Tolerancia para considerar la respuesta como válida
    double estimado = x / 2.0;  // Estimado inicial

    while (abs(estimado * estimado - x) > tolerancia)
    {                                               // Mientras no se alcance la tolerancia deseada
        estimado = (estimado + x / estimado) / 2.0; // Aplicar fórmula de Newton-Raphson
    }

    return estimado; // Devolver el estimado final
}

int main()
{
    double x;
    cout << "Ingrese un número: ";
    cin >> x;

    double resultado = raizCuadrada(x);

    cout << "La raíz cuadrada de " << x << " es " << resultado << endl;

    return 0;
}