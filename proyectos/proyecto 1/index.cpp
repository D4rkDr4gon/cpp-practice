#include <iostream>
#include <regex>
#include <string>

using namespace std;

// Módulo 1: Gestor de Estudiantes

struct Estudiante {
    int legajo;
    string nombre;
    string email;
    string clave;
    int meritos;
};

int numero_legajo = 1; // Inicializar el número de legajo

void ver_informacion_estudiante(Estudiante estudiante) {
    cout << "Información del estudiante:" << endl;
    cout << "Legajo: " << estudiante.legajo << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Email: " << estudiante.email << endl;
    cout << "Méritos disponibles: " << estudiante.meritos << endl;
}

void modificar_informacion_estudiante(Estudiante& estudiante) {
    cout << "Modificar información del estudiante:" << endl;
    cout << "1. Cambiar nombre" << endl;
    cout << "2. Cambiar contraseña" << endl;
    cout << "3. Salir" << endl;
    int opcion;
    cout << "¿Qué desea hacer? (1/2/3): ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "Nuevo nombre: ";
        cin >> estudiante.nombre;
    } else if (opcion == 2) {
        cout << "Nueva clave: ";
        cin >> estudiante.clave;
    }
    cout << "Información modificada con éxito." << endl;
}

bool validar_email(string email) {
    // Función para validar el formato de un email
    string pattern = R"(\b[A-Za-z0-9._%+-]+@frba.utn.edu.ar\b)";
    return regex_match(email, regex(pattern));
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

    if (!validar_email(nuevoEstudiante.email)) {
        cout << "Email no válido." << endl;
        return;
    }

    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].email == nuevoEstudiante.email) {
            cout << "El email ya está registrado." << endl;
            return;
        }
    }

    nuevoEstudiante.legajo = numero_legajo;
    numero_legajo++;
    nuevoEstudiante.meritos = 1000;
    estudiantes[numEstudiantes] = nuevoEstudiante;
    numEstudiantes++;

    cout << "Registro exitoso." << endl;
}

// Módulo 2: Gestor de Beneficios y Acreditación de Logros

struct Beneficio {
    string nombre;
    int costo;
};

void mostrar_menu_beneficios(Estudiante& estudiante, const Beneficio beneficios[], int numbeneficios) {
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
            listar_beneficios(beneficios, numBeneficios);
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


void agregar_beneficio(Beneficio beneficios[], int& numBeneficios) {
    cout << "Ingrese el nombre del beneficio: ";
    cin >> beneficios[numBeneficios].nombre;
    cout << "Ingrese el costo del beneficio en créditos: ";
    cin >> beneficios[numBeneficios].costo;
    numBeneficios++;
    cout << "Beneficio agregado exitosamente." << endl;
}

void listar_beneficios(Beneficio beneficios[], int numBeneficios) {
    cout << "Beneficios disponibles:" << endl;
    for (int i = 0; i < numBeneficios; ++i) {
        cout << beneficios[i].nombre << " - Costo: " << beneficios[i].costo << " créditos" << endl;
    }
}

void acreditar_logros(Estudiante& estudiante, int puntos) {
    estudiante.meritos += puntos;
    cout << "Se acreditaron " << puntos << " puntos. Méritos disponibles: " << estudiante.meritos << endl;
}

// Módulo 3: Consumidor de Beneficios

void consumir_beneficio(Estudiante& estudiante, Beneficio beneficios[], int& numBeneficios) {
    string nombre_beneficio;
    cout << "Ingrese el nombre del beneficio que desea consumir: ";
    cin >> nombre_beneficio;

    for (int i = 0; i < numBeneficios; ++i) {
        if (beneficios[i].nombre == nombre_beneficio && beneficios[i].costo <= estudiante.meritos) {
            estudiante.meritos -= beneficios[i].costo;
            cout << "Beneficio '" << nombre_beneficio << "' consumido. Créditos restantes: " << estudiante.meritos << endl;
            return;
        }
    }

    cout << "No se pudo consumir el beneficio." << endl;
}

// Módulo 4: Administración

struct Administrador {
    string username;
    string password;
};

bool autenticar_administrador(Administrador administradores[], int numAdministradores, string username, string password) {
    for (int i = 0; i < numAdministradores; ++i) {
        if (administradores[i].username == username && administradores[i].password == password) {
            return true;
        }
    }
    return false;
}

void menu_administracion(Estudiante estudiantes[], int numEstudiantes, Beneficio beneficios[], int numBeneficios) {
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
            string email;
            cout << "Ingrese el email del estudiante cuyos datos desea modificar: ";
            cin >> email;

            for (int i = 0; i < numEstudiantes; ++i) {
                if (estudiantes[i].email == email) {
                    modificar_informacion_estudiante(estudiantes[i]);
                    break;
                }
            }

            cout << "Estudiante no encontrado." << endl;
        } else if (opcion == 2) {
            if (numBeneficios < 100) { // Suponemos un máximo de 100 beneficios
                agregar_beneficio(beneficios, numBeneficios);
            } else {
                cout << "Se ha alcanzado el límite de beneficios." << endl;
            }
        } else if (opcion == 3) {
            if (numEstudiantes < 100) { // Suponemos un máximo de 100 estudiantes
                crear_cuenta_estudiante(estudiantes, numEstudiantes);
            } else {
                cout << "Se ha alcanzado el límite de estudiantes." << endl;
            }
        } else if (opcion == 4) {
            return;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}

void guardar_registros(Estudiante estudiantes[], int numEstudiantes, Beneficio beneficios[], int numBeneficios) {
    FILE* registros_file = fopen("registros.dat", "wb");

    if (registros_file != nullptr) {
        fwrite(estudiantes, sizeof(Estudiante), numEstudiantes, registros_file);
        fwrite(beneficios, sizeof(Beneficio), numBeneficios, registros_file);
        fclose(registros_file);
        cout << "Registros guardados exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo de registros." << endl;
    }
}

void guardar_logros_y_beneficios(Beneficio beneficios[], int numBeneficios) {
    FILE* logros_file = fopen("logrosYbeneficios.txt", "wb");

    if (logros_file != nullptr) {
        // Utilizamos fwrite para escribir los datos en el archivo binario
        for (int i = 0; i < numBeneficios; ++i) {
            fwrite(beneficios[i].nombre.c_str(), sizeof(char), beneficios[i].nombre.size(), logros_file);
            fwrite("\n", sizeof(char), 1, logros_file);
            fwrite(&beneficios[i].costo, sizeof(int), 1, logros_file);
            fwrite(" créditos\n", sizeof(char), 10, logros_file);
        }
        fclose(logros_file);
        cout << "Logros y beneficios guardados exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo de logros y beneficios." << endl;
    }
}

void iniciar_sesion_estudiante(Estudiante estudiantes[], int numEstudiantes, Beneficio beneficios[], int numBeneficios) {
    string email;
    string clave;
    cout << "Ingrese su email: ";
    cin >> email;
    cout << "Ingrese su clave: ";
    cin >> clave;

    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].email == email && estudiantes[i].clave == clave) {
            cout << "Inicio de sesión exitoso." << endl;
            mostrar_menu_beneficios(estudiantes[i], beneficios, numBeneficios);
            return;
        }
    }

    cout << "Credenciales incorrectas." << endl;
}

int main() {
    Estudiante estudiantes[100]; // Supongamos un máximo de 100 estudiantes
    int numEstudiantes = 0;
    Beneficio beneficios[100];   // Supongamos un máximo de 100 beneficios
    int numBeneficios = 0;
    Administrador administradores[2]; // Usamos 2 administradores

    administradores[0].username = "admin1";
    administradores[0].password = "contraseña1";
    administradores[1].username = "admin2";
    administradores[1].password = "contraseña2";

    while (true) {
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Iniciar sesión como estudiante" << endl;
        cout << "2. Iniciar sesión como administrador" << endl;
        cout << "3. Crear cuenta de estudiante" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            iniciar_sesion_estudiante(estudiantes, numEstudiantes, beneficios, numBeneficios);
        } else if (opcion == 2) {
            while (true) {
                string username;
                string password;
                cout << "Ingrese el nombre de usuario del administrador: ";
                cin >> username;
                cout << "Ingrese la contraseña del administrador: ";
                cin >> password;

                if (autenticar_administrador(administradores, 2, username, password)) {
                    cout << "Inicio de sesión de administrador exitoso." << endl;
                    menu_administracion(estudiantes, numEstudiantes, beneficios, numBeneficios);
                    break;
                } else {
                    cout << "Credenciales de administrador incorrectas. Intente nuevamente." << endl;
                }
            }
        } else if (opcion == 3) {
            if (numEstudiantes < 100) { // Suponemos un máximo de 100 estudiantes
                crear_cuenta_estudiante(estudiantes, numEstudiantes);
            } else {
                cout << "Se ha alcanzado el límite de estudiantes." << endl;
            }
        } else if (opcion == 4) {
            guardar_registros(estudiantes, numEstudiantes, beneficios, numBeneficios);
            guardar_logros_y_beneficios(beneficios, numBeneficios);
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
