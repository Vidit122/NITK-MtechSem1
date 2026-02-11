#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500  
#define EDGE_PROB 0.05 

int *alloc_graph(size_t n) {
    int *g = calloc(n * n, sizeof(int));
    if (!g) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }
    return g;
}

void set_edge(int *g, size_t n, size_t i, size_t j) {
    g[i * n + j] = 1;
    g[j * n + i] = 1;
}

int has_edge(int *g, size_t n, size_t i, size_t j) {
    return g[i * n + j];
}

void gen_random_graph(int *g, size_t n, double p) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            double r = (double)rand() / (double)RAND_MAX;
            if (r < p) {
                set_edge(g, n, i, j);
            }
        }
    }
}

int main(void) {
    int k;
    printf("Enter desired clique size k (1..%d): ", N);
    if (scanf("%d", &k) != 1) {
        fprintf(stderr, "Invalid input for k\n");
        return EXIT_FAILURE;
    }
    if (k <= 0 || k > N) {
        fprintf(stderr, "k must be between 1 and %d\n", N);
        return EXIT_FAILURE;
    }
    srand((unsigned)time(NULL));
    clock_t t0 = clock();
    int *G = alloc_graph(N);
    gen_random_graph(G, N, EDGE_PROB);

    size_t edges = 0;
    size_t non_edges = 0;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = i + 1; j < N; ++j) {
            if (has_edge(G, N, i, j)) ++edges;
            else ++non_edges;
        }
    }

    FILE *out = fopen("pcs_instance.txt", "w");
    if (!out) {
        perror("fopen");
        free(G);
        return EXIT_FAILURE;
    }

    fprintf(out, "# CLIQUE -> PCS reduction (simple)\n");
    fprintf(out, "# Graph: n=%d, edges=%zu, non-edges=%zu\n", N, edges, non_edges);
    fprintf(out, "machines %d\n", k);
    fprintf(out, "deadline 1\n"); 
    fprintf(out, "jobs %d\n\n", N);
    fprintf(out, "# Precedence relations (one per non-edge i<j):\n");
    fprintf(out, "# Format: pred -> succ  (pred must finish before succ starts)\n");

    size_t prec_count = 0;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = i + 1; j < N; ++j) {
            if (!has_edge(G, N, i, j)) {
                fprintf(out, "%zu -> %zu\n", i, j);
                ++prec_count;
            }
        }
    }
    fclose(out);
    clock_t t1 = clock();
    double seconds = (double)(t1 - t0) / (double)CLOCKS_PER_SEC;
    printf("Generated random graph N=%d: edges=%zu, non-edges=%zu\n", N, edges, non_edges);
    printf("Wrote PCS instance with %zu precedence constraints.\n", prec_count);
    printf("Reduction generation time: %.4f seconds\n", seconds);
    free(G);
    return EXIT_SUCCESS;
}
