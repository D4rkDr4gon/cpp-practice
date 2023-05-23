#include <iostream>
#include <string>
#include <vector>
using namespace std;

//estructura
struct Tarea{
    string nombre;
    string descripcion;
    string progreso;
};

//crear nueva tarea
void Create(vector<Tarea>& gestor){

    Tarea tarea;
    cout << "----- Nueva Tarea -----" << endl;
    cout << "ingrese titulo de la tarea: " << endl;
    cin >> tarea.nombre;
    cout << "ingrese una breve descripcion: " << endl;
    cin >> tarea.descripcion;
    cout << "progreso de la tarea predefinido como en progreso" << endl;
    tarea.progreso = "en prgreso";

    //asigna la tarea a la ultima poscision del vector
    gestor.push_back(tarea);
}

//mostrar tareas pendientes
void Mostrar(vector<Tarea>& gestor){

    for (int i = 0; i < gestor.size(); i++){
        cout << "----- TAREA -----" << endl
             << "titulo: " << gestor[i].nombre << endl
             << "descripcion: " << gestor[i].descripcion << endl
             << "estado: " << gestor[i].progreso << endl;
    }
}

// definir si se realizo o no la tarea
void Progreso(vector<Tarea>& gestor) {
    Tarea dato;
    cout << "----- progreso de la tarea -----" << endl;
    cout << "nombre de la tarea: ";
    cin >> dato.nombre;


    for (int i = 0; i < gestor.size(); i++){
        if (gestor[i].nombre == dato.nombre){
            gestor[i].progreso = "completado";
        }else {
            cout << "no encontrada la tarea";
        }
    }
}

int main(){
    //vector
    vector<Tarea> gestor;

    char option;
    cout << "bienvenido al gestor de archivos!!" << endl;
    
    while(true){

        cout << "---------------------------------" << endl;
        cout << "que queres hacer? " << endl
             << "c = crear tarea" << endl
             << "m = mostrar tareas" << endl
             << "p = registrar tarea completada" << endl
             << "q = quit" << endl;
        cin >> option;

        //condicional
        if (option == 'c' || option == 'C'){
            //funcion de crear tarea
            Create(gestor);
        } else if (option == 'p' || option == 'P'){
            //progreso
            Progreso(gestor);
        } else if (option == 'm' || option == 'M'){
            //motstrar tareas
            Mostrar(gestor);
        }else if (option == 'q' || option == 'Q'){
            cout << "fin del programa!!" << endl;
            break;
        } else {
            cout << "no registrado" << endl;
        }
    }
    


    return 0;
}