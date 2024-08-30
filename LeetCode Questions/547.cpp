/*
Number of provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/
class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,vis);
            }
        }
    }
    void BFS(int node,vector<int> adj[],vector<int>& vis){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& connected) {
        int N=connected.size();
        vector<int> adj[N];
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(connected[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                c++;
                BFS(i,adj,vis);
            }
        }
        return c;
    }
};