#include <iostream>

const int ROWS = 3;
const int COLS = 4;

// funcion q revisa la matris
void printMatrix(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // array multidimensional definido
    int matrix[ROWS][COLS] = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12}};

    std::cout << "Matrix elements:" << std::endl;
    printMatrix(matrix);

    return 0;
}
