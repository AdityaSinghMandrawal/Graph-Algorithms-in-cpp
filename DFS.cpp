#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1; // Mark the current node as visited
    cout << node << " "; // Print the current node

    // Traverse all adjacent nodes
    for(auto it : adj[node]) {
        if(!vis[it]) {
            DFS(it, adj, vis); // Recursively call DFS for unvisited adjacent nodes
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
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Adding edge from u to v (assuming 1-based indexing)
        adj[v].push_back(u); // Adding edge from v to u for undirected graph
    }

    // Perform DFS from node 1 (assuming 1-based indexing)
    cout << "DFS Traversal starting from node 1:" << endl;
    DFS(1, adj, vis); // Starting DFS from node 1

    return 0;
}
