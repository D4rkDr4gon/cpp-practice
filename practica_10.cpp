#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int decimal, binario = 0, digito, exp = 0;
    cout << "Ingrese un numero decimal: ";
    cin >> decimal;
    while (decimal != 0)
    {
        digito = decimal % 2;
        binario += digito * pow(10, exp);
        exp++;
        decimal /= 2;
    }
    cout << "El numero en binario es: " << binario << endl;
    return 0;
}
