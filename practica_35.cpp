<<<<<<< HEAD
#include <iostream>
#include <string>

struct Temperatura {
    double valor;
    std::string unidad;
};

double convertirCelsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convertirFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void mostrarResultado(double valor, const std::string& unidadOrigen, const std::string& unidadDestino) {
    std::cout << valor << " " << unidadOrigen << " equivale a " << convertirCelsiusToFahrenheit(valor) << " " << unidadDestino << std::endl;
}

int main() {
    Temperatura temperatura;

    std::cout << "Conversor de Temperaturas" << std::endl;
    std::cout << "Ingrese un valor de temperatura: ";
    std::cin >> temperatura.valor;
    std::cout << "Ingrese la unidad de temperatura (C o F): ";
    std::cin >> temperatura.unidad;

    if (temperatura.unidad == "C") {
        mostrarResultado(temperatura.valor, "Celsius", "Fahrenheit");
    } else if (temperatura.unidad == "F") {
        mostrarResultado(temperatura.valor, "Fahrenheit", "Celsius");
    } else {
        std::cout << "Unidad de temperatura no válida. Por favor, ingrese 'C' o 'F'." << std::endl;
    }

    return 0;
}
=======
#include <iostream>
#include <string>

struct Temperatura {
    double valor;
    std::string unidad;
};

double convertirCelsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convertirFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void mostrarResultado(double valor, const std::string& unidadOrigen, const std::string& unidadDestino) {
    std::cout << valor << " " << unidadOrigen << " equivale a " << convertirCelsiusToFahrenheit(valor) << " " << unidadDestino << std::endl;
}

int main() {
    Temperatura temperatura;

    std::cout << "Conversor de Temperaturas" << std::endl;
    std::cout << "Ingrese un valor de temperatura: ";
    std::cin >> temperatura.valor;
    std::cout << "Ingrese la unidad de temperatura (C o F): ";
    std::cin >> temperatura.unidad;

    if (temperatura.unidad == "C") {
        mostrarResultado(temperatura.valor, "Celsius", "Fahrenheit");
    } else if (temperatura.unidad == "F") {
        mostrarResultado(temperatura.valor, "Fahrenheit", "Celsius");
    } else {
        std::cout << "Unidad de temperatura no válida. Por favor, ingrese 'C' o 'F'." << std::endl;
    }

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
