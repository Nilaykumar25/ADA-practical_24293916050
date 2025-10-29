#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *a = (int*)malloc(n1 * sizeof(int));
    int *b = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        b[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }

    while (i < n1){
        arr[k++] = a[i++];
    }
    while (j < n2){
        arr[k++] = b[j++];
    }

    free(a);
    free(b);
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int sizes[] = {100,500,1000,3000,5000,6000,7000,8000};
    int num_size = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    for (int i = 0; i < num_size; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        clock_t start =  clock(); 
        for (int i = 0; i < 1000; i++){
            mergesort(arr,0,n-1);
        }
        clock_t end = clock();

        double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Array size: %d, Time taken: %f seconds\n", n, cpu_time_used);

        free(arr);
    }

    return 0;
}
