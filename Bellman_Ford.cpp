#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to perform the Bellman-Ford algorithm
void bellmanFord(vector<vector<int>>& edges, int V, int E, int src) {
    // Distance vector to store the shortest path distance from src to each vertex
    vector<int> dist(V, INT_MAX);

    // Initialize distance of source vertex to 0
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
           dist[v]=dist[u] + weight ;
        }
    }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; ++j) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the calculated shortest distances
    cout << "Vertex Distance from Source (" << src << "):" << endl;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            cout << i << " : INF" << endl;
        } else {
            cout << i << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Edges represented as a vector of vectors
    // Each edge is represented as a vector of three integers: (u, v, weight)
    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(edges, V, E, src);

    return 0;
}
