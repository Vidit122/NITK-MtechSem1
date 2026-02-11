#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VAR_COUNT 100
#define CLAUSE_COUNT 200
#define LITERALS_PER_CLAUSE 3
#define MAX_VERTICES (CLAUSE_COUNT * LITERALS_PER_CLAUSE)

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

typedef struct {
    int V;
    AdjList* array;
} Graph;

Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; i++)
        g->array[i].head = NULL;
    return g;
}

void addEdge(Graph* g, int src, int dest) {
    Node* n1 = newNode(dest);
    n1->next = g->array[src].head;
    g->array[src].head = n1;

    Node* n2 = newNode(src);
    n2->next = g->array[dest].head;
    g->array[dest].head = n2;
}

void connectClauseLiterals(Graph* g, int base) {
    addEdge(g, base, base + 1);
    addEdge(g, base + 1, base + 2);
    addEdge(g, base, base + 2);
}

void generateFormula(int formula[CLAUSE_COUNT][LITERALS_PER_CLAUSE]) {
    for (int i = 0; i < CLAUSE_COUNT; i++) {
        for (int j = 0; j < LITERALS_PER_CLAUSE; j++) {
            int var = rand() % VAR_COUNT + 1;
            int sign = rand() % 2 ? 1 : -1;
            formula[i][j] = sign * var;
        }
    }
}

int conflict(int a, int b) {
    return (abs(a) == abs(b)) && ((a * b) < 0);
}

Graph* threeCNF_to_IS(int formula[CLAUSE_COUNT][LITERALS_PER_CLAUSE]) {
    Graph* g = createGraph(MAX_VERTICES);
    for (int i = 0; i < CLAUSE_COUNT; i++) {
        connectClauseLiterals(g, i * LITERALS_PER_CLAUSE);
    }
    for (int i = 0; i < CLAUSE_COUNT; i++) {
        for (int j = i + 1; j < CLAUSE_COUNT; j++) {
            for (int a = 0; a < LITERALS_PER_CLAUSE; a++) {
                for (int b = 0; b < LITERALS_PER_CLAUSE; b++) {
                    int u = i * LITERALS_PER_CLAUSE + a;
                    int v = j * LITERALS_PER_CLAUSE + b;
                    if (conflict(formula[i][a], formula[j][b])) {
                        addEdge(g, u, v);
                    }
                }
            }
        }
    }
    return g;
}

void printGraph(Graph* g, int limit) {
    printf("\n--- Graph (first %d vertices) ---\n", limit);
    for (int i = 0; i < limit; i++) {
        printf("Vertex %d -> ", i);
        Node* temp = g->array[i].head;
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int countEdges(Graph* g) {
    int count = 0;
    for (int i = 0; i < g->V; i++) {
        Node* temp = g->array[i].head;
        while (temp) {
            count++;
            temp = temp->next;
        }
    }
    return count / 2;
}


int main() {
    srand(time(NULL));
    int formula[CLAUSE_COUNT][LITERALS_PER_CLAUSE];

    clock_t start = clock();
    generateFormula(formula);
    Graph* g = threeCNF_to_IS(formula);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printGraph(g, 10);

    printf("\nTotal Vertices: %d\n", g->V);
    printf("Total Edges: %d\n", countEdges(g));
    printf("Independent Set target size = %d\n", CLAUSE_COUNT);
    printf("Execution Time: %.4f seconds\n", time_taken);

    return 0;
}
