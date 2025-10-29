#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int sizes[] = {100, 500, 1000, 3000, 5000, 6000, 7000, 8000};
    int num_size = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    for (int i = 0; i < num_size; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        int *temp = (int*)malloc(n * sizeof(int));
        if (arr == NULL || temp == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        clock_t start = clock();
        for (int t = 0; t < 1000; t++) {
            for (int j = 0; j < n; j++) temp[j] = arr[j];

            quick_sort(temp, 0, n - 1);
        }
        clock_t end = clock();

        double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC ;
        printf("Array size: %d, Avg Time taken: %f seconds\n", n, cpu_time_used);

        free(arr);
        free(temp);
    }

    return 0;
}
