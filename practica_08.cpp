#include <iostream>
using namespace std;

int main()
{
    int n;
    int m;

    cout << "ingrese el numero: ";
    cin >> m;
    cout << "Ingrese un numero: ";
    cin >> n;

    for (int i = m; i <= m * n; i += m)
    {
        cout << i << " ";
    }

    cout << std::endl;

    return 0;
}
