#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 200
#define MAX_WEIGHT 50
#define MAX_VALUE 100

void print_separator() {
    printf("=================================================================\n");
}

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    const Item *i1 = (const Item *)a;
    const Item *i2 = (const Item *)b;

    if (i2->ratio > i1->ratio) return 1;
    if (i2->ratio < i1->ratio) return -1;
    return 0;
}

int main() {
    srand(time(NULL));

    Item items[MAX_ITEMS];

    printf("Generating %d random items...\n", MAX_ITEMS);

    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].weight = rand() % MAX_WEIGHT + 1;
        items[i].value  = rand() % MAX_VALUE + 1;
        items[i].ratio  = (double)items[i].value / items[i].weight;

        printf("[W=%d V=%d R=%.2f]  ", 
               items[i].weight, items[i].value, items[i].ratio);

        if ((i + 1) % 4 == 0) printf("\n");
    }

    print_separator();

    int capacity = rand() % 801 + 200; 
    printf("Knapsack Capacity: %d\n", capacity);

    print_separator();

    printf("Sorting items by value/weight ratio...\n");
    qsort(items, MAX_ITEMS, sizeof(Item), compare);

    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("[W=%d V=%d R=%.2f]  ",
               items[i].weight, items[i].value, items[i].ratio);

        if ((i + 1) % 4 == 0) printf("\n");
    }

    print_separator();
    printf("Applying Greedy Fractional Knapsack...\n");

    double total_value = 0.0;
    int remaining = capacity;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (remaining <= 0) break;

        if (items[i].weight <= remaining) {
            remaining -= items[i].weight;
            total_value += items[i].value;
        } else {
            double fraction = (double)remaining / items[i].weight;
            total_value += items[i].value * fraction;
            remaining = 0; 
        }
    }

    print_separator();
    printf("Maximum value obtained: %.2f\n", total_value);
    printf("Unused capacity: %d\n", remaining);
    print_separator();

    return 0;
}
