#include <iostream>
#include <string>
using namespace std;

//constante q da la cantidad maxima de contactos q puede tener la libreria
const int CantContacto = 1;

//estructura de contacto
struct Contacto
{
    string nombre;
    int num;
    int cod_area;
    string correo;
};

//nuevo contacto
void NewCont(Contacto contacto[])
{
    static int Cant1 = 0;

    if (Cant1 < CantContacto)
    {
        cout << "Ingrese el Nombre: ";
        cin >> contacto[Cant1].nombre;
        cout << "Ingrese el código de área: ";
        cin >> contacto[Cant1].cod_area;
        cout << "Ingrese el número: ";
        cin >> contacto[Cant1].num;
        cout << "Ingrese el correo electrónico: ";
        cin >> contacto[Cant1].correo;

        Cant1++;
    }
    else
    {
        cout << "No hay más espacio para agregar contactos." << endl;
    }
}

//busqueda de dato

//busca el indice
int Indice(Contacto contacto[], Contacto dato)
{
    for (int i = 0; i < CantContacto; i++)
    {
        if (contacto[i].cod_area == dato.cod_area ||
            contacto[i].correo == dato.correo ||
            contacto[i].nombre == dato.nombre ||
            contacto[i].num == dato.num)
        {
            return i;
        }
    }

    return -1;
}

//funcion q usando el indice devuelve el contacto
void SearchCont(Contacto contacto[])
{
    Contacto dato;
    cout << "Dato de búsqueda: ";
    cin >> dato.nombre;

    //llama a la funcion indice
    int indice = Indice(contacto, dato);

    if (indice != -1)
    {
        cout << "Nombre: " << contacto[indice].nombre << endl
             << "Número de teléfono: +" << contacto[indice].cod_area << " " << contacto[indice].num << endl
             << "Correo electrónico: " << contacto[indice].correo << endl;
    }
    else
    {
        cout << "No se encontró el dato." << endl;
    }
}

//imprimir contactos
void PrintCont(Contacto contacto[]){
    cout << "lista de contactos:" << endl;

    for (int i = 0; i < CantContacto; i++){
        cout << "Nombre: " << contacto[i].nombre << endl
             << "Número de teléfono: +" << contacto[i].cod_area << " " << contacto[i].num << endl
             << "Correo electrónico: " << contacto[i].correo << endl;
    }
}

//eliminar un contacto
void DeleteCont(Contacto contacto[]){
    Contacto dato;
    cout << "nombre contacto: ";
    cin >> dato.nombre;

    //llama a la funcion indice
    int indice = Indice(contacto, dato);

    if (indice != -1){
        for (int i = 0; i < CantContacto - 1; i++){
            //borra el dato
            contacto[i] = contacto[i+1];
        }

        cout << "se ah borrado el contacto" << endl;
    }
}

int main()
{
    //array
    Contacto contacto[CantContacto];

    char eleccion;

    cout << "bienvenido a la libreta de contactos!!" << endl;
    
    while(true){
        cout << "--------------------------------------" << endl;
        cout << "que querie hacer? " << endl
             << "N --> nuevo contacto" << endl
             << "B --> buscar contacto" << endl
             << "M --> muestra la libreta entera" << endl
             << "D --> borra un contacto" << endl
             << "Q --> finaliza el programa" << endl;
        cin >> eleccion;
        cout << "--------------------------------------" << endl;

        if (eleccion == 'n' || eleccion == 'N'){
            NewCont(contacto);
        }else if (eleccion == 'b' || eleccion == 'B'){
            SearchCont(contacto);
        }else if (eleccion == 'm' || eleccion == 'M'){
            PrintCont(contacto);
        }else if (eleccion == 'd' || eleccion == 'D'){
            DeleteCont(contacto);
        }else if (eleccion == 'q' || eleccion == 'Q'){
            cout << " hasta la proxima!!" << endl;
            break;
        }

    }
    return 0;
}
