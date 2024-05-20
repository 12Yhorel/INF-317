#include <stdio.h>
#include <omp.h>

#define N 4

void multiplicarMatrizVector(int matriz[N][N], int vector[N], int resultado[N]) {
    int i, j;

    #pragma omp parallel for private(i, j)
    for (i = 0; i < N; i++) {
        resultado[i] = 0;
        int procesadoractivo = omp_get_thread_num();
        for (j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
            printf("procesador %d multiplicando matriz[%d][%d] * vector[%d]\n", procesadoractivo, i, j, j);
        }
    }
}

void main() {
    int matriz[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int vector[N] = {1, 2, 3, 4};
    int resultado[N] = {0};

    multiplicarMatrizVector(matriz, vector, resultado);

    printf("Resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", resultado[i]);
    }
}
