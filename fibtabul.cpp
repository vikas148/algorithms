#include <iostream>

using namespace std;

// Function to compute the nth Fibonacci number using tabulation
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    int fib = fibonacci(n);

    cout << "The " << n << "th Fibonacci number is: " << fib << endl;

    return 0;
}
