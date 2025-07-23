#include <stdio.h>
#include <stdlib.h>

void addEdge(int** graph, int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
}

void printGraph(int** graph, int n) {
    printf("[\n");
    for (int i = 0; i < n; i++) {
        printf("  ");
        for (int j = 0; j < n; j++) {
            printf("%d", graph[i][j]);
            if (j < n - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("]\n");
}

int main() {
    int n = 3;
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)calloc(n, sizeof(int));
    }

    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printGraph(graph, n);
    return 0;
}