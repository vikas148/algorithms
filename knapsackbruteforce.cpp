#include <iostream>

using namespace std;

// Function to solve the 0/1 Knapsack problem using a brute-force algorithm
int knapsackBruteForce(int weights[], int values[], int n, int capacity) {
    int maxVal = 0;

    // Iterate over all possible combinations of items (2^n)
    for (int i = 0; i < (1 << n); i++) {
        int currentWeight = 0;
        int currentValue = 0;

        // Compute the weight and value of the current combination of items
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                currentWeight += weights[j];
                currentValue += values[j];
            }
        }

        // Update the maximum value if the current combination is valid and has a higher value
        if (currentWeight <= capacity && currentValue > maxVal) {
            maxVal = currentValue;
        }
    }

    return maxVal;
}

int main() {
    int capacity, n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], values[n];

    cout << "Enter the weight and value of each item: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsackBruteForce(weights, values, n, capacity);

    cout << "The maximum value that can be put into the knapsack is: " << maxValue << endl;

    return 0;
}
