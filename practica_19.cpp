<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria
{
public:
    CuentaBancaria(int numero, string nombre, double saldo)
    {
        numeroCuenta = numero;
        nombreTitular = nombre;
        saldoActual = saldo;
    }

    void depositar(double cantidad)
    {
        saldoActual += cantidad;
    }

    void retirar(double cantidad)
    {
        if (cantidad > saldoActual)
        {
            cout << "No tienes suficiente saldo para realizar esta transacción." << endl;
        }
        else
        {
            saldoActual -= cantidad;
        }
    }

    void mostrarSaldo()
    {
        cout << "Tu saldo actual es: $" << saldoActual << endl;
    }

private:
    int numeroCuenta;
    string nombreTitular;
    double saldoActual;
};

int main()
{
    // variables
    int numCuenta;
    string Nombre;
    double saldo = 0;
    double cantDeposito;
    double cantRetirar;
    string pregunta;

    cout << "bienvenido al banco cpp!!! porfavor siga los pasos para crear su cuenta y trabajar con ella" << endl;

    // datos a usuario
    cout << "nombre del propietario: ";
    cin >> Nombre;
    cout << "numero de Cuenta: ";
    cin >> numCuenta;
    cout << "saldo inicial es: " << saldo << endl;

    // Creamos una nueva cuenta bancaria con número de cuenta, titular y saldo inicial
    CuentaBancaria cuenta(numCuenta, Nombre, saldo);

    cout << "buenos dias! " << Nombre << endl;

    // bucle infinito
    while (true)
    {

        // pregunta q hacer
        cout << "que quiere realizar? " << endl
             << "Deposito: d" << endl
             << "retiro: r" << endl
             << "mostrar saldo: m" << endl
             << "salir: s" << endl;
        cin >> pregunta;

        // q quiere realizar
        if (pregunta == "d" || pregunta == "D")
        {
            cout << "cantidad a depositar?" << endl;
            cin >> cantDeposito;
            cuenta.depositar(cantDeposito);
        }
        else if (pregunta == "r" || pregunta == "R")
        {
            cout << "cantidad a depositar?" << endl;
            cin >> cantRetirar;
            cuenta.retirar(cantRetirar);
        }
        else if (pregunta == "m" || pregunta == "M")
        {
            cuenta.mostrarSaldo();
        }
        else if (pregunta == "s" || pregunta == "S")
        {
            break;
        }
    }

    return 0;
}
=======
#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria
{
public:
    CuentaBancaria(int numero, string nombre, double saldo)
    {
        numeroCuenta = numero;
        nombreTitular = nombre;
        saldoActual = saldo;
    }

    void depositar(double cantidad)
    {
        saldoActual += cantidad;
    }

    void retirar(double cantidad)
    {
        if (cantidad > saldoActual)
        {
            cout << "No tienes suficiente saldo para realizar esta transacción." << endl;
        }
        else
        {
            saldoActual -= cantidad;
        }
    }

    void mostrarSaldo()
    {
        cout << "Tu saldo actual es: $" << saldoActual << endl;
    }

private:
    int numeroCuenta;
    string nombreTitular;
    double saldoActual;
};

int main()
{
    // variables
    int numCuenta;
    string Nombre;
    double saldo = 0;
    double cantDeposito;
    double cantRetirar;
    string pregunta;

    cout << "bienvenido al banco cpp!!! porfavor siga los pasos para crear su cuenta y trabajar con ella" << endl;

    // datos a usuario
    cout << "nombre del propietario: ";
    cin >> Nombre;
    cout << "numero de Cuenta: ";
    cin >> numCuenta;
    cout << "saldo inicial es: " << saldo << endl;

    // Creamos una nueva cuenta bancaria con número de cuenta, titular y saldo inicial
    CuentaBancaria cuenta(numCuenta, Nombre, saldo);

    cout << "buenos dias! " << Nombre << endl;

    // bucle infinito
    while (true)
    {

        // pregunta q hacer
        cout << "que quiere realizar? " << endl
             << "Deposito: d" << endl
             << "retiro: r" << endl
             << "mostrar saldo: m" << endl
             << "salir: s" << endl;
        cin >> pregunta;

        // q quiere realizar
        if (pregunta == "d" || pregunta == "D")
        {
            cout << "cantidad a depositar?" << endl;
            cin >> cantDeposito;
            cuenta.depositar(cantDeposito);
        }
        else if (pregunta == "r" || pregunta == "R")
        {
            cout << "cantidad a depositar?" << endl;
            cin >> cantRetirar;
            cuenta.retirar(cantRetirar);
        }
        else if (pregunta == "m" || pregunta == "M")
        {
            cuenta.mostrarSaldo();
        }
        else if (pregunta == "s" || pregunta == "S")
        {
            break;
        }
    }

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
