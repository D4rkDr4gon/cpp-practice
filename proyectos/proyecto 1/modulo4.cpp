#include <iostream>
#include <cstdio>

using namespace std;

struct Estudiante {
    int legajo;
    string nombre;
    string email;
    string clave;
    int meritos;
};

struct Beneficio {
    string nombre;
    int costo;
};

struct Administrador {
    string username;
    string password;
};

bool autenticar_administrador(Administrador administradores[], int numAdministradores, const string& username, const string& password) {
    for (int i = 0; i < numAdministradores; ++i) {
        if (administradores[i].username == username && administradores[i].password == password) {
            return true;
        }
    }
    return false;
}

void menu_administracion(Estudiante estudiantes[], int& numEstudiantes, Beneficio beneficios[], int& numBeneficios) {
    while (true) {
        cout << "\n--- Menú de Administración ---" << endl;
        cout << "1. Modificar datos de estudiante" << endl;
        cout << "2. Agregar beneficio" << endl;
        cout << "3. Crear cuenta de estudiante" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            modificar_datos_estudiante(estudiantes, numEstudiantes);
        } else if (opcion == 2) {
            // Llamar a la función agregar_beneficio
        } else if (opcion == 3) {
            crear_cuenta_estudiante(estudiantes, numEstudiantes);
        } else if (opcion == 4) {
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

void modificar_datos_estudiante(Estudiante estudiantes[], int numEstudiantes) {
    string email;
    cout << "Ingrese el email del estudiante cuyos datos desea modificar: ";
    cin >> email;

    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].email == email) {
            string nueva_clave;
            cout << "Ingrese la nueva clave para el estudiante: ";
            cin >> nueva_clave;
            estudiantes[i].clave = nueva_clave;
            cout << "Datos del estudiante actualizados." << endl;
            return;
        }
    }

    cout << "Estudiante no encontrado." << endl;
}

void crear_cuenta_estudiante(Estudiante estudiantes[], int& numEstudiantes) {
    cout << "Crear nueva cuenta de estudiante:" << endl;
    Estudiante nuevoEstudiante;
    cout << "Nombre del estudiante: ";
    cin >> nuevoEstudiante.nombre;
    cout << "Ingrese el email del estudiante: ";
    cin >> nuevoEstudiante.email;
    cout << "Ingrese la clave del estudiante: ";
    cin >> nuevoEstudiante.clave;

    bool emailValido = true; // Implementa tu validación de email si es necesario

    if (!emailValido) {
        cout << "Email no válido." << endl;
        return;
    }

    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].email == nuevoEstudiante.email) {
            cout << "El email ya está registrado." << endl;
            return;
        }
    }

    nuevoEstudiante.legajo = numEstudiantes + 1;
    nuevoEstudiante.meritos = 1000;
    estudiantes[numEstudiantes] = nuevoEstudiante;
    numEstudiantes++;

    cout << "Registro exitoso." << endl;
}

void guardar_registros(Estudiante estudiantes[], int numEstudiantes, Beneficio beneficios[], int numBeneficios) {
    FILE* registros_file = fopen("registros.dat", "wb");

    if (registros_file != nullptr) {
        fwrite(estudiantes, sizeof(Estudiante), numEstudiantes, registros_file);
        fwrite(beneficios, sizeof(Beneficio), numBeneficios, registros_file);
        fclose(registros_file);
    } else {
        cout << "Error al abrir el archivo de registros." << endl;
    }
}

void guardar_logros_y_beneficios(Beneficio beneficios[], int numBeneficios) {
    FILE* logros_file = fopen("logrosYbeneficios.txt", "w");

    if (logros_file != nullptr) {
        fwrite("Beneficios disponibles:\n", sizeof(char), 24, logros_file);
        for (int i = 0; i < numBeneficios; ++i) {
            string beneficioInfo = beneficios[i].nombre + " - Costo: " + to_string(beneficios[i].costo) + " créditos\n";
            fwrite(beneficioInfo.c_str(), sizeof(char), beneficioInfo.size(), logros_file);
        }
        fclose(logros_file);
    } else {
        cout << "Error al abrir el archivo de logros y beneficios." << endl;
    }
}

int main() {
    Administrador administradores[] = {{"admin1", "contraseña1"}, {"admin2", "contraseña2"}};
    int numAdministradores = sizeof(administradores) / sizeof(administradores[0]);

    Estudiante estudiantes[100]; // Tamaño máximo de estudiantes
    int numEstudiantes = 0;

    Beneficio beneficios[100]; // Tamaño máximo de beneficios
    int numBeneficios = 0;

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Iniciar sesión como administrador" << endl;
        cout << "2. Salir" << endl;

        int opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            while (true) {
                string username;
                string password;
                cout << "Ingrese el nombre de usuario del administrador: ";
                cin >> username;
                cout << "Ingrese la contraseña del administrador: ";
                cin >> password;

                if (autenticar_administrador(administradores, numAdministradores, username, password)) {
                    cout << "Inicio de sesión de administrador exitoso." << endl;
                    menu_administracion(estudiantes, numEstudiantes, beneficios, numBeneficios);
                    break;
                } else {
                    cout << "Credenciales de administrador incorrectas. Intente nuevamente." << endl;
                }
            }
        } else if (opcion == 2) {
            guardar_registros(estudiantes, numEstudiantes, beneficios, numBeneficios);
            guardar_logros_y_beneficios(beneficios, numBeneficios);
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
