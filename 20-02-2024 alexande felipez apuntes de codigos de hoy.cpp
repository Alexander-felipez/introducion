#include <iostream>     // Biblioteca est�ndar de entrada y salida
#include <iomanip>      // Biblioteca para manipulaci�n de formato de salida
#include <cstdlib>      // Biblioteca para funciones de utilidad general
#include <ctime>        // Biblioteca para manejo de tiempo
#include <vector>       // Biblioteca para el contenedor vector
#include <algorithm>    // Biblioteca para algoritmos generales
using namespace std;

const int TAMJ = 5;                // Constante para el tama�o de la lista de juegos por persona max-5
const int MNOMBRE = 2;             // Constante para el n�mero de nombres disponibles max-10 
const int MJUEGOS = 10;            // Constante para el n�mero total de juegos disponibles

struct vjuego {                     // Estructura para representar un juego
	string nombre;                  // Nombre del juego
	int ranking;                    // Calificaci�n del juego
	bool tipo;                      // Tipo de juego (Online u Offline)
	string dev;                     // Desarrollador del juego
	string des;                     // Descripci�n del juego
};

struct persona {                    // Estructura para representar una persona
	string nombre;                  // Nombre de la persona
	int id_persona;                 // ID de la persona
	vjuego juegos[TAMJ];            // Lista de juegos de la persona
};

string nombres[] = {"Juan Perez", "Maria Flor", "Alex Jimenez", "Angel Flores", "Luis Ramirez"};   // Lista de nombres disponibles
string vjuegos[] = {"WoW", "Age of Empire", "DOTA", "FIFA", "Eldeng ring", "Fortnite", "Minecraft", "Among Us", "Mario Kart", "splatoon"}; // Lista de juegos disponibles

int randomico(int max) {            // Funci�n para generar un n�mero aleatorio entre 0 y max-1
	return rand() % max;
}

void llenar_personas(persona p[], int cant) {   // Funci�n para llenar los datos de las personas
	vector<string> nombres_disponibles(nombres, nombres + MNOMBRE); // Crear un vector de nombres disponibles a partir del arreglo nombres
	//solo array sin vectores 
	random_shuffle(nombres_disponibles.begin(), nombres_disponibles.end()); // Mezclar aleatoriamente los nombres disponibles
	
	for (int i = 0; i < cant; ++i) {    // Iterar sobre la cantidad de personas a llenar
		p[i].nombre = nombres_disponibles[i];  // Asignar un nombre al azar a la persona
		p[i].id_persona = i + 1;                // Asignar un ID �nico a la persona
	}
}

void llenar_juegos(vjuego j[], int cant) {     // Funci�n para llenar los datos de los juegos
	for (int i = 0; i < cant; ++i) {           // Iterar sobre la cantidad de juegos a llenar
		j[i].nombre = vjuegos[randomico(MJUEGOS)];   // Asignar un nombre de juego al azar
		j[i].ranking = randomico(10) + 1;             // Asignar una calificaci�n aleatoria al juego (del 1 al 10)
		j[i].tipo = randomico(2) == 0 ? true : false; // Asignar aleatoriamente el tipo de juego (Online u Offline)
		j[i].des = "Descripci�n del juego";            // Asignar una descripci�n ficticia al juego
		
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

void llenar(persona p[], vjuego j[], int cant) {  // Funci�n para llenar tanto los datos de las personas como los de los juegos
	llenar_personas(p, cant);   // Llenar los datos de las personas
	llenar_juegos(j, cant * TAMJ);  // Llenar los datos de los juegos
}

void imprimir(persona p[], vjuego j[], int cant) {    // Funci�n para imprimir los datos de las personas y sus juegos
	for (int i = 0; i < cant; ++i) {   // Iterar sobre la cantidad de personas
		cout << "Personas" << endl;     // Imprimir encabezado de personas
		cout << "ID\t- NOMBRE" << endl; // Imprimir encabezado de ID y NOMBRE
		cout << p[i].id_persona << "\t- " << p[i].nombre << endl;   // Imprimir ID y nombre de la persona
		cout << endl;   // Imprimir l�nea en blanco para separar
		
		cout << "JUEGOS" << endl;   // Imprimir encabezado de juegos
		cout << "NOMBRE\t\t- TIPO\t\t- DEV\t\t- RANKING" << endl;   // Imprimir encabezado de nombres, tipo, desarrollador y ranking de juegos
		for (int k = 0; k < TAMJ; ++k) {   // Iterar sobre la cantidad de juegos por persona
			cout << setw(15) << left << j[i * TAMJ + k].nombre << "\t- "   // Imprimir nombre del juego con formato
				<< setw(8) << left << (j[i * TAMJ + k].tipo ? "Online" : "Offline") << "\t- "    // Imprimir tipo de juego con formato
				<< setw(20) << left << j[i * TAMJ + k].dev << "\t- "   // Imprimir desarrollador del juego con formato
				<< j[i * TAMJ + k].ranking << endl;   // Imprimir ranking del juego
		}
		cout << endl;   // Imprimir l�nea en blanco para separar
	}
}

void valoracion(persona p[], int cant) {
	// Implementaci�n de la funci�n valoracion
	// Esta funci�n a�n no est� definida
}

void menu() {   // Funci�n que muestra el men� y maneja las opciones
	int opcion; // Variable para almacenar la opci�n seleccionada
	persona personas[MNOMBRE];  // Arreglo para almacenar los datos de las personas
	vjuego juegos[MJUEGOS * TAMJ]; // Arreglo para almacenar los datos de los juegos
	bool datos_personas_llenos = false;    // Bandera para verificar si los datos de las personas han sido llenados
	do {
		cout << "Menu:" << endl;   // Imprimir encabezado del men�
		cout << "1) Llenado de personas" << endl;   // Opci�n para llenar los datos de las personas
		cout << "2) Impresion de personas" << endl; // Opci�n para imprimir los datos de las personas
		cout << "3) Ranking de juegos por persona" << endl;    // Opci�n para mostrar el ranking de juegos por persona
		cout << "4) Salir" << endl;    // Opci�n para salir del programa
		cout << "Seleccione una opcion: "; // Solicitar al usuario que seleccione una opci�n
		cin >> opcion;  // Leer la opci�n seleccionada por el usuario
		switch (opcion) {   // Evaluar la opci�n seleccionada
		case 1: // Opci�n para llenar los datos de las personas
			cout << "Opci�n 1: Llenado de personas" << endl; // Mensaje indicando la selecci�n
			llenar(personas, juegos, MNOMBRE);    // Llenar los datos de las personas y los juegos
			datos_personas_llenos = true;   // Establecer la bandera como verdadera para indicar que los datos han sido llenados
			cout << "Datos llenados correctamente." << endl;   // Informar al usuario que los datos han sido llenados correctamente
			break;  // Salir del caso
		case 2: // Opci�n para imprimir los datos de las personas
			cout << "Opci�n 2: Impresion de personas" << endl;    // Mensaje indicando la selecci�n
			// Verificar si los datos de las personas han sido llenados antes de imprimirlos
			if (!datos_personas_llenos) {  // Si los datos de las personas no han sido llenados
				cout << "No hay datos de personas. Por favor, llene los datos primero." << endl;   // Informar al usuario que debe llenar los datos primero
			} else {    // Si los datos de las personas han sido llenados
				imprimir(personas, juegos, MNOMBRE); // Imprimir los datos de las personas y sus juegos
			}
			break;  // Salir del caso
		case 3: // Opci�n para mostrar el ranking de juegos por persona
			cout << "Opci�n 3: Ranking de juegos por persona" << endl;  // Mensaje indicando la selecci�n
			// Llamar a la funci�n para mostrar el ranking de juegos por persona
			break;  // Salir del caso
		case 4: // Opci�n para salir del programa
			cout << "Opcion 4: SALIR" << endl;   // Mensaje indicando la selecci�n
			// No es necesario hacer nada m�s aqu�, el bucle se romper� y el programa terminar�
			break;  // Salir del caso
		default:    // Opci�n inv�lida
			cout << "Opcion invalida. Por favor seleccione nuevamente." << endl;   // Mensaje indicando que la opci�n seleccionada es inv�lida
			break;  // Salir del caso
		}
	} while (opcion != 4);  // Continuar ejecutando el bucle hasta que la opci�n seleccionada sea 4 (Salir)
}

int main() {    // Funci�n principal
	srand(time(0)); // Semilla para n�meros aleatorios
	menu(); // Llamada al men� principal
	return 0;   // Salida exitosa del programa
}

