#include <stdio.h>
#include <omp.h>

#define N 10
#define M 4

void generarSerie(int vector[], int n, int inicio) {
    for (int i = 0; i < n; i++) {
        vector[i] = (inicio + i) * 2;
    }
}

int main() {
    int serie[M][N];

    #pragma omp parallel for
    for (int i = 0; i < M; i++) {
        generarSerie(serie[i], N, i * N);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", serie[i][j]);
        }
        printf("\n");
    }

    return 0;
}
