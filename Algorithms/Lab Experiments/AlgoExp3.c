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

int partition(int arr[], int low, int high, int pivot) {
    int pivotIndex;
    for (pivotIndex = low; pivotIndex <= high; pivotIndex++) {
        if (arr[pivotIndex] == pivot)
            break;
    }
    swap(&arr[pivotIndex], &arr[high]);

    int storeIndex = low;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[high]);
    return storeIndex;
}


void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int findMedian(int arr[], int low, int high) {
    insertionSort(arr, low, high);
    int n = high - low + 1;
    return arr[low + n / 2];
}


int selectPivot(int arr[], int low, int high) {
    if (high - low < 5)
        return findMedian(arr, low, high);

    int subMedians[(high - low + 5) / 5];
    int idx = 0;

    for (int i = low; i <= high; i += 5) {
        int subHigh = i + 4;
        if (subHigh > high) subHigh = high;
        subMedians[idx++] = findMedian(arr, i, subHigh);
    }

    return selectPivot(subMedians, 0, idx - 1);
}


int kthSmallest(int arr[], int low, int high, int k) {
    if (low == high)
        return arr[low];

    int pivot = selectPivot(arr, low, high);
    int pivotIndex = partition(arr, low, high, pivot);

    if (pivotIndex == k - 1)
        return arr[pivotIndex];
    else if (pivotIndex > k - 1)
        return kthSmallest(arr, low, pivotIndex - 1, k);
    else
        return kthSmallest(arr, pivotIndex + 1, high, k);
}


int main(){
    srand(time(NULL));
    clock_t start_time, end_time;
    int arr[1000000];
    int n = 1000000;
    double timings[5];
    double timings2[5];
    int r = rand() % (-1000 - 100);
    for(int i=1;i<n+1;i++){
        arr[i-1] = i;
    }
    randomising(arr,n);
    printf("Array is randomised------\n");
    printf("\nSize of array is: - %d \n", sizeof(arr)/sizeof(arr[0]));


    printf("Finding the kth smallest element------\n");
    int k1, k2, k3, k4, k5, k6;

    //k1(1-100)
    k1 = rand() % (1+99);    
    printf("k1 is - %d , ans = ", k1);
    start_time = clock();
    int ans = kthSmallest(arr, 0, n-1, k1);
    printf("%d \n", ans);
    end_time = clock();
    double cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[0] = cpu_time;


    //k2(100-1000)
    k2 = rand() % (100+999);
    printf("k2 is - %d , ans = ", k2);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k2);
    printf("%d \n", ans);
    end_time = clock();
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[1] = cpu_time;


    //k3(1000-10000)
    k3 = rand() % (1000+9999);
    printf("k3 is - %d , ans = ", k3);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k3);
    printf("%d \n", ans);
    end_time = clock();
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[2] = cpu_time;


    //k4(10000-100000)
    k4 = rand() % (10000+99999);
    printf("k4 is - %d , ans = ", k4);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k4);
    printf("%d \n", ans);
    end_time = clock();
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[3] = cpu_time;


    //k5(100000-1000000)
    k5 = rand() % (100000+1000000);
    printf("k5 is - %d , ans = ", k5);   
    if(k5 > n){
        k5 = rand() % (100000+900000);
    }
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k5);
    printf("%d \n", ans);
    end_time = clock();
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings[4] = cpu_time;

    for(int i=0;i<5;i++){
        printf("\nTimings are %f\n", timings[i]);
    }



    printf("\nFinding kth largest element-----\n");
    k1 = rand() % (1+99);    
    printf("k1 is - %d , ans = ", k1);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k1);
    end_time = clock();
    printf("%d \n", n-ans+1);
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings2[0] = cpu_time;


    //k2(100-1000)
    k2 = rand() % (100+999);
    printf("k2 is - %d , ans = ", k2);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k2);
    end_time = clock();
    printf("%d \n", n-ans+1);
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings2[1] = cpu_time;


    //k3(1000-10000)
    k3 = rand() % (1000+9999);
    printf("k3 is - %d , ans = ", k3);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k3);
    end_time = clock();
    printf("%d \n", n-ans+1);
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings2[2] = cpu_time;


    //k4(10000-100000)
    k4 = rand() % (10000+99999);
    printf("k4 is - %d , ans = ", k4);
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k4);
    end_time = clock();
    printf("%d \n", n-ans+1);
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings2[3] = cpu_time;


    //k5(100000-1000000)
    k5 = rand() % (100000+1000000);
    printf("k5 is - %d , ans = ", k5);   
    if(k5 > n){
        k5 = rand() % (100000+900000);
    }
    start_time = clock();
    ans = kthSmallest(arr, 0, n-1, k5);
    end_time = clock();
    printf("%d \n", n-ans+1);
    cpu_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    timings2[4] = cpu_time;

    for(int i=0;i<5;i++){
        printf("\nTimings are %f\n", timings2[i]);
    }


    return 0;
}