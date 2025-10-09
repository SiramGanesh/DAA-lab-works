#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weight, vector<bool> &visited, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void primsAlgorithm(vector<vector<int>> &graph, int n) {
    vector<int> parent(n);
    vector<int> weight(n, INT_MAX);
    vector<bool> visited(n, false);

    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minVertex = findMinVertex(weight, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++) {
            if (graph[minVertex][j] != 0 && !visited[j]) {
                if (graph[minVertex][j] < weight[j]) {
                    weight[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    cout << "Edge\tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    primsAlgorithm(graph, n);

    return 0;
}
