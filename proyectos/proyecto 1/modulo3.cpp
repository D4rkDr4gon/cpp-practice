#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    static int numero_legajo;
    int legajo;
    string email;
    string clave;
    string nombre;
    int meritos;

    Estudiante(const string& nombre, const string& email, const string& clave)
        : legajo(numero_legajo++), meritos(1000), nombre(nombre), email(email), clave(clave) {
    }

    void ver_informacion() {
        cout << "Información del estudiante:" << endl;
        cout << "Legajo: " << legajo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Email: " << email << endl;
        cout << "Méritos disponibles: " << meritos << endl;
    }

    void modificar_informacion() {
        cout << "Modificar información del estudiante:" << endl;
        cout << "1. Cambiar nombre" << endl;
        cout << "2. Cambiar contraseña" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cout << "¿Qué desea hacer?: ";
        cin >> opcion;
        if (opcion == 1) {
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, nombre);
        } else if (opcion == 2) {
            cout << "Nueva clave: ";
            cin.ignore();
            getline(cin, clave);
        } else if (opcion == 3) {
            return;
        }

        cout << "Información modificada con éxito." << endl;
    }
};

int Estudiante::numero_legajo = 1;

struct Beneficio {
    string nombre;
    int costo;

    Beneficio(const string& nombre, int costo)
        : nombre(nombre), costo(costo) {
    }
};

void agregar_beneficio(Beneficio beneficios[], int& num_beneficios, const string& nombre, int costo) {
    if (num_beneficios < 100) {
        beneficios[num_beneficios++] = Beneficio(nombre, costo);
        cout << "Beneficio agregado exitosamente." << endl;
    } else {
        cout << "No se pueden agregar más beneficios." << endl;
    }
}

void listar_beneficios(const Beneficio beneficios[], int num_beneficios) {
    cout << "Beneficios disponibles:" << endl;
    for (int i = 0; i < num_beneficios; i++) {
        cout << beneficios[i].nombre << " - Costo: " << beneficios[i].costo << " créditos" << endl;
    }
}

void acreditar_logros(Estudiante& estudiante, int puntos) {
    estudiante.meritos += puntos;
    cout << "Se acreditaron " << puntos << " puntos. Méritos disponibles: " << estudiante.meritos << endl;
}

void iniciar_sesion(Estudiante estudiantes[], int& num_estudiantes, Beneficio beneficios[], int num_beneficios) {
    string email, clave;
    cout << "Ingrese su email: ";
    cin >> email;
    cout << "Ingrese su clave: ";
    cin >> clave;

    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].email == email && estudiantes[i].clave == clave) {
            cout << "Inicio de sesión exitoso." << endl;
            mostrar_menu_beneficios(estudiantes[i], beneficios, num_beneficios);
            return;
        }
    }

    cout << "Credenciales incorrectas." << endl;
}

void mostrar_menu_beneficios(Estudiante& estudiante, const Beneficio beneficios[], int num_beneficios) {
    while (true) {
        cout << "\n--- Menú de Beneficios ---" << endl;
        cout << "1. Mostrar créditos disponibles" << endl;
        cout << "2. Mostrar beneficios disponibles" << endl;
        cout << "3. Acreditar logros" << endl;
        cout << "4. Cerrar sesión" << endl;

        int opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Créditos disponibles: " << estudiante.meritos << endl;
        } else if (opcion == 2) {
            listar_beneficios(beneficios, num_beneficios);
        } else if (opcion == 3) {
            int puntos;
            cout << "Ingrese la cantidad de puntos a acreditar: ";
            cin >> puntos;
            acreditar_logros(estudiante, puntos);
        } else if (opcion == 4) {
            return;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

void guardar_registros(const Estudiante estudiantes[], int num_estudiantes, const Beneficio beneficios[], int num_beneficios) {
    FILE* registros_file = fopen("registros.dat", "wb");
    if (registros_file) {
        fwrite(estudiantes, sizeof(Estudiante), num_estudiantes, registros_file);
        fwrite(beneficios, sizeof(Beneficio), num_beneficios, registros_file);
        fclose(registros_file);
        cout << "Registros guardados exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo de registros." << endl;
    }
}

void guardar_logros_y_beneficios(const Beneficio beneficios[], int num_beneficios) {
    FILE* logros_file = fopen("logrosYbeneficios.txt", "w");
    if (logros_file) {
        fprintf(logros_file, "Beneficios disponibles:\n");
        for (int i = 0; i < num_beneficios; i++) {
            fprintf(logros_file, "%s - Costo: %d créditos\n", beneficios[i].nombre.c_str(), beneficios[i].costo);
        }
        fclose(logros_file);
        cout << "Logros y beneficios guardados exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo de logros y beneficios." << endl;
    }
}

int main() {
    Estudiante estudiantes[100];
    int num_estudiantes = 0;
    Beneficio beneficios[100];
    int num_beneficios = 0;

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Iniciar sesión como estudiante" << endl;
        cout << "2. Salir" << endl;

        int opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            iniciar_sesion(estudiantes, num_estudiantes, beneficios, num_beneficios);
        } else if (opcion == 2) {
            guardar_registros(estudiantes, num_estudiantes, beneficios, num_beneficios);
            guardar_logros_y_beneficios(beneficios, num_beneficios);
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
