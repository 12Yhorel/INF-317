import multiprocessing as mp


def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def calcular_fibonacci(rango):
    inicio, fin = rango
    return [fibonacci(i) for i in range(inicio, fin + 1)]


if __name__ == '__main__':
    n = 30
    num_procesos = mp.cpu_count()
    porcion = n // num_procesos
    rangos = [(i * porcion + 1, (i + 1) * porcion) for i in range(num_procesos)]

    pool = mp.Pool(num_procesos)
    resultados = pool.map(calcular_fibonacci, rangos)

    fibonacci_total = [item for sublist in resultados for item in sublist]
    print(fibonacci_total)
