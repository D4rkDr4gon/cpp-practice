#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct Estudiante {
    static int numero_legajo;
    int legajo;
    string email;
    string clave;
    string nombre;
    int meritos;

    void inicializar(string nombre, string email, string clave) {
        legajo = numero_legajo++;
        this->nombre = nombre;
        this->email = email;
        this->clave = clave;
        meritos = 1000;
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

    void inicializar(string nombre, int costo) {
        this->nombre = nombre;
        this->costo = costo;
    }
};

void agregar_beneficio(Beneficio beneficios[], int& num_beneficios, string nombre, int costo) {
    beneficios[num_beneficios].inicializar(nombre, costo);
    num_beneficios++;
    cout << "Beneficio agregado exitosamente." << endl;
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

void iniciar_sesion(Estudiante estudiantes[], int num_estudiantes, Beneficio beneficios[], int num_beneficios) {
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

void mostrar_menu_beneficios(Estudiante& estudiante, Beneficio beneficios[], int num_beneficios) {
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
            listar_beneficios(beneficios, num_beneficios);
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

    void inicializar(string username, string password) {
        this->username = username;
        this->password = password;
    }
};

bool autenticar_administrador(Administrador administradores[], int num_administradores, const string& username, const string& password) {
    for (int i = 0; i < num_administradores; i++) {
        if (administradores[i].username == username && administradores[i].password == password) {
            return true;
        }
    }
    return false;
}

void menu_administracion(Beneficio beneficios[], int& num_beneficios) {
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
            agregar_beneficio(beneficios, num_beneficios, nombre, costo);
        } else if (opcion == "2") {
            return;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

void guardar_registros(Estudiante estudiantes[], int num_estudiantes, Beneficio beneficios[], int num_beneficios) {
    FILE* archivo = fopen("registros.dat", "wb");
    if (archivo) {
        for (int i = 0; i < num_estudiantes; i++) {
            fwrite(&estudiantes[i], sizeof(Estudiante), 1, archivo);
        }
        fclose(archivo);
        cout << "Registros guardados exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo de registros." << endl;
    }
}

void cargar_registros(Estudiante estudiantes[], int& num_estudiantes) {
    FILE* archivo = fopen("registros.dat", "rb");
    if (archivo) {
        num_estudiantes = 0;
        Estudiante estudiante;
        while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
            estudiantes[num_estudiantes].inicializar(estudiante.nombre, estudiante.email, estudiante.clave);
            estudiantes[num_estudiantes].meritos = estudiante.meritos;
            num_estudiantes++;
        }
        fclose(archivo);
        cout << "Registros cargados exitosamente." << endl;
    } else {
        cout << "No se encontró el archivo de registros." << endl;
    }
}

int main() {
    const int MAX_ESTUDIANTES = 100;
    const int MAX_BENEFICIOS = 100;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    Beneficio beneficios[MAX_BENEFICIOS];
    Administrador administradores[2]; // Dos administradores según tu código original

    administradores[0].inicializar("admin1", "contraseña1");
    administradores[1].inicializar("admin2", "contraseña2");

    int num_estudiantes = 0;
    cargar_registros(estudiantes, num_estudiantes);
    int num_beneficios = 0;

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Iniciar sesión como estudiante" << endl;
        cout << "2. Iniciar sesión como administrador" << endl;
        cout << "3. Salir" << endl;
        string opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == "1") {
            iniciar_sesion(estudiantes, num_estudiantes, beneficios, num_beneficios);
        } else if (opcion == "2") {
            while (true) {
                string username, password;
                cout << "Ingrese el nombre de usuario del administrador: ";
                cin >> username;
                cout << "Ingrese la contraseña del administrador: ";
                cin >> password;

                if (autenticar_administrador(administradores, 2, username, password)) {
                    cout << "Inicio de sesión de administrador exitoso." << endl;
                    menu_administracion(beneficios, num_beneficios);
                    break;
                } else {
                    cout << "Credenciales de administrador incorrectas. Intente nuevamente." << endl;
                }
            }
        } else if (opcion == "3") {
            guardar_registros(estudiantes, num_estudiantes, beneficios, num_beneficios);
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
