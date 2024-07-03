#include <bits/stdc++.h>
using namespace std;

void BFS(int startNode, vector<int> adj[], vector<int>& vis) {
    queue<int> q;
    q.push(startNode);
    vis[startNode] = 1; // Mark the starting node as visited

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Print the current node for BFS traversal
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

int main() {
    int n, e; // n is the number of nodes, e is the number of edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<int> adj[n+1]; // Adjacency list for graph representation
    vector<int> vis(n+1, 0); // Visited array to keep track of visited nodes

    cout << "Enter edges (from to):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Adding edge from u to v (assuming 1-based indexing)
        adj[v].push_back(u); // Adding edge from v to u for undirected graph
    }

    // Perform BFS from node 1 (assuming 1-based indexing)
    cout << "BFS Traversal starting from node 1:" << endl;
    BFS(1, adj, vis); // Starting BFS from node 1

    return 0;
}
