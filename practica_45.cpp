#include <iostream>
#include <string>
#include <regex>
using namespace std;

struct Usuario {
    string nombre;
    string contrasena;
    string legajo;
    string email;
    int meritos; // Nuevo campo para los puntos de mérito
};

bool ValidarEmail(const string& email) {
    regex patron("\\b[A-Za-z0-9._%+-]+@frba.utn.edu.ar\\b");
    return regex_match(email, patron);
}

void Registro() {
    FILE* archivo = fopen("registros.dat", "ab");

    if (archivo == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    Usuario usuario1;

    cout << "------------- Registro de Usuario -------------" << endl;
    cout << "Nombre: ";
    cin >> usuario1.nombre;
    cout << "Contrasena: ";
    cin >> usuario1.contrasena;
    cout << "Legajo: ";
    cin >> usuario1.legajo;
    cout << "Email: ";
    cin >> usuario1.email;

    if (!ValidarEmail(usuario1.email)) {
        cout << "Email no válido. Debe terminar en @frba.utn.edu.ar." << endl;
        fclose(archivo);
        return;
    }

    usuario1.meritos = 100;

    cout << "-------------" << endl;

    fwrite(&usuario1, sizeof(Usuario), 1, archivo);

    fclose(archivo);
}

void ImprimirDatosUsuario(const Usuario& usuario) {
    cout << "Nombre: " << usuario.nombre << endl;
    cout << "Contrasena: " << usuario.contrasena << endl;
    cout << "Legajo: " << usuario.legajo << endl;
    cout << "Email: " << usuario.email << endl;
}

void LeerYMostrarRegistros() {
    FILE* archivo = fopen("registros.dat", "rb");

    if (archivo == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Usuario usuario;

    cout << "------------- Registros de Usuarios -------------" << endl;
    while (fread(&usuario, sizeof(Usuario), 1, archivo) == 1) {
        ImprimirDatosUsuario(usuario);
        cout << "-------------" << endl;
    }

    fclose(archivo);
}

void OrdenarRegistrosPorLegajo() {
    FILE* archivo = fopen("registros.dat", "rb+");

    if (archivo == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    fseek(archivo, 0, SEEK_END);
    int numRegistros = ftell(archivo) / sizeof(Usuario);

    bool intercambio;
    Usuario usuarioActual, usuarioSiguiente;

    do {
        intercambio = false;

        fseek(archivo, 0, SEEK_SET);
        fread(&usuarioActual, sizeof(Usuario), 1, archivo);

        for (int i = 0; i < numRegistros - 1; i++) {
            fread(&usuarioSiguiente, sizeof(Usuario), 1, archivo);

            if (usuarioActual.legajo > usuarioSiguiente.legajo) {
                fseek(archivo, -static_cast<long>(sizeof(Usuario) * 2), SEEK_CUR);
                fwrite(&usuarioSiguiente, sizeof(Usuario), 1, archivo);
                fwrite(&usuarioActual, sizeof(Usuario), 1, archivo);
                intercambio = true;
            }

            usuarioActual = usuarioSiguiente;
        }

    } while (intercambio);

    fclose(archivo);
}

int main() {
    Registro();
    OrdenarRegistrosPorLegajo();
    LeerYMostrarRegistros();

    return 0;
}
