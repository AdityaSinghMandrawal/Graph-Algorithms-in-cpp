#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minKey(vector<int>& key,vector<bool>& vis,int V){
    int min=INT_MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(vis[i]==false&&key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex; 
}
int prims(vector<vector<int>>& graph,int V){
    vector<int> key(V,INT_MAX);
    vector<bool> vis(V,false);
    vector<int> parent(V);
    key[0]=0;
    parent[0]=-1;
    for(int c=0;c<V-1;c++){
        int u =minKey(key,vis,V);
        vis[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]&&vis[v]==false&&graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"-"<< i <<"-"<<graph[i][parent[i]]<<endl;
    }
}
int main(){
    int v;
    cout<<"enter no. of verteces :";
    cin>>v;
    vector<vector<int>> graph(v,vector<int> (v));
    cout<<"enter weighted adj. matrix"<<endl;
    for(int u=0;u<v;u++){
        for(int i=0;i<v;i++){
            cin>>graph[u][i];
        }
    }
    prims(graph,v);
}


#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
void prims(vector<vector<pair<int, int>>>& adj, int V) {
    vector<int> key(V, INT_MAX); 
    vector<bool> vis(V, false);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    key[0] = 0; 
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue; 
        vis[u] = true; 
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (!vis[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    prims(adj, V);
    return 0;
}
