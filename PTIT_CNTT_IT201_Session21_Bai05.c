#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void addEdge(Node** graph, int startNode, int endNode) {
    Node* newNode = createNode(endNode);
    newNode->next = graph[startNode];
    graph[startNode] = newNode;
}

void printGraph(Node** graph, int n) {
    printf("[\n");
    for (int i = 0; i < n; i++) {
        printf("  ");
        Node* cur = graph[i];
        if (cur == NULL) {
            printf("NULL");
        } else {
            while (cur != NULL) {
                printf("%d", cur->data);
                if (cur->next != NULL) {
                    printf("->");
                }
                cur = cur->next;
            }
            printf("->NULL");
        }
        printf(",\n");
    }
    printf("]\n");
}

int main() {
    int n = 3;
    Node* graph[3] = {NULL, NULL, NULL};

    addEdge(graph, 1, 2);
    addEdge(graph, 2, 1);
    printGraph(graph, n);

    addEdge(graph, 0, 2);
    addEdge(graph, 1, 0);
    printGraph(graph, n);
    
    return 0;
}