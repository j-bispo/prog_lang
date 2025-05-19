# Program: Linked graph usage
#Author: Joseph Alberto
# Date: May 19, 2025
# Description: Implementation of a linked graph using a dictionary.
# License: CC BY

def dijkstra(weight, s, t):
    MAXNODES = len(weight)
    INFINITY = 9999
    MEMBER = 1
    NONMEMBER = 0

    distance = [INFINITY] * MAXNODES
    perm = [NONMEMBER] * MAXNODES
    precede = [-1] * MAXNODES

    current = s
    distance[s] = 0
    perm[s] = MEMBER

    while current != t:
        smalldist = INFINITY
        dc = distance[current]

        for i in range(MAXNODES):
            if perm[i] == NONMEMBER:
                newdist = dc + weight[current][i]
                if newdist < distance[i]:
                    distance[i] = newdist
                    precede[i] = current
                if distance[i] < smalldist:
                    smalldist = distance[i]
                    k = i

        current = k
        perm[current] = MEMBER

    return distance[t], precede

def reconstruct_path(precede, s, t):
    path = []
    while t != s and t != -1:
        path.append(t)
        t = precede[t]
    if t == -1:
        return []  # Sem caminho
    path.append(s)
    return path[::-1]


def main():
    Inf = 9999  # Definindo o valor para Inf

    matriz = [
        [0, 5, 1, 2, Inf, Inf, Inf, Inf, Inf],
        [5, 0, Inf, Inf, Inf, Inf, Inf, Inf, 3],
        [1, Inf, 0, Inf, 1, Inf, Inf, Inf, Inf],
        [2, Inf, Inf, 0, Inf, 1, Inf, Inf, Inf],
        [Inf, Inf, 1, Inf, 0, Inf, Inf, 1, Inf],
        [Inf, Inf, Inf, 1, Inf, 0, 1, Inf, Inf],
        [Inf, Inf, Inf, Inf, Inf, 1, 0, 3, 2],
        [Inf, 1, Inf, Inf, Inf, 1, Inf, 0, 3],
        [Inf, 3, Inf, Inf, Inf, Inf, 2, Inf, 0]
    ]

    # Exemplo de impressão da matriz
    print("Matriz de pesos:")
    for linha in matriz:
        for elemento in linha:
            if elemento == Inf:
                print("Inf", end=" ")
            else:
                print(elemento, end=" ")
        print()

    origem = 0
    destino = 6

    dist, precede = dijkstra(matriz, origem, destino)
    caminho = reconstruct_path(precede, origem, destino)

    print("\nMenor distância de", origem,"até", destino, ":",dist)
    
    if caminho:
        print("O caminho mais curto do vértice", origem, "até o vértice", destino, "é:")
        for i, vertice in enumerate(caminho):
            if i < len(caminho) - 1:
                print(vertice, end=" -> ")
            else:
                print(vertice)
    else:
        print("Não existe caminho entre o vértice", origem, "e o vértice", destino)

if __name__ == "__main__":
    main()
