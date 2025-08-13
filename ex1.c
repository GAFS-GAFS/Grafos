
// Programa para construir a matriz de adjacência de um grafo não direcionado
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    // Solicita ao usuário o número de vértices
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    // Aloca dinamicamente a matriz de adjacência (n x n) e inicializa com zeros
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = calloc(n, sizeof(int));
    }

    // Lê os pares de vértices que representam as arestas
    printf("Digite as arestas (par de vértices, 0 0 para terminar):\n");
    int u, v;
    while (1) {
        scanf("%d %d", &u, &v);
        // Se o par for 0 0, termina a leitura das arestas
        if (u == 0 && v == 0) break;
        // Verifica se os vértices são válidos
        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Vértices inválidos!\n");
            continue;
        }
        // Marca a existência da aresta na matriz (grafo não direcionado)
        matriz[u-1][v-1] = 1;
        matriz[v-1][u-1] = 1;
    }

    // Exibe a matriz de adjacência
    printf("\nMatriz de adjacência:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Solicita ao usuário o par de vértices para calcular o menor caminho
    printf("\nDigite o par de vértices para calcular o menor caminho (u v): ");
    scanf("%d %d", &u, &v);
    // Verifica se os vértices são válidos
    if (u < 1 || u > n || v < 1 || v > n) {
        printf("Vértices inválidos para o cálculo do menor caminho!\n");
    } else {
        // Ajusta para índice base 0
        u--; v--;
        // Algoritmo BFS para encontrar o menor caminho entre u e v
        int *visitado = calloc(n, sizeof(int)); // Vetor de visitados
        int *dist = calloc(n, sizeof(int));     // Vetor de distâncias
        int *fila = malloc(n * sizeof(int));    // Fila para BFS
        int ini = 0, fim = 0;
        fila[fim++] = u; // Insere vértice inicial na fila
        visitado[u] = 1;
        dist[u] = 0;
        while (ini < fim) {
            int atual = fila[ini++];
            // Para cada vizinho do vértice atual
            for (int i = 0; i < n; i++) {
                // Se existe aresta e não foi visitado
                if (matriz[atual][i] && !visitado[i]) {
                    visitado[i] = 1;
                    dist[i] = dist[atual] + 1;
                    fila[fim++] = i;
                }
            }
        }
        // Exibe a menor quantidade de arestas entre os vértices informados
        printf("Menor quantidade de arestas entre %d e %d: %d\n", u+1, v+1, dist[v]);
        // Libera memória usada pelo BFS
        free(visitado);
        free(dist);
        free(fila);
    }

    // Libera memória da matriz de adjacência
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}