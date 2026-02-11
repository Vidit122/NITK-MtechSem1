#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void randomising(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        // printf("%d ", root->data);
        inorder(root->right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // srand(time(NULL));
    clock_t start_time, end_time;
    int n = 1000000;
    int arr[1000000];
    // int temp[1000000];
    // int temp2[1000000];
    int temp3[1000000];
    double timings[6];
    // double timings2[6];
    // double timings3[6];
    double timings4[6];
    double exec_time;
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    printf("Array size: %d\n", n);
    randomising(arr, n);
    printf("Array randomized.\n");
    // for(int i=0;i<1000000;i++){
    //     temp[i] = arr[i];
    // }
    // for(int i=0;i<1000000;i++){
    //     temp2[i] = arr[i];
    // }
    for(int i=0;i<1000000;i++){
        temp3[i] = arr[i];
    }

                

    //BST
    start_time = clock();
    struct Node* root = NULL;
    root = insert(root, arr[0]);

    // 100 elements
    for(int i=1;i<100;i++){
        insert(root, arr[i]);
    }
    printf("The in order traversal is given by: \n");
    inorder(root);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[0] = exec_time;
    // printf("%f ", timings[0]);

    
    // 1000 elements
    start_time = clock();
    // struct Node* root = NULL;
    // root = insert(root, arr[0]);
    for(int i=1;i<1000;i++){
        insert(root,arr[i]);
    }
    inorder(root);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[1] = exec_time;
    // printf("%f ", timings[1]);
    

    // 10000 elements
    start_time = clock();
    for(int i=0;i<10000;i++){
        insert(root,arr[i]);
    }
    inorder(root);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[2] = exec_time;


    // 100000 elements
    start_time = clock();
    for(int i=0;i<100000;i++){
        insert(root,arr[i]);
    }
    inorder(root);   
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[3] = exec_time;


    // 200000 elements
    start_time = clock();
    for(int i=0;i<200000;i++){
        insert(root,arr[i]);
    }
    inorder(root); 
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[4] = exec_time;


    // 1000000 elements
    start_time = clock();
    for(int i=0;i<1000000;i++){
        insert(root,arr[i]);
    }
    inorder(root);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[5] = exec_time;

    for(int i=0;i<6;i++){
        printf("%f, ", timings[i]);
    }

    // printf("\n MergeSort:- \n");

    // // 100 elements
    // start_time = clock();
    // mergeSort(temp, 0, 100-1);
    // end_time = clock();
    // exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    // timings3[0] = exec_time;


    // // 1000 elements
    // start_time = clock();
    // mergeSort(temp, 0, 1000-1);
    // end_time = clock();
    // exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    // timings3[1] = exec_time;

    // // 10000 elements
    // start_time = clock();
    // mergeSort(temp, 0, 10000-1);
    // end_time = clock();
    // exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    // timings3[2] = exec_time;

    // // 100000 elements
    // start_time = clock();
    // mergeSort(temp, 0, 100000-1);
    // end_time = clock();
    // exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    // timings3[3] = exec_time;


    // // 200000 elements
    // start_time = clock();
    // mergeSort(temp, 0, 200000-1);
    // end_time = clock();
    // exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    // timings3[4] = exec_time;

    // // 1000000 elements
    // start_time = clock();
    // mergeSort(temp, 0, 1000000-1);
    // end_time = clock();
    // exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    // timings3[5] = exec_time;

    // for(int i=0;i<6;i++){
    //     printf("%f, ", timings3[i]);
    // }


    printf("\n QuickSort:- \n");

    // 100 elements
    start_time = clock();
    quickSort(temp3, 0, 100-1);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings4[0] = exec_time;


    // 1000 elements
    start_time = clock();
    quickSort(temp3, 0, 1000-1);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings4[1] = exec_time;

    // 10000 elements
    start_time = clock();
    quickSort(temp3, 0, 10000-1);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings4[2] = exec_time;

    // 100000 elements
    start_time = clock();
    quickSort(temp3, 0, 100000-1);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings4[3] = exec_time;

    // 200000 elements
    start_time = clock();
    quickSort(temp3, 0, 200000-1);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings4[4] = exec_time;

    // 1000000 elements
    start_time = clock();
    quickSort(temp3, 0, 1000000-1);
    end_time = clock();
    exec_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings4[5] = exec_time;

    for(int i=0;i<6;i++){
        printf("%f, ", timings4[i]);
    }



    FILE *fp;
    
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create data file.\n");
        return 1;
    }


    // fprintf(fp, "100 %f %f\n", timings[0]);
    // fprintf(fp, "1000 %f %f\n", timings[1]);
    // fprintf(fp, "10000 %f %f\n", timings[2]);
    // fprintf(fp, "100000 %f %f\n", timings[3]);
    // fprintf(fp, "200000 %f %f\n", timings[4]);
    // fprintf(fp, "1000000 %f %f\n", timings[5]);


    fprintf(fp, "100 %f %f\n", timings[0], timings4[0]);
    fprintf(fp, "1000 %f %f\n", timings[1], timings4[1]);
    fprintf(fp, "10000 %f %f\n", timings[2], timings4[2]);
    fprintf(fp, "100000 %f %f\n", timings[3], timings4[3]);
    fprintf(fp, "200000 %f %f\n", timings[4], timings4[4]);
    fprintf(fp, "1000000 %f %f\n", timings[5], timings4[5]);

    fclose(fp);
    printf("Plotting data with Gnuplot...\n");
    system("gnuplot -p -e \"\
    set xlabel 'Input Size'; \
    set ylabel 'Time (s)'; \
    plot 'data.txt' using 1:2 with linespoints title 'BST'lc rgb 'red',\
        'data.txt' using 1:3 with linespoints title 'Quick'lc rgb 'blue'\"");


    return 0;
}
