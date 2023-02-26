#include <iostream>
#include <limits.h>

using namespace std;

// Function to solve the Matrix Chain Multiplication problem
int matrixChainMultiplication(int dims[], int n) {
    // Create a 2D array to store the minimum number of scalar multiplications required to multiply a chain of matrices
    int m[n][n] = {0};

    // Iterate over all possible chain lengths
    for (int chainLength = 2; chainLength < n; chainLength++) {
        // Iterate over all possible starting indices
        for (int i = 1; i < n - chainLength + 1; i++) {
            // Compute the ending index
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX;

            // Iterate over all possible partition points
            for (int k = i; k < j; k++) {
                // Compute the number of scalar multiplications required to multiply the two sub-chains
                int scalarMultiplications = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];

                // Update the minimum number of scalar multiplications seen so far
                if (scalarMultiplications < m[i][j]) {
                    m[i][j] = scalarMultiplications;
                }
            }
        }
    }

    // Return the minimum number of scalar multiplications required to multiply the entire chain of matrices
    return m[1][n - 1];
}

int main() {
    int n;

    cout << "Enter the number of matrices: ";
    cin >> n;

    int dims[n + 1];

    cout << "Enter the dimensions of the matrices: " << endl;

    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    int minScalarMultiplications = matrixChainMultiplication(dims, n + 1);

    cout << "The minimum number of scalar multiplications required is: " << minScalarMultiplications << endl;

    return 0;
}
