#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Estudiante {
    static int numero_legajo;
    int legajo;
    string email;
    string clave;
    string nombre;
    int meritos;

    Estudiante(string nombre, string email, string clave)
        : legajo(numero_legajo++), email(email), clave(clave), nombre(nombre), meritos(1000) {}

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
        string opcion;
        cout << "¿Qué desea hacer?: ";
        cin >> opcion;

        if (opcion == "1") {
            cout << "Nuevo nombre: ";
            cin >> nombre;
        } else if (opcion == "2") {
            cout << "Nueva clave: ";
            cin >> clave;
        } else if (opcion == "3") {
            return;
        } else {
            cout << "Opción no válida." << endl;
        }

        cout << "Información modificada con éxito." << endl;
    }
};

int Estudiante::numero_legajo = 1;

struct Beneficio {
    string nombre;
    int costo;

    Beneficio(string nombre, int costo) : nombre(nombre), costo(costo) {}
};

void agregar_beneficio(vector<Beneficio>& beneficios, string nombre, int costo) {
    beneficios.push_back(Beneficio(nombre, costo));
    cout << "Beneficio agregado exitosamente." << endl;
}

void listar_beneficios(const vector<Beneficio>& beneficios) {
    cout << "Beneficios disponibles:" << endl;
    for (const Beneficio& beneficio : beneficios) {
        cout << beneficio.nombre << " - Costo: " << beneficio.costo << " créditos" << endl;
    }
}

void acreditar_logros(Estudiante& estudiante, int puntos) {
    estudiante.meritos += puntos;
    cout << "Se acreditaron " << puntos << " puntos. Méritos disponibles: " << estudiante.meritos << endl;
}

void iniciar_sesion(vector<Estudiante>& estudiantes, vector<Beneficio>& beneficios) {
    string email, clave;
    cout << "Ingrese su email: ";
    cin >> email;
    cout << "Ingrese su clave: ";
    cin >> clave;

    for (Estudiante& estudiante : estudiantes) {
        if (estudiante.email == email && estudiante.clave == clave) {
            cout << "Inicio de sesión exitoso." << endl;
            mostrar_menu_beneficios(estudiante, beneficios);
            return;
        }
    }

    cout << "Credenciales incorrectas." << endl;
}

void mostrar_menu_beneficios(Estudiante& estudiante, vector<Beneficio>& beneficios) {
    while (true) {
        cout << "\n--- Menú de Beneficios ---" << endl;
        cout << "1. Mostrar créditos disponibles" << endl;
        cout << "2. Mostrar beneficios disponibles" << endl;
        cout << "3. Acreditar logros" << endl;
        cout << "4. Cerrar sesión" << endl;
        string opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == "1") {
            cout << "Créditos disponibles: " << estudiante.meritos << endl;
        } else if (opcion == "2") {
            listar_beneficios(beneficios);
        } else if (opcion == "3") {
            int puntos;
            cout << "Ingrese la cantidad de puntos a acreditar: ";
            cin >> puntos;
            acreditar_logros(estudiante, puntos);
        } else if (opcion == "4") {
            return;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

struct Administrador {
    string username;
    string password;

    Administrador(string username, string password)
        : username(username), password(password) {}
};

bool autenticar_administrador(const vector<Administrador>& administradores, const string& username, const string& password) {
    for (const Administrador& admin : administradores) {
        if (admin.username == username && admin.password == password) {
            return true;
        }
    }
    return false;
}

void menu_administracion(vector<Estudiante>& estudiantes, vector<Beneficio>& beneficios) {
    while (true) {
        cout << "\n--- Menú de Administración ---" << endl;
        cout << "1. Agregar beneficio" << endl;
        cout << "2. Salir" << endl;
        string opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == "1") {
            string nombre;
            int costo;
            cout << "Ingrese el nombre del beneficio: ";
            cin >> nombre;
            cout << "Ingrese el costo del beneficio en créditos: ";
            cin >> costo;
            agregar_beneficio(beneficios, nombre, costo);
        } else if (opcion == "2") {
            return;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

void guardar_registros(const vector<Estudiante>& estudiantes, const vector<Beneficio>& beneficios) {
    FILE* archivo = fopen("registros.dat", "wb");
    if (archivo) {
        for (const Estudiante& estudiante : estudiantes) {
            fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
        }
        fclose(archivo);
        cout << "Registros guardados exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo de registros." << endl;
    }
}

void cargar_registros(vector<Estudiante>& estudiantes) {
    FILE* archivo = fopen("registros.dat", "rb");
    if (archivo) {
        estudiantes.clear();
        Estudiante estudiante;
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
            estudiantes.push_back(estudiante);
        }
        fclose(archivo);
        cout << "Registros cargados exitosamente." << endl;
    } else {
        cout << "No se encontró el archivo de registros." << endl;
    }
}

int main() {
    vector<Beneficio> beneficios;
    vector<Administrador> administradores;
    vector<Estudiante> estudiantes;

    administradores.push_back(Administrador("admin1", "contraseña1"));
    administradores.push_back(Administrador("admin2", "contraseña2"));

    cargar_registros(estudiantes);

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Iniciar sesión como estudiante" << endl;
        cout << "2. Iniciar sesión como administrador" << endl;
        cout << "3. Salir" << endl;
        string opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == "1") {
            iniciar_sesion(estudiantes, beneficios);
        } else if (opcion == "2") {
            while (true) {
                string username, password;
                cout << "Ingrese el nombre de usuario del administrador: ";
                cin >> username;
                cout << "Ingrese la contraseña del administrador: ";
                cin >> password;

                if (autenticar_administrador(administradores, username, password)) {
                    cout << "Inicio de sesión de administrador exitoso." << endl;
                    menu_administracion(estudiantes, beneficios);
                    break;
                } else {
                    cout << "Credenciales de administrador incorrectas. Intente nuevamente." << endl;
                }
            }
        } else if (opcion == "3") {
            guardar_registros(estudiantes, beneficios);
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
