/*
Redundant connections
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    bool detectCycle(int node, int parent, vector<int>& vis, vector<vector<int>>& graph, vector<int>& ans) {
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, parent});
        while (!q.empty()) {
            int currentNode = q.front().first;
            int currentParent = q.front().second;
            q.pop();
            for (int neighbor : graph[currentNode]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, currentNode});
                } else if (neighbor != currentParent) {
                    ans = {currentNode, neighbor};
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        vector<int> vis(n + 1, 0);
        vector<int> ans;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            fill(vis.begin(), vis.end(), 0);
            if (detectCycle(u, -1, vis, graph, ans)) {
                return edge;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result1 = solution.findRedundantConnection(edges1);
    cout << "Redundant connection for edges1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> result2 = solution.findRedundantConnection(edges2);
    cout << "Redundant connection for edges2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}
