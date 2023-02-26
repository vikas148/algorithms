#include <iostream>

using namespace std;

// Function to compute the nth Fibonacci number using memoization
int fibonacci(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    return memo[n];
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    int memo[n + 1];
    memset(memo, -1, sizeof(memo));

    int fib = fibonacci(n, memo);

    cout << "The " << n << "th Fibonacci number is: " << fib << endl;

    return 0;
}
