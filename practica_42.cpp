/*
Tenemos un cliente que quiere realizar un simulador de partidos de fútbol. El usuario debe ingresar 2 equipos de 5 jugadores cada uno. Cada jugador tiene un nombre y una cantidad de puntos de calidad. Una vez cargados ambos equipos, el sistema muestra por pantalla el resultado del mismo. 

¿Cómo calcula el resultado? Bajo diferentes criterios.

- El equipo que suma más calidad en sus jugadores suma 2 goles.
- El equipo que tiene al mejor jugador suma 1 gol
- El equipo que tiene al peor jugador resta 1 gol (solo si tiene goles a favor)
- Comparando jugador por jugador según su nivel, se suma un gol por cada jugador mejor. Es decir, se compara al mejor de un equipo contra el mejor del otro y suma gol el de mayor calidad. Luego, se hace lo mismo con el segundo de cada equipo y suma gol el de mayor calidad. Luego, se hace lo mismo con el tercero, cuarto y quinto.
*/


/*
    Que cosas intuimos
    - Struct Jugador
        - Calidad
        - Nombre
    - Array equipo
        - Debe estar ordeando por calidad
*/
#include <iostream>
#include <string>
using namespace std;

struct Jugador {
    string nombre;
    int calidad;
};

struct Resultado {
    string ganador;
    int cant_goles1;
    string perdedor;
    int cant_goles2;
};

void pedirleAlUsuarioQueCargueEquipo(Jugador[],int);
void cargarEquipoFake(Jugador[],int,int);
int calcularGolesEquipo(Jugador[], Jugador[], int);
void mostrarResultados(int, int);
void mostrarEquipo(Jugador[],int);
void guardarResultado(int, int);
int buscarEstudiante() {
    
    //abre el archivo de practica_41_1
    FILE* archivo = fopen("resultados.dat", "rb");
    
    if (archivo != NULL) {
    
        Resultado estudiante;
        
        while (fread(&estudiante, sizeof(Resultado), 1, archivo) == 1) {
            cout << estudiante.ganador << endl;
            cout << estudiante.cant_goles1 << endl;
            cout << estudiante.perdedor << endl;
            cout << estudiante.cant_goles2 << endl;
            
        }
        //cierra el archivo
        fclose(archivo);
    
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
    return 0;
}


int main() {
    /*
        1. Declarar los arrays de cada equipo
            equipo1 y equipo2
        2. El usuario ingresa los jugadores de cada equipo
        3. Calcula los puntos de cada equipo
        4. Muestra resultados
    */

    const int CANTIDAD_JUGADORES = 5;
    Jugador equipo1[CANTIDAD_JUGADORES];
    Jugador equipo2[CANTIDAD_JUGADORES];
    
    //pedirleAlUsuarioQueCargueEquipo(equipo1,CANTIDAD_JUGADORES); //Asegurarse que salga ordenado
    //pedirleAlUsuarioQueCargueEquipo(equipo2,CANTIDAD_JUGADORES);

    cargarEquipoFake(equipo1, CANTIDAD_JUGADORES, 1);
    cargarEquipoFake(equipo2, CANTIDAD_JUGADORES, 2);

    // mostrarEquipo(equipo1, CANTIDAD_JUGADORES);
    // mostrarEquipo(equipo2, CANTIDAD_JUGADORES);
    
    int golesEquipo1 = calcularGolesEquipo(equipo1, equipo2, CANTIDAD_JUGADORES);
    int golesEquipo2 = calcularGolesEquipo(equipo2, equipo1, CANTIDAD_JUGADORES);

    mostrarResultados(golesEquipo1, golesEquipo2);
    guardarResultado(golesEquipo1, golesEquipo2);
    buscarEstudiante();

    return 1;
}

void guardarResultado(int golesEquipo1, int golesEquipo2){
    Resultado resultado[1];

    FILE* archivo = fopen("resultados.dat", "at");
    
    if (golesEquipo1 > golesEquipo2){
        resultado[0].ganador = "Equipo 1";
        resultado[0].cant_goles1 = golesEquipo1;
        resultado[0].perdedor = "Equipo 2";
        resultado[0].cant_goles2 = golesEquipo2;
    } else if (golesEquipo1 < golesEquipo2){
        resultado[0].ganador = "Equipo 2";
        resultado[0].cant_goles1 = golesEquipo2;
        resultado[0].perdedor = "Equipo 1";
        resultado[0].cant_goles2 = golesEquipo1;
    } else if (golesEquipo1 == golesEquipo2){
        resultado[0].ganador = "Equipo 1 y Equipo 2";
        resultado[0].cant_goles1 = golesEquipo1;
        resultado[0].perdedor = "ninguno";
        resultado[0].cant_goles2 = golesEquipo2;
    }

    fwrite(resultado,sizeof(Resultado), 1, archivo);
    fclose(archivo);
}

void mostrarResultados(int golesEquipo1, int golesEquipo2) {
    cout << "Goles equipo 1: " << golesEquipo1 << endl;
    cout << "Goles equipo 2: " << golesEquipo2 << endl;
}

Jugador crearJugadorFake(string nombre,int calidad) {
    Jugador nuevoJugador;
    nuevoJugador.nombre = nombre;
    nuevoJugador.calidad = calidad;
    return nuevoJugador;
}

void cargarEquipoFake(Jugador equipo[],int cantidad,int tipo) {
    // 2 1 1 1 0 1 0 = 6 - 1 = 5
    if (tipo == 1) {
        equipo[0] = crearJugadorFake("Pepe",999);
        equipo[1] = crearJugadorFake("Fede",50);
        equipo[2] = crearJugadorFake("Eli",40);
        equipo[3] = crearJugadorFake("Tobi",5);
        equipo[4] = crearJugadorFake("Peor",2); 
    } 

    // 0 0 0 0 1 0 1 = 2
    if (tipo == 2) {
        equipo[0] = crearJugadorFake("Pepo",99);
        equipo[1] = crearJugadorFake("Feda",49);
        equipo[2] = crearJugadorFake("Elo",41);
        equipo[3] = crearJugadorFake("Tobe",4);
        equipo[4] = crearJugadorFake("Menos peor",3);
    }
}


void mostrarEquipo(Jugador equipo[], int cantidad) {

    cout << "El equipo esta formado por los siguientes jugadores: " << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "Nombre: " << equipo[i].nombre << " Calidad: " << equipo[i].calidad << endl;
    }

}

void insertarJugadorOrdenado(Jugador arr[], int size, Jugador element) {
    int i = size - 1;

    // Desplazar elementos mayores hacia la derecha
    while (i >= 0 && arr[i].calidad < element.calidad) {
        arr[i + 1] = arr[i];
        i--;
    }

    // Insertar el elemento en su posición correcta
    arr[i + 1] = element;
}

Jugador pedirleAlUsuarioQueMeDeUnJugador() {
    Jugador jugador;
    
    cout << "Ingrese el nombre del jugador (solo uno)" << endl;
    cin >> jugador.nombre;

    cout << "Ingrese la calidad del jugador" << endl;
    cin >> jugador.calidad;
    
    return jugador;
}

void pedirleAlUsuarioQueCargueEquipo(Jugador equipo[], int cantidad) {
    /*
        Pedirle 5 veces con un for que ingrese un jugador.
            Insertar ordenado al jugador en el array.
    */

   for (int i = 0; i < cantidad; i++) {
        Jugador jugador = pedirleAlUsuarioQueMeDeUnJugador();
        insertarJugadorOrdenado(equipo,i,jugador);
   }
}


int dameGolesMasCalidad(Jugador equipoACalcular[],Jugador equipoVersus[],int cantidadJugadores) {
    int calidadEquipoACalcular = 0;
    int calidadEquipoVersus = 0;
    int goles = 0;

    for (int i = 0; i < cantidadJugadores; i++) {
        calidadEquipoACalcular = calidadEquipoACalcular + equipoACalcular[i].calidad;
        calidadEquipoVersus = calidadEquipoVersus + equipoVersus[i].calidad;
    }

    if (calidadEquipoACalcular > calidadEquipoVersus)
        goles = 2;
    
    return goles;
}

int dameGolesMejorJugador(Jugador equipoACalcular[],Jugador equipoVersus[]) {
    int goles = 0;
    
    if (equipoACalcular[0].calidad > equipoVersus[0].calidad)
        goles = 1;
    
    return goles;
}

int dameGolesComparacionJugadores(Jugador equipoACalcular[],Jugador equipoVersus[],int cantidadJugadores) {
    int goles = 0;

    for (int i = 0; i < cantidadJugadores; i++) {
        if (equipoACalcular[i].calidad > equipoVersus[i].calidad)
            goles++;
    }

    return goles;
}

int golesPeorJugador(Jugador equipoACalcular[],Jugador equipoVersus[],int cantidadJugadores) {
    int goles = 0;

    if (equipoACalcular[cantidadJugadores - 1].calidad < equipoVersus[cantidadJugadores - 1].calidad)
        goles = 1;

    return goles;
}

int calcularGolesEquipo(Jugador equipoACalcular[], Jugador equipoVersus[], int cantidadJugadores) {
    int golesMasCalidad = dameGolesMasCalidad(equipoACalcular,equipoVersus, cantidadJugadores);
    int golesMejorJugador = dameGolesMejorJugador(equipoACalcular,equipoVersus);
    int golesPorComparacionJugadores = dameGolesComparacionJugadores(equipoACalcular,equipoVersus,cantidadJugadores);
    int goles = golesMasCalidad + golesMejorJugador + golesPorComparacionJugadores;

    
    if (goles > 0)
        goles = goles - golesPeorJugador(equipoACalcular,equipoVersus,cantidadJugadores);
    

   return goles;
}