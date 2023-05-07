#include <iostream>
using namespace std;

// clase
class Fraccion
{
    // informacion privada de la clase
private:
    int numerador;
    int denominador;

    // informacion publica de la variable
public:
    // funcion
    Fraccion(int n, int d)
    {
        numerador = n;
        denominador = d;
    }

    // funcion
    void imprimir()
    {
        cout << numerador << "/" << denominador << std::endl;
    }

    Fraccion operator+(Fraccion f)
    {
        int n = numerador * f.denominador + f.numerador * denominador;
        int d = denominador * f.denominador;
        Fraccion resultado(n, d);
        return resultado;
    }

    Fraccion operator-(Fraccion f)
    {
        int n = numerador * f.denominador - f.numerador * denominador;
        int d = denominador * f.denominador;
        Fraccion resultado(n, d);
        return resultado;
    }

    Fraccion operator*(Fraccion f)
    {
        int n = numerador * f.numerador;
        int d = denominador * f.denominador;
        Fraccion resultado(n, d);
        return resultado;
    }

    Fraccion operator/(Fraccion f)
    {
        int n = numerador * f.denominador;
        int d = denominador * f.numerador;
        Fraccion resultado(n, d);
        return resultado;
    }
};

int main()
{
    // variables
    int n;
    int d;
    int n1;
    int d1;

    // datos a usuario
    cout << "numerador de la primera fraccion: ";
    cin >> n;
    cout << "denominador de la primera fraccion: ";
    cin >> d;

    cout << "numerador de la segunda fraccion: ";
    cin >> n1;
    cout << "numerador de la segunda fraccion: ";
    cin >> d1;

    // llamar a la clase
    Fraccion f1(n, d);
    Fraccion f2(n1, d1);

    // funciones
    Fraccion suma = f1 + f2;
    Fraccion resta = f1 - f2;
    Fraccion producto = f1 * f2;
    Fraccion division = f1 / f2;

    // imprimir en pantalla
    cout << "La suma de las fracciones es: ";
    suma.imprimir();

    cout << "La resta de las fracciones es: ";
    resta.imprimir();

    cout << "El producto de las fracciones es: ";
    producto.imprimir();

    cout << "La división de las fracciones es: ";
    division.imprimir();

    return 0;
}
