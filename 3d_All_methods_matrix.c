#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Iterative_approach(int n, int A[n][n], int B[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void Recursive_approach(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] += A[0][0] * B[0][0];
        return;
    }
    int mid = n / 2;

    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int C11[mid][mid], C12[mid][mid], C21[mid][mid], C22[mid][mid];

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++)
            C11[i][j] = C12[i][j] = C21[i][j] = C22[i][j] = 0;

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    Recursive_approach(mid, A11, B11, C11);
    Recursive_approach(mid, A12, B21, C11);
    Recursive_approach(mid, A11, B12, C12);
    Recursive_approach(mid, A12, B22, C12);
    Recursive_approach(mid, A21, B11, C21);
    Recursive_approach(mid, A22, B21, C21);
    Recursive_approach(mid, A21, B12, C22);
    Recursive_approach(mid, A22, B22, C22);

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] += A[0][0] * B[0][0];
        return;
    }
    int mid = n / 2;

    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int C11[mid][mid], C12[mid][mid], C21[mid][mid], C22[mid][mid];
    int M1[mid][mid], M2[mid][mid], M3[mid][mid], M4[mid][mid];
    int M5[mid][mid], M6[mid][mid], M7[mid][mid];
    int T1[mid][mid], T2[mid][mid];

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            C11[i][j] = C12[i][j] = C21[i][j] = C22[i][j] = 0;
            M1[i][j] = M2[i][j] = M3[i][j] = M4[i][j] = 0;
            M5[i][j] = M6[i][j] = M7[i][j] = 0;
        }

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A11[i][j] + A22[i][j];
            T2[i][j] = B11[i][j] + B22[i][j];
        }
    strassen(mid, T1, T2, M1);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A21[i][j] + A22[i][j];
            T2[i][j] = B11[i][j];
        }
    strassen(mid, T1, T2, M2);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A11[i][j];
            T2[i][j] = B12[i][j] - B22[i][j];
        }
    strassen(mid, T1, T2, M3);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A22[i][j];
            T2[i][j] = B21[i][j] - B11[i][j];
        }
    strassen(mid, T1, T2, M4);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A11[i][j] + A12[i][j];
            T2[i][j] = B22[i][j];
        }
    strassen(mid, T1, T2, M5);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A21[i][j] - A11[i][j];
            T2[i][j] = B11[i][j] + B12[i][j];
        }
    strassen(mid, T1, T2, M6);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A12[i][j] - A22[i][j];
            T2[i][j] = B21[i][j] + B22[i][j];
        }
    strassen(mid, T1, T2, M7);

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

int main() {
    srand(time(0));

    int sizes[] = {2, 4, 8, 16, 32};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int A[n][n], B[n][n], C[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }


        clock_t start = clock();
        for (int i = 0; i < 1000; i++){
            Iterative_approach(n, A, B, C);
        }
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Iterative: Matrix %dx%d => %.6f sec\n", n, n, time_taken);


        start = clock();
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    C[j][k] = 0;
            Recursive_approach(n, A, B, C);
        }
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Recursive: Matrix %dx%d => %.6f sec\n", n, n, time_taken);


        start = clock();
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    C[j][k] = 0;
            strassen(n, A, B, C);
        }
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Strassen:  Matrix %dx%d => %.6f sec\n\n", n, n, time_taken);
    }
    return 0;
}
