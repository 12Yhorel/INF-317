#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int procesador, cantidad;
    long num_steps = 1000000;
    double step, pi, sum = 0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    step = 1.0 / (double) num_steps;

    for (int i = procesador; i < num_steps; i += cantidad) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    double total_sum;
    MPI_Reduce(&sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (procesador == 0) {
        pi = step * total_sum;
        printf("PI = %.16f\n", pi);
    }

    MPI_Finalize();
    return 0;
}
