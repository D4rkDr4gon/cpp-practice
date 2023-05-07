#include <iostream>
using namespace std;

// fibonacci
int main()
{

    // variables
    int num1 = 0, num2 = 1, i = 1;

    // bucle while
    while (i <= 10)
    {
        cout << num1 << ", ";
        int sum = num1 + num2;
        num1 = num2;
        num2 = sum;
        i++;
    }

    return 0;
}
