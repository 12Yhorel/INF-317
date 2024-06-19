#include <iostream>

void suma(int a, int b, int &resultado) {
    resultado = a + b;
}

void resta(int a, int b, int &resultado) {
    resultado = a - b;
}

void multiplicacion(int a, int b, int &resultado) {
    resultado = 0;
    for (int i = 0; i < b; i++) {
        suma(resultado, a, resultado); // Aquí pasamos resultado directamente, no &resultado
    }
}

void division(int a, int b, int &resultado) {
    resultado = 0;
    int acumulador = a;
    while (acumulador >= b) {
        resta(acumulador, b, acumulador); // Aquí pasamos acumulador directamente, no &acumulador
        resultado++;
    }
}

int main() {
    int a = 10, b = 2;
    int resultado;

    suma(a, b, resultado);
    std::cout << "Suma: " << resultado << std::endl;

    resta(a, b, resultado);
    std::cout << "Resta: " << resultado << std::endl;

    multiplicacion(a, b, resultado);
    std::cout << "Multiplicacion: " << resultado << std::endl;

    division(a, b, resultado);
    std::cout << "Division: " << resultado << std::endl;

    return 0;
}
