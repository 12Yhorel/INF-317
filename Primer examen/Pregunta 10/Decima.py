import multiprocessing as mp

def generar_serie(n, inicio):
    return [(inicio + i) * 2 for i in range(n)]

if __name__ == '__main__':
    N = 10
    M = 4
    pool = mp.Pool(M)
    resultados = pool.starmap(generar_serie, [(N, i * N) for i in range(M)])
    
    for serie in resultados:
        print(serie)
