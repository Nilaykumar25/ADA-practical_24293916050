#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallest_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallest_index]) {
                smallest_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest_index];
        arr[smallest_index] = temp;
    }
}

int main(){
    int sizes[] = {100,500,1000,3000,5000,6000,7000,8000};
    int num_size = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));
    for (int s = 0; s < num_size; s++) {
        int n = sizes[s];
        int *arr = (int*)malloc(n * sizeof(int));

        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;                                   
        }
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;         
        }

        clock_t start = clock();
        for(int i=0;i<1000;i++){
            selection_sort(arr,n);
        }
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Array size: %d, Time: %f seconds\n", n, time_taken);

        free(arr);
    }
    return 0;
}
