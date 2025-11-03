#include <iostream>
#include <climits>
using namespace std;

#define V 5

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    MinHeapNode **array;
};

MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* node = new MinHeapNode;
    node->v = v;
    node->dist = dist;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = new MinHeap;
    minHeap->pos = new int[capacity];
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new MinHeapNode*[capacity];
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        // Update positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

MinHeapNode* extract_min(MinHeap* minHeap) {
    if (minHeap->size == 0)
        return nullptr;

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update positions
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void decrease_key(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void build_heap(MinHeap* minHeap, int dist[]) {
    for (int v = 0; v < V; v++) {
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
    minHeap->size = V;
}

bool isInMinHeap(MinHeap *minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
    }

    dist[src] = 0;
    build_heap(minHeap, dist);

    decrease_key(minHeap, src, dist[src]);

    while (minHeap->size != 0) {
        MinHeapNode* minNode = extract_min(minHeap);
        int u = minNode->v;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(minHeap, v) &&
                dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decrease_key(minHeap, v, dist[v]);
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {

    int graph[V][V] = {
        {0, 9, 6, 0, 0},
        {9, 0, 11, 5, 0},
        {6, 11, 0, 0, 9},
        {0, 5, 0, 0, 6},
        {0, 0, 9, 6, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
