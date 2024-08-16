#include<bits/stdc++.h>
using namespace std;
    
    
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low_tin[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low_tin[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low_tin, bridges);
                low_tin[node] = min(low_tin[it], low_tin[node]);
                // node --- it
                if (low_tin[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low_tin[node] = min(low_tin[node], low_tin[it]);
            }
        }
    }
   
   
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
           vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];//time of insertion
        int low_tin[n];//lowest time of insertion
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low_tin, bridges);
        return bridges;
    }