#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4

void imprimirVector(int *vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int procesador, cantidad;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    int matriz[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int vector[N] = {1, 2, 3, 4};
    int resultado[N] = {0};

    int porcion = N / cantidad;
    int inicio = procesador * porcion;
    int fin = (procesador == cantidad - 1) ? N : inicio + porcion;

    for (int i = inicio; i < fin; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    if (procesador != 0) {
        MPI_Send(&resultado[inicio], porcion, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        for (int i = 1; i < cantidad; i++) {
            int source_inicio = i * porcion;
            int source_fin = (i == cantidad - 1) ? N : source_inicio + porcion;
            MPI_Recv(&resultado[source_inicio], source_fin - source_inicio, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }

    if (procesador == 0) {
        printf("Resultado de la multiplicación matriz-vector:\n");
        imprimirVector(resultado, N);
    }

    MPI_Finalize();
    return 0;
}
