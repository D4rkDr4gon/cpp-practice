#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    int suma = 0;
    while (n > 0)
    {
        suma += n % 10;
        n /= 10;
    }
    cout << "La suma de los digitos es " << suma << endl;
    return 0;
}
