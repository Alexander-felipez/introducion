#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>  // Biblioteca para manipulación de formato


using namespace std;

// Definición de las estructuras

// Estructura para representar un libro
struct Libro {
	string strTitulo;
	string strAutor;
	string strISBN;
	int numAnioPublicacion;
	string strCondicion;
	string strGenero;
	string strIdioma;
	string strRecomendacionEdad;
};

// Estructura para representar un usuario
struct Usuario {
	int numIDUsuario;
	string strNombre;
	string strApellido;
	string strCorreoElectronico;
	string strGenero;
};

// Estructura para representar un bibliotecario
struct Bibliotecario {
	int numIDEmpleado;
	string strNombre;
	string strApellido;
	string strCorreoElectronico;
	string strTurnoLaboral;
};

// Función para generar datos aleatorios para un libro
void generarDatos(Libro &libro) {
	const string titulos[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	const string autores[] = {"Autor1", "Autor2", "Autor3"};
	const string condiciones[] = {"Nuevo", "Usado - Buen estado", "Coleccionista", "Como nuevo", "Usado - Regular estado"};
	const string generos[] = {"Misterio", "Ciencia ficción", "Romance", "Realismo mágico", "Fantasía"};
	const string idiomas[] = {"Inglés", "Español", "Francés", "Alemán", "Italiano"};
	const string recomendacionesEdad[] = {"12+", "18+", "Todas las edades", "16+", "8+"};
	
	libro.strTitulo = titulos[rand() % 3];
	libro.strAutor = autores[rand() % 3];
	libro.strISBN = to_string(rand() % 5 + 1);
	libro.numAnioPublicacion = rand() % 30 + 1990;
	libro.strCondicion = condiciones[rand() % 5];
	libro.strGenero = generos[rand() % 5];
	libro.strIdioma = idiomas[rand() % 5];
	libro.strRecomendacionEdad = recomendacionesEdad[rand() % 5];
}

// Función para generar datos aleatorios para un usuario
// Función para generar datos aleatorios para un usuario
void generarDatos(Usuario &usuario) {
	const string nombres[] = {"Juan", "Maria", "Carlos"};
	const string apellidos[] = {"Gonzalez", "Martinez", "Lopez"};
	const string genero[] = {"Masculino", "Femenino", "No binario"};
	
	usuario.strNombre = nombres[rand() % 3];
	usuario.strApellido = apellidos[rand() % 3];
	usuario.strCorreoElectronico = usuario.strNombre + usuario.strApellido + "@example.com";
	usuario.numIDUsuario = rand() % 5 + 1;
	usuario.strGenero = genero[rand() % 3]; // Se elige aleatoriamente entre Masculino, Femenino o No binario
}


// Función para generar datos aleatorios para un bibliotecario
void generarDatos(Bibliotecario &bibliotecario) {
	const string nombres[] = {"alex", "ana", "roberto"};
	const string apellidos[] = {"vilar", "perez", "mejia"};
	const string turnos[] = {"Mañana", "Tarde", "Noche"};
	
	bibliotecario.strNombre = nombres[rand() % 3];
	bibliotecario.strApellido = apellidos[rand() % 3];
	bibliotecario.strCorreoElectronico = bibliotecario.strNombre + bibliotecario.strApellido + "@library.com";
	bibliotecario.numIDEmpleado = rand() % 100;
	bibliotecario.strTurnoLaboral = turnos[rand() % 3];
}

// Sobrecargas para impresión de datos

// Función para imprimir datos de un libro
void imprimirDatos(const Libro &libro) {
	cout << "Título: " << libro.strTitulo << endl;
	cout << "Autor: " << libro.strAutor << endl;
	cout << "ISBN: " << libro.strISBN << endl;
	cout << "Año de publicación: " << libro.numAnioPublicacion << endl;
	cout << "Condición: " << libro.strCondicion << endl;
	cout << "Género: " << libro.strGenero << endl;
	cout << "Idioma: " << libro.strIdioma << endl;
	cout << "Recomendación de edad: " << libro.strRecomendacionEdad << endl;
	cout << endl;
}

// Función para imprimir datos de un usuario
void imprimirDatos(const Usuario &usuario) {
	cout << "Nombre: " << usuario.strNombre << endl;
	cout << "Apellido: " << usuario.strApellido << endl;
	cout << "Correo electrónico: " << usuario.strCorreoElectronico << endl;
	cout << "ID de usuario: " << usuario.numIDUsuario << endl;
	cout << "Género: " << usuario.strGenero << endl;
	cout << endl;
}

// Función para imprimir datos de un bibliotecario
void imprimirDatos(const Bibliotecario &bibliotecario) {
	cout << "Nombre: " << bibliotecario.strNombre << endl;
	cout << "Apellido: " << bibliotecario.strApellido << endl;
	cout << "Correo electrónico: " << bibliotecario.strCorreoElectronico << endl;
	cout << "ID de empleado: " << bibliotecario.numIDEmpleado << endl;
	cout << "Turno laboral: " << bibliotecario.strTurnoLaboral << endl;
	cout << endl;
}

// Funciones de búsqueda

// Función para buscar un libro por título
void buscarLibroPorTitulo(const Libro libros[], int size, const string &titulo, int index = 0) {
	if (index < size) {
		if (libros[index].strTitulo == titulo) {
			cout << "Libro encontrado:" << endl;
			imprimirDatos(libros[index]);
		}
		buscarLibroPorTitulo(libros, size, titulo, index + 1);
	}
}

// Función para buscar un usuario por nombre y apellido
void buscarUsuarioPorNombreApellido(const Usuario usuarios[], int size, const string &nombre, const string &apellido, int index = 0) {
	if (index < size) {
		if (usuarios[index].strNombre == nombre && usuarios[index].strApellido == apellido) {
			cout << "Usuario encontrado:" << endl;
			imprimirDatos(usuarios[index]);
		}
		buscarUsuarioPorNombreApellido(usuarios, size, nombre, apellido, index + 1);
	}
}

// Función para buscar un bibliotecario por nombre y apellido
void buscarBibliotecarioPorNombreApellido(const Bibliotecario bibliotecarios[], int size, const string &nombre, const string &apellido, int index = 0) {
	if (index < size) {
		if (bibliotecarios[index].strNombre == nombre && bibliotecarios[index].strApellido == apellido) {
			cout << "Bibliotecario encontrado:" << endl;
			imprimirDatos(bibliotecarios[index]);
		}
		buscarBibliotecarioPorNombreApellido(bibliotecarios, size, nombre, apellido, index + 1);
	}
}

// Funciones de listado

// Función para listar libros en formato de tabla
void listarLibros(const Libro libros[], int size, int index = 0) {
	if (index < size) {
		// Usar std::setw para establecer el ancho de las columnas
		cout << setw(10) << left << "Libro " << setw(30) << left << "Título" << setw(20) << left << "Autor"
			<< setw(10) << left << "ISBN" << setw(30) << left << "Año de publicación"
			<< setw(30) << left << "Condición" << setw(30) << left << "Género"
			<< setw(30) << left << "Idioma" << setw(30) << left << "Recomendación de edad" << endl;
		
		cout << setw(10) << left << index + 1 << setw(30) << left << libros[index].strTitulo
			<< setw(20) << left << libros[index].strAutor << setw(10) << left << libros[index].strISBN
			<< setw(30) << left << libros[index].numAnioPublicacion
			<< setw(30) << left << libros[index].strCondicion << setw(30) << left << libros[index].strGenero
			<< setw(30) << left << libros[index].strIdioma << setw(30) << left << libros[index].strRecomendacionEdad << endl;
		
		listarLibros(libros, size, index + 1);
	}
}

// Función para listar usuarios en formato de tabla
void listarUsuarios(const Usuario usuarios[], int size, int index = 0) {
	if (index < size) {
		// Usar std::setw para establecer el ancho de las columnas
		cout << setw(10) << left << "Usuario" << setw(20) << left << "Nombre" << setw(20) << left << "Apellido"
			<< setw(30) << left << "Correo Electrónico" << setw(20) << left << "ID de Usuario" << setw(30) << left << "Género" << endl;
		
		cout << setw(10) << left << index + 1 << setw(20) << left << usuarios[index].strNombre
			<< setw(20) << left << usuarios[index].strApellido << setw(30) << left << usuarios[index].strCorreoElectronico
			<< setw(20) << left << usuarios[index].numIDUsuario << setw(30) << left << usuarios[index].strGenero << endl;
		
		listarUsuarios(usuarios, size, index + 1);
	}
}

// Función para listar bibliotecarios en formato de tabla
void listarBibliotecarios(const Bibliotecario bibliotecarios[], int size, int index = 0) {
	if (index < size) {
		// Usar std::setw para establecer el ancho de las columnas
		cout << setw(15) << left << "Bibliotecario" << setw(20) << left << "Nombre" << setw(20) << left << "Apellido"
			<< setw(30) << left << "Correo Electrónico" << setw(20) << left << "ID de Empleado" << setw(30) << left << "Turno Laboral" << endl;
		
		cout << setw(15) << left << index + 1 << setw(20) << left << bibliotecarios[index].strNombre
			<< setw(20) << left << bibliotecarios[index].strApellido << setw(30) << left << bibliotecarios[index].strCorreoElectronico
			<< setw(20) << left << bibliotecarios[index].numIDEmpleado << setw(30) << left << bibliotecarios[index].strTurnoLaboral << endl;
		
		listarBibliotecarios(bibliotecarios, size, index + 1);
	}
}
// Función principal
int main() {
	// Inicializar la semilla para la generación de números aleatorios
	srand(time(0));
	
	// Número de libros, usuarios y bibliotecarios
	const int numLibros = 3;
	const int numUsuarios = 3;
	const int numBibliotecarios = 3;
	
	// Arreglos para almacenar libros, usuarios y bibliotecarios
	Libro libros[numLibros];
	Usuario usuarios[numUsuarios];
	Bibliotecario bibliotecarios[numBibliotecarios];
	
	// Variable para almacenar la opción del menú principal
	int opcion;
	
	// Menú principal
	do {
		// Mostrar opciones del menú principal
		cout << "Menu Principal" << endl;
		cout << "1) Llenado de datos" << endl;
		cout << "2) Listados" << endl;
		cout << "3) Búsquedas" << endl;
		cout << "0) Salir" << endl;
		cout << "Seleccione su opción: ";
		cin >> opcion;
		
		// Procesar la opción seleccionada
		switch (opcion) {
		case 1:
			// Llenado de datos aleatorios para libros, usuarios y bibliotecarios
			for (int i = 0; i < numLibros; ++i) {
				generarDatos(libros[i]);
			}
			for (int i = 0; i < numUsuarios; ++i) {
				generarDatos(usuarios[i]);
			}
			for (int i = 0; i < numBibliotecarios; ++i) {
				generarDatos(bibliotecarios[i]);
			}
			cout << "Datos llenados exitosamente." << endl;
			break;
		case 2:
			// Menú de listados
			char opcionListados;
			do {
				// Mostrar opciones del menú de listados
				cout << "Submenu Listados" << endl;
				cout << "A) Listado de Libros" << endl;
				cout << "B) Listado Usuarios" << endl;
				cout << "C) Listado Bibliotecarios" << endl;
				cout << "X) Salir" << endl;
				cout << "Seleccione su opción: ";
				cin >> opcionListados;
				
				// Procesar la opción de listados
				switch (opcionListados) {
				case 'A':
					// Listado de libros
					listarLibros(libros, numLibros);
					break;
				case 'B':
					// Listado de usuarios
					listarUsuarios(usuarios, numUsuarios);
					break;
				case 'C':
					// Listado de bibliotecarios
					listarBibliotecarios(bibliotecarios, numBibliotecarios);
					break;
				case 'X':
					break;
				default:
					// Opción no válida
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
			} while (opcionListados != 'X');
			break;
			
		case 3:
			// Menú de búsquedas
			char opcionBusquedas;
			do {
				// Mostrar opciones del menú de búsquedas
				cout << "Submenu Búsquedas" << endl;
				cout << "A) Búsqueda de Libro (Título)" << endl;
				cout << "B) Listado Búsqueda de Usuario (Nombre y Apellido)" << endl;
				cout << "C) Búsqueda de Bibliotecario (Nombre y Apellido)" << endl;
				cout << "X) Salir" << endl;
				cout << "Seleccione su opción: ";
				cin >> opcionBusquedas;
				
				// Procesar la opción de búsquedas
				switch (opcionBusquedas) {
				case 'A':
					// Búsqueda de libro por título
				{
					string titulo;
					cout << "Ingrese el título del libro a buscar: ";
					cin.ignore();
					getline(cin, titulo);
					buscarLibroPorTitulo(libros, numLibros, titulo);
				}
				break;
				case 'B':
					// Listado de búsqueda de usuario por nombre y apellido
				{
					string nombre, apellido;
					cout << "Ingrese el nombre del usuario a buscar: ";
					cin >> nombre;
					cout << "Ingrese el apellido del usuario a buscar: ";
					cin >> apellido;
					buscarUsuarioPorNombreApellido(usuarios, numUsuarios, nombre, apellido);
				}
				break;
				case 'C':
					// Búsqueda de bibliotecario por nombre y apellido
				{
					string nombre, apellido;
					cout << "Ingrese el nombre del bibliotecario a buscar: ";
					cin >> nombre;
					cout << "Ingrese el apellido del bibliotecario a buscar: ";
					cin >> apellido;
					buscarBibliotecarioPorNombreApellido(bibliotecarios, numBibliotecarios, nombre, apellido);
				}
				break;
				case 'X':
					break;
				default:
					// Opción no válida
					cout << "Opción no válida. Intente de nuevo." << endl;
				}
			} while (opcionBusquedas != 'X');
			break;
			
		case 0:
			// Salir del programa
			cout << "Saliendo del programa." << endl;
			break;
			
		default:
			// Opción no válida
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}

