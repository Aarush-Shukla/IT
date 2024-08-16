#include <bits/stdc++.h>
using namespace std;

// Approach 1 - BFS

//   bool isCycle(int src,int V, vector<int> adj[],int vis[]){
//         queue <pair<int,int>> q;
//         vis[src]=1;
//         q.push({src,-1});
//         while(!q.empty()){
//             int node=q.front().first;
//             int parent=q.front().second;
//             q.pop();
            
//             for(auto i:adj[node]){
//                 if(!vis[i]){
//                     vis[i]=1;
//                     q.push({i,node});
//                 }else if(i!=parent){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
    
    
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         int vis[V]={0};
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 if(isCycle(i,V,adj,vis)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }





//Approach 2 -DFS

 
    bool isCycle_DFS(int node,int parent,int vis[],vector<int> adj[] ){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(isCycle_DFS(i,node,vis,adj)){
                    return true;
                }
            }
            else if(i!=parent) { // iss condition mai visited hai i aur vo parent bhi nahi hai iska matlab cycle hai
                return true;
            }
        }
        return false;
    }
    
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {

        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(isCycle_DFS(i,-1,vis,adj)){
                return true;
                }
            }
        }
        
        return false;
    }