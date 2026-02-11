// //knapsack problem take 200 values of si, take S as some value and calculate knapsack using DP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 200
#define MAX_VALUE 20

void print_separator() {
    printf("=================================================================\n");
}

int main() {
    srand(time(NULL));

    int items[MAX_ITEMS];
    printf("Generating a set of %d items with values from 1 to %d...\n", MAX_ITEMS, MAX_VALUE);
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i] = rand() % MAX_VALUE + 1;
        printf("%d ", items[i]);
    }
    printf("\n");
    print_separator();

    int target_sum = rand() % (4000 - 200 + 1) + 200;
    printf("Generating a random target sum: %d\n", target_sum);
    print_separator();

    int dp[MAX_ITEMS + 1][target_sum + 1];
    for (int i = 0; i <= MAX_ITEMS; i++) {
        dp[i][0] = 1; 
    }
    for (int j = 1; j <= target_sum; j++) {
        dp[0][j] = 0; 
    }
    for (int i = 1; i <= MAX_ITEMS; i++) {
        for (int j = 1; j <= target_sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (items[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j - items[i-1]];
            }
        }
    }

    printf("Checking if the target sum can be achieved...\n");
    if (dp[MAX_ITEMS][target_sum]) {
        printf("Result: TRUE. A subset of the numbers sums to %d.\n", target_sum);

    } else {
        printf("Result: FALSE. No subset of the numbers sums to %d.\n", target_sum);
    }

    print_separator();

    return 0;
}




