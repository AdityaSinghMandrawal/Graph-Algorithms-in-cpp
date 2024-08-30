/*
Finding Critical and Pseudo-Critical Edges in a Minimum Spanning Tree Using Kruskal's Algorithm

Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
 
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    vector<int> parent;
    int V, comp;
    
    int findParent(int u) {
        while (1) {
            if (parent[u] < 0)
                return u;
            u = parent[u];
        }
    }
    
    void unionSet(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);
        if (p1 == p2) return;
        if (abs(parent[p1]) > abs(parent[p2])) {
            parent[p1] += parent[p2];
            parent[p2] = p1;
        } else {
            parent[p2] += parent[p1];
            parent[p1] = p2;
        }
        comp--;
    }
    
    int kruskal(vector<vector<int>>& edges, int include, int skip) {
        parent.assign(V, -1);  
        comp = V;
        int sum = 0;
        if (include != -1) {
            sum += edges[include][0];
            unionSet(findParent(edges[include][1]), findParent(edges[include][2]));
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (i == skip) continue;
            int w = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            int p1 = findParent(u);
            int p2 = findParent(v);
            if (p1 != p2) {
                sum += w;
                unionSet(p1, p2);
            }
        }
        return comp != 1 ? INT_MAX : sum;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(2, vector<int>());
        this->V = n;
        
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            edges[i][0] = w;
            edges[i][1] = u;
            edges[i][2] = v;
            edges[i].push_back(i); 
        }
        
        sort(edges.begin(), edges.end());
        
        int mstWeight = kruskal(edges, -1, -1);
        
        for (int i = 0; i < edges.size(); ++i) {
            int skip = kruskal(edges, -1, i);
            int inclu = kruskal(edges, i, -1);
            
            if (skip > mstWeight) {
                ans[0].push_back(edges[i][3]);  // Critical edge
            } else if (inclu == mstWeight) {
                ans[1].push_back(edges[i][3]);  // Pseudo-critical edge
            }
        }
        return ans;
    }
};
