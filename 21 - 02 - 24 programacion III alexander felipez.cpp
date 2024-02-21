#include <iostream>    // Inclusión de la biblioteca estándar para entrada y salida
#include <cstdlib>     // Inclusión de la biblioteca estándar para funciones generales
#include <ctime>       // Inclusión de la biblioteca estándar para manipulación de tiempo

using namespace std;

// Definición de las estructuras

// Definición de la estructura para representar un libro
struct Libro {
	string title;             // Título del libro
	string author;            // Autor del libro
	string ISBN;              // ISBN del libro
	int publicationYear;      // Año de publicación del libro
	string condition;         // Nuevo atributo: Condición del libro
	string genre;             // Nuevo atributo: Género del libro
	string language;          // Nuevo atributo: Idioma del libro
	string ageRecommendation; // Nuevo atributo: Recomendación de edad para el libro
};

// Definición de la estructura para representar un usuario
struct Usuario {
	int userID;       // ID del usuario
	string name;      // Nombre del usuario
	string lastname;  // Apellido del usuario
	string email;     // Email del usuario
	string gender;    // Nuevo atributo: Género del usuario
};

// Definición de la estructura para representar un bibliotecario
struct Bibliotecario {
	int employeeID;      // ID del bibliotecario
	string name;         // Nombre del bibliotecario
	string lastname;     // Apellido del bibliotecario
	string email;        // Email del bibliotecario
	string turnoLaboral; // Nuevo atributo: Turno laboral del bibliotecario
};

// Función para generar datos aleatorios para libros
void generarDatos(Libro &libro) {
	// Arrays fijos para generar datos aleatorios
	const string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	const string condiciones[] = {"Nuevo", "Usado - Buen estado", "Coleccionista", "Como nuevo", "Usado - Regular estado"};
	const string generos[] = {"Misterio", "Ciencia ficción", "Romance", "Realismo mágico", "Fantasía"};
	const string idiomas[] = {"Inglés", "Español", "Francés", "Alemán", "Italiano"};
	const string recomendacionesEdad[] = {"12+", "18+", "Todas las edades", "16+", "8+"};
	
	// Generar datos aleatorios para el libro
	libro.title = listaLibros[rand() % 3];                             // Título aleatorio del libro
	libro.author = "Autor" + to_string(rand() % 100);                  // Autor aleatorio del libro
	libro.ISBN = to_string(rand() % 5 + 1);                            // ISBN aleatorio del libro
	libro.publicationYear = rand() % 30 + 1990;                         // Año de publicación aleatorio del libro
	libro.condition = condiciones[rand() % 5];                         // Condición aleatoria del libro
	libro.genre = generos[rand() % 5];                                 // Género aleatorio del libro
	libro.language = idiomas[rand() % 5];                              // Idioma aleatorio del libro
	libro.ageRecommendation = recomendacionesEdad[rand() % 5];          // Recomendación de edad aleatoria para el libro
}

// Función para generar datos aleatorios para usuarios
void generarDatos(Usuario &usuario) {
	// Arrays fijos para generar datos aleatorios
	const string listaNombres[] = {"Juan", "María", "Carlos"};
	const string listaApellidos[] = {"González", "Martínez", "López"};
	const string generos[] = {"Femenino", "Masculino", "No binario", "Prefiero no decirlo", "Otro"};
	
	// Generar datos aleatorios para el usuario
	usuario.name = listaNombres[rand() % 3];                            // Nombre aleatorio del usuario
	usuario.lastname = listaApellidos[rand() % 3];                      // Apellido aleatorio del usuario
	usuario.email = usuario.name + usuario.lastname + "@example.com";   // Email del usuario combinando nombre y apellido
	usuario.userID = rand() % 5 + 1;                                   // ID aleatorio del usuario
	usuario.gender = generos[rand() % 5];                               // Género aleatorio del usuario
}

// Función para generar datos aleatorios para bibliotecarios
void generarDatos(Bibliotecario &bibliotecario) {
	// Arrays fijos para generar datos aleatorios
	const string listaNombres[] = {"alex", "ana", "roberto"};
	const string listaApellidos[] = {"vilar", "perez", "mejia"};
	const string turnos[] = {"Mañana", "Tarde", "Noche"};
	
	// Generar datos aleatorios para el bibliotecario
	bibliotecario.name = listaNombres[rand() % 3];                      // Nombre aleatorio del bibliotecario
	bibliotecario.lastname = listaApellidos[rand() % 3];                // Apellido aleatorio del bibliotecario
	bibliotecario.email = bibliotecario.name + bibliotecario.lastname + "@library.com"; // Email del bibliotecario combinando nombre y apellido
	bibliotecario.employeeID = rand() % 100;                            // ID aleatorio del bibliotecario
	bibliotecario.turnoLaboral = turnos[rand() % 3];                    // Turno laboral aleatorio del bibliotecario
}

int main() {
	// Semilla para generar números aleatorios
	srand(time(0));
	
	// Arrays fijos de libros, nombres y apellidos
	const string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	const string listaNombres[] = {"Juan", "María", "Carlos"};
	const string listaApellidos[] = {"González", "Martínez", "López"};
	
	// Número de elementos en cada array fijo
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
		cout << "Título: " << libros[i].title << endl;
		cout << "Autor: " << libros[i].author << endl;
		cout << "ISBN: " << libros[i].ISBN << endl;
		cout << "Año de publicación: " << libros[i].publicationYear << endl;
		cout << "Condición: " << libros[i].condition << endl;               // Nuevo atributo
		cout << "Género: " << libros[i].genre << endl;                       // Nuevo atributo
		cout << "Idioma: " << libros[i].language << endl;                   // Nuevo atributo
		cout << "Recomendación de edad: " << libros[i].ageRecommendation << endl; // Nuevo atributo
		cout << endl;
	}
	
	cout << "Datos de usuarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Usuario " << i+1 << ":" << endl;
		cout << "Nombre: " << usuarios[i].name << endl;
		cout << "Apellido: " << usuarios[i].lastname << endl;
		cout << "Email: " << usuarios[i].email << endl;
		cout << "ID de usuario: " << usuarios[i].userID << endl;
		cout << "Género: " << usuarios[i].gender << endl;                 // Nuevo atributo
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


