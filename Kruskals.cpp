#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Function to find the parent of a node in the disjoint set
int find(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to union two subsets
void unionSets(vector<int>& parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Kruskal's algorithm to find MST
void KruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result; // Store the resultant MST
    int e = 0; // Number of edges in MST

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V, -1); // Initialize parent array for disjoint set

    // Step 2: Pick the smallest edge and check if it forms a cycle
    for (auto& edge : edges) {
        if (e == V - 1) break; // If the MST contains V-1 edges, stop

        int u = find(parent, edge.src);
        int v = find(parent, edge.dest);

        // If including this edge doesn't cause a cycle, include it in result
        if (u != v) {
            result.push_back(edge);
            unionSets(parent, u, v);
            e++;
        }
    }

    // Print the resultant MST
    cout << "Edges in the MST:" << endl;
    for (auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
}

int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph
    vector<Edge> edges(E);

    // Adding edges to the graph
    edges[0] = {0, 1, 10};
    edges[1] = {0, 2, 6};
    edges[2] = {0, 3, 5};
    edges[3] = {1, 3, 15};
    edges[4] = {2, 3, 4};

    // Running Kruskal's algorithm
    KruskalMST(edges, V);

    return 0;
}
