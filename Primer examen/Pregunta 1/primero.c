#include <stdio.h>

// Funciones básicas
void suma(int a, int b, int *resultado) {
    *resultado = a + b;
}

void resta(int a, int b, int *resultado) {
    *resultado = a - b;
}

void multiplicacion(int a, int b, int *resultado) {
    *resultado = 0;
    for (int i = 0; i < b; i++) {
        *resultado += a;
    }
}

void division(int a, int b, int *resultado) {
    *resultado = 0;
    int acumulador = a;
    while (acumulador >= b) {
        acumulador -= b;
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
