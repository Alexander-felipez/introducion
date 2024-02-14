#include <iostream>
using namespace std;

// Función para contar vocales en una cadena dado un puntero a la cadena
int vocales(char *pc) {
	int contadorVocales = 0;
	
	// Recorremos la cadena con el puntero
	while (*pc != '\0') {
		// Verificamos si el carácter actual es una vocal
		if (*pc == 'a' || *pc == 'e' || *pc == 'i' || *pc == 'o' || *pc == 'u' ||
			*pc == 'A' || *pc == 'E' || *pc == 'I' || *pc == 'O' || *pc == 'U') {
			// Incrementamos el contador de vocales si encontramos una vocal
			contadorVocales++;
		}
		// Avanzamos el puntero al siguiente carácter en la cadena
		pc++;
	}
	
	// Devolvemos el número de vocales encontrado
	return contadorVocales;
}

int main(int argc, char *argv[]) {
	char cadena[] = "hola mundo";
	char *pc = cadena; // Declaramos el puntero 'pc' y lo inicializamos apuntando al inicio de la cadena 'cadena'
	
	// Llamamos a la función vocales y pasamos el puntero a la cadena como argumento
	int numVocales = vocales(pc);
	
	// Imprimimos el resultado devuelto por la función
	cout << "El número de vocales en la cadena es: " << numVocales << endl;
	
	return 0;
}
