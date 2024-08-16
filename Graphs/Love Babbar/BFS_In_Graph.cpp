#include <bits/stdc++.h> 
using namespace std;

// BFS or Breadth-First Search is a algorithm used to visit all of the nodes of a given graph.in this travaersal algorithm, one node is selscted, and then all of the adjacent nodes are visited one by one.




// T.C-O(N+E), S.C-O(N+E)
// N-No of Nodes, E-No.of Edges
void PutinAdjList(vector<pair<int, int>> &edges,unordered_map<int,set<int>> &adjList){
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        //undirected graph
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}



vector<int> bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        
        ans.push_back(frontNode);


    for(auto i:adjList[frontNode])
        if(visited[i]==false){
            q.push(i);
            visited[i]=true;
        }
    }
    return ans;
}



vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool>visited;

    //put elements in adjList
    PutinAdjList(edges,adjList);
    
    //visiting every Node
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }

    return ans;
}



