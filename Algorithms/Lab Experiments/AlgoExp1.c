#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
    int arr = *a;
    *a = *b;
    *b = arr;
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
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d, ", arr[i]);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void insertion(int arr[], int n){
    for (int i = 1; i <n;i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void shuffling(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main(){
    clock_t start_time, end_time;
    double cpu_time_used;
    int min = 1;
    srand(time(NULL));
    int max = 1000000;
    int n = 1000000;
    int arr[1000000];
    for(int i=min;i<max;i++){
        arr[i] = i;
    }
    // for(int i=0;i<100;i++){
    //     printf("%d, ", arr[i]);
    // }
    shuffling(arr, n);
    // printf("After shuffling ----\n");
    // for(int i=0;i<100;i++){
    //     printf("%d, ", arr[i]);
    // }

    // int arr[1000000];
    // for(int i =0;i<n;i++){
    //     arr[i] = arr[i];
    // }
    int arr1[1000000];
    for(int i =0;i<n;i++){
        arr1[i]= arr[i];
    }
    // int arr2[1000000];
    // for(int i =0;i<n;i++){
    //     arr2[i]=arr[i];
    // }
    // int arr3[1000000];
    // for(int i =0;i<n;i++){
    //     arr3[i]= arr[i];
    // }
    double timings3[6];
    double timings4[6];
    double timings1[6];
    double timings2[6];
    int choice;
    int k=0;
    printf("select the choice of insertion to do: \n");
    do{
        printf("Enter 1 for insertion sort, 2 for bubble sort, 3 for merge sort, 4 for quick sort and 5 for exit: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            //100
            start_time = clock();
            insertion(arr, 100);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            timings3[0]=cpu_time_used;
            

            //1000
            start_time = clock();
            insertion(arr, 1000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings3[1]=cpu_time_used;

            //10000
            start_time = clock();
            insertion(arr, 10000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings3[2]=cpu_time_used;


            //100000
            start_time = clock();
            insertion(arr, 100000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings3[3]=cpu_time_used;

            //200000
            start_time = clock();
            insertion(arr, 200000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings3[3]=cpu_time_used;


            //1000000
            start_time = clock();
            insertion(arr, 1000000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings3[5]=cpu_time_used;


            for(int i=0;i<6;i++){
                printf("%f, ", timings3[i]);
            }
            break;   

        case 2:
            //100
            start_time = clock();
            bubble(arr,100);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            timings4[0]=cpu_time_used;
            

            //1000
            start_time = clock();
            bubble(arr,1000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings4[1]=cpu_time_used;

            //10000
            start_time = clock();
            bubble(arr,10000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings4[2]=cpu_time_used;


            //100000
            start_time = clock();
            bubble(arr,100000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings4[3]=cpu_time_used;

            //200000
            start_time = clock();
            bubble(arr,200000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings4[4]=cpu_time_used;


            //1000000
            start_time = clock();
            bubble(arr,1000000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings4[5]=cpu_time_used;


            for(int i=0;i<6;i++){
                printf("%f, ", timings4[i]);
            }
            break;   

        case 3:
            //100
            start_time = clock();
            mergeSort(arr,0,100);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            timings1[0]=cpu_time_used;
            

            //1000
            start_time = clock();
            mergeSort(arr,0,1000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings1[1]=cpu_time_used;

            //10000
            start_time = clock();
            mergeSort(arr,0,10000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings1[2]=cpu_time_used;


            //100000
            start_time = clock();
            mergeSort(arr,0,100000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings1[3]=cpu_time_used;

            //200000
            start_time = clock();
            mergeSort(arr,0,200000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings1[4]=cpu_time_used;


            //1000000
            start_time = clock();
            mergeSort(arr,0,1000000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings1[5]=cpu_time_used;


            for(int i=0;i<6;i++){
                printf("%f, ", timings1[i]);
            }
            break;   


        case 4:
            //100
            start_time = clock();
            quickSort(arr1,0,100);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            timings2[0]=cpu_time_used;
            

            //1000
            start_time = clock();
            quickSort(arr1,0,1000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings2[1]=cpu_time_used;

            //10000
            start_time = clock();
            quickSort(arr1,0,10000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings2[2]=cpu_time_used;


            //100000
            start_time = clock();
            quickSort(arr1,0,100000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings2[3]=cpu_time_used;

            //200000
            start_time = clock();
            quickSort(arr1,0,200000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings2[4]=cpu_time_used;


            //1000000
            start_time = clock();
            quickSort(arr1,0,1000000);
            end_time = clock();
            cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            // printf("%f ", cpu_time_used);
            timings2[5]=cpu_time_used;


            for(int i=0;i<6;i++){
                printf("%f, ", timings2[i]);
            }
            break;   
        
        default:
            break;
        }
    }while(choice!=5);

    FILE *fp;
    
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create data file.\n");
        return 1;
    }


    fprintf(fp, "100 %f %f\n", timings1[0], timings2[0]);
    fprintf(fp, "1000 %f %f\n", timings1[1], timings2[1]);
    fprintf(fp, "10000 %f %f\n", timings1[2], timings2[2]);
    fprintf(fp, "100000 %f %f\n", timings1[3], timings2[3]);
    fprintf(fp, "200000 %f %f\n", timings1[4], timings2[4]);
    fprintf(fp, "1000000 %f %f\n", timings1[5], timings2[5]);

    fclose(fp);
    printf("Plotting data with Gnuplot...\n");
    system("gnuplot -p -e \"\
    set xlabel 'Input Size'; \
    set ylabel 'Time (s)'; \
    plot 'data.txt' using 1:2 with linespoints title 'MergeSort'lc rgb 'red',\
        'data.txt' using 1:3 with linespoints title 'QuickSort'lc rgb 'blue'\"");

    
    return 0;
}

