#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

typedef pair<int, int> iPair;

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<iPair>>& graph, int src, int V) {
    // Priority queue to store the vertices to be processed
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Distance vector to store the shortest path distance from src to each vertex
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize its distance as 0
    pq.push({0,src});
    dist[src] = 0;

    while (!pq.empty()) {
        // Extract the vertex with the minimum distance value
        int u = pq.top().second;
        pq.pop();

        // Traverse all adjacent vertices of u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight) {
                // Update distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print the calculated shortest distances
    cout << "Vertex Distance from Source (" << src << "):" << endl;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) {
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

    // Graph represented as an adjacency list
    vector<vector<iPair>> graph(V);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        // Uncomment the next line if the graph is undirected
        // graph[v].emplace_back(u, w);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, src, V);

    return 0;
}
