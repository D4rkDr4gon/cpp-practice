#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Ingrese un número entero positivo: ";
    cin >> n;

    bool es_primo = true;

    if (n < 2)
    {
        es_primo = false;
    }
    else
    {
        for (int i = 2; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                es_primo = false;
                break;
            }
        }
    }

    if (es_primo)
        cout << n << " es un número primo";
    else
        cout << n << " no es un número primo";

    return 0;
}