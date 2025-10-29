#include <stdio.h>
#include <time.h>

// Recursive Fibonacci
long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    int test_cases[] = {5, 10, 15, 20, 25, 30};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\nTime Complexity : Exponential O(2^n)");
    printf("\nSpace Complexity: O(n) (recursion stack)");
    
    for (int t = 0; t < num_cases; t++) {
        int terms = test_cases[t];

        clock_t start = clock();

        printf("\nFibonacci Series for n = %d: ", terms);
        for (int i = 0; i < terms; i++) {
            printf("%lld", fib_recursive(i));
            if (i < terms - 1) {
                printf(", ");
            }
        }

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nExecution Time  : %f seconds\n", time_taken);
    }

    return 0;
}
