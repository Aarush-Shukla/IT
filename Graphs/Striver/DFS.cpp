#include <bits/stdc++.h>
using namespace std;



    void dfs(int start, vector<int> adj[], int visited[], vector<int> &ans) {
        visited[start] = 1; 
        ans.push_back(start); 
        // traverse all its neighbours
        for(auto it : adj[start]) {
            // if the neighbour is not visited
            if(!visited[it]) {
                dfs(it, adj, visited, ans); 
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ans; 
        // call dfs for starting node

        //for calling unconnected graph too
         for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(start,adj,visited,ans);
           }
       }
        return ans; 
    }