#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[],int n,int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
    free(L);
    free(R);
}

// Merge Sort Function
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000, 100000, 200000};
    int num_size = sizeof(sizes) / sizeof(sizes[0]);

    int key;
    printf("Enter element to be found: ");
    scanf("%d", &key);

    srand(time(NULL));

    for (int i = 0; i < num_size; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Generate random elements
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000000;
        }

        merge_sort(arr, 0, n - 1);

        clock_t start = clock();
        for (int k = 0; k < 1000000; k++) {    // 1000000 bcuz of the time complexity nlogn 
            binary_search(arr, n, key);
        }
        clock_t end = clock();

        double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC / 1000;
        printf("%d %f\n", n, cpu_time_used);

        free(arr);
    }
    return 0;
}
