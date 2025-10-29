#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Iterative_approach(int n, int A[n][n], int B[n][n], int result[n][n]) {

    for (int i = 0; i < n; i++) {
        for (int j=0;j<n;j++){
            result[i][j] = 0;   //Result matrix ko zero se initialize
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    srand(time(0));  // seed for random numbers

    int sizes[] = {2, 4, 8, 16, 32};  
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i=0; i<num_sizes;i++) {
        int n = sizes[i];

        int matrix1[n][n], matrix2[n][n], result[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix1[i][j] = rand() % 10; //0-9
                matrix2[i][j] = rand() % 10;
            }
        }

        clock_t start = clock();
        for (int i= 0; i< 1000;i++){
            Iterative_approach(n, matrix1, matrix2, result);
        }
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Matrix size %dx%d => Execution time: %.6f seconds\n", n, n, time_taken);
    }

    return 0;
}
