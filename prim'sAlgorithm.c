#include <stdio.h>
#include <limits.h>

#define V 6 // number of vertices in the graph

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    }

    return min_index;
}

void primMST(int graph[V][V]) {
    int key[V]; // key values used to pick minimum weight edge
    int mstSet[V]; // to keep track of vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int v = 0; v < V; v++) {
        key[v] = INT_MAX, mstSet[v] = 0;
    }

    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }

    // print the MST
    printf("Edge \tWeight\n");
    for (int v = 1; v < V; v++)
        printf("%d - %d \t%d \n", v, key[v], v);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0, 0},
        {2, 0, 3, 8, 5, 0},
        {0, 3, 0, 0, 7, 4},
        {6, 8, 0, 0, 9, 7},
        {0, 5, 7, 9, 0, 1},
        {0, 0, 4, 7, 1, 0}
    };

    primMST(graph);

    return 0;
}
