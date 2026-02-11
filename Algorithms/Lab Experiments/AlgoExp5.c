// matrix chain multiplication using divide and conquer & dynamic programming 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dp[100][100];

int cost(int a[], int i, int j){
    if (i+1 == j) return 0;
    int res = __INT_MAX__;
    for (int k = i+1; k < j; k++)
    {
        int curr = cost(a, i, k) + cost(a, k, j) + (a[i] * a[k] * a[j]);

        if(curr<res){
            res = curr;
        }
    }
    return res;
}


int matrixChainMemoised(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = __INT_MAX__;
    for (int k = i; k < j; k++) {
        dp[i][j] = (dp[i][j] < (matrixChainMemoised(p, i, k)
                          + matrixChainMemoised(p, k + 1, j)
                          + p[i - 1] * p[k] * p[j])) ? dp[i][j] : (matrixChainMemoised(p, i, k)
                          + matrixChainMemoised(p, k + 1, j)
                          + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}


int main(){
    int a[100];
    int n;
    clock_t start_time, end_time;
    srand(time(NULL));
    printf("Enter number of R values u wish to enter: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 + 1;
        printf("%d ", a[i]);
    }
    
    // printf("Enter the values to enter: ");
    // for(int i=0;i<n;i++){
    //     scanf("%d", &a[i]);
    // }
    // for(int i=0;i<n;i++){
    //     printf("%d ", a[i]);
    // }
    printf("Divide & Conquer ============\n");
    start_time = clock();
    int ans = cost(a, 0, n-1);
    end_time = clock();
    printf("%d", ans);
    double cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf(" %f ", cpu_time);

    printf("\n");
    printf("Dynamic Programming ============\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    start_time = clock();
    int res = matrixChainMemoised(a, 1, n-1);
    end_time = clock();
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf(" %d ", res);
    printf(" %f ", cpu_time);
    printf("Table================\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
