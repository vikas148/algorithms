#include <iostream>
#include <climits>

using namespace std;

const int MAX = 1000;

int graph[MAX][MAX];    // the input graph
int parent[MAX];        // stores the parent of each vertex in the MST
int key[MAX];           // stores the minimum weight edge connected to each vertex
bool mstSet[MAX];       // stores whether a vertex is in the MST or not

int V, E;   // number of vertices and edges in the input graph

// Function to find the vertex with the minimum key value
int minKey() {
    int minIndex = -1;
    int minVal = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < minVal) {
            minIndex = i;
            minVal = key[i];
        }
    }

    return minIndex;
}

// Function to print the MST
void printMST() {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST() {
    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        // Find the vertex with the minimum key value
        int u = minKey();

        // Add the selected vertex to the MST
        mstSet[u] = true;

        // Update the key and parent of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST();
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges and their weights: " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST();

    return 0;
}
