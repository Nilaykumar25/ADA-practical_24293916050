#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > current){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
    }
}

int main() {
    int sizes[] = {100, 500, 1000, 3000, 5000, 6000, 7000, 8000};
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

        clock_t start = clock();

        for(int i=0;i<1000;i++){     //1000 repetition
            insertion_sort(arr, n);
        }
        clock_t end = clock();
        
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Array size: %d, Time: %f seconds\n", n, time_taken);
        free(arr);
    }

    return 0;
}
