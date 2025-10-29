#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int linear_search(int arr[], int n, int key){
    for (int i = 0; i < n; i++) {
        if (arr[i] == key){
            return i;   
        }
    }
    return -1;   
}

int main() {

    int sizes[]={1000,5000,10000,50000,100000,200000};
    int num_size = sizeof(sizes)/sizeof(sizes[0]);
    
    int key;
    printf("Enter element to be found: ");
    scanf("%d", &key);

    srand(time(NULL));

    for (int i = 0;i<num_size;i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
        }

        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        clock_t start =  clock(); 
        for (int i = 0; i < 1000; i++){
            linear_search(arr,n,key);
        }
        clock_t end = clock();

        double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC/1000;
        printf("%d %f\n", n, cpu_time_used);
        free(arr);
    }
    return 0;
}

