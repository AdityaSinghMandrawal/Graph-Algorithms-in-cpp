#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

// Function to perform Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    // Create a distance matrix initialized to INF
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Initialize distances for direct edges
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Calculate shortest paths
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    // Graph represented as an adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (0 for no edge, otherwise weight):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);

    return 0;
}
