#include <iostream>
#include <iomanip>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[V][V]) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << setw(7) << "INF";
            else
                cout << setw(7) << dist[i][j];
        }
        cout << endl;
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

int main() {

    int graph[V][V] = {
        {0,   3,  INF, 5},
        {2,   0,  INF, 4},
        {INF, 1,   0,  INF},
        {INF, INF, 2,  0}
    };

    floydWarshall(graph);
    return 0;
}
