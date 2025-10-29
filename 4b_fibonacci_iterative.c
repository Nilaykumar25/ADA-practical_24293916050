#include <stdio.h>
#include <time.h>

// Iterative Fibonacci
void fib_iterative(int terms) {
    long long t1 = 0, t2 = 1, next_term;

    printf("\nFibonacci Series for n = %d: ", terms);
    for (int i = 0; i < terms; i++) {
        if (i == 0) {
            next_term = 0;
        } else if (i == 1) {
            next_term = 1;
        } else {
            next_term = t1 + t2;
            t1 = t2;
            t2 = next_term;
        }
        printf("%lld", next_term);
        if (i < terms - 1) {
            printf(", ");
        }
    }
}

int main() {
    int test_cases[] = {5, 10, 15, 20, 25, 30};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\nTime Complexity : O(n)");
    printf("\nSpace Complexity: O(1)");

    for (int t = 0; t < num_cases; t++) {
        int terms = test_cases[t];
        
        clock_t start = clock();
        fib_iterative(terms);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nExecution Time  : %f seconds\n", time_taken);
    }

    return 0;
}
