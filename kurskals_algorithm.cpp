#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to find the parent of a node (with path compression)
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

// Function to union two sets
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);

    if (parentU != parentV) {
        if (rank[parentU] < rank[parentV])
            parent[parentU] = parentV;
        else if (rank[parentU] > rank[parentV])
            parent[parentV] = parentU;
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
}

// Kruskal's Algorithm
void kruskalAlgorithm(int n, vector<Edge>& edges) {
    // Sort edges based on their weights
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n);
    vector<int> rank(n, 0);

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<Edge> mst; // To store MST edges
    int totalWeight = 0;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.weight;

        // If adding this edge doesn’t form a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            totalWeight += wt;
            mst.push_back(edge);
            unionSet(u, v, parent, rank);
        }
    }

    // Output the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";

    cout << "Total Weight of MST = " << totalWeight << endl;
}

// Driver code
int main() {
    int n = 5, e = 7;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 3, 8},
        {1, 2, 3}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };

    kruskalAlgorithm(n, edges);
    return 0;
}


