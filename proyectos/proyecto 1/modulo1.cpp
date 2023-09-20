#include <iostream>
#include <string>
#include <regex>


using namespace std;

// Declaración de estructuras

struct Estudiante {
    int legajo;
    string nombre;
    string email;
    string clave;
    int meritos;
};

// Variables globales

Estudiante estudiantes[1000];
int numero_legajo = 1000000;
int total_estudiantes = 0;

// Declaración de funciones

void ver_informacion(Estudiante estudiante) {
    cout << "Información del estudiante:" << endl;
    cout << "Legajo: " << estudiante.legajo << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Email: " << estudiante.email << endl;
    cout << "Méritos disponibles: " << estudiante.meritos << endl;
}

void modificar_informacion(Estudiante& estudiante) {
    cout << "Modificar información del estudiante:" << endl;
    cout << "1. Cambiar nombre" << endl;
    cout << "2. Cambiar contraseña" << endl;
    cout << "3. Salir" << endl;
    string opcion;
    cin >> opcion;
    if (opcion == "1") {
        cout << "Nuevo nombre: ";
        cin >> estudiante.nombre;
    }
    else if (opcion == "2") {
        cout << "Nueva contraseña: ";
        cin >> estudiante.clave;
    }
    else if (opcion == "3") {
        return;
    }
    else {
        cout << "Opción no válida." << endl;
    }
    cout << "Información modificada con éxito." << endl;
}

bool validar_email(string email) {
    regex patron("\\b[A-Za-z0-9._%+-]+@frba.utn.edu.ar\\b");
    return regex_match(email, patron);
}

void registrar_estudiante() {
    cout << "Crear nueva cuenta de estudiante:" << endl;
    Estudiante nuevo_estudiante;
    nuevo_estudiante.legajo = numero_legajo++;
    cout << "Nombre del estudiante: ";
    cin >> nuevo_estudiante.nombre;
    cout << "Ingrese el email del estudiante: ";
    cin >> nuevo_estudiante.email;
    cout << "Ingrese la contraseña del estudiante: ";
    cin >> nuevo_estudiante.clave;

    if (!validar_email(nuevo_estudiante.email)) {
        cout << "Email no válido." << endl;
        return;
    }

    for (int i = 0; i < total_estudiantes; i++) {
        if (estudiantes[i].email == nuevo_estudiante.email) {
            cout << "El email ya está registrado." << endl;
            return;
        }
    }

    nuevo_estudiante.meritos = 1000;
    estudiantes[total_estudiantes++] = nuevo_estudiante;
    cout << "Registro exitoso." << endl;
}

void guardar_registros() {
    // Abre un archivo binario y guarda los datos en él
    FILE* archivo = fopen("registros.dat", "ab+");
    if (archivo != NULL) {
        fwrite(estudiantes, sizeof(Estudiante), total_estudiantes, archivo);
        fclose(archivo);
    }
}

void cargar_registros() {
    // Lee los datos del archivo binario y carga en memoria
    FILE* archivo = fopen("registros.dat", "ab+");
    if (archivo != NULL) {
        fseek(archivo, 0, SEEK_END);
        long fileSize = ftell(archivo);
        fseek(archivo, 0, SEEK_SET);
        total_estudiantes = fileSize / sizeof(Estudiante);
        fread(estudiantes, sizeof(Estudiante), total_estudiantes, archivo);
        fclose(archivo);
    }
}

int main() {
    cargar_registros();

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Iniciar sesión como estudiante" << endl;
        cout << "2. Crear cuenta de estudiante" << endl;
        cout << "3. Salir" << endl;

        string opcion;
        cin >> opcion;

        if (opcion == "1") {
            cout << "Ingrese su email: ";
            string email;
            cin >> email;
            cout << "Ingrese su contraseña: ";
            string clave;
            cin >> clave;

            for (int i = 0; i < total_estudiantes; i++) {
                if (estudiantes[i].email == email && estudiantes[i].clave == clave) {
                    cout << "Inicio de sesión exitoso." << endl;
                    ver_informacion(estudiantes[i]);
                    modificar_informacion(estudiantes[i]);
                    guardar_registros();
                    break;
                }
            }
            cout << "Credenciales incorrectas." << endl;
        }
        else if (opcion == "2") {
            registrar_estudiante();
            guardar_registros();
        }
        else if (opcion == "3") {
            guardar_registros();
            break;
        }
        else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
