#include <stdio.h>

// Funciones básicas
void suma(int a, int b, int *resultado) {
    *resultado = a + b;
}

// Función de resta
void resta(int a, int b, int *resultado) {
    *resultado = a - b;
}

// Función de multiplicación
void multiplicacion(int a, int b, int *resultado) {
    *resultado = 0;
    int temp;
    for (int i = 0; i < b; i++) {
        suma(*resultado, a, &temp);
        *resultado = temp;
    }
}

// Función de división
void division(int a, int b, int *resultado) {
    *resultado = 0;
    int acumulador = a;
    int temp;
    while (acumulador >= b) {
        resta(acumulador, b, &temp);
        acumulador = temp;
        (*resultado)++;
    }
}
int main() {
    int a = 10, b = 2;
    int resultado;

    suma(a, b, &resultado);
    printf("Suma: %d\n", resultado);

    resta(a, b, &resultado);
    printf("Resta: %d\n", resultado);

    multiplicacion(a, b, &resultado);
    printf("Multiplicacion: %d\n", resultado);

    division(a, b, &resultado);
    printf("Division: %d\n", resultado);

    return 0;
}
