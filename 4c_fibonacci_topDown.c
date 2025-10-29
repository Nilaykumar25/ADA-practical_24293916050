#include <stdio.h>
#include <time.h>

long long fib_array[100]; // Array to store fibonacci numbers

long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    if (fib_array[n] != 0) {
        return fib_array[n];
    }
    fib_array[n] = fib(n - 1) + fib(n - 2);
    return fib_array[n];
}

int main() {
    int test_cases[] = {5, 10, 15, 20, 25, 30};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\n--- Complexity Analysis (Top-Down DP with Memoization) ---");
    printf("\nTime Complexity : O(n)");
    printf("\nSpace Complexity: O(n) (array + recursion stack)\n");

    for (int t = 0; t < num_cases; t++) {
        int terms = test_cases[t];

        for (int i = 0; i < 100; i++) {
            fib_array[i] = 0;
        }

        clock_t start = clock();

        printf("\nFibonacci Series for n = %d: ", terms);
        for (int i = 0; i < terms; i++) {
            printf("%lld", fib(i));
            if (i < terms - 1) printf(", ");
        }

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nExecution Time  : %f seconds\n", time_taken);
    }

    return 0;
}
