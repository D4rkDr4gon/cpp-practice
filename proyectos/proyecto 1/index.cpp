#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

// Módulo 1: Gestor de estudiantes

struct Estudiante {
    string email;
    string clave;
    int creditos;

    Estudiante(const string& e, const string& c) : email(e), clave(c), creditos(1000) {}
};

bool ValidarEmail(const string& email) {
    regex patron("\\b[A-Za-z0-9._%+-]+@frba.utn.edu.ar\\b");
    return regex_match(email, patron);
}

void RegistrarEstudiante(vector<Estudiante>& estudiantes) {
    string email, clave;
    cout << "Ingrese su email: ";
    cin >> email;

    if (!ValidarEmail(email)) {
        cout << "Email no válido." << endl;
        return;
    }

    for (const Estudiante& estudiante : estudiantes) {
        if (estudiante.email == email) {
            cout << "El email ya está registrado." << endl;
            return;
        }
    }

    cout << "Ingrese su clave: ";
    cin >> clave;
    estudiantes.push_back(Estudiante(email, clave));
    cout << "Registro exitoso." << endl;
}

// Módulo 2: Gestor de beneficios y acreditación de logros

struct Beneficio {
    string nombre;
    int costo;

    Beneficio(const string& n, int c) : nombre(n), costo(c) {}
};

void AgregarBeneficio(vector<Beneficio>& beneficios) {
    string nombre;
    int costo;
    cout << "Ingrese el nombre del beneficio: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el costo del beneficio en créditos: ";
    cin >> costo;
    beneficios.push_back(Beneficio(nombre, costo));
    cout << "Beneficio agregado exitosamente." << endl;
}

void ListarBeneficios(const vector<Beneficio>& beneficios) {
    cout << "Beneficios disponibles:" << endl;
    for (const Beneficio& beneficio : beneficios) {
        cout << beneficio.nombre << " - Costo: " << beneficio.costo << " créditos" << endl;
    }
}

void AcreditarLogros(Estudiante& estudiante, int puntos) {
    estudiante.creditos += puntos;
    cout << "Se acreditaron " << puntos << " puntos. Créditos disponibles: " << estudiante.creditos << endl;
}

// Módulo 3: Consumidor de beneficios

void IniciarSesion(const vector<Estudiante>& estudiantes, vector<Beneficio>& beneficios) {
    string email, clave;
    cout << "Ingrese su email: ";
    cin >> email;
    cout << "Ingrese su clave: ";
    cin >> clave;

    for (Estudiante& estudiante : estudiantes) {
        if (estudiante.email == email && estudiante.clave == clave) {
            cout << "Inicio de sesión exitoso." << endl;
            MostrarMenuBeneficios(estudiante, beneficios);
            return;
        }
    }

    cout << "Credenciales incorrectas." << endl;
}

void MostrarMenuBeneficios(Estudiante& estudiante, vector<Beneficio>& beneficios) {
    while (true) {
        cout << "\n--- Menú de Beneficios ---" << endl;
        cout << "1. Mostrar créditos disponibles" << endl;
        cout << "2. Mostrar beneficios disponibles" << endl;
        cout << "3. Consumir un beneficio" << endl;
        cout << "4. Acreditar logros" << endl;
        cout << "5. Cerrar sesión" << endl;
        cout << "Elija una opción: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Créditos disponibles: " << estudiante.creditos << endl;
                break;
            case 2:
                ListarBeneficios(beneficios);
                break;
            case 3:
                ConsumirBeneficio(estudiante, beneficios);
                break;
            case 4:
                int puntos;
                cout << "Ingrese la cantidad de puntos a acreditar: ";
                cin >> puntos;
                AcreditarLogros(estudiante, puntos);
                break;
            case 5:
                return;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

void ConsumirBeneficio(Estudiante& estudiante, vector<Beneficio>& beneficios) {
    string nombreBeneficio;
    cout << "Ingrese el nombre del beneficio que desea consumir: ";
    cin.ignore();
    getline(cin, nombreBeneficio);

    for (Beneficio& beneficio : beneficios) {
        if (beneficio.nombre == nombreBeneficio && beneficio.costo <= estudiante.creditos) {
            estudiante.creditos -= beneficio.costo;
            cout << "Beneficio '" << nombreBeneficio << "' consumido. Créditos restantes: " << estudiante.creditos << endl;
            return;
        }
    }

    cout << "No se pudo consumir el beneficio." << endl;
}

int main() {
    vector<Estudiante> estudiantes;
    vector<Beneficio> beneficios;

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Iniciar sesión como estudiante" << endl;
        cout << "3. Agregar beneficio" << endl;
        cout << "4. Listar beneficios" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                RegistrarEstudiante(estudiantes);
                break;
            case 2:
                IniciarSesion(estudiantes, beneficios);
                break;
            case 3:
                AgregarBeneficio(beneficios);
                break;
            case 4:
                ListarBeneficios(beneficios);
                break;
            case 5:
                return 0;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
