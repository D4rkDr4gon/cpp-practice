<<<<<<< HEAD
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    // algoritmo de ordenamiento x seleccion
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    // array
    int arr[] = {64, 25, 12, 22, 11, 100, 10000, 5, 15, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Array ordenado: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
=======
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    // algoritmo de ordenamiento x seleccion
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    // array
    int arr[] = {64, 25, 12, 22, 11, 100, 10000, 5, 15, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Array ordenado: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
