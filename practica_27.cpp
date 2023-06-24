#include <iostream>
using namespace std;

int main()
{
    int i;
    cin >> i;

    // devuelve el espacio de memoria
    int numeros[i];
    cout << sizeof(numeros) << " Bytes";

    return 0;

}