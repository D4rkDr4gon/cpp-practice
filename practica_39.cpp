#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> detectAnomalies(const std::vector<double>& data) {
    double mean = 0.0;
    double std = 0.0;

    // Calcular la media de los datos
    for (double value : data) {
        mean += value;
    }
    mean /= data.size();

    // Calcular la desviación estándar de los datos
    for (double value : data) {
        std += pow(value - mean, 2);
    }
    std = sqrt(std / data.size());

    double threshold = 3 * std; // Umbral para detectar anomalías (3 desviaciones estándar)

    std::vector<double> anomalies;

    // Detectar anomalías en los datos
    for (double value : data) {
        if (std::abs(value - mean) > threshold) {
            anomalies.push_back(value);
        }
    }

    return anomalies;
}

int main() {
    // Generar datos de ejemplo (1000 valores)
    std::vector<double> data;
    for (int i = 0; i < 900; i++) {
        data.push_back((double)rand() / RAND_MAX); // Datos normales
    }
    for (int i = 0; i < 100; i++) {
        data.push_back(10 + ((double)rand() / RAND_MAX)); // Anomalías
    }

    // Detectar anomalías en los datos
    std::vector<double> anomalies = detectAnomalies(data);

    // Imprimir las anomalías encontradas
    std::cout << "Anomalies:" << std::endl;
    for (double anomaly : anomalies) {
        std::cout << anomaly << std::endl;
    }

    return 0;
}
