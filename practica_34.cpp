#include <iostream>

double calcularBMI(double peso, double altura) {
    return peso / (altura * altura);
}

void mostrarCategoria(double bmi) {
    if (bmi < 18.5) {
        std::cout << "Bajo peso" << std::endl;
    } else if (bmi < 25.0) {
        std::cout << "Peso normal" << std::endl;
    } else if (bmi < 30.0) {
        std::cout << "Sobrepeso" << std::endl;
    } else {
        std::cout << "Obesidad" << std::endl;
    }
}

int main() {
    double peso, altura;

    std::cout << "Calculadora de BMI" << std::endl;
    std::cout << "Ingrese su peso en kilogramos: ";
    std::cin >> peso;
    std::cout << "Ingrese su altura en metros: ";
    std::cin >> altura;

    double bmi = calcularBMI(peso, altura);

    std::cout << "Su BMI es: " << bmi << std::endl;
    std::cout << "Categoría: ";
    mostrarCategoria(bmi);

    return 0;
}
