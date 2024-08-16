#include <bits/stdc++.h>
using namespace std;


bool isCyclicBFS(int  src_node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList){

unordered_map<int,int> parent;

parent[src_node] = -1;
visited[src_node] = 1;
queue<int> q;
q.push(src_node);

while(!q.empty()){
    int front=q.front();
    q.pop();
 
    for(auto neighbour:adjList[front]){
        if(visited[neighbour]==true && neighbour!=parent[front]){
            return true;
        }else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=1;
            parent[neighbour]=front;
            }
        }
    }
return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;

    //adjList banayi
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    //har node pe traverse kar rahe
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans= isCyclicBFS(i,visited,adjList);
            if(ans==1)
                return "Yes";
            
        }
    }
    return "No";
}
