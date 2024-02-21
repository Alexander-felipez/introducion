#include <iostream>    // Inclusi�n de la biblioteca est�ndar para entrada y salida
#include <cstdlib>     // Inclusi�n de la biblioteca est�ndar para funciones generales
#include <ctime>       // Inclusi�n de la biblioteca est�ndar para manipulaci�n de tiempo

using namespace std;

// Definici�n de las estructuras

// Definici�n de la estructura para representar un libro
struct Libro {
	string title;             // T�tulo del libro
	string author;            // Autor del libro
	string ISBN;              // ISBN del libro
	int publicationYear;      // A�o de publicaci�n del libro
	string condition;         // Nuevo atributo: Condici�n del libro
	string genre;             // Nuevo atributo: G�nero del libro
	string language;          // Nuevo atributo: Idioma del libro
	string ageRecommendation; // Nuevo atributo: Recomendaci�n de edad para el libro
};

// Definici�n de la estructura para representar un usuario
struct Usuario {
	int userID;       // ID del usuario
	string name;      // Nombre del usuario
	string lastname;  // Apellido del usuario
	string email;     // Email del usuario
	string gender;    // Nuevo atributo: G�nero del usuario
};

// Definici�n de la estructura para representar un bibliotecario
struct Bibliotecario {
	int employeeID;      // ID del bibliotecario
	string name;         // Nombre del bibliotecario
	string lastname;     // Apellido del bibliotecario
	string email;        // Email del bibliotecario
	string turnoLaboral; // Nuevo atributo: Turno laboral del bibliotecario
};

// Funci�n para generar datos aleatorios para libros
void generarDatos(Libro &libro) {
	// Arrays fijos para generar datos aleatorios
	const string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	const string condiciones[] = {"Nuevo", "Usado - Buen estado", "Coleccionista", "Como nuevo", "Usado - Regular estado"};
	const string generos[] = {"Misterio", "Ciencia ficci�n", "Romance", "Realismo m�gico", "Fantas�a"};
	const string idiomas[] = {"Ingl�s", "Espa�ol", "Franc�s", "Alem�n", "Italiano"};
	const string recomendacionesEdad[] = {"12+", "18+", "Todas las edades", "16+", "8+"};
	
	// Generar datos aleatorios para el libro
	libro.title = listaLibros[rand() % 3];                             // T�tulo aleatorio del libro
	libro.author = "Autor" + to_string(rand() % 100);                  // Autor aleatorio del libro
	libro.ISBN = to_string(rand() % 5 + 1);                            // ISBN aleatorio del libro
	libro.publicationYear = rand() % 30 + 1990;                         // A�o de publicaci�n aleatorio del libro
	libro.condition = condiciones[rand() % 5];                         // Condici�n aleatoria del libro
	libro.genre = generos[rand() % 5];                                 // G�nero aleatorio del libro
	libro.language = idiomas[rand() % 5];                              // Idioma aleatorio del libro
	libro.ageRecommendation = recomendacionesEdad[rand() % 5];          // Recomendaci�n de edad aleatoria para el libro
}

// Funci�n para generar datos aleatorios para usuarios
void generarDatos(Usuario &usuario) {
	// Arrays fijos para generar datos aleatorios
	const string listaNombres[] = {"Juan", "Mar�a", "Carlos"};
	const string listaApellidos[] = {"Gonz�lez", "Mart�nez", "L�pez"};
	const string generos[] = {"Femenino", "Masculino", "No binario", "Prefiero no decirlo", "Otro"};
	
	// Generar datos aleatorios para el usuario
	usuario.name = listaNombres[rand() % 3];                            // Nombre aleatorio del usuario
	usuario.lastname = listaApellidos[rand() % 3];                      // Apellido aleatorio del usuario
	usuario.email = usuario.name + usuario.lastname + "@example.com";   // Email del usuario combinando nombre y apellido
	usuario.userID = rand() % 5 + 1;                                   // ID aleatorio del usuario
	usuario.gender = generos[rand() % 5];                               // G�nero aleatorio del usuario
}

// Funci�n para generar datos aleatorios para bibliotecarios
void generarDatos(Bibliotecario &bibliotecario) {
	// Arrays fijos para generar datos aleatorios
	const string listaNombres[] = {"alex", "ana", "roberto"};
	const string listaApellidos[] = {"vilar", "perez", "mejia"};
	const string turnos[] = {"Ma�ana", "Tarde", "Noche"};
	
	// Generar datos aleatorios para el bibliotecario
	bibliotecario.name = listaNombres[rand() % 3];                      // Nombre aleatorio del bibliotecario
	bibliotecario.lastname = listaApellidos[rand() % 3];                // Apellido aleatorio del bibliotecario
	bibliotecario.email = bibliotecario.name + bibliotecario.lastname + "@library.com"; // Email del bibliotecario combinando nombre y apellido
	bibliotecario.employeeID = rand() % 100;                            // ID aleatorio del bibliotecario
	bibliotecario.turnoLaboral = turnos[rand() % 3];                    // Turno laboral aleatorio del bibliotecario
}

int main() {
	// Semilla para generar n�meros aleatorios
	srand(time(0));
	
	// Arrays fijos de libros, nombres y apellidos
	const string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	const string listaNombres[] = {"Juan", "Mar�a", "Carlos"};
	const string listaApellidos[] = {"Gonz�lez", "Mart�nez", "L�pez"};
	
	// N�mero de elementos en cada array fijo
	int numLibros = sizeof(listaLibros) / sizeof(listaLibros[0]);
	
	// Generar estructuras de forma aleatoria
	Libro libros[3];
	Usuario usuarios[3];
	Bibliotecario bibliotecarios[3];
	
	for (int i = 0; i < 3; ++i) {
		// Generar datos aleatorios para cada estructura
		generarDatos(libros[i]);
		generarDatos(usuarios[i]);
		generarDatos(bibliotecarios[i]);
	}
	
	// Imprimir los datos generados
	cout << "Datos de libros:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Libro " << i+1 << ":" << endl;
		cout << "T�tulo: " << libros[i].title << endl;
		cout << "Autor: " << libros[i].author << endl;
		cout << "ISBN: " << libros[i].ISBN << endl;
		cout << "A�o de publicaci�n: " << libros[i].publicationYear << endl;
		cout << "Condici�n: " << libros[i].condition << endl;               // Nuevo atributo
		cout << "G�nero: " << libros[i].genre << endl;                       // Nuevo atributo
		cout << "Idioma: " << libros[i].language << endl;                   // Nuevo atributo
		cout << "Recomendaci�n de edad: " << libros[i].ageRecommendation << endl; // Nuevo atributo
		cout << endl;
	}
	
	cout << "Datos de usuarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Usuario " << i+1 << ":" << endl;
		cout << "Nombre: " << usuarios[i].name << endl;
		cout << "Apellido: " << usuarios[i].lastname << endl;
		cout << "Email: " << usuarios[i].email << endl;
		cout << "ID de usuario: " << usuarios[i].userID << endl;
		cout << "G�nero: " << usuarios[i].gender << endl;                 // Nuevo atributo
		cout << endl;
	}
	
	cout << "Datos de bibliotecarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Bibliotecario " << i+1 << ":" << endl;
		cout << "Nombre: " << bibliotecarios[i].name << endl;
		cout << "Apellido: " << bibliotecarios[i].lastname << endl;
		cout << "Email: " << bibliotecarios[i].email << endl;
		cout << "ID de empleado: " << bibliotecarios[i].employeeID << endl;
		cout << "Turno laboral: " << bibliotecarios[i].turnoLaboral << endl; // Nuevo atributo
		cout << endl;
	}
	
	return 0;
}


