#include "stdio.h"
#include "omp.h"

void multiplicacion(int a, int b, int *resultado) {
    *resultado = 0;
    #pragma omp parallel
    {
        int procesadoractivo = omp_get_thread_num();
        #pragma omp for reduction(+:*resultado)
        for (int i = 0; i < b; i++) {
            printf("procesador %d multiplicando %d\n", procesadoractivo, a);
            *resultado += a;
        }
    }
}

void division(int a, int b, int *resultado) {
    *resultado = 0;
    int acumulador = a;
    #pragma omp parallel
    {
        int procesadoractivo = omp_get_thread_num();
        #pragma omp single
        {
            while (acumulador >= b) {
                printf("procesador %d dividiendo %d\n", procesadoractivo, acumulador);
                acumulador -= b;
                (*resultado)++;
            }
        }
    }
}

void main() {
    int a = 10, b = 2;
    int resultado;

    multiplicacion(a, b, &resultado);
    printf("Multiplicacion: %d\n", resultado);

    division(a, b, &resultado);
    printf("Division: %d\n", resultado);
}
