import multiprocessing as mp

def calcular_pi(parte):
    num_steps, inicio, cantidad = parte
    step = 1.0 / num_steps
    sum = 0.0
    for i in range(inicio, num_steps, cantidad):
        x = (i + 0.5) * step
        sum += 4.0 / (1.0 + x * x)
    return sum

if __name__ == '__main__':
    num_steps = 1000000
    step = 1.0 / num_steps
    pool = mp.Pool(mp.cpu_count())
    partes = [(num_steps, i, mp.cpu_count()) for i in range(mp.cpu_count())]
    resultados = pool.map(calcular_pi, partes)
    pi = step * sum(resultados)
    print(f"PI = {pi:.16f}")
