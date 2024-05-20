#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

long long fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    int procesador, cantidad;
    long long valor;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    int n = 20;
    int porcion = n / (cantidad - 1);

    if (procesador == 0) {
        for (int i = 1; i < cantidad; i++) {
            int inicio = (i - 1) * porcion + 1;
            int fin = i * porcion;
            if (i == cantidad - 1) fin = n;
            MPI_Send(&inicio, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&fin, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }

        for (int i = 1; i < cantidad; i++) {
            for (int j = 0; j < porcion && i * porcion + j <= n; j++) {
                MPI_Recv(&valor, 1, MPI_LONG_LONG, i, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
                printf("Fibonacci: %lld\n", valor);
            }
        }
    } else {
        int inicio, fin;
        MPI_Recv(&inicio, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        MPI_Recv(&fin, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

        for (int i = inicio; i <= fin; i++) {
            valor = fibonacci(i);
            MPI_Send(&valor, 1, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
