#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    // algoritmo de auclides
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cout << "ingresa un numero: ";
    cin >> a;
    cout << "ingresa un numero: ";
    cin >> b;
    // funcion
    int mcd = gcd(a, b);
    cout << "El MCD de " << a << " y " << b << " es " << mcd << endl;
    return 0;
}
