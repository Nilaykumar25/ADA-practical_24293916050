#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C11[i][j] = C12[i][j] = C21[i][j] = C22[i][j] = 0;
            M1[i][j] = M2[i][j] = M3[i][j] = M4[i][j] = 0;
            M5[i][j] = M6[i][j] = M7[i][j] = 0;
        }
    }

    // Split matrices A and B
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

    // Strassen’s formulas
    // M1 = (A11 + A22) * (B11 + B22)
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A11[i][j] + A22[i][j];
            T2[i][j] = B11[i][j] + B22[i][j];
        }
    }
    strassen(mid, T1, T2, M1);
    // M2 = (A21 + A22) * B11
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A21[i][j] + A22[i][j];
            T2[i][j] = B11[i][j];
        }
    }
    strassen(mid, T1, T2, M2);

    // M3 = A11 * (B12 - B22)
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A11[i][j];
            T2[i][j] = B12[i][j] - B22[i][j];
        }
    }
    strassen(mid, T1, T2, M3);

    // M4 = A22 * (B21 - B11)
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A22[i][j];
            T2[i][j] = B21[i][j] - B11[i][j];
        }
    }
    strassen(mid, T1, T2, M4);

    // M5 = (A11 + A12) * B22
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A11[i][j] + A12[i][j];
            T2[i][j] = B22[i][j];
        }
    }
    strassen(mid, T1, T2, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A21[i][j] - A11[i][j];
            T2[i][j] = B11[i][j] + B12[i][j];
        }
    }
    strassen(mid, T1, T2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            T1[i][j] = A12[i][j] - A22[i][j];
            T2[i][j] = B21[i][j] + B22[i][j];
        }
    }
    strassen(mid, T1, T2, M7);

    // Combine results
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j]             = C11[i][j];
            C[i][j + mid]       = C12[i][j];
            C[i + mid][j]       = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

int main() {
    srand(time(0));

    int sizes[] = {2, 4, 8, 16, 32};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int k = 0; k < num_sizes; k++) {
        int n = sizes[k];
        int A[n][n], B[n][n], C[n][n];

        // Fill A, B with random numbers and C with 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
                C[i][j] = 0;
            }
        }

        clock_t start = clock();
        for(int i=0;i<1000;i++){
            strassen(n,A,B,C);
        }
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Strassen: Matrix size %dx%d => Execution time: %.6f seconds\n",
               n, n, time_taken);
    }

    return 0;
}
