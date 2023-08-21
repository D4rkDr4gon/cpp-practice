#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

//estructura temporal de beneficios
struct Beneficio {
    string nombre;
    int valor;
};

//funcion para guardar en un archivo
void Guardar(Beneficio beneficio[]);

int main(){
    //array
    Beneficio beneficio[SIZE];

    //bucle para llenar archivo temporal
    for (int i = 0; i > SIZE; i++) {
        cout << "ingrese nombre del beneficio: " << endl;
        cin >> beneficio[i].nombre;
        cout << "ingrese valor del beneficio: " << endl;
        cin >> beneficio[i].valor;
    }

    Guardar(beneficio);

    return 0;
}

void Guardar(Beneficio beneficio[]){
    //abre archivo
    FILE* archivo = fopen("beneficios.txt", "wt");
    //escribe 
    fwrite(beneficio, sizeof(Beneficio) , SIZE, archivo);
    //cierra archivo
    fclose(archivo);
}

