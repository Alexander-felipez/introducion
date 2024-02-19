#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definición de las estructuras
struct Libro {
	string title;
	string author;
	string ISBN;
	int publicationYear;
};

struct Usuario {
	int userID;
	string name;
	string lastname;
	string email;
};

struct Bibliotecario {
	int employeeID;
	string name;
	string lastname;
	string email;
};

// Función para generar datos aleatorios para los libros
void generarDatosLibros(Libro &libro, const string *listaLibros, int numLibros) {
	libro.title = listaLibros[rand() % numLibros];
	libro.author = "Autor" + to_string(rand() % 100);
	libro.ISBN = to_string(rand() % 100000);
	libro.publicationYear = rand() % 30 + 1990;
}

// Función para generar datos aleatorios para usuarios
void generarDatosUsuarios(Usuario &usuario, const string *nombre, const string *apellido) {
	usuario.name = *nombre;
	usuario.lastname = *apellido;
	usuario.email = usuario.name + usuario.lastname + "@example.com";
	usuario.userID = rand() % 1000;
}

// Función para generar datos aleatorios para bibliotecarios
void generarDatosBibliotecarios(Bibliotecario &bibliotecario, const string *nombre, const string *apellido) {
	bibliotecario.name = *nombre;
	bibliotecario.lastname = *apellido;
	bibliotecario.email = bibliotecario.name + bibliotecario.lastname + "@library.com";
	bibliotecario.employeeID = rand() % 100;
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
		generarDatosLibros(libros[i], listaLibros, numLibros);
		generarDatosUsuarios(usuarios[i], &listaNombres[i % 3], &listaApellidos[i % 3]);
		generarDatosBibliotecarios(bibliotecarios[i], &listaNombres[i % 3], &listaApellidos[i % 3]);
	}
	
	// Imprimir los datos generados
	cout << "Datos de libros:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Libro " << i+1 << ":" << endl;
		cout << "Título: " << libros[i].title << endl;
		cout << "Autor: " << libros[i].author << endl;
		cout << "ISBN: " << libros[i].ISBN << endl;
		cout << "Año de publicación: " << libros[i].publicationYear << endl;
		cout << endl;
	}
	
	cout << "Datos de usuarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Usuario " << i+1 << ":" << endl;
		cout << "Nombre: " << usuarios[i].name << endl;
		cout << "Apellido: " << usuarios[i].lastname << endl;
		cout << "Email: " << usuarios[i].email << endl;
		cout << "ID de usuario: " << usuarios[i].userID << endl;
		cout << endl;
	}
	
	cout << "Datos de bibliotecarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Bibliotecario " << i+1 << ":" << endl;
		cout << "Nombre: " << bibliotecarios[i].name << endl;
		cout << "Apellido: " << bibliotecarios[i].lastname << endl;
		cout << "Email: " << bibliotecarios[i].email << endl;
		cout << "ID de empleado: " << bibliotecarios[i].employeeID << endl;
		cout << endl;
	}
	
	return 0;
}
