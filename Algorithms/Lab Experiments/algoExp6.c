#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

static double drand() { return (double)rand() / (double)RAND_MAX; }
static long long ceil_div_ll(long long a, long long b) { return (a + b - 1) / b; }

int main(int argc, char **argv) {
    clock_t start = clock();
    int n = 500;               
    double edge_prob = 0.01;
    int m = 0;                  
    unsigned seed = (unsigned) time(NULL);

    if (argc >= 2) n = atoi(argv[1]);
    if (argc >= 3) edge_prob = atof(argv[2]);
    if (argc >= 4) m = atoi(argv[3]); 
    if (argc >= 5) seed = (unsigned)atoi(argv[4]);

    if (n <= 0) { fprintf(stderr, "n must be positive\n"); return 1; }
    if (edge_prob < 0) edge_prob = 0.0;
    if (edge_prob > 1) edge_prob = 1.0;

    srand(seed);

    if (m <= 0) {
        m = 10 + (rand() % 41); 
    }
    int *pos2node = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) pos2node[i] = i;
    for (int i = 0; i < n; ++i) {
        int j = i + rand() % (n - i);
        int tmp = pos2node[i]; pos2node[i] = pos2node[j]; pos2node[j] = tmp;
    }
    int *node2pos = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) node2pos[pos2node[i]] = i;
    int est_edges = (int)(edge_prob * n * (n-1) / 2.0) + 10;
    int *edges_from = malloc(sizeof(int) * est_edges);
    int *edges_to   = malloc(sizeof(int) * est_edges);
    int edge_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (drand() <= edge_prob) {
                int u = pos2node[i];
                int v = pos2node[j];
                if (edge_count >= est_edges) {
                    est_edges = est_edges * 2 + 100;
                    edges_from = realloc(edges_from, sizeof(int) * est_edges);
                    edges_to   = realloc(edges_to, sizeof(int) * est_edges);
                }
                edges_from[edge_count] = u;
                edges_to[edge_count] = v;
                ++edge_count;
            }
        }
    }
    int *outdeg = calloc(n, sizeof(int));
    for (int e = 0; e < edge_count; ++e) outdeg[ edges_from[e] ]++;
    int *adj_index = malloc(sizeof(int) * (n + 1));
    adj_index[0] = 0;
    for (int i = 0; i < n; ++i) adj_index[i+1] = adj_index[i] + outdeg[i];
    int *adj = malloc(sizeof(int) * edge_count);
    int *cur = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) cur[i] = adj_index[i];
    for (int e = 0; e < edge_count; ++e) {
        int u = edges_from[e];
        int v = edges_to[e];
        adj[ cur[u]++ ] = v;
    }
    free(cur);

    int *lp = malloc(sizeof(int) * n); 
    for (int i = 0; i < n; ++i) lp[i] = 1;
    int height = 1;
    for (int idx = 0; idx < n; ++idx) {
        int u = pos2node[idx];
        int start = adj_index[u], end = adj_index[u+1];
        for (int k = start; k < end; ++k) {
            int v = adj[k];
            if (lp[v] < lp[u] + 1) {
                lp[v] = lp[u] + 1;
                if (lp[v] > height) height = lp[v];
            }
        }
    }
    long long D = ceil_div_ll((long long)n, (long long)m) + (long long)height;
    if (D <= 0) D = 1;
    FILE *f = fopen("reduction.lp", "w");
    if (!f) { perror("fopen"); return 1; }
    fprintf(f, "Minimize\n obj: 0\n\nSubject To\n");

    printf("=== PCS to 0/1-ILP reduction ===\n");
    printf("Parameters: n=%d tasks, edge_prob=%.4f, edges=%d, processors m=%d (random if not provided), height=%d\n",
           n, edge_prob, edge_count, m, height);
    printf("Deadline D = ceil(n/m) + height = %lld\n\n", D);

    printf("Precedence constraints (one per edge u->v):\n");
    int print_limit = 200; 
    for (int e = 0; e < edge_count; ++e) {
        int u = edges_from[e], v = edges_to[e];
        if (e < print_limit) {
            printf("  prec_%d_%d: ", u, v);
            printf("sum_t t*x_%d_t  - sum_t t*x_%d_t <= -1\n", u, v);
        } else if (e == print_limit) {
            printf("  ... (skipping printing further precedence constraints to console) ...\n");
        }
        fprintf(f, " prec_%d_%d: ", u, v);
        int first = 1;
        for (int t = 0; t < D; ++t) {
            if (!first) fprintf(f, " + ");
            fprintf(f, "%d x_%d_%d", t, u, t);
            first = 0;
        }
        for (int t = 0; t < D; ++t) {
            fprintf(f, " - %d x_%d_%d", t, v, t);
        }
        fprintf(f, " <= -1\n");
    }
    if (edge_count == 0) printf("  (no precedence edges)\n");
    printf("\n");

    fprintf(f, "\nBinary\n");
    printf("Binary variables: x_i_t for i=0..%d, t=0..%lld  (total %lld variables)\n",
           n-1, D-1, (long long)n * D);

    int per_line = 8;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (long long t = 0; t < D; ++t) {
            fprintf(f, " x_%d_%lld", i, t);
            cnt++;
            if (cnt % per_line == 0) fprintf(f, "\n");
        }
    }
    if (cnt % per_line != 0) fprintf(f, "\n");
    fprintf(f, "End\n");
    fclose(f);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution Time: %.4f seconds\n", time_taken);
    printf("Summary: n=%d, m=%d, height=%d, D=%lld, edges=%d\n", n, m, height, D, edge_count);
    printf("Variables: %lld ; Constraints: %d (assignment) + %lld (proc) + %d (prec) = %lld\n",
           (long long)n * D, n, D, edge_count, (long long)n + D + edge_count);
    printf("Seed used: %u\n", seed);

    free(pos2node); free(node2pos);
    free(edges_from); free(edges_to);
    free(outdeg); free(adj_index); free(adj); free(lp);

    return 0;
}
