#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to compare items based on their value per unit weight
bool compareItems(Item item1, Item item2) {
    return (double)item1.value / item1.weight > (double)item2.value / item2.weight;
}

// Function to solve the 0/1 Knapsack problem using a greedy algorithm
int knapsackGreedy(Item items[], int n, int capacity) {
    sort(items, items + n, compareItems); // Sort the items in decreasing order of value per unit weight

    int currentWeight = 0;
    int currentValue = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            currentValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }

    return currentValue;
}

int main() {
    int capacity, n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter the weight and value of each item: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    int maxValue = knapsackGreedy(items, n, capacity);

    cout << "The maximum value that can be put into the knapsack is: " << maxValue << endl;

    return 0;
}
