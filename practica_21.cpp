<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <bitset>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// decimal a punto flotante simple presicion
void DecPFSP()
{
    float decimal_value;
    cout << "Ingrese un numero decimal: ";
    cin >> decimal_value;

    int sign = (decimal_value >= 0) ? 0 : 1; // Determinar el signo del número
    decimal_value = abs(decimal_value);      // Tomar el valor absoluto del número
    int exponent = 0;
    float fraction = decimal_value;

    if (fraction >= 2.0)
    {
        while (fraction >= 2.0)
        {
            fraction /= 2.0;
            exponent++;
        }
    }
    else if (fraction < 1.0)
    {
        while (fraction < 1.0)
        {
            fraction *= 2.0;
            exponent--;
        }
    }

    fraction -= 1.0;
    exponent += 127;

    bitset<32> float_bits;
    float_bits[31] = sign;
    for (int i = 0; i < 8; i++)
    {
        float_bits[30 - i] = (exponent >> i) & 1;
    }
    for (int i = 0; i < 23; i++)
    {
        fraction *= 2.0;
        float_bits[22 - i] = static_cast<int>(fraction);
        fraction -= static_cast<int>(fraction);
    }

    cout << "El equivalente en punto flotante es: " << float_bits.to_ulong() << endl;
}

// caracter a codigo ascii
void CharASCII()
{
    char c;
    cout << "Ingrese un caracter: ";
    cin >> c;
    printf("El equivalente en codigo ASCII de '%c' es %d", c, c);
    cout << endl;
}

// binario a ascci
void BinASCII()
{
    string binary_str;
    cout << "Ingrese un numero binario: ";
    cin >> binary_str;

    bitset<8> binary(binary_str);
    char ascii_char = static_cast<char>(binary.to_ulong());

    cout << "El equivalente en ASCII es: " << ascii_char << endl;
}

// ascii a binario
void ASCIIBin()
{
    int ascii_code;
    cout << "Ingrese un codigo ASCII: ";
    cin >> ascii_code;
    bitset<8> binary(ascii_code);
    cout << "El equivalente en binario es: " << binary << endl;
}

// binario a hexadecimal
void BinHex()
{
    string binary_str;
    cout << "Ingrese un numero binario: ";
    cin >> binary_str;
    bitset<32> binary(binary_str);
    int hex_value = binary.to_ulong();
    cout << "El equivalente en hexadecimal es: " << hex << hex_value << endl;
}

// binario a decimal
void BinDec()
{
    string binary_str;
    cout << "Ingrese un numero binario: ";
    cin >> binary_str;
    bitset<32> binary(binary_str);
    int decimal_value = binary.to_ulong();
    cout << "El equivalente en decimal es: " << decimal_value << endl;
}

// punto flotante simple presicion a binario
void PFSPBin()
{
    float float_value;
    cout << "Ingrese un numero de punto flotante en formato IEEE 754 (32 bits): ";
    cin >> float_value;

    bitset<32> float_bits(*reinterpret_cast<unsigned int *>(&float_value));
    cout << "El equivalente en binario es: " << float_bits.to_string() << endl;
}

// hexadecimal a decimal
void HexDec()
{
    string hex_value;
    cout << "Ingrese un numero hexadecimal: ";
    cin >> hex_value;

    int dec_value = 0;
    int base = 1;

    for (int i = hex_value.length() - 1; i >= 0; i--)
    {
        if (hex_value[i] >= '0' && hex_value[i] <= '9')
        {
            dec_value += (hex_value[i] - '0') * base;
        }
        else if (hex_value[i] >= 'A' && hex_value[i] <= 'F')
        {
            dec_value += (hex_value[i] - 'A' + 10) * base;
        }
        else if (hex_value[i] >= 'a' && hex_value[i] <= 'f')
        {
            dec_value += (hex_value[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    cout << "El equivalente en decimal es: " << dec_value << endl;
}

int main()
{

    while (true)
    {
        int eleccion;

        cout << "conversor de unidades!" << endl
             << "1 = caracteres a ASCII" << endl
             << "2 = ASCII a binario" << endl
             << "3 = binario a hexadecimal" << endl
             << "4 = binario a decimal" << endl
             << "5 = binario a ASCII" << endl
             << "6 = decimal a Punto Flotante Simple Presicion" << endl
             << "7 = Punto Flotante Simple Presicion a binario" << endl
             << "8 = Hexadecimal a Descimal" << endl
             << "9 = fin del programa" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            CharASCII();

            break;

        case 2:
            ASCIIBin();

            break;

        case 3:
            BinDec();

            break;

        case 4:
            BinHex();

            break;

        case 5:
            BinASCII();

            break;

        case 6:
            DecPFSP();

            break;

        case 7:
            PFSPBin();

            break;

        case 8:
            HexDec();

            break;

        case 9:
            break;

        default:
            cout << "no valido";

            break;
        }

        if (eleccion == 9)
        {
            break;
        }
    }

    return 0;
}
=======
#include <iostream>
#include <cstdio>
#include <bitset>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// decimal a punto flotante simple presicion
void DecPFSP()
{
    float decimal_value;
    cout << "Ingrese un numero decimal: ";
    cin >> decimal_value;

    int sign = (decimal_value >= 0) ? 0 : 1; // Determinar el signo del número
    decimal_value = abs(decimal_value);      // Tomar el valor absoluto del número
    int exponent = 0;
    float fraction = decimal_value;

    if (fraction >= 2.0)
    {
        while (fraction >= 2.0)
        {
            fraction /= 2.0;
            exponent++;
        }
    }
    else if (fraction < 1.0)
    {
        while (fraction < 1.0)
        {
            fraction *= 2.0;
            exponent--;
        }
    }

    fraction -= 1.0;
    exponent += 127;

    bitset<32> float_bits;
    float_bits[31] = sign;
    for (int i = 0; i < 8; i++)
    {
        float_bits[30 - i] = (exponent >> i) & 1;
    }
    for (int i = 0; i < 23; i++)
    {
        fraction *= 2.0;
        float_bits[22 - i] = static_cast<int>(fraction);
        fraction -= static_cast<int>(fraction);
    }

    cout << "El equivalente en punto flotante es: " << float_bits.to_ulong() << endl;
}

// caracter a codigo ascii
void CharASCII()
{
    char c;
    cout << "Ingrese un caracter: ";
    cin >> c;
    printf("El equivalente en codigo ASCII de '%c' es %d", c, c);
    cout << endl;
}

// binario a ascci
void BinASCII()
{
    string binary_str;
    cout << "Ingrese un numero binario: ";
    cin >> binary_str;

    bitset<8> binary(binary_str);
    char ascii_char = static_cast<char>(binary.to_ulong());

    cout << "El equivalente en ASCII es: " << ascii_char << endl;
}

// ascii a binario
void ASCIIBin()
{
    int ascii_code;
    cout << "Ingrese un codigo ASCII: ";
    cin >> ascii_code;
    bitset<8> binary(ascii_code);
    cout << "El equivalente en binario es: " << binary << endl;
}

// binario a hexadecimal
void BinHex()
{
    string binary_str;
    cout << "Ingrese un numero binario: ";
    cin >> binary_str;
    bitset<32> binary(binary_str);
    int hex_value = binary.to_ulong();
    cout << "El equivalente en hexadecimal es: " << hex << hex_value << endl;
}

// binario a decimal
void BinDec()
{
    string binary_str;
    cout << "Ingrese un numero binario: ";
    cin >> binary_str;
    bitset<32> binary(binary_str);
    int decimal_value = binary.to_ulong();
    cout << "El equivalente en decimal es: " << decimal_value << endl;
}

// punto flotante simple presicion a binario
void PFSPBin()
{
    float float_value;
    cout << "Ingrese un numero de punto flotante en formato IEEE 754 (32 bits): ";
    cin >> float_value;

    bitset<32> float_bits(*reinterpret_cast<unsigned int *>(&float_value));
    cout << "El equivalente en binario es: " << float_bits.to_string() << endl;
}

// hexadecimal a decimal
void HexDec()
{
    string hex_value;
    cout << "Ingrese un numero hexadecimal: ";
    cin >> hex_value;

    int dec_value = 0;
    int base = 1;

    for (int i = hex_value.length() - 1; i >= 0; i--)
    {
        if (hex_value[i] >= '0' && hex_value[i] <= '9')
        {
            dec_value += (hex_value[i] - '0') * base;
        }
        else if (hex_value[i] >= 'A' && hex_value[i] <= 'F')
        {
            dec_value += (hex_value[i] - 'A' + 10) * base;
        }
        else if (hex_value[i] >= 'a' && hex_value[i] <= 'f')
        {
            dec_value += (hex_value[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    cout << "El equivalente en decimal es: " << dec_value << endl;
}

int main()
{

    while (true)
    {
        int eleccion;

        cout << "conversor de unidades!" << endl
             << "1 = caracteres a ASCII" << endl
             << "2 = ASCII a binario" << endl
             << "3 = binario a hexadecimal" << endl
             << "4 = binario a decimal" << endl
             << "5 = binario a ASCII" << endl
             << "6 = decimal a Punto Flotante Simple Presicion" << endl
             << "7 = Punto Flotante Simple Presicion a binario" << endl
             << "8 = Hexadecimal a Descimal" << endl
             << "9 = fin del programa" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            CharASCII();

            break;

        case 2:
            ASCIIBin();

            break;

        case 3:
            BinDec();

            break;

        case 4:
            BinHex();

            break;

        case 5:
            BinASCII();

            break;

        case 6:
            DecPFSP();

            break;

        case 7:
            PFSPBin();

            break;

        case 8:
            HexDec();

            break;

        case 9:
            break;

        default:
            cout << "no valido";

            break;
        }

        if (eleccion == 9)
        {
            break;
        }
    }

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
