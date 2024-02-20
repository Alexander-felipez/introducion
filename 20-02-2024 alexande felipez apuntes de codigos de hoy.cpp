#include <iostream>     // Biblioteca estándar de entrada y salida
#include <iomanip>      // Biblioteca para manipulación de formato de salida
#include <cstdlib>      // Biblioteca para funciones de utilidad general
#include <ctime>        // Biblioteca para manejo de tiempo
#include <vector>       // Biblioteca para el contenedor vector
#include <algorithm>    // Biblioteca para algoritmos generales
using namespace std;

const int TAMJ = 5;                // Constante para el tamaño de la lista de juegos por persona max-5
const int MNOMBRE = 2;             // Constante para el número de nombres disponibles max-10 
const int MJUEGOS = 10;            // Constante para el número total de juegos disponibles

struct vjuego {                     // Estructura para representar un juego
	string nombre;                  // Nombre del juego
	int ranking;                    // Calificación del juego
	bool tipo;                      // Tipo de juego (Online u Offline)
	string dev;                     // Desarrollador del juego
	string des;                     // Descripción del juego
};

struct persona {                    // Estructura para representar una persona
	string nombre;                  // Nombre de la persona
	int id_persona;                 // ID de la persona
	vjuego juegos[TAMJ];            // Lista de juegos de la persona
};

string nombres[] = {"Juan Perez", "Maria Flor", "Alex Jimenez", "Angel Flores", "Luis Ramirez"};   // Lista de nombres disponibles
string vjuegos[] = {"WoW", "Age of Empire", "DOTA", "FIFA", "Eldeng ring", "Fortnite", "Minecraft", "Among Us", "Mario Kart", "splatoon"}; // Lista de juegos disponibles

int randomico(int max) {            // Función para generar un número aleatorio entre 0 y max-1
	return rand() % max;
}

void llenar_personas(persona p[], int cant) {   // Función para llenar los datos de las personas
	vector<string> nombres_disponibles(nombres, nombres + MNOMBRE); // Crear un vector de nombres disponibles a partir del arreglo nombres
	//solo array sin vectores 
	random_shuffle(nombres_disponibles.begin(), nombres_disponibles.end()); // Mezclar aleatoriamente los nombres disponibles
	
	for (int i = 0; i < cant; ++i) {    // Iterar sobre la cantidad de personas a llenar
		p[i].nombre = nombres_disponibles[i];  // Asignar un nombre al azar a la persona
		p[i].id_persona = i + 1;                // Asignar un ID único a la persona
	}
}

void llenar_juegos(vjuego j[], int cant) {     // Función para llenar los datos de los juegos
	for (int i = 0; i < cant; ++i) {           // Iterar sobre la cantidad de juegos a llenar
		j[i].nombre = vjuegos[randomico(MJUEGOS)];   // Asignar un nombre de juego al azar
		j[i].ranking = randomico(10) + 1;             // Asignar una calificación aleatoria al juego (del 1 al 10)
		j[i].tipo = randomico(2) == 0 ? true : false; // Asignar aleatoriamente el tipo de juego (Online u Offline)
		j[i].des = "Descripción del juego";            // Asignar una descripción ficticia al juego
		
		// Asignar el desarrollador correspondiente a cada juego
		if (j[i].nombre == "Minecraft") {
			j[i].dev = "Mojang";
		} else if (j[i].nombre == "WoW" || j[i].nombre == "DOTA" || j[i].nombre == "Age of Empire") {
			j[i].dev = "Blizzard Entertainment";
		} else if (j[i].nombre == "Mario Kart" || j[i].nombre == "splatoon") {
			j[i].dev = "Nintendo";
		} else if (j[i].nombre == "Fortnite") {
			j[i].dev = "Epic Games";
		} else if (j[i].nombre == "Eldeng ring") {
			j[i].dev = "From Software";
		} else if (j[i].nombre == "Among Us") {
			j[i].dev = "InnerSloth";
		} else if (j[i].nombre == "FIFA") {
			j[i].dev = "EA SPORTS";
		}
	}
}

void llenar(persona p[], vjuego j[], int cant) {  // Función para llenar tanto los datos de las personas como los de los juegos
	llenar_personas(p, cant);   // Llenar los datos de las personas
	llenar_juegos(j, cant * TAMJ);  // Llenar los datos de los juegos
}

void imprimir(persona p[], vjuego j[], int cant) {    // Función para imprimir los datos de las personas y sus juegos
	for (int i = 0; i < cant; ++i) {   // Iterar sobre la cantidad de personas
		cout << "Personas" << endl;     // Imprimir encabezado de personas
		cout << "ID\t- NOMBRE" << endl; // Imprimir encabezado de ID y NOMBRE
		cout << p[i].id_persona << "\t- " << p[i].nombre << endl;   // Imprimir ID y nombre de la persona
		cout << endl;   // Imprimir línea en blanco para separar
		
		cout << "JUEGOS" << endl;   // Imprimir encabezado de juegos
		cout << "NOMBRE\t\t- TIPO\t\t- DEV\t\t- RANKING" << endl;   // Imprimir encabezado de nombres, tipo, desarrollador y ranking de juegos
		for (int k = 0; k < TAMJ; ++k) {   // Iterar sobre la cantidad de juegos por persona
			cout << setw(15) << left << j[i * TAMJ + k].nombre << "\t- "   // Imprimir nombre del juego con formato
				<< setw(8) << left << (j[i * TAMJ + k].tipo ? "Online" : "Offline") << "\t- "    // Imprimir tipo de juego con formato
				<< setw(20) << left << j[i * TAMJ + k].dev << "\t- "   // Imprimir desarrollador del juego con formato
				<< j[i * TAMJ + k].ranking << endl;   // Imprimir ranking del juego
		}
		cout << endl;   // Imprimir línea en blanco para separar
	}
}

void valoracion(persona p[], int cant) {
	// Implementación de la función valoracion
	// Esta función aún no está definida
}

void menu() {   // Función que muestra el menú y maneja las opciones
	int opcion; // Variable para almacenar la opción seleccionada
	persona personas[MNOMBRE];  // Arreglo para almacenar los datos de las personas
	vjuego juegos[MJUEGOS * TAMJ]; // Arreglo para almacenar los datos de los juegos
	bool datos_personas_llenos = false;    // Bandera para verificar si los datos de las personas han sido llenados
	do {
		cout << "Menu:" << endl;   // Imprimir encabezado del menú
		cout << "1) Llenado de personas" << endl;   // Opción para llenar los datos de las personas
		cout << "2) Impresion de personas" << endl; // Opción para imprimir los datos de las personas
		cout << "3) Ranking de juegos por persona" << endl;    // Opción para mostrar el ranking de juegos por persona
		cout << "4) Salir" << endl;    // Opción para salir del programa
		cout << "Seleccione una opcion: "; // Solicitar al usuario que seleccione una opción
		cin >> opcion;  // Leer la opción seleccionada por el usuario
		switch (opcion) {   // Evaluar la opción seleccionada
		case 1: // Opción para llenar los datos de las personas
			cout << "Opción 1: Llenado de personas" << endl; // Mensaje indicando la selección
			llenar(personas, juegos, MNOMBRE);    // Llenar los datos de las personas y los juegos
			datos_personas_llenos = true;   // Establecer la bandera como verdadera para indicar que los datos han sido llenados
			cout << "Datos llenados correctamente." << endl;   // Informar al usuario que los datos han sido llenados correctamente
			break;  // Salir del caso
		case 2: // Opción para imprimir los datos de las personas
			cout << "Opción 2: Impresion de personas" << endl;    // Mensaje indicando la selección
			// Verificar si los datos de las personas han sido llenados antes de imprimirlos
			if (!datos_personas_llenos) {  // Si los datos de las personas no han sido llenados
				cout << "No hay datos de personas. Por favor, llene los datos primero." << endl;   // Informar al usuario que debe llenar los datos primero
			} else {    // Si los datos de las personas han sido llenados
				imprimir(personas, juegos, MNOMBRE); // Imprimir los datos de las personas y sus juegos
			}
			break;  // Salir del caso
		case 3: // Opción para mostrar el ranking de juegos por persona
			cout << "Opción 3: Ranking de juegos por persona" << endl;  // Mensaje indicando la selección
			// Llamar a la función para mostrar el ranking de juegos por persona
			break;  // Salir del caso
		case 4: // Opción para salir del programa
			cout << "Opcion 4: SALIR" << endl;   // Mensaje indicando la selección
			// No es necesario hacer nada más aquí, el bucle se romperá y el programa terminará
			break;  // Salir del caso
		default:    // Opción inválida
			cout << "Opcion invalida. Por favor seleccione nuevamente." << endl;   // Mensaje indicando que la opción seleccionada es inválida
			break;  // Salir del caso
		}
	} while (opcion != 4);  // Continuar ejecutando el bucle hasta que la opción seleccionada sea 4 (Salir)
}

int main() {    // Función principal
	srand(time(0)); // Semilla para números aleatorios
	menu(); // Llamada al menú principal
	return 0;   // Salida exitosa del programa
}

