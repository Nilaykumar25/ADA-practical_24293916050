#include <stdio.h>
#include <time.h>

// Function to calculate and print Fibonacci series using Bottom-Up DP
void fib_bottomup(int terms) {
    long long dp[terms + 1];

    dp[0] = 0;
    if (terms > 1) dp[1] = 1;

    printf("Fibonacci Series for n = %d: ", terms);
    for (int i = 0; i < terms; i++) {
        if (i == 0 || i == 1)
            printf("%lld", dp[i]);
        else {
            dp[i] = dp[i - 1] + dp[i - 2];
            printf("%lld", dp[i]);
        }
        if (i < terms - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    int test_cases[] = {5, 10, 15, 20, 25, 30};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\n--- Complexity Analysis (Bottom-Up DP) ---\n");
    printf("Time Complexity : O(n)\n");
    printf("Space Complexity: O(n) (array for storing sequence)\n");

    for (int t = 0; t < num_cases; t++) {
        int terms = test_cases[t];

        clock_t start = clock();
        fib_bottomup(terms);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Execution Time  : %f seconds\n\n", time_taken);
    }

    return 0;
}
