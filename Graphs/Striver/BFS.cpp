#include <bits/stdc++.h>
using namespace std;
  
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0}; 
       //since in question given 0 based indexing, so we take 0 as starting node
        visited[0] = 1; 
        queue<int> q;
        // push the initial starting node 
        q.push(0); 
        vector<int> bfs; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // traverse for all its neighbours 
            for(auto i : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!visited[i]) {
                    visited[i] = 1; 
                    q.push(i); 
                }
            }
        }
        return bfs; 
    }