#include <iostream>

using namespace std;

int binarySearchRecursive(int* arr, int left, int right, int target) {
    if (left > right) {
        // Base case: target not found
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == target) {
        // Base case: target found
        return mid;
    } else if (arr[mid] > target) {
        // Recursive case: search left half
        return binarySearchRecursive(arr, left, mid - 1, target);
    } else {
        // Recursive case: search right half
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = binarySearchRecursive(arr, 0, n - 1, target);
    if (index == -1) {
        cout << "Target " << target << " not found in array" << endl;
    } else {
        cout << "Target " << target << " found at index " << index << endl;
    }

    return 0;
}
