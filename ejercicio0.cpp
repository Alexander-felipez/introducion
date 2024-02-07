#include <iostream> // Incluimos la librería iostream para poder utilizar funciones de entrada/salida estándar

using namespace std;

int main() {
    // Declaramos tres variables para almacenar los números ingresados por el usuario
    int num1, num2, num3;

    // Solicitamos al usuario que ingrese los tres números y los almacenamos en las variables correspondientes
    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "Ingrese el tercer numero: ";
    cin >> num3;

    // Comparamos los números para encontrar el mayor
    int mayor; // Declaramos una variable para almacenar el número mayor

    if (num1 >= num2 && num1 >= num3) {
        mayor = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        mayor = num2;
    } else {
        mayor = num3;
    }

    // Mostramos el número mayor al usuario
    cout << "El numero mayor es: " << mayor << endl;

    return 0; // Indicamos que el programa finalizó correctamente
}
